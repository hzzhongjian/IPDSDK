//
//  AWMMediatedNativeAdViewCreator.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/20.
//

/// 媒体Native广告视图构造协议
/// adapter开发者可不配置数据内容，外部开发者在接入时需手动填充AWMMediatedNativeAdData中数据
@protocol AWMMediatedNativeAdViewCreator <NSObject>

/// 视频视图
@property (nonatomic, strong, readonly) UIView *mediaView;

/// 广告图标视图
@property (nonatomic, strong, readonly) UIView *adLogoView;

/// 不喜欢广告按钮
@property (nonatomic, strong, readonly) UIButton *dislikeBtn;

/// 广告图片视图
@property (nonatomic, strong, readonly) UIImageView *imageView;

/// 广告图片组合视图
@property (nonatomic, strong, readonly) NSArray<UIImageView *> * imageViewArray;

@required
/// 绑定数据
- (void)refreshData;
/// 设置根视图 （不设置可能造成点击无反应）
- (void)setRootViewController:(UIViewController *)viewController;
/// 在原生广告视图中注册可点击视图。
- (void)registerContainer:(UIView *)containerView
       withClickableViews:(NSArray<UIView *> *)clickableViews;
/// 设置图片的占位图
- (void)setPlaceholderImage:(UIImage *)placeholderImage;

@end
