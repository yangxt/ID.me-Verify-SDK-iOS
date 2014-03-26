//
//  IDmeDefenseCredential.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 8/26/13.
//  Copyright (c) 2013 ID.me, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDmeCredential.h"

@interface IDmeDefenseCredential : IDmeCredential

@property (nonatomic, copy) NSString *ssn;
@property (nonatomic, copy) NSString *rank;
@property (nonatomic, copy) NSString *cardIssueDate;
@property (nonatomic, copy) NSString *cardExpirationDate;
@property (nonatomic, assign, getter = isCardExpired) BOOL cardExpired;

@end
