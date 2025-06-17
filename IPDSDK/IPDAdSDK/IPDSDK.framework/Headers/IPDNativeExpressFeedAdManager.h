//
//  IPDNativeExpressFeedAdManager.h
//  IPDSDK
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import <IPDSDK/IPDAd.h>
#import <IPDSDKCore/IPDNativeExpressFeedAd.h>
#import <IPDSDK/IPDMultipleAd.h>

// 信息流广告
NS_ASSUME_NONNULL_BEGIN

@class IPDNativeExpressFeedAdManager ,IPDNativeExpressFeedAd;

@protocol IPDNativeExpressFeedAdManagerDelegate <NSObject>

@optional
///加载成功
- (void)IPD_nativeExpressFeedAdManagerSuccessToLoad:(IPDNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<IPDNativeExpressFeedAd *> *_Nullable)multipleResultObject;

///加载失败
- (void)IPD_nativeExpressFeedAdManager:(IPDNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end


@interface IPDNativeExpressFeedAdManager : IPDMultipleAd

@property (nonatomic, weak) id <IPDNativeExpressFeedAdManagerDelegate> delegate;


@property (nonatomic) CGSize adSize;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;


@property (nonatomic, strong ,readonly) NSArray <IPDNativeExpressFeedAd *> *data;

// 部分联盟需要设置size [必选]
- (instancetype)initWithPlacementId:(NSString *)placementId size:(CGSize)size;

/**
 * 加载广告，建议最大个数不超过5个
 */
- (void)loadAdDataWithCount:(NSInteger)count;

@end




NS_ASSUME_NONNULL_END
