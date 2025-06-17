//
//  ZJTubePageVC.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2024/6/11.
//  Copyright © 2024 zj. All rights reserved.
//

#import "IPDTubePageVC.h"
#import "IPDTubePageStyle1VC.h"
#import <IPDSDK/IPDTubePage.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>
#import <IPDSDK/IPDTubePageAd.h>
#import <IPDSDKCore/IPDCommon.h>

@interface IPDTubePageVC () <IPDContentPageVideoStateDelegate,IPDContentPageStateDelegate, IPDContentPageLoadCallBackDelegate, IPDShortPlayCustomViewDelegate, IPDShortPlayInterfaceDelegate, IPDShortPlayCustomDrawAdViewDelegate, IPDShortPlayDrawVideoViewControllerBannerDelegate, IPDShortPlayAdDelegate, IPDShortPlayPlayerDelegate>

@property (nonatomic, strong) IPDTubePageStyle1VC *vc;


@property (nonatomic, strong) IPDTubePage *tubePage;

@property (nonatomic, weak) UIViewController *weakTubeVC;

@property (nonatomic, strong) IPDTubePageAd *tubePageAd;

@end

@implementation IPDTubePageVC

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_Tube1]];
    
    [self.loadAdView.loadButton setTitle:@"加载短剧" forState:UIControlStateNormal];
    
    __weak typeof(self) weakSelf = self;
//    [self.loadAdView.loadButton clickHandle:^(UIButton *button) {
//        self.vc = [[IPDTubePageStyle1VC alloc]init];
//        self.vc.contentId = weakSelf.loadAdView.adIDTextField.text;
//        [self.vc newTubePageAd];
//        self.loadAdView.showButton.backgroundColor = kMainColor;
//    }];

    [self.loadAdView.showButton setTitle:@"展示短剧" forState:UIControlStateNormal];
//    [self.loadAdView.showButton clickHandle:^(UIButton *button) {
//        if (self.vc) {
//            [self.navigationController pushViewController:self.vc animated:YES];
//            [self.vc showAd];
//        } else {
//            IPDTubePageStyle1VC *contentPage1VC = [[IPDTubePageStyle1VC alloc]init];
//            contentPage1VC.contentId = weakSelf.loadAdView.adIDTextField.text;
//            [self.navigationController pushViewController:contentPage1VC animated:YES];
//        }
//    }];
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [_tubePage.viewController viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [_tubePage.viewController viewDidAppear:animated];
}

- (void)loadAd:(NSString *)adId
{
    IPDTubePageConfig *config = [[IPDTubePageConfig alloc] init];
    config.JSONConfigPath = [[NSBundle mainBundle] pathForResource:@"SDK_Setting_5434885" ofType:@"json"];
    config.freeEpisodesCount = 1;
    config.unlockEpisodesCountUsingAD = 2;
//    config.hideLikeIcon = YES;
//    config.hideCollectIcon = YES;
    config.showCloseButton = YES;
//    CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
//    config.viewSize = CGSizeMake(self.view.bounds.size.width, self.view.bounds.size.height - contentY);
//    config.configOrNotCustomViewDelegate = YES;
//    config.configOrNotCustomDrawAdViewDelegate = YES;
//    config.configOrNotCustomBannerDelegate = YES;
//    config.customAdIndex = @[@0, @1];
    self.tubePageAd = [[IPDTubePageAd alloc]initWithPlacementId:adId];
    self.tubePageAd.tubePageConfig = config;
    self.tubePageAd.videoStateDelegate = self;
    self.tubePageAd.stateDelegate = self;
    self.tubePageAd.loadCallBackDelegate = self;
    // ====================
    /// 短剧播放器回调
    self.tubePageAd.playerCallbackDelegate = self;


    /// 广告回调
    self.tubePageAd.adCallbackDelegate = self;

    /// 业务接口回调
    self.tubePageAd.interfaceCallbackDelegate = self;

    /// 自定义详情页cell试图回调
    self.tubePageAd.customViewCallBackDelegate = self;

    /// 自定义Draw流的subview回调
    self.tubePageAd.customDrawAdViewCallBackDelegate = self;

    /// 滑滑溜底部自定义Banner广告
    self.tubePageAd.drawVideoViewBannerCallbackDelegate = self;

    
    [self.tubePageAd loadAd];
}

