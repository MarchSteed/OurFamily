//
//  PublicDefine.h
//  OurFamily
//
//  Created by MarchSteed on 2018/7/4.
//  Copyright © 2018年 WingMarch. All rights reserved.
//
//layer.masksToBounds
//layer.cornerRadius
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
//#import "Masonry.h"
//#import "RequestManager.h"
//#import "LoginInfoModel.h"
//#import "ShowHudManager.h"
//#import "UIView+YYMessageView.h"
//#import "UIView+Extension.h"
//#import "NSString+Extension.h"
//#import "IQKeyboardManager.h"
//#import "UserInfoCacheManager.h"
//#import "UserDefaultManager.h"

typedef NS_ENUM(NSUInteger,ToastDelay)
{
    shortToastDelay = 1,
    longToastDelay = 2
};
typedef NS_ENUM(NSInteger,BindHouseStatus)
{
    BindHouseNo = 0,//未绑定或失败
    BindHouseAlready = 1,//已经绑定房产
};

#ifndef PublicDefine_h
#define PublicDefine_h



//请求接口 使用key
#define AUTHKEY @"authkey"

#define NOT_OPEN  @"该功能正在玩命开发中..."
#define NO_MORE_DATA @"没有更多数据了"

//用户登录信息
//#define USERINFO @"userInfo"
//#define LOGIN_INFO @"loginInfo"
//#define IS_BUILD @"isleftBind"
//
//#define LOGIN_INFO_MODEL  [NSKeyedUnarchiver unarchiveObjectWithData:[kUserDefaults objectForKey:LOGIN_INFO]];
//#define USER_INFO_MODEL  [NSKeyedUnarchiver unarchiveObjectWithData:[kUserDefaults objectForKey:USERINFO]];
//#define LEFT_BUILDING_MODEL  [NSKeyedUnarchiver unarchiveObjectWithData:[kUserDefaults objectForKey:IS_BUILD]];


#define LOGIN_INFO_MODEL  [[UserInfoCacheManager sharedUserInfoCacheManager] getLoginInfo];
#define USER_INFO_MODEL  [[UserInfoCacheManager sharedUserInfoCacheManager] getUserInfo];
#define BIND_HOUSE_MODEL  [[UserInfoCacheManager sharedUserInfoCacheManager] getHouseInfo];

#define SDK_FIRST_APPKEYMODEL [[UserInfoCacheManager sharedUserInfoCacheManager] getGetSDKToken];
#define SDK_FIRST_TOKENMODEL [[UserInfoCacheManager sharedUserInfoCacheManager] getSDKToken];


//网络请求类
#define HTTPMANAGER    [HTTPSessionManager shareHTTPSessionManager]
#define REQUESTMANAGER [RequestManager sharedRequestManager]

//荧石云sdk的域名跟baseurl不一样
#define HTTPSDKMANAGER    [HTTPSessionManager shareSDKHTTPSessionManager]


//hud
#define HUDVIEW [ShowHudManager sharedShowHudManager]




#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)


//----------------------string---------------------------

#define NULLString(string)  [NSString stringIsBlank:string]

//重写NSLog,Debug模式下打印日志和当前行数
#ifdef DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif


#define WeakObj(obj) __weak typeof(obj) obj##Weak = obj;

#define StrongObj(obj) __strong __typeof(obj) obj##Strong =obj;

//一些常用的缩写
#define kApplication        [UIApplication sharedApplication]
#define kKeyWindow          [UIApplication sharedApplication].keyWindow
#define kAppDelegate        [UIApplication sharedApplication].delegate
#define kUserDefaults      [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]



#define componentsSeparatedByString(str1,str2) [str1 componentsSeparatedByString:str2]

//定义UIImage对象
#define IMAGE(A) [UIImage imageWithContentsOfFile:［NSBundle mainBundle] pathForResource:A ofType:nil］

//定义UIImage对象
#define ImageNamed(name) [UIImage imageNamed:name]

