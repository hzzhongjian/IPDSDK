//
//  NLSliderSwotchProtocol.h
//  SliderSwitch
//
//  Created by kkmm on 2018/10/16.
//  Copyright © 2018 kkmm. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <objc/objc-api.h>

#ifndef IPDSliderSwitchProtocol_h
#define IPDSliderSwitchProtocol_h
//切换页面触发方式
typedef enum {
    IPDSlideWayByCode = 0,
    IPDSlideWayByTapTagButton = 1,
    IPDSlideWayByPanGesture = 2,
    IPDSlideWayByOutRequest = 3,
} IPDSlideWay;

@protocol IPDSliderSwitchProtocol<NSObject>
@required
/**
 是否为当前可见VC
 实现协议的类加上：
 @synthesize isVisiableView;
 */
@property (nonatomic,readonly) BOOL isVisiableView;

/**
 是否以页卡的方式展示
 实现协议的类加上：
 @synthesize showAsPageCard;
 */
@property (nonatomic) BOOL showAsPageCard;

-(BOOL)canGoBack;

-(BOOL)goBack;

- (BOOL)canGoForward;

- (BOOL)goForward;
    
@optional
/*! 滑动到当前子页面*/
-(void)viewDidScrollToVisiableArea DEPRECATED_MSG_ATTRIBUTE("此方法不能在页面切换时 给jpVideo视频的暂停播放提供一个正确的时机，使用 sliderSwitchDidEndDeceleratingBySlideWay: 替换此方法:"); ;

/*! 当前页面离开显示页*/
-(void)viewDidScrollToUnVisiableArea DEPRECATED_MSG_ATTRIBUTE("此方法不能在页面切换时 给jpVideo视频的暂停播放提供一个正确的时机，使用 sliderSwitchWillBeginDragging: 替换此方法:");//这个用问题，不要写这个

/*! 当前页面从不可见页面滑动到可显示的左右页面*/
-(void)viewDidScrollToSideArea DEPRECATED_MSG_ATTRIBUTE("此方法不能在页面切换时 给jpVideo视频的暂停播放提供一个正确的时机，使用 sliderSwitchDidEndDeceleratingBySlideWay: 替换此方法:");


//用作视频开始停止播放
/*! 开始拖动 仅在isVisiableView中回调 */
-(void)sliderSwitchWillBeginDragging;

/*! 停止滚动 仅在isVisiableView中回调 */
-(void)sliderSwitchDidEndDeceleratingBySlideWay:(IPDSlideWay)slideWay;

/*! sliderSwitch请求刷新当前页面 主要用于点击menubar调用刷新数据方法 */
-(void)sliderSwitchRequestRefresh;

/*! 点击了当前页卡标题 */
-(void)sliderSwitchDidTapCurrentPageTitle;

@end


#endif /* SliderSwitchProtocol_h */
