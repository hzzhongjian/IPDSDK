//
//  IPDFullScreenVideoAdAdapter.h
//  IPDSDKCore
//
//  Created by Rare on 2021/4/27.
//

#import <IPDSDKCore/IPDTierAdAdapter.h>
#import <UIKit/UIKit.h>
#import <IPDSDKCore/IPDSDKAdEnum.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDFullScreenVideoAdAdapter;

@protocol IPDfullScreenVideoAdAdapterDelegate <NSObject>

- (void)ipd_fullScreenVideoAdapterDidLoad:(IPDFullScreenVideoAdAdapter*)adapter;

- (void)ipd_fullScreenVideoAdapterDidLoadFail:(IPDFullScreenVideoAdAdapter*)adapter error:(NSError * __nullable)error;

- (void)ipd_fullScreenVideoAdapterDidPresentScreen:(IPDFullScreenVideoAdAdapter*)adapter;

- (void)ipd_fullScreenVideoAdapterDidClick:(IPDFullScreenVideoAdAdapter*)adapter;

- (void)ipd_fullScreenVideoAdapterDidClose:(IPDFullScreenVideoAdAdapter*)adapter;

- (void)ipd_fullScreenVideoAdapterDidFail:(IPDFullScreenVideoAdAdapter*)adapter error:(NSError * __nullable)error;

- (void)ipd_fullScreenVideoAdapter:(IPDFullScreenVideoAdAdapter*)adapter  playerStatus:(IPDMediaPlayerStatus)playerStatus;

- (void)ipd_fullScreenVideoAdapterDetailDidClose:(IPDFullScreenVideoAdAdapter*)adapter;

- (void)ipd_fullScreenVideoAdapterDetailDidPresent:(IPDFullScreenVideoAdAdapter*)adapter;

@end


@interface IPDFullScreenVideoAdAdapter : IPDTierAdAdapter


@property(nonatomic,weak) id<IPDfullScreenVideoAdAdapterDelegate> delegate;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

- (void)presentAdFromRootViewController:(UIViewController*)viewController;

- (void)ipd_fullScreenVideoDidLoad;

- (void)ipd_fullScreenVideoDidLoadFail:(NSError * __nullable)error;

- (void)ipd_fullScreenVideoDidPresentScreen;

- (void)ipd_fullScreenVideoDidClick;

- (void)ipd_fullScreenVideoDidClose;

- (void)ipd_fullScreenVideoDetailDidClose;

- (void)ipd_fullScreenVideoDidFail:(NSError * __nullable)error;

- (void)ipd_fullScreenVideoPlayerStatus:(IPDMediaPlayerStatus)status;

- (void)ipd_fullScreenVideoDetailDidPresent;

@end

NS_ASSUME_NONNULL_END
