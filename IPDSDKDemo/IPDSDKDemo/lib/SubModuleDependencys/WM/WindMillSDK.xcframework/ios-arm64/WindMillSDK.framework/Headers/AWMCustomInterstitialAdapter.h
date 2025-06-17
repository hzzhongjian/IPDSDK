//
//  AWMCustomInterstitialAdapter.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/17.
//
#import <UIKit/UIKit.h>

@protocol AWMCustomAdapter;
@protocol AWMCustomInterstitialAdapterBridge;
@class AWMParameter;

@protocol AWMCustomInterstitialAdapter <AWMCustomAdapter>
/// 构造方法
/// 通过bridge回传广告状态
- (instancetype)initWithBridge:(id<AWMCustomInterstitialAdapterBridge>)bridge;

/// 当前加载的广告的状态
- (BOOL)mediatedAdStatus;

/// 加载广告的方法
/// @param placementId adn的广告位ID
/// @param parameter 广告加载的参数
- (void)loadAdWithPlacementId:(NSString *)placementId parameter:(AWMParameter *)parameter;

/// 展示广告的方法
/// @param viewController 控制器对象
/// @param parameter 展示广告的参数，由ToBid接入媒体配置
- (BOOL)showAdFromRootViewController:(UIViewController *)viewController parameter:(AWMParameter *)parameter;

@end
