//
//  IPDRewardVideoAdAdapter.h
//  IPDSDKCore
//
//  Created by Robin on 2021/1/14.
//


#import <IPDSDKCore/IPDTierAdAdapter.h>
#import <IPDSDKCore/IPDRewardVideoAdProtocol.h>
#import <IPDSDKCore/IPDRewardVideoAdAdapterDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDRewardVideoAdAdapter : IPDTierAdAdapter<IPDRewardVideoAdProtocol>

@property(nonatomic,strong,readonly)UIView *rewardAdapterView;

@property(nonatomic,weak) id<IPDRewardVideoAdAdapterDelegate> delegate;

- (instancetype)initWithAdItemConfig:(IPDAdUnitModel *)adItemConfig userId:(NSString *)userId;

- (void)ipd_rewardVideoAdDidLoad;

- (void)ipd_rewardVideoAdVideoDidLoad;

- (void)ipd_rewardVideoAdDidShow;

- (void)ipd_rewardVideoAdDidClose;

- (void)ipd_rewardVideoAdDidClicked;

- (void)ipd_rewardVideoAdDidRewardEffective;

- (void)ipd_rewardVideoAdDidPlayFinish;

- (void)ipd_rewardVideoAdDidFailWithError:(NSError *)error;

- (void)ipd_rewardVideoAdDisplayFailWithError:(NSError *)error;

- (void)ipd_rewardedVideoAdDidClickSkip;

@end

NS_ASSUME_NONNULL_END
