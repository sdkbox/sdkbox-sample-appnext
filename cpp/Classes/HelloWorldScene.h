#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginAppnext/PluginAppnext.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::AppnextListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    void createTestMenu();


    void onAdError(const std::string& msg);
    void onAdLoaded();
    void onAdOpened();
    void onAdClosed();
    void onAdClicked();
    
    void onVideoLoaded(const std::string& name);
    void onVideoClicked(const std::string& name);
    void onVideoClosed(const std::string& name);
    void onVideoEnded(const std::string& name);
    void onVideoError(const std::string& name, const std::string& msg);
};

#endif // __HELLOWORLD_SCENE_H__
