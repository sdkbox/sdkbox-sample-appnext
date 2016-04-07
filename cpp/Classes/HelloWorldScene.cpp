
#include "HelloWorldScene.h"
#include "PluginAppnext/PluginAppnext.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginAppnext::cacheAd("default");
    sdkbox::PluginAppnext::cacheVideo("fullscreen");
    
    auto menu = Menu::create();

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Show Ads", "sans", 24), [](Ref*){
        CCLOG("Show Ads");
        sdkbox::PluginAppnext::showAd();
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Show Video", "sans", 24), [](Ref*){
        CCLOG("Show Video");
        sdkbox::PluginAppnext::showVideo("fullscreen");
    }));

    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

void HelloWorld::onAdError(const std::string& msg)
{
    CCLOG("onAdError: %s", msg.c_str());
}

void HelloWorld::onAdLoaded()
{
    CCLOG("onAdLoaded");
}

void HelloWorld::onAdOpened() // not support on android
{
    CCLOG("onAdOpened");
}

void HelloWorld::onAdClosed()
{
    CCLOG("onAdClosed");
}

void HelloWorld::onAdClicked()
{
    CCLOG("onAdClicked");
}

void HelloWorld::onVideoLoaded(const std::string& name) // not support on ios
{
    CCLOG("onVideoLoaded: %s", name.c_str());
}

void HelloWorld::onVideoClicked(const std::string& name) // not support on ios
{
    CCLOG("onVideoClicked: %s", name.c_str());
}

void HelloWorld::onVideoClosed(const std::string& name) // not support on ios
{
    CCLOG("onVideoClosed: %s", name.c_str());
}

void HelloWorld::onVideoEnded(const std::string& name) // not support on ios
{
    CCLOG("onVideoEnded: %s", name.c_str());
}

void HelloWorld::onVideoError(const std::string& name, const std::string& msg) // not support on ios
{
    CCLOG("onVideoError: %s, %s", name.c_str(), msg.c_str());
}
