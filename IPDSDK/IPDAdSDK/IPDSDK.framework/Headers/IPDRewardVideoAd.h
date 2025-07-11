//
//  ZJRewardAd.h
//  ZJSDK
//
//  Created by Rare on 2022/3/1.
//  Copyright © 2022 zj. All rights reserved.
//

#import <IPDSDK/IPDTierAd.h>
#import <IPDSDKCore/IPDRewardVideoAdProtocol.h>
#import <IPDSDKCore/IPDRewardVideoAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class  IPDRewardVideoAd;

@protocol IPDRewardVideoAdDelegate <NSObject>

@optional
/**
广告数据加载成功回调
 ⚠️请勿在该回调内调用 showAdInViewController:方法（需视频下载完成）
@param rewardedVideoAd IPDRewardVideoAd 实例
*/
- (void)ipd_rewardVideoAdDidLoad:(IPDRewardVideoAd *)rewardedVideoAd;

/**
 视频数据下载成功回调，已经下载过的视频会直接回调，在这里调用展示广告的方法。
 ✅ showAdInViewController: 方法请在该回调中执行 ， 广告展示需要在视频下载完成后才能展示，
@param rewardedVideoAd IPDRewardVideoAd 实例
*/
- (void)ipd_rewardVideoAdVideoDidLoad:(IPDRewardVideoAd *)rewardedVideoAd;

/**
 视频广告展示
 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidShow:(IPDRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭
 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidClose:(IPDRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击
 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidClicked:(IPDRewardVideoAd *)rewardedVideoAd;

/**
 视频广告播放达到激励条件回调
 @param rewardedVideoAd IPDRewardVideoAd 实例，
 可以从rewardedVideoAd获取此次广告行为的交易id  ：trade_id
 */
- (void)ipd_rewardVideoAdDidRewardEffective:(IPDRewardVideoAd *)rewardedVideoAd;

/**
 视频广告视频播放完成
 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidPlayFinish:(IPDRewardVideoAd *)rewardedVideoAd;


/// 正常情况不需要此方法，请不要使用此方法作为判断依据
/// @param rewardedVideoAd 激励广告
/// @param success 是否成功
/// @param error 错误信息
- (void)ipd_rewardVideoAd:(IPDRewardVideoAd *)rewardedVideoAd serviceCheckResult:(BOOL)success error:(NSError *)error;
/**
 视频广告加载错误信息回调
 @param rewardedVideoAd IPDRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)ipd_rewardVideoAd:(IPDRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;

/**
 视频广告播放错误信息回调
 @param rewardedVideoAd IPDRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)ipd_rewardVideoAd:(IPDRewardVideoAd *)rewardedVideoAd displayFailWithError:(NSError *)error;

/**
 用户点击视频跳过按钮
 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidClickSkip:(IPDRewardVideoAd *)rewardedVideoAd;

@end


@interface IPDRewardVideoAd : IPDTierAd <IPDRewardVideoAdProtocol>

@property (nonatomic, weak) id <IPDRewardVideoAdDelegate> delegate;

@property (nonatomic,strong,nullable)IPDRewardVideoAdAdapter *currentAdapter;

/**激励视频初始化方法
@param placementId   required 激励视频广告位ID
@param userId   required 由媒体提供urseId， 用于奖励发放的数据校验，是每个用户的唯一标识符。
 */
- (instancetype)initWithPlacementId:(NSString *)placementId userId:(NSString *)userId;

- (instancetype)initWithPlacementId:(NSString *)placementId NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
