
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    sdkbox.PluginAppnext:init()

    sdkbox.PluginAppnext:setListener(function(args)
        dump(args)
    end)

    -- sdkbox.PluginAppnext:cacheAd("default")
    -- sdkbox.PluginAppnext:cacheVideo("fullscreen")

    local menu = cc.Menu:create()

    local label1 = cc.Label:createWithSystemFont("Show Ads", "sans", 28)
    local item1 = cc.MenuItemLabel:create(label1)
    item1:onClicked(function()
        print("Show Ads")
        sdkbox.PluginAppnext:showAd()
    end)
    menu:addChild(item1)

    local label2 = cc.Label:createWithSystemFont("Show fullscreen Video", "sans", 28)
    local item2 = cc.MenuItemLabel:create(label2)
    item2:onClicked(function()
        print("Show fullscreen Video")
        sdkbox.PluginAppnext:showVideo("fullscreen")
    end)
    menu:addChild(item2)

    local label3 = cc.Label:createWithSystemFont("Show reward Video", "sans", 28)
    local item3 = cc.MenuItemLabel:create(label3)
    item3:onClicked(function()
        print("Show reward Video")
        sdkbox.PluginAppnext:showVideo("reward")
    end)
    menu:addChild(item3)

    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
