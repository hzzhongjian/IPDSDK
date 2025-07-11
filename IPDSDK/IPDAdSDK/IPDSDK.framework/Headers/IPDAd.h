//
//  IPDAd.h
//  IPDSDK
//
//  Created by Rare on 2022/2/25.
//  Copyright © 2022 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <IPDSDKCore/IPDAdDebugLog.h>
#import <IPDSDKCore/NSError+IPDAd.h>
#import <IPDSDKCore/IPDAdInfo.h>
#import <IPDSDKCore/IPDAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDAd : NSObject <IPDAdProtocol>

// 广告位ID
@property (nonatomic, copy, readonly) NSString *placementId;

/// bidding广告竞价成功是否回传，由sdk内部使用
@property (nonatomic, assign, readonly) BOOL isBiddingSuccessReport;

/**
*  构造方法
*  详解：placementId - 广告位 ID
*/
- (instancetype)initWithPlacementId:(NSString *)placementId;


// 获取错误信息
- (NSArray *)getFillFailureMessages;

/**
 * 返回广告的eCPM，广告加载成功后调用有效，单位：分
 * @return 成功返回一个大于等于0的值，
 */
- (NSInteger)eCPM;

// 返回广告相关信息，例如：广告ID，广告名字，广告平台类型
- (IPDAdInfo *)adInfo;

// 判断广告是否有效，默认从广告加载成功到广告过期，30分钟的时效
- (BOOL)pmAdValid;

// 获取本条广告一些额外信息
- (NSDictionary *)getExtraInfo;

/// 竞胜成功的事件回调，由sdk内部使用。
- (void)biddingSuccessCallbackEvent;

@end

NS_ASSUME_NONNULL_END
