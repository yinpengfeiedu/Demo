//
//  Alipay.h
//  Alipay
//
//  Created by yinpengfei on 16/4/6.
//  Copyright © 2016年 yinpengfei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Alipay : NSObject


@property (nonatomic ,copy) NSString *mOrder;
@property (nonatomic ,copy) NSString *mPid;
@property (nonatomic ,copy) NSString *mAccountNo;
@property (nonatomic ,copy) NSString *mPrivateKey;

-(Boolean) initData : (NSString*) pid
       andAccountNo : (NSString*) accountNo
      andPrivateKey : (NSString*) privateKey;

-(void) pay;

-(int) add: (int) x
     andy : (int) y;

-(void) setOrder:(NSString *)order;

-(void) print;

@end