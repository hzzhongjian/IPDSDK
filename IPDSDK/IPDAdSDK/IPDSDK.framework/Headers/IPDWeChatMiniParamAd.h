//
//  ZJWeChatMiniParamAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/19.
//  Copyright © 2025 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>
#import <IPDSDKCore/IPDMiniParamAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDWeChatMiniParamAd;

@protocol IPDWeChatMiniParamAdDelegate <NSObject>

@optional
/**
 *  小程序唤起成功
 */
- (void)ipd_wechatMiniParamAdDidAwake:(IPDWeChatMiniParamAd *)miniParamAd;


/**
 *  小程序唤起失败
 */
- (void)ipd_wechatMiniParamAdAwakeFail:(IPDWeChatMiniParamAd *)miniParamAd error:(NSError *)error;


@end


@interface IPDWeChatMiniParamAd : IPDTierAd

@property (nonatomic, weak) id <IPDWeChatMiniParamAdDelegate> delegate;

@property (nonatomic, strong,nullable) IPDMiniParamAdAdapter *currentAdapter;

@end

NS_ASSUME_NONNULL_END
