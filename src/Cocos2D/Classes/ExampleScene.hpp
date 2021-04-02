#ifndef __EXAMPLE_SCENE_HPP__
#define __EXAMPLE_SCENE_HPP__

#include "cocos2d.h"

USING_NS_CC;

class ExampleScene : public Scene
{
private: /* MAS */
    bool isRewardedLoaded;
    bool isInterstitialLoaded;
    bool isBannerLoaded;

public:
    ExampleScene();
    virtual ~ExampleScene();

    static ExampleScene* createScene();
    static ExampleScene* create();

    virtual bool init() override;
    virtual void update(float delta) override;
    virtual void onEnter() override;
    virtual void onExit() override;

private:
    void LoadRewardedAd(float delta);
    void LoadInterstitialAd(float delta);
    void LoadBannerAd(float delta);
};

#endif // __EXAMPLE_SCENE_HPP__