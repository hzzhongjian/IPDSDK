//
//  AWMCustomBannerAdapterBridge.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/17.
//
#import <Foundation/Foundation.h>
@protocol AWMCustomBannerAdapter;

@protocol AWMCustomBannerAdapterBridge <AWMCustomAdapterBridge>

/// 在广告数据成功返回时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param bannerView 广告视图
/// @param ext 回传信息
/// @warning 如何开启了客户端bidding,则ext中需要回传price和货币类型
- (void)bannerAd:(id<AWMCustomBannerAdapter>)adapter didAdServerResponse:(UIView *)bannerView ext:(NSDictionary *)ext;

/// 在广告加载成功时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param bannerView 广告视图
- (void)bannerAd:(id<AWMCustomBannerAdapter>)adapter didLoad:(UIView *)bannerView;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)bannerAd:(id<AWMCustomBannerAdapter>)adapter didLoadFailWithError:(NSError *)error ext:(NSDictionary *)ext;

/// 在广告已经展示的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param bannerView 广告视图
- (void)bannerAdDidBecomeVisible:(id<AWMCustomBannerAdapter>)adapter bannerView:(UIView *)bannerView;

/// 在广告弹出详情页或者展示展示appstore时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param bannerView 广告视图
- (void)bannerAdWillPresentFullScreenModal:(id<AWMCustomBannerAdapter>)adapter bannerView:(UIView *)bannerView;

/// 在广告关闭详情页或者appstore时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param bannerView 广告视图
- (void)bannerAdWillDismissFullScreenModal:(id<AWMCustomBannerAdapter>)adapter bannerView:(UIView *)bannerView;

/// 当用户由于点击要离开您的应用程序时调用该方法,直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param bannerView 广告视图
- (void)bannerAdWillLeaveApplication:(id<AWMCustomBannerAdapter>)adapter bannerAdView:(UIView *)bannerView;

/// 在广告触发点击事件时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param bannerView 广告视图
- (void)bannerAdDidClick:(id<AWMCustomBannerAdapter>)adapter bannerView:(UIView *)bannerView;

/// 在广告关闭时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param bannerView 广告视图
- (void)bannerAdDidClosed:(id<AWMCustomBannerAdapter>)adapter bannerView:(UIView *)bannerView;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;
@end
