//
//  IPDH5AdDelegate.h
//  IPDSDK
//
//  Created by Robin on 2020/10/28.
//  Copyright © 2020 zj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDUser;

@protocol IPDH5PageDelegate <NSObject>

@optional

//H5Ad加载完成
- (void)onIPDH5PageLoaded:(IPDUser *)user error:(nullable NSError *) error;

//H5Ad错误
- (void)onIPDH5PageError:(IPDUser *)user error:(NSError *) error;

//H5Ad关闭
- (void)onIPDH5PageWillClose:(IPDUser *)user;

//H5操作回调
//积分不足
- (void)onIPDIntegralNotEnough:(IPDUser *)user needIntegral:(NSInteger)integral;
//积分消耗
- (void)onIPDIntegralExpend:(IPDUser *)user expendIntegral:(NSInteger)integral;
//积分奖励
- (void)onIPDIntegralReward:(IPDUser *)user rewardIntegral:(NSInteger)integral;

//奖励发放,奖励积分
- (void)onIPDH5PageAdRewardProvide:(IPDUser *)user rewardIntegral:(NSInteger)integral;

//用户页面的行为操作
- (void)onIPDH5PageUserBehavior:(IPDUser *)user behavior:(NSString *)behavior;


//广告回调
//广告激励视频加载成功
- (void)onIPDH5PageAdRewardLoaded:(IPDUser *)user trans_id:(NSString *)trans_id;

//广告激励视频触发激励（观看视频大于一定时长或者视频播放完毕）
- (void)onIPDH5PageAdRewardValid:(IPDUser *)user trans_id:(NSString *)trans_id;

//广告点击
- (void)onIPDH5PageAdRewardClick:(IPDUser *)user;

//广告加载错误
- (void)onIPDH5PageAdReward:(IPDUser*) user didFailWithError:(NSError *)error;


@end


NS_ASSUME_NONNULL_END
