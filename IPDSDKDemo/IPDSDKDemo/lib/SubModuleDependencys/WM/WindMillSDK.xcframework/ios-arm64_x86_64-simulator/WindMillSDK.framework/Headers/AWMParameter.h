//
//  AWMParameter.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/13.
//

#import <Foundation/Foundation.h>

@class WADOptions;

@interface AWMParameter : NSObject
/// 广告位ID
@property (nonatomic, copy, readonly) NSString *placementId;
/// 是否开启竞价
@property (nonatomic, assign, readonly) BOOL isHeaderBidding;
/// 自定义渠道中在平台输入的自定义参数
@property (nonatomic, strong, readonly) NSDictionary *customInfo;
/// 扩展参数 - 针对广告加载
@property (nonatomic, strong, readonly) NSDictionary *extra;
/// 扩展参数 - 针对广告播放
@property (nonatomic, strong, readonly) NSDictionary *showExtra;
@end
