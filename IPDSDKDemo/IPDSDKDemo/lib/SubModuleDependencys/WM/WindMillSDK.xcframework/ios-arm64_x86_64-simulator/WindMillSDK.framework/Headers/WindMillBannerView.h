//
//  WindMillBannerView.h
//  WindMillSDK
//
//  Created by Codi on 2022/3/18.
//

#import <UIKit/UIKit.h>

@class WindMillAdRequest;
@class WindMillBannerView;
@class WindMillAdInfo;

@protocol WindMillBannerViewDelegate <NSObject>

@optional
//bannerView自动刷新
- (void)bannerAdViewDidAutoRefresh:(WindMillBannerView *)bannerAdView;
//bannerView自动刷新失败
- (void)bannerView:(WindMillBannerView *)bannerAdView failedToAutoRefreshWithError:(NSError *)error;
//成功加载广告
- (void)bannerAdViewLoadSuccess:(WindMillBannerView *)bannerAdView;
//广告加载失败
- (void)bannerAdViewFailedToLoad:(WindMillBannerView *)bannerAdView error:(NSError *)error;
//广告将要展示
- (void)bannerAdViewWillExpose:(WindMillBannerView *)bannerAdView;
//广告被点击
- (void)bannerAdViewDidClicked:(WindMillBannerView *)bannerAdView;
//当用户由于点击要离开您的应用程序时触发该回调,您的应用程序将移至后台
- (void)bannerAdViewWillLeaveApplication:(WindMillBannerView *)bannerAdView;
//将打开全屏视图。在打开storekit或在应用程序中打开网页时触发
- (void)bannerAdViewWillOpenFullScreen:(WindMillBannerView *)bannerAdView;
//将关闭全屏视图。关闭storekit或关闭应用程序中的网页时发送
- (void)bannerAdViewCloseFullScreen:(WindMillBannerView *)bannerAdView;
//广告视图被移除
- (void)bannerAdViewDidRemoved:(WindMillBannerView *)bannerAdView;
@end

@interface WindMillBannerView : UIView
/**
 *  委托 [可选]
 */
@property (nonatomic, weak) id<WindMillBannerViewDelegate> delegate;

/**
 *  视图控制器 [必传]
 */
@property (nonatomic, weak) UIViewController *viewController;

/**
 *  Banner展现和轮播时的动画效果开关，默认打开 [可选]
 */
@property (nonatomic) BOOL animated;

/**
 *  广告位ID
 */
@property (nonatomic, copy, readonly) NSString *placementId;

/**
 *  广告是否有效，以下情况会返回NO，建议在展示广告之前判断，否则会影响计费或展示失败
 *  a.广告未拉取成功
 *  b.广告过期
 */
@property (nonatomic, readonly) BOOL isAdValid;

/**
 *  在广告展示后，描述当前播放广告源信息
 */
@property (nonatomic, strong, readonly) WindMillAdInfo *adInfo;

/**
 *  广告内容大小
 */
@property (nonatomic, assign, readonly) CGSize adSize;

/**
 *  构造方法
 *  详解：request - 广告请求对象
 */
- (instancetype)initWithRequest:(WindMillAdRequest *)request;

/**
 *  构造方法
 *  详解：request - 广告请求对象
 *  详解：expectSize - 期望的广告视图大小
 */
- (instancetype)initWithRequest:(WindMillAdRequest *)request
                     expectSize:(CGSize)expectSize;

/**
 *  拉取广告
 */
- (void)loadAdData;

@end
