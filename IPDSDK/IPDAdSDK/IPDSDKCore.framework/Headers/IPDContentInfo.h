//
//  IPDContentInfo.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2023/1/6.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSUInteger, IPDContentInfoType) {
    IPDContentInfoTypeUnknown,         //未知，正常不会出现
    IPDContentInfoTypeNormal,          //普通信息流
    IPDContentInfoTypeAd,              //SDK内部广告
    IPDContentInfoTypeEmbeded = 100    //外部广告
};

NS_ASSUME_NONNULL_BEGIN

@protocol IPDContentInfo <NSObject>

//内容标识
- (NSString *)contentInfoId;
//内容类型
//IPDContentInfoTypeUnknown = 0,         //未知，正常不会出现
// IPDContentInfoTypeNormal = 1,          //普通信息流
// IPDContentInfoTypeAd = 2,              //SDK内部广告
//IPDContentInfoTypeEmbeded = 100    //外部广告
- (NSInteger)contentInfoType;

@end

NS_ASSUME_NONNULL_END
