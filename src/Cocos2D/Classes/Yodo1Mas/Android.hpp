#include"cocos2d.h"

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"

// ALIGN BIT FLAGS
const static int BannerLeft = 1;
const static int BannerHorizontalCenter = 1 << 1;
const static int BannerRight = 1 << 2;
const static int BannerTop = 1 << 3;
const static int BannerVerticalCenter = 1 << 4;
const static int BannerBottom = 1 << 5;

#endif

/* LOAD */
static bool IsBannerAdLoaded()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    jboolean isLoaded = false;
    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "IsBannerAdLoaded", "()Z") == true)
    {
        isLoaded = (jboolean)t.env->CallStaticBooleanMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }

    return (isLoaded);
#else
    return (false);
#endif
}

static bool IsInterstitialAdLoaded()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    jboolean isLoaded = false;
    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "IsInterstitialAdLoaded", "()Z") == true)
    {
        isLoaded = (jboolean)t.env->CallStaticBooleanMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }

    return (isLoaded);
#else
    return (false);
#endif
}

static bool IsRewardAdLoaded()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    jboolean isLoaded = false;
    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "IsRewardAdLoaded", "()Z") == true)
    {
        isLoaded = (jboolean)t.env->CallStaticBooleanMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }

    return (isLoaded);
#else
    return (false);
#endif
}

/* SHOW */
static void ShowRewardedAd()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "ShowRewardedAd", "()V") == true)
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
#endif
}

static void ShowInterstitialAd()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "ShowInterstitialAd", "()V") == true)
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
#endif
}

static void ShowBannerAd()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "ShowBannerAd", "(III)V") == true)
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, BannerTop | BannerHorizontalCenter, 0, 0);
        t.env->DeleteLocalRef(t.classID);
    }
#endif
}

static void ShowBannerAd(int _align)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "ShowBannerAd", "(III)V") == true)
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, _align, 0, 0);
        t.env->DeleteLocalRef(t.classID);
    }
#endif
}

static void ShowBannerAd(int _align, int _offsetX, int _offsetY)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "ShowBannerAd", "(III)V") == true)
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID, _align, _offsetX, _offsetY);
        t.env->DeleteLocalRef(t.classID);
    }
#endif
}

/* DISMISS */
static void DismissBannerAd()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "DismissBannerAd", "()V") == true)
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
#endif
}