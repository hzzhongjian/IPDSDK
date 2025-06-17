//
//  IPDBiddingLossRelease.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/7/22.
//

#ifndef IPDBiddingLossRelease_h
#define IPDBiddingLossRelease_h

typedef NS_ENUM(NSInteger,IPDBiddingLossReason){
    IPDBiddingLossReason_LowPrice          = 1,        // 竞争力不足，如不是本次竞价的最高出价方，可上报此竞败原因
    IPDBiddingLossReason_LoadTimeout       = 2,        // 返回超时，如在本次竞价中未返回广告，可上报此竞败原因
    IPDBiddingLossReason_NoAd              = 3,        // 无广告回包
    IPDBiddingLossReason_AdDataError       = 4,        // 回包不合法
    IPDBiddingLossReason_Other             = 10001     // 其他
};

#endif /* IPDBiddingLossRelease_h */
