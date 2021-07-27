//
//  HereLinkBusinessAPI.h
//  HereLink20Component
//
//  Created by HTenL on 2020/11/11.
//

#import <HereLink20Component/HereLinkAPI.h>

typedef NS_ENUM(NSUInteger, HLKIndexStateEnum) {
    HLKIndexStateEnumValid                  = 1, /**< 有效*/
    HLKIndexStateEnumTimeOut                = 2, /**< 过期*/
    HLKIndexStateEnumWaitRemove             = 3, /**< 待删*/
};

/// 循环策略
typedef NS_ENUM(NSUInteger, HLKLoopStrategyEnum) {
    HLKLoopStrategyEnumMonday               = 1, /**< 周一*/
    HLKLoopStrategyEnumTuesday,                  /**< 周二*/
    HLKLoopStrategyEnumWednesday,                /**< 周三*/
    HLKLoopStrategyEnumThursday,                 /**< 周四*/
    HLKLoopStrategyEnumFriday,                   /**< 周五*/
    HLKLoopStrategyEnumSaturday,                 /**< 周六*/
    HLKLoopStrategyEnumSunday,                   /**< 周日*/
    HLKLoopStrategyEnumWeekday,                  /**< 周一 ～ 周五*/
    HLKLoopStrategyEnumWeekend,                  /**< 周六、周日*/
    HLKLoopStrategyEnumEveryday,                 /**< 每天*/
};

/// 循环结束时间点
typedef NS_ENUM(NSUInteger, HLKLoopEndPointEnum) {
    HLKLoopEndPointEnumHour0                = 0,
    HLKLoopEndPointEnumHour1,
    HLKLoopEndPointEnumHour2,
    HLKLoopEndPointEnumHour3,
    HLKLoopEndPointEnumHour4,
    HLKLoopEndPointEnumHour5,
    HLKLoopEndPointEnumHour6,
    HLKLoopEndPointEnumHour7,
    HLKLoopEndPointEnumHour8,
    HLKLoopEndPointEnumHour9,
    HLKLoopEndPointEnumHour10,
    HLKLoopEndPointEnumHour11,
    HLKLoopEndPointEnumHour12,
    HLKLoopEndPointEnumHour13,
    HLKLoopEndPointEnumHour14,
    HLKLoopEndPointEnumHour15,
    HLKLoopEndPointEnumHour16,
    HLKLoopEndPointEnumHour17,
    HLKLoopEndPointEnumHour18,
    HLKLoopEndPointEnumHour19,
    HLKLoopEndPointEnumHour20,
    HLKLoopEndPointEnumHour21,
    HLKLoopEndPointEnumHour22,
    HLKLoopEndPointEnumHour23,
};

NS_ASSUME_NONNULL_BEGIN

@interface HereLinkBusinessAPI : NSObject

/// 注册蓝牙锁
/// @param huid 海联用户 ID
/// @param lockMac 锁 MAC
/// @param lockName 门锁名称
/// @param lockApiExecuteCallBack 结果回调 （成功 data 类型为HereLinkDoorlockRegisterBean）
+ (void)registerDoorlockWithHuid:(NSString *)huid
                         lockMac:(NSString *)lockMac
                        lockName:(NSString * _Nullable)lockName
          lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 删除蓝牙锁
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockApiExecuteCallBack 结果回调
+ (void)doorlockDelWithHuid:(NSString *)huid
                        pid:(NSString *)pid
     lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取蓝牙锁详细信息
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockApiExecuteCallBack 结果回调（成功 data 类型为HereLinkDoorlockRegisterBean）
+ (void)getDoorlockInfoWithHuid:(NSString *)huid
                            pid:(NSString *)pid
         lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取蓝牙锁列表
