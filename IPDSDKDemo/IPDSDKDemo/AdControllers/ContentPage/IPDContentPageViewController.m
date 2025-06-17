//
//  ZJContentPageViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "IPDContentPageViewController.h"
#import "IPDContentPageStyle1ViewController.h"
#import "IPDContentPageTabBarController.h"
#import "UIButton+Event.h"

@interface IPDContentPageViewController ()

@end

@implementation IPDContentPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_ContentPage1]];
    
    [self.loadAdView.loadButton setTitle:@"style1" forState:UIControlStateNormal];
    
    __weak typeof(self) weakSelf = self;
    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
        IPDContentPageStyle1ViewController *contentPage1VC = [[IPDContentPageStyle1ViewController alloc]init];
        contentPage1VC.contentId = weakSelf.loadAdView.adIDTextField.text;
        [weakSelf.navigationController pushViewController:contentPage1VC animated:YES];
    }];

    [self.loadAdView.showButton setTitle:@"style2(长按返回)" forState:UIControlStateNormal];
    [self.loadAdView.showButton clickHandle:^(UIButton *button) {
        //demo 使用的ID K90010005
        IPDContentPageTabBarController *contentPage2VC = [[IPDContentPageTabBarController alloc]init];
        [weakSelf.navigationController pushViewController:contentPage2VC animated:YES];

    }];
}


@end
