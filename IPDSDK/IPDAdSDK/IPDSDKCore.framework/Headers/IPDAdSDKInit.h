//
//  IPDAdSDKInit.h
//  IPDSDKCore
//
//  Created by Robin on 2021/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDAdSDKInit : NSObject

+ (void)registerPlatform:(NSString *)platform sdkInitClass:(NSString *)sdkInitClass;

+ (instancetype)creatSdkInit:(NSString *)platform;

- (BOOL)registerSDK:(nullable NSDictionary *)config;

+ (NSDictionary *)sdkVersionDict;

+ (void)registerSDKVersionWithPlatform:(NSString *)platform sdkVersion:(NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
