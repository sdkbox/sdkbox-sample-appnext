#include "PluginAppnextLua.hpp"
#include "PluginAppnext/PluginAppnext.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginAppnextLua_PluginAppnext_hideAd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_hideAd'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::hideAd();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:hideAd",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_hideAd'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_cacheAd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:cacheAd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_cacheAd'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::cacheAd(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:cacheAd",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_cacheAd'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_showVideo(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:showVideo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_showVideo'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::showVideo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:showVideo",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_showVideo'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_refreshAds(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_refreshAds'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::refreshAds();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:refreshAds",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_refreshAds'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_isVideoReady(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:isVideoReady");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_isVideoReady'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAppnext::isVideoReady(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:isVideoReady",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_isVideoReady'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_setRewardsRewardTypeCurrency(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:setRewardsRewardTypeCurrency");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsRewardTypeCurrency'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::setRewardsRewardTypeCurrency(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:setRewardsRewardTypeCurrency",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsRewardTypeCurrency'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_isAdReady(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_isAdReady'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAppnext::isAdReady();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:isAdReady",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_isAdReady'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_refreshVideo(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:refreshVideo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_refreshVideo'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::refreshVideo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:refreshVideo",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_refreshVideo'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_cacheVideo(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:cacheVideo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_cacheVideo'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::cacheVideo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:cacheVideo",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_cacheVideo'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAppnext::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_setRewardsTransactionId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:setRewardsTransactionId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsTransactionId'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::setRewardsTransactionId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:setRewardsTransactionId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsTransactionId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_setRewardsUserId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:setRewardsUserId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsUserId'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::setRewardsUserId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:setRewardsUserId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsUserId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_showAd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_showAd'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::showAd();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:showAd",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_showAd'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_setRewardsCustomParameter(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:setRewardsCustomParameter");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsCustomParameter'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::setRewardsCustomParameter(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:setRewardsCustomParameter",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsCustomParameter'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAppnextLua_PluginAppnext_setRewardsAmountRewarded(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAppnext",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAppnext:setRewardsAmountRewarded");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsAmountRewarded'", nullptr);
            return 0;
        }
        sdkbox::PluginAppnext::setRewardsAmountRewarded(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAppnext:setRewardsAmountRewarded",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAppnextLua_PluginAppnext_setRewardsAmountRewarded'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginAppnextLua_PluginAppnext_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginAppnext)");
    return 0;
}

int lua_register_PluginAppnextLua_PluginAppnext(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginAppnext");
    tolua_cclass(tolua_S,"PluginAppnext","sdkbox.PluginAppnext","",nullptr);

    tolua_beginmodule(tolua_S,"PluginAppnext");
        tolua_function(tolua_S,"hideAd", lua_PluginAppnextLua_PluginAppnext_hideAd);
        tolua_function(tolua_S,"cacheAd", lua_PluginAppnextLua_PluginAppnext_cacheAd);
        tolua_function(tolua_S,"showVideo", lua_PluginAppnextLua_PluginAppnext_showVideo);
        tolua_function(tolua_S,"refreshAds", lua_PluginAppnextLua_PluginAppnext_refreshAds);
        tolua_function(tolua_S,"isVideoReady", lua_PluginAppnextLua_PluginAppnext_isVideoReady);
        tolua_function(tolua_S,"setRewardsRewardTypeCurrency", lua_PluginAppnextLua_PluginAppnext_setRewardsRewardTypeCurrency);
        tolua_function(tolua_S,"isAdReady", lua_PluginAppnextLua_PluginAppnext_isAdReady);
        tolua_function(tolua_S,"refreshVideo", lua_PluginAppnextLua_PluginAppnext_refreshVideo);
        tolua_function(tolua_S,"cacheVideo", lua_PluginAppnextLua_PluginAppnext_cacheVideo);
        tolua_function(tolua_S,"init", lua_PluginAppnextLua_PluginAppnext_init);
        tolua_function(tolua_S,"setRewardsTransactionId", lua_PluginAppnextLua_PluginAppnext_setRewardsTransactionId);
        tolua_function(tolua_S,"setRewardsUserId", lua_PluginAppnextLua_PluginAppnext_setRewardsUserId);
        tolua_function(tolua_S,"showAd", lua_PluginAppnextLua_PluginAppnext_showAd);
        tolua_function(tolua_S,"setRewardsCustomParameter", lua_PluginAppnextLua_PluginAppnext_setRewardsCustomParameter);
        tolua_function(tolua_S,"setRewardsAmountRewarded", lua_PluginAppnextLua_PluginAppnext_setRewardsAmountRewarded);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginAppnext).name();
    g_luaType[typeName] = "sdkbox.PluginAppnext";
    g_typeCast["PluginAppnext"] = "sdkbox.PluginAppnext";
    return 1;
}
TOLUA_API int register_all_PluginAppnextLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginAppnextLua_PluginAppnext(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

