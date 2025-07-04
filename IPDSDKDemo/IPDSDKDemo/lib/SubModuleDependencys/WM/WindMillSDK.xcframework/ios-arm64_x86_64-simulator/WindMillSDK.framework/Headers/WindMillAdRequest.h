//
//  WindMillAdRequest.h
//  WindSDK
//
//  Created by happyelements on 2018/4/8.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WindMillAdRequest : NSObject

@property (nonatomic,copy) NSString *userId;

@property (nonatomic,copy) NSString *placementId;

//做为扩展参数使用
@property (nonatomic,strong) NSDictionary<NSString *, NSString *> *options;

+ (instancetype)request;



@end
