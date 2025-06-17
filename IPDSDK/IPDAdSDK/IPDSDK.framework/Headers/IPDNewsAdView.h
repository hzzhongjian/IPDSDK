//
//  IPDNewsAdView.h
//  IPDSDK
//
//  Created by 麻明康 on 2022/12/20.
//  Copyright © 2022 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IPDSDKCore/IPDNewsAdProtocol.h>
NS_ASSUME_NONNULL_BEGIN
@class IPDNewsAdView;
@protocol IPDNewsAdViewDelegate <NSObject>
@optional
/**
 news广告加载成功
 */
- (void)ipd_newsAdViewDidLoad:(IPDNewsAdView *)newsAdView;

/**
 news广告加载失败
 */
- (void)ipd_newsAdView:(IPDNewsAdView *)newsAdView didLoadFailWithError:(NSError * _Nullable)error;

/**
 newsAdView曝光回调
 */
- (void)ipd_newsAdViewDidShow:(IPDNewsAdView *)newsAdView;

/**
 关闭news广告回调
 */
- (void)ipd_newsAdViewRewardEffective:(IPDNewsAdView *)newsAdView;

/**
 点击news广告回调
 */
- (void)ipd_newsAdViewDidClick:(IPDNewsAdView *)newsAdView;

/**
 canGoBack状态监听
 */
- (void)ipd_newsAd:(IPDNewsAdView *)newsAd canGoBackStateChange:(BOOL)canGoBack;
@end
@interface IPDNewsAdView : UIView <IPDNewsAdProtocol>
@property (nonatomic, copy, readonly) NSString *placementId;
@property (nonatomic, assign) BOOL enableGoBackGesture;
@property (nonatomic, assign) BOOL enableSlide;

@property (nonatomic, weak, nullable) id <IPDNewsAdViewDelegate> delegate;

- (instancetype)initWithPlacementId:(NSString *)placementId frame:(CGRect)frame;

- (void)loadAdAndShow;
- (BOOL)canGoBack;
- (void)goBack;
@end

NS_ASSUME_NONNULL_END
