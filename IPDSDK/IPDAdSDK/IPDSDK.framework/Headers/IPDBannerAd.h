//
//  IPDBannerAd.h
//  IPDSDK
//
//  Created by 麻明康 on 2025/1/3.
//  Copyright © 2025 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>
#import <IPDSDKCore/IPDBannerAdAdapter.h>
#import <IPDSDKCore/IPDBannerAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDBannerAd;

@protocol IPDBannerAdDelegate <NSObject>

/**
 banner广告加载成功
 */
- (void)ipd_bannerAdDidLoad:(IPDBannerAd *)bannerAd;

/**
 banner广告加载失败
 */
- (void)ipd_bannerAd:(IPDBannerAd *)bannerAd didLoadFailWithError:(NSError * _Nullable)error;

/**
 bannerAdView曝光回调
 */
- (void)ipd_bannerAdWillBecomVisible:(IPDBannerAd *)bannerAd;

/**
 关闭banner广告回调
 */
- (void)ipd_bannerAdDislike:(IPDBannerAd *)bannerAd;

/**
 点击banner广告回调
 */
- (void)ipd_bannerAdDidClick:(IPDBannerAd *)bannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)ipd_bannerAdDidCloseOtherController:(IPDBannerAd *)bannerAd;

@end

@interface IPDBannerAd : IPDTierAd

/// interval  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
@property (nonatomic, assign) CGFloat interval;

@property (nonatomic, strong) UIViewController *rootViewController;

@property (nonatomic, weak) id <IPDBannerAdDelegate> delegate;

@property (nonatomic, strong,nullable) IPDBannerAdAdapter *currentAdapter;

@property (nonatomic, assign) CGSize adSize;

- (instancetype)initWithPlacementId:(NSString *)placementId
                 rootViewController:(UIViewController *)rootViewController
                             adSize:(CGSize)adSize;

// 需要展示的bannerView
- (UIView *)bannerView;

- (void)showAd;

@end

NS_ASSUME_NONNULL_END
