//
//  AWMCustomConfigAdapterBridge.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/10.
//

@protocol AWMCustomConfigAdapter;

@protocol AWMCustomConfigAdapterBridge <NSObject>

/// adn初始化成功
/// @param adapter 初始化配置类
- (void)initializeAdapterSuccess:(id<AWMCustomConfigAdapter>)adapter;

/// adn初始化失败
/// @param adapter 初始化配置类
/// @param error 初始化错误信息
- (void)initializeAdapterFailed:(id<AWMCustomConfigAdapter>)adapter error:(NSError *)error;

@end
