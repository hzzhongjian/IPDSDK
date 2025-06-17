//
//  ZJNativeAdViewController.m
//  ZJSDKDemo
//
//  Created by Rare on 2021/3/30.
//  Copyright © 2021 zj. All rights reserved.
//

#import "IPDNativeAdViewController.h"
#import <IPDSDK/IPDNativeAd.h>
#import "IPDNativeAdImageTableViewCell.h"
#import "IPDNativeAdAtlasImageTableViewCell.h"
#import "IPDNativeAdVideoTableViewCell.h"
#import "IPDLogView.h"
@interface IPDNativeAdViewController ()<IPDNativeAdDelegate,UITableViewDataSource,UITableViewDelegate,IPDNativeAdViewDelegate, UIGestureRecognizerDelegate>


@property (strong, nonatomic) UITableView *tableView;

@property (nonatomic,strong)IPDNativeAd *nativeAd;

@property (nonatomic,strong)NSMutableArray <IPDNativeAdObject *>*dataArray;

@property (nonatomic, strong)IPDLogView *logView;
@end

@implementation IPDNativeAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dataArray = [NSMutableArray array];
    self.view.backgroundColor = [UIColor whiteColor];
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
    
    self.nativeAd = [[IPDNativeAd alloc] initWithPlacementId:self.adId];
    self.nativeAd.delegate = self;
    self.nativeAd.imgSize = IPDProposalSize_Feed690_388;
    [self.nativeAd loadAdWithCount:1];
    

}


-(void)loadAd{
    [self.nativeAd loadAdWithCount:1];
}


- (void)ipd_nativeAdLoaded:(NSArray<IPDNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error{
    if (!error &&multipleResultObject.count > 0) {
        [self.logView logMessage:[NSString stringWithFormat:@"nativeAdDidLoaded: %ld",multipleResultObject.count]];
        [self.dataArray addObjectsFromArray:multipleResultObject];
        [self.tableView reloadData];
        
    }else{
        [self.logView logMessage:[NSString stringWithFormat:@"nativeAdDidError: %@",error]];
        NSLog(@"自渲染错误回调:%@",error);
    }
    [self.logView logMessage:[self.nativeAd valueForKey:@"logString"]];
}

#pragma mark  - Property

-(UITableView*) tableView{
    if(!_tableView){
        
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, kNavigationBarHeight+4, kScreenWidth, kScreenHeight-kNavigationBarHeight-4)];
        _tableView.backgroundColor = [[UIColor grayColor]colorWithAlphaComponent:0.6];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        _tableView.estimatedRowHeight = 0;
        _tableView.estimatedSectionFooterHeight = 0;
        _tableView.estimatedSectionHeaderHeight = 0;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        
        [_tableView registerClass:[IPDNativeAdImageTableViewCell class] forCellReuseIdentifier:NSStringFromClass(IPDNativeAdImageTableViewCell.class)];
        [_tableView registerClass:[IPDNativeAdAtlasImageTableViewCell class] forCellReuseIdentifier:NSStringFromClass(IPDNativeAdAtlasImageTableViewCell.class)];
        [_tableView registerClass:[IPDNativeAdVideoTableViewCell class] forCellReuseIdentifier:NSStringFromClass(IPDNativeAdVideoTableViewCell.class)];
    }
    
    return _tableView;
}


#pragma mark - UITableViewDataSource

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataArray.count;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    IPDNativeAdObject  *object =  self.dataArray[indexPath.row];
    
    if (object.materialType == IPDAdMaterialTypeVideo) {
        return [IPDNativeAdVideoTableViewCell cellHeightWithUnifiedNativeAdDataObject:object];
    } else if (object.materialType == IPDAdMaterialTypeAtlas){
        return [IPDNativeAdAtlasImageTableViewCell cellHeightWithUnifiedNativeAdDataObject:object];
    }else {
        return [IPDNativeAdImageTableViewCell cellHeightWithUnifiedNativeAdDataObject:object];
    }
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    IPDNativeAdObject *object =  self.dataArray[indexPath.row];
    if (object.materialType == IPDAdMaterialTypeVideo) {
        IPDNativeAdVideoTableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(IPDNativeAdVideoTableViewCell.class) forIndexPath:indexPath];
        [cell setupWithUnifiedNativeAdDataObject:object delegate:self vc:self];
        return cell;
    } else if (object.materialType == IPDAdMaterialTypeAtlas){
        IPDNativeAdAtlasImageTableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(IPDNativeAdAtlasImageTableViewCell.class) forIndexPath:indexPath];
        [cell setupWithUnifiedNativeAdDataObject:object delegate:self vc:self];
        return cell;
    }else {
        IPDNativeAdImageTableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass(IPDNativeAdImageTableViewCell.class) forIndexPath:indexPath];
        [cell setupWithUnifiedNativeAdDataObject:object delegate:self vc:self];
        return cell;
    }
    
    
}

-(void)dealloc{
    
}
#pragma mark - IPDNativeAdViewDelegate
//广告曝光回调
-(void)ipd_nativeAdViewWillExpose:(UIView *)nativeAdView{
    NSLog(@"======%s",__FUNCTION__);
    NSLog(@"ecpm = %ld", self.nativeAd.eCPM);
    [self.logView logMessage:[NSString stringWithFormat:@"nativeAdViewWillExpose"]];
}
//广告点击回调
-(void)ipd_nativeAdViewDidClick:(UIView *)nativeAdView{
    NSLog(@"======%s",__FUNCTION__);
    [self.logView logMessage:[NSString stringWithFormat:@"nativeAdViewDidClick"]];
}
//广告详情页关闭回调
-(void)ipd_nativeAdDetailViewClosed:(UIView *)nativeAdView{
    NSLog(@"======%s",__FUNCTION__);
    [self.logView logMessage:[NSString stringWithFormat:@"nativeAdDetailViewClosed"]];
}
//广告详情页面即将展示回调
-(void)ipd_nativeAdDetailViewWillPresentScreen:(UIView *)nativeAdView{
    NSLog(@"======%s",__FUNCTION__);
    [self.logView logMessage:[NSString stringWithFormat:@"nativeAdDetailViewWillPresentScreen"]];
}
//- (void)ipd_nativeAdViewShowError:(IPDNativeAdView *)nativeAdView error:(NSError *)error
//{
//    NSLog(@"======%s==%@",__FUNCTION__, error.userInfo);
//}

@end
