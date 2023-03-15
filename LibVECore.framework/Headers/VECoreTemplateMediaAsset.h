//
//  VECoreTemplateMediaAsset.h
//  LibVECore
//
//  Created by iOS VESDK Team  on 2021/4/21.
//  Copyright © 2021 iOS VESDK Team. All rights reserved.
//

#import <LibVECore/Scene.h>
#import <LibVECore/VECoreTemplateCustomFilter.h>
#import <LibVECore/VECoreTemplateCaption.h>
#import <LibVECore/VECoreTemplateMask.h>

@interface VECoreTemplateMediaAssetBlur : MediaAssetBlur

/** 设置模糊在虚拟视频中的开始时间
 *  设置媒体动画后，该属性无效，以动画中的atTime为准
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 设置模糊在虚拟视频中的结束时间
 *  设置媒体动画后，该属性无效，以动画中的atTime为准
 */
@property (nonatomic, assign) Float64 timelineTo;

- (instancetype)initWithMediaBlur:(MediaAssetBlur *)blur;

@end

@interface VECoreTemplateMediaAssetAnimate : MediaAssetAnimatePosition

/**在video中的位置大小，默认CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 * showRectF与pointsF只有一个有效，以最后设置的为准
 */
@property (nonatomic, assign) CGRect showRectF;

/**在video中四个顶点(左上,右上,右下,左下)的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * showRectF与pointsF只有一个有效，以最后设置的为准
 */
@property (nonatomic, strong) NSArray *pointsF;

/**视频(或图片)裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 */
@property (nonatomic, assign) CGRect cropRect;

/** 色调 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的tint值为准
 */
@property (nonatomic, assign) float tint;

/** 阴影 ranges from-1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的shadows值为准
 */
@property (nonatomic, assign) float shadows;

/** 颗粒 ranges from 0.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的graininess值为准
 */
@property (nonatomic, assign) float graininess;

/** 高光 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的highlight值为准
 */
@property (nonatomic, assign) float highlight;

/** 光感 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的lightSensation值为准
 */
@property (nonatomic, assign) float lightSensation;

/** 褪色 ranges from 0.0 to 1.0 (max fade) , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的fade值为准
 */
@property (nonatomic, assign) float fade;

/** 曝光 ranges from -1.0 to 1.0 (max exposure) , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的fade值为准
 */
@property (nonatomic, assign) float exposure;

/** 设置模糊强度0.0~1.0，默认为0.0
 */
@property (nonatomic, assign)BlurType blurType;


/** 设置模糊强度0.0~1.0，默认为0.0
 */
@property (nonatomic, assign)float intensity;


/** 设置模糊中心，默认为屏幕中心 (0.5,0.5)
 */
@property (nonatomic, assign)CGPoint centerPoint;


/** 设置模糊半径，默认为0.0
 */
@property (nonatomic, assign)float radius;


- (instancetype)initWithMediaAnimate:(MediaAssetAnimatePosition *)animate;

- (MediaAssetAnimatePosition *)getMediaAssetAnimatePosition;

@end

@interface VECoreTemplateMediaAsset : MediaAsset

/**  资源地址 图片  视频
 */
@property (nonatomic, strong) NSString *path;

/** 媒体截取开始时间
 */
@property (nonatomic, assign) Float64 trimTimeStart;

/** 媒体截取结束时间
 */
@property (nonatomic, assign) Float64 trimTimeEnd;

/**视频(或图片)裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 * 设置媒体动画后，该属性无效，以动画中的crop为准
 */
@property (nonatomic, assign) CGRect cropRect;

/**在video中的范围。默认为CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 * showRectF与pointsF只有一个有效，以最后设置的为准
 * 设置媒体动画后，该属性及pointsF属性均无效，以动画中的showRectF或pointsF值为准
 */
@property (nonatomic, assign) CGRect showRectF;

/**在video中四个顶点(左上,右上,右下,左下)的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * showRectF与pointsF只有一个有效，以最后设置的为准
 * 设置媒体动画后，该属性及showRectF属性均无效，以动画中的showRectF或pointsF值为准
 */
@property (nonatomic, strong) NSArray *pointsF;

/**抠图精度，0.0~1.0,默认为0.5
 */
@property (nonatomic, assign) float cutoutFactor;

/** 要透过的颜色，须与视频或者图片中一致，FilterBlendType 需要设置为 FilterBlendTypeChromaColor 否则无效
*/
@property (nonatomic, strong) UIColor *cutoutColor;

/**滤镜资源地址
 */
@property (nonatomic, strong) NSString *filterPath;

/**滤镜条纹启用，kFilterType_Mosaic时有效,默认为YES
 */
@property (nonatomic, assign)BOOL strip;

/** 色调 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的tint值为准
 */
@property (nonatomic, assign) float tint;

/** 阴影 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的shadows值为准
 */
@property (nonatomic, assign) float shadows;

/** 颗粒 ranges from 0.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的graininess值为准
 */
@property (nonatomic, assign) float graininess;

/** 高光 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的highlight值为准
 */
@property (nonatomic, assign) float highlight;

/** 光感 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的lightSensation值为准
 */
@property (nonatomic, assign) float lightSensation;

/** 褪色 ranges from 0.0 to 1.0 (max fade) , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的fade值为准
 */
@property (nonatomic, assign) float fade;

/** 曝光 ranges from -1.0 to 1.0 (max exposure) , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的fade值为准
 */
@property (nonatomic, assign) float exposure;

/** 媒体动画组
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMediaAssetAnimate*>*animates;

/**文字蒙版
 */
@property (nonatomic, strong)VECoreTemplateSubtitleEx * maskCaption;

/**设置媒体自定义特效。
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateSpecialEffect*>* specialEffects;

/**设置媒体自定义动画（入场、出场、组合）
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateCustomAnimation*>* customAnimations;

/**3D动画
 */
@property (nonatomic, strong) VECoreTemplateAnimation3D *animate3D;

/**蒙版
 */
@property (nonatomic, strong) VECoreTemplateMask *maskObject;

/**智能抠像
 */
@property (nonatomic, assign) BOOL autoSegment;
@property (nonatomic, assign) kAutoSegmentType segmentType;

- (instancetype)initWithMediaAsset:(MediaAsset *)asset;

- (MediaAsset *)getMediaAssetWithFolderPath:(NSString *)folderPath;

@end
