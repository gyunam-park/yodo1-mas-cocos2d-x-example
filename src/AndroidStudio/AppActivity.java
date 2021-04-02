/****************************************************************************
Copyright (c) 2015-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import android.app.Activity;
import android.os.Bundle;
import org.cocos2dx.lib.Cocos2dxActivity;
import android.os.Build;
import android.view.WindowManager;
import android.view.WindowManager.LayoutParams;

import androidx.annotation.NonNull;

import com.yodo1.mas.Yodo1Mas;
import com.yodo1.mas.error.Yodo1MasError;
import com.yodo1.mas.event.Yodo1MasAdEvent;

public class AppActivity extends Cocos2dxActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.setEnableVirtualButton(false);
        super.onCreate(savedInstanceState);
        // Workaround in https://stackoverflow.com/questions/16283079/re-launch-of-activity-on-home-button-but-only-the-first-time/16447508
        if (!isTaskRoot()) {
            // Android launched another instance of the root activity into an existing task
            //  so just quietly finish and go away, dropping the user back into the activity
            //  at the top of the stack (ie: the last state of this task)
            // Don't need to finish it again since it's finished in super.onCreate .
            return;
        }
        // Make sure we're running on Pie or higher to change cutout mode
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            // Enable rendering into the cutout area
            WindowManager.LayoutParams lp = getWindow().getAttributes();
            lp.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            getWindow().setAttributes(lp);
        }
        // DO OTHER INITIALIZATION BELOW

        ////////////////////////////////////////////////////////////////
        // YODO1MAS INITIALIZE
        ////////////////////////////////////////////////////////////////
        Yodo1Mas.getInstance().init(this, "APP-KEY", new Yodo1Mas.InitListener() {
            @Override
            public void onMasInitSuccessful() {
                // BANNER
                Yodo1Mas.getInstance().setBannerListener(new Yodo1Mas.BannerListener() {
                    @Override
                    public void onAdOpened(@NonNull Yodo1MasAdEvent event) {

                    }

                    @Override
                    public void onAdError(@NonNull Yodo1MasAdEvent event, @NonNull Yodo1MasError error) {

                    }

                    @Override
                    public void onAdClosed(@NonNull Yodo1MasAdEvent event) {

                    }
                });

                // INTERSTITIAL
                Yodo1Mas.getInstance().setInterstitialListener(new Yodo1Mas.InterstitialListener() {
                    @Override
                    public void onAdOpened(@NonNull Yodo1MasAdEvent event) {
                    }

                    @Override
                    public void onAdError(@NonNull Yodo1MasAdEvent event, @NonNull Yodo1MasError error) {

                    }

                    @Override
                    public void onAdClosed(@NonNull Yodo1MasAdEvent event) {

                    }
                });

                // REWARD
                Yodo1Mas.getInstance().setRewardListener(new Yodo1Mas.RewardListener() {
                    @Override
                    public void onAdOpened(@NonNull Yodo1MasAdEvent event) {

                    }

                    @Override
                    public void onAdvertRewardEarned(@NonNull Yodo1MasAdEvent event) {

                    }

                    @Override
                    public void onAdError(@NonNull Yodo1MasAdEvent event, @NonNull Yodo1MasError error) {

                    }

                    @Override
                    public void onAdClosed(@NonNull Yodo1MasAdEvent event) {

                    }
                });
            }

            @Override
            public void onMasInitFailed(@NonNull Yodo1MasError error) {
            }
        });
    }

    ////////////////////////////////////////////////////////////////
    // YODO1MAS METHODS FOR USING IN COCOS2DX
    ////////////////////////////////////////////////////////////////

    // LOAD
    static public boolean IsRewardAdLoaded()
    {
        return Yodo1Mas.getInstance().isRewardedAdLoaded();
    }

    static public boolean IsInterstitialAdLoaded()
    {
        return Yodo1Mas.getInstance().isInterstitialAdLoaded();
    }

    static public boolean IsBannerAdLoaded()
    {
        return Yodo1Mas.getInstance().isBannerAdLoaded();
    }

    // SHOW
    static public void ShowRewardedAd()
    {
        ((Activity)getContext()).runOnUiThread(new Runnable(){
            @Override
            public void run()
            {
                Yodo1Mas.getInstance().showRewardedAd((Activity) getContext());
            }
        });
    }

    static public void ShowInterstitialAd()
    {
        ((Activity)getContext()).runOnUiThread(new Runnable(){
            @Override
            public void run()
            {
                Yodo1Mas.getInstance().showInterstitialAd((Activity) getContext());
            }
        });
    }

    static public void ShowBannerAd(int align, int offsetX, int offsetY)
    {
        ((Activity)getContext()).runOnUiThread(new Runnable(){
            @Override
            public void run()
            {
                Yodo1Mas.getInstance().showBannerAd((Activity) getContext(), align, offsetX, offsetY);
            }
        });
    }

    // DISMISS
    static public void DismissBannerAd()
    {
        ((Activity)getContext()).runOnUiThread(new Runnable(){
            @Override
            public void run()
            {
                Yodo1Mas.getInstance().dismissBannerAd();
            }
        });
    }
}
