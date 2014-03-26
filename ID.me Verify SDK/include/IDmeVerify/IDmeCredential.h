//
//  IDmeCredential.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 7/8/13.
//  Copyright (c) 2013 ID.me, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDmeConstants.h"
#import "IDmeTypedefs.h"

@interface IDmeCredential : NSObject

@property (nonatomic, assign, readonly) IDmeVerifyCredentialType credentialType;
@property (nonatomic, copy, readonly) NSString *credentialTypeName;
@property (nonatomic, copy) NSString *barcode;
@property (nonatomic, copy) NSString *firstName;
@property (nonatomic, copy) NSString *lastName;
@property (nonatomic, copy) NSString *address;
@property (nonatomic, copy) NSString *birthDay;
@property (nonatomic, copy) NSString *birthMonth;
@property (nonatomic, copy) NSString *birthYear;
@property (nonatomic, copy) NSString *birthdate;
@property (nonatomic, copy) NSString *age;

- (instancetype)initWithBarcode:(NSString *)barcode andCredentialType:(IDmeVerifyCredentialType)credentialType;

@end
