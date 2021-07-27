//
//  HereLinkDoorlockTimePowerBean.h
//  HereLink20Component
//
//  Created by codejoy on 2020/11/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereLinkDoorlockTimePowerBean : NSObject

/// 协议平台门锁 ID
@property (nonatomic, copy) NSString *pid;
/// 业务 ID
@property (nonatomic, copy) NSString *seqNum;
/// 门锁 MAC 地址
@property (nonatomic, copy) NSString *lockMac;
/// 协议平台关联用户 ID，参与业务
@property (nonatomic, copy) NSString *huid;
/// APP 初始化生成的 ID
@property (nonatomic, copy) NSString *appId;
/// 设备时间
@property (nonatomic, copy) NSString *deviceTime;
/// 设备电量
@property (nonatomic, copy) NSNumber *devicePower;
/// 服务器时间
@property (nonatomic, copy) NSString *serviceTime;
/// 数据状态：0-无效，1-有效
@property (nonatomic, copy) NSString *status;

@end

NS_ASSUME_NONNULL_END
