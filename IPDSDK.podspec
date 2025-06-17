#
# Be sure to run `pod lib lint IPDSDK_Pods.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'IPDSDK'
  s.version          = '2.0.2.1'
  s.summary          = 'IPDSDK广告'
# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!
 
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/hzzhongjian/IPDSDK.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'hzzhongjian' => 'opentwo@hzzhongjian.cn' }
  s.source           = { :git => 'https://github.com/hzzhongjian/IPDSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  s.ios.deployment_target = '11.0'
  s.platform     = :ios, "11.0"
  
  #依赖的系统frameworks
  s.frameworks = 'UIKit','Foundation','StoreKit','MobileCoreServices','WebKit','MediaPlayer','CoreMedia','CoreLocation','AVFoundation','CoreTelephony','SystemConfiguration','AdSupport','CoreMotion','Accelerate','QuartzCore','Security','ImageIO','CFNetwork','CoreGraphics','SafariServices'
  s.weak_frameworks = 'AppTrackingTransparency'
  #依赖的系统静态库
  #z表示libz.tdb,后缀不需要,lib开头的省略lib
  s.libraries = 'resolv.9','c++','z','sqlite3','bz2','xml2','c++abi','sqlite3.0','iconv'
  # s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64', 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386,arm64' }
  
#  valid_archs = ['armv7', 'i386', 'x86_64', 'arm64']
#  s.pod_target_xcconfig = {
#    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
#  }
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.default_subspecs = 'IPDSDKModuleGDT','IPDSDKModuleCSJ','IPDSDKModuleDSP','IPDSDKModuleSIG','IPDSDKModuleBD','IPDSDKModuleBeiZi','IPDSDKModuleTanX','IPDSDKModuleKS','IPDSDKModuleTaKu','IPDSDKModuleJiaJi','IPDSDKModuleWanJia'
  
    s.subspec 'IPDAdSDK' do |ss|
        ss.vendored_frameworks = 'IPDSDK/IPDAdSDK/*.framework'
        ss.preserve_paths = 'IPDSDK/IPDAdSDK/*.framework'
        ss.resource = 'IPDSDK/IPDAdSDK/*.bundle'
    end

    ### GDT适配器兼容版
    s.subspec 'IPDSDKModuleGDTCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleGDT/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end
  
    ### GDT适配器
    s.subspec 'IPDSDKModuleGDT' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleGDT/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'GDTMobSDK', '~> 4.15.22'
        # 以下版本可以导入4.15.10
    end
  
    ### 穿山甲适配器兼容版
    s.subspec 'IPDSDKModuleCSJCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleCSJ/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end
  
    ### 穿山甲适配器
    s.subspec 'IPDSDKModuleCSJ' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleCSJ/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'Ads-CN-Beta'
        ss.dependency 'Ads-CN-Beta/CSJMediation'
        ss.dependency 'Ads-CN-Beta/BUAdSDK'
    end

    ### 穿山甲短剧SDK依赖
    ### source 'https://github.com/CocoaPods/Specs.git'
    ### source 'https://github.com/volcengine/volcengine-specs.git'
    s.subspec 'IPDSDKModuleCSJPlayletSDK' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleCSJ/playlet/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        # ss.dependency 'TTSDKFramework/Player-SR', '1.42.3.4-premium'
        # ss.dependency 'PangrowthX/shortplay', '2.7.0.1'
    end    
  
    ### 快手适配器兼容版
    s.subspec 'IPDSDKModuleKSCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleKS/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end
  
    ### 快手适配器
    s.subspec 'IPDSDKModuleKS' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleKS/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ##    ss.dependency 'KSAdSDK', '3.3.69'
        ss.vendored_frameworks  = 'IPDSDK/IPDSDKModuleKS/KSAdSDK/*.xcframework'
        ss.preserve_paths       = 'IPDSDK/IPDSDKModuleKS/KSAdSDK/*.xcframework'
    end

    ### MTG适配器
    s.subspec 'IPDSDKModuleMTG' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleMTG/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'MintegralAdSDK', '~> 7.0'
        ss.dependency 'MintegralAdSDK/RewardVideoAd'
        ss.dependency 'MintegralAdSDK/BannerAd'
        ss.dependency 'MintegralAdSDK/SplashAd'
        ss.dependency 'MintegralAdSDK/InterstitialAd'
        ss.dependency 'MintegralAdSDK/NativeAdvancedAd'
    end

    ### DSP适配器
    s.subspec 'IPDSDKModuleDSP' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleDSP/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'DSPSDK'
    end
 
    ### SIG适配器兼容版
    s.subspec 'IPDSDKModuleSIGCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleSIG/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end

    ### SIG适配器
    s.subspec 'IPDSDKModuleSIG' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleSIG/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'SigmobAd-iOS', '~> 4.19.0'
    end

    # ### 谷歌适配器
    # s.subspec 'IPDSDKModuleGoogle' do |ss|
    #     ss.vendored_libraries = 'IPDSDK/IPDSDKModuleGoogle/*.a'
    #     ss.dependency 'IPDSDK/IPDAdSDK'
    #     ss.dependency 'Google-Mobile-Ads-SDK'
    # end
 
    ### 百度适配器兼容版   
    s.subspec 'IPDSDKModuleBDCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleBD/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.resource           = 'IPDSDK/IPDSDKModuleBD/*.bundle'
    end

    ### 百度适配器   
    s.subspec 'IPDSDKModuleBD' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleBD/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'BaiduMobAdSDK', '~> 5.37'
        ss.resource           = 'IPDSDK/IPDSDKModuleBD/*.bundle'
    end
 
    ### 穿山甲海外适配器
    s.subspec 'IPDSDKModulePangle' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModulePangle/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'Ads-Global'
    end

    ### 倍孜适配器兼容版
    s.subspec 'IPDSDKModuleBeiZiCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleBeiZi/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end

    ### 倍孜适配器
    s.subspec 'IPDSDKModuleBeiZi' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleBeiZi/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'BeiZiSDK-iOS/BeiZiSDK-iOS', '~> 4.90'
    end

    ###Tanx适配器兼容版  
    s.subspec 'IPDSDKModuleTanXCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleTanX/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end

    ### Tanx适配器
    s.subspec 'IPDSDKModuleTanX' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleTanX/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        # 可以把TanX的依赖更换为pod管理
        #    ss.dependency 'TanxSDK', '~> 3.5.3'
        ss.vendored_frameworks  = 'IPDSDK/IPDSDKModuleTanX/*.framework'
        ss.resource             = 'IPDSDK/IPDSDKModuleTanX/*.bundle'
        ss.preserve_paths       = 'IPDSDK/IPDSDKModuleTanX/*.framework'
    end

    ###趣盟适配器兼容版
    s.subspec 'IPDSDKModuleQMCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleQM/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end

    ###趣盟适配器
    s.subspec 'IPDSDKModuleQM' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleQM/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.vendored_frameworks = 'IPDSDK/IPDSDKModuleQM/QMAdSDK/*.xcframework'
        ss.preserve_paths      = 'IPDSDK/IPDSDKModuleQM/QMAdSDK/*.xcframework'
        ss.dependency 'AFNetworking'
        ss.dependency 'YYWebImage'
        ss.dependency 'YYImage/WebP'
    end

    ###章鱼适配器兼容版
    s.subspec 'IPDSDKModuleOCTOPUSCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleOCTOPUS/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end
  
    ###章鱼适配器
    s.subspec 'IPDSDKModuleOCTOPUS' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleOCTOPUS/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'OctopusSDK'
    end

    ###章鱼定制包适配器
    s.subspec 'IPDSDKModuleWanJia' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleWanJia/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.vendored_frameworks  = 'IPDSDK/IPDSDKModuleWanJia/WanJiaAdSDK/*.xcframework'
        ss.preserve_paths       = 'IPDSDK/IPDSDKModuleWanJia/WanJiaAdSDK/*.xcframework'
        ss.resource             = 'IPDSDK/IPDSDKModuleWanJia/WanJiaAdSDK/Assets/*.bundle'
    end

    ###移卡适配器兼容版
    s.subspec 'IPDSDKModuleYKCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleYK/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end

    ###移卡适配器
    s.subspec 'IPDSDKModuleYK' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleYK/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.vendored_frameworks  = 'IPDSDK/IPDSDKModuleYK/*.framework'
        ss.preserve_paths       = 'IPDSDK/IPDSDKModuleYK/*.framework'
    end
    
    ###奇运适配器兼容版
    s.subspec 'IPDSDKModuleJiaJiCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleJiaJi/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end

    ###奇运适配器
    s.subspec 'IPDSDKModuleJiaJi' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleJiaJi/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.vendored_frameworks  = 'IPDSDK/IPDSDKModuleJiaJi/*.xcframework'
        ss.preserve_paths       = 'IPDSDK/IPDSDKModuleJiaJi/*.xcframework'
    end

    ###TaKu适配器兼容版
    s.subspec 'IPDSDKModuleTaKuCompatible' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleTaKu/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
    end

    ###TaKu适配器
    s.subspec 'IPDSDKModuleTaKu' do |ss|
        ss.vendored_libraries = 'IPDSDK/IPDSDKModuleTaKu/*.a'
        ss.dependency 'IPDSDK/IPDAdSDK'
        ss.dependency 'AnyThinkiOS', '~> 6.4.75'
    end
end