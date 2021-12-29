//
//  PECoreTemplateImageAsset.h
//  LibVECore
//
//  Created by mac on 2021/12/20.
//


#import "VECoreTemplateInfo.h"
#import <LibVECore/PEAssetManager.h>
#import <LibVECore/VECoreTemplateCustomFilter.h>
#import <LibVECore/VECoreTemplateMask.h>

NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateImageAsset : PEImageAsset
@property (nonatomic, strong) NSString *path;

/**滤镜资源地址
 */
@property (nonatomic, strong) NSString *filterPath;

/**图片裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 */
@property (nonatomic, assign) CGRect cropRect;
/**在图片中的范围。默认为CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 */
@property (nonatomic, assign) CGRect showRectF;

@property (nonatomic, strong)VECoreTemplateToningInfo * toningInfo;

/**蒙版
 */
@property (nonatomic, strong) VECoreTemplateMask *maskObject;

- (instancetype)initWithMediaAsset:(PEImageAsset *)asset;

- (PEImageAsset *)getMediaAssetWithFolderPath:(NSString *)folderPath;

@end

NS_ASSUME_NONNULL_END
