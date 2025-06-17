//
//  IPDFeedFullVideoProviderAdapterDelegate.h
//  IPDSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>

@class IPDFeedFullVideoProviderAdapter,IPDFeedFullVideoView;

NS_ASSUME_NONNULL_BEGIN

@protocol IPDFeedFullVideoProviderAdapterDelegate <NSObject>

/**
 * 广告加载成功
 */
- (void)ipd_feedFullVideoProviderAdapterLoadSuccess:(IPDFeedFullVideoProviderAdapter *)adapter views:(NSArray<__kindof IPDFeedFullVideoView *> *)views;

/**
* 广告加载失败
*/
- (void)ipd_feedFullVideoProviderAdapterLoadFail:(IPDFeedFullVideoProviderAdapter *)adapter error:(NSError *_Nullable)error;

/**
 * 广告渲染成功, IPDFeedFullVideoView.size.height has been updated
 */
- (void)ipd_feedFullVideoAdViewRenderSuccess:(IPDFeedFullVideoProviderAdapter *)adapter view:(IPDFeedFullVideoView *)adView;

/**
 * 广告渲染失败
 */
- (void)ipd_feedFullVideoAdViewRenderFail:(IPDFeedFullVideoProviderAdapter *)adapter view:(IPDFeedFullVideoView *)adView error:(NSError *_Nullable)error;

/**
 * 广告曝光回调
 */
- (void)ipd_feedFullVideoAdViewWillShow:(IPDFeedFullVideoProviderAdapter *)adapter view:(IPDFeedFullVideoView *)adView;

/**
视频广告播放状态更改回调
*/
- (void)ipd_feedFullVideoAdViewStateDidChanged:(IPDFeedFullVideoProviderAdapter *)adapter view:(IPDFeedFullVideoView *)adView state:(IPDMediaPlayerStatus)playerState;

- (void)ipd_feedFullVideoAdViewPlayerDidPlayFinish:(IPDFeedFullVideoProviderAdapter *)adapter view:(IPDFeedFullVideoView *)adView;

/**
 * 广告点击回调
 */
- (void)ipd_feedFullVideoAdViewDidClick:(IPDFeedFullVideoProviderAdapter *)adapter view:(IPDFeedFullVideoView *)adView;

/**
* 广告详情页面即将展示回调
*/
- (void)ipd_feedFullVideoAdViewDetailViewWillPresentScreen:(IPDFeedFullVideoProviderAdapter *)adapter view:(IPDFeedFullVideoView *)adView;

/**
 *广告详情页关闭回调
 */
- (void)ipd_feedFullVideoAdViewDetailViewClosed:(IPDFeedFullVideoProviderAdapter *)adapter view:(IPDFeedFullVideoView *)adView;

@end

NS_ASSUME_NONNULL_END
