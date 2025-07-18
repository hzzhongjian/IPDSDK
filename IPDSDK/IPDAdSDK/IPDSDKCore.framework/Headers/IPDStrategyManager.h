//
//  IPDStrategyManager.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/5/25.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDCacheManager.h>
#import <IPDSDKCore/IPDAdEventReport.h>
#import <IPDSDKCore/IPDAdUnionItemModel.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, IPDStrategy) {
    IPDStrategyNone,
    IPDStrategyLimitNum,
    ZIPDStrategy1,
    IPDStrategy2,
    IPDStrategy3,
};

///  策略管理类，不同错误处理策略，次数限制策略等
@interface IPDStrategyManager : NSObject

@property (nonatomic, copy) NSArray *recordEventTypes;

+ (instancetype)sharedManager;


/// 是否应该执行策略
/// @return 默认返回NO，继续请求，返回YES表示正在执行策略，应跳过请求。
/// @param unit 广告单元数据
- (BOOL)shouldExcutingStategyForUnit:(IPDAdUnitModel *)unit;

/// 判断此ID是否正在执行策略,启动后首次请求adid需要从磁盘中读取，会提前返回默认不执行，后续考虑读取放在主线程，其他操作异步。
/// @param adid 联盟广告位ID
/// @param errorStrategy 广告位ID对应的错误策略 （限制策略触发次数;触发有效时间间隔;限制策略限制分钟数;错误策略触发次数;触发有效时间间隔;错误策略限制分钟数）
//- (BOOL)isExcutingStategyForAdid:(NSString *)adid errorStrategy:(NSString *)errorStrategy;


/// 判断此ID是否正在执行限制次数策略,启动后首次请求adid需要从磁盘中读取，会提前返回默认不执行，后续考虑读取放在主线程，其他操作异步。
/// @param adid 联盟广告位ID
/// @param limitNum 当天限制展示的的次数
- (BOOL)isExcutingLimitNumForAdid:(NSString *)adid limitNum:(NSInteger)limitNum;

- (BOOL)isExcutingStartNumForAdid:(NSString *)adid startNum:(NSInteger)startNum;

///// 异步判断是否执行block，
///// @param adid adid
///// @param backBlock 回调是否执行策略
//- (void)blockExcutingStategyForAdid:(NSString *)adid backBlock:(BOOL (^)(void))backBlock;;


///// 获取当天完成次数
///// @param adid 联盟广告位ID
//- (NSInteger)finishNumForAdid:(NSString *)adid;

#pragma mark =============== 读取 ===============
- (NSDictionary *)loadCacheForAdid:(NSString *)adid;

/// 将磁盘到日期读取出来保存到缓存中，目的是判断是否同一日期时避免再从磁盘中去读取，保持线程同步，减少代码量。
/// @param completedBlock 返回读取结果block
- (void)readDateInfoFromDiskCompleted:(nullable IPDCacheCompletionBlock)completedBlock;


#pragma mark =============== 存储 ===============
/// 给对应type事件计数+1
/// @param type 事件type
/// @param adid 联盟广告位ID
- (void)increaseEvent:(IPDEventString)type forAdid:(NSString *)adid;


/// 给对应type事件计数+1
/// @param type 事件type
/// @param adid 联盟广告位ID
/// @param completedBlock 磁盘存储完成回调
- (void)increaseEvent:(IPDEventString)type forAdid:(NSString *)adid completed:(nullable IPDCacheCompletionBlock)completedBlock;

/// 给对应type事件计数-1
- (void)decreaseEvent:(IPDEventString)type forAdid:(NSString *)adid completed:(nullable IPDCacheCompletionBlock)completedBlock;

/// 清理掉对应事件记录
- (void)cleanEvent:(IPDEventString)type forAdid:(NSString *)adid completed:(nullable IPDCacheCompletionBlock)completedBlock;

/// 错误类型发生次数记录加一,errorDomain可靠时，使用此方法，通过errorDomain判断平台，耦合性低。
/// @param error 对应的错误
/// @param adid 联盟广告位ID
//-(void)increaseError:(NSError *)error forAdid:(NSString *)adid;

/// 错误类型发生次数记录加一,errorDomain不可靠时，使用此方法。
/// @param error 对应的错误
/// @param adid 联盟广告位ID
/// @param type 对应平台
- (void)increaseError:(NSError *)error forAdid:(NSString *)adid platformType:(IPDAdPlatformType)type;

/// 错误类型发生次数记录加一
/// @param error 对应的错误，通过errorDomain判断平台
/// @param adid 联盟广告位ID
/// @param type 对应平台
/// @param completedBlock 磁盘存储完成回调
- (void)increaseError:(NSError *)error forAdid:(NSString *)adid platformType:(IPDAdPlatformType)type completed:(nullable IPDCacheCompletionBlock)completedBlock;

#pragma mark =============== 清理 ===============
/// 每天首次调用cache类，会先清理过去的cache，返回是否应清理缓存
/// 提前调用readDateInfoFromDiskCompleted方法，把日期缓存到内存，complicatedBlock将会同步执行返回。如果没有提前缓存，首次调用将会返回NO
- (BOOL)shouldCleanCache;

/// 清理缓存
- (void)cleanAllCache;

/// 清理所有数据，并更新本地日期
/// @param completionBlock 磁盘存储完成回调
- (void)cleanAndUpdateDateOnCompletion:(nullable IPDCacheCompletionBlock)completionBlock;


- (void)cleanCacheForAdid:(NSString *)adid;

@end

NS_ASSUME_NONNULL_END
