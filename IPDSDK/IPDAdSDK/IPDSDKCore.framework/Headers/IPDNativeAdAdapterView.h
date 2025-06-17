//
//  IPDNativeAdAdapterView.h
//  IPDSDKCore
//
//  Created by Rare on 2021/6/7.
//

#import <UIKit/UIKit.h>
#import <IPDSDKCore/IPDNativeAdObject.h>
#import <IPDSDKCore/IPDKSAdExposureReportParam.h>
#import <IPDSDKCore/IPDAdUnionItemModel.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDNativeAdAdapterView;

@protocol IPDNativeAdAdapterViewDelegate <NSObject>

@optional
//广告曝光回调
- (void)ipdAdapter_nativeAdViewWillExpose:(IPDNativeAdAdapterView *)nativeAdView;
//广告点击回调
- (void)ipdAdapter_nativeAdViewDidClick:(IPDNativeAdAdapterView *)nativeAdView;
//广告详情页关闭回调
- (void)ipdAdapter_nativeAdDetailViewClosed:(IPDNativeAdAdapterView *)nativeAdView;
//广告详情页面即将展示回调
- (void)ipdAdapter_nativeAdDetailViewWillPresentScreen:(IPDNativeAdAdapterView *)nativeAdView;
//当点击应用下载或者广告调用系统程序打开时调用
- (void)ipdAdapter_NativeAdViewApplicationWillEnterBackground:(IPDNativeAdAdapterView *)nativeAdView;
//广告曝光错误
- (void)ipdAdapter_nativeAdViewShowError:(IPDNativeAdAdapterView *)nativeAdView error:(NSError *)error;

@end


@interface IPDNativeAdAdapterView : UIView

/**
 广告 View 时间回调对象
 */
@property (nonatomic, weak) id<IPDNativeAdAdapterViewDelegate> delegate;

/*
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;


/**
 自渲染2.0视图注册方法
 @param dataObject 数据对象，必传字段
 @param clickableViews 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
 */
- (void)registerDataObject:(IPDNativeAdObject *)dataObject
            clickableViews:(NSArray<UIView *> *)clickableViews;


/**
 注册可点击的callToAction视图的方法
 建议开发者使用IPDNativeAdObject中的callToAction字段来创建视图，并取代自定义的下载或打开等button,
 调用此方法之前必须先调用registerDataObject:clickableViews
 @param callToActionView CTA视图, 系统自动处理点击事件
 */
- (void)registerClickableCallToActionView:(UIView *)callToActionView;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 GDTUnifiedNativeAdView 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，
 将广告对象与 IPDNativeAdView 解绑
 */
- (void)unregisterDataObject;


@property (nonatomic,strong)UIView *logoView;
/**
  视频广告的媒体View，绑定数据对象后自动生成，可自定义布局
 */
@property (nonatomic,strong)UIView *videoAdView;


@property (nonatomic, strong) UIView *adContentView;

/**
 用来标记广告媒体View的 视频/图片 的大小，比如videoAdView的frame大小
 */
//@property (nonatomic, assign) CGRect videoOrImageFrame;


//广告曝光回调
- (void)ipdAdapter_nativeAdViewWillExpose;

//广告点击回调
- (void)ipdAdapter_nativeAdViewDidClick;

//广告详情页关闭回调
- (void)ipdAdapter_nativeAdDetailViewClosed;

//广告详情页面即将展示回调
- (void)ipdAdapter_nativeAdDetailViewWillPresentScreen;

//当点击应用下载或者广告调用系统程序打开时调用
- (void)ipdAdapter_NativeAdViewApplicationWillEnterBackground;

// 广告曝光错误
- (void)ipdAdapter_nativeAdViewShowError:(NSError *)error;


@property (nonatomic, strong) UIView *superRenderView;

/// 设置是否静音，默认为NO
@property (nonatomic, assign, readwrite) BOOL mutedIfCan;

/// 部分联盟设置了视频视图后需要重绘UI
- (void)resizeIfNeed;

@property (nonatomic, assign) BOOL hasShown;

@end

NS_ASSUME_NONNULL_END
