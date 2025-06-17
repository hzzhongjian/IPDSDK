//
//  WindMillNativeAdsManager.h
//  WindSDK
//
//  Created by Codi on 2021/7/14.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class WindMillAdRequest;
@class WindMillNativeAd;
@class WindMillNativeAdsManager;

@protocol WindMillNativeAdsManagerDelegate <NSObject>

@optional

- (void)nativeAdsManagerSuccessToLoad:(WindMillNativeAdsManager *)adsManager;

- (void)nativeAdsManager:(WindMillNativeAdsManager *)adsManager didFailWithError:(NSError *)error;

@end


@interface WindMillNativeAdsManager : NSObject

@property (nonatomic, weak) id<WindMillNativeAdsManagerDelegate> delegate;

@property (nonatomic, strong, readonly) NSString *placementId;

/// 自定义扩展参数
@property (nonatomic, strong) NSDictionary *extra;

/*
 * 必传参数，为空时聚合会默认设置为width=screen.bouces.size.width; height=0
 * 穿山甲 height: 0自适应
 * 腾讯：height会在render success后自动更新到合适的高度
 */
@property (nonatomic, assign, readwrite) CGSize adSize;

- (instancetype)initWithRequest:(WindMillAdRequest *)request;

/**
 It is recommended to request no more than 3 ads.
 */
- (void)loadAdDataWithCount:(NSInteger)count;

/**
 Get all ads when call methord: nativeAdsManagerSuccessToLoad
 */
- (NSArray<WindMillNativeAd *> *)getAllNativeAds;

@end

