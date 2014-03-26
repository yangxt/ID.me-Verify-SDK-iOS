//
//  IDmeCommonAccessCard.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 7/8/13.
//  Copyright (c) 2013 ID.me, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "IDmeDefenseCredential.h"

@interface IDmeCommonAccessCard : IDmeDefenseCredential

@property (nonatomic, copy) NSString *edipi;

@end
