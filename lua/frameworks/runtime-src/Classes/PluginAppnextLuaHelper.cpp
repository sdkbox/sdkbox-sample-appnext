
#include "PluginAppnextLuaHelper.h"
#include "PluginAppnext/PluginAppnext.h"
#include "SDKBoxLuaHelper.h"

class AppnextListenerLua : public sdkbox::AppnextListener {
public:
    AppnextListenerLua(): mLuaHandler(0) {
    }

    ~AppnextListenerLua() {
        resetHandler();
    }

    void setHandler(int luaHandler) {
        if (mLuaHandler == luaHandler) {
            return;
        }
        resetHandler();
        mLuaHandler = luaHandler;
    }

    void resetHandler() {
        if (0 == mLuaHandler) {
            return;
        }

        LUAENGINE->removeScriptHandler(mLuaHandler);
        mLuaHandler = 0;
    }


    void onAdError(const std::string& msg) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onAdError")));
        dict.insert(std::make_pair("msg", LuaValue::stringValue(msg)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onAdLoaded() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onAdLoaded")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onAdOpened() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onAdOpened")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onAdClosed() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onAdClosed")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onAdClicked() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onAdClicked")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onVideoLoaded(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onVideoLoaded")));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onVideoClicked(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onVideoClicked")));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onVideoClosed(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onVideoClosed")));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onVideoEnded(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onVideoEnded")));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onVideoError(const std::string& name, const std::string& msg) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onVideoError")));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));
        dict.insert(std::make_pair("msg", LuaValue::stringValue(msg)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
    int mLuaHandler;
};

int lua_PluginAppnextLua_PluginAppnext_setListener(lua_State* tolua_S) {
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        AppnextListenerLua* lis = static_cast<AppnextListenerLua*> (sdkbox::PluginAppnext::getListener());
        if (NULL == lis) {
            lis = new AppnextListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginAppnext::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_setListener'.",&tolua_err);
#endif
    return 0;
}

int extern_PluginAppnext(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginAppnext");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginAppnextLua_PluginAppnext_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginAppnextLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginAppnext(L);

    tolua_endmodule(L);
    return 1;
}


