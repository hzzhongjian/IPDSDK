//
//  ZJTubePageStyle1VC.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2024/6/11.
//  Copyright © 2024 zj. All rights reserved.
//

#import "IPDTubePageStyle1VC.h"
#import <IPDSDK/IPDTubePage.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>
#import <IPDSDK/IPDTubePageAd.h>

@interface IPDTubePageStyle1VC ()<IPDContentPageVideoStateDelegate,IPDContentPageStateDelegate, IPDContentPageLoadCallBackDelegate>
@property (nonatomic, strong) IPDTubePage *tubePage;
@property (nonatomic, weak) UIViewController *weakTubeVC;

@property (nonatomic, strong) IPDTubePageAd *tubePageAd;

@end

@implementation IPDTubePageStyle1VC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"短剧";
    IPDTubePageConfig *config = [[IPDTubePageConfig alloc] init];
    config.JSONConfigPath = [[NSBundle mainBundle] pathForResource:@"SDK_Setting_5434885" ofType:@"json"];
    config.freeEpisodesCount = 2;
    config.unlockEpisodesCountUsingAD = 1;
    config.hideLikeIcon = YES;
    config.hideCollectIcon = YES;
    config.showCloseButton = YES;
    [IPDTubePage setConfig:config];
    self.tubePage = [[IPDTubePage alloc]initWithPlacementId:self.contentId];
    self.tubePage.videoStateDelegate = self;
    self.tubePage.stateDelegate = self;
    self.weakTubeVC = self.tubePage.viewController;
    if(self.weakTubeVC){
//        CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
//        self.weakTubeVC.view.frame = CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height-contentY);
//        [self addChildViewController:self.weakTubeVC];
//        [self.view addSubview:self.weakTubeVC.view];
        [self presentViewController:self.weakTubeVC animated:YES completion:^{
                    
        }];
    }else{
        NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
    }
}

- (void)newTubePageAd
{
    IPDTubePageConfig *config = [[IPDTubePageConfig alloc] init];
    config.JSONConfigPath = [[NSBundle mainBundle] pathForResource:@"SDK_Setting_5434885" ofType:@"json"];
    config.freeEpisodesCount = 2;
    config.unlockEpisodesCountUsingAD = 1;
    config.hideLikeIcon = YES;
    config.hideCollectIcon = YES;
    config.showCloseButton = YES;
    CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
//    config.viewSize = CGSizeMake(self.view.bounds.size.width, self.view.bounds.size.height - contentY);
    self.tubePageAd = [[IPDTubePageAd alloc]initWithPlacementId:self.contentId];
    self.tubePageAd.tubePageConfig = config;
    self.tubePageAd.videoStateDelegate = self;
    self.tubePageAd.stateDelegate = self;
    self.tubePageAd.loadCallBackDelegate = self;
    [self.tubePageAd loadAd];
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [_tubePage.viewController viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [_tubePage.viewController viewDidAppear:animated];
}

-(void)showAd{
    self.weakTubeVC = self.tubePageAd.tubePageViewController;
    if(self.weakTubeVC){
        CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
        self.weakTubeVC.view.frame = CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height-contentY);
        // 快手只能push
        [self addChildViewController:self.weakTubeVC];
        [self.view addSubview:self.weakTubeVC.view];
        // 穿山甲目前用presentViewController的方式
//        [self presentViewController:self.weakTubeVC animated:YES completion:^{
//                    
//        }];
    }else{
        NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
    }
}

#pragma mark - IPDContentPageLoadCallBackDelegate

- (void)ipd_contentPageLoadSuccess
{
    NSLog(@"短剧内容可以加载了");
}

- (void)ipd_contentPageLoadFailure:(NSError *)error
{
    NSLog(@"短剧内容加载失败了");
}

#pragma mark IPDContentPageVideoStateDelegate
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)ipd_videoDidStartPlay:(id<IPDContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)ipd_videoDidPause:(id<IPDContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)ipd_videoDidResume:(id<IPDContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)ipd_videoDidEndPlay:(id<IPDContentInfo>)videoContent isFinished:(BOOL)finished{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)ipd_videoDidFailedToPlay:(id<IPDContentInfo>)videoContent withError:(NSError *)error{
    NSLog(@"%s，%@",__FUNCTION__,error);
}

#pragma mark IPDContentPageStateDelegate

/**
* 内容展示
* @param content 内容模型
*/
- (void)ipd_contentDidFullDisplay:(id<IPDContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)ipd_contentDidEndDisplay:(id<IPDContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)ipd_contentDidPause:(id<IPDContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)ipd_contentDidResume:(id<IPDContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}

@end
