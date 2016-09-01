//
//  AppoxeeInapp.h
//  AppoxeeInapp
//
//  Created by Raz Elkayam on 4/17/16.
//  Copyright © 2016 Teradata. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AppoxeeInapp;

@protocol AppoxeeInappDelegate <NSObject>

@optional
/**
 Delegate method for informing a received Inapp message.
 @brief Method will be called when an Inapp message is receieved.
 @param appoxeeInapp A singleton instance of AppoxeeInapp.
 @param identifier NSNumber as an identifier for the specific message.
 @param messageExtraData NSDictionary which may contain extra data assigned to the specific message.
 */
- (void)appoxeeInapp:(nonnull AppoxeeInapp *)appoxeeInapp didReceiveInappMessageWithIdentifier:(nonnull NSNumber *)identifier andMessageExtraData:(nullable NSDictionary <NSString *, id> *)messageExtraData;

@end

@interface AppoxeeInapp : NSObject

/*!
 * The Appoxee Inapp delegate.
 */
@property (nonatomic, weak, nullable) id <AppoxeeInappDelegate> delegate;

/**
 Appoxee Inapp instance
 @brief Method for getting a singleton instance of AppoxeeInapp
 @code
 AppoxeeInapp *appoxeeInapp = [AppoxeeInapp shared];
 </pre></code>
 @return AppoxeeInapp an Instance Type of AppoxeeInapp.
 */
+ (nullable instancetype)shared;

/**
 Appoxee Inapp version
 @brief Method for getting the SDK version
 @code
 NSString *version = [AppoxeeInapp inappVersion];
 </pre></code>
 @return NSString representing the SDK version.
 */
+ (nonnull NSString *)inappVersion;

/**
 Method for engaging with AppoxeeInapp SDK.
 @brief Call this method to enable engagement with AppoxeeInapp SDK. You will typically call this method on application launch. 
 @attention Method is considered critical, and must be implemented.
 @code
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
    [[AppoxeeInapp shared] engageWithDelegate:self];
 
    return YES;
 }
 </pre></code>
 @param delegate id which conforms to AppoxeeInappDelegate protocol.
 */
- (void)engageWithDelegate:(nullable id <AppoxeeInappDelegate>)delegate;

/**
 Method for reporting an interactionable event, which may trigger a display of an Inapp message, provided by a Real Time Decisioning Engine.
 @brief Call this method to report significant events, which may trigger a display of an Inapp banner message or a full screen Inapp message.
 @code
 - (void)userDidConfirmPaymentOfAmount:(nonnull NSNumber *)amount
 {
    [[AppoxeeInapp shared] reportInteractionEventWithName:@"payment" andAttributes:@{@"amount" : amount}];
 }
 </pre></code>
 @param name NSString which describes the event name. No spaces, numbers, or symboles are allowed. Preferebly, use camelCase.
 @param attributes NSDictionary which contains Plist objects with any additional data.
 */
- (void)reportInteractionEventWithName:(nonnull NSString *)name andAttributes:(nullable NSDictionary <NSString *, NSObject <NSCoding> *> *)attributes;

@end
