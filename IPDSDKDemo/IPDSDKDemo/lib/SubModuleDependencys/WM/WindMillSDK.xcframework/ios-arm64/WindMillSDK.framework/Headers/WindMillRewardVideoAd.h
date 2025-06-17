//
//  WindMillRewardVideoAd.h
//  WindSDK
//
//  Created by Codi on 2021/4/19.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class WindMillAdInfo;
@class WindMillAdRequest;
@class WindMillRewardInfo;
@class WindMillRewardVideoAd;

@protocol WindMillRewardVideoAdDelegate<NSObject>

@required
/**
 This method is called when video ad is ca
 n be motivated
 */
- (void)rewardVideoAd:(WindMillRewardVideoAd *)rewardVideoAd reward:(WindMillRewardInfo *)reward;

@optional
/**
 This method is called when video ad material loaded successfully.
 */
- (void)rewardVideoAdDidLoad:(WindMillRewardVideoAd *)rewardVideoAd;

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)rewardVideoAdDidLoad:(WindMillRewardVideoAd *)rewardVideoAd didFailWithError:(NSError *)error;

/**
 This method is called when video ad slot has been shown.
 */
- (void)rewardVideoAdDidVisible:(WindMillRewardVideoAd *)rewardVideoAd;

/**
 This method is called when ad failed to show.
 */
- (void)rewardVideoAdDidShowFailed:(WindMillRewardVideoAd *)rewardVideoAd error:(NSError *)error;

/**
 This method is called when video ad is clicked.
 */
- (void)rewardVideoAdDidClick:(WindMillRewardVideoAd *)rewardVideoAd;

/**
 This method is called when video ad is clicked skip button.
 */
- (void)rewardVideoAdDidClickSkip:(WindMillRewardVideoAd *)rewardVideoAd;

/**
 This method is called when video ad is about to close.
 */
- (void)rewardVideoAdDidClose:(WindMillRewardVideoAd *)rewardVideoAd;

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)rewardVideoAdDidPlayFinish:(WindMillRewardVideoAd *)rewardVideoAd didFailWithError:(NSError *)error;


@end

@interface WindMillRewardVideoAd : NSObject

@property (nonatomic, weak) id<WindMillRewardVideoAdDelegate> delegate;

@property (nonatomic, strong, readonly) NSString *placementId;

@property (nonatomic, getter=isAdReady, readonly) BOOL ready;

@property (nonatomic, strong, readonly) WindMillAdInfo *adInfo;


- (instancetype)initWithRequest:(WindMillAdRequest *)request;

- (void)loadAdData;

/**
 Display video ad.
 @param rootViewController : root view controller for displaying ad.
 @param extras : Extended parameters for displaying ad.
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController
                             options:(NSDictionary<NSString *, NSString *> *)extras;

@end
