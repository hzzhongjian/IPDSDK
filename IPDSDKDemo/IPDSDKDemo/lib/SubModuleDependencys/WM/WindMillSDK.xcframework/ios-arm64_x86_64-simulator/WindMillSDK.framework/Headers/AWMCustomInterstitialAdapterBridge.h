//
//  AWMCustomInterstitialAdapterBridge.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/17.
//

@protocol AWMCustomInterstitialAdapter;

@protocol AWMCustomInterstitialAdapterBridge <AWMCustomAdapterBridge>

@optional
/// 在广告数据返回时调用该方法，此时广告只是返回还未预加载完成
/// @param adapter 当前适配器
/// @param ext 回传信息
/// @warning 1.客户端竞价时，ext中需要回传kWindMillExtraKeyPrice出价;
/// @warning 2.客户端竞价时，ext中需要回传kWindMillExtraKeyCurrency货币类型, USD或者CNY;
- (void)interstitialAd:(id<AWMCustomInterstitialAdapter>)adapter
didAdServerResponseWithExt:(NSDictionary *)ext;

/// 在广告中素材加载完成时调用，此时广告预加载完成
/// @param adapter 当前适配器
- (void)interstitialAdDidLoad:(id<AWMCustomInterstitialAdapter>)adapter;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)interstitialAd:(id<AWMCustomInterstitialAdapter>)adapter
   didLoadFailWithError:(NSError *)error
                    ext:(NSDictionary *)ext;

/// 在广告已经展示时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidVisible:(id<AWMCustomInterstitialAdapter>)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)interstitialAdDidShowFailed:(id<AWMCustomInterstitialAdapter>)adapter
                               error:(NSError *)error;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidClick:(id<AWMCustomInterstitialAdapter>)adapter;

/// 在广告被点击跳过时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidClickSkip:(id<AWMCustomInterstitialAdapter>)adapter;

/// 在广告视频播放完成时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)interstitialAd:(id<AWMCustomInterstitialAdapter>)adapter didPlayFinishWithError:(NSError *)error;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidClose:(id<AWMCustomInterstitialAdapter>)adapter;
@end
