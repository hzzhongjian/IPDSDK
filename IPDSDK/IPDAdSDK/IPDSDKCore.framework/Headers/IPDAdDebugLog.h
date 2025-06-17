//
//  IPDAdDebugLog.h
//  IPDSDKCore
//
//  Created by Rare on 2022/2/24.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>
#import <IPDSDKCore/IPDSDKDefines.h>

NS_ASSUME_NONNULL_BEGIN

#define IPD_BaseLog(level, frmt, ...) [IPDAdDebugLog level##LogWithFormat:@"[IPDSDK-%@]-[%s]:\n%@", IPDSDKVersion, #level , [NSString stringWithFormat:frmt, ##__VA_ARGS__]];

#define IPD_DebugLog(frmt, ...) IPD_BaseLog(debug,frmt, ##__VA_ARGS__)

#define IPD_ErrorLog(frmt, ...) IPD_BaseLog(error,frmt, ##__VA_ARGS__)

#define IPD_WarningLog(frmt, ...) IPD_BaseLog(warning,frmt, ##__VA_ARGS__)

@interface IPDAdDebugLog : NSObject

+ (void)debugLogWithFormat:(NSString *)format, ...;

+ (void)errorLogWithFormat:(NSString *)format, ...;

+ (void)warningLogWithFormat:(NSString *)format, ...;

@end

NS_ASSUME_NONNULL_END
