//
//  AWMCustomAdapter.h
//  WindMillSDK
//
//  Created by Codi on 2022/10/13.
//

@class AWMMediaBidResult;
@class AWMParameter;

@protocol AWMCustomAdapter <NSObject>

@optional

/// 当接入服务端竞价时，需要返回对应adn竞价需要的参数
/// @warning 1. 自定义适配器不支持；
- (NSDictionary *)biddingWithParams:(AWMParameter *)params;

// 回调客户端竞价结果，比价成功时回传成功，比价失败、返回超时或价格低于竞价底价时回传失败
/// @param result bid结果对象
/// @warning 1.adn广告load失败不触发该回调，如需回传adn竞价结果，请在load失败处自行处理
///          2.信息流加载多条会触发多次，返回每条比价结果
///          3.只有胜出时回传价格，失败时不回传胜出方
- (void)didReceiveBidResult:(AWMMediaBidResult *)result;

/// 在适配器被释放前
- (void)destory;

@end
