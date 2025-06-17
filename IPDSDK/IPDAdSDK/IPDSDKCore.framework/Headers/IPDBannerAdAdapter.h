//
//  IPDBannerAdAdapter.h
//  IPDSDKCore
//
//  Created by Robin on 2021/1/23.
//

#import <IPDSDKCore/IPDTierAdAdapter.h>
#import <IPDSDKCore/IPDCoreAdAdapter.h>
#import <IPDSDKCore/IPDBannerAdProtocol.h>


NS_ASSUME_NONNULL_BEGIN

@class IPDBannerAdAdapter;

@protocol IPDBannerAdAdapterDelegate <NSObject>
/**
 banner广告加载成功
 */
- (void)ipdad_bannerAdViewDidLoad:(IPDBannerAdAdapter *)bannerAd;

/**
 banner广告加载失败
 */
- (void)ipdad_bannerAdView:(IPDBannerAdAdapter *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 bannerAdView曝光回调
 */
- (void)ipdad_bannerAdViewWillBecomVisible:(IPDBannerAdAdapter *)bannerAd;

/**
 关闭banner广告回调
 */
- (void)ipdad_bannerAdViewDislike:(IPDBannerAdAdapter *)bannerAd;

/**
 点击banner广告回调
 */
- (void)ipdad_bannerAdViewDidClick:(IPDBannerAdAdapter *)bannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)ipdad_bannerAdViewDidCloseOtherController:(IPDBannerAdAdapter *)bannerAd;

@end
// IPDBannerAdAdapter是继承IPDCoreAdAdapter，
@interface IPDBannerAdAdapter : IPDTierAdAdapter <IPDBannerAdProtocol>

@property(nonatomic,weak) id<IPDBannerAdAdapterDelegate> delegate;

@property (nonatomic,weak)UIView *adView;


- (instancetype)initWithAdItemConfig:(IPDAdUnitModel *)adItemConfig
                      viewController:(UIViewController *)viewController
                              adSize:(CGSize)adSize;

- (instancetype)initWithAdItemConfig:(IPDAdUnitModel *)adItemConfig
                      viewController:(UIViewController *)viewController
                              adSize:(CGSize)adSize
                            interval:(NSInteger)interval;

/**
 banner广告加载成功
 */
- (void)ipdad_bannerAdViewDidLoad:(IPDBannerAdAdapter *)bannerAd;

/**
 banner广告加载失败
 */
- (void)ipdad_bannerAdView:(IPDBannerAdAdapter *)bannerAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 bannerAdView曝光回调
 */
- (void)ipdad_bannerAdViewWillBecomVisible:(IPDBannerAdAdapter *)bannerAd;

/**
 关闭banner广告回调
 */
- (void)ipdad_bannerAdViewDislike:(IPDBannerAdAdapter *)bannerAd;

/**
 点击banner广告回调
 */
- (void)ipdad_bannerAdViewDidClick:(IPDBannerAdAdapter *)bannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)ipdad_bannerAdViewDidCloseOtherController:(IPDBannerAdAdapter *)bannerAd;


@end

NS_ASSUME_NONNULL_END
