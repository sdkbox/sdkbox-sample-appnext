/****************************************************************************

 Copyright (c) 2014-2015 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_APPNEXT_WRAPPER_H_
#define _PLUGIN_APPNEXT_WRAPPER_H_

#include "PluginAppnext.h"
#include "json98.h"

#define TAG "Appnext"
#define VERSION "v1.3"
#define APPNEXT_CATEGORY_IOS "v1.01.01"
#define APPNEXT_CATEGORY_ANDROID "v1.3"

namespace sdkbox {


    class AppnextWrapper {

    public:
        static AppnextWrapper* getInstance();

        virtual bool init() = 0;
        virtual bool __init( bool asAdUnit ) = 0;
        virtual void setListener(AppnextListener* listener) = 0;
        virtual AppnextListener* getListener() = 0;
        virtual void removeListener() = 0;

        virtual void hideAd() = 0;
        virtual void showAd() = 0;
        virtual void refreshAds() = 0;
        virtual void cacheAd(const std::string& name) = 0;
        virtual bool isAdReady() = 0;

        virtual void cacheVideo(const std::string& name) = 0;
        virtual void showVideo(const std::string& name) = 0;
        virtual void refreshVideo(const std::string& name) = 0;
        virtual bool isVideoReady(const std::string& name) = 0;

        virtual void setRewardsTransactionId(const std::string& transactionId)  = 0;
        virtual void setRewardsUserId(const std::string& userId)  = 0;
        virtual void setRewardsRewardTypeCurrency(const std::string& currency)  = 0;
        virtual void setRewardsAmountRewarded(const std::string& amount)  = 0;
        virtual void setRewardsCustomParameter(const std::string& parameter)  = 0;

        // ad unit
        virtual bool available(const std::string& name) = 0;
        virtual void play(const std::string& zone) = 0;
    };

    class AppnextWrapperDisabled : public AppnextWrapper {

    public:
        bool init() { return false; }
        bool __init( bool asAdUnit ) { return false; }
        void setListener(AppnextListener* listener) {}
        AppnextListener* getListener() { return NULL; }
        void removeListener() {}

        void hideAd() {}
        void showAd() {}
        void refreshAds() {}
        void cacheAd(const std::string& name) {}
        bool isAdReady() { return false; }

        void cacheVideo(const std::string& name) {}
        void showVideo(const std::string& name) {}
        void refreshVideo(const std::string& name) {}
        bool isVideoReady(const std::string& name) { return false; }

        void setRewardsTransactionId(const std::string& transactionId)  {}
        void setRewardsUserId(const std::string& userId)  {}
        void setRewardsRewardTypeCurrency(const std::string& currency)  {}
        void setRewardsAmountRewarded(const std::string& amount)  {}
        void setRewardsCustomParameter(const std::string& parameter)  {}

        bool available(const std::string& name) { return false; }
        void play(const std::string& zone) {}
    };

class AppnextWrapperEnabled : public AppnextWrapper {

    public:
    AppnextWrapperEnabled();

    bool init();
    bool __init( bool asAdUnit );
    void setListener(AppnextListener* listener);
    AppnextListener* getListener();
    void removeListener();

    void hideAd();
    void showAd();
    void refreshAds();
    void cacheAd(const std::string& name);
    bool isAdReady();

    void cacheVideo(const std::string& name);
    void showVideo(const std::string& name);
    void refreshVideo(const std::string& name);
    bool isVideoReady(const std::string& name);

    void setRewardsTransactionId(const std::string& transactionId);
    void setRewardsUserId(const std::string& userId);
    void setRewardsRewardTypeCurrency(const std::string& currency);
    void setRewardsAmountRewarded(const std::string& amount);
    void setRewardsCustomParameter(const std::string& parameter);

    bool available(const std::string& name);
    void play(const std::string& zone);
protected:
    bool nativeInit(const Json& config, bool asAdUnit);
    std::string nativeSDKVersion();

    AppnextListener* _listener;
    std::map<std::string, std::string> _ADsMap;
};

}

#endif
