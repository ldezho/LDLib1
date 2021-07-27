//
//  HereLinkDoorlockKeysBean.h
//  HereLink20Component
//
//  Created by codejoy on 2020/11/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereLinkDoorlockKeysBean : NSObject

/// 门锁 ID
@property (nonatomic, copy) NSString *pid;
/// 用户ID
@property (nonatomic, copy) NSString *huid;
/// 索引号
@property (nonatomic, copy) NSString *index ;
/// 索引类型
@property (nonatomic, copy) NSString *indexType ;
/// 权限开始时间
@property (nonatomic, copy) NSString *startTime ;
/// 权限结束时间
@property (nonatomic, copy) NSString *stopTime ;
/// 索引状态
@property (nonatomic, copy) NSString *state ;
/// 创建时间
@property (nonatomic, copy) NSString *createTime ;
/// 用户名称
@property (nonatomic, copy) NSString *userName;
/// 用户手机号
@property (nonatomic, copy) NSString *userMobile;
/// 卡片ID
@property (nonatomic, copy) NSString *cardId;
/// 启用/禁用
@property (nonatomic, copy) NSString *enable;
/// 密码HASH
@property (nonatomic, copy) NSString *passwdmac;
/// 备注
@property (nonatomic, copy) NSString *remark;
/// 标签
@property (nonatomic, copy) NSString *tags;
/// 标签对象
@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *tagObject;

@end

NS_ASSUME_NONNULL_END
