//
//  IPDContentPageAdTierLoader.h
//  IPDSDK
//
//  Created by 麻明康 on 2025/1/20.
//  Copyright © 2025 zj. All rights reserved.
//

#import <IPDSDK/IPDSDK.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IPDContentPageAdTierLoaderStateDelegate <NSObject>

/**
* 内容展示
* @param content 内容模型
*/
- (void)ipd_contentPageLoaderDidFullDisplay:(id<IPDContentInfo>)content;
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)ipd_contentPageLoaderDidEndDisplay:(id<IPDContentInfo>)content;
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)ipd_contentPageLoaderDidPause:(id<IPDContentInfo>)content;
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)ipd_contentPageLoaderDidResume:(id<IPDContentInfo>)content;

/// 任务完成回调
- (void)ipd_contentPageLoaderTaskComplete:(id<IPDContentInfo>)content;

@end



@protocol IPDContentPageAdTierLoaderVideoStateDelegate <NSObject>

/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)ipd_contentPageLoaderVideoDidStartPlay:(id<IPDContentInfo>)videoContent;
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)ipd_contentPageLoaderVideoDidPause:(id<IPDContentInfo>)videoContent;
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)ipd_contentPageLoaderVideoDidResume:(id<IPDContentInfo>)videoContent;
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)ipd_contentPageLoaderVideoDidEndPlay:(id<IPDContentInfo>)videoContent isFinished:(BOOL)finished;
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)ipd_contentPageLoaderVideoDidFailedToPlay:(id<IPDContentInfo>)videoContent withError:(NSError *)error;

@end



@interface IPDContentPageAdTierLoader : IPDTierAdLoader

@property (nonatomic, weak) id <IPDContentPageAdTierLoaderStateDelegate> stateDelegate;

@property (nonatomic, weak) id <IPDContentPageAdTierLoaderVideoStateDelegate>videoStateDelegate;

@end

NS_ASSUME_NONNULL_END
