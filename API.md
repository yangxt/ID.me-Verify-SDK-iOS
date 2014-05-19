# ID.me Private API

## Information

- Current Version: **v1**
- Last Updated: **05/18/2014**
- Maintained By: **[Arthur Ariel Sabintsev](mailto:arthur@id.me)**

## Getting Started

An ID.me developer account is needed to access these routes. We enforce that you use our Sandbox environment while testing your app. Please register a developer account at [https://developer.sandbox.id.me](https://developer.sandbox.id.me) and create a client application. Once we've approved your client application, and you've successfully finished testing your integration of the ID.me Verify SDK, we will allow you to use your application in our production environment [https://developer.id.me](https://developer.id.me).

The client application must be approved for **private API access** before using any of the endpoints below. All API calls take `client_id` and `client_secret` as parameters. All parameters are required unless otherwise noted. Response data is in JSON format.

Connecting to the API via the iOS SDK is achieved using the following instance method on the `IDmeAPIMediator` object:

```
- (void)performRequest:(IDmeAPIRequestType)requestType
            withParams:(NSMutableDictionary *)params
            andResults:(IDmeAPIRequestResults)requestResults;
```

The method ingests two parameters and returns the results in the `IDmeAPIRequestResults` block, which is defined as:

```
typedef void (^IDmeAPIRequestResults)(BOOL status, NSString *errorMessage, id resultsObject);
```

For an entire list of the API requests and how to use them. please refer to the sample project included with these SDKs. Xcode `#warning` statements have been added to notify you where you should edit the code before running the project.

## Important note about Affinity Group and Subgroup IDs
Various endpoints in the API return`affinity_group_id` or `affinity_subgroup_id` in the results. The values are integers stored as strings. The integers denote the following group affiliation information:

### affinity_group_id
- **1** = Military
- **2** = Student
- **3** = First Responder

### affinity_subgroup_id
- **Military**
	- **1** = Service Member
	- **2** = Retiree
	- **3** = Military Spouse
	- **4** = Military Family
- **Student**
	- No subgroups exists 
- **First Responder**
	- **7** = Emt

## Sign In

Sign in a user and retrieve their authentication token. The user's email and authentication token are required parameters on all requests that require authentication.

This route is accessed via the `IDmeAPIRequestTypeSignIn` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- client_id
- client_secret
- email
- password

**Error Codes**

| Code      | Description
| --------- |:-------------
| 1000      | Invalid email or password
| 1001      | Unconfirmed email address


**Example Response: Success**

	{
	    "success": true,
	    "email": "test123@example.com",
	    "auth_token": "2UyFTaTM6aLiuExVmqTS",
	    "first_name": "Joe",
	    "last_name": "Schmoe",
	    "affinity_group_ids": [
        	1,
        	2
    	]
	}

**Example Response: Failure (invalid email or password)**

	{
	    "success": false,
	    "message": "Invalid email or password."
	    "error_code": 1000
	}

**Example Response: Failure (unconfirmed email)**

	{
	    "success": false,
	    "message": "Unconfirmed email address.",
	    "error_code": 1001
	}


## Sign Up

Sign in a user and retrieve their authentication token. The user's email and authentication token are required parameters on all requests that require authentication.

Create a new user account and return the authentication token.

This route is accessed via the `IDmeAPIRequestTypeSignUp` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- client_id
- client_secret
- email
- password
- password_confirmation
- zip
- affinity_group_id

**Example Response: Success**

	{
	    "success": true,
	    "email": "dd33333tonyasdffffff3@gmail.com",
	    "auth_token": "zsmZ3_K3CVfmC42m9svB"
	}

**Example Response: Failure (missing zip code)**

	{
	    "success": false,
	    "message": "Zip Code Please enter a zip code"
	}


## Sign Out

Logs out the user by removing all persistant data. No API call is made, however, this route is still accessed through the `IDmeAPIMediator` object as future versions of the API may require a ping to the the API.

This route is accessed via the `IDmeAPIRequestTypeSignOut` route in the `IDmeAPIRequestType` enum type.


## Military Verification

Verifies military personnel who served post 1985.

This route is accessed via the `IDmeAPIRequestTypeVerifyMilitary` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- client_id
- client_secret
- email
- auth_token
- relationship - *accepted values are defined by the *`IDmeVerifyRelationshipType` *enum*
- affinity_subgroup_id
- service_member_first_name
- service_member_last_name
- first_name *(optional)*
	- only required if relationship is not `IDmeVerifyRelationshipTypeSelf`
- last_name *(optional)*
	- only required if relationship is not `IDmeVerifyRelationshipTypeSelf`
- ssn - 9 digit SSN
- birth_date - MM/DD/YYYY
- active_duty_status_date - MM/DD/YYYY

**Example Response (success)**

	{
	    "success": true,
	    "affinity_subgroup": {
	        "id": 2,
	        "name": "Veteran"
	    }
    	"first_name": "Mike",
	    "last_name": "Jones"
	}

## Responder Verification

### EMT option:

Verifies nationally certified EMTs.

This route is accessed via the `IDmeAPIRequestTypeVerifyEMT` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- client_id
- client_secret
- email
- auth_token
- first_name
- last_name
- suffix - *(optional, should be one of Jr., Sr., I, II, III, IV, V)*
- registry_number - 8 digit registry number
- city
- state

**Example Response (success)**

	{
	    "success": true,
	    "first_name": "Mike",
	    "last_name": "Jones"
	}

### Firefighter option:

Verifies state certified firefighters.

This route is accessed via the `IDmeAPIRequestTypeVerifyFirefighter` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- client_id
- client_secret
- email
- auth_token
- first_name
- last_name
- state - 2 digit state code
- ssn - last 4 digits of SSN
- birth_date - MM/DD/YYYY

**Example Response (success)**

	{
	    "success": true,
	    "first_name": "Mike",
	    "last_name": "Jones"
	}

## Student Verification

### List of Schools:

Returns the list of schools supported by ID.me student verification. The school_id param is needed to use the student verification API call (`IDmeAPIRequestTypeVerifyStudent`). The response will be an array with nearly 5000 hash elements.

This route is accessed via the `IDmeAPIRequestTypeSchools` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- client_id
- client_secret

**Example Response**

	[
	    {
	        "name": "A.T. STILL UNIVERSITY OF HEALTH SCIENCES",
	        "school_id": 2477
	    },
	    {
	        "name": "A.T.C.",
	        "school_id": 10056
	    },
	    {
	        "name": "ABILENE CHRISTIAN UNIVERSITY",
	        "school_id": 3537
	    }
	]

### Student verification

Verifies currently enrolled students.

This route is accessed via the `IDmeAPIRequestTypeVerifyStudent` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- client_id
- client_secret
- email
- auth_token
- first_name
- last_name
- school_id - This should be a school_id returned from `IDmeAPIRequestTypeSchools` route.
- birth_date - MM/DD/YYYY
- ssn - last 4 digits of SSN
- ssn_full - 9 digit SSN

*Note: Only one of ssn or ssn_full are required. You do not need to pass both parameters.*

**Example Response**

	{
	    "success": true,
	    "first_name": "John",
	    "last_name": "Smith"
	}

## User Profile

All User profile information is accessed via the `IDmeAPIRequestTypeUserProfile` route in the `IDmeAPIRequestType` enum type. This route is affiliation-agnostic.

### Military Profile:

Retrieve the user's military profile data, which shows their verified status and subgroup.

**Parameters**

- email
- auth_token
- client_id
- client_secret

**Example Response**

	{
	    "id": "14be8db8434b06c279",
	    "verified": true,
	    "affiliation": "Veteran"
	}

### Responder Profile

Retrieve the user's first responder profile data, which shows their verified status and subgroup.

**Parameters**

- email
- auth_token
- client_id
- client_secret

**Example Response**

	{
	    "id": "1a35514db94126d21",
	    "verified": true,
	    "affiliation": "Emt"
	}

### Student Profile

Retrieve the user's student profile data, which shows their verified status. The student affinity group does not any subgroups, so the "affiliation" key is not passed back.

**Parameters**

- email
- auth_token
- client_id
- client_secret

**Example Response**

	{
	    "id": "1a35514db94126d21",
	    "verified": true
	}

### View Avatar:

Retrieve the user's profile avatar. This will return URLs to the avatar images on Amazon S3. If the user does not have an avatar you will receive an error.

This route is accessed via the `IDmeAPIRequestTypeDownloadAvatar` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- email
- auth_token
- client_id
- client_secret

**Example Response: Success**

	{
	    "small": "https://idme-development.s3.amazonaws.com/profiles/pictures/d88757bfcaff4e5480/small?1389594586",
	    "medium": "https://idme-development.s3.amazonaws.com/profiles/pictures/d88757bfcaff4e5480/medium?1389594586",
	    "large": "https://idme-development.s3.amazonaws.com/profiles/pictures/d88757bfcaff4e5480/large?1389594586"
	}

**Example Response: Failure**

	{
	    "success": false,
	    "message": "User does not have a profile picture."
	}

### Upload Avatar

This route is accessed via the `IDmeAPIRequestTypeUploadAvatar` route in the `IDmeAPIRequestType` enum type.

**Parameters**

- client_id
- client_secret
- email
- auth_token
- avatar