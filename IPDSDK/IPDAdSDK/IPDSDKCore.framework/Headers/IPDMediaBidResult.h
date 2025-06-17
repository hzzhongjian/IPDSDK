//
//  IPDMediaBidResult.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2025/3/24.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDKSAdExposureReportParam.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDMediaBidResult : NSObject

+ (instancetype)sharedInstance;

// -------------------回调给快手的曝光/点击事件----------------
// bidding失败，上报给快手平台的回调
@property (nonatomic, copy) void(^ksBiddingFailureExposureReportBlock)(IPDKSAdExposureReportParam *param);

@end

NS_ASSUME_NONNULL_END
