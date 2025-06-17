//
//  IPDInterstitialAd.h
//  IPDSDK
//
//  Created by Rare on 2022/3/1.
//  Copyright © 2022 zj. All rights reserved.
//

#import <IPDSDK/IPDTierAd.h>
#import <IPDSDKCore/IPDInterstitialAdProtocol.h>
#import <IPDSDKCore/IPDInterstitialAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDInterstitialAd;

@protocol IPDInterstitialAdDelegate <NSObject>

@optional
///插屏广告加载成功
- (void)ipd_interstitialAdDidLoad:(IPDInterstitialAd *)ad;

///插屏广告加载失败
- (void)ipd_interstitialAdDidLoadFail:(IPDInterstitialAd*)ad error:(nullable NSError *)error;

///插屏广告展示成功回调
- (void)ipd_interstitialAdDidPresentScreen:(IPDInterstitialAd*)ad;

///插屏广告点击回调
- (void)ipd_interstitialAdDidClick:(IPDInterstitialAd*)ad;

///插屏广告关闭回调
- (void)ipd_interstitialAdDidClose:(IPDInterstitialAd*)ad;

///插屏广告详情页关闭回调
- (void)ipd_interstitialAdDetailDidClose:(IPDInterstitialAd*)ad;

///插屏广告其他错误回调
- (void)ipd_interstitialAdDidFail:(IPDInterstitialAd *)ad error:(nullable NSError *)error;

@end

@interface IPDInterstitialAd : IPDTierAd<IPDInterstitialAdProtocol>

@property(nonatomic,weak) id<IPDInterstitialAdDelegate>delegate;

@property (nonatomic,strong,nullable)IPDInterstitialAdAdapter *currentAdapter;

@end

NS_ASSUME_NONNULL_END
