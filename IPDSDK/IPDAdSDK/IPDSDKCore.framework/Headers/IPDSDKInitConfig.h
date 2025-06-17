//
//  IPDSDKInitConfig.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2024/9/10.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>
#import <IPDSDKCore/IPDSDKInitModel.h>
#import <IPDSDKCore/IPDSDKPrivacyAuthorityModel.h>
#import <IPDSDKCore/IPDSDKPrivacyProvider.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDSDKInitConfig : NSObject


+ (instancetype)sharedInstance;

@property (nonatomic, strong) IPDSDKInitModel *sdkInitModel;

// 个性化推荐
@property (nonatomic, assign) IPDSDKPersionalizedState persionalizedState;

// 程序化推荐开关
@property (nonatomic, assign) IPDSDKProgrammaticRecommend programmaticRecommend;

/**
 * 用户控制聚合SDK隐私权限
 */
@property (nonatomic, strong) IPDSDKPrivacyAuthorityModel *privacyAuthorityModel;

/**
 * 用户控制IPDSDK隐私权限
 */
@property (nonatomic, strong, nullable) id <IPDSDKPrivacyProvider> privacyProvider;

@end

NS_ASSUME_NONNULL_END
