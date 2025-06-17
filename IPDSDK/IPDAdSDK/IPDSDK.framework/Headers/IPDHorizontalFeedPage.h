//
//  IPDHorizontalFeedPage.h
//  IPDSDK
//
//  Created by 麻明康 on 2023/1/5.
//  Copyright © 2023 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>
#import <IPDSDK/IPDContentPageHorizontalFeedCallBackDelegate.h>
#import <IPDSDKCore/IPDContentInfo.h>

// 视频内容横板

NS_ASSUME_NONNULL_BEGIN

@interface IPDHorizontalFeedPage : IPDAd <IPDContentInfo>
@property (nonatomic, readonly) UIViewController *viewController;
///视频状态代理
@property (nonatomic, weak) id <IPDContentPageHorizontalFeedCallBackDelegate> callBackDelegate;

@end

NS_ASSUME_NONNULL_END
