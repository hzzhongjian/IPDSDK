//
//  IPDNativeExpressAdTableViewCell.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDNativeExpressAdTableViewCell.h"

@implementation IPDNativeExpressAdTableViewCell

-(instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    return self;
}


-(void)refreshWithAd:(IPDNativeExpressFeedAd *)ad{
    UIView *view = [self.contentView viewWithTag:100];
    [view removeFromSuperview];
    ad.feedView.tag = 100;
//    [feedAd setVideoSoundEnable:soundEnable];
    [self.contentView addSubview:ad.feedView];
    [ad.feedView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(@0);
    }];
    
//    [ad.feedView setFrame:CGRectMake(0, 0, 300, 100)];
}

-(void)prepareForReuse{
    [super prepareForReuse];
}

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}


- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
