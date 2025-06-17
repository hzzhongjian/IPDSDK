//
//  IPDImageTextDetailDelegate.h
//  IPDSDK
//
//  Created by 麻明康 on 2023/1/6.
//  Copyright © 2023 zj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//图文详情的回调
@protocol IPDImageTextDetailDelegate <NSObject>
@optional
/// 进入图文详情页
/// @param detailViewController 图文详情页VC
/// @param feedId feedId
- (void)ipd_imageTextDetailDidEnter:(UIViewController *)detailViewController feedId:(NSString *)feedId;

/// 离开图文详情页
/// @param detailViewController 图文详情页VC
- (void)ipd_imageTextDetailDidLeave:(UIViewController *)detailViewController;

/// 图文详情页appear
/// @param detailViewController 图文详情页VC
- (void)ipd_imageTextDetailDidAppear:(UIViewController *)detailViewController;

/// 图文详情页disappear
/// @param detailViewController 图文详情页VC
- (void)ipd_imageTextDetailDidDisappear:(UIViewController *)detailViewController;

/// 图文详情加载结果
/// @param detailViewController 图文详情页VC
/// @param success 是否成功
/// @param error error
- (void)ipd_imageTextDetailDidLoadFinish:(UIViewController *)detailViewController sucess:(BOOL)success error:(NSError *)error;

/// 图文详情阅读进度
/// @param detailViewController 图文详情页VC
/// @param isFold 是否折叠
/// @param totalHeight 详情总高度
/// @param seenHeight 已经看过的高度
- (void)ipd_imageTextDetailDidScroll:(UIViewController *)detailViewController isFold:(BOOL)isFold totalHeight:(CGFloat)totalHeight seenHeight:(CGFloat)seenHeight;

@end

NS_ASSUME_NONNULL_END
