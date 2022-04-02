//
//  PECoreTemplateFaceRecognition.h
//  LibVECore
//
//  Created by mac on 2022/3/29.
//

#import <Foundation/Foundation.h>
#import <LibVECore/CameraManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateFaceRecognition : FaceRecognition


- (instancetype)initWithFaceRecognition:(FaceRecognition *) face;
- (FaceRecognition *)getFaceRecognitionWithFolderPath:(NSString *)folderPath;

@end

NS_ASSUME_NONNULL_END
