//
//  ZJNativeAdSelectedViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDNativeAdSelectedViewController.h"
#import "IPDNativeAdViewController.h"


@interface IPDNativeAdSelectedViewController ()

@end

@implementation IPDNativeAdSelectedViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[@"J2958823444", @"J2640784155", @"J8949215626", AdId_NativeRender1,AdId_NativeRender2,AdId_NativeRender3,AdId_NativeRender4,AdId_NativeRender5,AdId_NativeRender6,AdId_NativeRender7,AdId_NativeRender8,AdId_NativeRender9]];
    
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    IPDNativeAdViewController *nativeAdVC = [[IPDNativeAdViewController alloc]init];
    nativeAdVC.adId = adId;
    [self.navigationController pushViewController:nativeAdVC animated:YES];
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
