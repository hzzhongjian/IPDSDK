//
//  IPDImageTextAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2023/1/5.
//

#import <IPDSDKCore/IPDBaseContentAdapter.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDKCore/IPDContentAdapterHorizontalFeedCallBackDelegate.h>
#import <IPDSDKCore/IPDContentAdapterImageTextDetailDelegate.h>
#import <IPDSDKCore/IPDContentAdapterStateProtocol.h>
#import <IPDSDKCore/IPDContentAdapterHorizontalFeedCallBackProtocol.h>
#import <IPDSDKCore/IPDContentAdapterImageTextDetailProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDImageTextAdapter : IPDBaseContentAdapter<
IPDContentAdapterStateProtocol,
IPDAdapterContentAdapterVideoStateProtocol,
IPDContentAdapterHorizontalFeedCallBackProtocol,
IPDContentAdapterImageTextDetailProtocol
>

@property (nonatomic, weak, nullable) id<IPDContentAdapterHorizontalFeedCallBackDelegate> ipdAdapter_callBackDelegate;

@property (nonatomic, weak, nullable) id<IPDContentAdapterImageTextDetailDelegate> ipdAdapter_imageTextDelegate;

@end

NS_ASSUME_NONNULL_END
