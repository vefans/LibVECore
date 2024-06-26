//
//  PECoreTemplateImageAsset.h
//  LibVECore
//
//  Created by iOS VESDK Team on 2021/12/20.
//


#import "VECoreTemplateInfo.h"
#import <LibVECore/PEAssetManager.h>
#import <LibVECore/VECoreTemplateCustomFilter.h>
#import <LibVECore/VECoreTemplateMask.h>

NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateImageAsset : PEImageAsset

/** 组Id
 */
@property (nonatomic, assign) int groupId;

@property (nonatomic, strong) NSString *path;

@property (nonatomic, strong) NSString * segmentManualKeyPath;

/**滤镜资源
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


/** 亮度 ranges from -1.0 to 1.0, with 0.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 brightness值 或者 adjustments值为准
 */
@property (nonatomic, assign) float brightness;

/** 对比度 ranges from 0.0 to 4.0 (max contrast), with 1.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 contrast值 或者 adjustments为准
 */
@property (readwrite, nonatomic) float contrast;

/** 饱和度 ranges from 0.0 (fully desaturated) to 2.0 (max saturation), with 1.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 saturation值 或者 adjustments值为准
*/
@property (nonatomic, assign) float saturation;


/** 暗角 ranges from 0.0 to 1.0 , with 0.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 vignette值 或者 adjustments值为准
 */
@property (nonatomic, assign) float vignette;

/** 锐化 ranges from -4.0 to 4.0 , with 0.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 sharpness值 或者 adjustments值为准
 */
@property (nonatomic, assign) float sharpness;

/** 色温 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 whiteBalance值 或者 adjustments值为准
 */
@property (nonatomic, assign) float whiteBalance;

/** 调色
 *  如果 adjustments 为空，调色以 brightness / contrast / saturation / vignette / sharpness / whiteBalance 为准
 *  如果 adjustments 不为空， brightness / contrast / saturation / vignette / sharpness / whiteBalance 属性无效
 *//** 色调 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的tint值为准
 */
@property (nonatomic, assign) float tint;

/** 阴影 ranges from 0.0 to 1.0 , with 0.0 as the normal level
 */
@property (nonatomic, assign) float shadows;

/** 颗粒 ranges from 0.0 to 1.0 , with 0.0 as the normal level
 */
@property (nonatomic, assign) float graininess;

/** 高光 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 */
@property (nonatomic, assign) float highlight;

/** 光感 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 */
@property (nonatomic, assign) float lightSensation;

/** 褪色 ranges from 0.0 to 1.0 (max fade) , with 0.0 as the normal level
 */
@property (nonatomic, assign) float fade;

/** 曝光 ranges from -1.0 to 1.0 (max exposure) , with 0.0 as the normal level
 */
@property (nonatomic, assign) float exposure;

/** hsl
 */
@property (nonatomic, strong) HSL*  hsl;

/** highLight shadow
 */
@property (nonatomic, strong) HighLightShadow*  highLight_shadow;

/** rgb曲线调节
 */
@property (nonatomic, strong) RGBCurve*  rgb;

@property (nonatomic, assign) kAutoSegmentType segementType;

/**设置媒体自定义特效。
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateSpecialEffect*>* filterArray;

/**设置媒体自定义特效。
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateSpecialEffect*>* effects;

/**蒙版
 */
@property (nonatomic, strong) VECoreTemplateMask *maskObject;

/** hdr 强度设置
 */
@property(nonatomic, assign) float  hdrIntensity;
 
- (instancetype)initWithMediaAsset:(PEImageAsset *)asset;

- (PEImageAsset *)getMediaAssetWithFolderPath:(NSString *)folderPath;

/**
 五官美颜，左眼相关坐标点 (参考坐标点：55，54，53，52，57，56)，如果设置该参数，需要通过 FaceAttribute 控制效果
 */
@property (nonatomic,strong) NSMutableArray* facesPoints;

@end

NS_ASSUME_NONNULL_END
