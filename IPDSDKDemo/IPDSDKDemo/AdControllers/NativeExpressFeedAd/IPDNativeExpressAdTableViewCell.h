//
//  IPDNativeExpressAdTableViewCell.h
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IPDSDK/IPDNativeExpressFeedAdManager.h>
NS_ASSUME_NONNULL_BEGIN

@interface IPDNativeExpressAdTableViewCell : UITableViewCell


-(void)refreshWithAd:(IPDNativeExpressFeedAd *)ad;

@end

NS_ASSUME_NONNULL_END
