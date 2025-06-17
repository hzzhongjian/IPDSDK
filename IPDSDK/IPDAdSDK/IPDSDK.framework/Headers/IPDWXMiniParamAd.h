//
//  ZJWXMiniParamAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2022/9/20.
//  Copyright © 2022 zj. All rights reserved.
//

#import <IPDSDK/IPDAd.h>
#import <IPDSDKCore/IPDMiniParamAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDWXMiniParamAd;

@protocol IPDWXMiniParamAdDelegate <NSObject>
@optional
/**
 *  小程序唤起成功
 */
- (void)ipd_miniParamAdDidAwake:(IPDWXMiniParamAd *)miniParamAd;


/**
 *  小程序唤起失败
 */
- (void)ipd_miniParamAdAwakeFail:(IPDWXMiniParamAd *)miniParamAd error:(NSError *)error;

- (void)ipd_miniParamAd:(IPDWXMiniParamAd *)miniParamAd onResp:(id)resp;
@end


@interface IPDWXMiniParamAd : IPDAd <IPDMiniParamAdProtocol>

@property (nonatomic, weak) id <IPDWXMiniParamAdDelegate> delegate;


/// 请先导入微信SDK以唤起微信小程序。由于友盟与微信模块之间的冲突，本SDK默认不帮开发者导入微信依赖库，请开发者根据自身业务集成
/// 原本app内两者都未集成，建议集成微信pod 'WechatOpenSDK'，并导入微信小程序广告模块:pod 'ZJSDK/ZJADWXMiniProgramAdapter'
/// 微信文档：https://developers.weixin.qq.com/doc/oplatform/Mobile_App/Access_Guide/iOS.html
/// 友盟文档：https://developer.umeng.com/docs/128606/cate/128606
-(void)wakeUpMiniParam;
@end

NS_ASSUME_NONNULL_END
