//
//  ZJNativeExpressAdsViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDNativeExpressAdsViewController.h"
#import <IPDSDK/IPDNativeExpressFeedAdManager.h>
#import "IPDNativeExpressAdTableViewCell.h"
#import "IPDLogView.h"
@interface IPDNativeExpressAdsViewController ()<UITableViewDelegate,UITableViewDataSource,IPDNativeExpressFeedAdManagerDelegate,IPDNativeExpressFeedAdDelegate>

@property (nonatomic,strong)UITableView *tableView;

@property (nonatomic,strong)IPDNativeExpressFeedAdManager *feedAdManager;

@property (nonatomic,strong)NSMutableArray *dataArray;
@property (nonatomic,strong)NSArray <IPDNativeExpressFeedAd *>*adArray;

@property (nonatomic, strong)IPDLogView *logView;
@end

@implementation IPDNativeExpressAdsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    UIButton *refreshBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [refreshBtn setTitle:@"刷新广告" forState:UIControlStateNormal];
    [refreshBtn setBackgroundColor:[UIColor brownColor]];
    [refreshBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [refreshBtn addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:refreshBtn];
    [refreshBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.mas_equalTo(0);
        make.top.mas_equalTo(self.navigationController.navigationBar.frame.size.height+[UIApplication sharedApplication].statusBarFrame.size.height);
        make.height.mas_equalTo(40);
    }];
    
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(refreshBtn.mas_bottom);
        make.left.right.bottom.mas_equalTo(0);
    }];
    
    self.logView = [[IPDLogView alloc]init];
    [self.view addSubview:self.logView];
    [self.logView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.offset(0);
        make.height.mas_equalTo(100);
    }];
    
    [self loadAd];
}

-(void)loadAd{
    [self.logView logMessage:@"loadAd"];
    if (!_feedAdManager) {
        _feedAdManager = [[IPDNativeExpressFeedAdManager alloc] initWithPlacementId:self.adId size:CGSizeMake(self.tableView.frame.size.width, 300)]; // csj的banner需要固定高度
        _feedAdManager.delegate = self;
        _feedAdManager.mutedIfCan = YES;
        _feedAdManager.rootViewController = self;
    }
    [_feedAdManager loadAdDataWithCount:2];
}


#pragma mark - IPDNativeExpressFeedAdManagerDelegate
-(void)IPD_nativeExpressFeedAdManagerSuccessToLoad:(IPDNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<IPDNativeExpressFeedAd *> *)multipleResultObject{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdManagerSuccessToLoad: %ld",multipleResultObject.count]];
    [self.logView logMessage:[self.feedAdManager valueForKey:@"logString"]];
    //不要保存太多广告，需要在合适的时机手动释放不用的，否则内存会过大
//    if (self.adArray.count > 0) {
//        for (IPDNativeExpressFeedAd *feedAd in self.adArray) {
//            [self.dataArray removeObject:feedAd];
//        }
//    }
    for (int i = 0; i<multipleResultObject.count; i++) {
        IPDNativeExpressFeedAd *feedAd = multipleResultObject[i];
        feedAd.rootViewController = self;
        feedAd.delegate = self;
        [feedAd render];
        NSLog(@"获取到的ECPM为-------%li",[feedAd eCPM]);
        NSInteger index = i*3;
        if (index >= self.dataArray.count) {
            [self.dataArray addObject:feedAd];
        }else{
            [self.dataArray insertObject:feedAd atIndex:index];
        }
    }
    self.adArray = multipleResultObject;
    [self.tableView reloadData];
    
}

-(void)IPD_nativeExpressFeedAdManager:(IPDNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *)error{
    [self.logView logMessage:[NSString stringWithFormat:@"FeedAdDidFailWithError: %@",error]];
    [self.logView logMessage:[self.feedAdManager valueForKey:@"logString"]];
    NSArray *errors =  [self.feedAdManager getFillFailureMessages];
    [self.logView logMessage:[NSString stringWithFormat:@"报错信息:%@",errors.count > 0?errors:@"无"]];
}

#pragma mark - IPDNativeExpressFeedAdDelegate
/**
 * 广告渲染成功
 */
