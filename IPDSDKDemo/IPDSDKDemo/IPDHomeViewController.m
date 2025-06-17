//
//  IPDHomeViewController.m
//  IPDSDKDemo
//
//  Created by Rare on 2022/3/1.
//  Copyright © 2022 zj. All rights reserved.
//

#import "IPDHomeViewController.h"
#import "IPDHomeTableViewCell.h"
#import <IPDSDK/IPDSDK.h>

@interface IPDHomeViewController ()<UITableViewDataSource,UITableViewDelegate>

@property(nonatomic,strong) UITableView *tableView;

@property(nonatomic,strong) NSMutableDictionary *demoVCDictionary;

@property(nonatomic,strong) NSArray *adTypes;

@end

@implementation IPDHomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = [NSString stringWithFormat:@"IPDSDK Demo -V%@",[IPDAdSDK SDKVersion]];
    
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.offset(kNavigationBarHeight);
        make.left.right.bottom.offset(0);
    }];
    
//    NSString *path = [[NSBundle mainBundle] pathForResource:@"DSPBundle" ofType:@"bundle"];
//    NSBundle *bundle = [NSBundle bundleWithPath:path];
//    UIImage *image = [UIImage imageNamed:@"zj_close_circle_icon.png" inBundle:bundle compatibleWithTraitCollection:nil];
//    UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(100, 100, 200, 200)];
//    imageView.backgroundColor = [UIColor yellowColor];
//    imageView.image = image;
//    [self.view addSubview:imageView];
}


#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return self.adTypes.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    NSArray *rows = self.adTypes[section];
    return rows.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    IPDHomeTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([IPDHomeTableViewCell class])];
    if(!cell){
        cell = [[IPDHomeTableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:NSStringFromClass([IPDHomeTableViewCell class])];
    }
    NSArray *rows = self.adTypes[indexPath.section];
    NSString *keyType = rows[indexPath.row];
    cell.titleLabel.text = keyType;

    UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"ad_icon%ld",(long)indexPath.section]];
    cell.iconImageView.image = image;
    return cell;
}
-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 15;
}



#pragma mark -UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    NSArray *rows = self.adTypes[indexPath.section];
    NSString *keyType = rows[indexPath.row];
    NSString *vcName = self.demoVCDictionary[keyType];
    UIViewController *vc  = [[NSClassFromString(vcName) alloc] init];
    vc.title = keyType;
    [self.navigationController pushViewController:vc animated:YES];
}


- (NSArray*)adTypes{
    if(!_adTypes){
        NSArray *section1 = @[@"开屏",@"激励视频",@"插屏",@"全屏视频",@"Banner"];
        NSArray *section2 = @[@"视频流",@"信息流",@"自渲染"];
        NSArray *section3 = @[@"视频内容列表", @"新视频内容列表",@"视频内容瀑布流",@"视频内容横版"];
        NSArray *section4 = @[@"短剧"];
        NSArray *section5 = @[@"新闻资讯",@"H5页面",@"悬浮广告",@"H5页面JS交互"];
        NSArray *section6 = @[@"微信小程序广告"];
        _adTypes = [NSArray arrayWithObjects:section1, section2, section3,section4,section5,section6, nil];
    }
    return _adTypes;
}

- (NSMutableDictionary *)demoVCDictionary{
    if(!_demoVCDictionary){
        _demoVCDictionary = [NSMutableDictionary dictionaryWithCapacity:0];
        [_demoVCDictionary setValue:@"IPDSplashViewController" forKey:@"开屏"];
        [_demoVCDictionary setValue:@"IPDRewardViewController" forKey:@"激励视频"];
        [_demoVCDictionary setValue:@"IPDInterstitialAdViewController" forKey:@"插屏"];
        [_demoVCDictionary setValue:@"IPDFullScreenVideoViewController" forKey:@"全屏视频"];
        [_demoVCDictionary setValue:@"IPDBannerViewController" forKey:@"Banner"];
        
        [_demoVCDictionary setValue:@"IPDFeedFullVideoViewController" forKey:@"视频流"];
        [_demoVCDictionary setValue:@"IPDFeedAdsViewController" forKey:@"信息流"];
        [_demoVCDictionary setValue:@"IPDNativeAdSelectedViewController" forKey:@"自渲染"];
        
        [_demoVCDictionary setValue:@"IPDContentPageViewController" forKey:@"视频内容列表"];
        [_demoVCDictionary setValue:@"IPDContentPageAdViewController" forKey:@"新视频内容列表"];
        [_demoVCDictionary setValue:@"IPDFeedPageLoadViewController" forKey:@"视频内容瀑布流"];
        [_demoVCDictionary setValue:@"IPDHorizontalFeedPageLoadVC" forKey:@"视频内容横版"];
        [_demoVCDictionary setValue:@"IPDTubePageVC" forKey:@"短剧"];

        [_demoVCDictionary setValue:@"IPDNewsAdViewController" forKey:@"新闻资讯"];
        [_demoVCDictionary setValue:@"IPDH5ViewController" forKey:@"H5页面"];
        [_demoVCDictionary setValue:@"IPDFloatingAdViewController" forKey:@"悬浮广告"];
        [_demoVCDictionary setValue:@"IPDJSBridgeViewController" forKey:@"H5页面JS交互"];
        [_demoVCDictionary setValue:@"IPDMiniParamViewController" forKey:@"微信小程序广告"];

    }
    return _demoVCDictionary;;
}


- (UITableView *)tableView{
    if (!_tableView) {
        _tableView = [[UITableView alloc]initWithFrame:CGRectZero style:UITableViewStyleGrouped];
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.estimatedRowHeight = 0;
        _tableView.estimatedSectionFooterHeight = 0;
        _tableView.estimatedSectionHeaderHeight = 0;
        _tableView.rowHeight = 65;
        _tableView.sectionHeaderHeight = 15;
        _tableView.sectionFooterHeight = 0.1;
        
        
        _tableView.showsVerticalScrollIndicator = NO;
        _tableView.showsHorizontalScrollIndicator = NO;
        _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    }
    return _tableView;
}
@end
