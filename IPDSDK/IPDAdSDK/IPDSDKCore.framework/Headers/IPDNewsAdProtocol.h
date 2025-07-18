//
//  IPDNewsAdProtocol.h
//  IPDSDKCore
//
//  Created by 麻明康 on 2022/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDNewsAdProtocol <NSObject>
/** required.
 由接入方提供urseId
 用于奖励发放的数据校验，是每个用户的唯一标识符。
 */
@property (nonatomic, copy) NSString *userId;


@property (nonatomic, assign) CGRect adFrame;

- (void)loadAdAndShow;

- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
