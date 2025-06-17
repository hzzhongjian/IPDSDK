//
//  IPDFeedFullVideoShowViewController.m
//  IPDSDKDemo
//
//  Created by Robin on 2020/10/19.
//  Copyright © 2020 zj. All rights reserved.
//

#import "IPDFeedFullVideoShowViewController.h"
#import "IPDFullScreenCell.h"
#import "IPDFeedFullVideoAdCell.h"
#import <IPDSDK/IPDFeedFullVideoProvider.h>
#import "IPDLogView.h"

@interface IPDFeedFullVideoShowViewController ()<UITableViewDataSource,UITableViewDelegate,IPDFeedFullVideoProviderDelegate>
@property (strong, nonatomic) UITableView *tableView;

@property(nonatomic,strong) IPDFeedFullVideoProvider *adProvider;
@property (nonatomic, copy) NSArray *dataSource;
@property (nonatomic, strong)IPDLogView *logView;
@end

@implementation IPDFeedFullVideoShowViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self.navigationController setNavigationBarHidden:YES animated:NO];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.tableView];
    
    UIButton *closeButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [closeButton setImage:[UIImage imageNamed:@"zj_h5_back"] forState:UIControlStateNormal];
    [closeButton setBackgroundColor:[UIColor whiteColor]];
    closeButton.frame = CGRectMake(6, 44, 44, 44);
    closeButton.layer.cornerRadius = 22;
    __weak typeof(self) weakSelf = self;
    [closeButton clickHandle:^(UIButton *button) {
        [weakSelf.navigationController popViewControllerAnimated:NO];
    }];
    
    [self.view addSubview:closeButton];
    
    NSMutableArray *datas = [NSMutableArray array];
    for (NSInteger i =0 ; i <= 5; i++) {
        [datas addObject:@"App tableViewcell"];
    }
    self.dataSource = [datas copy];
    
    self.logView = [[IPDLogView alloc]init];
    [self.view addSubview:self.logView];
    [self.logView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.offset(0);
        make.height.mas_equalTo(100);
    }];
    
    [self loadData];
}

-(void)clickPlayBtn:(UIButton *)btn{
    UITableViewCell *cell = [self.tableView visibleCells].firstObject;
    for (UIView *sV in cell.contentView.subviews) {
        if ([sV isKindOfClass:[IPDFeedFullVideoView class]]) {
            if (btn.selected) {
                [((IPDFeedFullVideoView *)sV) play];
            }else{
                [((IPDFeedFullVideoView *)sV) pause];
            }
            
        }
    }
    btn.selected = !btn.selected;
}

- (void)loadData{
    [self.logView logMessage:@"loadAd"];
    if(!self.adProvider){
        self.adProvider = [[IPDFeedFullVideoProvider alloc] initWithPlacementId:self.placementId];
        self.adProvider.delegate = self;
        self.adProvider.adSize = CGSizeMake(kScreenWidth, kScreenHeight);
    }
    [self.adProvider loadAd:6];
    
}

#pragma mark IPDFeedFullVideoProviderDelegate
/**
 * 广告加载成功
 */
- (void)ipd_feedFullVideoProviderLoadSuccess:(IPDFeedFullVideoProvider *)provider views:(NSArray<__kindof IPDFeedFullVideoView *> *)views{
    [self.logView logMessage:[NSString stringWithFormat:@"feedFullVideoProviderLoadSuccess: %ld",views.count]];
    [self.logView logMessage:[self.adProvider valueForKey:@"logString"]];
    if (views.count) {
        NSMutableArray *dataSources = [NSMutableArray arrayWithCapacity:0];
        [views enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            IPDFeedFullVideoView *videoView = (IPDFeedFullVideoView *)obj;
            videoView.rootViewController = self;
            // important: 此处会进行WKWebview的渲染，建议一次最多预加载三个广告，如果超过3个会很大概率导致WKWebview渲染失败。
            [videoView render];
            [dataSources addObject:videoView];
            [dataSources addObject:@"App tableViewcell"];
        }];
        self.dataSource = [dataSources copy];
    }
    [self.tableView reloadData];
}



