//
//  IPDTierAdAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/11/11.
//

#import <IPDSDKCore/IPDCoreAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDTierAdapterProtocol <NSObject>

- (void)loadAd;

@end

@interface IPDTierAdAdapter : IPDCoreAdAdapter<IPDTierAdapterProtocol>

@end

NS_ASSUME_NONNULL_END
