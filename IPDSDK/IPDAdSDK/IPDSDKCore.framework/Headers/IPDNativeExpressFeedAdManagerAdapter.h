//
//  IPDNativeExpressFeedAdManagerAdapter.h
//  IPDSDKCore
//
//  Created by Rare on 2021/3/2.
//

#import <IPDSDKCore/IPDMultipleAdAdapter.h>
#import <IPDSDKCore/IPDNativeExpressFeedAd.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDNativeExpressFeedAdManagerApterDelegate;

@interface IPDNativeExpressFeedAdManagerAdapter : IPDMultipleAdAdapter

@property (nonatomic) CGSize adSize;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

@property (nonatomic, strong) NSArray<IPDNativeExpressFeedAd *> *data;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;


@property (nonatomic,weak) id <IPDNativeExpressFeedAdManagerApterDelegate> delegate;

- (instancetype)initWithAdItemConfig:(IPDAdUnitModel *)adItemConfig size:(CGSize)size;


- (void)loadAdWithCount:(NSInteger)adCount;


- (void)IPDFeed_feedAdsManagerSuccessToLoad:(IPDNativeExpressFeedAdManagerAdapter *)adsManager nativeAds:(NSArray<IPDNativeExpressFeedAd *> *_Nullable)multipleResultObject;

- (void)IPDFeed_feedAdsManager:(IPDNativeExpressFeedAdManagerAdapter *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

@protocol IPDNativeExpressFeedAdManagerApterDelegate <NSObject>

@optional

- (void)IPDFeed_feedAdsManagerSuccessToLoad:(IPDNativeExpressFeedAdManagerAdapter *)adsManager nativeAds:(NSArray<IPDNativeExpressFeedAd *> *_Nullable)multipleResultObject;

- (void)IPDFeed_feedAdsManager:(IPDNativeExpressFeedAdManagerAdapter *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
