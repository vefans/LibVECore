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

/** 层次，数值越大，越靠前，0 为最底层，默认为 0
 */
@property(nonatomic,assign) int level;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

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

- (CaptionEx *)getSubtitleExWithFolderPath:(NSString *)folderPath videoSize:(CGSize)videoSize;



@end

@interface VECoreTemplateWordItem : CaptionItem

/** 花字类型
 */
@property (nonatomic, strong) NSString *flowerCategoryId;

/** 在VECoreTemplateSubtitleEx中的开始时间
 */
@property (nonatomic, assign) float startTime;

/** 在VECoreTemplateSubtitleEx中的显示时长
 * 0,0  表示在整个VECoreTemplateSubtitleEx的timeRange内显示
 */
@property (nonatomic, assign) float duration;

/** 文字区域(相对于CaptionEx)
 */
@property (nonatomic, assign) CGRect showRectF;

/** 文字透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic ,assign) float opacity;

/**文字阴影颜色【纯色】
 */
@property (nonatomic ,strong) UIColor* shadowColor;

/**文字阴影偏移量
 */
@property (nonatomic ,assign) float shadowDistance;

/**文字阴影角度 （默认-45）范围(-180 ---> 180)
 */
@property (nonatomic ,assign) float shadowAngle;

/**文字阴影模糊度
 */
@property (nonatomic ,assign) float shadowBlur;

/**文字描边颜色，默认黑色blackColor
 */
@property (nonatomic ,strong) UIColor *strokeColor;

/**文字描边宽度,默认为0.0
 */
@property (nonatomic ,assign) float strokeWidth;

/** 入场/出场/组合动画
 *
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateCustomAnimation *>*animates;

- (instancetype)initWithCaptionItem:(CaptionItem *)captionItem;

- (CaptionItem *)getCaptionItemWithFolderPath:(NSString *)folderPath;

@end

@interface VECoreTemplateSubtitleEx : CaptionEx

@property (nonatomic, assign)VEPIPType  pipType;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/** 显示区域
 */
@property (nonatomic, assign) CGRect showRectF;

/** 字幕图片文件夹路径
 *  多张图片的情况，与imageName、timeArray及frameArray配合使用
 */
@property (nonatomic ,copy) NSString *folderPath;

/** 文字
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateWordItem*>* wordItem;

/** 关键帧动画
 * 与normalAnimate互斥
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateCaptionCustomAnimation*>* keyFrameAnimates;

/**高级动画(脚本)
 *
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateCustomAnimation *>*animates;

- (instancetype)initWithCaption:(CaptionEx *)caption videoSize:(CGSize)videoSize;
- (instancetype)initWithCaption:(CaptionEx *)caption videoSize:(CGSize)videoSize rootPath:(NSString *)rootPath isExportResources:(BOOL)isExportResources;
- (instancetype)initWithCaption:(CaptionEx *)caption videoSize:(CGSize)videoSize rootPath:(NSString *)rootPath;

- (CaptionEx *)getSubtitleWithFolderPath:(NSString *)folderPath videoSize:(CGSize)videoSize;

@end

@interface VECoreTemplateSubtitleTemplate : CaptionEx

@property(nonatomic, assign)VEPIPType  pipType;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/** 显示区域
 */
@property (nonatomic, assign) CGRect showRectF;

/** 字幕图片文件夹路径
 *  多张图片的情况，与imageName、timeArray及frameArray配合使用
 */
@property (nonatomic ,copy) NSString *folderPath;

/**文字内容
 */
@property (nonatomic ,copy) NSMutableArray<NSString *>*content;

/** 关键帧动画
 * 与normalAnimate互斥
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateCaptionCustomAnimation*>* keyFrameAnimates;

- (instancetype)initWithCaption:(CaptionEx *)caption videoSize:(CGSize)videoSize;

- (CaptionEx *)getSubtitleWithFolderPath:(NSString *)folderPath videoSize:(CGSize)videoSize;

@end

@interface VECoreTemplateSticker : CaptionEx

@property(nonatomic, assign)VEPIPType   pipType;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/**贴纸位置，默认为视频中心CGPointMake(0.5, 0.5)
 * 设置贴纸动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic, assign) CGPoint centerF;

/**贴纸大小，相对于实际视频size的字幕大小(CGPointMake(0, 0)〜CGPointMake(1, 1))
 * 设置贴纸动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic, assign) CGSize sizeF;

/** 混合模式
*/
@property (nonatomic, assign) NSInteger blendType;

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

/** 配乐音量
 */
@property (nonatomic, assign) float volume;

/** 配乐音量关键帧
 */
@property (nonatomic, strong) NSMutableArray <AudioVolumePosition *> *volumePointArray;

/** 字幕类型
 *  导出模板用。1表示 遮挡贴纸
 */
@property (nonatomic, assign) NSInteger stickerType;

- (instancetype)initWithCaption:(Caption *)caption;

- (Caption *)getStickerWithFolderPath:(NSString *)folderPath;

- (instancetype)initWithCaptionEx:(CaptionEx *)caption;
- (instancetype)initWithCaptionEx:(CaptionEx *)caption rootPath:(NSString *)rootPath;

- (CaptionEx *)getStickerExWithFolderPath:(NSString *)folderPath;

@end
