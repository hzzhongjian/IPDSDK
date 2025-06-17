//
//  IPDCache.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/5/23.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDDiskCache.h>
#import <IPDSDKCore/IPDMemoryCache.h>
#import <IPDSDKCore/IPDCacheOperation.h>


NS_ASSUME_NONNULL_BEGIN

#define KEY_CACHE_DIRECTORY  @"IPDCacheData"

typedef void(^IPDNoParamsBlock)(void);
typedef void(^IPDCacheQueryCompletionBlock)(NSDictionary * _Nullable dic);
typedef NSString * _Nullable (^IPDCacheAdditionalCachePathBlock)(NSString * _Nonnull key);
@protocol IPDCache <NSObject>

@required
- (NSDictionary *)queryCacheForKey:(NSString *)key;

- (void)storeDic:(NSDictionary *)dic forKey:(nullable NSString *)key completion:(nullable IPDNoParamsBlock)completionBlock;


- (void)removeDicForKey:(NSString *)key completion:(nullable IPDNoParamsBlock)completionBlock;


- (void)containsDicForKey:(NSString *)key completion:(nullable IPDNoParamsBlock)completionBlock;

- (void)clearAllCacheCompletion:(IPDNoParamsBlock)completionBlock;

@end

@interface IPDCache : NSObject <IPDCache>
@property (nonatomic, class, readonly, nonnull) IPDCache *sharedCache;
@property (nonatomic, strong, readonly, nonnull) id <IPDMemoryCache>memoryCache;
@property (nonatomic, strong, readonly, nonnull) id <IPDDiskCache>diskCache;
@property (nonatomic, copy, nonnull, readonly) NSString *diskCachePath;

@property (nonatomic, copy, nullable) IPDCacheAdditionalCachePathBlock additionalCachePathBlock;



@end
NS_ASSUME_NONNULL_END
