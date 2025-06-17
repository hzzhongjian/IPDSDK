//
//  IPDMiniParamViewController.m
//  IPDSDKDemo
//
//  Created by 麻明康 on 2022/9/20.
//  Copyright © 2022 zj. All rights reserved.
//

#import "IPDMiniParamViewController.h"
#import <IPDSDK/IPDWXMiniParamAd.h>
#import <IPDSDK/IPDWeChatMiniParamAd.h>

@interface IPDMiniParamViewController () <IPDWXMiniParamAdDelegate,IPDWeChatMiniParamAdDelegate>

@property(nonatomic,strong) IPDWXMiniParamAd *miniParamAd;

@property (nonatomic, strong) IPDWeChatMiniParamAd *wechatMiniParamAd;

@end

@implementation IPDMiniParamViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_MiniParam1]];
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    
//    self.miniParamAd = [[IPDWXMiniParamAd alloc] initWithPlacementId:adId];
//    self.miniParamAd.delegate = self;
//    [self.miniParamAd wakeUpMiniParam];
    
    self.wechatMiniParamAd = [[IPDWeChatMiniParamAd alloc] initWithPlacementId:adId];
    self.wechatMiniParamAd.delegate = self;
    [self.wechatMiniParamAd loadAd];
}


/**
 *  微信唤起失败
 */
- (void)ipd_miniParamAdAwakeFail:(IPDWXMiniParamAd *)miniParamAd error:(NSError *)error{
    NSArray *errors =  [self.miniParamAd getFillFailureMessages];
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"bannerAdViewError:%@",error]];
}

/**
 *  微信唤起成功
 */
- (void)ipd_miniParamAdDidAwake:(IPDWXMiniParamAd *)miniParamAd{
    [self logMessage:@"唤起微信小程序成功"];
}

- (void)ipd_miniParamAd:(IPDWXMiniParamAd *)miniParamAd onResp:(id)resp{
    [self logMessage:@"收到微信回调信息"];
}

#pragma mark - IPDWeChatMiniParamAdDelegate
/**
 *  小程序唤起成功
 */
- (void)ipd_wechatMiniParamAdDidAwake:(IPDWeChatMiniParamAd *)miniParamAd
{
    [self logMessage:@"唤起微信小程序成功"];
}


/**
 *  小程序唤起失败
 */
- (void)ipd_wechatMiniParamAdAwakeFail:(IPDWeChatMiniParamAd *)miniParamAd error:(NSError *)error
{
    NSArray *errors =  [self.wechatMiniParamAd getFillFailureMessages];
    [self logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
    [self logMessage:[NSString stringWithFormat:@"wechatMiniError:%@",error]];
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
