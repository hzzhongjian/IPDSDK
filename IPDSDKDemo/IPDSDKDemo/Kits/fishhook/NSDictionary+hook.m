//
//  NSDictionary+hook.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2024/4/11.
//  Copyright © 2024 zj. All rights reserved.
//

#import "NSDictionary+hook.h"
#import <objc/message.h>
#import <dlfcn.h>
@implementation NSDictionary (hook)
+ (void)load{
//    //    拿到两个Method
//    [NSDictionary swizzlingForType:"__NSDictionaryI"];
//    只能成功交换bundleId1，bundleId2和bundleId3可能是直接调用CFDictionaryGetValue方法，不好处理
//    id dic = [[NSBundle mainBundle] infoDictionary];
//    NSString *bundleId1 = [[[NSBundle mainBundle] infoDictionary] valueForKey:(__bridge NSString *)kCFBundleIdentifierKey];
//    NSString *bundleId2 = [[NSBundle mainBundle] infoDictionary][(__bridge NSString *)kCFBundleIdentifierKey];
//    NSString *bundleId3 = [[[NSBundle mainBundle] infoDictionary] objectForKey:(__bridge NSString *)kCFBundleIdentifierKey];
    
//    没用
//    [NSDictionary swizzlingForType:"__NSDictionaryM"];
//    [NSDictionary swizzlingForType:"__NSCFDictionary"];
    // 获取 CFDictionaryGetValue 函数指针
}

//-(void)test{
//    id dic = [[NSBundle mainBundle] infoDictionary];
//    NSString *bundleId1 = [[[NSBundle mainBundle] infoDictionary] valueForKey:(__bridge NSString *)kCFBundleIdentifierKey];
//    NSString *bundleId2 = [[NSBundle mainBundle] infoDictionary][@"kkCFBundleIdentifierKey"];
//    NSString *bundleId3 = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"kkCFBundleIdentifierKey"];
//    NSDictionary *testDic_I = @{@"CFBundleIdentifierKey":@"com.nonononon",@"CFBundleIdentifierKe1y":@"com.nonononon",@"CFBundleIdentifierKewy":@"com.nonononon",@"CFBundleIdentifierKe3y":@"com.nonononon",};
//    NSMutableDictionary *testDic_M = [testDic_I mutableCopy];
//    NSString *bundleId4 = [testDic_M objectForKey:(__bridge NSString *)kCFBundleIdentifierKey];
//}


+(void)swizzlingForType:(const char * _Nonnull)classType{
    Method valueForKey = class_getInstanceMethod(objc_getClass(classType), @selector(valueForKey:));
    Method zj_valueForKey = class_getInstanceMethod(objc_getClass(classType), @selector(zj_valueForKey:));
    //    交换
    if(!valueForKey||!zj_valueForKey){
        NSLog(@"找不到要交换的setObject:ForKey:方法");
    }else{
        method_exchangeImplementations(valueForKey, zj_valueForKey);
    }
    
    Method objectForKey = class_getInstanceMethod(objc_getClass(classType), @selector(objectForKey:));
    Method zj_objectForKey = class_getInstanceMethod(objc_getClass(classType), @selector(zj_objectForKey:));
    //    交换
    if(!objectForKey||!zj_objectForKey){
        NSLog(@"找不到要交换的setObject:ForKey:方法");
    }else{
        method_exchangeImplementations(objectForKey, zj_objectForKey);
    }
    
    Method objectForKeyedSubscript = class_getInstanceMethod(objc_getClass(classType), @selector(objectForKeyedSubscript:));
    Method zj_objectForKeyedSubscript = class_getInstanceMethod(objc_getClass(classType), @selector(zj_objectForKeyedSubscript:));
    //    交换
    if(!objectForKeyedSubscript||!zj_objectForKeyedSubscript){
        NSLog(@"找不到要交换的setObject:ForKey:方法");
    }else{
        method_exchangeImplementations(objectForKeyedSubscript, zj_objectForKeyedSubscript);
    }
}

-(id)zj_objectForKey:(NSString *)key{
//    NSLog(@"%@",NSStringFromSelector(_cmd));
    if([self isCallFromTaker]){
#ifdef ZJ_BundleId
//        if (self == [[NSBundle mainBundle] infoDictionary]) {
            if([(__bridge NSString *)kCFBundleIdentifierKey isEqualToString:key]){
                return ZJ_BundleId;
            }
//        }
        return [self zj_objectForKey:key];
#else
        return [self zj_objectForKey:key];
#endif
    }
    return [self zj_objectForKey:key];
}

-(id)zj_objectForKeyedSubscript:(NSString *)key{
//    NSLog(@"%@",NSStringFromSelector(_cmd));
    if([self isCallFromTaker]){
#ifdef ZJ_BundleId
//        if (self == [[NSBundle mainBundle] infoDictionary]) {
            if([(__bridge NSString *)kCFBundleIdentifierKey isEqualToString:key]){
                return ZJ_BundleId;
            }
//        }
        return [self zj_objectForKeyedSubscript:key];
#else
        return [self zj_objectForKeyedSubscript:key];
#endif
    }
    return [self zj_objectForKeyedSubscript:key];
}

-(id)zj_valueForKey:(NSString *)key{
//    NSLog(@"%@",NSStringFromSelector(_cmd));
    if([self isCallFromTaker]){
#ifdef ZJ_BundleId
//        if (self == [[NSBundle mainBundle] infoDictionary]) {
            if([(__bridge NSString *)kCFBundleIdentifierKey isEqualToString:key]){
                return ZJ_BundleId;
            }
//        }
        return [self zj_valueForKey:key];
#else
        return [self zj_valueForKey:key];
#endif
    }
    return [self zj_valueForKey:key];
}

//-(id)zj_getCFBundleIdentifier{
//    if([self isCallFromTaker]){
//#ifdef ZJ_BundleId
////        if (self == [[NSBundle mainBundle] infoDictionary]) {
//                return ZJ_BundleId;
////        }
//        return [self zj_getCFBundleIdentifier];
//#else
//        return [self zj_getCFBundleIdentifier];
//#endif
//    }
//    return [self zj_getCFBundleIdentifier];
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
        
        if ([path.lastPathComponent isEqualToString:@"ZJSDKDemo"]) {
            // 二进制是app
            return NO;
        } else if ([path.lastPathComponent isEqualToString:@"KSAdSDK"]
                   ) {
            // 二进制是app
            return YES;
        }
        NSLog(@"path.lastPathComponent ======= %@",path.lastPathComponent);
        return NO;

    } else {
        // 二进制是系统或者越狱插件
        return NO;
    }
}

//bool is_call_frome_taker(void){
//    NSArray *address = [NSThread callStackReturnAddresses];
//    Dl_info info = {0};
//    if(dladdr((void *)[address[2] longLongValue], &info) == 0){
//        return NO;
//    }
//    NSString *path = [NSString stringWithUTF8String:info.dli_fname];
//    if ([path hasPrefix:NSBundle.mainBundle.bundlePath]) {
//        // 二进制来自 ipa 包内
//        if ([path.lastPathComponent isEqualToString:@"libTakerDylib.dylib"]) {
//            // 二进制是插件本身
//            return NO;
//        } else {
//            // 二进制是app
//            return YES;
//        }
//    } else {
//        // 二进制是系统或者越狱插件
//        return NO;
//    }
//}
@end