#define PlaceHolderImage [UIImage createImageWithColor:VIEW_BG_COLOR size:CGSizeMake(SCREEN_WIDTH, 500)]

#define STRING_TO_URL(str) [NSURL URLWithString:str]

//----------------------颜色类---------------------------

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

#define UIColorFromHexA(hexValue, a)     [UIColor colorWithRed:(((hexValue & 0xFF0000) >> 16))/255.0f green:(((hexValue & 0xFF00) >> 8))/255.0f blue:((hexValue & 0xFF))/255.0f alpha:a]
#define UIColorFromHex(hexValue)        UIColorFromHexA(hexValue, 1.0f)

//----------------------颜色类--------------------------
//字体大小
#define FONT(size) [UIFont systemFontOfSize:size]
#define BFONT(size) [UIFont boldSystemFontOfSize:size]

//设备信息
//[UIDevice currentDevice].name;
//[UIDevice currentDevice].systemName;
//[[[UIDevice currentDevice] identifierForVendor] UUIDString];
//[UIDevice currentDevice].systemVersion;



#define UDID [[[UIDevice currentDevice] identifierForVendor] UUIDString]
#define SYSTEM_NAME [UIDevice currentDevice].systemName
#define USER_DEVICE_NAME [UIDevice currentDevice].name
#define SYSTEM_VERSION [UIDevice currentDevice].systemVersion
#define DEVICETYPE @"1" //1表示iOS
#define USERTYPE @"1" //1为商家。

#define USERINFO_NAME [NSString stringWithFormat:@"%@;%@;%@",USER_DEVICE_NAME,SYSTEM_VERSION,SYSTEM_NAME]


//    IQKeyboardManager *manager = [IQKeyboardManager sharedManager];
//    [manager doneAction];

#define DOWN_KEYBOARD IQKeyboardManager *manager = [IQKeyboardManager sharedManager];\
[manager doneAction];

#define showAlertWithMsg(TITLE,MESSAGE,QUVC) UIAlertController *alertController = [UIAlertController alertControllerWithTitle:TITLE message:MESSAGE preferredStyle:UIAlertControllerStyleAlert];\
[alertController addAction:[UIAlertAction actionWithTitle:@"确定"style:UIAlertActionStyleDefault handler:nil]];\
[QUVC presentViewController:alertController animated:YES completion:nil];



// 自动生成属性声明的代码
#define propertyCodeWithDictionary(dict) \
if(dict){\
NSMutableString *strM = [NSMutableString string];\
[dict enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {\
NSString *str;\
 NSLog(@"%@",[obj class]);\
if ([obj isKindOfClass:NSClassFromString(@"__NSCFString")] || [obj isKindOfClass:NSClassFromString(@"NSTaggedPointerString")] || [obj isKindOfClass:NSClassFromString(@"__NSCFConstantString")]) {\
            str = [NSString stringWithFormat:@"@property (nonatomic, copy) NSString *%@;",key];\
        }\
        if ([obj isKindOfClass:NSClassFromString(@"__NSCFNumber")]) {\
            str = [NSString stringWithFormat:@"@property (nonatomic, assign) int %@;",key];\
        }\
        if ([obj isKindOfClass:NSClassFromString(@"__NSCFArray")]) {\
            str = [NSString stringWithFormat:@"@property (nonatomic, copy) NSArray *%@;",key];\
        }\
        if ([obj isKindOfClass:NSClassFromString(@"__NSCFDictionary")]) {\
            str = [NSString stringWithFormat:@"@property (nonatomic, copy) NSDictionary *%@;",key];\
        }\
   if ([obj isKindOfClass:NSClassFromString(@"__NSCFBoolean")]) {\
            str = [NSString stringWithFormat:@"@property (nonatomic, assign) BOOL %@;",key];\
        }\
[strM appendFormat:@"\n%@\n",str];\
    }];\
NSLog(@"%@",strM);\
}\



#endif /* PublicDefine_h */