- (void)IPD_nativeExpressFeedAdRenderSuccess:(IPDNativeExpressFeedAd *)feedAd{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdRenderSuccess"]];
    [self.tableView reloadData];
}
/**
 * 广告渲染失败
 */
- (void)IPD_nativeExpressFeedAdRenderFail:(IPDNativeExpressFeedAd *)feedAd{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdRenderFail"]];
    
    [self.dataArray removeObject:feedAd];
    [self.tableView reloadData];
}

- (void)IPD_nativeExpressFeedAdViewWillShow:(IPDNativeExpressFeedAd *)feedAd{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdViewShow"]];
    NSLog(@"ecpm = %ld", (long)_feedAdManager.eCPM);
}
- (void)IPD_nativeExpressFeedAdDidClick:(IPDNativeExpressFeedAd *)feedAd{
    NSLog(@"======%s",__FUNCTION__);
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdDidClick"]];
}
- (void)IPD_nativeExpressFeedAdDislike:(IPDNativeExpressFeedAd *)feedAd{
    [self.dataArray removeObject:feedAd];
    [self.tableView reloadData];
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdDislike"]];
    NSLog(@"======%s",__FUNCTION__);
}
- (void)IPD_nativeExpressFeedAdDidShowOtherController:(IPDNativeExpressFeedAd *)nativeAd{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdDidShowOtherController"]];
    NSLog(@"======%s",__FUNCTION__);
}
- (void)IPD_nativeExpressFeedAdDidCloseOtherController:(IPDNativeExpressFeedAd *)nativeAd{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdDidCloseOtherController"]];
    NSLog(@"======%s",__FUNCTION__);
}

- (void)IPD_nativeExpressFeedAdViewShowError:(IPDNativeExpressFeedAd *)feedAd error:(NSError *)error
{
    [self.logView logMessage:[NSString stringWithFormat:@"nativeExpressFeedAdViewShowError"]];
    NSLog(@"======%s==%@",__FUNCTION__, error.userInfo);
}

#pragma mark - UITableViewDataSource

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataArray.count;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    id object =  self.dataArray[indexPath.row];
    if ([object isKindOfClass:[IPDNativeExpressFeedAd class]]) {
        CGFloat height = ((IPDNativeExpressFeedAd *)object).feedView.frame.size.height;
        return height;
    }else{
        return 44;
    }
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
   UITableViewCell *cell = nil;
    id object =  self.dataArray[indexPath.row];
    if ([object isKindOfClass:[IPDNativeExpressFeedAd class]]) {
        cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(IPDNativeExpressAdTableViewCell.class) forIndexPath:indexPath];
        [(IPDNativeExpressAdTableViewCell *)cell refreshWithAd:(IPDNativeExpressFeedAd *)object];
    }else{
        cell = [self.tableView dequeueReusableCellWithIdentifier:@"IPDDemoNormalCell" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.backgroundColor = [UIColor whiteColor];
        cell.textLabel.textColor = [UIColor blackColor];
        cell.textLabel.font = [UIFont boldSystemFontOfSize:16];
        cell.textLabel.text = (NSString *)object;
    }

   return cell;
}
#pragma mark  - Property

-(UITableView*) tableView{
    if(!_tableView){
        _tableView = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        if (@available(iOS 11.0, *)) {
            _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        }else{
            self.automaticallyAdjustsScrollViewInsets = NO;
        }
//        _tableView.estimatedRowHeight = 0;
        _tableView.estimatedSectionFooterHeight = 0;
        _tableView.estimatedSectionHeaderHeight = 0;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        
        [_tableView registerClass:[IPDNativeExpressAdTableViewCell class] forCellReuseIdentifier:NSStringFromClass(IPDNativeExpressAdTableViewCell.class)];
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"IPDDemoNormalCell"];
    }
    
    return _tableView;
}

-(NSMutableArray *)dataArray{
    if (!_dataArray) {
        NSMutableArray *array = [NSMutableArray array];
        for (int i = 0 ; i <= 10; i++) {
            NSString *string = [NSString stringWithFormat:@"数据_%d",i];
            [array addObject:string];
        }
        _dataArray = array;
    }
    return _dataArray;
}

@end
