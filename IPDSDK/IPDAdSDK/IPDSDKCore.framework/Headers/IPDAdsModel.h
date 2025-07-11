//
//  IPDAdsModel.h
//  IPDSDKCore
//
//  Created by Rare on 2022/2/23.
//

#import <Foundation/Foundation.h>
#import <IPDSDKCore/IPDAdUnionItemModel.h>

NS_ASSUME_NONNULL_BEGIN

@class IPDAdPositionModel;

@interface IPDAdsModel : NSObject

@property (nonatomic, copy) NSArray <IPDAdPositionModel *>*ads;

- (void)parseAds:(NSArray *)ads;

@end

// 广告配置数据model，对应ads数据模型
@interface IPDAdPositionModel : NSObject

@property (nonatomic, assign) BOOL is_service;
//@property (nonatomic, assign) BOOL is_cdn;
@property (nonatomic, assign) BOOL is_pd_cache;
@property (nonatomic, assign) BOOL is_verify_params;
@property (nonatomic, assign) NSInteger reward_ver;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *zj_adID; // 广告位
@property (nonatomic, copy) NSArray <IPDAdUnionItemModel *>*items_pd;
@property (nonatomic, copy) NSArray <IPDAdUnitModel *>*items_hb_array;

/// 流量组分组
@property (nonatomic, copy) NSString *title;
/// 流量组id
@property (nonatomic, assign) long pos_template_id;

//@property (nonatomic, copy) NSArray <AdTemplatesModel *>*templates;

- (NSArray <IPDAdUnionItemModel *> *)parseItems:(NSArray *)items;

@end




NS_ASSUME_NONNULL_END
