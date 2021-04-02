#include "ExampleScene.hpp"

#include "Yodo1Mas/Android.hpp"

ExampleScene::ExampleScene()
{
    isRewardedLoaded = false;
    isInterstitialLoaded = false;
    isBannerLoaded = false;

}

ExampleScene::~ExampleScene()
{

}

ExampleScene* ExampleScene::createScene()
{
    ExampleScene* exampleScene = create();
    return (exampleScene);
}

ExampleScene* ExampleScene::create()
{
    ExampleScene* exampleScene = new ExampleScene();

    if (exampleScene != nullptr && exampleScene->init())
    {
        exampleScene->autorelease();
    }
    else
    {
        if (exampleScene != nullptr)
        {
            delete (exampleScene);
            exampleScene = nullptr;
        }
    }

    return (exampleScene);
}

bool ExampleScene::init()
{
    if (Scene::init() == false) { return (false); }

    /* ORIGIN & SIZE */
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 originPoint = Director::getInstance()->getVisibleOrigin();
    Vec2 centerPoint = Vec2(originPoint.x + visibleSize.width * 0.5f, originPoint.y + visibleSize.height * 0.5f);

    /* CONTENTS LAYER */
    LayerColor* contentsLayer = LayerColor::create(Color4B(32, 32, 32, 255));
    this->addChild(contentsLayer);

    MenuItemFont::setFontSize(14);

    // BANNER
    MenuItemFont* bannerShowMenu = MenuItemFont::create("Show Banner", [&](cocos2d::Ref* pSender) {
        if (isBannerLoaded == true)
        {
            ShowBannerAd();
        }
        });
    MenuItemFont* bannerDismissMenu = MenuItemFont::create("Dismiss Banner", [&](cocos2d::Ref* pSender) {
        if (isBannerLoaded == true)
        {
            DismissBannerAd();
        }

        });

    // REWARDED
    MenuItemFont* rewardedShowMenu = MenuItemFont::create("Show Rwarded", [&](cocos2d::Ref* pSender) {
        if (isRewardedLoaded == true)
        {
            ShowRewardedAd();
        }

        });

    // INTERSTITIAL
    MenuItemFont* interstitialShowMenu = MenuItemFont::create("Show Interstitial", [&](cocos2d::Ref* pSender) {
        if (isInterstitialLoaded == true)
        {
            ShowInterstitialAd();
        }

        });

    Menu* menu = Menu::create(bannerShowMenu, bannerDismissMenu, rewardedShowMenu, interstitialShowMenu, NULL);
    menu->setPosition(centerPoint);
    menu->alignItemsVerticallyWithPadding(14);

    contentsLayer->addChild(menu);

    /* UPDATE */
    this->scheduleUpdate();
    this->schedule(CC_SCHEDULE_SELECTOR(ExampleScene::LoadRewardedAd), 1.0f, CC_REPEAT_FOREVER, 0.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(ExampleScene::LoadInterstitialAd), 1.0f, CC_REPEAT_FOREVER, 0.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(ExampleScene::LoadBannerAd), 1.0f, CC_REPEAT_FOREVER, 0.0f);

    return (true);
}

void ExampleScene::update(float delta)
{
    Scene::update(delta);
}

void ExampleScene::onEnter()
{
    Scene::onEnter();
}

void ExampleScene::onExit()
{
    Scene::onExit();
}

void ExampleScene::LoadRewardedAd(float delta)
{
    isRewardedLoaded = IsRewardAdLoaded();
    if (isRewardedLoaded == true)
    {
        this->unschedule(CC_SCHEDULE_SELECTOR(ExampleScene::LoadRewardedAd));
    }
}

void ExampleScene::LoadInterstitialAd(float delta)
{
    isInterstitialLoaded = IsInterstitialAdLoaded();
    if (isRewardedLoaded == true)
    {
        this->unschedule(CC_SCHEDULE_SELECTOR(ExampleScene::LoadInterstitialAd));
    }
}

void ExampleScene::LoadBannerAd(float delta)
{
    isBannerLoaded = IsBannerAdLoaded();
    if (isBannerLoaded == true)
    {
        this->unschedule(CC_SCHEDULE_SELECTOR(ExampleScene::LoadBannerAd));
    }
}

