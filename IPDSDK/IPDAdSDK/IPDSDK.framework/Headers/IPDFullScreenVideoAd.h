//
//  IPDFullScreenVideoAd.h
//  IPDSDK
//
//  Created by Rare on 2022/3/3.
//  Copyright © 2022 zj. All rights reserved.
//

#import <IPDSDK/IPDTierAd.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>
#import <IPDSDKCore/IPDFullScreenVideoAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDFullScreenVideoAd;

@protocol IPDFullScreenVideoAdDelegate <NSObject>

//广告加载成功
- (void)ipd_fullScreenVideoAdDidLoad:(IPDFullScreenVideoAd *)ad;

//广告加载失败
- (void)ipd_fullScreenVideoAdDidLoadFail:(IPDFullScreenVideoAd *)ad error:(nullable NSError *)error;

//广告展示
- (void)ipd_fullScreenVideoAdDidShow:(IPDFullScreenVideoAd *)ad;

//广告点击
- (void)ipd_fullScreenVideoAdDidClick:(IPDFullScreenVideoAd *)ad;

//广告关闭
- (void)ipd_fullScreenVideoAdDidClose:(IPDFullScreenVideoAd *)ad;

//广告错误
- (void)ipd_fullScreenVideoAdDidFail:(IPDFullScreenVideoAd *)ad error:(nullable NSError *)error;

//广告播放状态回调
- (void)ipd_fullScreenVideoAd:(IPDFullScreenVideoAd *)ad  playerStatusChanged:(IPDMediaPlayerStatus)playerStatus;

//广告详情页打开
- (void)ipd_fullScreenVideoAdDetailDidPresent:(IPDFullScreenVideoAd *)ad;

//广告详情页关闭
- (void)ipd_fullScreenVideoAdDetailDidClose:(IPDFullScreenVideoAd *)ad;

@end

@interface IPDFullScreenVideoAd : IPDTierAd

@property (nonatomic, weak) id <IPDFullScreenVideoAdDelegate> delegate;

@property (nonatomic,strong,nullable)IPDFullScreenVideoAdAdapter *currentAdapter;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

- (void)presentFullScreenVideoAdFromRootViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
