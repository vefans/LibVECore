#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "CameraFile.h"
#import "CameraManager.h"
#import "Common.h"
#import "CustomFilter.h"
#import "CustomShader.h"
#import "CustomTransition.h"
#import "LibVECore.h"
#import "MaskObject.h"
#import "PEAssetManager.h"
#import "PECore.h"
#import "Scene.h"
#import "VECore.h"
#import "VECoreJsonManager.h"
#import "VECoreTemplateCaption.h"
#import "VECoreTemplateCustomFilter.h"
#import "VECoreTemplateInfo.h"
#import "VECoreTemplateMask.h"
#import "VECoreTemplateMediaAsset.h"
#import "VECoreTemplateMusic.h"
#import "VECoreTemplateParticle.h"
#import "NSObject+VECoreYYModel.h"
#import "VECoreYYClassInfo.h"
#import "VECoreYYModel.h"
#import "VEAudioRecorder.h"
#import "PECoreTemplateAssetManager.h"
#import "PECoreTemplateAssetManagerBackground.h"
#import "PECoreTemplateBackground.h"
#import "PECoreTemplateFaceRecognition.h"
#import "PECoreTemplateFilter.h"
#import "PECoreTemplateImageAsset.h"
#import "PECoreTemplateInfo.h"
#import "PECoreTemplateMediaInfo.h"
#import "PECoreTemplateOverlay.h"
#import "PECoreTemplateOverlayMedia.h"
#import "PETemplateExportInfo.h"

FOUNDATION_EXPORT double LibVECoreVersionNumber;
FOUNDATION_EXPORT const unsigned char LibVECoreVersionString[];

