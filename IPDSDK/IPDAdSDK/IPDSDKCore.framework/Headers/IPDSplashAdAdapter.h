//
//  IPDSplashAdAdapter.h
//  IPDSDKCore
//
//  Created by Robin on 2020/12/22.
//

#import <IPDSDKCore/IPDTierAdAdapter.h>
#import <IPDSDKCore/IPDSplashAdProtocol.h>
#import <IPDSDKCore/IPDSplashAdAdapterDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDSplashAdAdapter : IPDTierAdAdapter<IPDSplashAdProtocol>


@property (nonatomic, weak) id <IPDSplashAdAdapterDelegate> delegate;

@property(nonatomic, strong, readonly) UIView *splashAdapterView;


/**
 *  开屏广告素材加载成功
 */
- (void)ipd_splashAdDidLoad;

/**
 *  开屏广告成功展示
 */
- (void)ipd_splashAdSuccessPresentScreen;

/**
 *  开屏广告点击回调
 */
- (void)ipd_splashAdClicked;


/**
 *  开屏广告即将关闭回调
 */
- (void)ipd_splashAdWillClose;

/**
 *  开屏广告关闭回调
 */
- (void)ipd_splashAdClosed;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)ipd_splashAdApplicationWillEnterBackground;

/**
 * 开屏广告倒记时结束
 */
- (void)ipd_splashAdCountdownEnd;

/**
 *  开屏广告错误
 */
- (void)ipd_splashAdErrorWithError:(nullable NSError *)error;
/**
 *  开屏广告播放错误
 */
- (void)ipd_splashAdDisplayError:(NSError *)error;

/// 事件上报
- (void)reportWithEvent:(IPDEventString)event supplementMsg:(nullable NSString *)supplementMsg;


/// 奖励触发
- (void)ipd_splashAdDidRewardEffectiveWithInfo:(nullable NSDictionary *)info;


@end

NS_ASSUME_NONNULL_END
