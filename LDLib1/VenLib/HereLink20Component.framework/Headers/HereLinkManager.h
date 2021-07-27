//
//  HereLinkManager.h
//  HereLink20Component
//
//  Created by HTenL on 2020/11/11.
//
//  APPSDK 初始化接口

#import <Foundation/Foundation.h>
@class CBPeripheral;

typedef void(^HLKSdkExecuteCallBack)(int code, NSString * _Nullable message);
typedef void(^HLKOnRealTimeScanDeviceListener)(CBPeripheral * _Nonnull peripheral, NSDictionary<NSString *, id> * _Nullable advertisementData, NSNumber * _Nullable RSSI);
typedef void(^HLKOnRealTimeDeviceStatusListener)(CBPeripheral * _Nonnull peripheral);

NS_ASSUME_NONNULL_BEGIN

@interface HereLinkManager : NSObject

+ (HereLinkManager *)defaultManager;

/// 启动sdk
/// @param huid 海联用户ID
/// @param sdkExecuteCallBack 结果回调
/// @discussion 启动app后，首次获取到huid或更换用户时调用（注：需要与HereLink.plist配置文件配合使用）
+ (void)startWithHuid:(NSString *)huid andSdkExecuteCallBack:(HLKSdkExecuteCallBack)sdkExecuteCallBack;

/// 启动sdk
/// @param businessKey 商户Key
/// @param bid 商户ID
/// @param cacheLockMac 是否缓存锁的mac地址，自动连接门锁使用
/// @param busHost1 业务服务器地址
/// @param busHost2 备用业务服务器地址(可选)
/// @param huid 海联用户ID
/// @param sdkExecuteCallBack 结果回调
/// @discussion 启动app后，首次获取到huid或更换用户时调用
+ (void)startWithBusinessKey:(NSString *)businessKey
                         bid:(NSString *)bid
                cacheLockMac:(BOOL)cacheLockMac
                    busHost1:(NSString *)busHost1
                    busHost2:(NSString *)busHost2
                        huid:(NSString *)huid
          sdkExecuteCallBack:(HLKSdkExecuteCallBack)sdkExecuteCallBack;

/// APPSDK 注册，app 初始化时候调用
/// @param businessKey 商户 Key
/// @param bid 商户 ID
/// @param cacheLockMac 是否缓存锁的 mac 地址，自动连 接门锁使用
/// @param busHost1 业务服务域名
/// @param busHost2 业务服务域名，备用业务服务(可 选填)
/// @param sdkExecuteCallBack 结果回调
- (void)sdkResgisterWithBusinessKey:(NSString *)businessKey
                                bid:(NSString *)bid
                       cacheLockMac:(BOOL)cacheLockMac
                           busHost1:(NSString *)busHost1
                           busHost2:(NSString *)busHost2
                 sdkExecuteCallBack:(HLKSdkExecuteCallBack)sdkExecuteCallBack;

/// 用户绑定 APPSDK(用户登录成功 且 APPSDK 注册成功后 调用)
/// @param huid 海联用户 ID
/// @param sdkExecuteCallBack 结果回调
- (void)userBindSdkWithHuid:(NSString *)huid sdkExecuteCallBack:(HLKSdkExecuteCallBack)sdkExecuteCallBack;

/// 扫描蓝牙锁实时回调
/// @param onRealTimeScanDeviceListener 回调
- (void)addOnRealTimeScanDeviceListener:(HLKOnRealTimeScanDeviceListener)onRealTimeScanDeviceListener;

/// 蓝牙锁状态实时回调
/// @param onRealTimeDeviceStatusListener 回调
- (void)addOnRealTimeDeviceStatusListener:(HLKOnRealTimeDeviceStatusListener)onRealTimeDeviceStatusListener;

/// 手动断开单个蓝牙连接
/// @param lockMac 蓝牙设备mac地址
- (void)lockClosed:(NSString *)lockMac;

/// 手动断开全部蓝牙连接
- (void)lockClosesAll;

/// 设置groupId
/// @param groupId App Groups Identifier
/// @discussion 如果需要共享数据，请设置正确的App Groups Identifier
+ (void)setGroupId:(NSString *)groupId;

@end

NS_ASSUME_NONNULL_END
