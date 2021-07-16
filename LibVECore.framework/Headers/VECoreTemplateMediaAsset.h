//
//  VECoreTemplateMediaAsset.h
//  LibVECore
//
//  Created by iOS VESDK Team  on 2021/4/21.
//  Copyright © 2021 iOS VESDK Team. All rights reserved.
//

#import <LibVECore/Scene.h>
#import <LibVECore/VECoreTemplateCustomFilter.h>
#import <LibVECore/VECoreTemplateMask.h>

@interface VECoreTemplateMediaAssetBlur : MediaAssetBlur

/** 设置模糊在虚拟视频中的开始时间
 *  设置媒体动画后，该属性无效，以动画中的atTime为准
 */
@property (nonatomic, assign) float timelineFrom;

/** 设置模糊在虚拟视频中的结束时间
 *  设置媒体动画后，该属性无效，以动画中的atTime为准
 */
@property (nonatomic, assign) float timelineTo;

- (instancetype)initWithMediaBlur:(MediaAssetBlur *)blur;

@end

@interface VECoreTemplateMediaAssetAnimate : MediaAssetAnimatePosition

/**在video中的位置大小，默认CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 * rect与pointsArray只有一个有效，以最后设置的为准
 */
@property (nonatomic, assign) CGRect showRectF;

/**视频(或图片)裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 */
@property (nonatomic, assign) CGRect cropRect;

- (instancetype)initWithMediaAnimate:(MediaAssetAnimatePosition *)animate;

- (MediaAssetAnimatePosition *)getMediaAssetAnimatePosition;

@end

@interface VECoreTemplateMediaAsset : MediaAsset

/**  资源地址 图片  视频
 */
@property (nonatomic, strong) NSString *path;

/** 媒体截取开始时间
 */
@property (nonatomic, assign) float trimTimeStart;

/** 媒体截取结束时间
 */
@property (nonatomic, assign) float trimTimeEnd;

/**视频(或图片)裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 * 设置媒体动画后，该属性无效，以动画中的crop为准
 */
@property (nonatomic, assign) CGRect cropRect;

/**在video中的范围。默认为CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 * rectInVideo与pointsInVideoArray只有一个有效，以最后设置的为准
 * 设置媒体动画后，该属性及pointsInVideoArray属性均无效，以动画中的rect或pointsArray值为准
 */
@property (nonatomic, assign) CGRect showRectF;

/**抠图精度，0.0~1.0,默认为0.5
 */
@property (nonatomic, assign) float cutoutFactor;

/** 要透过的颜色，须与视频或者图片中一致，FilterBlendType 需要设置为 FilterBlendTypeChromaColor 否则无效
*/
@property (nonatomic, strong) UIColor *cutoutColor;

/**滤镜资源地址
 */
@property (nonatomic, strong) NSString *filterPath;

/** 媒体动画组
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMediaAssetAnimate*>*animates;

/**设置媒体自定义特效。
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateSpecialEffect*>* specialEffects;

/** 设置媒体自定义多脚本特效
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMultipleSpecialEffect*>* multipleSpecialEffects;

/**设置媒体自定义动画（入场、出场、组合）
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateCustomAnimation*>* customAnimations;

/**蒙版
 */
@property (nonatomic, strong) VECoreTemplateMask *maskObject;

- (instancetype)initWithMediaAsset:(MediaAsset *)asset;

- (MediaAsset *)getMediaAssetWithFolderPath:(NSString *)folderPath;

@end
