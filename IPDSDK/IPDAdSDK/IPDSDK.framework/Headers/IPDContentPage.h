//
//  IPDContentPage.h
//  IPDSDK
//
//  Created by Rare on 2020/12/21.
//  Copyright © 2020 zj. All rights reserved.
//

#import <IPDSDK/IPDAd.h>
#import <IPDSDK/IPDContentPageStateDelegate.h>
#import <IPDSDKCore/IPDContentInfo.h>

// 视频内容列表

NS_ASSUME_NONNULL_BEGIN
//typedef NS_ENUM(NSInteger, IPDContentPageType){
//    
//    IPDContentPageDefault = 0,
//    
////    IPDContentPage,
//};
@interface IPDContentPage : IPDAd <IPDContentInfo>

@property (nonatomic, readonly) UIViewController *viewController;
///视频状态代理
@property (nonatomic, weak) id <IPDContentPageVideoStateDelegate> videoStateDelegate;
///页面状态代理
@property (nonatomic, weak) id <IPDContentPageStateDelegate> stateDelegate;

- (void)tryToRefresh;

@end







NS_ASSUME_NONNULL_END
