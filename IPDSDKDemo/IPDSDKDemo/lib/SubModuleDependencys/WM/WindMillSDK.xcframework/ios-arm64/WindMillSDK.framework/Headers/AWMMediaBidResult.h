//
//  AWMMediaBidResult.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/13.
//

#import <Foundation/Foundation.h>

@interface AWMMediaBidResult : NSObject

/// bidding胜出
@property (nonatomic, assign, readonly) BOOL win;

/// 当胜出时，winnerPrice有值，其它情况不回传胜出价
@property (nonatomic, assign, readonly) NSInteger winnerPrice;

@property (nonatomic, copy, readonly) NSDictionary *ext;

@end
