//
//  IPDBaseContentAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2023/1/4.
//

#import <IPDSDKCore/IPDCoreAdAdapter.h>
#import <IPDSDKCore/IPDTierAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

// 之前是继承IPDCoreAdAdapter，现改成IPDTierAdAdapter
@interface IPDBaseContentAdapter : IPDTierAdAdapter

@property (nonatomic, strong) UIViewController *viewController;

- (void)reportWithEvent:(IPDEventString)event supplementMsg:(nullable NSString *)supplementMsg;

- (void)loadContentPageWithDeeplink:(NSString *)deepLink;

- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
