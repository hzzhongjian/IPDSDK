//
//  AWMCustomRewardedVideoAdapterBridge.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/13.
//

#import "AWMCustomAdapterBridge.h"

@class WindMillRewardInfo;

@protocol AWMCustomRewardedVideoAdapter;

/// 自定义激励视频广告的adapter的回调协议
@protocol AWMCustomRewardedVideoAdapterBridge <AWMCustomAdapterBridge>

@optional
/// 在广告数据返回时调用该方法，此时广告只是返回还未预加载完成
/// @param adapter 当前适配器
/// @param ext 回传信息
/// @warning 1.客户端竞价时，ext中需要回传kWindMillExtraKeyPrice出价;
/// @warning 2.客户端竞价时，ext中需要回传kWindMillExtraKeyCurrency货币类型, USD或者CNY;
- (void)rewardedVideoAd:(id<AWMCustomRewardedVideoAdapter>)adapter didAdServerResponseWithExt:(NSDictionary *)ext;

/// 在广告中素材加载完成时调用，此时广告预加载完成
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidLoad:(id<AWMCustomRewardedVideoAdapter>)adapter;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)rewardedVideoAd:(id<AWMCustomRewardedVideoAdapter>)adapter
   didLoadFailWithError:(NSError *)error
                    ext:(NSDictionary *)ext;

/// 在广告已经展示时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidVisible:(id<AWMCustomRewardedVideoAdapter>)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)rewardedVideoAdDidShowFailed:(id<AWMCustomRewardedVideoAdapter>)adapter
                               error:(NSError *)error;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidClick:(id<AWMCustomRewardedVideoAdapter>)adapter;

/// 在广告被点击跳过时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidClickSkip:(id<AWMCustomRewardedVideoAdapter>)adapter;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidClose:(id<AWMCustomRewardedVideoAdapter>)adapter;

/// 在广告视频播放完成时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)rewardedVideoAd:(id<AWMCustomRewardedVideoAdapter>)adapter didPlayFinishWithError:(NSError *)error;

/// 在ADN验证激励成功时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param info 激励信息
- (void)rewardedVideoAd:(id<AWMCustomRewardedVideoAdapter>)adapter didRewardSuccessWithInfo:(WindMillRewardInfo *)info;

@end
