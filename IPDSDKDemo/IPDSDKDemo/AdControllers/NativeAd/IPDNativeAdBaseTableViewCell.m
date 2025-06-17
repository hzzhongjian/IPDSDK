//
//  ZJNativeAdBaseTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/1.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDNativeAdBaseTableViewCell.h"

@implementation IPDNativeAdBaseTableViewCell

-(instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        
    }
    return self;
}


- (void)setupWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject delegate:(id<IPDNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{
    
}

+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject{
    return IPDNativeTopHeight+5+IPDNativeBottomHight;
}

    
- (void)prepareForReuse{
    [super prepareForReuse];
//    [self.fillView unregisterDataObject];
//    [self.fillView removeFromSuperview];
//    [self.adView removeFromSuperview];
//    _fillView = nil;
//    _adView = nil;
}
    
-(void)dealloc{
    [_fillView unregisterDataObject];
}
    

-(IPDFillNativeAdView *)fillView{
    if (!_fillView) {
        _fillView= [[IPDFillNativeAdView alloc]initWithFrame:self.contentView.bounds];
        
    }
    return _fillView;
}

@end
