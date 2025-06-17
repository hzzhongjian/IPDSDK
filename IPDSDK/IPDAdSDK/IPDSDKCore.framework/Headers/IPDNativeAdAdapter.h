//
//  IPDNativeAdAdapter.h
//  IPDSDKCore
//
//  Created by Rare on 2021/3/29.
//

//#import "IPDMultipleAdAdapter.h"
#import <IPDSDKCore/IPDMultipleAdAdapter.h>
#import <IPDSDKCore/IPDNativeAdObject.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDNativeAdAdapter;

@protocol IPDNativeAdAdapterDelegate <NSObject>
/**
 广告数据回调

 @param multipleResultObject 广告数据数组
 @param error 错误信息
 */
- (void)ipdAdapter_nativeAd:(IPDNativeAdAdapter *)adAdapter didLoaded:(NSArray<IPDNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;


@end



@interface IPDNativeAdAdapter : IPDMultipleAdAdapter

@property (nonatomic,weak)id <IPDNativeAdAdapterDelegate> delegate;

@property (nonatomic, strong) NSArray<IPDNativeAdObject *> *data;

// required. Image size.
// 穿山甲联盟要求传加载图片尺寸
@property (nonatomic, assign) IPDProposalSize imgSize;

/**
 广告数据回调
 */
- (void)nativeAdLoaded:(NSArray<IPDNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;



- (void)loadAdWithCount:(NSInteger)adCount;



@end

NS_ASSUME_NONNULL_END
