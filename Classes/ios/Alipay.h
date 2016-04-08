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
@property (nonatomic ,copy) NSString *mPublicKey;
@property (nonatomic ,copy) NSString *mSignValue;
@property (nonatomic ,copy) NSString *mSignType;
@property (nonatomic ,copy) NSString *mUrl;


+(Alipay*) defaultPay;

-(void) print;

-(int) add: (int) x andy : (int) y;

-(Boolean) initData : (NSString*) pid
       andAccountNo : (NSString*) accountNo
      andPrivateKey : (NSString*) privateKey;


-(void) setPid:(NSString *)partnerId;

-(void) setAccountNo:(NSString *)accountNo;

-(void) setPrivateKey:(NSString *)privateKey;

-(void) setPublicKey:(NSString *)publicKey;

-(void) setSignValue:(NSString *)srcSign;

-(void) setSignType:(NSString *)signType;

-(NSString*) getPid;

-(NSString*) getAccountNo;

-(NSString*) getPrivateKey;

-(NSString*) getPublicKey;

-(NSString*) getSignValue;

-(NSString*) getSignType;

-(void) setOrder:(NSString *)order;

-(NSString*) getOrder;


-(int) pay;

-(void) setUrl : (NSString *)url;

-(NSString*) getUrl;

-(int) doH5Pay;

@end