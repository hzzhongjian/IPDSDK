//
//  ZJNativeExpressFeedViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDFeedAdsViewController.h"

#import "IPDNativeExpressAdsViewController.h"
@interface IPDFeedAdsViewController ()



@end

@implementation IPDFeedAdsViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.loadAdView.showButton.hidden = YES;
//    J0128142431
    [self.loadAdView appendAdID:@[@"J2203305378", @"J7380206749",
        @"J9481236908",
        AdId_ExpressAd1,AdId_ExpressAd2,AdId_ExpressAd3,AdId_ExpressAd4,AdId_ExpressAd5,AdId_ExpressAd6,AdId_ExpressAd7,AdId_ExpressAd8,AdId_ExpressAd9]];
    
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    
    IPDNativeExpressAdsViewController *vc = [[IPDNativeExpressAdsViewController alloc]init];
    vc.adId = adId;
    [self.navigationController pushViewController:vc animated:YES];
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
