//
//  WADOptions.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/28.
//

#import <Foundation/Foundation.h>

@interface WADOptions : NSObject
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *apiKey;
@property (nonatomic, copy) NSString *placementId;
@property (nonatomic, copy) NSString *unitId;
@property (nonatomic, copy) NSString *publisherId;
@property (nonatomic, copy) NSString *playDirection;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *bidToken;
@property (nonatomic, copy) NSString *countdown;
@property (nonatomic, copy) NSString *allowSkip;
@property (nonatomic, copy) NSString *subType;//0: 非全屏 1:全屏 2:新插屏
@property (nonatomic, copy) NSString *ratio;//针对admob: 1: 任意；2:横屏；3:竖屏；4：正方形
@property (nonatomic, copy) NSString *showClose;//0: 显示；1：不显示
@property (nonatomic, copy) NSString *autoPlayPolicy;//WIFI:仅wifi网络自动播放； ALWAYS：自动播放
@property (nonatomic, copy) NSString *autoPlayMuted;//1:静音 0:非静音
@property (nonatomic, copy) NSString *detailPageMuted;//1:静音 0:非静音
@property (nonatomic, copy) NSString *minVideoDuration;
@property (nonatomic, copy) NSString *maxVideoDuration;
@property (nonatomic, copy) NSString *clickType;//0按钮点击；1全屏点击
@property (nonatomic, copy) NSString *templateType;//0: 模版渲染 1:非模版渲染
@property (nonatomic, copy) NSString *splashType;//0: 普通开屏 1:开屏V/开屏点睛
@property (nonatomic, copy) NSString *imgType;//0: 690*388px 1:228*150px
@property (nonatomic, assign) CGSize size;
@property (nonatomic, copy) NSString *bannerType;//300*50、300*90、300*250、320*50/728*90
@property (nonatomic, assign) BOOL isHeaderBidding;//是否是竞价广告源
@property (nonatomic, assign) int32_t biddingType;//竞价类型
@property(nonatomic, readwrite) int32_t bidFloor;/** bidding的底价，单位：分 */
@end
