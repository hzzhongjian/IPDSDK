//
//  NSBundle+ZJDynamicID.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2023/8/12.
//  Copyright © 2023 zj. All rights reserved.
//

#import "NSBundle+ZJDynamicID.h"
#import <objc/message.h>
#import <dlfcn.h>
#import "IPDADIDS.h"
@implementation NSBundle (ZJDynamicID)
+ (void)load{
    //    拿到两个Method
    Method bundleIdentifier = class_getInstanceMethod([NSBundle class], @selector(bundleIdentifier));
    Method ZJbundleIdentifier = class_getInstanceMethod([NSBundle class], @selector(ZJBundleIdentifier));
    //    交换
    if(!bundleIdentifier||!ZJbundleIdentifier){
        NSLog(@"找不到要交换的方法");
    }else{
        method_exchangeImplementations(bundleIdentifier, ZJbundleIdentifier);
    }
}

////测试代码
//-(void)test{
//    NSDictionary *dic = [[NSBundle mainBundle] infoDictionary];
//    NSString *bundleID1 = [[[NSBundle mainBundle] infoDictionary] valueForKey:(__bridge NSString *)kCFBundleIdentifierKey];
//    NSString *bundleID2 = [[[NSBundle mainBundle] infoDictionary] objectForKey:(__bridge NSString *)kCFBundleIdentifierKey];
//    NSString *bundleID3 = [[NSBundle mainBundle] infoDictionary][(__bridge NSString *)kCFBundleIdentifierKey];
//}
-(BOOL)isCallFromTaker{
    NSArray *address = [NSThread callStackReturnAddresses];
    Dl_info info = {0};
    if(dladdr((void *)[address[2] longLongValue], &info) == 0){
        return NO;
    }
    NSString *path = [NSString stringWithUTF8String:info.dli_fname];
    if ([path hasPrefix:NSBundle.mainBundle.bundlePath]) {
        // 二进制来自 ipa 包内
        if ([path.lastPathComponent isEqualToString:@"libTakerDylib.dylib"]) {
            // 二进制是插件本身
            return NO;
        } else {
            // 二进制是app
            return YES;
        }
    } else {
        // 二进制是系统或者越狱插件
        return NO;
    }
}

-(id)ZJBundleIdentifier{
    if([self isCallFromTaker]){
#ifdef ZJ_BundleId
        return ZJ_BundleId;
#else
        return [self ZJBundleIdentifier];
#endif
    }
    return [self ZJBundleIdentifier];
}
@end