/// @param huid 海联用户 ID
/// @param tags 搜索关键字 可以不填
/// @param lockApiExecuteCallBack 结果回调 （成功 data 类型为NSArray<HereLinkDoorlockRegisterBean *> *）
+ (void)getListDoorlockWithHuid:(NSString *)huid
                           tags:(NSArray<NSString *> * _Nullable)tags
         lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取蓝牙锁的电量和时间
/// @param pid 门锁的 PID
/// @param lockApiExecuteCallBack 执行结果回调（成功 data 类型为HereLinkDoorlockTimePowerBean）
+ (void)getDoorlockTimePowerWithPid:(NSString *)pid
             lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取门锁的钥匙列表
/// @param huid 海联用户 ID
/// @param pid 门锁的 PID
/// @param indexTypes 索引类型 多个类型用逗号 分割
/// @param state 索引状态
/// @param lockApiExecuteCallBack 执行结果回调（成功 data 类型为NSArray<HereLinkDoorlockKeysBean *> *）
+ (void)getListDoorlockKeysWithHuid:(NSString *)huid
                                pid:(NSString *)pid
                         indexTypes:(NSString *)indexTypes
                              state:(HLKIndexStateEnum)state
             lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取临时密码
/// @param huid 海联用户 ID
/// @param pid 门锁的 PID
/// @param remark 描述信息
/// @param lockApiExecuteCallBack 执行结果回调（成功 data 类型为HereLinkDynamicPasswordBean）
+ (void)getTempPwdWithHuid:(NSString *)huid
                       pid:(NSString *)pid
                    remark:(NSString * _Nullable)remark
    lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取自定义时间密码
/// @param huid 海联用户 ID
/// @param pid 门锁的 PID
/// @param startTime 开始时间 yyyy-MM-dd HH:mm:ss
/// @param endTime 结束时间 yyyy-MM-dd HH:mm:ss
/// @param remark 描述信息
/// @param lockApiExecuteCallBack 执行结果回调（成功 data 类型为HereLinkDynamicPasswordBean）
+ (void)getNormalPwdWithHuid:(NSString *)huid
                         pid:(NSString *)pid
                   startTime:(NSString *)startTime
                     endTime:(NSString *)endTime
                      remark:(NSString * _Nullable)remark
      lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取永久密码
/// @param huid 海联用户 ID
/// @param pid 门锁的 PID
/// @param remark 描述信息
/// @param lockApiExecuteCallBack 执行结果回调（成功 data 类型为HereLinkDynamicPasswordBean）
+ (void)getForeverPwdWithHuid:(NSString *)huid
                          pid:(NSString *)pid
                       remark:(NSString * _Nullable)remark
       lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取清空密码
/// @param huid 海联用户 ID
/// @param pid 门锁的 PID
/// @param remark 描述信息
/// @param lockApiExecuteCallBack 执行结果回调（成功 data 类型为HereLinkDynamicPasswordBean）
+ (void)getEliminatePwdWithHuid:(NSString *)huid
                            pid:(NSString *)pid
                         remark:(NSString * _Nullable)remark
         lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取自定义周期密码
/// @param huid 海联用户 ID
/// @param pid 门锁的 PID
/// @param startTime 开始时间 yyyy-MM-dd HH:mm:ss
/// @param endTime 结束时间 yyyy-MM-dd HH:mm:ss
/// @param loopStrategyEnum 循环策略
/// @param loopEndPointEnum 循环结束时间点
/// @param remark 描述信息
/// @param lockApiExecuteCallBack 执行结果回调（成功 data 类型为HereLinkDynamicPasswordBean）
+ (void)getCyclePwdWithHuid:(NSString *)huid
                        pid:(NSString *)pid
                  startTime:(NSString *)startTime
                    endTime:(NSString *)endTime
           loopStrategyEnum:(HLKLoopStrategyEnum)loopStrategyEnum
           loopEndPointEnum:(HLKLoopEndPointEnum)loopEndPointEnum
                     remark:(NSString * _Nullable)remark
     lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

@end

NS_ASSUME_NONNULL_END
  
