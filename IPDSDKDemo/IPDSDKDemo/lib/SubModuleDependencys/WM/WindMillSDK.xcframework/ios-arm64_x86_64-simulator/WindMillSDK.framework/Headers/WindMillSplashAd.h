//
//  WindMillSplashAd.h
//  WindSDK
//
//  Created by happyelements on 2018/7/30.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class WindMillAdRequest;
@class WindMillSplashAd;
@class WindMillAdInfo;

@protocol WindMillSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告素材加载成功
 */
- (void)onSplashAdDidLoad:(WindMillSplashAd *)splashAd;

/**
 *  开屏广告加载失败
 */
-(void)onSplashAdLoadFail:(WindMillSplashAd *)splashAd error:(NSError *)error;

/**
 *  开屏广告成功展示
 */
-(void)onSplashAdSuccessPresentScreen:(WindMillSplashAd *)splashAd;

/**
 *  开屏广告展示失败
 */
-(void)onSplashAdFailToPresent:(WindMillSplashAd *)splashAd withError:(NSError *)error;

/**
 *  开屏广告点击回调
 */
- (void)onSplashAdClicked:(WindMillSplashAd *)splashAd;

/**
 *  开屏广告点击跳过
 */
- (void)onSplashAdSkiped:(WindMillSplashAd *)splashAd;

/**
 *  开屏广告将要关闭回调
 */
- (void)onSplashAdWillClosed:(WindMillSplashAd *)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)onSplashAdClosed:(WindMillSplashAd *)splashAd;

/**
 *  开屏小窗口点击
 */
- (void)onSplashZoomOutViewAdDidClick:(WindMillSplashAd *)splashAd;

/**
 *  开屏小窗口关闭
 */
- (void)onSplashZoomOutViewAdDidClose:(WindMillSplashAd *)splashAd;

@end

@interface WindMillSplashAd : NSObject

@property (nonatomic, weak) id<WindMillSplashAdDelegate> delegate;

@property (nonatomic,strong, readonly) NSString *placementId;

/// 必须设置，否则有可能导致无法点击跳转
@property (nonatomic, weak) UIViewController *rootViewController;


@property (nonatomic, strong, readonly) WindMillAdInfo *adInfo;


/// 初始化splash ad对象，当请求和播放分开处理时，使用改构造函数
/// @param request 广告请求对象
/// @param extra 各个平台需要的扩展参数
///     1、kWindMillSplashExtraBottomView: 如果需要品牌区，需要通过改参数设置，类型：UIView
///     2、kWindMillSplashExtraAdSize: 如果需要品牌区，需要通过改参数设置，类型NSString,字符串格式为NSStringFromCGSize
- (instancetype)initWithRequest:(WindMillAdRequest *)request
                              extra:(NSDictionary *)extra;


/**
 * 返回广告是否可展示
 * 对于并行请求，在调用showAdInWindow前时需判断下
 * @return 当广告已经加载完成且未曝光时，为YES，否则为NO
 */
- (BOOL)isAdReady;

/**
 *  广告发起请求并自动展示在Window中
 *  详解：[可选]发起拉取广告请求,并将获取的广告以全屏形式展示在传入的Window参数中
 */
-(void)loadAdAndShow;

/**
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面或是自定义View
 *  详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
 *       请注意bottomView需设置好宽高，所占的空间不能过大，并保证广告界面的高度大于360
 *  @param bottomView 自定义底部View，可以在此View中设置应用Logo
 *
 */
-(void)loadAdAndShowWithBottomView:(UIView *)bottomView;

/**
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面
 *  详解：[logo会自动读取应用图标]
 *
 @param title 设置标题
 @param description 设置描述信息
 */
- (void)loadADAndShowWithTitle:(NSString *)title description:(NSString *)description;


/**
 *  发起拉取广告请求，只拉取不展示
 *  详解：广告素材及广告图片拉取成功后会回调onSplashAdDidLoad方法，当拉取失败时会回调onSplashAdFailToPresent方法
 */
- (void)loadAd;

/**
 *  展示广告，调用此方法前需调用isAdValid方法判断广告素材是否有效
 *  详解：广告展示成功时会回调onSplashAdSuccessPresentScreen方法，展示失败时会回调onSplashAdFailToPresent方法
 */
- (void)showAdInWindow:(UIWindow *)window withBottomView:(UIView *)bottomView;

/**
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面
 *  详解：[logo会自动读取应用图标]，请中高度位100，宽度为屏幕宽度
 *
 @param window 容器
 @param title 设置标题
 @param desc 设置描述信息
 */
- (void)showAdInWindow:(UIWindow *)window title:(NSString *)title desc:(NSString *)desc;

@end