-(void)showAd
{
    self.weakTubeVC = self.tubePageAd.tubePageViewController;
    if(self.weakTubeVC){
//        CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
//        self.weakTubeVC.view.frame = CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height-contentY);
        // 快手只能push
        if (self.tubePageAd.currentAdapter.config.platformType == IPDAdPlatform_KS) {
            [self addChildViewController:self.weakTubeVC];
            [self.view addSubview:self.weakTubeVC.view];
        } else {
            // 穿山甲目前用presentViewController的方式
            [self presentViewController:self.weakTubeVC animated:YES completion:^{
                
            }];
        }
    }else{
        NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
    }
}

#pragma mark
/*! @abstract 视频切换时的回调 */
- (void)ipd_shortplayDrawVideoCurrentVideoChanged:(NSInteger)index adapter:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 加载失败按钮点击重试回调 */
- (void)ipd_shortplayDrawVideoDidClickedErrorButtonRetry:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 默认关闭按钮被点击的回调 */
- (void)ipd_shortplayDrawVideoCloseButtonClicked:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 数据刷新完成回调 */
- (void)ipd_shortplayDrawVideoDataRefreshCompletion:(NSError *)error content:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract tab栏切换控制器的回调*/
- (void)ipd_shortplayPageViewControllerSwitchToIndex:(NSInteger)index content:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/**! @abstract 推荐页面底部banner视图**/
- (UIView *)ipd_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc content:(id<IPDContentInfo>)content
{
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 200)];
    view.backgroundColor = [UIColor cyanColor];
    return view;
}

#pragma mark -

/*! @abstract 发起广告请求 */
- (void)ipd_shortplaySendAdRequest:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 广告加载成功 */
- (void)ipd_shortplayAdLoadSuccess:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 广告加载失败 */
- (void)ipd_shortplayAdLoadFail:(id<IPDContentInfo>)content error:(NSError *)error
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 广告填充失败 */
- (void)ipd_shortplayAdFillFail:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 广告曝光 */
- (void)ipd_shortplayAdWillShow:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 视频广告开始播放 */
- (void)ipd_shortplayVideoAdStartPlay:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 视频广告暂停播放 */
- (void)ipd_shortplayVideoAdPause:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 视频广告继续播放 */
- (void)ipd_shortplayVideoAdContinue:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 视频广告停止播放 */
- (void)ipd_shortplayVideoAdOverPlay:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 点击广告 */
- (void)ipd_shortplayClickAdViewEvent:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}
/*! @abstract 广告缓冲 */
- (void)ipd_shortplayVideoBufferEvent:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 激励视频广告结束 */
- (void)ipd_shortplayVideoRewardFinishEvent:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 激励视频广告跳过 */
- (void)ipd_shortplayVideoRewardSkipEvent:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

#pragma mark - IPDShortPlayInterfaceDelegate

/*! @abstract 解锁流程开始 */
- (void)ipd_shortplayPlayletDetailUnlockFlowStart:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 解锁流程取消 */
- (void)ipd_shortplayPlayletDetailUnlockFlowCancel:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

- (void)ipd_shortplayPlayletDetailUnlockFlowCancelUnlock:(void (^)(void))cancelUnlockCallback unlockCallback:(void (^)(void))unlockCallback
{
//    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 200)];
//    view.backgroundColor = [UIColor redColor];
//    [[UIApplication sharedApplication].keyWindow addSubview:view];
////    cancelUnlockCallback();
////    unlockCallback();
    ///
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"看广告解锁"
                                                                   message:[NSString stringWithFormat:@"看一个激励广告解锁1集"]
                                                            preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"退出" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        cancelUnlockCallback();
    }]];
    [alert addAction:[UIAlertAction actionWithTitle:@"看广告" style:UIAlertActionStyleDestructive handler:^(UIAlertAction * _Nonnull action) {
        unlockCallback();
    }]];
