//
//  IPDFeedPageAd.h
//  IPDSDK
//
//  Created by 麻明康 on 2025/1/20.
//  Copyright © 2025 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <UIKit/UIKit.h>
#import <IPDSDKCore/IPDFeedPageAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDFeedPageAd : IPDTierAd

///视频状态代理
@property (nonatomic, weak) id <IPDContentPageVideoStateDelegate> videoStateDelegate;
///页面状态代理
@property (nonatomic, weak) id <IPDContentPageStateDelegate> stateDelegate;

/// 处理视频内容加载成功和失败的代理方法
@property (nonatomic, weak) id <IPDContentPageLoadCallBackDelegate> loadCallBackDelegate;

@property (nonatomic, strong) IPDFeedPageAdapter *currentAdapter;


/// 内容页的ViewController
- (UIViewController *)feedPageViewController;

@end

NS_ASSUME_NONNULL_END
