#
# Be sure to run `pod lib lint ExSuperPlayer.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |spec|
  spec.name             = 'ExSuperPlayer'
  spec.version          = '8.5.1'
  spec.summary          = 'A short description of ExSuperPlayer.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  spec.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  spec.homepage         = 'https://github.com/yinjun322/SuperPlayer_iOS'
  spec.license          = { :type => 'MIT' }
  spec.author           = { 'yinjun322' => 'yinjun322@gmail.com' }
  spec.source           = { :git => 'https://github.com/yinjun322/SuperPlayer_iOS.git', :tag => spec.version.to_s }

  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  spec.ios.deployment_target = '9.0'
  spec.requires_arc = true

  spec.dependency 'AFNetworking'
  spec.dependency 'SDWebImage'
  spec.dependency 'Masonry'
  #spec.dependency 'MMLayout'

  spec.static_framework = true
  spec.default_subspec = 'Player'

  spec.ios.framework    = ['SystemConfiguration','CoreTelephony', 'VideoToolbox', 'CoreGraphics', 'AVFoundation', 'Accelerate']
  spec.ios.library = 'z', 'resolv', 'iconv', 'stdc++', 'c++', 'sqlite3'

  spec.subspec "Player" do |s|
      s.source_files = 'Demo/TXLiteAVDemo/SuperPlayerKit/SuperPlayer/**/*.{h,m}'
      s.private_header_files = 'Demo/TXLiteAVDemo/SuperPlayerKit/SuperPlayer/Utils/TXBitrateItemHelper.h', 'Demo/TXLiteAVDemo/SuperPlayerKit/SuperPlayer/Views/SuperPlayerView+Private.h'
      s.dependency 'TXLiteAVSDK_Player'
  end
  
  spec.resource = 'Demo/TXLiteAVDemo/SuperPlayerKit/SuperPlayer/Resource/*'
  spec.frameworks = ["SystemConfiguration", "CoreTelephony", "VideoToolbox", "CoreGraphics", "AVFoundation", "Accelerate"]
  spec.libraries = [
    "z",
    "resolv",
    "iconv",
    "stdc++",
    "c++",
    "sqlite3"
  ]
end
