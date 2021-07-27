//
//  HereLinkAPI.h
//  HereLink20Component
//
//  Created by HTenL on 2020/11/11.
//
//  蓝牙接口

#import <Foundation/Foundation.h>

typedef void(^HLKLockApiExecuteCallBack)(int code, NSString * _Nullable message, id _Nullable data);

/// 操作类型
typedef NS_ENUM(NSUInteger, HLKUserReqCmdEnum) {
    HLKUserReqCmdEnumInit                           = 0x01, /**< 门锁初始化*/
    HLKUserReqCmdEnumReset                          = 0x04, /**< 恢复出厂设置*/
    HLKUserReqCmdEnumOTA                            = 0x06, /**< 升级固件请求(status:2.下载文件中 3.升级中 4.升级成功 6.已是最新版本)*/
    HLKUserReqCmdEnumFirmwareInfo                   = 0x08, /**< 查询门锁固件*/
    HLKUserReqCmdEnumBindIndex                      = 0x33, /**< 绑定索引指令*/
    HLKUserReqCmdEnumUnbindIndex                    = 0x34, /**< 解绑索引*/
    HLKUserReqCmdEnumEditIndex                      = 0x35, /**< 修改索引有效期*/
    HLKUserReqCmdEnumFreezeIndex                    = 0x36, /**< 冻结索引*/
    HLKUserReqCmdEnumUnfreezeIndex                  = 0x39, /**< 解冻索引*/
    HLKUserReqCmdEnumDelDynamicPwd                  = 0x41, /**< 删除随机密码*/
    HLKUserReqCmdEnumEditDynamicPwdToCustom         = 0x42, /**< 修改随机密 码为自定义密码*/
    HLKUserReqCmdEnumCleanCpuCard                   = 0x44, /**< 清除 CPU 卡数据*/
    HLKUserReqCmdEnumOpen                           = 0x71, /**< 蓝牙开门*/
    HLKUserReqCmdEnumClose                          = 0x72, /**< 蓝牙关门*/
    HLKUserReqCmdEnumResetTime                      = 0x73, /**< 校准时间*/
    HLKUserReqCmdEnumQueryTimePower                 = 0x74, /**< 获取电量/时间*/
    HLKUserReqCmdEnumQueryLockLog                   = 0x75, /**< 获取门锁日志*/
    HLKUserReqCmdEnumObtainlockDetail               = 0x76, /**< 获取门锁信息*/
};

/// 索引类型
typedef NS_ENUM(NSUInteger, HLKIndexTypeEnum) {
    HLKIndexTypeEnumCustomPassword          = 0x01, /**< 密码*/
    HLKIndexTypeEnumFingerprint             = 0x02, /**< 指纹*/
    HLKIndexTypeEnumNFC_Card                = 0x03, /**< NFC卡*/
    HLKIndexTypeEnumCPU_Card                = 0x04, /**< CPU卡*/
    HLKIndexTypeEnumBindCard                = 0x06, /**< 绑卡*/
};

NS_ASSUME_NONNULL_BEGIN


@interface HereLinkAPI : NSObject

