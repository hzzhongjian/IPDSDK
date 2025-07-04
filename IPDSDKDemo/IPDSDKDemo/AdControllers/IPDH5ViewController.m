//
//  IPDH5ViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2020/9/17.
//  Copyright © 2020 zj. All rights reserved.
//

#import "IPDH5ViewController.h"
#import <IPDSDK/IPDH5Page.h>
#import <AVFoundation/AVFoundation.h>

@interface IPDH5ViewController ()<IPDH5PageDelegate,UINavigationControllerDelegate>

@property(nonatomic,strong) IPDH5Page *zjH5Page;

@end

@implementation IPDH5ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.loadAdView appendAdID:@[AdId_Web1,AdId_Web2,AdId_Web3,AdId_Web4,AdId_Web5,AdId_Web6,AdId_Web7]];
    [self.loadAdView.loadButton setTitle:@"加载网页" forState:UIControlStateNormal];
    
}

-(void) loadAd:(NSString*) adId{
    [super loadAd:adId];
    IPDUser *user = [IPDUser new];
    user.userID = @"00012282";
//    user.userID = [NSString stringWithFormat:@"00012282_%u",arc4random() % 100];;
    user.userName = @"吊炸天524";
    user.userAvatar = @"";
    user.userIntegral = 10000;
    user.posId = adId;
    user.ext = @"超级无敌4";
    self.zjH5Page = [[IPDH5Page alloc] initWithPlacementId:adId user:user delegate:self];
    [self.zjH5Page loadH5Page];
    //zjH5Page
    //[self.zjH5 openUrl:@"http://192.168.2.18:8856" user:user delegate:self fromRootController:self];
    
}


#pragma mark -IPDH5Delegate
//H5Ad加载完成
-(void) onIPDH5PageLoaded:(IPDUser*) user error:(nullable NSError*)error{
    if(!error){
        NSError *error = nil;
            [[AVAudioSession sharedInstance] setActive:NO error:&error];
            [[AVAudioSession sharedInstance] setCategory:AVAudioSessionCategoryPlayback error:&error];
            [[AVAudioSession sharedInstance] setActive:YES error:&error];
            if(error){
                   
            }
        [self.zjH5Page presentH5FromRootViewController:self animated:YES];
    }
        
    else{
        NSString *msg =[error.userInfo valueForKey:NSLocalizedDescriptionKey];
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"提示" message:msg preferredStyle:UIAlertControllerStyleAlert];
       
        [alertController addAction:([UIAlertAction actionWithTitle:@"确认" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            [self.navigationController popViewControllerAnimated:NO];
        }])];
        [self presentViewController:alertController animated:YES completion:nil];
    }
}

//H5Ad错误
-(void)onIPDH5PageError:(IPDUser*) user error:(NSError*) error{
    NSLog(@"%s",__func__);
}

//广告
//激励视频加载成功
-(void) onIPDH5PageAdRewardLoaded:(IPDUser*) user trans_id:(NSString*) trans_id{
    NSLog(@"%s",__func__);
}

//H5Ad页面关闭
- (void)onIPDH5PageWillClose:(IPDUser *)user{
    NSLog(@"%s",__func__);
}

//激励视频触发激励（观看视频大于一定时长或者视频播放完毕）
-(void) onIPDH5PageAdRewardValid:(IPDUser*) user trans_id:(NSString*) trans_id{
    NSLog(@"%s",__func__);
}

//奖励发放,奖励积分
-(void) onIPDH5PageAdRewardProvide:(IPDUser*) user rewardIntegral:(NSInteger) integral{
    NSLog(@"%s",__func__);
}

//奖励发放,奖励积分
-(void) onIPDH5PageAdRewardClick:(IPDUser*) user {
    NSLog(@"%s",__func__);
}
//用户页面的行为操作
-(void) onIPDH5PageUserBehavior:(IPDUser*) user behavior:(NSString*) behavior{
    NSLog(@"%s",__func__);
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

//-(void)navigationController:(UINavigationController *)navigationController willShowViewController:(UIViewController *)viewController animated:(BOOL)animated{
//    if ([viewController isKindOfClass:[NSClassFromString(@"ZJWebViewController") class]]) {
//        navigationController.navigationBar.barTintColor = [UIColor redColor];
//    }else{
//        navigationController.navigationBar.barTintColor = [UIColor whiteColor];
//    }
//    NSLog(@"-----");
//}

@end
