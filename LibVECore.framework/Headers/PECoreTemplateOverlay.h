//
//  PECoreTemplateOverlay.h
//  LibVECore
//
//  Created by mac on 2021/12/20.
//

#import <LibVECore/PEAssetManager.h>
#import "PECoreTemplateImageAsset.h"
#import "PECoreTemplateAssetManagerBackground.h"

NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateOverlay : NSObject
/** 标识符
 */
@property (nonatomic,strong) NSString *identifier;
/** 组Id
 */
@property (nonatomic, assign) int groupId;
/** 类型
 */
@property (nonatomic, assign) OverlayType type;
/** 媒体
 */
@property (nonatomic, strong) PECoreTemplateImageAsset *media;
/** 背景
 */
@property (nonatomic, strong) PECoreTemplateAssetManagerBackground *background;

- (instancetype)initWithOverlay:(PEOverlay *)overlay;
- (PEOverlay *)getOverlayWithFolderPath:(NSString *)folderPath;
@end

NS_ASSUME_NONNULL_END
