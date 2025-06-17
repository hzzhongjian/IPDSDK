//
//  AWMCustomAdapterVersion.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/10.
//

#import <Foundation/Foundation.h>

@class AWMCustomAdapterVersion;

/// 自定义adapter协议版本，版本号 1.0
extern AWMCustomAdapterVersion * const AWMCustomAdapterVersion1_0;

/// 自定义adapter使用的协议版本，请开发者实现/更新自定义adapter时使用最新版本的版本号即可
/// ToBid会根据实际情况控制adapter是否可用，[及时更新]
@interface AWMCustomAdapterVersion : NSString

@end
