//
//  IDmeUniformedServicesDependentCard.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 9/11/13.
//  Copyright (c) 2013 ID.me, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDmeUniformedServicesCard.h"

@interface IDmeUniformedServicesDependentCard : IDmeUniformedServicesCard

@property (nonatomic, copy) NSString *dependentFirstName;
@property (nonatomic, copy) NSString *dependentLastName;
@property (nonatomic, copy) NSString *dependentSSN;
@property (nonatomic, copy) NSString *dependentRelationshipToSponsor;
@property (nonatomic, copy) NSString *dependentRelationshipToSponsorCode;

@end
