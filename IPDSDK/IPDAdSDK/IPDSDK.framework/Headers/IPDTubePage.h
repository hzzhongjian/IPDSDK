//
//  ZJTubePage.h
//  ZJSDK
//
//  Created by 麻明康 on 2024/6/12.
//  Copyright © 2024 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDKCore/IPDTubePageConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDTubePage : IPDAd <IPDContentInfo>

@property (nonatomic, readonly) UIViewController *viewController;

///视频状态代理
@property (nonatomic, weak) id <IPDContentPageVideoStateDelegate> videoStateDelegate;

///页面状态代理
@property (nonatomic, weak) id <IPDContentPageStateDelegate> stateDelegate;

// 新增类方法,必须在调用初始化方法之前使用，此方法必须调用
+ (void)setConfig:(IPDTubePageConfig *)config;

/// 短剧播放器回调
@property (nonatomic, weak) id <IPDShortPlayPlayerDelegate> playerCallbackDelegate;

/// 广告回调
@property (nonatomic, weak) id <IPDShortPlayAdDelegate> adCallbackDelegate;

/// 业务接口回调
@property (nonatomic, weak) id <IPDShortPlayInterfaceDelegate> interfaceCallbackDelegate;

/// 自定义详情页cell视图回调
@property (nonatomic, weak) id <IPDShortPlayCustomViewDelegate> customViewCallBackDelegate;

/// 自定义Draw流的subview回调
@property (nonatomic, weak) id <IPDShortPlayCustomDrawAdViewDelegate> customDrawAdViewCallBackDelegate;

/// 滑滑溜底部自定义Banner广告
@property (nonatomic, weak) id <IPDShortPlayDrawVideoViewControllerBannerDelegate> drawVideoViewBannerCallbackDelegate;

@end

NS_ASSUME_NONNULL_END
