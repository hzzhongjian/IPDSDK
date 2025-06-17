//
//  IPDInterstitialAdViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/10/16.
//  Copyright © 2020 zj. All rights reserved.
//

#import "IPDInterstitialAdViewController.h"
#import <IPDSDK/IPDInterstitialAd.h>

@interface IPDInterstitialAdViewController ()<IPDInterstitialAdDelegate>
{

}
@property(nonatomic,strong) IPDInterstitialAd *interstitialAd;
@end

@implementation IPDInterstitialAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[@"zjad_G10506",@"J7311893871",@"J4647160897",@"J3815584775",@"J8105377013",@"zjad_iOS_ZI0001", @"J6165278193", AdId_Interstitial1,AdId_Interstitial2,AdId_Interstitial3,AdId_Interstitial4,AdId_Interstitial5,AdId_Interstitial7,AdId_Interstitial8]];
    
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    
}

- (void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.interstitialAd = [[IPDInterstitialAd alloc] initWithPlacementId:adId];
    self.interstitialAd.delegate = self;
    self.interstitialAd.mutedIfCan = YES;
    self.interstitialAd.adSize = CGSizeMake(389, 523);
    [self.interstitialAd loadAd];
}

- (void)showAd{
    if(self.interstitialAd && self.interstitialAd.currentAdapter.pmAdValid)
        [self.interstitialAd presentAdFromRootViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
    
}

#pragma mark IPDInterstitialAdDelegate

- (void)ipd_interstitialAdDidLoad:(IPDInterstitialAd*)ad{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    [self logMessage:@"interstitialAdDidLoad"];
    [self logMessage:[ad valueForKey:@"logString"]];
}

- (void)ipd_interstitialAdDidLoadFail:(IPDInterstitialAd*) ad error:(NSError * __nullable)error{
    [self logMessage:[self.interstitialAd valueForKey:@"logString"]];
    NSArray *errors =  [self.interstitialAd getFillFailureMessages];
    NSLog(@"所有错误信息 %@",errors);
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"interstitialAdDidLoadFail : %@",error]];
}

- (void)ipd_interstitialAdDidPresentScreen:(IPDInterstitialAd*)ad{
    self.interstitialAd.mutedIfCan = NO;
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"interstitialAdDidPresentScreen"];
    
}

- (void)ipd_interstitialAdDidClick:(IPDInterstitialAd*)ad{
    [self logMessage:@"interstitialAdDidClick"];
}

- (void)ipd_interstitialAdDidClose:(IPDInterstitialAd*)ad{
    [self logMessage:@"interstitialAdDidClose"];
}

- (void)ipd_interstitialAdDetailDidClose:(IPDInterstitialAd*)ad{
    [self logMessage:@"interstitialAdDetailDidClose"];
}

- (void)ipd_interstitialAdDidFail:(IPDInterstitialAd*)ad error:(NSError * __nullable)error{
    [self logMessage:[NSString stringWithFormat:@"interstitialAdError : %@",error]];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
