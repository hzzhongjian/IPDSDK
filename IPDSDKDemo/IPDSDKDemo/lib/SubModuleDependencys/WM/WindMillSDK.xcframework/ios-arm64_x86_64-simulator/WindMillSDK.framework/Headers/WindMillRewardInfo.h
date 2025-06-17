//
//  WindMillRewardInfo.h
//  HeMobTest
//
//  Created by zhou.ding on 2017/5/3.
//  Copyright © 2017年 happyelements. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WindMillRewardInfo : NSObject

/// 是否达到激励条件
@property (nonatomic,assign) BOOL isCompeltedView;

/// 交易的唯一id
@property (nonatomic, copy) NSString *transId;

/// 用户id
@property (nonatomic, copy) NSString *userId;

@end
