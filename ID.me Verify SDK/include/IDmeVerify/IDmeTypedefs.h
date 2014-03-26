//
//  IDmeTypedefs.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 2/15/14.
//  Copyright (c) 2014 ID.me. All rights reserved.
//

@class IDmeCredential;

/// Enumerates the development environments
typedef NS_ENUM (NSUInteger, IDmeAPIEnvironmentType)
{
    IDmeAPIEnvironmentTypeSandbox = 0,
    IDmeAPIEnvironmentTypeProduction
};

/// Enumerates the various types of APIRequests that can be performed.
typedef NS_ENUM(NSUInteger, IDmeAPIRequestType)
{
    IDmeAPIRequestTypeDownloadAvatar,
    IDmeAPIRequestTypeSchools,
    IDmeAPIRequestTypeSignIn,
    IDmeAPIRequestTypeSignOut,
    IDmeAPIRequestTypeSignUp,
    IDmeAPIRequestTypeUploadAvatar,
    IDmeAPIRequestTypeUserProfile,
    IDmeAPIRequestTypeVerifyEMT,
    IDmeAPIRequestTypeVerifyFirefighter,
    IDmeAPIRequestTypeVerifyMilitary,
    IDmeAPIRequestTypeVerifyStudent
};

/// These options are used to configure the types of credentials can be scanned. \nThe values are bitshifted for your convenience.
typedef NS_OPTIONS(NSUInteger, IDmeVerifyDetectCredentialType)
{
    IDmeVerifyDetectCredentialTypeAll                               = (0x1 << 0), // 0x00000001
    IDmeVerifyDetectCredentialTypeStateLicense                      = (0x1 << 1), // 0x00000010
    IDmeVerifyDetectCredentialTypeCommonAccessCard                  = (0x1 << 2), // 0x00000100
    IDmeVerifyDetectCredentialTypeUniformedServicesCard             = (0x1 << 3), // 0x00001000
    IDmeVerifyDetectCredentialTypeUniformedServicesDependentCard    = (0x1 << 4)  // 0x00010000
};

/// Enumerates the different credentialTypes that are currently supported by the scanner.
typedef NS_ENUM(NSUInteger, IDmeVerifyCredentialType)
{
    /// Scanned Credential is an unknown credential, and therefore, can not be parsed.
    IDmeVerifyCredentialTypeUnknown = 0,
    
    /// Scanned Credential is a U.S. State License (including District of Columbia).
    IDmeVerifyCredentialTypeStateLicense,
    
    /// Scanned Credential is a Common Access Card (aka CAC).
    IDmeVerifyCredentialTypeCommonAccessCard,
    
    /// Scanned Credential is a Uniformed Services Card owned by a Sponsor
    IDmeVerifyCredentialTypeUniformedServicesCard,
    
    /// Scanned Credential is a Uniformed Services Card owned by a Dependent
    IDmeVerifyCredentialTypeUniformedServicesDependentCard
};

/// The results block that returns data and errors (if they exist) when scanning and parsing a credential.
typedef void (^IDmeVerifyScanResults)(IDmeCredential *credential, NSError *error);

/// This typedef differentiates errors that may occur when using the credential scanner and parser.
typedef NS_ENUM(NSUInteger, IDmeVerifyErrorCode)
{
    /// Error occurs if developer attempts to access scanner, but is not given access to it. To gain access to scanner, send an email to @b mobile@id.me.
    IDmeVerifyErrorCodeScannerAccessForbidden = 101,
    
    /// Error occurs if user exits scanner without scanning a credential.
    IDmeVerifyErrorCodeNoScanPerformed,
    
    /// Error occurs if scanned credential could not be parsed.
    IDmeVerifyErrorCodeCouldNotParseCredential,
    
    /// Error occurs if owner of scanned credential is under age.
    IDmeVerifyErrorCodeCredentialOwnerIsUnderLegalAge,
};
