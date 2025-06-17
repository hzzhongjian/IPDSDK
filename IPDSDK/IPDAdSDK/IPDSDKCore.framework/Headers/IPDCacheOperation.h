//
//  IPDCacheOperation.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/5/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// A protocol represents cancelable operation.
@protocol IPDCacheOperation <NSObject>

- (void)cancel;

@end
/// NSOperation conform to `IPDCacheOperation`.
@interface NSOperation (IPDCacheOperation) <IPDCacheOperation>

@end

NS_ASSUME_NONNULL_END
