//
//  IPDSDKAdEnum.h
//  IPDSDKCore
//
//  Created by Rare on 2021/8/16.
//

#ifndef IPDSDKAdEnum_h
#define IPDSDKAdEnum_h



typedef NS_ENUM(NSUInteger, IPDMediaPlayerStatus) {
    IPDMediaPlayerStatusDefalt = 0,         // 初始状态
    IPDMediaPlayerStatusLoading = 1,         // 加载中
    IPDMediaPlayerStatusPlaying = 2,         // 开始播放
    IPDMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    IPDMediaPlayerStatusError = 4,           // 播放出错
    IPDMediaPlayerStatusStoped = 5,          // 播放停止
};


typedef NS_ENUM(NSInteger,IPDAdSDKLogLevel){
    IPDAdSDKLogLevelNone,
    IPDAdSDKLogLevelDebug,
    IPDAdSDKLogLevelWarning,
    IPDAdSDKLogLevelError,
};

typedef NS_ENUM(NSInteger, IPDAdPlatformType) {
    IPDAdPlatform_None,
    IPDAdPlatform_CSJ,
    IPDAdPlatform_GDT,
    IPDAdPlatform_MTG,
    IPDAdPlatform_KS,
    IPDAdPlatform_ZJ,
    IPDAdPlatform_YM,
    IPDAdPlatform_SIG,
    IPDAdPlatform_WW,
    IPDAdPlatform_Google,
    IPDAdPlatform_Baidu,
    IPDAdPlatform_Gromore,
    IPDAdPlatform_BeiZi,
    IPDAdPlatform_WM,
    IPDAdPlatform_Pangle,
    IPDAdPlatform_TANX,
    IPDAdPlatform_QM,
    IPDAdPlatform_OCTOPUS,
    IPDAdPlatform_YIKA,
    IPDAdPlatform_QIYUN,
    IPDAdPlatform_TaKu,
};

typedef NS_ENUM(NSInteger, IPDAdType){
    IPDAdType_Unknow                 = 0,
    IPDAdType_SPLASH                 = 1,
    IPDAdType_REWARD                 = 3,
    IPDAdType_H5                     = 4,
    IPDAdType_Banner                 = 5,//banner
    IPDAdType_Interstitial           = 6,//插屏
    IPDAdType_ExpressFullVideoFeed   = 7,//视频流 
    IPDAdType_ContentVideo           = 8,//视频内容 
    IPDAdType_Native                 = 9,//原生渲染 
    IPDAdType_NativeExpress          = 11,//信息流 
    IPDAdType_FullScreenVideo        = 12,//全屏视频
    IPDAdType_News                   = 21,//新闻资讯
    IPDAdType_WXMiniProgram          = 22
};

//穿山甲联盟建议加载图片大小的尺寸
typedef NS_ENUM(NSInteger, IPDProposalSize) {
    IPDProposalSize_Banner600_90,
    IPDProposalSize_Banner640_100,
    IPDProposalSize_Banner600_150,
    IPDProposalSize_Banner600_260,
    IPDProposalSize_Banner600_286,
    IPDProposalSize_Banner600_300,
    IPDProposalSize_Banner690_388,
    IPDProposalSize_Banner600_400,
    IPDProposalSize_Banner600_500,
    IPDProposalSize_Feed228_150,
    IPDProposalSize_Feed690_388,
    IPDProposalSize_Interstitial600_400,
    IPDProposalSize_Interstitial600_600,
    IPDProposalSize_Interstitial600_900,
    IPDProposalSize_DrawFullScreen
};

// 设置个性化推荐广告
typedef NS_ENUM(NSInteger, IPDSDKPersionalizedState) {
    IPDSDKPersionalizedState_OFF, // 关闭
    IPDSDKPersionalizedState_ON, // 开启
};

// 是否允许开启广告的程序化推荐
typedef NS_ENUM(NSInteger, IPDSDKProgrammaticRecommend) {
    IPDSDKProgrammaticRecommend_OFF,
    IPDSDKProgrammaticRecommend_ON,
};

// 自渲染广告点击跳转类型
typedef NS_ENUM(NSInteger, IPDSDKAdInteractionType) {
    IPDSDKAdInteractionType_Unknown,        //unknown type
    IPDSDKAdInteractionType_App,            //open downlaod page in app
    IPDSDKAdInteractionType_Web,            //open webpage in app
    IPDSDKAdInteractionType_DeepLink,       //open deeplink
    IPDSDKAdInteractionType_AppStore,       //open appstore
};

#endif /* IPDSDKAdEnum_h */
