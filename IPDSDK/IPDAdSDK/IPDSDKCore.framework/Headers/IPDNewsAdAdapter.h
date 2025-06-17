//
//  IPDNewsAdAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/12/20.
//

#import <IPDSDKCore/IPDCoreAdAdapter.h>
#import <IPDSDKCore/IPDTierAdAdapter.h>
#import <IPDSDKCore/IPDNewsAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDNewsAdAdapter;

@protocol IPDNewsAdAdapterDelegate <NSObject>
/**
 news广告加载成功
 */
- (void)ipdad_newsAdViewDidLoad:(IPDNewsAdAdapter *)newsAd;

/**
 news广告加载失败
 */
- (void)ipdad_newsAdView:(IPDNewsAdAdapter *)newsAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 newsAdView曝光回调
 */
- (void)ipdad_newsAdViewDidShow:(IPDNewsAdAdapter *)newsAd;

/**
 关闭news广告回调
 */
- (void)ipdad_newsAdViewRewardEffective:(IPDNewsAdAdapter *)newsAd;

/**
 点击news广告回调
 */
- (void)ipdad_newsAdViewDidClick:(IPDNewsAdAdapter *)newsAd;

/**
 canGoBack状态监听
 */
- (void)ipdad_newsAd:(IPDNewsAdAdapter *)newsAd canGoBackStateChange:(BOOL)canGoBack;

@end

@interface IPDNewsAdAdapter : IPDTierAdAdapter <IPDNewsAdProtocol>

@property(nonatomic,weak) id<IPDNewsAdAdapterDelegate> delegate;

@property (nonatomic,strong)UIView *adView;

@property (nonatomic, readonly) BOOL canGoBack;

@property (nonatomic, readonly) BOOL canGoForward;

@property (nonatomic, assign) BOOL enableGoBackGesture;

@property (nonatomic, assign) BOOL enableSlide;

- (instancetype)initWithAdItemConfig:(IPDAdUnitModel *)adItemConfig frame:(CGRect)frame;

- (BOOL)goBack;

- (BOOL)goForward;

- (void)removeTimer;

//- (void)reload;
//- (void)stopLoading;

/**
 news广告加载成功
 */
- (void)ipdad_newsAdViewDidLoad:(IPDNewsAdAdapter *)newsAd;

/**
 news广告加载失败
 */
- (void)ipdad_newsAdView:(IPDNewsAdAdapter *)newsAd didLoadFailWithError:(NSError *_Nullable)error;


/**
 newsAdView曝光回调
 */
- (void)ipdad_newsAdViewDidShow:(IPDNewsAdAdapter *)newsAd;

/**
 news广告发奖回调
 */
- (void)ipdad_newsAdViewRewardEffective:(IPDNewsAdAdapter *)newsAd;

/**
 点击news广告回调
 */
- (void)ipdad_newsAdViewDidClick:(IPDNewsAdAdapter *)newsAd;

/**
 canGoBack状态监听
 */
- (void)ipdad_newsAdCanGoBackStateChange:(BOOL)canGoBack;

@end

NS_ASSUME_NONNULL_END
