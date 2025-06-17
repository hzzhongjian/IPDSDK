//
//  IPDFeedPageAdapter.h
//  IPDSDK
//
//  Created by Rare on 2020/12/22.
//  Copyright © 2020 zj. All rights reserved.
//

#import <IPDSDKCore/IPDBaseContentAdapter.h>
#import <UIKit/UIKit.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDKCore/IPDContentAdapterStateDelegate.h>
#import <IPDSDKCore/IPDContentAdapterStateProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDFeedPageAdapter : IPDBaseContentAdapter<
IPDContentAdapterStateProtocol,
IPDAdapterContentAdapterVideoStateProtocol,
IPDContentAdapterLoadCallBackProtocol
>

///  视频状态代理
@property (nonatomic, weak) id <IPDAdapterContentAdapterVideoStateDelegate> ipdAdapter_videoStateDelegate;
///  页面状态代理
@property (nonatomic, weak) id <IPDContentAdapterStateDelegate> ipdAdapter_stateDelegate;

@property (nonatomic, weak) id <IPDContentAdapterLoadCallBackDelegate> ipdAdapter_loadCallbackDelegate;


@end
NS_ASSUME_NONNULL_END
