//
//  AWMMediatedNativeAd.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AWMMediatedNativeAdData.h"

@protocol AWMMediatedNativeAdViewCreator;

@interface AWMMediatedNativeAd : NSObject

// 广告物料，包含有最全的广告数据 [Optional]（仅自渲染需要赋值，模版渲染时可设置为nil）
@property (nonatomic, strong) id<AWMMediatedNativeAdData> data;

// 广告视图创建对象，对常用广告展示元素进行创建 [Required]
@property (nonatomic, strong) id<AWMMediatedNativeAdViewCreator> viewCreator;

// 广告视图对象，一般指原生广告的根视图 [Optional]（部分adn的自渲染可能为空）
@property (nonatomic, strong) UIView *view;

// adn获取到的原始广告数据 [Required] (adn广告回调的原始数据，通过该数据建立对应关系)
@property (nonatomic, strong) id originMediatedNativeAd;

@end

