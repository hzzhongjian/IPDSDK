//
//  IPDLogView.h
//  IPDSDKDemo
//
//  Created by Rare on 2022/3/3.
//  Copyright © 2022 zj. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface IPDLogView : UIView

-(void)clearLog;
-(void)logMessage:(NSString *)log;

@end

NS_ASSUME_NONNULL_END
