Pod::Spec.new do |s|

  s.name         = "AppoxeeInapp"
  s.version      = "4.0.14"
  s.summary      = "Appoxee Inapp enables developers to harnest the full power of Appoxee Inapp messaging on their iOS applications."
  s.description  = 	<<-DESC
  					Appoxee Inapp enables Inapp messaging in your iOS application, for engaging your application users and increasing retention.
                   	DESC
  s.homepage     = "http://www.appoxee.com"
  s.license      = { :type => "Custom", :file => "AppoxeeLicence.txt" }
  s.author       = { "Appoxee" => "info@appoxee.com" }
  s.source       = { :git => "https://github.com/AppoxeeMobile/iosInappArtifacts.git", :tag => "4.0.14" }
  s.platform     = :ios, "7.0"
  s.ios.vendored_frameworks = "SDK/AppoxeeInapp.framework"
  s.preserve_paths = 'SDK/AppoxeeInapp.framework'
  s.resource_bundle = { 'AppoxeeInappResources' => 'SDK/AppoxeeInappResources.bundle' }
  s.dependency 'AppoxeeSDK', '~> 4.0.14'
  s.requires_arc = true

end
