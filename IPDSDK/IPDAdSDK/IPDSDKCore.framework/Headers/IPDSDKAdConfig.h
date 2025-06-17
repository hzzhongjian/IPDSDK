//
//  IPDSDKAdConfig.h
//  IPDSDKCore
//
//  Created by Rare on 2022/2/23.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>
#import <IPDSDKCore/IPDAdsModel.h>


NS_ASSUME_NONNULL_BEGIN

@interface IPDSDKAdConfig : NSObject

+ (instancetype)shared;

@property (nonatomic, copy) NSString *appId;

@property (nonatomic, copy) NSArray <NSDictionary *>*platforms;

@property (nonatomic, copy) NSArray <IPDAdPositionModel *>*adArray;

@property (nonatomic, copy) NSString *secretStr;

@property (nonatomic, assign) IPDAdSDKLogLevel level;

//是否可以获取ecpm
@property (nonatomic, assign) BOOL can_read_ecpm;


@end

NS_ASSUME_NONNULL_END
