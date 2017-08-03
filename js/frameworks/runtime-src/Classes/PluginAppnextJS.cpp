#include "PluginAppnextJS.hpp"
#include "PluginAppnext/PluginAppnext.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 52
#elif MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS_ReportErrorUTF8(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginAppnext_class;
#if MOZJS_MAJOR_VERSION < 33
JSObject *jsb_sdkbox_PluginAppnext_prototype;
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_hideAd(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginAppnext::hideAd();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_hideAd : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_hideAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginAppnext::hideAd();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_cacheAd(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_cacheAd : Error processing arguments");
        sdkbox::PluginAppnext::cacheAd(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_cacheAd : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_cacheAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::cacheAd(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_showVideo(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_showVideo : Error processing arguments");
        sdkbox::PluginAppnext::showVideo(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_showVideo : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_showVideo(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::showVideo(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_refreshAds(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginAppnext::refreshAds();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_refreshAds : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_refreshAds(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginAppnext::refreshAds();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_isVideoReady(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_isVideoReady : Error processing arguments");
        bool ret = sdkbox::PluginAppnext::isVideoReady(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_isVideoReady : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_isVideoReady(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginAppnext::isVideoReady(arg0);
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsRewardTypeCurrency(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::setRewardsRewardTypeCurrency(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_isAdReady(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginAppnext::isAdReady();
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_isAdReady : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_isAdReady(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginAppnext::isAdReady();
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_refreshVideo(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_refreshVideo : Error processing arguments");
        sdkbox::PluginAppnext::refreshVideo(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_refreshVideo : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_refreshVideo(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::refreshVideo(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_cacheVideo(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_cacheVideo : Error processing arguments");
        sdkbox::PluginAppnext::cacheVideo(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_cacheVideo : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_cacheVideo(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::cacheVideo(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_init(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginAppnext::init();
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginAppnext::init();
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsTransactionId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::setRewardsTransactionId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsUserId(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_setRewardsUserId : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsUserId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_setRewardsUserId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::setRewardsUserId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_showAd(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginAppnext::showAd();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_showAd : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_showAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginAppnext::showAd();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsCustomParameter(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::setRewardsCustomParameter(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsAmountRewarded(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAppnext::setRewardsAmountRewarded(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginAppnextJS_PluginAppnext_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginAppnext)", obj);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAppnextJS_PluginAppnext(JSContext *cx, JS::HandleObject global) {
    static JSClass PluginAgeCheq_class = {
        "PluginAppnext",
        JSCLASS_HAS_PRIVATE,
        nullptr
    };
    jsb_sdkbox_PluginAppnext_class = &PluginAgeCheq_class;

#if MOZJS_MAJOR_VERSION < 52
    jsb_sdkbox_PluginAppnext_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppnext_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginAppnext_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppnext_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAppnext_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAppnext_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAppnext_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAppnext_class->finalize = js_PluginAppnextJS_PluginAppnext_finalize;
    jsb_sdkbox_PluginAppnext_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
#endif

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("hideAd", js_PluginAppnextJS_PluginAppnext_hideAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheAd", js_PluginAppnextJS_PluginAppnext_cacheAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showVideo", js_PluginAppnextJS_PluginAppnext_showVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshAds", js_PluginAppnextJS_PluginAppnext_refreshAds, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isVideoReady", js_PluginAppnextJS_PluginAppnext_isVideoReady, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsRewardTypeCurrency", js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAdReady", js_PluginAppnextJS_PluginAppnext_isAdReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshVideo", js_PluginAppnextJS_PluginAppnext_refreshVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheVideo", js_PluginAppnextJS_PluginAppnext_cacheVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAppnextJS_PluginAppnext_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsTransactionId", js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsUserId", js_PluginAppnextJS_PluginAppnext_setRewardsUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAd", js_PluginAppnextJS_PluginAppnext_showAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsCustomParameter", js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsAmountRewarded", js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, nullptr);
    JSObject* objProto = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_sdkbox_PluginAppnext_class,
        dummy_constructor<sdkbox::PluginAppnext>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, objProto);
#if (SDKBOX_COCOS_JSB_VERSION >= 2)
#if MOZJS_MAJOR_VERSION >= 52
    jsb_register_class<sdkbox::PluginAppnext>(cx, jsb_sdkbox_PluginAppnext_class, proto);
#else
    jsb_register_class<sdkbox::PluginAppnext>(cx, jsb_sdkbox_PluginAppnext_class, proto, JS::NullPtr());
#endif
#else
    TypeTest<sdkbox::PluginAppnext> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginAppnext_class;
        p->proto = objProto;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif

    // add the proto and JSClass to the type->js info hash table
    JS::RootedValue className(cx);
    JSString* jsstr = JS_NewStringCopyZ(cx, "PluginAppnext");
    className = JS::StringValue(jsstr);
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
}
#else
void js_register_PluginAppnextJS_PluginAppnext(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginAppnext_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginAppnext_class->name = "PluginAppnext";
    jsb_sdkbox_PluginAppnext_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppnext_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginAppnext_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppnext_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAppnext_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAppnext_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAppnext_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAppnext_class->finalize = js_PluginAppnextJS_PluginAppnext_finalize;
    jsb_sdkbox_PluginAppnext_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("hideAd", js_PluginAppnextJS_PluginAppnext_hideAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheAd", js_PluginAppnextJS_PluginAppnext_cacheAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showVideo", js_PluginAppnextJS_PluginAppnext_showVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshAds", js_PluginAppnextJS_PluginAppnext_refreshAds, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isVideoReady", js_PluginAppnextJS_PluginAppnext_isVideoReady, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsRewardTypeCurrency", js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAdReady", js_PluginAppnextJS_PluginAppnext_isAdReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshVideo", js_PluginAppnextJS_PluginAppnext_refreshVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheVideo", js_PluginAppnextJS_PluginAppnext_cacheVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAppnextJS_PluginAppnext_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsTransactionId", js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsUserId", js_PluginAppnextJS_PluginAppnext_setRewardsUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAd", js_PluginAppnextJS_PluginAppnext_showAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsCustomParameter", js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsAmountRewarded", js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginAppnext_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginAppnext_class,
        dummy_constructor<sdkbox::PluginAppnext>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginAppnext", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginAppnext> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginAppnext_class;
        p->proto = jsb_sdkbox_PluginAppnext_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginAppnextJS_PluginAppnext(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginAppnext_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginAppnext_class->name = "PluginAppnext";
    jsb_sdkbox_PluginAppnext_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppnext_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppnext_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAppnext_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAppnext_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAppnext_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAppnext_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAppnext_class->finalize = js_PluginAppnextJS_PluginAppnext_finalize;
    jsb_sdkbox_PluginAppnext_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("hideAd", js_PluginAppnextJS_PluginAppnext_hideAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheAd", js_PluginAppnextJS_PluginAppnext_cacheAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showVideo", js_PluginAppnextJS_PluginAppnext_showVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshAds", js_PluginAppnextJS_PluginAppnext_refreshAds, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isVideoReady", js_PluginAppnextJS_PluginAppnext_isVideoReady, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsRewardTypeCurrency", js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAdReady", js_PluginAppnextJS_PluginAppnext_isAdReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshVideo", js_PluginAppnextJS_PluginAppnext_refreshVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheVideo", js_PluginAppnextJS_PluginAppnext_cacheVideo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAppnextJS_PluginAppnext_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsTransactionId", js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsUserId", js_PluginAppnextJS_PluginAppnext_setRewardsUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAd", js_PluginAppnextJS_PluginAppnext_showAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsCustomParameter", js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRewardsAmountRewarded", js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginAppnext_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginAppnext_class,
        dummy_constructor<sdkbox::PluginAppnext>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginAppnext", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginAppnext> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginAppnext_class;
        p->proto = jsb_sdkbox_PluginAppnext_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginAppnextJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginAppnextJS_PluginAppnext(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginAppnextJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginAppnextJS_PluginAppnext(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginAppnextJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginAppnextJS_PluginAppnext(cx, obj);

    sdkbox::setProjectType("js");
}
#endif