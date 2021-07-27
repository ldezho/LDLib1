//
//  HereLinkLockDetail.h
//  HereLink20Component
//
//  Created by HTenL on 2020/11/10.
//

#import <HereLink20Component/HereLinkBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereLinkLockDetail : HereLinkBaseModel

/// 锁电量
@property (nonatomic, assign) UInt8 power;
/// 锁时间
@property (nonatomic, copy) NSString * lockTimeString;
/// 固件版本号
@property (nonatomic, assign) UInt8 firmwareVersion;
/// 硬件版本号
@property (nonatomic, assign) UInt8 hardwareVersion;
/// SDK版本号
@property (nonatomic, assign) UInt8 sdkVersion;
/// 锁型号
@property (nonatomic, assign) UInt8 lockModel;
/// 锁品牌
@property (nonatomic, copy) NSString * lockBrand;
/// 门锁状态
@property (nonatomic, assign) UInt8 lockStatus;
/// 当前初始化时间
@property (nonatomic, copy) NSString * lockInitTimeString;
/// 门锁PID
@property (nonatomic, copy) NSString * pid;
/// 门锁BID
@property (nonatomic, copy) NSString * bid;
/// MAC地址
@property (nonatomic, copy) NSString * lockMac;

@end

NS_ASSUME_NONNULL_END
