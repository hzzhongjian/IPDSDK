//
//  IPDMultipleAdAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2023/3/7.
//

#import <IPDSDKCore/IPDCoreAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDMultipleAdAdapterProtocol <NSObject>

- (void)loadAdWithCount:(NSUInteger)count;

@end

@interface IPDMultipleAdAdapter : IPDCoreAdAdapter<IPDMultipleAdAdapterProtocol>

@property (nonatomic, strong, readonly) NSArray *multipleResultObject;

@end

NS_ASSUME_NONNULL_END
