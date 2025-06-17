//
//  IPDHorizontalFeedAdapter.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2023/1/5.
//

#import <IPDSDKCore/IPDBaseContentAdapter.h>
#import <IPDSDKCore/IPDContentInfo.h>
#import <IPDSDKCore/IPDContentAdapterHorizontalFeedCallBackDelegate.h>
#import <IPDSDKCore/IPDContentAdapterStateProtocol.h>
#import <IPDSDKCore/IPDContentAdapterHorizontalFeedCallBackProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDHorizontalFeedAdapter : IPDBaseContentAdapter<
IPDContentAdapterStateProtocol,
IPDAdapterContentAdapterVideoStateProtocol,
IPDContentAdapterHorizontalFeedCallBackProtocol,
IPDContentAdapterLoadCallBackProtocol
>
@property (nonatomic, weak, nullable) id<IPDContentAdapterHorizontalFeedCallBackDelegate> ipdAdapter_callBackDelegate;


@end

NS_ASSUME_NONNULL_END
