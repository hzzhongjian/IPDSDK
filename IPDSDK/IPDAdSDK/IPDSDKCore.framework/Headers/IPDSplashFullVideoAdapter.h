//
//  IPDSplashFullVideoAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/8/1.
//

#import <IPDSDKCore/IPDSplashAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDSplashFullVideoAdapter : IPDSplashAdAdapter

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

- (void)showAdInWindow:(UIWindow *)window;
/**
 *  展示广告，调用此方法前需调用isAdValid方法判断广告素材是否有效
 */
- (void)showAdInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

- (void)presentAdFromRootViewController:(UIViewController*)viewController;

- (void)ipd_fullScreenVideoDidLoad;

- (void)ipd_fullScreenVideoDidLoadFail:(NSError * __nullable)error;

- (void)ipd_fullScreenVideoDidPresentScreen;

- (void)ipd_fullScreenVideoDidClick;

- (void)ipd_fullScreenVideoDidClose;

- (void)ipd_fullScreenVideoDetailDidClose;

- (void)ipd_fullScreenVideoDidFail:(NSError * __nullable)error;

- (void)ipd_fullScreenVideoPlayerStatus:(IPDMediaPlayerStatus)status;

- (void)ipd_fullScreenVideoDetailDidPresent;

@end

NS_ASSUME_NONNULL_END
