//
//  IPDNativeAdAtlasImageTableViewCell.m
//  IPDSDKDemo
//
//  Created by Rare on 2021/4/1.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDNativeAdAtlasImageTableViewCell.h"

@implementation IPDNativeAdAtlasImageTableViewCell

#pragma mark - public
- (void)setupWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject delegate:(id<IPDNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{
    
    
    self.fillView.viewController = vc;
    self.fillView.delegate = delegate;
//    if (!self.fillView) {
        CGFloat imageWidth = (kScreenWidth-20)/3.0;
        CGFloat imageHeight = imageWidth *(@(dataObject.imageHeight).floatValue/@(dataObject.imageWidth).floatValue);
        for (int i = 0; i<dataObject.mediaUrlList.count; i++) {
            NSString *urlString = dataObject.mediaUrlList[i];
            //行
            NSInteger line =floorf(i/3.0);
            //y
            CGFloat y = IPDNativeTopHeight+(line *(imageHeight+5));
            //每一行的位置
            NSInteger index = i - line*3;
            CGFloat x =  5*(index+1)+imageWidth*index;
            
            UIImageView *imageView = [[UIImageView alloc]init];
            imageView.frame = CGRectMake(x,y, imageWidth,imageHeight);
            [imageView sd_setImageWithURL:[NSURL URLWithString:urlString]];
            [self.fillView addSubview:imageView];
        }
        // 假设图片布局是这么多
//        self.fillView.videoOrImageFrame = CGRectMake(5, 60, 404, 227.333);
        [self.fillView registerDataObject:dataObject clickableViews:@[self.fillView,self.fillView.clickButton]];
        [self.fillView resizeIfNeed];
        [self.contentView addSubview:self.fillView];
        
//        self.fillView.logoView.hidden = YES;
//    }
}

+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject
{
    CGFloat baseHeigth =  [super cellHeightWithUnifiedNativeAdDataObject:dataObject];
    CGFloat imageWidth = (kScreenWidth-20)/3.0;
    CGFloat imageHeight = imageWidth *(@(dataObject.imageHeight).floatValue/@(dataObject.imageWidth).floatValue);
    NSInteger totalLine =ceilf(dataObject.mediaUrlList.count/3.0);
    CGFloat totalHeight = totalLine *(imageHeight+5);
    return totalHeight +baseHeigth+8;
}




@end
