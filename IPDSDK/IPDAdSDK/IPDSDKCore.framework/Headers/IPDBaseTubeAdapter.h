//
//  IPDBaseTubeAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2024/6/11.
//

#import <IPDSDKCore/IPDCoreAdAdapter.h>
#import <IPDSDKCore/IPDTierAdAdapter.h>
#import <IPDSDKCore/IPDTubePageConfig.h>

NS_ASSUME_NONNULL_BEGIN
//IPDCoreAdAdapter是继承IPDCoreAdAdapter 改成 IPDTierAdAdapter

@interface IPDBaseTubeAdapter : IPDTierAdAdapter

@property (nonatomic, strong) UIViewController *viewController;

@property (nonatomic, strong) IPDTubePageConfig *tubePageConfig;

- (void)reportWithEvent:(IPDEventString)event supplementMsg:(nullable NSString *)supplementMsg;

- (void)loadContentPageWithDeeplink:(NSString *)deepLink;

- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
