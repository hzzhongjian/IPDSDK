//
//  IPDFullScreenVideoViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/27.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDFullScreenVideoViewController.h"
#import <IPDSDK/IPDFullScreenVideoAd.h>


@interface IPDFullScreenVideoViewController ()<IPDFullScreenVideoAdDelegate>
@property (nonatomic,strong)IPDFullScreenVideoAd *fullVideoAd;
@end

@implementation IPDFullScreenVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[@"J3964813241", AdId_FullScreenVideo1,AdId_FullScreenVideo2,AdId_FullScreenVideo3,AdId_FullScreenVideo4,AdId_FullScreenVideo5,AdId_FullScreenVideo6]];
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.fullVideoAd = [[IPDFullScreenVideoAd alloc] initWithPlacementId:adId];
    self.fullVideoAd.delegate = self;
    [self.fullVideoAd loadAd];
}

-(void) showAd{
    if(self.fullVideoAd)
        [self.fullVideoAd presentFullScreenVideoAdFromRootViewController:self];
    
}

//广告加载成功
- (void)ipd_fullScreenVideoAdDidLoad:(IPDFullScreenVideoAd*)ad{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    NSArray *errors =  [self.fullVideoAd getFillFailureMessages];
    NSLog(@"所有错误信息 %@",errors);
    [self logMessage:@"fullScreenVideoAdDidLoad"];
    [self logMessage:[self.fullVideoAd valueForKey:@"logString"]];
}
//广告加载失败
- (void)ipd_fullScreenVideoAdDidLoadFail:(IPDFullScreenVideoAd*)ad error:(NSError * __nullable)error{
    [self logMessage:[self.fullVideoAd valueForKey:@"logString"]];
    NSArray *errors =  [self.fullVideoAd getFillFailureMessages];
    NSLog(@"所有错误信息 %@",errors);
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"fullScreenVideoAdDidLoadFail : %@",error]];
}

//广告展示
- (void)ipd_fullScreenVideoAdDidShow:(IPDFullScreenVideoAd *)ad{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"fullScreenVideoAdDidShow"];
}
//广告点击
- (void)ipd_fullScreenVideoAdDidClick:(IPDFullScreenVideoAd *)ad{
    
}
//广告关闭
- (void)ipd_fullScreenVideoAdDidClose:(IPDFullScreenVideoAd *)ad{
    [self logMessage:@"fullScreenVideoAdDidClose"];
    NSLog(@"--------%ld", ad.eCPM);
}
//广告详情页关闭
- (void)ipd_fullScreenVideoAdDetailDidClose:(IPDFullScreenVideoAd *)ad{
    
}
//广告错误
- (void)ipd_fullScreenVideoAdDidFail:(IPDFullScreenVideoAd*) ad error:(NSError * __nullable)error{
    [self logMessage:[NSString stringWithFormat:@"fullScreenVideoAdError : %@",error]];
}

//广告播放状态
-(void)ipd_fullScreenVideoAd:(IPDFullScreenVideoAd *)ad playerStatusChanged:(IPDMediaPlayerStatus)playerStatus{
    
}

//广告详情页打开
- (void)ipd_fullScreenVideoAdDetailDidPresent:(IPDFullScreenVideoAd*)ad{
    
}

@end
