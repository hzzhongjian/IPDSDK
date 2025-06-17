//
//  ZJNativeAdBaseTableViewCell.h
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/1.
//  Copyright © 2021 zj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IPDSDK/IPDNativeAd.h>
#import "IPDFillNativeAdView.h"
NS_ASSUME_NONNULL_BEGIN

@interface IPDNativeAdBaseTableViewCell : UITableViewCell

@property (nonatomic,strong)IPDFillNativeAdView *fillView;
//@property (nonatomic,strong)UIView *adView;



- (void)setupWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject delegate:(id<IPDNativeAdViewDelegate>)delegate vc:(UIViewController *)vc;

+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject;




@end

NS_ASSUME_NONNULL_END
