//
//  IPDBannerViewController.m
//  IPDSDKDemo
//
//  Created by Robin on 2021/1/31.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDBannerViewController.h"
#import <IPDSDK/IPDBannerAdView.h>
#import <IPDSDK/IPDBannerAd.h>

#define IPDBannerHeight 50
@interface IPDBannerViewController ()<IPDBannerAdViewDelegate, IPDBannerAdDelegate>


@property(nonatomic,strong) IPDBannerAdView *bannerView;

@property (nonatomic, strong) IPDBannerAd *bannerAd;

@end

@implementation IPDBannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[@"J8348219443", @"J5549308336", @"J0029791795", @"J3564017834", AdId_Banner1,AdId_Banner2,AdId_Banner3,AdId_Banner4,AdId_Banner5,AdId_Banner6,AdId_Banner7,AdId_Banner8,AdId_Banner9]];
    self.loadAdView.showButton.hidden = NO;
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
//    if (_bannerView) {
//        [_bannerView removeFromSuperview];
//        _bannerView = nil;
//    }
//    CGFloat width = self.view.frame.size.width;
//    self.bannerView = [[IPDBannerAdView alloc] initWithPlacementId:adId viewController:self adSize:CGSizeMake(width, IPDBannerHeight)];
//    self.bannerView.delegate = self;
//    [self.bannerView loadAdAndShow];
//    [self addBannerView];
    
    [self newLoadAd:adId];
}

-(void)showAd{
    [self.bannerAd showAd];
    UIView *bannerView = [self.bannerAd bannerView];
    CGFloat y = self.view.frame.size.height - bannerView.frame.size.height -kSafeBottomMargin-50;
    CGRect frame = CGRectMake(0, y, bannerView.frame.size.width, bannerView.frame.size.height);
    bannerView.frame = frame;
    [self.view addSubview:bannerView];
}

-(void)addBannerView{
    if(self.bannerView&&![self.view.subviews containsObject:self.bannerView]){
        CGFloat y = self.view.frame.size.height -IPDBannerHeight-kSafeBottomMargin-50;
        CGRect frame = CGRectMake(0, y, self.view.frame.size.width, IPDBannerHeight);
        self.bannerView.frame = frame;
        [self.view addSubview:self.bannerView];
    }
}

// 新的对接方法
- (void)newLoadAd:(NSString *)adId
{
    CGFloat width = self.view.frame.size.width;
    self.bannerAd = [[IPDBannerAd alloc] initWithPlacementId:adId rootViewController:self adSize:CGSizeMake(width, IPDBannerHeight)];
    self.bannerAd.delegate = self;
    [self.bannerAd loadAd];
}

#pragma mark IPDBannerAdViewDelegate
/**
 banner广告加载成功
 */
- (void)ipd_bannerAdViewDidLoad:(IPDBannerAdView *)bannerAdView{
    [self logMessage:@"bannerAdViewDidLoad"];
}

/**
 banner广告加载失败
 */
- (void)ipd_bannerAdView:(IPDBannerAdView *)bannerAdView didLoadFailWithError:(NSError *_Nullable)error{
    NSArray *errors =  [self.bannerView getFillFailureMessages];
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"bannerAdViewError:%@",error]];
}


/**
 bannerAdView曝光回调
 */
- (void)ipd_bannerAdViewWillBecomVisible:(IPDBannerAdView *)bannerAdView{
    [self logMessage:@"bannerAdShow"];
}

/**
 关闭banner广告回调
 */
- (void)ipd_bannerAdViewDislike:(IPDBannerAdView *)bannerAdView{
    [self logMessage:@"bannerAdDislike"];
}

/**
 点击banner广告回调
 */
- (void)ipd_bannerAdViewDidClick:(IPDBannerAdView *)bannerAdView{
    
}

/**
 关闭banner广告详情页回调
 */
- (void)ipd_bannerAdViewDidCloseOtherController:(IPDBannerAdView *)bannerAdView{
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark - IPDBannerAdDelegate
/**
 banner广告加载成功
 */
- (void)ipd_bannerAdDidLoad:(IPDBannerAd *)bannerAd
{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    [self logMessage:[NSString stringWithFormat:@"ipd_bannerAdDidLoad"]];
    [self logMessage:[bannerAd valueForKey:@"logString"]];
}

/**
 banner广告加载失败
 */
- (void)ipd_bannerAd:(IPDBannerAd *)bannerAd didLoadFailWithError:(NSError * _Nullable)error
{
    [self logMessage:[NSString stringWithFormat:@"bannerAdViewError:%@",error]];
}

/**
 bannerAdView曝光回调
 */
- (void)ipd_bannerAdWillBecomVisible:(IPDBannerAd *)bannerAd
{
    [self logMessage:[NSString stringWithFormat:@"ipd_bannerAdWillBecomVisible"]];
}

/**
 关闭banner广告回调
 */
- (void)ipd_bannerAdDislike:(IPDBannerAd *)bannerAd
{
    [self logMessage:[NSString stringWithFormat:@"ipd_bannerAdDislike"]];
}

/**
 点击banner广告回调
 */
- (void)ipd_bannerAdDidClick:(IPDBannerAd *)bannerAd
{
    [self logMessage:[NSString stringWithFormat:@"ipd_bannerAdDidClick"]];
}

/**
 关闭banner广告详情页回调
 */
- (void)ipd_bannerAdDidCloseOtherController:(IPDBannerAd *)bannerAd
{
    [self logMessage:[NSString stringWithFormat:@"ipd_bannerAdDidCloseOtherController"]];
}

@end
