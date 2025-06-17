//
//  IPDSplashViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/16.
//  Copyright © 2020 zj. All rights reserved.
//

#import "IPDSplashViewController.h"
#import "IPDAdLoadView.h"
#import <IPDSDK/IPDSplashAd.h>
#import "AppDelegate.h"
#import <IPDSDK/IPDAdSDK.h>

@interface IPDSplashViewController ()<IPDSplashAdDelegate>
@property(nonatomic,strong) IPDSplashAd *splashAd;
@property(nonatomic,strong) UIView *bottomView;
@end

@implementation IPDSplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self.loadAdView appendAdID:@[@"J0488260074", @"J2784576157", @"J1087635396", AdId_Splash1,@"J8335585790", @"J2412348906",@"J4861053586", @"J3212412217", AdId_Splash2,AdId_Splash3,AdId_Splash4,AdId_Splash5,AdId_Splash6,AdId_Splash7,AdId_Splash8,AdId_Splash9,AdId_Splash10,AdId_Splash11,AdId_Splash12, AdId_Splash13, @"J3212412217", @"J4220911194"]];
}


- (void)loadAd:(NSString *)adId
{
    [super loadAd:adId];
    self.splashAd = [[IPDSplashAd alloc] initWithPlacementId:adId];
    self.splashAd.delegate = self;
    self.splashAd.fetchDelay = 5.0;
    self.splashAd.rootViewController = self;
    self.splashAd.customBottomView = self.bottomView;
    [self.splashAd loadAd];
}

- (void)showAd {
    NSLog(@"------%d", self.splashAd.currentAdapter.pmAdValid);
    if(self.splashAd){
        [self.splashAd showAdInWindow:[UIApplication sharedApplication].keyWindow];
        
//        [self.splashAd showAdInWindow:[UIApplication sharedApplication].keyWindow withBottomView:self.bottomView];
    }
}


-(UIView *)bottomView{
    if (!_bottomView) {
        _bottomView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, kScreenWidth, 100)];
        _bottomView.backgroundColor = [UIColor whiteColor];
        
        UILabel *titleLabel = [[UILabel alloc]init];
        titleLabel.textColor = [UIColor redColor];
        titleLabel.font = [UIFont boldSystemFontOfSize:24];
        titleLabel.text = @"LOGO";
        [_bottomView addSubview:titleLabel];
        [titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.center.mas_equalTo(0);
        }];
    }
    return _bottomView;
}

#pragma mark - IPDSplashAdDelegate


/**
 *  开屏广告素材加载成功
 */
-(void)ipd_splashAdDidLoad:(IPDSplashAd *)splashAd{
    NSLog(@"6666返回给用户的价格====%ld", (long)[splashAd eCPM]);
    self.loadAdView.showButton.backgroundColor = kMainColor;
    [self logMessage:@"splashAdDidLoad"];
    [self logMessage:[splashAd valueForKey:@"logString"]];
    
    IPDAdExposureReportParam *param = [IPDAdExposureReportParam new];
    [splashAd reportAdExposureFailed:IPDAdExposureFailureBidFailed reportParam:param];
}

/**
 *  开屏广告成功展示
 */
-(void)ipd_splashAdSuccessPresentScreen:(IPDSplashAd *)splashAd{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"splashAdShow"];
    NSLog(@"展示广告来源：%ld", (long)splashAd.adInfo.platformType);
    
    [splashAd setBidEcpm:3000 highestLossEcpm:2000];
}


/**
 *  开屏广告点击回调
 */
- (void)ipd_splashAdClicked:(IPDSplashAd *)splashAd{
    [self logMessage:@"ipd_splashAdClicked"];
}

/**
 *  开屏广告关闭回调
 */
- (void)ipd_splashAdClosed:(IPDSplashAd *)splashAd{
    [self logMessage:@"splashAdClosed"];
    NSLog(@"返回给用户的价格====%ld", (long)[splashAd eCPM]);
}


/**
 *  开屏广告即将关闭回调
 */
- (void)ipd_splashAdWillClose:(IPDSplashAd *)splashAd{
    [self logMessage:@"ipd_splashAdWillClose"];
}


/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)ipd_splashAdApplicationWillEnterBackground:(IPDSplashAd *)splashAd{
    
}

/**
 * 开屏广告倒记时结束
 */
- (void)ipd_splashAdCountdownEnd:(IPDSplashAd*)splashAd{
    
}

/**
 *  开屏广告错误
 */
- (void)ipd_splashAdError:(IPDSplashAd *)splashAd withError:(NSError *)error{
    [self logMessage:[splashAd valueForKey:@"logString"]];
    NSArray *errors =  [self.splashAd getFillFailureMessages];
    NSLog(@"开屏广告所有错误信息 ====== %@",errors);
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"splashAdError : %@",error]];
}

/**
 *  开屏广告播放错误
 */
- (void)ipd_splashAdDisplayError:(IPDSplashAd *)splashAd withError:(NSError *)error{
    self.loadAdView.showButton.backgroundColor = [UIColor lightGrayColor];
    [self logMessage:@"ipd_splashAdDisplayError"];
}

- (void)ipd_splashAdDidRewardEffective:(IPDSplashAd *)splashAd withInfo:(NSDictionary *)info{
    [self logMessage:[NSString stringWithFormat:@"奖励触发，奖励信息信息 %@",info]];

}


-(void)dealloc{
    
}

@end
