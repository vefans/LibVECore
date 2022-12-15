//
//  PECoreTemplateBackground.h
//  LibVECore
//
//  Created by iOS VESDK Team on 2022/2/28.
//

#import <Foundation/Foundation.h>
#import <LibVECore/PEAssetManager.h>
#import "PECoreTemplateImageAsset.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateBackground : NSObject

/** 组Id
 */
@property (nonatomic, assign) int groupId;

@property(nonatomic, strong)UIColor *color;

@property(nonatomic, strong)PECoreTemplateImageAsset *media;

- (instancetype)initWithScene:(PEAssetManager *)scene;
- (PEAssetManager *)getSceneWithFolderPath:(NSString *)folderPath;
@end

NS_ASSUME_NONNULL_END
