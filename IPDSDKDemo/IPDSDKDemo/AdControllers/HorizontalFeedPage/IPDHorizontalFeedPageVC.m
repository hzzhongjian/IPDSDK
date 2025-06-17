//
//  ZJHorizontalFeedPageVC.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2023/1/5.
//  Copyright © 2023 zj. All rights reserved.
//

#import "IPDHorizontalFeedPageVC.h"
#import <IPDSDK/IPDHorizontalFeedPage.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>
#import <IPDSDK/IPDHorizontalFeedPageAd.h>

@interface IPDHorizontalFeedPageVC ()<IPDContentPageHorizontalFeedCallBackDelegate, IPDContentPageLoadCallBackDelegate>
//@property (nonatomic,strong)ZJHorizontalFeedPage *contentPage;

@property (nonatomic, strong) IPDHorizontalFeedPageAd *contentPage;

@end

@implementation IPDHorizontalFeedPageVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
//    self.contentPage = [[IPDHorizontalFeedPage alloc]initWithPlacementId:self.contentId];
    self.contentPage = [[IPDHorizontalFeedPageAd alloc]initWithPlacementId:self.contentId];
    self.contentPage.videoStateDelegate = self;
    self.contentPage.stateDelegate = self;
    self.contentPage.loadCallBackDelegate = self;
    
    [self.contentPage loadAd];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(10 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        UIViewController *vc = self.contentPage.horizontalFeedPageViewController;
    //    self.contentPage.callBackDelegate = self;
    //    UIViewController *vc = self.contentPage.viewController;
        if(vc){
            CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
            vc.view.frame = CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height-contentY);
            [self addChildViewController:vc];
            [self.view addSubview:vc.view];
        }else{
            NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
        }
    });
}

/// 内容加载成功
- (void)ipd_contentPageLoadSuccess
{
    NSLog(@"======%s",__FUNCTION__);
}

/// 内容加载失败
- (void)ipd_contentPageLoadFailure:(NSError *)error
{
    NSLog(@"======%s",__FUNCTION__);
}

#pragma mark =============== IPDContentPageHorizontalFeedCallBackDelegate ===============

/// 进入横版视频详情页
/// @param viewController 详情页VC
/// @param content 视频信息
- (void)ipd_horizontalFeedDetailDidEnter:(UIViewController *)viewController contentInfo:(id<IPDContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/// 离开横版视频详情页
/// @param viewController 详情页VC
- (void)ipd_horizontalFeedDetailDidLeave:(UIViewController *)viewController{
    NSLog(@"======%s",__FUNCTION__);
}

/// 视频详情页appear
/// @param viewController 详情页VC
- (void)ipd_horizontalFeedDetailDidAppear:(UIViewController *)viewController{
    NSLog(@"======%s",__FUNCTION__);
}

/// 详情页disappear
/// @param viewController 详情页VC
- (void)ipd_horizontalFeedDetailDidDisappear:(UIViewController *)viewController{
    NSLog(@"======%s",__FUNCTION__);
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
