//
//  IPDNativeAd.h
//  IPDSDK
//
//  Created by Rare on 2021/3/29.
//  Copyright © 2021 zj. All rights reserved.
//

//#import "IPDAd.h"
#import <IPDSDKCore/IPDNativeAdObject.h>
#import <IPDSDKCore/IPDNativeAdView.h>
#import <IPDSDK/IPDMultipleAd.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDNativeAdDelegate <NSObject>

@optional
/**自渲染广告加载回调*/
- (void)ipd_nativeAdLoaded:(NSArray<IPDNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;

@end

@interface IPDNativeAd : IPDMultipleAd

@property (nonatomic, weak) id <IPDNativeAdDelegate> delegate;

// required. Image size.
// 穿山甲联盟要求传加载图片尺寸
@property (nonatomic, assign) IPDProposalSize imgSize;

@end

NS_ASSUME_NONNULL_END
