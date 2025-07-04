//
//  IPDCoreAdAdapter.h
//  IPDSDKCore
//
//  Created by Robin on 2020/11/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <IPDSDKCore/IPDAdUnionItemModel.h>
#import <IPDSDKCore/IPDAdDebugLog.h>
#import <IPDSDKCore/IPDBiddingLossRelease.h>
#import <IPDSDKCore/IPDAdEventReport.h>
#import <IPDSDKCore/IPDSDKManager.h>
#import <IPDSDKCore/IPDBiddingReportModel.h>
#import <IPDSDKCore/IPDAdInfo.h>
#import <IPDSDKCore/IPDKSAdExposureReportParam.h>
#import <IPDSDKCore/IPDMediaBidResult.h>

NS_ASSUME_NONNULL_BEGIN


@interface IPDCoreAdAdapter : NSObject

@property(nonatomic, strong ,readonly) IPDAdUnitModel *config;
///结算价格
@property (nonatomic, strong) NSString *secondPrice;

@property (nonatomic, strong) NSString *cacheTime;

/// 记录加载广告成功的时间戳
@property (nonatomic, assign) NSTimeInterval hasAdTimeInterval;

/// 平台判断广告是否已过期（如有）,默认值yes，代表广告合法
- (BOOL)pmAdValid;

- (instancetype)initWithAdItemConfig:(IPDAdUnitModel *)adItemConfig;


+ (void)registerPlatform:(NSString*)platform adType:(NSString*)adType adapterClass:(NSString*) adapterClass;

//创建对象使用
+ (instancetype)createWithAdItemConfig:(IPDAdUnitModel *)adItemConfig;



+ (Class)getAdapterClass:(IPDAdUnitModel *)adItemConfig;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值
 */
- (NSInteger)eCPM;

/**
 返回广告的eCPM等级
 
 @return 成功返回一个包含数字的string，@""或nil表示无权限或后台异常
 */
- (NSString *)eCPMLevel;


/// 竞价成功后，将出价排名第二的价格回传
/// @param secondPrice 二价
- (void)biddingSuccess:(NSInteger )secondPrice;


/// 竞价上报，提供更多信息
/// @param model 上报内容model
- (void)biddingSuccessModel:(IPDBiddingReportModel *)model;

/// 竞价上报，提供更多信息
/// @param model 上报内容model
- (void)biddingLossModel:(IPDBiddingReportModel *)model;
/**
 *  竞败之后或未参竞调用
 *  @param price - 本次竞胜方出价（单位：分），必填
 *  @param reason - 广告竞败原因，必填
 *  @param adnID - 本次竞胜方渠道ID，选填；
 *         对于【adnID】字段回传支持3个枚举值，分别代表：
 *         1 - 输给优量汇其它广告，当优量汇目标价报价为本次竞价的最高报价时，可上报此值，仅对混合比价类型的开发者适用；
 *         2 - 输给第三方ADN，当其它ADN报价为本次竞价的最高报价时，可上报此值，您无需回传具体竞胜方渠道；
 *         3 - 输给自售广告主，当自售广告源报价为本次竞价的最高报价时，可上报此值，仅对有自售广告源的开发者使用；
 */
- (void)biddingLoss:(NSInteger)price reason:(IPDBiddingLossReason)reason winnerAdnID:(nullable NSString *)adnID;


+ (NSString*)getAdapterClass:(NSString *)platform adType:(NSString *)adType;


-(void)reportWithEvent:(IPDEventString)event supplementMsg:(nullable NSString *)supplementMsg;

// 广告来源
- (IPDAdInfo *)adInfo;

@end

NS_ASSUME_NONNULL_END
