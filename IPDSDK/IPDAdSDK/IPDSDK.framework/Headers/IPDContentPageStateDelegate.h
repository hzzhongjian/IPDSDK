//
//  IPDContentPageStateDelegate.h
//  IPDSDK
//
//  Created by 麻明康 on 2023/1/6.
//  Copyright © 2023 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDKCore/IPDContentAdapterStateDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDContentPageVideoStateDelegate <NSObject>
@optional
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)ipd_videoDidStartPlay:(id<IPDContentInfo>)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)ipd_videoDidPause:(id<IPDContentInfo>)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)ipd_videoDidResume:(id<IPDContentInfo>)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)ipd_videoDidEndPlay:(id<IPDContentInfo>)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)ipd_videoDidFailedToPlay:(id<IPDContentInfo>)videoContent withError:(NSError *)error;

/// 一下四个代理方法只在横板视频里面调用
/// 进入横版视频详情页
/// @param viewController 详情页VC
/// @param content 视频信息
- (void)ipd_horizontalFeedVideoDetailDidEnter:(UIViewController *)viewController contentInfo:(id<IPDContentInfo>)content;

/// 离开横版视频详情页
/// @param viewController 详情页VC
- (void)ipd_horizontalFeedVideoDetailDidLeave:(UIViewController *)viewController;

/// 视频详情页appear
/// @param viewController 详情页VC
- (void)ipd_horizontalFeedVideoDetailDidAppear:(UIViewController *)viewController;

/// 详情页disappear
/// @param viewController 详情页VC
- (void)ipd_horizontalFeedVideoDetailDidDisappear:(UIViewController *)viewController;


@end


@protocol IPDContentPageStateDelegate <NSObject>

@optional
/**
* 内容展示
* @param content 内容模型
*/
- (void)ipd_contentDidFullDisplay:(id<IPDContentInfo>)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)ipd_contentDidEndDisplay:(id<IPDContentInfo>)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)ipd_contentDidPause:(id<IPDContentInfo>)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)ipd_contentDidResume:(id<IPDContentInfo>)content;

/// 任务完成回调
- (void)ipdAdapter_contentTaskComplete:(id<IPDContentInfo>)content;

@end

/// 短剧内容加载成功和失败的代理方法，根据加载成功/失败来判断是否可以加载短剧页面
@protocol IPDContentPageLoadCallBackDelegate <NSObject>

@optional
/// 内容加载成功
- (void)ipd_contentPageLoadSuccess;

/// 内容加载失败
- (void)ipd_contentPageLoadFailure:(NSError *)error;

@end


// 从csj开始使用
/// 短剧播放器回调
@protocol IPDShortPlayPlayerDelegate <NSObject>

@optional

/*! @abstract 视频切换时的回调 */
- (void)ipd_shortplayDrawVideoCurrentVideoChanged:(NSInteger)index adapter:(id<IPDContentInfo>)content;

/*! @abstract 加载失败按钮点击重试回调 */
- (void)ipd_shortplayDrawVideoDidClickedErrorButtonRetry:(id<IPDContentInfo>)content;

/*! @abstract 默认关闭按钮被点击的回调 */
- (void)ipd_shortplayDrawVideoCloseButtonClicked:(id<IPDContentInfo>)content;

/*! @abstract 数据刷新完成回调 */
- (void)ipd_shortplayDrawVideoDataRefreshCompletion:(NSError *)error content:(id<IPDContentInfo>)content;

/*! @abstract tab栏切换控制器的回调*/
- (void)ipd_shortplayPageViewControllerSwitchToIndex:(NSInteger)index content:(id<IPDContentInfo>)content;

/**! @abstract 推荐页面底部banner视图**/
- (UIView *)ipd_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc content:(id<IPDContentInfo>)content;

@end


// 广告回调
@protocol IPDShortPlayAdDelegate <NSObject>

@optional

/*! @abstract 发起广告请求 */
- (void)ipd_shortplaySendAdRequest:(id<IPDContentInfo>)content;

/*! @abstract 广告加载成功 */
- (void)ipd_shortplayAdLoadSuccess:(id<IPDContentInfo>)content;

/*! @abstract 广告加载失败 */
- (void)ipd_shortplayAdLoadFail:(id<IPDContentInfo>)content error:(NSError *)error;

/*! @abstract 广告填充失败 */
- (void)ipd_shortplayAdFillFail:(id<IPDContentInfo>)content;

