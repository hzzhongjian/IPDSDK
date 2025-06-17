//
//  IPDAdExposureReportParam.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2025/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, IPDAdExposureFailureCode) {
    IPDAdExposureFailureOther                   = 0,    // 其他
    IPDAdExposureFailureMediaBasePriceFilter    = 1,    // 媒体侧底价过滤
    IPDAdExposureFailureBidFailed               = 2,    // 广告竞价失败
    IPDAdExposureFailureCacheInvalid            = 3,    // 缓存失效
    IPDAdExposureFailureExposurePriorityReduce  = 4,    // 曝光优先级降低
    IPDAdExposureFailureExposureReturnTimeout   = 5,    // 返回超时
    IPDAdExposureFailureExposureMediaBlocking   = 6,    // 媒体屏蔽
};


typedef NS_ENUM(NSUInteger, IPDAdExposureAdnType) {
    IPDAdExposureAdnTypeKuaishou         = 1,    // 输给快手联盟其他广告
    IPDAdExposureAdnTypeOther            = 2,    // 输给其他ADN
    IPDAdExposureAdnTypeSelfSale         = 3,    // 输给自售广告主
};

typedef NS_ENUM(NSUInteger, IPDAdExposureAdnMaterialType) {
    IPDAdExposureAdnMaterialTypeHorizontalImg         = 1,    // 横版图片
    IPDAdExposureAdnMaterialTypeVerticalImg           = 2,    // 竖版图片
    IPDAdExposureAdnMaterialTypeHorizontalVideo       = 3,    // 横版视频
    IPDAdExposureAdnMaterialTypeVerticalVideo         = 4,    // 竖版视频
    IPDAdExposureAdnMaterialTypeThreeImg              = 5,    // 三图
    IPDAdExposureAdnMaterialTypeStreamer              = 6,    // 横幅
    IPDAdExposureAdnMaterialTypeOther                 = 7,    // 其他
};

typedef NS_ENUM(NSUInteger, IPDAdBiddingActionType) {
    IPDAdBiddingActionTypeNone         = 0,    // 未点击&未曝光
    IPDAdBiddingActionTypeSuccess      = 1,    // 点击&曝光
    IPDAdBiddingActionTypeUnkown       = 2,    // 未知
};

typedef NSString* IPDAdADNName;
//平台定义
extern IPDAdADNName const IPDAdADNNameChuanshanjia; // 穿山甲
extern IPDAdADNName const IPDAdADNNameGuangdiantong; // 优量汇
extern IPDAdADNName const IPDAdADNNameBaidu; // 百度
extern IPDAdADNName const IPDAdADNNameKS; // 快手
extern IPDAdADNName const IPDAdADNNameSIGMOB; // sigmob
extern IPDAdADNName const IPDAdADNNameOCTOPUS; // 章鱼
extern IPDAdADNName const IPDAdADNNameQuMeng; // 趣盟
extern IPDAdADNName const IPDAdADNNameBeiZi; // 倍孜
extern IPDAdADNName const IPDAdADNNameOther; // 其他

@interface IPDAdExposureReportParam : NSObject

// 胜出者的ecpm报价
@property (nonatomic, assign) NSUInteger winEcpm;
// 竞胜平台类型
@property (nonatomic, assign) IPDAdExposureAdnType adnType;
// 竞胜平台名称，adnType=KSAdExposureAdnTypeOther时可以设置
@property (nonatomic, copy) IPDAdADNName adnName;

// 竞胜方dsp的广告主名称
@property (nonatomic, copy) NSString *adUserName;
// 竞胜方广告物料类型
@property (nonatomic, assign) IPDAdExposureAdnMaterialType adnMaterialType;
// 竞胜方广告素材url
@property (nonatomic, copy) NSString *adnMaterialUrl;
// 竞胜方的广告主标题
@property (nonatomic, copy) NSString *adTitle;
// 竞胜方dsp本次请求是否展示
@property (nonatomic, assign) IPDAdBiddingActionType isShow;
// 竞胜方dsp本次pv是否被点击
@property (nonatomic, assign) IPDAdBiddingActionType isClick;

@end

NS_ASSUME_NONNULL_END
