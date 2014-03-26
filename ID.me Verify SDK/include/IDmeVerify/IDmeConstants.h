//
//  IDmeConstants.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 2/14/14.
//  Copyright (c) 2014 ID.me. All rights reserved.
//


/// The installed version of the ID.me Verify SDK.
FOUNDATION_EXPORT NSString * const kIDmeVerifySDKVersion;

/// A string value of @b Not @b Available may on occassion be returned for the @c barcode, @c SSN, & @c EDIPI values.
FOUNDATION_EXPORT NSString * const kIDmeVerifyErrorNotAvailable;

/// The plain text error description returned for the @c IDmeVerifyErrorCodeScannerAccessForbidden type in the @c IDmeVerifyErrorCode typedef.
FOUNDATION_EXPORT NSString * const kIDmeVerifyErrorScannerAccessForbidden;

/// The plain text error description returned for the @c IDmeVerifyErrorCodeScannerAccessForbidden type in the @c IDmeVerifyErrorCode typedef.
FOUNDATION_EXPORT NSString * const kIDmeVerifyErrorNoScanPerformed;

/// The plain text error description returned for the @c IDmeVerifyErrorCodeCouldNotParseCredential type in the @c IDmeVerifyErrorCode typedef.
FOUNDATION_EXPORT NSString * const kIDmeVerifyErrorCouldNotParseCredential;

/// The plain text error description returned for the @c IDmeVerifyErrorCodeCredentialOwnerIsUnderLegalAge type in the @c IDmeVerifyErrorCode typedef.
FOUNDATION_EXPORT NSString * const kIDmeVerifyCredentialOwnerIsUnderLegalAge;

/// Credential Types
/// Plain text string for the @c IDmeVerifyCredentialTypeUnknown type in the @c IDmeVerifyCredentialType typedef
FOUNDATION_EXPORT NSString * const kIDmeVerifyCredentialTypeNameUnknown;

/// Plain text string for the @c IDmeVerifyCredentialTypeStateLicense type in the @c IDmeVerifyCredentialType typedef
FOUNDATION_EXPORT NSString * const kIDmeVerifyCredentialTypeNameStateLicense;

/// Plain text string for the @c IDmeVerifyCredentialTypeCommonAccessCard type in the @c IDmeVerifyCredentialType typedef
FOUNDATION_EXPORT NSString * const kIDmeVerifyCredentialTypeNameCommonAccessCard;

/// Plain text string for the @c IDmeVerifyCredentialTypeUniformedServicesCard type in the @c IDmeVerifyCredentialType typedef
FOUNDATION_EXPORT NSString * const kIDmeVerifyCredentialTypeNameUniformedServicesCard;

/// Plain text string for the @c IDmeVerifyCredentialTypeUniformedServicesDependentCard type in the @c IDmeVerifyCredentialType typedef
FOUNDATION_EXPORT NSString * const kIDmeVerifyCredentialTypeNameUniformedServicesDependentCard;

/** API CONSTANTS (Authentication) **/

/// ID.me API Client ID
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_CLIENT_ID;

/// ID.me API Client Secret
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_CLIENT_SECRET;

/// ID.me API Auth Token
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_AUTH_TOKEN;

/// ID.me user's email
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_EMAIL;

/// ID.me user's password
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_PASSWORD;

/// ID.me user's password confirmation
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_CONFIRM_PASSWORD;

/** API CONSTANTS (User Profile) **/

/// ID.me user's first name
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_FIRST_NAME;

/// ID.me user's last name
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_LAST_NAME;

/// ID.me user's birthdate
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_BIRTHDATE;

/// ID.me user's social security number
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_SSN;

/// ID.me user's city
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_CITY;

/// ID.me user's state (2 letter state code)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_STATE;

/// ID.me user's zip code
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_ZIP_CODE;

/// ID.me user's avatar (e.g., UIImage stored as NSData)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_IMAGE;

/// ID.me user's affinity group ID
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_AFFINITY_GROUP_ID;

/// ID.me user's affinity subgroup ID
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_AFFINITY_SUBGROUP_ID;

/** API CONSTANTS (Military Specific) **/

/// ID.me user's first name (when verifying as military)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_SERVICE_MEMBER_FIRST_NAME;

/// ID.me user's last name (when verifying as military)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_SERVICE_MEMBER_LAST_NAME;

/// ID.me user's relationship to military personnel (when verifying as military)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_RELATIONSHIP;

/// ID.me user's active duty status date (i.e., @b ANY date in which user was in military and on active duty status)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_ACTIVE_DUTY_STATUS_DATE;

/** API CONSTANTS (EMT Specific) **/

/// ID.me user's name suffix (optional)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_SUFFIX;

/// ID.me user's EMT registry number (8 alphanumeric characters)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_REGISTRY_NUMBER;

/** API CONSTANTS (Firefighter Specific) **/

/// ID.me user's social security number (last 4 digits only)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_SSN_FIREFIGHTER;

/** API CONSTANTS (Student Specific) **/

/// ID.me user's social security number
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_SSN9_STUDENT;

/// ID.me user's social security number (last 4 digits only)
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_SSN4_STUDENT;

/// Four year institution ID, which can be found by fetching data from the @b IDmeAPIRequestTypeSchools route.
FOUNDATION_EXPORT NSString * const IDME_API_PARAM_SCHOOL_ID;

