//
//  IPDMiniParamAdAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/9/26.
//

#import <IPDSDKCore/IPDCoreAdAdapter.h>
#import <IPDSDKCore/IPDMiniParamAdProtocol.h>
#import <IPDSDKCore/IPDTierAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDMiniParamAdAdapter;

@protocol IPDMiniParamAdAdapterDelegate <NSObject>

@optional
/**
 *  小程序唤起成功
 */
- (void)ipd_miniParamAdAdapterDidAwake:(IPDMiniParamAdAdapter *)miniParamAdAdapter;


/**
 *  小程序唤起失败
 */
- (void)ipd_miniParamAdAdapterAwakeFail:(IPDMiniParamAdAdapter *)miniParamAdAdapter error:(NSError *)error;

- (void)ipd_miniParamAdAdapter:(IPDMiniParamAdAdapter *)miniParamAdAdapter onResp:(id)resp;

@end

// 修改之前，是继承IPDCoreAdAdapter这个类的

@interface IPDMiniParamAdAdapter : IPDTierAdAdapter <IPDMiniParamAdProtocol>

@property (nonatomic, weak) id <IPDMiniParamAdAdapterDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