/**
* 广告加载失败
*/
- (void)ipd_feedFullVideoProviderLoadFail:(IPDFeedFullVideoProvider *)provider error:(NSError *_Nullable)error{
    [self.logView logMessage:[NSString stringWithFormat:@"feedFullVideoProviderLoadFail: %@",error]];
    [self.logView logMessage:[self.adProvider valueForKey:@"logString"]];
    NSArray *errors =  [self.adProvider getFillFailureMessages];
    [self.logView logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
}

/**
 * 广告渲染成功, IPDFeedFullVideoView.size.height has been updated
 */
- (void)ipd_feedFullVideoAdViewRenderSuccess:(IPDFeedFullVideoProvider *)provider view:(IPDFeedFullVideoView*) adView{
    
}

/**
 * 广告渲染失败
 */
- (void)ipd_feedFullVideoAdViewRenderFail:(IPDFeedFullVideoProvider *)provider view:(IPDFeedFullVideoView*) adView error:(NSError *_Nullable)error{
    [self.logView logMessage:[NSString stringWithFormat:@"feedFullVideoAdViewRenderFail: %@",error]];
}

/**
 * 广告曝光回调
 */
- (void)ipd_feedFullVideoAdViewWillShow:(IPDFeedFullVideoProvider *)provider view:(IPDFeedFullVideoView*) adView{
    [self.logView logMessage:[NSString stringWithFormat:@"feedFullVideoAdViewWillShow"]];
}

/**
视频广告播放状态更改回调
*/
- (void)ipd_feedFullVideoAdViewStateDidChanged:(IPDFeedFullVideoProvider *)provider view:(IPDFeedFullVideoView*) adView state:(IPDMediaPlayerStatus)playerState{
    
}

/**
视频广告播放完毕
*/
- (void)ipd_feedFullVideoAdViewPlayerDidPlayFinish:(IPDFeedFullVideoProvider *)provider view:(IPDFeedFullVideoView*) adView{

}

/**
 * 广告点击回调
 */
- (void)ipd_feedFullVideoAdViewDidClick:(IPDFeedFullVideoProvider *)provider view:(IPDFeedFullVideoView*) adView{
    
}

/**
* 广告详情页面即将展示回调
*/
- (void)ipd_feedFullVideoAdViewDetailViewWillPresentScreen:(IPDFeedFullVideoProvider *)provider view:(IPDFeedFullVideoView*) adView{
    
}

/**
 *广告详情页关闭回调
 */
- (void)ipd_feedFullVideoAdViewDetailViewClosed:(IPDFeedFullVideoProvider *)provider view:(IPDFeedFullVideoView*) adView{
    
}

#pragma mark --- tableView dataSource&delegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSUInteger index = indexPath.row;
    id model = self.dataSource[index];
    if ([model isKindOfClass:[IPDFeedFullVideoView class]]) {
        UITableViewCell *cell = nil;
        cell = [self.tableView dequeueReusableCellWithIdentifier:@"IPDFeedFullVideoAdCell" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        // 重用BUNativeExpressAdView，先把之前的广告试图取下来，再添加上当前视图
        UIView *subView = (UIView *)[cell.contentView viewWithTag:1000];
        if ([subView superview]) {
            [subView removeFromSuperview];
        }
        UIView *view = model;
        view.tag = 1000;
        [cell.contentView addSubview:view];
        return cell;
    } else {
        IPDFullScreenCell *cell = nil;
        cell = [tableView dequeueReusableCellWithIdentifier:@"IPDFullScreenCell" forIndexPath:indexPath];
        return cell;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [UIScreen mainScreen].bounds.size.height;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
}

#pragma mark Property

-(UITableView*) tableView{
    if(!_tableView){
        _tableView = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        _tableView.pagingEnabled = YES;
        #if defined(__IPHONE_11_0) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_11_0
            if ([_tableView respondsToSelector:@selector(setContentInsetAdjustmentBehavior:)]) {
                if (@available(iOS 11.0, *)) {
                    _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
                    _tableView.estimatedRowHeight = 0;
                }
            }
        #else
            self.automaticallyAdjustsScrollViewInsets = NO;
        #endif
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [_tableView registerClass:[IPDFullScreenCell class] forCellReuseIdentifier:@"IPDFullScreenCell"];
        [_tableView registerClass:[IPDFeedFullVideoAdCell class] forCellReuseIdentifier:@"IPDFeedFullVideoAdCell"];
    }
    return _tableView;
}


@end
