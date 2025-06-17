//
//  NSError+IPDAd.h
//  IPDSDKCore
//
//  Created by Rare on 2021/6/9.


#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDAdUnionItemModel.h>

NS_ASSUME_NONNULL_BEGIN

#define kIPDTANXErrorDomain @"COM.IPD.TANX.SDK"
#define kIPDGOOGLEErrorDomain @"COM.IPD.GOOGLE.SDK"
#define kIPDBAIDUErrorDomain @"COM.IPD.BAIDU.SDK"
#define kIPDCSJErrorDomain @"COM.IPD.CSJ.SDK"
#define kIPDPANGLEErrorDomain @"COM.IPD.PANGLE.SDK"
#define kIPDGDTErrorDomain @"COM.IPD.GDT.SDK"
#define kIPDKSErrorDomain @"COM.IPD.KS.SDK"
#define kIPDMTGErrorDomain @"COM.IPD.MTG.SDK"
#define kIPDSIGErrorDomain @"COM.IPD.SIG.SDK"
#define kIPDBEIZIErrorDomain @"COM.IPD.BEIZI.SDK"
#define kIPDDSPErrorDomain @"COM.IPD.DSP.SDK"
#define kIPDQMErrorDomain @"COM.IPD.QM.SDK"
#define kIPDOCTOPUSErrorDomain @"COM.IPD.OCTOPUS.SDK"
#define kIPDYKErrorDomain @"COM.IPD.YK.SDK"
#define kIPDQIYUNErrorDomain @"COM.IPD.QIYUN.SDK"
#define kIPDTAKUErrorDomain @"COM.IPD.TAKU.SDK"

typedef NS_ENUM(NSInteger, IPDErrorCodeAd)
{
    IPDErrorCodeAd_Unknown = 100100, // 未知错误
    IPDErrorCodeAd_Unregistered = 100101, // 未注册
    IPDErrorCodeAd_Timeout = 100200, // 请求超时
    IPDErrorCodeAd_LackLibraries = 100201, // 缺少依赖库
    IPDErrorCodeAd_AdId = 100202, // adid错误
    IPDErrorCodeAd_AllAdReturnError = 100203, // 广告返回错误
    IPDErrorCodeAd_is_being_limit = 100301, // 广告被限制
    IPDErrorCodeAd_WXLibrarieMissed = 100403, // 微信OpenSDK依赖缺失
    IPDErrorCodeAd_WXLibrarieRegistFail = 100404, // 微信注册失败
    IPDErrorCodeAd_WXNotResponseImp = 100405, // 微信未响应
    IPDErrorCodeAd_DisplayError = 100500, // 显示错误
    IPDErrorCodeAd_MissParameter = 100601, // 缺少参数
    IPDErrorCodeAd_AdInvalid = 100602, // 广告不合法
    IPDErrorCodeAd_app_tradeId_verify_fail = 100701,//媒体激励校验未通过
    IPDErrorCodeAd_POS_ID_RETURN_EMPTY_BY_SDK_FILTER_CODE = 100800,// 广告位匹配，但没有限制且填充为空,配置的平台没有匹配到
    IPDErrorCodeAd_CONFIG_ERROR = 1000009, // 配置数据错误
    IPDErrorCodeAd_Splash_RepeatedExposure_ERROR = 1000900, // 开屏广告重复曝光的错误
    IPDErrorCodeAd_RewardVideo_RepeatedExposure_ERROR = 1000901, // 激励视频广告重复曝光的错误
    IPDErrorCodeAd_SplashFullVideo_RepeatedExposure_ERROR = 1000902, // 开屏全屏视频广告重复曝光的错误
    IPDErrorCodeAd_Interstitial_RepeatedExposure_ERROR = 1000903, // 插屏广告重复曝光的错误
    IPDErrorCodeAd_FullScreenVideo_RepeatedExposure_ERROR = 1000904, // 全屏视频广告重复曝光的错误
    IPDErrorCodeAd_NativeExpress_RepeatedExposure_ERROR = 1000905, // 信息流广告重复曝光的错误
    IPDErrorCodeAd_Native_RepeatedExposure_ERROR = 1000906, // 自渲染广告重复曝光的错误
    
};


@interface NSError (IPDAd)


+ (NSError *)ipdAdError_errorWithCode:(IPDErrorCodeAd)code adItemConfig:(nullable IPDAdUnitModel *)adItemConfig userInfo:(nullable NSDictionary<NSString *, id> *)dict;

+ (NSError *)app_tradeId_verify_fail;

+ (NSError *)errorWithCode:(NSInteger)code message:(nullable NSString *)message;

- (NSDictionary *)convertDictionary;

- (NSString *)convertJSONString;

@end

NS_ASSUME_NONNULL_END
