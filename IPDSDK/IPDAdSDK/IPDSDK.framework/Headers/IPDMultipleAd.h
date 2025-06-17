//
//  IPDMultipleAd.h
//  IPDSDK
//
//  Created by 麻明康 on 2022/11/11.
//  Copyright © 2022 zj. All rights reserved.
//

#import <IPDSDK/IPDAd.h>
#import <IPDSDK/IPDTierAd.h>
#import <IPDSDKCore/IPDMultipleAdAdapter.h>
#import <IPDSDKCore/IPDAdCountdown.h>
#import <IPDSDKCore/IPDAdPreferenceManager.h>
#import <IPDSDKCore/IPDStrategyManager.h>
#import <IPDSDK/IPDMultipleTierAdLoader.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDMultipleProtocol <NSObject>

@required
- (void)dealSuccessResult;

- (void)dealFailResultWithError:(NSError*)error;

- (IPDMultipleTierAdLoader *)createTierLoader:(NSArray <IPDAdUnitModel *>*)tiers showPriority:(IPDAdShowPriority)showPriority;

@optional

- (NSInteger)getCountDownInterval;


@end



@interface IPDMultipleAd : IPDAd<IPDMultipleProtocol>{
    BOOL _needDelayLoadAd;
    BOOL _takeFastReturnAd;
    NSInteger eCPM1;
    NSInteger eCPM2;
}

//倒计时器
//@property (nonatomic,strong)IPDAdCountdown *countdown;
//数据管理
@property (nonatomic,strong)IPDAdPreferenceManager *adManager;

//错误信息数组
@property (nonatomic,strong)NSMutableArray <NSError *>*adFailArray;

@property (nonatomic,strong)NSMutableString *logString;



//pd广告请求成功数组
@property (nonatomic,strong)NSMutableArray <IPDMultipleAdAdapter *>*successAdaptersPD;

//bd广告请求成功数组
@property (nonatomic,strong)NSMutableArray <IPDMultipleAdAdapter *>*successAdaptersBD;


@property (nonatomic,strong)IPDMultipleAdAdapter *ecpm1Adapter;

@property (nonatomic,strong,nullable)IPDMultipleAdAdapter *currentAdapter;

- (void)loadAdWithCount:(NSUInteger)count;

@end

NS_ASSUME_NONNULL_END
