//
//  IPDSplashAdAdapterDelegate.h
//  IPDSDKCore
//
//  Created by Robin on 2021/1/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDSplashAdAdapter;

@protocol IPDSplashAdAdapterDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
- (void)ipd_splashAdAdapterDidLoad:(IPDSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告成功展示
 */
- (void)ipd_splashAdAdapterSuccessPresentScreen:(IPDSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告点击回调
 */
- (void)ipd_splashAdAdapterClicked:(IPDSplashAdAdapter *)splashAdAdapter;


/**
 *  开屏广告即将关闭回调
 */
- (void)ipd_splashAdAdapterWillClose:(IPDSplashAdAdapter *)splashAdAdapter;

/**
 *  开屏广告关闭回调
 */
- (void)ipd_splashAdAdapterClosed:(IPDSplashAdAdapter *)splashAdAdapter;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)ipd_splashAdAdapterApplicationWillEnterBackground:(IPDSplashAdAdapter *)splashAdAdapter;

/**
 * 开屏广告倒记时结束
 */
- (void)ipd_splashAdAdapterCountdownEnd:(IPDSplashAdAdapter*)splashAdAdapter;

/**
 *  开屏广告错误
 */
- (void)ipd_splashAdAdapterError:(IPDSplashAdAdapter *)splashAdAdapter withError:(NSError *)error;

/**
 *  开屏广告播放错误
 */
- (void)ipd_splashAdAdapterDisplayError:(IPDSplashAdAdapter *)splashAdAdapter withError:(NSError *)error;

/// 奖励触发
- (void)ipd_splashAdAdapterDidRewardEffective:(IPDSplashAdAdapter *)splashAdAdapter withInfo:(nullable NSDictionary *)info;

@end

NS_ASSUME_NONNULL_END
