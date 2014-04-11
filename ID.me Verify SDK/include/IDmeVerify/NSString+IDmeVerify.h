//
//  NSString+IDmeVerify.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 7/10/13.
//  Copyright (c) 2013 ID.me, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (IDmeVerify)

/// Typedefs (for API)
typedef NS_ENUM (NSUInteger, IDmeVerifyAffinityGroup)
{
    IDmeVerifyAffinityGroupMilitary = 1,
    IDmeVerifyAffinityGroupResponder,
    IDmeVerifyAffinityGroupStudent
};

typedef NS_ENUM(NSUInteger, IDmeVerifyAffinitySubgroup)
{
    IDmeVerifyAffinitySubgroupServiceMember = 1,
    IDmeVerifyAffinitySubgroupVeteran,
    IDmeVerifyAffinitySubgroupMilitarySpouse,
    IDmeVerifyAffinitySubgroupMilitaryFamily,
    IDmeVerifyAffinitySubgroupRetiree,
    IDmeVerifyAffinitySubgroupEMT
};

typedef NS_ENUM(NSUInteger, IDmeVerifyRelationshipType)
{
    IDmeVerifyRelationshipTypeSelf,
    IDmeVerifyRelationshipTypeSpouse,
    IDmeVerifyRelationshipTypeFamily
};

/// String Manipulation Methods (for API)
+ (instancetype)stringForAffinityGroup:(IDmeVerifyAffinityGroup)group;
+ (instancetype)stringForAffinitySubgroup:(IDmeVerifyAffinitySubgroup)subgroup;
+ (instancetype)stringForRelationshipType:(IDmeVerifyRelationshipType)type;

/// Credential Scanning & Parsing Methods
+ (instancetype)ageFromBirthdate:(NSString *)date;
+ (instancetype)numericalMonthFromString:(NSString *)month;
+ (instancetype)string:(NSString *)string withSubstringExistsInRange:(NSRange)range;

@end
