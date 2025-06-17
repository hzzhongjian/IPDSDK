//
//  ZJTubePageAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/8.
//  Copyright © 2025 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>
#import <IPDSDKCore/IPDTubePageAdapter.h>
#import <IPDSDKCore/IPDTubePageConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDTubePageAd : IPDTierAd

@property (nonatomic, strong,nullable) IPDTubePageAdapter *currentAdapter;

///视频状态代理
@property (nonatomic, weak) id <IPDContentPageVideoStateDelegate> videoStateDelegate;

///页面状态代理
@property (nonatomic, weak) id <IPDContentPageStateDelegate> stateDelegate;

/// 短剧内容加载结果代理
@property (nonatomic, weak) id <IPDContentPageLoadCallBackDelegate> loadCallBackDelegate;

/// 短剧播放器回调
@property (nonatomic, weak) id <IPDShortPlayPlayerDelegate> playerCallbackDelegate;

/// 广告回调
@property (nonatomic, weak) id <IPDShortPlayAdDelegate> adCallbackDelegate;

/// 业务接口回调
@property (nonatomic, weak) id <IPDShortPlayInterfaceDelegate> interfaceCallbackDelegate;

/// 自定义详情页cell试图回调
@property (nonatomic, weak) id <IPDShortPlayCustomViewDelegate> customViewCallBackDelegate;

/// 自定义Draw流的subview回调
@property (nonatomic, weak) id <IPDShortPlayCustomDrawAdViewDelegate> customDrawAdViewCallBackDelegate;

/// 滑滑溜底部自定义Banner广告
@property (nonatomic, weak) id <IPDShortPlayDrawVideoViewControllerBannerDelegate> drawVideoViewBannerCallbackDelegate;


/// 短剧相关配置
@property (nonatomic, strong) IPDTubePageConfig *tubePageConfig;

/// 短剧内容的控制器，媒体可以直接获取并展示
- (UIViewController *)tubePageViewController;


@end

NS_ASSUME_NONNULL_END
