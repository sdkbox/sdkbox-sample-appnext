
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        // var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
        //     cc.log("QUIT");
        // });
        // var menu = new cc.Menu(quit);
        // var size = quit.getContentSize();
        // menu.x = winsize.width - size.width / 2 - 16;
        // menu.y = size.height / 2 + 16;
        // this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        sdkbox.PluginAppnext.init();
        sdkbox.PluginAppnext.setListener({
            onAdError : function(msg) {
                cc.log("onAdError: " + msg);
            },

            onAdLoaded : function() {
                cc.log("onAdLoaded");
            },

            onAdOpened : function() {
                cc.log("onAdOpened");
            },

            onAdClosed : function() {
                cc.log("onAdClosed");
            },

            onAdClicked : function() {
                cc.log("onAdClicked");
            },

            onVideoLoaded : function(name) {
                cc.log("onVideoLoaded: " + name);
            },

            onVideoClicked : function(name) {
                cc.log("onVideoClicked: " + name);
            },

            onVideoClosed : function(name) {
                cc.log("onVideoClosed: " + name);
            },

            onVideoEnded : function(name) {
                cc.log("onVideoEnded: " + name);
            },

            onVideoError : function(name, msg) {
                cc.log("onVideoError: " + name);
            }
        });

        // sdkbox.PluginAppnext.cacheAd("default");
        // sdkbox.PluginAppnext.cacheVideo("fullscreen");

        var menu = new cc.Menu();

        var item1 = new cc.MenuItemLabel(new cc.LabelTTF("Show Ads", "sans", 28), function() {
            cc.log("Show Ads");
            sdkbox.PluginAppnext.showAd();
        });
        menu.addChild(item1);

        var item2 = new cc.MenuItemLabel(new cc.LabelTTF("Show fullscreen Video", "sans", 28), function() {
            cc.log("Show fullscreen Video");
            sdkbox.PluginAppnext.showVideo("fullscreen");
        });
        menu.addChild(item2);

        var item2 = new cc.MenuItemLabel(new cc.LabelTTF("Show rewarded Video", "sans", 28), function() {
            cc.log("Show rewarded Video");
            sdkbox.PluginAppnext.showVideo("reward");
        });
        menu.addChild(item2);

        var winsize = cc.winSize;
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

