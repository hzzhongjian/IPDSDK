//
//  AWMCustomConfigAdapter.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/10.
//

#import "AWMSdkInitConfig.h"
#import "AWMCustomAdapterVersion.h"

@protocol AWMCustomConfigAdapterBridge;

/// 自定义adapter的基本配置协议
@protocol AWMCustomConfigAdapter <NSObject>

@required

/// 构造函数，通过bridge通知初始化成功和失败
/// @param bridge 代理。用于通知初始化成功或初始化失败
- (instancetype)initWithBridge:(id<AWMCustomConfigAdapterBridge>)bridge;

/// 该自定义adapter是基于哪个版本实现的，填写编写时的最新值即可，ToBid会根据该值进行兼容处理
- (AWMCustomAdapterVersion *)basedOnCustomAdapterVersion;

/// adn初始化方法
/// @param initConfig 初始化配置，包括appid、appkey基本信息和用户自定义参数等
- (void)initializeAdapterWithConfiguration:(AWMSdkInitConfig *)initConfig;

/// Adapter的版本号 (用于ToBid获取Adapter的版本号)
- (NSString *)adapterVersion;

/// adn的版本号 (用于ToBid获取adn的版本号)
- (NSString *)networkSdkVersion;

/// 隐私权限更新，用户更新隐私配置时触发，初始化方法调用前一定会触发一次
/// @config initConfig 隐私合规配置，字段详见AWMPrivacyConfig.h文件
- (void)didRequestAdPrivacyConfigUpdate:(NSDictionary *)config;

@end
