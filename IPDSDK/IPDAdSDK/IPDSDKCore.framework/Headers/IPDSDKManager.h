//
//  IPDSDKManager.h
//  IPDSDKCore
//
//  Created by Rare on 2022/2/22.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>

@class IPDSDKInitModel;

NS_ASSUME_NONNULL_BEGIN

@interface IPDSDKManager : NSObject

+ (instancetype)shared;

- (void)registerAppId:(NSString *)appId;

- (void)registerSDK:(IPDSDKInitModel *)initData;

@property (nonatomic, copy) void(^registrationCompleted)(BOOL completed, NSDictionary *info);

/// sdk初始化完成
@property (nonatomic, assign, readonly) BOOL sdkInitComplete;

@property (nonatomic, assign, readonly) BOOL registerAppIdEnd;

@property (nonatomic, copy, readonly) NSString *appId;

@property (nonatomic, assign) IPDAdSDKLogLevel level;

//是否可以获取ecpm
@property (nonatomic, assign) BOOL can_read_ecpm;

//是否永久断开配置更新
@property (nonatomic, assign) BOOL is_disconnect;

//是否跳过单个广告位配置请求，直接使用本地配置
@property (nonatomic, assign) BOOL is_skip_pos_conf_req;

- (void)registerPlatform:(NSString *)platform;


@end

NS_ASSUME_NONNULL_END
