//
//  ZJNativeAdVideoTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/4/1.
//  Copyright © 2021 IPD. All rights reserved.
//

#import "IPDNativeAdVideoTableViewCell.h"


@implementation IPDNativeAdVideoTableViewCell

- (void)setupWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject delegate:(id<IPDNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{

//
    
    self.fillView.viewController = vc;
    self.fillView.delegate = delegate;
//    [self.fillView registerDataObject:dataObject clickableViews:@[self.fillView.appIconImageView, self.fillView.imageView,self.fillView.descLabel,self.fillView.titleLabel,self.fillView.clickButton]];
    [self.fillView registerDataObject:dataObject clickableViews:@[self.fillView,self.fillView.clickButton]];
    self.fillView.videoAdView.frame = CGRectMake(0, IPDNativeTopHeight, self.frame.size.width, 150);
//    self.fillView.videoOrImageFrame = self.fillView.videoAdView.frame;
    [self.fillView resizeIfNeed];
    [self.contentView addSubview:self.fillView];
    [self.contentView addSubview:self.muteBtn];
//    self.fillView.logoView.hidden = YES;
    
    UIPanGestureRecognizer *panGesture = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handlePanGesture:)];
    panGesture.delegate = self;
    [self addGestureRecognizer:panGesture];
    
    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapGesture:)];
    tapGesture.delegate = self;
    [self addGestureRecognizer:tapGesture];
}


+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(IPDNativeAdObject *)dataObject
{
    CGFloat baseHeigth =  [super cellHeightWithUnifiedNativeAdDataObject:dataObject];
     
     //视频cell
     CGFloat videoHeight = 150;
     //图片高度+顶部固定高度+底部间隙
     return videoHeight+baseHeigth+8;
}

-(UIButton *)muteBtn{
    if (!_muteBtn) {
        _muteBtn = [[UIButton alloc]initWithFrame:CGRectMake(self.frame.size.width-30, self.frame.size.height-IPDNativeBottomHight-8, 20, 20)];
//        _muteBtn.backgroundColor = [UIColor redColor];
        [_muteBtn setImage:[UIImage imageNamed:@"sound_open"] forState:UIControlStateNormal];
        [_muteBtn setImage:[UIImage imageNamed:@"sound_close"] forState:UIControlStateSelected];
        [_muteBtn addTarget:self action:@selector(muteAction:) forControlEvents:UIControlEventTouchUpInside];
    }
    return _muteBtn;
}

-(void)muteAction:(UIButton *)sender{
    sender.selected = !sender.selected;
    self.fillView.mutedIfCan = sender.selected;
}


- (void)handlePanGesture:(UIPanGestureRecognizer *)gesture
{
    NSLog(@"=============移动了");
    if (gesture.state == UIGestureRecognizerStateBegan) {
        
    } else if (gesture.state == UIGestureRecognizerStateEnded) {
//        self.testView.hello = NO;
    }
    
}

- (void)handleTapGesture:(UIPanGestureRecognizer *)gesture
{
//    gesture.state;
    if (gesture.state == UIGestureRecognizerStateBegan) {
//        self.testView.userInteractionEnabled = NO;
        
    } else if (gesture.state == UIGestureRecognizerStateEnded) {
//        self.testView.userInteractionEnabled = YES;
//        self.testView.hello = YES;
    }
    
    NSLog(@"=============点击了");
}

// 允许多个手势同时识别
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
    return YES;
}
@end



