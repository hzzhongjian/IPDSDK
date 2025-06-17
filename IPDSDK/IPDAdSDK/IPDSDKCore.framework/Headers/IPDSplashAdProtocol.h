//
//  IPDSplashAdProtocol.h
//  IPDSDKCore
//
//  Created by Robin on 2020/12/22.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,IPDSplashHotspotType){
    IPDSplashHotspotType_FullScreen = 0,//全屏区域
    IPDSplashHotspotType_TriggerButton = 1  //按钮区域
};

@protocol IPDSplashAdProtocol <NSObject>

/**
 *  拉取广告超时时间，默认为3秒
 *详解：拉取广告超时时间，开发者调用loadAd方法以后，然后在该超时时间内，如果广告拉取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) CGFloat fetchDelay;

/**
 *  开屏自定义底部视图
 */
@property (nonatomic, strong) UIView *customBottomView;

/**
 *  开屏广告的可点击区域    默认：IPDSplashHotspotType_FullScreen
 */
@property (nonatomic, assign) IPDSplashHotspotType hotspotType;


/// 用于处理广告动作的视图控制器
@property (nonatomic, weak) UIViewController *_Nullable rootViewController;

/**
*  发起拉取广告请求，只拉取不展示
 详解：广告素材及广告图片拉取成功后会回调splashAdDidLoad方法
*/
- (void)loadAd;

/**
 *  展示广告，
  详解：广告展示成功时会回调IPD_splashAdSuccessPresentScreen方法
 */
- (void)showAdInWindow:(UIWindow *)window;


#pragma mark - DEPRECATED

/**
 *  开屏广告的底部预留尺寸
 *  可以设置开屏图片自定义bottomvVew的预留尺寸
 */
@property (nonatomic, assign) CGSize bottomViewSize DEPRECATED_MSG_ATTRIBUTE("use customBottomView instead.");
/**
 *  展示广告，
  详解：广告展示成功时会回调splashAdSuccessPresentScreen方法
 */
- (void)showAdInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView DEPRECATED_MSG_ATTRIBUTE("use showAdInWindow: instead.");

@end

NS_ASSUME_NONNULL_END
