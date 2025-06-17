//
//  WindNativeView.h
//  WindSDK
//
//  Created by Codi on 2021/7/27.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WindMillSDK/WindMillEnum.h>

@class WindMillAdInfo;
@class WindMillNativeAdView;
@class WindMillNativeAd;
@class WindMillDislikeWords;

@protocol WindMillNativeAdViewDelegate <NSObject>

@optional
/**
 * 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 * （只针对模版渲染）
 */
- (void)nativeExpressAdViewRenderSuccess:(WindMillNativeAdView *)nativeExpressAdView;

/**
 * 原生模板广告渲染失败
 * （只针对模版渲染）
 */
- (void)nativeExpressAdViewRenderFail:(WindMillNativeAdView *)nativeExpressAdView error:(NSError *)error;

/**
 广告曝光回调

 @param nativeAdView WindMillNativeAdView 实例
 */
- (void)nativeAdViewWillExpose:(WindMillNativeAdView *)nativeAdView;

/**
 广告点击回调

 @param nativeAdView WindMillNativeAdView 实例
 */
- (void)nativeAdViewDidClick:(WindMillNativeAdView *)nativeAdView;

/**
 广告详情页关闭回调

 @param nativeAdView WindMillNativeAdView 实例
 */
- (void)nativeAdDetailViewClosed:(WindMillNativeAdView *)nativeAdView;

/**
 广告详情页面即将展示回调

 @param nativeAdView WindMillNativeAdView 实例
 */
- (void)nativeAdDetailViewWillPresentScreen:(WindMillNativeAdView *)nativeAdView;

/**
 视频广告播放状态更改回调

 @param nativeAdView WindMillNativeAdView 实例
 @param status 视频广告播放状态
 @param userInfo 视频广告信息
 */
- (void)nativeAdView:(WindMillNativeAdView *)nativeAdView playerStatusChanged:(WindMillMediaPlayerStatus)status userInfo:(NSDictionary *)userInfo;

/**
 点击dislike回调
 开发者需要在这个回调中移除视图，否则，会出现用户点击叉无效的情况
 
 @param filterWords : 选择不喜欢的原因
 */
- (void)nativeAdView:(WindMillNativeAdView *)nativeAdView dislikeWithReason:(NSArray<WindMillDislikeWords *> *)filterWords;
@end


@interface WindMillNativeAdView : UIView

@property (nonatomic, strong, readonly) WindMillNativeAd *nativeAd;

@property (nonatomic, strong, readonly) WindMillAdInfo *adInfo;

/**
 广告 View 回调对象
 */
@property (nonatomic, weak) id<WindMillNativeAdViewDelegate> delegate;

/*
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;

/**
 视频组件
 */
@property (nonatomic, strong, readonly) UIView *mediaView;

/**
 广告平台logo组件
 */
@property (nonatomic, strong, readonly) UIView *logoView;

/**
 dislike组件
 */
@property (nonatomic, strong, readonly) UIButton *dislikeButton;

/**
 单图广告对应的图片组件
 */
@property (nonatomic, strong, readonly) UIImageView *mainImageView;

/**
 3张小图
 */
@property (nonatomic, strong, readonly) NSArray<UIImageView *> *imageViewList;
- (instancetype)initWithFrame:(CGRect)frame;

/**
 每次获取物料信息后需要刷新调用refreshData:方法
 */
- (void)refreshData:(WindMillNativeAd *)nativeAd;

/**
 在物料加载成功方法里获取相关广告信息赋值后，需调用 setClickableViews:绑定点击的View
 */
- (void)setClickableViews:(NSArray<UIView *> *)clickableViews;

- (void)setPlaceholderImage:(UIImage *)placeholderImage;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 WindMillNativeAdView 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，
 将广告对象与 WindMillNativeAdView 解绑
 */
- (void)unregisterDataObject;

@end

