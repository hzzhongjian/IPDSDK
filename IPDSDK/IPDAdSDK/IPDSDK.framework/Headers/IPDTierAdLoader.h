//
//  IPDTierAdLoader.h
//  IPDSDK
//
//  Created by 麻明康 on 2023/2/23.
//  Copyright © 2023 zj. All rights reserved.
//

#import <IPDSDKCore/IPDSDKCore.h>
#import <IPDSDKCore/IPDTierAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDTierProtocol <NSObject>

@required
- (IPDTierAdAdapter *)createTierAdapterForUnit:(IPDAdUnitModel *)unit;

- (void)setCacheAdapter:(IPDTierAdAdapter *)cacheAdapter;

@end

@interface IPDTierAdLoader : NSObject <IPDTierProtocol>

typedef void(^RequestLevelCompleteBlk)( NSMutableArray <IPDTierAdAdapter *>* _Nullable successAdapters, NSMutableArray <NSError *>*_Nullable tierFailArray);

@property (nonatomic,strong)dispatch_semaphore_t semaphore;

@property (nonatomic, strong) dispatch_queue_t semaphoreQueue;

@property (nonatomic, nullable, copy) RequestLevelCompleteBlk completeBlk;

@property (nonatomic, strong) NSArray <IPDAdUnitModel *>* currentTiers;
//广告请求对象数组
@property (nonatomic,readonly)NSMutableArray <IPDTierAdAdapter *>*adapterArray;

//广告请求成功数组
@property (nonatomic,strong)NSMutableArray <IPDTierAdAdapter *>*successAdapters;

//错误信息数组
@property (nonatomic,strong)NSMutableArray <NSError *>*tierFailArray;

//倒计时器
@property (nonatomic,strong)IPDAdCountdown *countdown;

@property (nonatomic, assign) long timeout;



- (instancetype)initWithTiers:(NSArray <IPDAdUnitModel *>*)tiers
                     timeoutInterval:(CGFloat)timeoutInterval
                        showPriority:(IPDAdShowPriority)showPriority;

- (void)startLoad;

/// 联盟适配器素材加载成功
- (void)unitAdapterDidLoad:(IPDTierAdAdapter *)adapter;
/// 联盟适配器素材加载失败
- (void)unitAdapterLoadFail:(IPDTierAdAdapter *)adapter error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
