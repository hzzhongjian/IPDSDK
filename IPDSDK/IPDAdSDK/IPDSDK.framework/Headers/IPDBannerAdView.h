//
//  IPDBannerAdView.h
//  IPDSDK
//
//  Created by Rare on 2021/1/23.
//  Copyright © 2021 zj. All rights reserved.
//

#import <IPDSDK/IPDAd.h>
#import <IPDSDKCore/IPDBannerAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDBannerAdView;

@protocol IPDBannerAdViewDelegate <NSObject>

@optional
/**
 banner广告加载成功
 */
- (void)ipd_bannerAdViewDidLoad:(IPDBannerAdView *)bannerAdView;

/**
 banner广告加载失败
 */
- (void)ipd_bannerAdView:(IPDBannerAdView *)bannerAdView didLoadFailWithError:(NSError * _Nullable)error;

/**
 bannerAdView曝光回调
 */
- (void)ipd_bannerAdViewWillBecomVisible:(IPDBannerAdView *)bannerAdView;

/**
 关闭banner广告回调
 */
- (void)ipd_bannerAdViewDislike:(IPDBannerAdView *)bannerAdView;

/**
 点击banner广告回调
 */
- (void)ipd_bannerAdViewDidClick:(IPDBannerAdView *)bannerAdView;

/**
 关闭banner广告详情页回调
 */
- (void)ipd_bannerAdViewDidCloseOtherController:(IPDBannerAdView *)bannerAdView;

@end


@interface IPDBannerAdView : UIView<IPDBannerAdProtocol>

@property (nonatomic, copy, readonly) NSString *placementId;

@property (nonatomic, weak, nullable) id <IPDBannerAdViewDelegate> delegate;

/**
   @params
   placementId - 广告位id
   viewController - 视图控制器
   adSize 展示的位置和大小
   interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController
                             adSize:(CGSize)adSize
                           interval:(NSInteger)interval;

/**
   @params
   placementId - 广告位id
   viewController - 视图控制器
   adSize 展示的位置和大小
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController
                             adSize:(CGSize)adSize;


- (NSArray *)getFillFailureMessages;

@end

NS_ASSUME_NONNULL_END
