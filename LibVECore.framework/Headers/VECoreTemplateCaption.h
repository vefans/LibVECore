//
//  VECoreTemplateCaption.h
//  LibVECore
//
//  Created by iOS VESDK Team  on 2021/4/21.
//  Copyright © 2021 iOS VESDK Team. All rights reserved.
//

#import <LibVECore/Scene.h>
#import <LibVECore/VECoreTemplateCustomFilter.h>

@interface VECoreTemplateSubtitleAnimation : CaptionAnimation

/**推入点，动画类型为CaptionAnimationTypeMove时有效(CGPointMake(0, 0)〜CGPointMake(1, 1))。默认为CGPointZero
 * 以字幕center为基准，相对于实际视频size的移动Point
 */
@property (nonatomic, assign) CGPoint pushInPointF;

/**推出点，动画类型为CaptionAnimationTypeMove时有效(CGPointMake(0, 0)〜CGPointMake(1, 1))。默认为CGPointZero
 * 以字幕center为基准，相对于实际视频size的移动Point
 */
@property (nonatomic, assign) CGPoint pushOutPointF;

- (instancetype)initWithCaptionAnimation:(CaptionAnimation *)animate;

- (CaptionAnimation *)getCaptionAnimation;

@end

@interface VECoreTemplateCaptionCustomAnimation : CaptionCustomAnimation

/**透明度(0.0~1.0)，默认1.0
 */
@property (nonatomic,assign) CGFloat alpha;

/**字幕位置，默认为CGRectZero
 */
@property (nonatomic ,assign) CGRect showRectF;

- (instancetype)initWithCaptionCustomAnimation:(CaptionCustomAnimation *)animate;

- (CaptionCustomAnimation *)getCaptionCustomAnimation;

@end

@interface VECoreTemplateSubtitle : Caption

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/**字幕位置，默认为视频中心CGPointMake(0.5, 0.5)
 * 设置字幕动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic, assign) CGPoint centerF;

/**字幕大小，相对于实际视频size的字幕大小(CGPointMake(0, 0)〜CGPointMake(1, 1))
 * 设置字幕动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic, assign) CGSize sizeF;

/**文字内容
 */
@property (nonatomic ,copy) NSString * text;

/**文字字体名称
 */
@property (nonatomic ,copy) NSString * fontName;

/**文字字体路径
 */
@property (nonatomic ,copy) NSString * fontPath;

/**文字颜色，默认为whiteColor
 */
@property (nonatomic, strong) UIColor *textColor;

/**文字对齐方式 默认为CaptionTextAlignmentCenter
 */
@property (nonatomic ,assign) CaptionTextAlignment textAlignment;

/**文字阴影颜色，默认黑色blackColor
 */
@property (nonatomic, strong) UIColor *shadowColor;

/**文字阴影偏移量
 */
@property (nonatomic, assign) float shadowWidth;

/** 文字区域
 */
@property (nonatomic, assign) CGRect textShowRectF;

/** 字幕文字动画
 *  设置字幕动画组后，该属性无效
 */
@property (nonatomic, strong) VECoreTemplateSubtitleAnimation * textAnimation;

/**字幕背景图动画
 *  设置字幕动画组后，该属性无效
 */
@property (nonatomic, strong) VECoreTemplateSubtitleAnimation * imageAnimation;

/** 字幕动画组
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateCaptionCustomAnimation *>*animates;

/**是否上下镜像
 */
@property (nonatomic, assign) BOOL isVerticalMirror;

/**是否左右镜像
 */
@property (nonatomic, assign) BOOL isHorizontalMirror;

- (instancetype)initWithCaption:(Caption *)caption videoSize:(CGSize)videoSize;

- (Caption *)getSubtitleWithFolderPath:(NSString *)folderPath videoSize:(CGSize)videoSize;

@end

@interface VECoreTemplateSticker : Caption

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/**贴纸位置，默认为视频中心CGPointMake(0.5, 0.5)
 * 设置贴纸动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic, assign) CGPoint centerF;

/**贴纸大小，相对于实际视频size的字幕大小(CGPointMake(0, 0)〜CGPointMake(1, 1))
 * 设置贴纸动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic, assign) CGSize sizeF;

/** 贴纸动画组
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateCaptionCustomAnimation *>*animates;

/** 自定义动画
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateCustomAnimation *>*customAnimations;

/**是否上下镜像
 */
@property (nonatomic, assign) BOOL isVerticalMirror;

/**是否左右镜像
 */
@property (nonatomic, assign) BOOL isHorizontalMirror;

- (instancetype)initWithCaption:(Caption *)caption;

- (Caption *)getStickerWithFolderPath:(NSString *)folderPath;

@end
