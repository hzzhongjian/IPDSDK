//
//  ZJFloatingAdViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/7/16.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDFloatingAdViewController.h"
#import <IPDSDK/IPDFloatingAdView.h>

@interface IPDFloatingAdViewController ()<IPDFloatingAdViewDelegate>

@property (nonatomic,strong)IPDFloatingAdView *floatingAd;

@end

@implementation IPDFloatingAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.floatingAd = [[IPDFloatingAdView alloc]initWithPlacementId:AdId_Floating1 frame:CGRectZero];
    self.floatingAd.delegate = self;
    self.floatingAd.backImage = [UIImage imageNamed:@"zj_h5_back"];
    self.floatingAd.hiddenH5CloseButton = YES;
    self.floatingAd.closeText = [[NSAttributedString alloc]initWithString:@"关闭" attributes:@{NSForegroundColorAttributeName:[UIColor redColor]}];
    [self.floatingAd loadAd];
//
//    adView.canMove = YES;
//    adView.needMoveToSide = NO;
}




-(void)ipd_floatingAdViewDidLoad:(IPDFloatingAdView *)floatingAdView{
    NSLog(@"======%s",__FUNCTION__);
    [self.view addSubview:floatingAdView];
}

-(void)ipd_floatingAdViewError:(IPDFloatingAdView *)floatingAdView error:(NSError *)error{
    NSLog(@"======%s",__FUNCTION__);
}

-(void)ipd_floatingAdViewDidClick:(IPDFloatingAdView *)floatingAdView{
    NSLog(@"======%s",__FUNCTION__);
}

-(void)ipd_floatingAdViewDidClose:(IPDFloatingAdView *)floatingAdView{
    NSLog(@"======%s",__FUNCTION__);
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
