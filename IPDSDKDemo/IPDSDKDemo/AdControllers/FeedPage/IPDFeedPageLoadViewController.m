//
//  ZJFeedPageLoadViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "IPDFeedPageLoadViewController.h"
#import "IPDFeedPageViewController.h"
#import "IPDContentPageTabBarController.h"
#import "UIButton+Event.h"

@interface IPDFeedPageLoadViewController ()

@end

@implementation IPDFeedPageLoadViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_ContentPage1]];
    
    [self.loadAdView.loadButton setTitle:@"加载广告页" forState:UIControlStateNormal];
    
    __weak typeof(self) weakSelf = self;
    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
        IPDFeedPageViewController *feedPage = [[IPDFeedPageViewController alloc]init];
        feedPage.contentId = weakSelf.loadAdView.adIDTextField.text;
        [weakSelf.navigationController pushViewController:feedPage animated:YES];
    }];

    self.loadAdView.showButton.hidden = NO;
    
}


@end
