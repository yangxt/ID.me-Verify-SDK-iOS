//
//  AppDelegate.m
//  IDmeVerifySampleApp
//
//  Created by Arthur Sabintsev on 2/21/14.
//  Copyright (c) 2014 ID.me, Inc. All rights reserved.
//

#import "AppDelegate.h"
#import "RoutesViewController.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
#warning Make sure to initialize the SDK.
    // ID.me Verify
    [[IDmeVerify sharedInstance] startWithSerialKey:@""
                                           clientID:@""
                                       clientSecret:@""
                                        scannerUser:@""
                                         scannerKey:@""
                                     andEnvironment:IDmeAPIEnvironmentTypeSandbox];
    
    RoutesViewController *routesViewController = [[RoutesViewController alloc] initWithStyle:UITableViewStylePlain];
    self.navController = [[UINavigationController alloc] initWithRootViewController:routesViewController];
 
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    [self.window setRootViewController:[self navController]];
    [self.window makeKeyAndVisible];
    
    return YES;
}

@end
