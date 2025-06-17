//
//  AppDelegate.m
//  IPDSDKDemo
//
//  Created by 麻明康 on 2025/6/6.
//

#import "AppDelegate.h"
#import "IPDHomeViewController.h"
#import <IPDSDK/IPDSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    IPDHomeViewController *homeVC = [[IPDHomeViewController alloc]init];
    UINavigationController *nc = [[UINavigationController alloc] initWithRootViewController:homeVC];
    nc.navigationBar.backgroundColor = [UIColor whiteColor];
    self.window.rootViewController = nc;
    [self.window makeKeyAndVisible];
    
    
    [IPDAdSDK setLogLevel:IPDAdSDKLogLevelDebug];
    [IPDAdSDK registerAppId:@"zj_20201014iOSDEMO"];
    
    return YES;
}



@end
