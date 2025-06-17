//
//  WindMillIntersititialAd.h
//  WindSDK
//
//  Created by Codi on 2021/4/19.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class WindMillAdInfo;
@class WindMillAdRequest;
@class WindMillIntersititialAd;

@protocol WindMillIntersititialAdDelegate<NSObject>

@optional
/**
 This method is called when video ad material loaded successfully.
 */
- (void)intersititialAdDidLoad:(WindMillIntersititialAd *)intersititialAd;

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)intersititialAdDidLoad:(WindMillIntersititialAd *)intersititialAd didFailWithError:(NSError *)error;
/**
 This method is called when video ad slot has been shown.
 */
- (void)intersititialAdDidVisible:(WindMillIntersititialAd *)intersititialAd;

/**
 This method is called when ad failed to show.
 */
- (void)intersititialAdDidShowFailed:(WindMillIntersititialAd *)intersititialAd error:(NSError *)error;

/**
 This method is called when video ad is clicked.
 */
- (void)intersititialAdDidClick:(WindMillIntersititialAd *)intersititialAd;

/**
 This method is called when video ad is clicked skip button.
 */
- (void)intersititialAdDidClickSkip:(WindMillIntersititialAd *)intersititialAd;

/**
 This method is called when video ad is about to close.
 */
- (void)intersititialAdDidClose:(WindMillIntersititialAd *)intersititialAd;

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)intersititialAdDidPlayFinish:(WindMillIntersititialAd *)intersititialAd didFailWithError:(NSError *)error;


@end

@interface WindMillIntersititialAd : NSObject

@property (nonatomic, weak) id<WindMillIntersititialAdDelegate> delegate;

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
