//
//  ZJNativeAdTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDNativeAdImageTableViewCell.h"

@interface IPDNativeAdImageTableViewCell()



@end

@implementation IPDNativeAdImageTableViewCell


#pragma mark - public
- (void)setupWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject delegate:(id<IPDNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{
    //配置单图广告
    CGFloat height = 0;
    if (dataObject.imageWidth == 0 && dataObject.imageHeight == 0) {
        height = 100;
    } else {
        height = (kScreenWidth-10)*(@(dataObject.imageHeight).floatValue/@(dataObject.imageWidth).floatValue);
    }
    [self.fillView.imageView mas_updateConstraints:^(MASConstraintMaker *make) {
        make.height.mas_equalTo(height);
    }];
    [self.fillView.imageView layoutIfNeeded];
    [self.fillView layoutIfNeeded];
//    self.fillView.videoOrImageFrame = self.fillView.imageView.frame;
//    self.fillView.videoOrImageFrame = CGRectMake(5, 60, 404, 227.333);
    self.fillView.delegate = delegate; // adView 广告回调
    self.fillView.viewController = vc; // 跳转 VC
    [self.fillView registerDataObject:dataObject clickableViews:@[self.fillView.clickButton]];//self.fillView,
    [self.contentView addSubview:self.fillView];
    [self.fillView resizeIfNeed];
//    self.fillView.logoView.hidden = YES;
}
 
+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject
{
   CGFloat baseHeigth =  [super cellHeightWithUnifiedNativeAdDataObject:dataObject];
    
    if (dataObject.imageWidth == 0 && dataObject.imageHeight == 0) {
        return 100+baseHeigth+8;
    }
    //单图cell
    CGFloat imageHeight = (kScreenWidth-10)*(@(dataObject.imageHeight).floatValue/@(dataObject.imageWidth).floatValue);
    //图片高度+顶部固定高度+底部间隙
    return imageHeight+baseHeigth+8;
}




@end
