//
//  ZJFillNativeAdView.h
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import <IPDSDKCore/IPDNativeAdView.h>

NS_ASSUME_NONNULL_BEGIN
//头部高度。头像、标题，描述+顶部空隙+下部分视图开始的位置
#define IPDNativeTopHeight (45+5+10)
//logo和静音按钮
#define IPDNativeBottomHight (20)


@interface IPDFillNativeAdView : IPDNativeAdView


@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *descLabel;
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UIButton *clickButton;
@property (nonatomic, strong) UIImageView *appIconImageView;


@end

NS_ASSUME_NONNULL_END