//    [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:alert animated:YES completion:nil];
    [[IPDCommon getCurrentVC] presentViewController:alert animated:YES completion:^{
            
    }];
}

/*! @abstract 解锁流程结束，回调解锁结果
 *  - success: 是否解锁成功
 *   - error: 解锁失败错误信息
 */
- (void)ipd_shortplayPlayletDetailUnlockFlowEnd:(id<IPDContentInfo>)content
                           success:(BOOL)success
                             error:(NSError * _Nullable)error
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 点击混排中进入跳转播放页的按钮 */
- (void)ipd_shortplayClickEnterView:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 本剧集观看完毕，切到下一部短剧回调 */
- (void)ipd_shortplayNextPlayletWillPlay:(id<IPDContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

- (UIView *)ipd_shortplayPlayletDetailBottomBanner:(id<IPDContentInfo>)content
{
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 200)];
    view.backgroundColor = [UIColor orangeColor];
    return view;
}

#pragma mark - IPDShortPlayCustomViewDelegate

/// 创建自定义View直接返回，外部不要持有，cell自己持有复用
/// @param cell 短剧的cell
- (UIView *)ipd_shortplayPlayletDetailCellCustomView:(UITableViewCell *)cell
{
    // 短剧的cell自定义视图
    UIView *view = [[UIView alloc] initWithFrame:cell.bounds];
    view.backgroundColor = [UIColor greenColor];
    return view;
}

/// 根据数据更新UI
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View，短剧的cell内部会持有
/// @param playletInfo 短剧的数据
- (void)ipd_shortplayPlayletDetailCell:(UITableViewCell *)cell updateCustomView:(UIView *)customView withPlayletData:(id)playletInfo
{
    NSLog(@"======%s",__FUNCTION__);
}

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)ipd_shortplayPlayletDetailCell:(UITableViewCell *)cell layoutSubviews:(UIView *)customView
{
    NSLog(@"======%s",__FUNCTION__);
}

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)ipd_shortplayPlayletDetailCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)customView
{
    NSLog(@"======%s",__FUNCTION__);
}

#pragma mark - ZJShortPlayCustomDrawAdViewDelegate
- (UIView *)ipd_shortplayDetailCellCreateAdView:(UITableViewCell *)cell adInputIndex:(NSUInteger)adIndex
{
//    自定义draw的广告页面
    UIView *view = [[UIView alloc] initWithFrame:cell.bounds];
    view.backgroundColor = [UIColor yellowColor];
    return view;
}

- (void)ipd_shortplayDetailCell:(UITableViewCell *)cell bindDataToDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex
{
    NSLog(@"======%s",__FUNCTION__);
}


- (void)ipd_shortplayDetailCell:(UITableViewCell *)cell layoutSubview:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex
{
    NSLog(@"======%s",__FUNCTION__);
}

- (void)ipd_shortplayDetailCell:(UITableViewCell *)cell willDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex
{
    NSLog(@"======%s",__FUNCTION__);
}

- (void)ipd_shortplayDetailCell:(UITableViewCell *)cell didEndDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex
{
    NSLog(@"======%s",__FUNCTION__);
}


#pragma mark - 推荐的底部banner
- (UIView *)ipd_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc
{
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 300)];
    view.backgroundColor = [UIColor redColor];
    return view;
    
//    return nil;
}

#pragma mark - ZJContentPageLoadCallBackDelegate

- (void)ipd_contentPageLoadSuccess
{
    NSLog(@"短剧内容可以加载了");
    self.loadAdView.showButton.backgroundColor = kMainColor;
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
