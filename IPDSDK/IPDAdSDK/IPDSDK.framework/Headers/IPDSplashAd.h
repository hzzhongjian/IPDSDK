//
//  IPDSplashAd.h
//  IPDSDK
//
//  Created by Rare on 2022/2/28.
//  Copyright © 2022 zj. All rights reserved.
//

#import <IPDSDK/IPDTierAd.h>
#import <IPDSDKCore/IPDSplashAdProtocol.h>
#import <IPDSDKCore/IPDSplashAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDSplashAd;

@protocol IPDSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
- (void)ipd_splashAdDidLoad:(IPDSplashAd *)splashAd;

/**
 *  开屏广告成功展示
 */
- (void)ipd_splashAdSuccessPresentScreen:(IPDSplashAd *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)ipd_splashAdClicked:(IPDSplashAd *)splashAd;

/**
 *  开屏广告即将关闭回调
 */
- (void)ipd_splashAdWillClose:(IPDSplashAd *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)ipd_splashAdClosed:(IPDSplashAd *)splashAd;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)ipd_splashAdApplicationWillEnterBackground:(IPDSplashAd *)splashAd;

/**
 * 开屏广告倒记时结束
 */
- (void)ipd_splashAdCountdownEnd:(IPDSplashAd *)splashAd;

/**
 *  开屏广告错误
 */
- (void)ipd_splashAdError:(IPDSplashAd *)splashAd withError:(NSError *)error;

/**
 *  开屏广告播放错误
 */
- (void)ipd_splashAdDisplayError:(IPDSplashAd *)splashAd withError:(NSError *)error;

/// 奖励触发
- (void)ipd_splashAdDidRewardEffective:(IPDSplashAd *)splashAd withInfo:(nullable NSDictionary *)info;

@end


@interface IPDSplashAd : IPDTierAd<IPDSplashAdProtocol>

@property (nonatomic, weak) id <IPDSplashAdDelegate> delegate;

@property (nonatomic, strong,nullable) IPDSplashAdAdapter *currentAdapter;

@end

NS_ASSUME_NONNULL_END
