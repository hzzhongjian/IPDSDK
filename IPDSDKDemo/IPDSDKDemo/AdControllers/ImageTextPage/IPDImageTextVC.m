//
//  ZJImageTextVC.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2023/1/5.
//  Copyright © 2023 zj. All rights reserved.
//

#import "IPDImageTextVC.h"
#import <IPDSDK/IPDImageTextPage.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>
@interface IPDImageTextVC ()<IPDContentPageHorizontalFeedCallBackDelegate,IPDImageTextDetailDelegate>
@property (nonatomic,strong)IPDImageTextPage *contentPage;

@end

@implementation IPDImageTextVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.contentPage = [[IPDImageTextPage alloc]initWithPlacementId:self.contentId];
    self.contentPage.callBackDelegate = self;
    self.contentPage.imageTextDelegate = self;
    UIViewController *vc = self.contentPage.viewController;
    if(vc){
        CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
        vc.view.frame = CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height-contentY);
        [self addChildViewController:vc];
        [self.view addSubview:vc.view];
    }else{
        NSLog(@"图文样式已废弃，请使用其他样式");
    }
}


#pragma mark =============== ZJContentPageHorizontalFeedCallBackDelegate ===============

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

#pragma mark ZJContentPageVideoStateDelegate
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

#pragma mark ZJContentPageStateDelegate

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

#pragma mark =============== ZJImageTextDetailDelegate ===============
/// 进入图文详情页
/// @param detailViewController 图文详情页VC
/// @param feedId feedId
- (void)ipd_imageTextDetailDidEnter:(UIViewController *)detailViewController feedId:(NSString *)feedId{
    NSLog(@"======%s",__FUNCTION__);
}

/// 离开图文详情页
/// @param detailViewController 图文详情页VC
- (void)ipd_imageTextDetailDidLeave:(UIViewController *)detailViewController{
    NSLog(@"======%s",__FUNCTION__);
}


/// 图文详情页appear
/// @param detailViewController 图文详情页VC
- (void)ipd_imageTextDetailDidAppear:(UIViewController *)detailViewController{
    NSLog(@"======%s",__FUNCTION__);
}


/// 图文详情页disappear
/// @param detailViewController 图文详情页VC
- (void)ipd_imageTextDetailDidDisappear:(UIViewController *)detailViewController{
    NSLog(@"======%s",__FUNCTION__);
}


/// 图文详情加载结果
/// @param detailViewController 图文详情页VC
/// @param success 是否成功
/// @param error error
- (void)ipd_imageTextDetailDidLoadFinish:(UIViewController *)detailViewController sucess:(BOOL)success error:(NSError *)error{
    NSLog(@"======%s",__FUNCTION__);
}


/// 图文详情阅读进度
/// @param detailViewController 图文详情页VC
/// @param isFold 是否折叠
/// @param totalHeight 详情总高度
/// @param seenHeight 已经看过的高度
- (void)ipd_imageTextDetailDidScroll:(UIViewController *)detailViewController isFold:(BOOL)isFold totalHeight:(CGFloat)totalHeight seenHeight:(CGFloat)seenHeight{
    NSLog(@"======%s",__FUNCTION__);
}

@end
