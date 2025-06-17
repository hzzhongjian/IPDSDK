//
//  IPDTubePageAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2024/6/12.
//

#import <IPDSDKCore/IPDBaseTubeAdapter.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDKCore/IPDContentAdapterStateDelegate.h>
#import <IPDSDKCore/IPDContentAdapterStateProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDTubePageAdapter : IPDBaseTubeAdapter<
IPDContentAdapterStateProtocol,
IPDAdapterContentAdapterVideoStateProtocol,
IPDContentAdapterLoadCallBackProtocol,
IPDShortPlayPlayerCallBackProtocol,
IPDShortPlayAdCallBackProtocol,
IPDShortPlayInterfaceCallBackProtocol,
IPDShortPlayCustomViewCallBackProtocol,
IPDShortPlayCustomDrawAdViewCallBackProtocol,
IPDShortPlayDrawVideoViewControllerBannerCallBackProtocol
>
/// 任务完成回调
- (void)ipdAdapter_contentTaskComplete:(id<IPDContentInfo>)content;

///  视频状态代理
@property (nonatomic, weak) id <IPDAdapterContentAdapterVideoStateDelegate> ipdAdapter_videoStateDelegate;
///  页面状态代理
@property (nonatomic, weak) id <IPDContentAdapterStateDelegate> ipdAdapter_stateDelegate;
/// 加载状态回调
@property (nonatomic, weak) id <IPDContentAdapterLoadCallBackDelegate> ipdAdapter_loadCallbackDelegate;

// 以下为新增回调
/// 短剧播放器回调
@property (nonatomic, weak) id <IPDShortPlayPlayerCallBackDelegate> ipdAdapter_playerCallbackDelegate;

/// 广告回调
@property (nonatomic, weak) id <IPDShortPlayAdCallBackDelegate> ipdAdapter_adCallbackDelegate;

/// 业务接口回调
@property (nonatomic, weak) id <IPDShortPlayInterfaceCallBackDelegate> ipdAdapter_interfaceCallbackDelgate;

/// 自定义详情页cell试图回调
@property (nonatomic, weak) id <IPDShortPlayCustomViewCallBackDelegate> ipdAdapter_customViewCallBackDelegate;

/// 自定义Draw流的subview回调
@property (nonatomic, weak) id <IPDShortPlayCustomDrawAdViewCallBackDelegate> ipdAdapter_customDrawAdViewCallBackDelegate;

/// 滑滑溜底部自定义Banner广告
@property (nonatomic, weak) id <IPDShortPlayDrawVideoViewControllerBannerCallBackDelegate> ipdAdapter_drawVideoViewBannerCallbackDelegate;

@end

NS_ASSUME_NONNULL_END
