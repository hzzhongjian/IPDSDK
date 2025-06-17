//
//  WindMillAdInfo.h
//  WindMillSDK
//
//  Created by Codi on 2022/3/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WindMillSDK/WindMillEnum.h>

@interface WindMillAdInfo : NSObject
/// 渠道id
@property (nonatomic, assign, readonly) WindMillAdn networkId;

/// 渠道名称
@property (nonatomic, copy, readonly) NSString *networkName;

/// 渠道的广告位ID
@property (nonatomic, copy) NSString *networkPlacementId;

/// 瀑布流id / 策略分组ID
@property (nonatomic, copy, readonly) NSString *groupId;

/// 定向包ID
@property (nonatomic, copy, readonly) NSString *ruleId;

/// ab分组
@property (nonatomic, assign, readonly) NSInteger abFlag;

/// 加载优先级
@property (nonatomic, assign, readonly) NSInteger loadPriority;

/// 播放优先级
@property (nonatomic, assign, readonly) NSInteger playPriority;

/// 单位分
@property (nonatomic, assign, readonly) NSInteger eCPM;

/// 货币单位
@property (nonatomic, copy, readonly) NSString *currency;

/// 是否hb广告源
@property (nonatomic, assign, readonly) BOOL isHeaderBidding;

/// 每次展示广告时生成的独立 ID，可用于排查问题
@property (nonatomic, copy, readonly) NSString *loadId;

/// app自己的用户体系的id，开发者传入
@property (nonatomic, copy, readonly) NSString *userId;

/// 当前广告类型
@property (nonatomic, assign, readonly) WindMillAdSlotType adType;

/// 广告场景id，由开发者传入
@property (nonatomic, copy, readonly) NSString *scene;

/// 开发者在request中传入的options
@property (nonatomic, strong, readonly) NSDictionary *options;

- (NSString *)toJson;

@end
