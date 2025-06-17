//
//  IPDNewsAdViewController.m
//  IPDSDKDemo
//
//  Created by 麻明康 on 2022/12/19.
//  Copyright © 2022 zj. All rights reserved.
//

#import "IPDNewsAdViewController.h"
#import <WebKit/WebKit.h>
#import <IPDSDK/IPDNewsAdView.h>
#import <IPDSDKCore/IPDSDKDefines.h>
#import <IPDSDK/IPDNewsAd.h>
@interface IPDNewsAdViewController () <IPDNewsAdViewDelegate, IPDNewsAdDelegate>
@property(nonatomic,strong) IPDNewsAdView *newsAdView;

@property (nonatomic, strong) IPDNewsAd *newsAd;

@end

@implementation IPDNewsAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //J1321306298
    [self.loadAdView appendAdID:@[AdId_News1,AdId_News2]];
    [self.loadAdView.showButton setHidden:NO];
    [self setBackBarButton];

}
-(void)setBackBarButton{
    //返回按钮
    UIButton *backButton  =  [[UIButton alloc] init];
    backButton.titleLabel.font = [UIFont systemFontOfSize:16];
    backButton.userInteractionEnabled = YES;
    
    //    backButton.frame  =  CGRectMake(12.5, 0, 25, 25);
    // iOS 11 适配
    if (@available(iOS 13, *)) {
        backButton.frame  =  CGRectMake(2.5, 0, 22, 22);
    } else {
        backButton.frame  =  CGRectMake(12.5, 0, 40, 22);
    }
    if (@available(iOS 13.0, *)) {
        [backButton setImage:[UIImage systemImageNamed:@"chevron.backward"] forState:UIControlStateNormal];
        [backButton setImage:[UIImage systemImageNamed:@"chevron.backward"] forState:UIControlStateHighlighted];
    } else {
//        [backButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [backButton setTitle:@"Back" forState:UIControlStateNormal];
        [backButton setTitle:@"Back" forState:UIControlStateHighlighted];
    }
    backButton.imageEdgeInsets = UIEdgeInsetsMake(2, 2, 2, 2);
    [backButton addTarget: self action:@selector(closeView) forControlEvents: UIControlEventTouchUpInside];
    UIView *leftview = [[UIView alloc]initWithFrame:CGRectMake(0, 0, 40, 22)];
    [leftview addSubview:backButton];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:leftview];
}
//返回按钮
-(void)closeView
{
    if ([self.newsAdView canGoBack]) {
        [self.newsAdView goBack];
    } else {
        if (_newsAdView) {
            [_newsAdView removeFromSuperview];
            _newsAdView = nil;
        } else {
            [self.navigationController popViewControllerAnimated:YES];
        }
    }
}

#pragma mark =============== IPDNewsAdViewDelegate ===============
/**
 news广告加载成功
 */
- (void)ipd_newsAdViewDidLoad:(IPDNewsAdView *)newsAdView{
    [self logMessage:NSStringFromSelector(_cmd)];
}

- (void)ipd_newsAdViewDidShow:(IPDNewsAdView *)newsAdView{
    [self logMessage:NSStringFromSelector(_cmd)];
}
/**
 news广告加载失败
 */
- (void)ipd_newsAdView:(IPDNewsAdView *)newsAdView didLoadFailWithError:(NSError * _Nullable)error{
    [self logMessage:NSStringFromSelector(_cmd)];

    [self.newsAdView removeFromSuperview];

}

/**
 news广告奖励触发回调
 */
- (void)ipd_newsAdViewRewardEffective:(IPDNewsAdView *)newsAdView{
    [self logMessage:NSStringFromSelector(_cmd)];

}

/**
 点击news广告回调
 */
- (void)ipd_newsAdViewDidClick:(IPDNewsAdView *)newsAdView{
    [self logMessage:NSStringFromSelector(_cmd)];

}

/**
 canGoBack状态监听
 */
- (void)ipd_newsAd:(IPDNewsAdView *)newsAd canGoBackStateChange:(BOOL)canGoBack{
    [self logMessage:NSStringFromSelector(_cmd)];
    self.newsAdView.enableGoBackGesture = canGoBack;
    self.newsAdView.enableSlide = !canGoBack;
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
//    if (_newsAdView) {
//        [_newsAdView removeFromSuperview];
//        _newsAdView = nil;
//    }
//    self.newsAdView = [[IPDNewsAdView alloc] initWithPlacementId:adId frame:CGRectMake(0, IPD_StatusBarHeight+44, kScreenWidth, kScreenHeight-IPD_StatusBarHeight-44)];
//    self.newsAdView.delegate = self;
//    self.newsAdView.userId = @"robin6666";
//    [self.view addSubview:self.newsAdView];
//    
//    [self.newsAdView loadAdAndShow];
    
    self.newsAd = [[IPDNewsAd alloc] initWithPlacementId:adId frame:CGRectMake(0, IPD_StatusBarHeight+44, kScreenWidth, kScreenHeight-IPD_StatusBarHeight-44)];
    self.newsAd.userId = @"robin6666";
    self.newsAd.delegate = self;
    [self.newsAd loadAd];
}

- (void)showAd
{
    [super showAd];
    self.newsAdView = self.newsAd.newAdView;
    [self.view addSubview:self.newsAdView];
}

/**
 news广告加载成功
 */
- (void)ipd_newsAdDidLoad:(IPDNewsAd *)newsAd
{
    [self logMessage:NSStringFromSelector(_cmd)];
    self.loadAdView.showButton.backgroundColor = kMainColor;
}

/**
 news广告加载失败
 */
- (void)ipd_newsAd:(IPDNewsAd *)newsAd didLoadFailWithError:(NSError * _Nullable)error
{
    [self logMessage:NSStringFromSelector(_cmd)];
    [self.newsAd.newAdView removeFromSuperview];
}

/**
 newsAdView曝光回调
 */
- (void)ipd_newsAdDidShow:(IPDNewsAd *)newsAd
{
    [self logMessage:NSStringFromSelector(_cmd)];
}

/**
 news获取奖励的广告回调
 */
- (void)ipd_newsAdRewardEffective:(IPDNewsAd *)newsAd
{
    [self logMessage:NSStringFromSelector(_cmd)];
}

/**
 点击news广告回调
 */
- (void)ipd_newsAdDidClick:(IPDNewsAd *)newsAd
{
    [self logMessage:NSStringFromSelector(_cmd)];
}

/**
 canGoBack状态监听
 */
- (void)ipd_newsAd:(IPDNewsAd *)newsAd newsAdCanGoBackStateChange:(BOOL)canGoBack
{
    [self logMessage:NSStringFromSelector(_cmd)];
    self.newsAd.enableGoBackGesture = canGoBack;
    self.newsAd.enableSlide = !canGoBack;
}


@end
