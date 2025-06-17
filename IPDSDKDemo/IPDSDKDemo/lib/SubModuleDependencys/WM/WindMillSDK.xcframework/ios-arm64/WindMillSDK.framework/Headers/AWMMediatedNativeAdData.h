//
//  AWMCustomNativeAd.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/20.
//

typedef NS_ENUM(NSInteger, AWMMediatedNativeAdMode) {
    AWMMediatedNativeAdModeSmallImage = 2,      // 水平小图样式
    AWMMediatedNativeAdModeLargeImage = 3,      // 水平大图样式
    AWMMediatedNativeAdModeGroupImage = 4,      // 水平组图样式
    AWMMediatedNativeAdModeNativeExpress = 5,   // 模版广告
    AWMMediatedNativeAdModeVideo = 14,          // 视频样式
    AWMMediatedNativeAdModeVideoPortrait = 15,  // 垂直视频样式
    AWMMediatedNativeAdModeVideoLandSpace = 16, // 水平视频样式
};

typedef NS_ENUM(NSInteger, AWMNativeAdSlotAdType) {
    AWMNativeAdSlotAdTypeFeed          = 1,       // feed ads
    AWMNativeAdSlotAdTypeDrawVideo     = 2,       // vertical (immersive) video ads
};


@protocol AWMMediatedNativeAdData <NSObject>

/// 广告标题
@property (nonatomic, copy) NSString *title;

/// 广告详情描述
@property (nonatomic, copy) NSString *desc;

/// app类型广告的广告商app图标，
@property (nonatomic, copy) NSString *iconUrl;

/// 按钮文案，例如'下载/安装'
@property (nonatomic, copy) NSString *callToAction;

/// app评分，区间为0-5
@property (nonatomic, assign) double rating;

/// 图片/视频模式
@property (nonatomic, assign) AWMMediatedNativeAdMode adMode;

/// 广告类型（feed/draw）
@property (nonatomic, assign) AWMNativeAdSlotAdType adType;


@end
