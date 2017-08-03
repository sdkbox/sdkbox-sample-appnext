#ifndef __PluginAppnextJS_h__
#define __PluginAppnextJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAppnextJS_PluginAppnext(JSContext *cx, JS::HandleObject global);
void register_all_PluginAppnextJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginAppnextJS_PluginAppnext(JSContext *cx, JSObject* global);
void register_all_PluginAppnextJS(JSContext* cx, JSObject* obj);
#endif
#endif

