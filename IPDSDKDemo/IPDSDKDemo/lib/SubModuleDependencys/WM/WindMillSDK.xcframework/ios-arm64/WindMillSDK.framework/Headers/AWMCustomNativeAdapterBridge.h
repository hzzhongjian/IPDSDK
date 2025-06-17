//
//  AWMCustomNativeAdapterBridge.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/20.
//

@class AWMMediatedNativeAd;
@protocol AWMCustomNativeAdapter;

@protocol AWMCustomNativeAdapterBridge <AWMCustomAdapterBridge>
@optional

#pragma mark - Load
/// 在广告数据成功返回时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
/// @warning 如何开启了客户端bidding,则ext中需要回传price和货币类型
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
didAdServerResponseWithExt:(NSDictionary *_Nonnull)ext;

/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ads 广告数据组
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
didLoadWithNativeAds:(NSArray<AWMMediatedNativeAd *> *_Nonnull)ads;


/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
didLoadFailWithError:(NSError *_Nonnull)error;

#pragma mark - View

/// 广告展示时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd  广告数据，native广告请传递原始数据（即AWMMediatedNativeAd.originMediatedNativeAd），express广告请传递上报ToBid的UIView
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
didVisibleWithMediatedNativeAd:(id _Nonnull)nativeAd;

/// 广告点击事件时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即AWMMediatedNativeAd.originMediatedNativeAd），express广告请传递上报ToBid的UIView
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
didClickWithMediatedNativeAd:(id _Nonnull)nativeAd;

/// 在广告即将展示详情页时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即AWMMediatedNativeAd.originMediatedNativeAd），express广告请传递上报ToBid的UIView
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
willPresentFullScreenModalWithMediatedNativeAd:(id _Nonnull)nativeAd;

/// 在广告落地页关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即AWMMediatedNativeAd.originMediatedNativeAd），express广告请传递上报ToBid的UIView
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
didDismissFullScreenModalWithMediatedNativeAd:(id _Nonnull)nativeAd;

/// 在模板广告关闭的时候调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即AWMMediatedNativeAd.originMediatedNativeAd），express广告请传递上报ToBid的UIView
/// @param filterWords 用户手动关闭时的关闭原因描述
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
        didClose:(id _Nonnull)nativeAd
    closeReasons:(NSArray<NSString *> *_Nullable)filterWords;
#pragma mark - Express ad
/// 仅限模板广告，在渲染成功或者模板广告的尺寸更新时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param expressView 模板广告
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
renderSuccessWithExpressView:(UIView *_Nonnull)expressView;

/// 仅限模板广告，在渲染失败调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param expressView 模板广告
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
renderFailWithExpressView:(UIView *_Nonnull)expressView
        andError:(NSError *_Nonnull)error;

#pragma mark - Video
/// 视频广告中视频播放状态变更的时候调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param state 播放状态
/// @param nativeAd 广告数据，native广告请传递原始数据（即AWMMediatedNativeAd.originMediatedNativeAd），express广告请传递上报ToBid的UIView
- (void)nativeAd:(id<AWMCustomNativeAdapter>_Nonnull)adapter
videoStateDidChangedWithState:(WindMillMediaPlayerStatus)state
     andNativeAd:(id _Nonnull)nativeAd;

@end
