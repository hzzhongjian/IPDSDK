//
//  IPDContentAdapterStateDelegate.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2023/1/6.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDKCore/IPDTierAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDTubePageAdapter;

@protocol IPDAdapterContentAdapterVideoStateDelegate <NSObject>
@optional
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)ipdAdapter_videoDidStartPlay:(id<IPDContentInfo>)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)ipdAdapter_videoDidPause:(id<IPDContentInfo>)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)ipdAdapter_videoDidResume:(id<IPDContentInfo>)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)ipdAdapter_videoDidEndPlay:(id<IPDContentInfo>)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)ipdAdapter_videoDidFailedToPlay:(id<IPDContentInfo>)videoContent withError:(NSError *)error;

@end



@protocol IPDContentAdapterStateDelegate <NSObject>
@optional
/**
* 内容展示
* @param content 内容模型
*/
- (void)ipdAdapter_contentDidFullDisplay:(id<IPDContentInfo>)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)ipdAdapter_contentDidEndDisplay:(id<IPDContentInfo>)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)ipdAdapter_contentDidPause:(id<IPDContentInfo>)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)ipdAdapter_contentDidResume:(id<IPDContentInfo>)content;

/// 任务完成回调
- (void)ipdAdapter_contentTaskComplete:(id<IPDContentInfo>)content;
@end


@protocol IPDContentAdapterLoadCallBackDelegate <NSObject>

/// 广告对象加载成功
- (void)ipdAdapter_contentLoadSuccess:(IPDTierAdAdapter *)adapter;

/// 广告对象请求失败回调
- (void)ipdAdapter_contentLoadFail:(IPDTierAdAdapter *)adapter error:(NSError *)error;

@end


/// 短剧播放器回调DJXDrawVideoViewControllerDelegate
@protocol IPDShortPlayPlayerCallBackDelegate <NSObject>

@optional

/*! @abstract 视频切换时的回调 */
- (void)ipdAdapter_shortplayDrawVideoCurrentVideoChanged:(NSInteger)index content:(id<IPDContentInfo>)content;

/*! @abstract 加载失败按钮点击重试回调 */
- (void)ipdAdapter_shortplayDrawVideoDidClickedErrorButtonRetry:(id<IPDContentInfo>)content;

/*! @abstract 默认关闭按钮被点击的回调 */
- (void)ipdAdapter_shortplayDrawVideoCloseButtonClicked:(id<IPDContentInfo>)content;

/*! @abstract 数据刷新完成回调 */
- (void)ipdAdapter_shortplayDrawVideoDataRefreshCompletion:(NSError *)error content:(id<IPDContentInfo>)content;

/*! @abstract tab栏切换控制器的回调*/
- (void)ipdAdapter_shortplayPageViewControllerSwitchToIndex:(NSInteger)index content:(id<IPDContentInfo>)content;

@end


// 广告回调
@protocol IPDShortPlayAdCallBackDelegate <NSObject>

@optional

/*! @abstract 发起广告请求 */
- (void)ipdAdapter_shortplaySendAdRequest:(id<IPDContentInfo>)content;

/*! @abstract 广告加载成功 */
- (void)ipdAdapter_shortplayAdLoadSuccess:(id<IPDContentInfo>)content;

/*! @abstract 广告加载失败 */
- (void)ipdAdapter_shortplayAdLoadFail:(id<IPDContentInfo>)content error:(NSError *)error;

/*! @abstract 广告填充失败 */
- (void)ipdAdapter_shortplayAdFillFail:(id<IPDContentInfo>)content;

/*! @abstract 广告曝光 */
- (void)ipdAdapter_shortplayAdWillShow:(id<IPDContentInfo>)content;

/*! @abstract 视频广告开始播放 */
- (void)ipdAdapter_shortplayVideoAdStartPlay:(id<IPDContentInfo>)content;

/*! @abstract 视频广告暂停播放 */
- (void)ipdAdapter_shortplayVideoAdPause:(id<IPDContentInfo>)content;

/*! @abstract 视频广告继续播放 */
- (void)ipdAdapter_shortplayVideoAdContinue:(id<IPDContentInfo>)content;

/*! @abstract 视频广告停止播放 */
- (void)ipdAdapter_shortplayVideoAdOverPlay:(id<IPDContentInfo>)content;