/*! @abstract 广告曝光 */
- (void)ipd_shortplayAdWillShow:(id<IPDContentInfo>)content;

/*! @abstract 视频广告开始播放 */
- (void)ipd_shortplayVideoAdStartPlay:(id<IPDContentInfo>)content;

/*! @abstract 视频广告暂停播放 */
- (void)ipd_shortplayVideoAdPause:(id<IPDContentInfo>)content;

/*! @abstract 视频广告继续播放 */
- (void)ipd_shortplayVideoAdContinue:(id<IPDContentInfo>)content;

/*! @abstract 视频广告停止播放 */
- (void)ipd_shortplayVideoAdOverPlay:(id<IPDContentInfo>)content;

/*! @abstract 点击广告 */
- (void)ipd_shortplayClickAdViewEvent:(id<IPDContentInfo>)content;
/*! @abstract 广告缓冲 */
- (void)ipd_shortplayVideoBufferEvent:(id<IPDContentInfo>)content;

/*! @abstract 激励视频广告结束 */
- (void)ipd_shortplayVideoRewardFinishEvent:(id<IPDContentInfo>)content;

/*! @abstract 激励视频广告跳过 */
- (void)ipd_shortplayVideoRewardSkipEvent:(id<IPDContentInfo>)content;

@end


// 业务接口回调
@protocol IPDShortPlayInterfaceDelegate <NSObject>

/*! @abstract 解锁流程开始 */
- (void)ipd_shortplayPlayletDetailUnlockFlowStart:(id<IPDContentInfo>)content;

/*! @abstract 解锁流程取消 */
- (void)ipd_shortplayPlayletDetailUnlockFlowCancel:(id<IPDContentInfo>)content;

/*! 自定义解锁弹窗 cancelUnlockCallback取消回调，unlockCallback确认的回调 */
- (void)ipd_shortplayPlayletDetailUnlockFlowCancelUnlock:(void (^)(void))cancelUnlockCallback
                                                unlockCallback:(void(^)(void))unlockCallback;

/*! @abstract 解锁流程结束，回调解锁结果
 *  - success: 是否解锁成功
 *   - error: 解锁失败错误信息
 */
- (void)ipd_shortplayPlayletDetailUnlockFlowEnd:(id<IPDContentInfo>)content
                           success:(BOOL)success
                             error:(NSError * _Nullable)error;

@optional

/*! @abstract 点击混排中进入跳转播放页的按钮 */
- (void)ipd_shortplayClickEnterView:(id<IPDContentInfo>)content;

/*! @abstract 本剧集观看完毕，切到下一部短剧回调 */
- (void)ipd_shortplayNextPlayletWillPlay:(id<IPDContentInfo>)content;

- (UIView *)ipd_shortplayPlayletDetailBottomBanner:(id<IPDContentInfo>)content;

@end


// 自定义详情页cell试图
@protocol IPDShortPlayCustomViewDelegate <NSObject>

/// 创建自定义View直接返回，外部不要持有，cell自己持有复用
/// @param cell 短剧的cell
- (UIView *)ipd_shortplayPlayletDetailCellCustomView:(UITableViewCell *)cell;

/// 根据数据更新UI
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View，短剧的cell内部会持有
/// @param playletInfo 短剧的数据
- (void)ipd_shortplayPlayletDetailCell:(UITableViewCell *)cell updateCustomView:(UIView *)customView withPlayletData:(id)playletInfo;

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)ipd_shortplayPlayletDetailCell:(UITableViewCell *)cell layoutSubviews:(UIView *)customView;

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)ipd_shortplayPlayletDetailCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)customView;

@end


/// 自定义Draw流的subview
@protocol IPDShortPlayCustomDrawAdViewDelegate <NSObject>

- (UIView *)ipd_shortplayDetailCellCreateAdView:(UITableViewCell *)cell adInputIndex:(NSUInteger)adIndex;

- (void)ipd_shortplayDetailCell:(UITableViewCell *)cell bindDataToDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

@optional

- (void)ipd_shortplayDetailCell:(UITableViewCell *)cell layoutSubview:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)ipd_shortplayDetailCell:(UITableViewCell *)cell willDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)ipd_shortplayDetailCell:(UITableViewCell *)cell didEndDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;


@end


/// 滑滑溜底部自定义Banner广告
@protocol IPDShortPlayDrawVideoViewControllerBannerDelegate <NSObject>

- (UIView *)ipd_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc;

@end

NS_ASSUME_NONNULL_END
