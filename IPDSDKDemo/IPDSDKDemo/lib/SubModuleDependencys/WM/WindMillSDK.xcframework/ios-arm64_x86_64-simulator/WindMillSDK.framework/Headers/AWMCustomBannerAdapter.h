//
//  AWMCustomBannerAdapter.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/17.
//
#import <Foundation/Foundation.h>

@protocol AWMCustomAdapter;
@protocol AWMCustomBannerAdapterBridge;

@protocol AWMCustomBannerAdapter <AWMCustomAdapter>

/// 构造方法
/// 通过bridge回传广告状态
- (instancetype)initWithBridge:(id<AWMCustomBannerAdapterBridge>)bridge;

/// 当前加载的广告的状态
- (BOOL)mediatedAdStatus;

/// 加载广告的方法
/// @param placementId adn的广告位ID
/// @param parameter 广告加载的参数
- (void)loadAdWithPlacementId:(NSString *)placementId parameter:(AWMParameter *)parameter;
@end
