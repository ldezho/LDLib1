//
//  HereLinkDoorlockRegisterBean.h
//  HereLink20Component
//
//  Created by codejoy on 2020/11/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereLinkDoorlockRegisterBean : NSObject

/// 商户业务平台 ID
@property (nonatomic, copy) NSString *bid;
/// 门锁品牌 ID
@property (nonatomic, copy) NSString *brandId;
/// 门锁电量(%)
@property (nonatomic, copy) NSNumber *devicePower;
/// 固件版本号
@property (nonatomic, copy) NSString *firmVersion;
/// 硬件版本号
@property (nonatomic, copy) NSString *hardVersion;
/// id
@property (nonatomic, copy) NSString *doorlockRegisterId;
/// 门锁品牌名称
@property (nonatomic, copy) NSString *lockBrandName;
/// 门锁品牌编号
@property (nonatomic, copy) NSString *lockBrandNo;
/// 门锁厂商
@property (nonatomic, copy) NSString *lockFactory;
/// 门锁 MAC 地址
@property (nonatomic, copy) NSString *lockMac;
/// 门锁名称
@property (nonatomic, copy) NSString *lockName;
/// 门锁状态(0 待激活 1 正常 2 停用)
@property (nonatomic, copy) NSNumber *lockStatus;
/// 产品型号
@property (nonatomic, copy) NSString *model;
/// 协议平台门锁 ID
@property (nonatomic, copy) NSString *pid;
/// Sdk 版本号
@property (nonatomic, copy) NSString *sdkVersion;
/// 最后上报时间
@property (nonatomic, copy) NSString *serviceTime;
/// 软件包 ID
@property (nonatomic, copy) NSString *softId;
/// 数据状态:0-无效，1-有效
@property (nonatomic, copy) NSNumber *status;
/// 标签
@property (nonatomic, copy) NSString *tags;

@end

NS_ASSUME_NONNULL_END
