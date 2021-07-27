//
//  HereLinkDynamicPasswordBean.h
//  HereLink20Component
//
//  Created by codejoy on 2020/11/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereLinkDynamicPasswordBean : NSObject

/// 密码
@property (nonatomic, copy) NSString *password;
/// 业务 ID
@property (nonatomic, copy) NSString *seqNum;
/// pwdMac
@property (nonatomic, copy) NSString *pwdMac;

@end

NS_ASSUME_NONNULL_END
