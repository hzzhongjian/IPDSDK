//
//  IPDInterstitialAdAdapterDelegate.h
//  IPDSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDInterstitialAdAdapter;

@protocol IPDInterstitialAdAdapterDelegate <NSObject>

- (void)ipd_interstitialAdAdapterDidLoad:(IPDInterstitialAdAdapter *)adapter;

- (void)ipd_interstitialAdAdapterDidLoadFail:(IPDInterstitialAdAdapter *)adapter error:(NSError * __nullable)error;

- (void)ipd_interstitialAdAdapterDidPresentScreen:(IPDInterstitialAdAdapter *)adapter;

- (void)ipd_interstitialAdAdapterDidClick:(IPDInterstitialAdAdapter *)adapter;

- (void)ipd_interstitialAdAdapterDidClose:(IPDInterstitialAdAdapter *)adapter;

- (void)ipd_interstitialAdAdapterDetailDidClose:(IPDInterstitialAdAdapter *)adapter;

- (void)ipd_interstitialAdAdapterDidFail:(IPDInterstitialAdAdapter *)adapter error:(NSError * __nullable)error;

@end

NS_ASSUME_NONNULL_END
