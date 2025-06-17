//
//  IPDAdEventReport.h
//  IPDSDKCore
//
//  Created by Rare on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDAdBaseNetworking.h>
#import <IPDSDKCore/NSError+IPDAd.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>
#import <IPDSDKCore/IPDAdExposureReportParam.h>


NS_ASSUME_NONNULL_BEGIN

typedef NSString *IPDEventString NS_STRING_ENUM;
FOUNDATION_EXPORT NSString * const IPDEvent_START;//开始调用
FOUNDATION_EXPORT NSString * const IPDEvent_Load;//加载成功
FOUNDATION_EXPORT NSString * const IPDEvent_Show;//展示成功
FOUNDATION_EXPORT NSString * const IPDEvent_Finish;//触发激励
FOUNDATION_EXPORT NSString * const IPDEvent_Click;//点击
FOUNDATION_EXPORT NSString * const IPDEvent_Error;//错误
FOUNDATION_EXPORT NSString * const IPDEvent_Other;//其他信息
FOUNDATION_EXPORT NSString * const IPDEvent_Start_Show; // 媒体调用我们激励视频的展示方法


@interface IPDAdEventReport : IPDAdBaseNetworking

//事件上报
+ (void)reportEventWithZjad_id:(NSString *)zjad_id
                        adType:(IPDAdType)adType
                         event:(IPDEventString)event
                     unionType:(NSString *)unionType
                      zj_pm_id:(NSString *)zj_pm_id
                 supplementMsg:(NSString * _Nullable )supplementMsg
                      otherDic:(NSDictionary * _Nullable)otherDic
                     ad_config:(IPDAdUnitModel *)ad_config
                      callback:(void(^)(_Nullable id responseObject, NSError * _Nullable error))callback;

+ (nullable NSURLSessionTask *)reportAppInitWithCallback:(nullable void(^)(_Nullable id responseObject, NSError * _Nullable error))callback;

+ (NSString *)getTimestampSince1970;

+ (NSNumber *)adPlatformTypeConvertPmType:(IPDAdPlatformType)adPlatformType;

+ (NSNumber *)adADNNameConvertPmType:(IPDAdADNName)adADNName;

+ (NSString *)adPlatformTypeConvertPmName:(IPDAdPlatformType)adPlatformType;

@end

NS_ASSUME_NONNULL_END
