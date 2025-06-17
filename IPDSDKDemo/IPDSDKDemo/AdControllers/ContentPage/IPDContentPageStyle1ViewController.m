//
//  ZJContentPageStyle1ViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import "IPDContentPageStyle1ViewController.h"
#import <IPDSDK/IPDContentPage.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>

@interface IPDContentPageStyle1ViewController ()<IPDContentPageVideoStateDelegate,IPDContentPageStateDelegate>

@property (nonatomic,strong)IPDContentPage *contentPage;
@end

@implementation IPDContentPageStyle1ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.contentPage = [[IPDContentPage alloc]initWithPlacementId:self.contentId];
    self.contentPage.videoStateDelegate = self;
    self.contentPage.stateDelegate = self;
    UIViewController *vc = self.contentPage.viewController;
    if(vc){
        CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
        vc.view.frame = CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height-contentY);
        [self addChildViewController:vc];
        [self.view addSubview:vc.view];
    }else{
        NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
    }
//    [vc.view mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.mas_equalTo(200);
//        make.left.right.mas_equalTo(0);
//        make.bottom.mas_equalTo(-80);
//    }];
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

@end
