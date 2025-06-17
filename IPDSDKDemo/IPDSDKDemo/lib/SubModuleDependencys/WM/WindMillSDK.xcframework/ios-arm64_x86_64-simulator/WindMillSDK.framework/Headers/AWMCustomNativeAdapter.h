//
//  AWMCustomNativeAdapter.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/20.
//

#import <Foundation/Foundation.h>

@class AWMParameter;
@protocol AWMCustomAdapter;
@protocol AWMCustomNativeAdapterBridge;

@protocol AWMCustomNativeAdapter <AWMCustomAdapter>

/// 构造方法
/// 通过bridge回传广告状态
- (instancetype)initWithBridge:(id<AWMCustomNativeAdapterBridge>)bridge;

/// 加载广告的方法
/// @param placementId adn的广告位ID
/// @param parameter 广告加载的参数
- (void)loadAdWithPlacementId:(NSString *)placementId
                       adSize:(CGSize)size
                    parameter:(AWMParameter *)parameter;

@end
