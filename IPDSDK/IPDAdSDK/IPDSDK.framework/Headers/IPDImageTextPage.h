//
//  IPDImageTextPage.h
//  IPDSDK
//
//  Created by 麻明康 on 2023/1/5.
//  Copyright © 2023 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDK/IPDContentPageHorizontalFeedCallBackDelegate.h>
#import <IPDSDK/IPDImageTextDetailDelegate.h>

NS_ASSUME_NONNULL_BEGIN


@interface IPDImageTextPage : IPDAd <IPDContentInfo>
@property (nonatomic, readonly) UIViewController *viewController;

@property (nonatomic, weak) id <IPDContentPageHorizontalFeedCallBackDelegate> callBackDelegate;
@property (nonatomic, weak) id <IPDImageTextDetailDelegate> imageTextDelegate;

@end

NS_ASSUME_NONNULL_END
