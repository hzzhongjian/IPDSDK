//
//  IPDNewsAd.h
//  IPDSDK
//
//  Created by 麻明康 on 2025/1/7.
//  Copyright © 2025 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>
#import <IPDSDKCore/IPDNewsAdAdapter.h>
#import <IPDSDKCore/IPDNewsAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDNewsAd;

@protocol IPDNewsAdDelegate <NSObject>

/**
 news广告加载成功
 */
- (void)ipd_newsAdDidLoad:(IPDNewsAd *)newsAd;

/**
 news广告加载失败
 */
- (void)ipd_newsAd:(IPDNewsAd *)newsAd didLoadFailWithError:(NSError * _Nullable)error;

/**
 newsAdView曝光回调
 */
- (void)ipd_newsAdDidShow:(IPDNewsAd *)newsAd;

/**
 关闭news广告回调
 */
- (void)ipd_newsAdRewardEffective:(IPDNewsAd *)newsAd;

/**
 点击news广告回调
 */
- (void)ipd_newsAdDidClick:(IPDNewsAd *)newsAd;

/**
 canGoBack状态监听
 */
- (void)ipd_newsAd:(IPDNewsAd *)newsAd newsAdCanGoBackStateChange:(BOOL)canGoBack;

@end

@interface IPDNewsAd : IPDTierAd <IPDNewsAdProtocol>

@property (nonatomic, copy, readonly) NSString *placementId;

@property (nonatomic, assign) BOOL enableGoBackGesture;

@property (nonatomic, assign) BOOL enableSlide;

@property (nonatomic, strong,nullable) IPDNewsAdAdapter *currentAdapter;

@property (nonatomic, weak, nullable) id <IPDNewsAdDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId frame:(CGRect)frame;

- (UIView *)newAdView;

- (BOOL)canGoBack;

- (void)goBack;

- (void)goForward;

- (BOOL)canGoForward;

@end

NS_ASSUME_NONNULL_END
