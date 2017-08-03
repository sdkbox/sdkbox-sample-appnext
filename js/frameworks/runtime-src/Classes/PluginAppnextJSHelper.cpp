#include "PluginAppnextJSHelper.h"
#include "PluginAppnext/PluginAppnext.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginAppnext_prototype;
static JSContext* s_cx = nullptr;

#if (COCOS2D_VERSION < 0x00030000)
#define Ref CCObject
#define Director CCDirector
#define getInstance sharedDirector
#define schedule scheduleSelector
#endif

class AppNextCallbackJS: public cocos2d::Ref {
public:
    AppNextCallbackJS();
    void schedule();
    void notityJs(float dt);
    int transParams(JS::Value** pp);

    std::string _name;  // function name

    JS::Value _paramVal[2];
    int _paramLen;
};

class AppnextListenerJS : public sdkbox::AppnextListener, public sdkbox::JSListenerBase
{
public:
    AppnextListenerJS():sdkbox::JSListenerBase() {
    }

    void onAdError(const std::string& msg) {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onAdError";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(s_cx, msg);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void onAdLoaded() {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onAdLoaded";
        cb->schedule();
    }
    void onAdOpened() {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onAdOpened";
        cb->schedule();
    }
    void onAdClosed() {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onAdClosed";
        cb->schedule();
    }
    void onAdClicked() {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onAdClicked";
        cb->schedule();
    }

    void onVideoLoaded(const std::string& name) {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onVideoLoaded";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void onVideoClicked(const std::string& name) {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onVideoClicked";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void onVideoClosed(const std::string& name) {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onVideoClosed";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void onVideoEnded(const std::string& name) {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onVideoEnded";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void onVideoError(const std::string& name, const std::string& msg) {
        AppNextCallbackJS* cb = new AppNextCallbackJS();
#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif
        cb->_name = "onVideoError";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(s_cx, name);
        cb->_paramVal[1] = SB_STR_TO_JSVAL(s_cx, msg);
        cb->_paramLen = 2;
        cb->schedule();
    }

    void invokeJS(const char* func, JS::Value* pVals, int valueSize) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = func;
        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JS::NullValue()) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(valueSize, pVals), &retval);
            }
#else
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, valueSize, pVals, &retval);
            }
#endif
        }
    }

};


AppNextCallbackJS::AppNextCallbackJS():
_paramLen(0) {
}

void AppNextCallbackJS::schedule() {
    retain();
    cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(AppNextCallbackJS::notityJs), this, 0.1, 0, 0.0f, false);
    autorelease();
}

void AppNextCallbackJS::notityJs(float dt) {
    sdkbox::AppnextListener* lis = sdkbox::PluginAppnext::getListener();
    AppnextListenerJS* l = dynamic_cast<AppnextListenerJS*>(lis);
    if (l) {
        l->invokeJS(_name.c_str(), _paramVal, _paramLen);
    }
    release();
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginAppnextJS_PluginAppnext_setListener(JSContext *cx, uint32_t argc, JS::Value *vp)
#else
bool js_PluginAppnextJS_PluginAppnext_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }

        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_setIAPListener : Error processing arguments");
        AppnextListenerJS* wrapper = new AppnextListenerJS();
        wrapper->setJSDelegate(cx, args.get(0));
        sdkbox::PluginAppnext::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_setIAPListener : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void appnext_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, int>& params)
#else
void appnext_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, int>& params)
#endif
{
    JS::RootedValue val(cx);
    sdkbox::std_map_string_int_to_jsval(cx, params, &val);

    JS::RootedValue rv(cx);
    rv = val;
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    JS_SetProperty(cx, obj, name.c_str(), rv);
#else
    JS_SetProperty(cx, obj, name.c_str(), rv.address());
#endif
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void appnext_register_constants(JSContext* cx, const JS::RootedObject& obj)
#else
void appnext_register_constants(JSContext* cx, JSObject* obj)
#endif
{
    std::map<std::string, int> enums;
    enums.clear();
    enums.insert(std::make_pair("AdOrientation_AutoDetect", 0));
    enums.insert(std::make_pair("AdOrientation_Landscape", 1));
    enums.insert(std::make_pair("AdOrientation_Portrait", 2));
    appnext_set_constants(cx, obj, "AdOrientation", enums);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginAppnextJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginAppnext", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAppnextJS_PluginAppnext_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    appnext_register_constants(cx, pluginObj);
}
#else
void register_all_PluginAppnextJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginAppnext", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAppnextJS_PluginAppnext_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    appnext_register_constants(cx, pluginObj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginAppnextJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginAppnext", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAppnextJS_PluginAppnext_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    appnext_register_constants(cx, pluginObj);
}
#endif
