//
//  AWMCustomSpalshAdapterBridge.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/17.
//

@protocol AWMCustomSplashAdapter;

@protocol AWMCustomSplashAdapterBridge <AWMCustomAdapterBridge>
/// 在广告数据成功返回时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
/// @warning 如何开启了客户端bidding,则ext中需要回传price和货币类型
- (void)splashAd:(id<AWMCustomSplashAdapter>)adapter didAdServerResponseWithExt:(NSDictionary *)ext;

/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidLoad:(id<AWMCustomSplashAdapter>)adapter;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)splashAd:(id<AWMCustomSplashAdapter>)adapter didLoadFailWithError:(NSError *)error ext:(NSDictionary *)ext;

/// 在广告即将展示时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillVisible:(id<AWMCustomSplashAdapter>)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)splashAdDidShowFailed:(id<AWMCustomSplashAdapter>)adapter error:(NSError *)error;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClick:(id<AWMCustomSplashAdapter>)adapter;

/// 在广告跳过事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClickSkip:(id<AWMCustomSplashAdapter>)adapter;

/// 在广告关闭事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClose:(id<AWMCustomSplashAdapter>)adapter;

/// 在zoom out 视图点击事件触发时调用，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdZoomOutViewDidClick:(id<AWMCustomSplashAdapter>)adapter;

/// 当zoom out 视图关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdZoomOutViewDidClose:(id<AWMCustomSplashAdapter>)adapter;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;
@end
