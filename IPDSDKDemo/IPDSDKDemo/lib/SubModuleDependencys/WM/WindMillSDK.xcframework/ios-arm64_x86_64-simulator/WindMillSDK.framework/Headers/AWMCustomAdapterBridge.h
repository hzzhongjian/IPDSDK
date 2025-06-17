//
//  AWMCustomAdapterBridge.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/13.
//

@class WindMillAdRequest;

@protocol AWMCustomAdapterBridge <NSObject>

@required

/// 广告加载时构建的request对象
- (WindMillAdRequest *)adRequest;

@end