/// 蓝牙锁操作
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 门锁 mac 地址
/// @param userReqCmdEnum 操作类型
/// @param lockApiExecuteCallBack 执行结果回调
+ (void)execBasicInstructWithHuid:(NSString *)huid
                              pid:(NSString *)pid
                          lockMac:(NSString *)lockMac
                   userReqCmdEnum:(HLKUserReqCmdEnum)userReqCmdEnum
           lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 设置密码
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param password 门锁密码
/// @param startTime 开始时间 yyyy-MM-dd HH:mm:ss
/// @param endTime 结束时间 yyyy-MM-dd HH:mm:ss
/// @param remark 描述
/// @param lockApiExecuteCallBack 结果回调
+ (void)execSetPasswordWithHuid:(NSString *)huid
                            pid:(NSString *)pid
                        lockMac:(NSString *)lockMac
                       password:(NSString *)password
                      startTime:(NSString *)startTime
                        endTime:(NSString *)endTime
                         remark:(NSString *)remark
         lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 添加索引
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param startTime 开始时间 yyyy-MM-dd HH:mm:ss
/// @param endTime 结束时间 yyyy-MM-dd HH:mm:ss
/// @param remark 索引描述
/// @param tags 自定义参数
/// @param indexTypeEnum 索引类型
/// @param lockApiExecuteCallBack 结果回调
+ (void)execAddIndexWithHuid:(NSString *)huid
                         pid:(NSString *)pid
                     lockMac:(NSString *)lockMac
                   startTime:(NSString *)startTime
                     endTime:(NSString *)endTime
                      remark:(NSString *)remark
                        tags:(NSDictionary<NSString *, NSString *> *)tags
               indexTypeEnum:(HLKIndexTypeEnum)indexTypeEnum
      lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 编辑索引
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param startTime 开始时间 yyyy-MM-dd HH:mm:ss
/// @param endTime 结束时间 yyyy-MM-dd HH:mm:ss
/// @param indexId 索引ID
/// @param tags 自定义参数
/// @param indexTypeEnum 索引类型
/// @param lockApiExecuteCallBack 结果回调
+ (void)execEditIndexWithHuid:(NSString *)huid
                          pid:(NSString *)pid
                      lockMac:(NSString *)lockMac
                    startTime:(NSString *)startTime
                      endTime:(NSString *)endTime
                      indexId:(NSString *)indexId
                         tags:(NSDictionary<NSString *, NSString *> *)tags
                indexTypeEnum:(HLKIndexTypeEnum)indexTypeEnum
       lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 解绑索引
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param indexId 索引ID
/// @param indexTypeEnum 索引类型
/// @param lockApiExecuteCallBack 结果回调
+ (void)execUnbindIndexWithHuid:(NSString *)huid
                            pid:(NSString *)pid
                        lockMac:(NSString *)lockMac
                        indexId:(NSString *)indexId
                  indexTypeEnum:(HLKIndexTypeEnum)indexTypeEnum
         lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 冻结索引
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param indexId 索引ID
/// @param indexTypeEnum 索引类型
/// @param lockApiExecuteCallBack 结果回调
+ (void)execFreezeIndexWithHuid:(NSString *)huid
                            pid:(NSString *)pid
                        lockMac:(NSString *)lockMac
                        indexId:(NSString *)indexId
                  indexTypeEnum:(HLKIndexTypeEnum)indexTypeEnum
         lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 解冻索引
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param indexId 索引ID
/// @param indexTypeEnum 索引类型
/// @param lockApiExecuteCallBack 结果回调
+ (void)execUnfreezeIndexWithHuid:(NSString *)huid
                              pid:(NSString *)pid
                          lockMac:(NSString *)lockMac
                          indexId:(NSString *)indexId
                    indexTypeEnum:(HLKIndexTypeEnum)indexTypeEnum
           lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 删除动态密码
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param passwordmac 密码地址信息
/// @param lockApiExecuteCallBack 结果回调
+ (void)execDelDynamicPwdWithHuid:(NSString *)huid
                              pid:(NSString *)pid
                          lockMac:(NSString *)lockMac
                      passwordmac:(NSString *)passwordmac
           lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 修改动态密码为自定义密码
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param passwordmac 密码地址信息
/// @param startTime 开始时间 yyyy-MM-dd HH:mm:ss
/// @param endTime 结束时间 yyyy-MM-dd HH:mm:ss
/// @param lockApiExecuteCallBack 结果回调
+ (void)execEditDynamicPwdToCustomWithHuid:(NSString *)huid
                                       pid:(NSString *)pid
                                   lockMac:(NSString *)lockMac
                               passwordmac:(NSString *)passwordmac
                                  password:(NSString *)password
                                 startTime:(NSString *)startTime
                                   endTime:(NSString *)endTime
                    lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 清空 CPU 卡里面的钥匙
/// @param huid 海联用户 ID
/// @param pid 门锁 pid
/// @param lockMac 锁 MAC
/// @param cardId 卡片 ID
/// @param lockApiExecuteCallBack 结果回调
+ (void)execCleanCpuCardWithHuid:(NSString *)huid
                             pid:(NSString *)pid
                         lockMac:(NSString *)lockMac
                          cardId:(NSString *)cardId
          lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

/// 获取锁的信息
/// @param huid 海联用户 ID
/// @param lockMac 锁 MAC 或者 lockName均可
/// @param lockApiExecuteCallBack 结果回调 (成功则data为HereLinkLockDetail类型)
+ (void)obtainLockDetailWithHuid:(NSString *)huid
                         lockMac:(NSString *)lockMac
          lockApiExecuteCallBack:(HLKLockApiExecuteCallBack)lockApiExecuteCallBack;

@end

NS_ASSUME_NONNULL_END
