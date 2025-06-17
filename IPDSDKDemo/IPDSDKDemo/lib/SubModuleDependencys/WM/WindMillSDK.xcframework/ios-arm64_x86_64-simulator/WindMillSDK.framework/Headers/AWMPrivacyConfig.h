//
//  AWMPrivacyConfig.h
//  WindMillSDK
//
//  Created by Codi on 2022/11/7.
//

#import <Foundation/Foundation.h>

/// 【可选】NSNumber，是否限制个性化广告:0-不限制，1-限制，默认为0。
const static NSString *kAWMPrivacyLimitPersonalAds = @"AWMPrivacyLimitPersonalAds";

/// 【可选】NSNumber，是成人或者儿童，2-儿童(＜15),1-儿童(15-18岁), 0-成人，默认为0(成人)。
const static NSString *kAWMPrivacyNotAdult = @"AWMPrivacyNotAdult";

/// 【可选】NSNumber，GDPR授权状态：0-位置，1-同意，2-拒绝，默认为0。
const static NSString *kAWMPrivacyStateGDPR = @"AWMPrivacyStateGDPR";

/// 【可选】NSNumber，CCPA授权状态：0-位置，1-同意，2-拒绝，默认为0。
const static NSString *kAWMPrivacyStateCCPA = @"AWMPrivacyStateCCPA";

/// 【可选】NSNumber，COPPA授权状态：0-位置，1-同意，2-拒绝，默认为0。
const static NSString *kAWMPrivacyStateCOPPA = @"AWMPrivacyStateCOPPA";

@interface AWMPrivacyConfig : NSObject

// 根据key配置相关隐私项
+ (void)setPrivacyWithKey:(const NSString *)key andValue:(id)value;

// 获取当前配置项
+ (NSDictionary *)privacyConfig;

@end