/*! @abstract 点击广告 */
- (void)ipdAdapter_shortplayClickAdViewEvent:(id<IPDContentInfo>)content;
/*! @abstract 广告缓冲 */
- (void)ipdAdapter_shortplayVideoBufferEvent:(id<IPDContentInfo>)content;

/*! @abstract 激励视频广告结束 */
- (void)ipdAdapter_shortplayVideoRewardFinishEvent:(id<IPDContentInfo>)content;

/*! @abstract 激励视频广告跳过 */
- (void)ipdAdapter_shortplayVideoRewardSkipEvent:(id<IPDContentInfo>)content;

@end


// 业务接口回调
@protocol IPDShortPlayInterfaceCallBackDelegate <NSObject>

/*! @abstract 解锁流程开始 */
- (void)ipdAdapter_shortplayPlayletDetailUnlockFlowStart:(id<IPDContentInfo>)content;

/*! @abstract 解锁流程取消 */
- (void)ipdAdapter_shortplayPlayletDetailUnlockFlowCancel:(id<IPDContentInfo>)content;

/*! 是否需要自定义解锁弹窗 */
- (BOOL)ipdAdapter_shortplayPlayletDetailCustomUnlockView;

/*! 自定义解锁弹窗 cancelUnlockCallback取消回调，unlockCallback确认的回调 */
- (void)ipdAdapter_shortplayPlayletDetailUnlockFlowCancelUnlock:(void (^)(void))cancelUnlockCallback
                                                unlockCallback:(void(^)(void))unlockCallback;

/*! @abstract 解锁流程结束，回调解锁结果
 *  - success: 是否解锁成功
 *   - error: 解锁失败错误信息
 */
- (void)ipdAdapter_shortplayPlayletDetailUnlockFlowEnd:(id<IPDContentInfo>)content
                           success:(BOOL)success
                             error:(NSError * _Nullable)error;

@optional

/*! @abstract 点击混排中进入跳转播放页的按钮 */
- (void)ipdAdapter_shortplayClickEnterView:(id<IPDContentInfo>)content;

/*! @abstract 本剧集观看完毕，切到下一部短剧回调 */
- (void)ipdAdapter_shortplayNextPlayletWillPlay:(id<IPDContentInfo>)content;

- (UIView *)ipdAdapter_shortplayPlayletDetailBottomBanner:(id<IPDContentInfo>)content;

@end


// 自定义详情页cell试图
@protocol IPDShortPlayCustomViewCallBackDelegate <NSObject>

/// 创建自定义View直接返回，外部不要持有，cell自己持有复用
/// @param cell 短剧的cell
- (UIView *)ipdAdapter_shortplayPlayletDetailCellCustomView:(UITableViewCell *)cell;
/// 根据数据更新UI
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View，短剧的cell内部会持有
/// @param playletInfo 短剧的数据
- (void)ipdAdapter_shortplayPlayletDetailCell:(UITableViewCell *)cell updateCustomView:(UIView *)customView withPlayletData:(id)playletInfo;

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)ipdAdapter_shortplayPlayletDetailCell:(UITableViewCell *)cell layoutSubviews:(UIView *)customView;

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)ipdAdapter_shortplayPlayletDetailCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)customView;

@end

/// 自定义Draw流的subview
@protocol IPDShortPlayCustomDrawAdViewCallBackDelegate <NSObject>

- (UIView *)ipdAdapter_shortplayDetailCellCreateAdView:(UITableViewCell *)cell adInputIndex:(NSUInteger)adIndex;

- (void)ipdAdapter_shortplayDetailCell:(UITableViewCell *)cell bindDataToDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

@optional

- (void)ipdAdapter_shortplayDetailCell:(UITableViewCell *)cell layoutSubview:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)ipdAdapter_shortplayDetailCell:(UITableViewCell *)cell willDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;

- (void)ipdAdapter_shortplayDetailCell:(UITableViewCell *)cell didEndDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex;


@end


/// 滑滑溜底部自定义Banner广告
@protocol IPDShortPlayDrawVideoViewControllerBannerCallBackDelegate <NSObject>

- (UIView *)ipdAdapter_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc adapter:(IPDTubePageAdapter *)adapter;

@end


NS_ASSUME_NONNULL_END
