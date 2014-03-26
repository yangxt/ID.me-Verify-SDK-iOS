//
//  IDmeAPIMediator.h
//  ID.me Verify
//
//  Created by Arthur Sabintsev on 1/8/14.
//  Copyright (c) 2014 ID.me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSString+IDmeVerify.h"
#import "IDmeTypedefs.h"

@interface IDmeAPIMediator : NSObject

/// The results block that returns data and errors (if they exist) when performing an API request.
typedef void (^IDmeAPIRequestResults)(BOOL status, NSString *errorMessage, id resultsObject);

/// Use this initializaiton method when using the @b IDmeAPIRequestTypeUserProfile route
- (instancetype)initWithAffinity:(AffinityGroup)affinity;

/*!
 * This method receives API requests to ID.me's API, and receives data back in the @b IDmeAPIRequestResults block.
 *
 * @param IDmeAPIRequestType The type of API requestion you are trying to perform.
 * @param NSMutableDictionary A mutable dictionary that contains all of the API parameters that are needed to perform the API request specified by @b IDmeAPIRequestType.
 * @param IDmeAPIRequestResults A block that returns the JSON results from the API request.
 */
- (void)performRequest:(IDmeAPIRequestType)requestType
            withParams:(NSMutableDictionary *)params
            andResults:(IDmeAPIRequestResults)requestResults;

@end
