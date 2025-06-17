//
//  WindMillAds.h
//  WindMillSDK
//
//  Created by Codi on 2021/10/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AWMDeviceProtocol.h"

typedef NS_ENUM (NSInteger, WindMillCCPAStatus) {
    WindMillCCPAUnknown = 0,
    WindMillCCPAAccepted,
    WindMillCCPADenied,
};

typedef NS_ENUM (NSInteger, WindMillConsentStatus) {
    WindMillConsentUnknown = 0,
    WindMillConsentAccepted,
    WindMillConsentDenied,
};

typedef NS_ENUM (NSInteger, WindMillAgeRestrictedStatus) {
    WindMillAgeRestrictedStatusUnknow = 0,
    WindMillAgeRestrictedStatusYES, //年龄受限制
    WindMillAgeRestrictedStatusNO,  //成年人，年龄不受限制
};

typedef enum : NSUInteger {
    WindMillAdult = 0,
    WindMillChildren = 1,
} WindMillAdultState;

typedef enum : NSUInteger {
    WindMillPersonalizedAdvertisingOn = 0,
    WindMillPersonalizedAdvertisingOff = 1,
} WindMillPersonalizedAdvertisingState;



@interface WindMillAds : NSObject

+ (NSString *)sdkVersion;

// 获取平台唯一ID，需要在一次广告请求后调研，否则返回为nil
+ (NSString *)getUid;

// 获取初始化状态
+ (BOOL)hasInitSuccessed;

// Initialize WindMill Ads SDK
+ (void)setupSDKWithAppId:(NSString *)appId;

/// 场景曝光，sceneId由平台生成
+ (void)sceneExposeWithSceneId:(NSString *)sceneId sceneName:(NSString *)sceneName;

/// 设置流量分组自定义规则
/// (详细使用可参考在线文档：https://doc.sigmob.com/#/)
+ (void)initCustomGroup:(NSDictionary *)group;

/// 设置自定义信息
/// @param delegate 自定义代理对象
/// @warning  初始化前调用，否则有可能不生效
+ (void)setCustomDeviceController:(id<AWMDeviceProtocol>)delegate;

/**
 *   DeBug开关显示
 *
 *  @param enable true 开启debug，false 关闭debug
 */
+ (void)setDebugEnable:(BOOL)enable;

/*********  CCPA加州消费者隐私保护法案  *********/
+ (void)setCCPAStatus:(WindMillCCPAStatus)status;
+ (WindMillCCPAStatus)getCCPAStatus;

/*********  GDPR  *********/
+ (void)setUserGDPRConsentStatus:(WindMillConsentStatus)status;
+ (WindMillConsentStatus)getUserGDPRConsentStatus;

/*********  COPPA儿童在线隐私权保护法  *********/
+ (void)setIsAgeRestrictedUser:(WindMillAgeRestrictedStatus)status;
+ (WindMillAgeRestrictedStatus)getAgeRestrictedStatus;

/*********  设置是否是成年人  *********/
/// WindAdult: 成年人， WindChildren: 未成年人 default=WindAdult
+ (void)setAdult:(WindMillAdultState)state;
+ (WindMillAdultState)getAdultState;

/********* 个性化推荐设置  *********/
/// WindPersonalizedAdvertisingOn: 开启个性化推荐
/// WindPersonalizedAdvertisingOff: 关闭个性化推荐,
/// default=WindPersonalizedAdvertisingOn
+ (void)setPersonalizedAdvertising:(WindMillPersonalizedAdvertisingState)state;
+ (WindMillPersonalizedAdvertisingState)getPersonalizedAdvertisingState;

+ (NSUInteger)getUserAge;
+ (void)setUserAge:(NSUInteger)age;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;


@end
