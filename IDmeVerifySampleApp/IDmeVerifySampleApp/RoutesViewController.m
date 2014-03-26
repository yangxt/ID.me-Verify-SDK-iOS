//
//  RoutesViewController.m
//  IDmeVerifySampleApp
//
//  Created by Arthur Sabintsev on 2/25/14.
//  Copyright (c) 2014 ID.me, Inc. All rights reserved.
//

#import "RoutesViewController.h"

@implementation RoutesViewController

#pragma mark - View Interface Methods
- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"ID.me Verify SDK - API Routes";
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

#pragma mark - UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 12;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *cellIdentifier = @"cell";
    UITableViewCell *cell;
    cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
        cell.selectionStyle = UITableViewCellSelectionStyleDefault;
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    }
    
    switch (indexPath.row) {
        case 0:
            cell.textLabel.text = @"Scan Credential";
            break;
            
        case 1:
            cell.textLabel.text = @"Sign Up";
            break;
            
        case 2:
            cell.textLabel.text = @"Sign In";
            break;
            
        case 3:
            cell.textLabel.text = @"Verify Military";
            break;
            
        case 4:
            cell.textLabel.text = @"Verify Student";
            break;
            
        case 5:
            cell.textLabel.text = @"Verify EMT";
            break;
            
        case 6:
            cell.textLabel.text = @"Verify Firefighter";
            break;
            
        case 7:
            cell.textLabel.text = @"Military Profile";
            break;
            
        case 8:
            cell.textLabel.text = @"Student Profile";
            break;
            
        case 9:
            cell.textLabel.text = @"First Responder Profile";
            break;
            
        case 10:
            cell.textLabel.text = @"Download User Avatar/Image";
            break;
            
        case 11:
            cell.textLabel.text = @"Upload User Avatar/Image";
            break;
    }
    
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // API Mediator
    IDmeAPIMediator *mediator = [IDmeAPIMediator new];
    
    switch ([indexPath row]) {
        case 0:{ // Scan
            
            [[IDmeVerify sharedInstance] scanCredentialInViewController:self
                                                     forCredentialTypes:IDmeVerifyDetectCredentialTypeAll
                                                            withResults:^(IDmeCredential *credential, NSError *error) {
                                                                [self showError:[error localizedDescription] orResults:credential];
                                                            }];
        } break;

#warning SIGN UP: Make sure to to populate the 'params' (e.g., NSMutableDictionary) object with test values of your choosing.
        case 1:{ // Sign Up
            
            // Creates a new military user. Use the AffintiyGroup typedef to create military, student, or responder.
            NSString *affinityGroupString = [NSString stringWithFormat:@"%d", AffinityGroupMilitary];
            
            NSMutableDictionary *params = [@{ IDME_API_PARAM_EMAIL : @"",
                                              IDME_API_PARAM_PASSWORD : @"",
                                              IDME_API_PARAM_CONFIRM_PASSWORD : @"",
                                              IDME_API_PARAM_ZIP_CODE : @"",
                                              IDME_API_PARAM_AFFINITY_GROUP_ID : affinityGroupString } mutableCopy];
            [mediator performRequest:IDmeAPIRequestTypeSignUp
                          withParams:params
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;
            
#warning SIGN IN: Make sure to to populate the 'params' (e.g., NSMutableDictionary) object with test values of your choosing.
        case 2:{ // Sign In
            
            NSMutableDictionary *params = [@{ IDME_API_PARAM_EMAIL : @"",
                                              IDME_API_PARAM_PASSWORD : @"" } mutableCopy];
            [mediator performRequest:IDmeAPIRequestTypeSignIn
                          withParams:params
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;

#warning VERIFY MILITARY: Make sure to to populate the 'params' (e.g., NSMutableDictionary) object with test values of your choosing.
        case 3:{ // Verify Military
            
            NSString *affinitySubgroup = [NSString stringForAffinitySubgroup:AffinitySubgroupServiceMember];
            NSMutableDictionary *params = [@{ IDME_API_PARAM_SERVICE_MEMBER_FIRST_NAME : @"",
                                              IDME_API_PARAM_SERVICE_MEMBER_LAST_NAME : @"",
                                              IDME_API_PARAM_SSN : @"",
                                              IDME_API_PARAM_BIRTHDATE : @"",
                                              IDME_API_PARAM_ACTIVE_DUTY_STATUS_DATE : @"",
                                              IDME_API_PARAM_RELATIONSHIP : [NSString stringForRelationshipType:RelationshipTypeSelf],
                                              IDME_API_PARAM_AFFINITY_SUBGROUP_ID : affinitySubgroup} mutableCopy];
            [mediator performRequest:IDmeAPIRequestTypeVerifyMilitary
                          withParams:params
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;

#warning VERIFY STUDENT: Make sure to to populate the 'params' (e.g., NSMutableDictionary) object with test values of your choosing.
        case 4:{ // Verify Student
            
            // 1. Get list of schools
            [mediator performRequest:IDmeAPIRequestTypeSchools withParams:[@{} mutableCopy]
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              
                              // 2. Choose a school (choosing the 101st school entry for this current example)
                              NSString *schoolID = [[resultsObject objectAtIndex:10] valueForKey:@"school_id"];
                              
                              // 3. Verify Student
                              NSMutableDictionary *params = [@{ IDME_API_PARAM_FIRST_NAME : @"",
                                                                IDME_API_PARAM_LAST_NAME : @"",
                                                                IDME_API_PARAM_SSN4_STUDENT : @"", // or use SSN9_STUDENT, or use both, up to you.
                                                                IDME_API_PARAM_BIRTHDATE : @"",
                                                                IDME_API_PARAM_SCHOOL_ID : schoolID } mutableCopy];
                              [mediator performRequest:IDmeAPIRequestTypeVerifyStudent
                                            withParams:params
                                            andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                                                [self showError:errorMessage orResults:resultsObject];
                                            }];
                          }];
        } break;

#warning VERIFY EMT: Make sure to to populate the 'params' (e.g., NSMutableDictionary) object with test values of your choosing.
        case 5:{ // Verify EMT
            
            NSMutableDictionary *params = [@{ IDME_API_PARAM_FIRST_NAME : @"",
                                              IDME_API_PARAM_LAST_NAME : @"",
                                              IDME_API_PARAM_SUFFIX : @"",
                                              IDME_API_PARAM_BIRTHDATE : @"",
                                              IDME_API_PARAM_REGISTRY_NUMBER : @"",
                                              IDME_API_PARAM_CITY : @"",
                                              IDME_API_PARAM_STATE : @""} mutableCopy];
            [mediator performRequest:IDmeAPIRequestTypeVerifyEMT
                          withParams:params
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;
            
#warning VERIFY FIREFIGHTER: Make sure to to populate the 'params' (e.g., NSMutableDictionary) object with test values of your choosing.
        case 6:{ // Verify Firefighter
            
            NSMutableDictionary *params = [@{ IDME_API_PARAM_FIRST_NAME : @"",
                                              IDME_API_PARAM_LAST_NAME : @"",
                                              IDME_API_PARAM_BIRTHDATE : @"",
                                              IDME_API_PARAM_SSN_FIREFIGHTER : @"",
                                              IDME_API_PARAM_STATE : @""} mutableCopy];
            [mediator performRequest:IDmeAPIRequestTypeVerifyFirefighter
                          withParams:params
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;

        case 7:{ // Military Profile (No extra params necessary to perform this request)
            IDmeAPIMediator *mediator = [[IDmeAPIMediator alloc] initWithAffinity:AffinityGroupMilitary];
            [mediator performRequest:IDmeAPIRequestTypeUserProfile
                          withParams:[@{} mutableCopy]
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;

        case 8:{ // Student Profile (No extra params necessary to perform this request)
            IDmeAPIMediator *mediator = [[IDmeAPIMediator alloc] initWithAffinity:AffinityGroupStudent];
            [mediator performRequest:IDmeAPIRequestTypeUserProfile
                          withParams:[@{} mutableCopy]
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;
            
        case 9:{ // First Responder Profile (No extra params necessary to perform this request)
            IDmeAPIMediator *mediator = [[IDmeAPIMediator alloc] initWithAffinity:AffinityGroupResponder];
            [mediator performRequest:IDmeAPIRequestTypeUserProfile
                          withParams:[@{} mutableCopy]
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;
            
        case 10:{ // Download User Avatar (No extra params necessary to perform this request)
            [mediator performRequest:IDmeAPIRequestTypeDownloadAvatar
                          withParams:[@{} mutableCopy]
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              [self showError:errorMessage orResults:resultsObject];
                          }];
        } break;
            
#warning UPLOAD AVATAR: Make sure to to populate the image object.
        case 11:{ // Upload User Avatar
            UIImage *image = [UIImage imageNamed:@"logo"];
            NSMutableDictionary *params = [@{IDME_API_PARAM_IMAGE : image} mutableCopy];
            [mediator performRequest:IDmeAPIRequestTypeUploadAvatar
                          withParams:params
                          andResults:^(BOOL status, NSString *errorMessage, id resultsObject) {
                              if (status) {
                                  [self showError:errorMessage orResults:resultsObject];
                              }
                          }];
            
        } break;
    }
}

#pragma mark - Error Handling
- (void)showError:(NSString *)error orResults:(id)resultsObject
{
    UIViewController *resultsViewController = [UIViewController new];
    UITextView *textView = [[UITextView alloc] initWithFrame:[self.view frame]];
    textView.text = (error) ? error : [NSString stringWithFormat:@"Results:\n%@", resultsObject];
    textView.editable = NO;
    [resultsViewController.view addSubview:textView];
    
    [self.navigationController pushViewController:resultsViewController animated:YES];
}

@end
