//
//  IPDSDKDefines.h
//  IPDOptimizeProject
//
//  Created by Rare on 2021/7/29.
//
#import <UIKit/UIKit.h>

#ifndef IPDSDKDefines_h
#define IPDSDKDefines_h

#define IPD_ScreenHeight [UIScreen mainScreen].bounds.size.height

#define IPD_ScreenWidth [UIScreen mainScreen].bounds.size.width

#define IPD_BANNED_TIME @"BANNED_TIME"
#define IPD_StatusBarHeight \
({float statusBarHeight = 20;\
if(@available(iOS 15.0,*)) {\
    NSSet *set = [[UIApplication sharedApplication] connectedScenes];\
    UIWindowScene *windowScene = [set anyObject];\
    UIStatusBarManager *statusBarManager2 =  windowScene.statusBarManager;\
    statusBarHeight = statusBarManager2.statusBarFrame.size.height;\
}else if (@available(iOS 13.0, *)) {\
    UIStatusBarManager *statusBarManager = [UIApplication sharedApplication].windows.firstObject.windowScene.statusBarManager;\
    statusBarHeight = statusBarManager.statusBarFrame.size.height;\
}else {\
    statusBarHeight = [UIApplication sharedApplication].statusBarFrame.size.height;\
}\
(statusBarHeight);})

#define IPD_IPHONEXSeries ipd_is_iphoneXSeries_screen()

#define IPD_DefaultNavigationBarHeight \
({CGFloat navigationBarHeight = self.navigationController.navigationBar.frame.size.height; \
navigationBarHeight = navigationBarHeight+IPD_StatusBarHeight; \
(navigationBarHeight);})

#define IPD_SafeAreaInsetsBottom \
({CGFloat bottom = 0; \
if (@available(iOS 11.0, *))  { \
bottom = ipd_visibleWindow().safeAreaInsets.bottom; \
} \
(bottom);})

#define IPD_SafeAreaInsetsTop \
({CGFloat top = 0; \
if (@available(iOS 11.0, *)) { \
top = ipd_visibleWindow().safeAreaInsets.top; \
} \
(top);})


/**---------------------------------------------------*/
//强弱引用转换，用于解决代码块（block）与强引用对象之间的循环引用问题
//弱引用
#define ipd_weakify(object)  __weak typeof(object) weak##object = object;
//强引用
#define ipd_strongify(object)  __strong typeof(object) object = weak##object;
/**---------------------------------------------------*/


FOUNDATION_EXPORT UIWindow * ipd_visibleWindow(void);

FOUNDATION_EXPORT BOOL ipd_is_iphoneXSeries_screen(void);

FOUNDATION_EXPORT UIViewController * ipd_getCurrentVC(void);
FOUNDATION_EXPORT UIViewController * ipd_getCurrentVCFrom(UIViewController *vc);

FOUNDATION_EXPORT NSString * const IPDSDKVersion;

FOUNDATION_EXPORT NSNumber * getIPDSDKPlugVer (void);


// 判断某个类是否存在
#define IPD_RUNTIME_HAS_CLASS(classname) (NSClassFromString(@#classname) != nil)

// 运行时检查协议是否存在
#define IPD_RUNTIME_HAS_PROTOCOL(protocolname) (objc_getProtocol(#protocolname) != nil)

// 运行时检查某个类实现了某个协议，会检查整个继承链，包括父类实现的协议
#define IPD_CLASS_CONFORMS_TO_PROTOCOL(classname, protocolname) \
    ([NSClassFromString(@#classname) conformsToProtocol:@protocol(protocolname)])

// 运行时检查方法是否存在
#define IPD_RUNTIME_HAS_METHOD(classname, sel) ([NSClassFromString(@#classname) instancesRespondToSelector:@selector(sel)])


#endif /* IPDSDKDefines_h */
