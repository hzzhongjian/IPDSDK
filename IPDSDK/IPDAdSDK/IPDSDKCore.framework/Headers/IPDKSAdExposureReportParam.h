//
//  IPDKSAdExposureReportParam.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2025/2/11.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>

NS_ASSUME_NONNULL_BEGIN

#define kIPD_KSADBiddingFailureExposureReport @"IPD_KSADBiddingFailureExposureReport"

typedef NS_ENUM(NSUInteger, IPDKSAdBiddingActionType) {
    IPDKSAdBiddingActionTypeNone         = 0,    // 未点击&未曝光
    IPDKSAdBiddingActionTypeSuccess      = 1,    // 点击&曝光
    IPDKSAdBiddingActionTypeUnkown       = 2,    // 未知
};

typedef NS_ENUM(NSUInteger, IPDKSAdExposureAdnType) {
    IPDKSAdExposureAdnTypeKuaishou         = 1,    // 输给快手联盟其他广告
    IPDKSAdExposureAdnTypeOther            = 2,    // 输给其他ADN
    IPDKSAdExposureAdnTypeSelfSale         = 3,    // 输给自售广告主
};

typedef NS_ENUM(NSUInteger, IPDKSAdExposureAdnMaterialType) {
    IPDKSAdExposureAdnMaterialTypeHorizontalImg         = 1,    // 横版图片
    IPDKSAdExposureAdnMaterialTypeVerticalImg           = 2,    // 竖版图片
    IPDKSAdExposureAdnMaterialTypeHorizontalVideo       = 3,    // 横版视频
    IPDKSAdExposureAdnMaterialTypeVerticalVideo         = 4,    // 竖版视频
    IPDKSAdExposureAdnMaterialTypeThreeImg              = 5,    // 三图
    IPDKSAdExposureAdnMaterialTypeStreamer              = 6,    // 横幅
    IPDKSAdExposureAdnMaterialTypeOther                 = 7,    // 其他
};

@interface IPDKSAdExposureReportParam : NSObject

// 胜出者的ecpm报价
@property (nonatomic, assign) NSUInteger winEcpm;
// 竞胜平台类型
@property (nonatomic, assign) IPDKSAdExposureAdnType adnType;
// 竞胜平台名称，adnType=KSAdExposureAdnTypeOther时可以设置
// CSJ/GDT/BD/Other
@property (nonatomic, copy) NSString *adnName;

// 竞胜方dsp的广告主名称
@property (nonatomic, copy) NSString *adUserName;
// 竞胜方广告物料类型
@property (nonatomic, assign) IPDKSAdExposureAdnMaterialType adnMaterialType;
// 竞胜方广告素材url
@property (nonatomic, copy) NSString *adnMaterialUrl;
// 竞胜方的广告主标题
@property (nonatomic, copy) NSString *adTitle;
// 竞胜方媒体侧的请求id
@property (nonatomic, copy) NSString *adRequestId;
// 竞胜方dsp本次请求是否展示
@property (nonatomic, assign) IPDKSAdBiddingActionType isShow;
// 竞胜方dsp本次pv是否被点击
@property (nonatomic, assign) IPDKSAdBiddingActionType isClick;

// 广告类型
@property (nonatomic, assign) NSString *adType;

- (instancetype)initWithWinEcpm:(NSUInteger)winEcpm
                        adnType:(IPDKSAdExposureAdnType)adnType
                        adnName:(NSString *)adnName
                     adUserName:(NSString *)adUserName
                adnMaterialType:(IPDKSAdExposureAdnMaterialType)adnMaterialType
                 adnMaterialUrl:(NSString *)adnMaterialUrl
                        adTitle:(NSString *)adTitle
                    adRequestId:(NSString *)adRequestId
                         isShow:(IPDKSAdBiddingActionType)isShow
                        isClick:(IPDKSAdBiddingActionType)isClick
                         adType:(NSString *)adType;

@end

NS_ASSUME_NONNULL_END
