//
//  SliderLabel.h
//  nineteenlou
//
//  Created by 麻明康 on 2020/9/25.
//  Copyright © 2020 qiu . All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class IPDSliderLabel;
typedef void(^LabelClick)(IPDSliderLabel *sliderLab);

@interface IPDSliderLabel : UILabel
@property (nonatomic, assign) BOOL showLine;
@property (nonatomic, copy) LabelClick labelClick;
@end

NS_ASSUME_NONNULL_END
