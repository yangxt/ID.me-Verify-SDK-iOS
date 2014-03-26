//
//  IDmeStateLicense.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 5/15/13.
//  Copyright (c) 2013 . All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDmeCredential.h"

@interface IDmeStateLicense : IDmeCredential

@property (nonatomic, copy) NSString *address;
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSString *state;
@property (nonatomic, copy) NSString *zipCode;

@end
