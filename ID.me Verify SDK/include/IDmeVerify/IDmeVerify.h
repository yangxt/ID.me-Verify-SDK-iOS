//
//  IDmeVerify.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 7/16/13.
//  Copyright (c) 2013 ID.me, Inc. All rights reserved.
//

// Apple Frameworks
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// ID.me Verify - Constants and Typedefs
#import "IDmeConstants.h"
#import "IDmeTypedefs.h"

// ID.me Verify - Controllers
#import "IDmeAPIMediator.h"

// ID.me Verify - Scannable Credentials
#import "IDmeCredential.h"
#import "IDmeDefenseCredential.h"
#import "IDmeStateLicense.h"
#import "IDmeCommonAccessCard.h"
#import "IDmeUniformedServicesCard.h"
#import "IDmeUniformedServicesDependentCard.h"

// ID.me Verify - Console Logging Macro
#define IDmeLog(fmt, ...)                   NSLog((@"[ID.me Verify]: " fmt), ##__VA_ARGS__)
#define IDME_VERIFY_ERROR_DOMAIN            @"ID.me Verify Error Domain"

@interface IDmeVerify : NSObject

/// The serial key used to initialize the SDK.
@property (nonatomic, copy, readonly) NSString *serialKey;

/// The API key used to access the ID.me Mobile API.
@property (nonatomic, copy, readonly) NSString *clientID;

/// The API secret used to access the ID.me Mobile API.
@property (nonatomic, copy, readonly) NSString *clientSecret;

/// The Scanner username used to access the barcode scanner.
@property (nonatomic, copy, readonly) NSString *scannerUser;

/// The Scanner key used to access the barcode scanner.
@property (nonatomic, copy, readonly) NSString *scannerKey;

/// The ID.me API user's email address. This is set after a user signs in or signs up.
@property (nonatomic, copy, readonly) NSString *userEmail;

/// The ID.me API auth token of the user. This is set after a user signs in or signs up.
@property (nonatomic, copy, readonly) NSString *userAuthToken;

/// The ID.me user's avatar. This is set after a user signs in or signs up.
@property (nonatomic, copy, readonly) NSData *userAvatar;

/// The API Development Environment required to access the API.
@property (nonatomic, assign, readonly) IDmeAPIEnvironmentType environmentType;

/*!
 * The singleton method for the IDmeVerify class.
 *
 * @return A singleton instance of IDmeVerify.
 */
+ (instancetype)sharedInstance;

/*!
 * This method initializes the ID.me Verify SDK. As such, it must be called
 * before any other method in the SDK. Contact @b mobile\@id.me to request a serial key.
 *
 * @param serialKey The serial key that is provided by ID.me and used to unlock the SDK.
 * @param clientID The clientID that is provided by ID.me upon registering an app at @b http://developer.id.me
 * @param clientSecret The clientSecret that is provided by ID.me upon registering an app at @b http://developer.id.me
 * @param scannerUser (@b optional) The scanner username is needed to use the barcode scanner. Contact ID.me if you need assistance.
 * @param scannerKey (@b optional) The scanner key that is needed to use the barcode scanner. Contact ID.me if you need assistance.
 * @param environment: The development environment. Use @b IDmeAPIEnvironmentTypeSandbox for development and @b IDmeAPIEnvironmentTypeProduction before deploying your app to the store.
 */
- (void)startWithSerialKey:(NSString *)serialKey
                  clientID:(NSString *)clientID
              clientSecret:(NSString *)clientSecret
               scannerUser:(NSString *)scannerUser
                scannerKey:(NSString *)scannerKey
            andEnvironment:(IDmeAPIEnvironmentType)environmentType;

/*!
 * This method initializes and launches the credential scanner, which is a modal viewController that is loaded on top of a top-level viewController. The scanner works best in landscape mode.
 *
 * @param externalViewController The viewController which will present the credential scanner model viewController.
 * @param credentialTypes One or more credential types defined in the @b IDmeVerifyDetectCredentialType options enumerator.
 * @param scanResults A block that returns the parsed results of the scanned credential and an NSError object.
 */
- (void)scanCredentialInViewController:(UIViewController *)externalViewController
                    forCredentialTypes:(IDmeVerifyDetectCredentialType)credentialTypes
                           withResults:(IDmeVerifyScanResults)scanResults;

@end
