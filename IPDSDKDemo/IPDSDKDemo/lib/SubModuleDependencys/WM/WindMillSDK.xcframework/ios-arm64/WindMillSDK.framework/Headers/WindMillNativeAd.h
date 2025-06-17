//
//  WindMillNativeAd.h
//  WindSDK
//
//  Created by Codi on 2021/7/14.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, WindMillFeedADMode) {
    WindMillFeedADModeSmallImage = 2,
    WindMillFeedADModeLargeImage = 3,
    WindMillFeedADModeGroupImage = 4,
    WindMillFeedADModeNativeExpress = 5,
    WindMillFeedADModeVideo = 14,
    WindMillFeedADModeVideoPortrait = 15,
    WindMillFeedADModeVideoLandSpace = 16,
};

typedef NS_ENUM(NSInteger, WindMillNativeAdSlotAdType) {
    WindMillNativeAdSlotAdTypeFeed          = 1,       // feed ads
    WindMillNativeAdSlotAdTypeDrawVideo     = 2,       // vertical (immersive) video ads
};


@interface WindMillNativeAd : NSObject

/// Typed access to the ad title.
@property (nonatomic, copy, readonly) NSString *title;

/// Typed access to the body text, usually a longer description of the ad.
@property (nonatomic, copy, readonly) NSString *desc;

/// Typed access to the ad icon.
@property (nonatomic, copy, readonly) NSString *iconUrl;

/// Typed access to the call to action phrase of the ad.
@property (nonatomic, copy, readonly) NSString *callToAction;

/// Typed access to the ad star rating.
@property (nonatomic, assign, readonly) double rating;

/// WindMillFeedADModeNativeExpress为模版渲染，此时其它属性都为nil
@property (nonatomic, assign, readonly) WindMillFeedADMode feedADMode;

/// 广告类型（Feed/Draw）
@property (nonatomic, assign, readonly) WindMillNativeAdSlotAdType adType;

/// 是否为视频广告
@property (nonatomic, assign, readonly) BOOL isVideoAd;

@end
