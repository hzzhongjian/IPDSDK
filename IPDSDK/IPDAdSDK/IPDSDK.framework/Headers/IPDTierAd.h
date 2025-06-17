//
//  IPDTierAd.h
//  IPDSDK
//
//  Created by 麻明康 on 2022/11/11.
//  Copyright © 2022 zj. All rights reserved.
//

#import <IPDSDK/IPDAd.h>
#import <IPDSDKCore/IPDTierAdAdapter.h>
#import <IPDSDKCore/IPDAdCountdown.h>
#import <IPDSDKCore/IPDAdPreferenceManager.h>
#import <IPDSDKCore/IPDStrategyManager.h>
#import <IPDSDK/IPDTierAdLoader.h>


NS_ASSUME_NONNULL_BEGIN

@protocol IPDBiddingProtocol <NSObject>

@required
/// 广告数据和联盟素材加载处理成功，但是没有加载
- (void)dealSuccessResult;

/// 广告数据和联盟素材加载失败
- (void)dealFailResultWithError:(NSError *)error;

/// 创建Tier的加载器，处理ad适配器
- (IPDTierAdLoader *)createTierLoader:(NSArray <IPDAdUnitModel *> *)tiers showPriority:(IPDAdShowPriority)showPriority;

@optional
- (NSInteger)getCountDownInterval;

@end


//IPDTierAd为刚开始重构时思路不清晰，命名有误，特此标注。应理解为IPDSingleAd，与IPDMultipleAd对应
@interface IPDTierAd : IPDAd <IPDBiddingProtocol> {
    BOOL _needDelayLoadAd;
    BOOL _takeFastReturnAd;
    NSInteger eCPM1;
    NSInteger eCPM2;
}

@property (nonatomic, assign) BOOL hasLoadResult;

//倒计时器
//@property (nonatomic,strong)IPDAdCountdown *countdown;
//数据管理
@property (nonatomic, strong) IPDAdPreferenceManager *adManager;

//错误信息数组
@property (nonatomic, strong) NSMutableArray <NSError *>*adFailArray;

@property (nonatomic, strong) NSMutableString *logString;

//pd广告请求成功数组
@property (nonatomic, strong) NSMutableArray <IPDTierAdAdapter *> *successAdaptersPD;

//bd广告请求成功数组
@property (nonatomic, strong) NSMutableArray <IPDTierAdAdapter *> *successAdaptersBD;


@property (nonatomic, strong) IPDTierAdAdapter *ecpm1Adapter;

@property (nonatomic, strong, nullable)IPDTierAdAdapter *currentAdapter;

- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
