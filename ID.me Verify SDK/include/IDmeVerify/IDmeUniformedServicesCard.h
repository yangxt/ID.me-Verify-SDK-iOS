//
//  IDmeUniformedServicesCard.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 7/16/13.
//  Copyright (c) 2013 ID.me, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDmeDefenseCredential.h"

@interface IDmeUniformedServicesCard : IDmeDefenseCredential

@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *branch;
@property (nonatomic, copy) NSString *payGrade;

@end
