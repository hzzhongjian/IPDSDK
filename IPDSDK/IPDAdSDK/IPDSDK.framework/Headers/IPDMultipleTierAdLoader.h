//
//  IPDMultipleTierAdLoader.h
//  IPDSDK
//
//  Created by 麻明康 on 2023/2/23.
//  Copyright © 2023 zj. All rights reserved.
//

#import <IPDSDKCore/IPDSDKCore.h>
#import <IPDSDKCore/IPDMultipleAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDMultipleTierProtocol <NSObject>

@required

- (IPDMultipleAdAdapter *)createTierAdapterForUnit:(IPDAdUnitModel *)unit;

- (void)setCacheAdapter:(IPDMultipleAdAdapter *)cacheAdapter;

@optional
- (NSInteger)getCountDownInterval;

@end

@interface IPDMultipleTierAdLoader : NSObject <IPDMultipleTierProtocol>

typedef void(^MultipleRequestLevelCompleteBlk)( NSMutableArray <IPDMultipleAdAdapter *>* _Nullable successAdapters, NSMutableArray <NSError *>*_Nullable tierFailArray);

@property (nonatomic, strong) dispatch_semaphore_t semaphore;

@property (nonatomic, strong) dispatch_queue_t semaphoreQueue;

@property (nonatomic, assign) CGFloat timeoutInterval;

@property (nonatomic, assign) IPDAdShowPriority showPriority;

@property (nonatomic, nullable, copy) MultipleRequestLevelCompleteBlk completeBlk;

@property (nonatomic, strong) NSArray <IPDAdUnitModel *>* currentTiers;
//广告请求对象数组
@property (nonatomic, readonly) NSMutableArray <IPDMultipleAdAdapter *>*adapterArray;

//广告请求成功数组
@property (nonatomic, strong) NSMutableArray <IPDMultipleAdAdapter *>*successAdapters;

//错误信息数组
@property (nonatomic, strong) NSMutableArray <NSError *>*tierFailArray;

//倒计时器
@property (nonatomic, strong) IPDAdCountdown *countdown;

@property (nonatomic, assign) long timeout;

// required. Image size.
// 穿山甲联盟要求传加载图片尺寸
@property (nonatomic, assign) IPDProposalSize imgSize;


- (instancetype)initWithTiers:(NSArray <IPDAdUnitModel *>*)tiers
                     timeoutInterval:(CGFloat)timeoutInterval
                        showPriority:(IPDAdShowPriority)showPriority;

- (void)startLoadWithCount:(NSUInteger)count;

/// 联盟适配器加载成功，回调数据
- (void)unitAdapterDidLoad:(IPDMultipleAdAdapter *)adapter resultArray:(NSArray *)resultArray;

/// 联盟适配器加载失败
- (void)unitAdapterLoadFail:(IPDMultipleAdAdapter *)adapter error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
