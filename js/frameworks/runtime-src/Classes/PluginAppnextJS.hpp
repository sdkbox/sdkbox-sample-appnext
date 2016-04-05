#ifndef __PluginAppnextJS_h__
#define __PluginAppnextJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginAppnext_class;
extern JSObject *jsb_sdkbox_PluginAppnext_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAppnextJS_PluginAppnext(JSContext *cx, JS::HandleObject global);
void register_all_PluginAppnextJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginAppnextJS_PluginAppnext(JSContext *cx, JSObject* global);
void register_all_PluginAppnextJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginAppnextJS_PluginAppnext_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginAppnextJS_PluginAppnext_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_hideAd(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_hideAd(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_cacheAd(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_cacheAd(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_showVideo(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_showVideo(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_refreshAds(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_refreshAds(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_isVideoReady(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_isVideoReady(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_isAdReady(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_isAdReady(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_refreshVideo(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_refreshVideo(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_cacheVideo(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_cacheVideo(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsUserId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsUserId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_showAd(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_showAd(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

