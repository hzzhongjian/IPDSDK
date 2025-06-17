//
//  ZJContentAdapterHorizontalFeedCallBackDelegate.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/6.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDContentAdapterStateDelegate.h>


NS_ASSUME_NONNULL_BEGIN

@protocol IPDContentAdapterHorizontalFeedCallBackDelegate <IPDAdapterContentAdapterVideoStateDelegate, IPDContentAdapterStateDelegate, IPDContentAdapterLoadCallBackDelegate>
@optional
/// 进入横版视频详情页
/// @param viewController 详情页VC
/// @param contentInfo 视频信息
- (void)ipdAdapter_horizontalFeedDetailDidEnter:(UIViewController *)viewController contentInfo:(id<IPDContentInfo>)contentInfo;

/// 离开横版视频详情页
/// @param viewController 详情页VC
- (void)ipdAdapter_horizontalFeedDetailDidLeave:(UIViewController *)viewController;

/// 视频详情页appear
/// @param viewController 详情页VC
- (void)ipdAdapter_horizontalFeedDetailDidAppear:(UIViewController *)viewController;

/// 详情页disappear
/// @param viewController 详情页VC
- (void)ipdAdapter_horizontalFeedDetailDidDisappear:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
