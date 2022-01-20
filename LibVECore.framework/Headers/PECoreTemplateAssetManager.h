//
//  PECoreTemplateAssetManager.h
//  LibVECore
//
//  Created by mac on 2021/12/21.
//

#import <LibVECore/PEAssetManager.h>
#import "PECoreTemplateImageAsset.h"
#import "PECoreTemplateAssetManagerBackground.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateAssetManager : NSObject

/** 标识符
 */
@property (nonatomic,strong) NSString *identifier;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 场景背景媒体
*/
@property (nonatomic, strong) PECoreTemplateAssetManagerBackground *background;


/**一个场景中可有多个媒体
 */
@property (nonatomic, strong) NSMutableArray <PECoreTemplateImageAsset*>*media;


- (instancetype)initWithScene:(PEAssetManager *)scene;

- (PEAssetManager *)getSceneWithFolderPath:(NSString *)folderPath;
@end

NS_ASSUME_NONNULL_END
