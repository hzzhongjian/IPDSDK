//
//  AdViewController.h
//  ZJSDKDemo
//
//  Created by Robin on 2020/10/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IPDAdLoadView.h"
NS_ASSUME_NONNULL_BEGIN

@interface AdViewController : UIViewController

@property(nonatomic,strong,readonly) IPDAdLoadView *loadAdView;

-(void)log:(NSString *)fun message:(nullable NSString *)msg;

-(void)logMessage:(NSString *)message;

-(void)loadAd:(NSString*)adId;
-(void)showAd;
@end

NS_ASSUME_NONNULL_END
