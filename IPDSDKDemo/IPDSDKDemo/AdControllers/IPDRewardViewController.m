//
//  IPDRewardViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import "IPDRewardViewController.h"
#import <IPDSDK/IPDSDK.h>
#import "IPDSplashWindowVC.h"

@interface IPDRewardViewController ()<IPDRewardVideoAdDelegate>
{
   
}
@property(nonatomic,strong) IPDRewardVideoAd *rewardVideoAd;

@end

@implementation IPDRewardViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
   [self.loadAdView appendAdID:@[@"J0207472286", @"J5988878101", @"J4731110388",@"J1491608550", @"J8795659244", @"J3964813241", @"J3417058766", @"J8569782183",AdId_Reward1,AdId_Reward2,AdId_Reward3,AdId_Reward4,AdId_Reward5,AdId_Reward6,AdId_Reward7,AdId_Reward8,AdId_Reward9,AdId_Reward10, AdId_Reward11, @"J8348093531"]];
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
}

-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    self.rewardVideoAd = [[IPDRewardVideoAd alloc] initWithPlacementId:adId userId:@"18888888888"];
    self.rewardVideoAd.reward_name = @"奖励欢乐豆";
    self.rewardVideoAd.reward_amount = 10;
    self.rewardVideoAd.extra = @"123";
    self.rewardVideoAd.delegate = self;
    [self.rewardVideoAd loadAd];
}

-(void) showAd{
    if(self.rewardVideoAd)
       [self.rewardVideoAd showAdInViewController:self];
}


-(void) reloadAd{
    [self.rewardVideoAd loadAd];
}

#pragma mark - IPDRewardVideoAdDelegate
/**
广告数据加载成功回调
 ⚠️请勿在该回调内调用 showAdInViewController:方法（需视频下载完成）
@param rewardedVideoAd IPDRewardVideoAd 实例
*/
- (void)ipd_rewardVideoAdDidLoad:(IPDRewardVideoAd *)rewardedVideoAd{
    [self logMessage:@"rewardVideoAdDidLoad"];
}


/**
 视频数据下载成功回调，已经下载过的视频会直接回调，在这里调用展示广告的方法。
 ✅ showAdInViewController: 方法请在该回调中执行 ， 广告展示需要在视频下载完成后才能展示，
@param rewardedVideoAd IPDRewardVideoAd 实例
*/
- (void)ipd_rewardVideoAdVideoDidLoad:(IPDRewardVideoAd *)rewardedVideoAd{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    [self logMessage:@"rewardVideoAdVideoDidLoad"];
    [self logMessage:[self.rewardVideoAd valueForKey:@"logString"]];
}


/**
 视频广告展示

 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidShow:(IPDRewardVideoAd *)rewardedVideoAd{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"rewardVideoAdDidShow"];
}

//奖励触发
- (void)ipd_rewardVideoAdDidRewardEffective:(IPDRewardVideoAd *)rewardedVideoAd{
    [self logMessage:@"RewardEffective"];
    NSLog(@"===== %@",rewardedVideoAd.trade_id);
    NSLog(@"======%s",__FUNCTION__);
}

- (void)ipd_rewardVideoAd:(IPDRewardVideoAd *)rewardedVideoAd serviceCheckResult:(BOOL)success error:(NSError *)error{
    if (success) {
        NSLog(@"服务器校验成功");
    }else{
        NSLog(@"%@",error);
    }
}
/**
 视频播放页关闭

 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidClose:(IPDRewardVideoAd *)rewardedVideoAd{
    [self logMessage:@"rewardVideoAdDidClose"];
    NSLog(@"媒体获取的价格------%ld", (long)rewardedVideoAd.eCPM);
}

/**
 视频广告信息点击

 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidClicked:(IPDRewardVideoAd *)rewardedVideoAd{
    [self logMessage:@"rewardVideoAdDidClicked"];
}


/**
 视频广告视频播放完成

 @param rewardedVideoAd IPDRewardVideoAd 实例
 */
- (void)ipd_rewardVideoAdDidPlayFinish:(IPDRewardVideoAd *)rewardedVideoAd{
    [self logMessage:@"rewardVideoAdDidPlayFinish"];
}


/**
 视频广告各种错误信息回调

 @param rewardedVideoAd IPDRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)ipd_rewardVideoAd:(IPDRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error{
    [self logMessage:[self.rewardVideoAd valueForKey:@"logString"]];
    NSArray *errors =  [self.rewardVideoAd getFillFailureMessages];
    NSLog(@"激励视频所有错误信息 %@",errors);
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"rewardedVideoAdError : %@",error]];
}

- (void)ipd_rewardVideoAd:(IPDRewardVideoAd *)rewardedVideoAd displayFailWithError:(NSError *)error{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    switch (error.code) {
        case 4014:
            NSLog(@"请拉取到广告后再调用展示接口");
            break;
        case 4016:
            NSLog(@"应用方向与广告位支持方向不一致");
            break;
        case 5012:
            NSLog(@"广告已过期");
            break;
        case 4015:
            NSLog(@"广告已经播放过，请重新拉取");
            break;
        case 5003:
            NSLog(@"视频播放失败");
            break;
        case 5027:
            NSLog(@"页面加载失败");
            break;
        default:
            NSLog(@"激励视频播放错误: %@",error);
            break;
    }
}

- (void)ipd_rewardVideoAdDidClickSkip:(IPDRewardVideoAd *)rewardedVideoAd
{
    [self logMessage:@"rewardVideoAdDidClickSkip"];
}

@end
