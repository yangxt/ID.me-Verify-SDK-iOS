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
typedef NS_ENUM (NSUInteger, AffinityGroup)
{
    AffinityGroupMilitary = 1,
    AffinityGroupResponder,
    AffinityGroupStudent
};

typedef NS_ENUM(NSUInteger, AffinitySubgroup)
{
    AffinitySubgroupServiceMember = 1,
    AffinitySubgroupVeteran,
    AffinitySubgroupMilitarySpouse,
    AffinitySubgroupMilitaryFamily,
    AffinitySubgroupRetiree,
    AffinitySubgroupEMT
};

typedef NS_ENUM(NSUInteger, RelationshipType)
{
    RelationshipTypeSelf,
    RelationshipTypeSpouse,
    RelationshipTypeFamily
};

/// String Manipulation Methods (for API)
+ (instancetype)stringForAffinityGroup:(AffinityGroup)group;
+ (instancetype)stringForAffinitySubgroup:(AffinitySubgroup)subgroup;
+ (instancetype)stringForRelationshipType:(RelationshipType)type;

/// Credential Scanning & Parsing Methods
+ (instancetype)ageFromBirthdate:(NSString *)date;
+ (instancetype)numericalMonthFromString:(NSString *)month;
+ (instancetype)string:(NSString *)string withSubstringExistsInRange:(NSRange)range;

@end
