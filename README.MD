Appoxee Inapp SDK
===========
This repository contains the Appoxee Inapp iOS SDK.

Integration
-----------

**Cocoa pods**

```ruby
target 'project_name' do
    pod 'AppoxeeInapp'
end
```

**OR**


```ruby
target 'project_name' do
    pod 'AppoxeeInapp', :git => 'https://github.com/AppoxeeMobile/iosInappArtifacts.git', :tag => '4.1.1'
end
```

**Manual**

* Drag and drop the ```AppoxeeSDK.framework``` to your project.
* Drag and drop the ```AppoxeeSDKResources.bundle``` to your project.
* Link ```UserNotifications.framework``` to your project.
* Drag and drop the ```AppoxeeInapp.framework``` and the .bundle to your project.
* Drag and drop the ```AppoxeeInappResources.bundle``` and the .bundle to your project.


Configuration file
------------------

Make sure to provide an ```AppoxeeConfig.plist``` file.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
    <dict>
        <key>sdk</key>
        <dict>
            <key>app_id</key>
            <string>XXXXX</string>
            <key>dmc_system_id</key>
            <integer>0</integer>
            <key>sdk_key</key>
            <string>XXXXXXX</string>
            <key>is_eu</key> <!-- Optional, indicate if account is EU / US -->
            <false/>
            <key>open_landing_page_inside_app</key> <!-- Optional, indicate if landing page should open inside the app or via Safari -->
            <false/>
        </dict>
        <key>inapp</key>
        <dict>
            <key>custom_fields</key> <!-- Optional -->
            <array>
                <string>customString</string>
                <string>customNumber</string>
                <string>customDate</string>
            </array>
            <key>media_timeout</key>
            <integer>10</integer>
        </dict>
    </dict>
</plist>

```

Implementation
--------------

**Objective-C**

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[AppoxeeInapp shared] engageWithDelegate:nil];

    return YES;
}
```

```objective-c
- (void)somethingNeedsToBeEngagedWithInappMessaging
{
    [[AppoxeeInapp shared] reportInteractionEventWithName:@"eventName" andAttributes:nil];
}
```

**Swift**

```swift
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        
        AppoxeeInapp.shared()?.engage(with: nil)
        
        return true
    }
```
```swift
    func somethingNeedsToBeEngagedWithInappMessaging() -> Void {

        AppoxeeInapp.shared()?.reportInteractionEvent(withName: "eventName", andAttributes: nil)
    }
```

License
-------
http://www.appoxee.com/terms/
