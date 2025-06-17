//
//  IPDFloatingAdView.h
//  IPDSDK
//
//  Created by Rare on 2021/7/16.
//  Copyright © 2021 zj. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDFloatingAdView;

@protocol IPDFloatingAdViewDelegate <NSObject>

//广告加载完成
- (void)ipd_floatingAdViewDidLoad:(IPDFloatingAdView *)floatingAdView;

//广告加载错误
- (void)ipd_floatingAdViewError:(IPDFloatingAdView *)floatingAdView error:(NSError *)error;

//广告点击
- (void)ipd_floatingAdViewDidClick:(IPDFloatingAdView *)floatingAdView;

//广告关闭
- (void)ipd_floatingAdViewDidClose:(IPDFloatingAdView *)floatingAdView;

@end


@interface IPDFloatingAdView : UIView

- (instancetype)initWithPlacementId:(NSString *)placementId frame:(CGRect)frame;

@property (nonatomic, weak) id <IPDFloatingAdViewDelegate> delegate;
///placementId - 广告位 ID
@property (nonatomic, copy) NSString *placementId;
///广告是否能够移动 默认 YES
@property (nonatomic, assign) BOOL canMove;
///广告是否需要自动贴边展示 默认 YES
@property (nonatomic, assign) BOOL needMoveToSide;
///广告关闭按钮隐藏 默认 NO
@property (nonatomic, assign) BOOL hiddenCloseButton;
///用来弹出目标页的ViewController，一般为当前ViewController 默认当前widow的viewController
@property (nonatomic, weak) UIViewController *rootViewController;

///加载广告
- (void)loadAd;

@end


@interface IPDFloatingAdView (IPDH5PageCustom)

/**导航栏返回按钮 图片设置*/
@property (nonatomic, nullable, strong) UIImage *backImage;
/**导航栏返回按钮 文字描述设置*/
@property (nonatomic, nullable, copy) NSAttributedString *backText;

/**导航栏关闭按钮 图片设置*/
@property (nonatomic, nullable, strong) UIImage *closeImage;
/**导航栏关闭按钮 文字描述设置*/
@property (nonatomic, nullable, copy) NSAttributedString *closeText;

/**隐藏导航栏的关闭按钮 默认 :YES*/
@property (nonatomic, assign) BOOL hiddenH5CloseButton;

/**导航栏标题， 设置后不会读取网页的标题*/
@property (nonatomic, nullable, copy) NSString *navigationbarTitle;


@end



NS_ASSUME_NONNULL_END
