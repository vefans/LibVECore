Pod::Spec.new do |spec|

  spec.name         = "LibVECore"
  spec.version      = "2.4.4"
  spec.summary      = "LibVECore is a video editing SDK without UI and highly abstract API."
  spec.homepage     = "https://github.com/vefans/VECore"
  spec.platform     = :ios, '9.0'
  spec.license      = "MIT"
  spec.author       = { "iOS VESDK Team" => "" }
  spec.source       = { :git => 'https://github.com/vefans/LibVECore.git', :tag => spec.version.to_s}
  spec.source_files = '**/*.{h}'
  spec.vendored_frameworks = 'LibVECore.framework'
  spec.frameworks = "VideoToolbox","CoreServices"
  spec.pod_target_xcconfig ={'ENABLE_BITCODE' => 'NO' }
  spec.requires_arc = true
  spec.swift_version = "5.0"
  
end
