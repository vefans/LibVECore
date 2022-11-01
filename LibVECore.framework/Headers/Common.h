//
//  Common.h
//  VECore
//
//  Created by iOS SDK Team on 2017/5/22.
//  Copyright © 2017年 iOS SDK Team. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class CustomFilter;
typedef void(^LoadTracksFinishBlock)(float progress);
typedef NSData*(^GetParticleHistoryDataBlock)(void);


typedef NS_ENUM(NSInteger, ImageMediaFillType) {
    ImageMediaFillTypeFull, // 全填充
    ImageMediaFillTypeFit,  // 适配 静止
    ImageMediaFillTypeAspectFill,
    ImageMediaFillTypeFitZoomOut, // 适配 缩小
    ImageMediaFillTypeFitZoomIn   // 适配 放大
};


typedef NS_ENUM(NSInteger, FilterBlendType) {
    FilterBlendTypeNormal,          //常规贴图
    FilterBlendTypeChromaColor,     //指定颜色透明
    FilterBlendTypeAIChromaColor,   //智能解析图像，自动颜色透明
    FilterBlendTypeDark,            //变暗
    FilterBlendTypeScreen,          //滤色
    FilterBlendTypeOverlay,         //叠加
    FilterBlendTypeMultiply,        //正片叠底
    FilterBlendTypeLighten,         //变亮
    FilterBlendTypeHardLight,       //强光
    FilterBlendTypeSoftLight,       //柔光
    FilterBlendTypeLinearBurn,      //线性加深
    FilterBlendTypeColorBurn,       //颜色加深
    FilterBlendTypeColorDodge,      //颜色减淡
    FilterBlendTypeMask,            //左右结构mask
};


typedef NS_ENUM(NSInteger, FilterType) {
    kFilterTypeNone = 0,            // 原始
    kFilterType_HeiBai,             // 黑白
    kFilterType_SuiYue,             // 岁月
    kFilterType_FanXiang,           // 反向
    kFilterType_BianYuan,           // 边缘
    kFilterType_NiuQu,              // 扭曲
    kFilterType_Turn,               // 反转
    kFilterType_SLBP,               // SLBP
    kFilterType_Sketch,             // 素描
    kFilterType_DistortingMirror,   // 哈哈镜
    kFilterType_ACV,                // acv滤镜
    kFilterType_LookUp,             // lookup滤镜
    kFilterType_Mosaic              // 马赛克像素化
};

typedef NS_ENUM(NSInteger, OverlayType) {
    OverlayTypeNormal,  //画中画
    OverlayTypeDoodle,  //涂鸦
    OverlayTypeCover,   //封面
    OverlayTypeLogo,    //水印
    OverlayTypeFrame,    //边框
    OverlayTypeSuperposi, //叠加
    OverlayTypeBackground, //画中画背景
};

typedef NS_ENUM(NSInteger, kAutoSegmentType) {
    kAutoSegmentType_None       = 0,    //无
    kAutoSegmentType_Portrait   = 1,    //人像
    kAutoSegmentType_Reverse    = 2,    //反向抠图
    kAutoSegmentType_Sky        = 3,    //天空
};

//字幕类型
typedef NS_ENUM(NSInteger, CaptionType) {
    CaptionTypeHasText = 0,   //带文字
    CaptionTypeNoText         //不带文字
};

//字幕对齐方式
typedef NS_ENUM(NSInteger, CaptionTextAlignment) {
    CaptionTextAlignmentLeft = 0,
    CaptionTextAlignmentCenter,
    CaptionTextAlignmentRight
};

//字幕遮罩类型
typedef NS_ENUM(NSInteger, CaptionTextmMaskType) {
    CaptionTextMaskNone = 0,       //无效果
    CaptionTextMaskHollow,         //镂空效果
    
};


#pragma mark - Caption effect color

struct CGVec3 {
    float x;
    float y;
    float z;
};
typedef struct CGVec3 CGVec3;

typedef NS_ENUM(NSInteger, AnimationInterpolationType) {
    AnimationInterpolationTypeLinear, // 线性(匀速)
    AnimationInterpolationTypeAccelerateDecelerate, //在动画开始结束的地方速率改变比较慢，中间加速
    AnimationInterpolationTypeAccelerate, // 加速
    AnimationInterpolationTypeDecelerate, // 减速
    AnimationInterpolationTypeCycle,
};

@interface CaptionEffectColor : NSObject<NSCopying, NSMutableCopying>

/**文字颜色
 */
@property (nonatomic ,strong) UIColor *  color;

/**
 * 如果gradient为true时，代表指定位置颜色渐变范围:
*       如两个颜色，需要设置第一个颜色factor为0.0,第二个颜色factor为1.0，
 *       如果第一个颜色factor大于了0.1,第二个颜色factor小于了1.0，则渐变范围会缩短，而且会移动位置
 * 如果gradient为false时，代表指定位置颜色具体占比;
 *      如两个颜色，只需要设置第一个颜色factor为0.5即可
 */

@property (nonatomic, assign) float factor;

@end

#pragma mark - CaptionAnimation 字幕动画

/** 动画类型
 *  CaptionAnimationTypeMove时，需设置属性pushInPoint、pushOutPoint
 *  CaptionAnimationTypeScaleInOut时，需设置属性scaleIn、scaleOut
 */
typedef NS_ENUM(NSInteger, CaptionAnimationType) {
    CaptionAnimationTypeNone,               //无
    CaptionAnimationTypeMove,               //移动
    CaptionAnimationTypeScaleInOut,         //缩放入出
    CaptionAnimationTypeScrollInOut,        //滚动入出
    CaptionAnimationTypeFadeInOut,          //淡入淡出
};

@interface CaptionAnimation : NSObject<NSCopying, NSMutableCopying>

/**是否淡入淡出，默认YES
 */
@property (nonatomic, assign) BOOL isFade;

/**淡入时长，默认为1.0
 */
@property (nonatomic, assign) float fadeInDuration;

/**淡出时长，默认为1.0
 */
@property (nonatomic, assign) float fadeOutDuration;

/**动画类型
 */
@property (nonatomic, assign) CaptionAnimationType type;

/**进入时动画类型
 * 设置type后，该属性无效
*/
@property (nonatomic, assign) CaptionAnimationType inType;

/**消失时动画类型
 * 设置type后，该属性无效
*/
@property (nonatomic, assign) CaptionAnimationType outType;

/**动画进入时展示时长，默认为2.0
 */
@property (nonatomic, assign) float inDuration;

/**动画消失时展示时长，默认为2.0
 */
@property (nonatomic, assign) float outDuration;

/**推入点，动画类型为CaptionAnimationTypeMove时有效(CGPointMake(0, 0)〜CGPointMake(1, 1))。默认为CGPointZero
 * 以字幕center为基准，相对于实际视频size的移动Point
 */
@property (nonatomic, assign) CGPoint pushInPoint;

/**推出点，动画类型为CaptionAnimationTypeMove时有效(CGPointMake(0, 0)〜CGPointMake(1, 1))。默认为CGPointZero
 * 以字幕center为基准，相对于实际视频size的移动Point
 */
@property (nonatomic, assign) CGPoint pushOutPoint;

/**动画类型为CaptionAnimationTypeScaleInOut时有效，设置进入时的放大/缩小倍数(0.0~1.0)。
 * 默认为0.0。效果为进入时，字幕从0.5倍，在duration内逐渐放大到scaleOut倍。
 */
@property (nonatomic, assign) float scaleIn;

/**动画类型为CaptionAnimationTypeScaleInOut时有效，设置消失时的放大/缩小倍数(0.0~1.0)。
 * 默认为1.0。效果为消失时，字幕从1.0倍，在duration内逐渐缩小到scaleIn倍再消失。
 */
@property (nonatomic, assign) float scaleOut;

@end

/** 可设置字幕每帧的动画
 */
@interface CaptionCustomAnimation : NSObject

/**开始时间
 */
@property (nonatomic,assign) CGFloat atTime;

/**旋转角度
 */
@property (nonatomic,assign) CGFloat rotate;

/**字幕位置，默认为CGRectZero
 */
@property (nonatomic ,assign) CGRect rect;

/**透明度(0.0~1.0)，默认1.0
 */
@property (nonatomic,assign) CGFloat opacity;

/**动画类型
 */
@property (nonatomic,assign) AnimationInterpolationType type;

/**轨迹
 */
@property (nonatomic,strong) UIBezierPath*  path;

/** 字幕缩放大小，默认1.0
 */
@property (nonatomic,assign) CGFloat scale;

@end

#pragma mark - 文字颜色配置通用参数

@interface CaptionEffectColorParam : NSObject<NSCopying, NSMutableCopying>

/**
 * 是否为渐变色，
 * true代表渐变色，否则代表分段色，即过度很直接
 */
@property (nonatomic, assign) bool gradient;

/**
* 轮廓宽度(0-1.0)；
 *      如果第一层和第二层outline都设置为0.2时,第一层是看不见的，除非颜色是半透的
*/
@property (nonatomic, assign) float outlineWidth;

/**
 * 颜色角度向量，多个颜色时可支持一定角度偏移
 */
@property (nonatomic, assign) CGVec3 colorAngleFactor;


/**
 * 颜色定义,gradient为false时最大支持三个颜色，为true时最大支持五个颜色
 */
@property (nonatomic, strong) NSMutableArray<CaptionEffectColor*>* colors;

@end

#pragma mark - Caption shadow

@interface CaptionShadow : NSObject<NSCopying, NSMutableCopying>

/**文字阴影自适应颜色, true时,shadowColors设置无效
 */
@property (nonatomic ,assign) bool shadowAutoColor;


/**文字阴影颜色【纯色】
 */
@property (nonatomic ,strong) UIColor* shadowColor;

/**
 * 文字阴影颜色【多种颜色】与shadowColor互斥
 */
@property (nonatomic, strong) CaptionEffectColorParam *shadowColors;

/**
 *  (轮廓)文字阴影颜色配置,最大支持3层轮廓
 */
@property (nonatomic, strong) NSMutableArray<CaptionEffectColorParam*>* shadowStrokes;

/**文字阴影偏移量
 */
@property (nonatomic ,assign) float shadowDistance;

/**文字阴影角度 （默认-45）范围(-180 ---> 180)
 */
@property (nonatomic ,assign) float shadowAngle;

/**文字阴影模糊度
 */
@property (nonatomic ,assign) float shadowBlur;

@end



#pragma mark - 文字花字配置
@interface CaptionEffectCfg : NSObject<NSCopying, NSMutableCopying>

/**
 * 普通文字颜色配置
 */
@property (nonatomic, strong) CaptionEffectColorParam *normal;


/**
 *  (轮廓)文字颜色配置,最大支持3层轮廓
 */
@property (nonatomic, strong) NSMutableArray<CaptionEffectColorParam*>* strokes;


/**
 * 阴影配置
 */
@property (nonatomic, strong) CaptionShadow* shadow DEPRECATED_MSG_ATTRIBUTE("Use shadows instead.");

/**
 * 多层阴影配置
 */
@property (nonatomic, strong) NSMutableArray<CaptionShadow*>* shadows;

@end



#pragma mark - 单个文字

@interface CaptionItem : NSObject<NSCopying, NSMutableCopying>

/** 花字类型
 *  导出模板用
 */
@property (nonatomic, assign) NSInteger flowerTextType;

/** 花字资源地址
 *  导出模板用
 */
@property (nonatomic, strong) NSString *flowerPath;

/**单个文字时间范围(相对于CaptionEx)
 * 0,0  表示在整个CaptionEx的timeRange内显示（ PECore 默认与虚拟视频一致，不需设置）
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/**字幕背景色，默认无
 */
@property (nonatomic ,strong) UIColor *  backgroundColor;

/**文字内容
 */
@property (nonatomic ,copy) NSString * text;

/** 文字区域(相对于CaptionEx,注意：origin为中心位置,并非左上角)
 */
@property (nonatomic ,assign) CGRect  frame;

/** 文字区域(相对于CaptionEx, isStretch有效)(0-->1.0)
 */
@property (nonatomic ,assign) CGRect  padding;

/**文字字体名称
 */
@property (nonatomic ,copy) NSString * fontName;

/**文字字体路径
 */
@property (nonatomic ,copy) NSString * fontPath;

/**文字字体大小
 */
@property (nonatomic ,assign) float fontSize;

/** 文字行间距(-1.0〜1.0),默认为0.0
 */
@property (nonatomic ,assign) float lineSpacing;

/** 文字字间距(-1.0〜1.0),默认为0.0
 */
@property (nonatomic ,assign) float wordSpacing;

/**文字字体加粗，默认为NO
 */
@property (nonatomic ,assign) BOOL isBold;

/**文字字体斜体，默认为NO
 */
@property (nonatomic ,assign) BOOL isItalic;

/** 文字竖排，默认为NO
 */
@property (nonatomic ,assign) BOOL isVertical;

/** 文字下划线，默认为NO
 */
@property (nonatomic ,assign) BOOL isUnderline;

/**文字对齐方式 默认为CaptionTextAlignmentCenter
 */
@property (nonatomic ,assign) CaptionTextAlignment textAlignment;

/** 文字旋转度数
 */
@property (nonatomic ,assign) float angle;

/**文字颜色，默认为whiteColor
 */
@property (nonatomic ,strong) UIColor * textColor;

/** 卡拉ok文字颜色
 */
@property (nonatomic ,strong) UIColor * ktvColor;

/** 卡拉ok描边颜色
 */
@property (nonatomic ,strong) UIColor * ktvOutlineColor;

/** 卡拉ok阴影颜色
 */
@property (nonatomic ,strong) UIColor * ktvShadowColor;

/** 文字透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic ,assign) float alpha;

/** 遮罩类型
 */
@property (nonatomic ,assign) CaptionTextmMaskType maskType;

/**文字阴影
 */
@property (nonatomic ,strong) CaptionShadow *shadow;

/**文字描边
 */
@property (nonatomic ,strong) CaptionEffectColorParam *stroke;

/**文字花字
 */
@property (nonatomic ,strong) CaptionEffectCfg *effectCfg;

/**动画
 */
@property (nonatomic, strong) CustomFilter *animate;

/**出场动画
 */
@property (nonatomic, strong) CustomFilter *animateOut;

/**其他动画，例如：爱心跳动
 */
@property (nonatomic, strong) NSMutableArray<CustomFilter*> *otherAnimates;



@end

#pragma mark - 字幕
@class CaptionEx;

@protocol CaptionExDelegate<NSObject>

@optional
- (void)sizeChanged:(CaptionEx *)sender size:(CGSize)size;

@end





@interface Doodle :NSObject

@property (nonatomic,copy)NSString *path;

//时间范围（ PECore 默认与虚拟视频一致，不需设置）
@property (nonatomic,assign)CMTimeRange timeRange;


@end

@interface DoodleLayer : CALayer<NSCopying, NSMutableCopying>

@property (nonatomic,copy)NSString *path;

@property (nonatomic,assign)CMTimeRange timeRange;

@end


/** 可设置字幕每帧的动画
 */
@interface CaptionLightCustomAnimation : NSObject

/**开始时间
 */
@property (nonatomic,assign) CGFloat atTime;

/**透明度(0.0~1.0)，默认1.0
 */
@property (nonatomic,assign) CGFloat opacity;

/**在video中四个顶点的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * rect与pointsArray只有一个有效，以最后设置的为准
 */
@property (nonatomic, readonly) NSArray *pointsArray;

/**在video中四个顶点的坐标，可设置非矩形，设置的值将赋给pointsArray属性。
 * (0, 0)为左上角 (1, 1)为右下角
 *  @param leftTop      媒体在video中的 左上角 顶点坐标
 *  @param rightTop     媒体在video中的 右上角 顶点坐标
 *  @param rightBottom  媒体在video中的 右下角 顶点坐标
 *  @param leftBottom   媒体在video中的 左下角 顶点坐标
 *
 * rect与pointsArray只有一个有效，以最后设置的为准
 */
- (NSArray *)setPointsLeftTop:(CGPoint)leftTop
                     rightTop:(CGPoint)rightTop
                  rightBottom:(CGPoint)rightBottom
                   leftBottom:(CGPoint)leftBottom;

@end

/** 非矩形字幕
 */
@interface CaptionLight : NSObject<NSCopying, NSMutableCopying>

/** 字幕时间范围 （ PECore 默认与虚拟视频一致，不需设置）
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/** 字幕图片路径
 */
@property (nonatomic ,copy) NSString * imagePath;

/**是否淡入淡出，默认NO
 */
@property (nonatomic, assign) BOOL isFade;

/**淡入时长，默认为1.0
 */
@property (nonatomic, assign) float fadeInDuration;

/**淡出时长，默认为1.0
 */
@property (nonatomic, assign) float fadeOutDuration;

/**在video中四个顶点的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * 设置媒体动画后，该属性无效，以动画中的pointsArray值为准
 */
@property (nonatomic, readonly) NSArray *pointsInVideoArray;

/**在video中四个顶点的坐标，可设置非矩形，设置的值将赋给pointsInVideoArray属性。
 * (0, 0)为左上角 (1, 1)为右下角
 *  @param leftTop      媒体在video中的 左上角 顶点坐标
 *  @param rightTop     媒体在video中的 右上角 顶点坐标
 *  @param rightBottom  媒体在video中的 右下角 顶点坐标
 *  @param leftBottom   媒体在video中的 左下角 顶点坐标
 *
 * 设置媒体动画后，该属性无效，以动画中的pointsArray值为准
 */
- (NSArray *)setPointsInVideoLeftTop:(CGPoint)leftTop
                            rightTop:(CGPoint)rightTop
                         rightBottom:(CGPoint)rightBottom
                          leftBottom:(CGPoint)leftBottom;

/** 字幕动画组
 */
@property (nonatomic, strong) NSArray<CaptionLightCustomAnimation*>* animateList;

@end


#pragma mark - Caption
@interface Caption : NSObject<NSCopying, NSMutableCopying>

/** 标识符
 *  导出模板用
 */
@property (nonatomic,strong) NSString *identifier;

/** 组Id
 *  导出模板用
 */
@property (nonatomic, assign) int groupId;

/**资源分类ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkResourceId;

/** 花字类型
 *  导出模板用
 */
@property (nonatomic, assign) NSInteger flowerTextType;

/**字幕背景色，默认无
 */
@property (nonatomic ,strong) UIColor *  backgroundColor;

/**字幕时间范围（ PECore 默认与虚拟视频一致，不需设置）
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/**字幕旋转角度
 * 设置字幕动画组后，该属性无效，以动画中的rotate值为准
 */
@property (nonatomic ,assign) float angle;

/**字幕缩放大小，默认为1.0
 * 设置字幕动画组后，该属性无效，以动画中的scale值为准
 */
@property (nonatomic ,assign) float scale;

/**透明度(0.0~1.0)，默认1.0
 * 设置字幕动画组后，该属性无效，以动画中的opacity值为准
 */
@property (nonatomic,assign) CGFloat opacity;

/**字幕类型 0 带文字,1 不带文字
 */
@property (nonatomic ,assign) CaptionType type;

/** 字幕图片路径
 *   单张图片的情况，只设置该属性即可
 */
@property (nonatomic ,copy) NSString * captionImagePath;

/** 字幕图片文件夹路径
 *  多张图片的情况，与imageName、timeArray及frameArray配合使用
 */
@property (nonatomic ,copy) NSString * imageFolderPath;

/**图片前缀名字
 */
@property (nonatomic ,copy) NSString * imageName;

/**动画持续时间
 */
@property (nonatomic ,assign) float duration;

/**字幕位置，默认为视频中心CGPointMake(0.5, 0.5)
 * 设置字幕动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic ,assign) CGPoint position;

/**字幕大小，相对于实际视频size的字幕大小(CGPointMake(0, 0)〜CGPointMake(1, 1))
 * 设置字幕动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic ,assign) CGSize size;

/**文字内容
 */
@property (nonatomic ,copy) NSString * pText;

/**文字内容(富文本)
 *  设置富文本后，文字颜色、字体加粗等属性均无效，以富文本的设置为准
 */
@property (nonatomic ,copy) NSMutableAttributedString * attriStr;

/** 文字图片
 */
@property (nonatomic ,strong) UIImage * tImage;

/**文字字体名称
 */
@property (nonatomic ,copy) NSString * tFontName;

/**文字字体路径
 */
@property (nonatomic ,copy) NSString * tFontPath;

/**文字字体大小
 */
@property (nonatomic ,assign) float tFontSize;

/**文字字体加粗，默认为NO
 */
@property (nonatomic ,assign) BOOL isBold;

/**文字字体斜体，默认为NO
 */
@property (nonatomic ,assign) BOOL isItalic;

/**文字对齐方式 默认为CaptionTextAlignmentCenter
 */
@property (nonatomic ,assign) CaptionTextAlignment tAlignment;

/** 文字旋转度数
 */
@property (nonatomic ,assign) float tAngle;

/**文字颜色，默认为whiteColor
 */
@property (nonatomic ,strong) UIColor * tColor;

/** 文字竖排，默认为NO
 *  仅支持一列
 *  设置富文本后，该属性无效
 */
@property (nonatomic ,assign) BOOL isVerticalText;

/**文字是否描边，默认为NO
 */
@property (nonatomic ,assign) BOOL isStroke;

/**文字描边颜色，默认黑色blackColor
 */
@property (nonatomic ,strong) UIColor *  strokeColor;

/**文字描边宽度,默认为0.0
 */
@property (nonatomic ,assign) float strokeWidth;

/** 文字描边透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic, assign) float strokeAlpha;

/**文字内描边颜色，默认黑色blackColor
 */
@property (strong,nonatomic) UIColor *innerStrokeColor;

/**文字内描边宽度,默认为0.0
 */
@property (assign,nonatomic) CGFloat innerStrokeWidth;

/** 文字内描边透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic, assign) float innerStrokeAlpha;

/**文字是否设置阴影，默认为NO
 */
@property (nonatomic ,assign) BOOL isShadow;

/**文字阴影颜色，默认黑色blackColor
 */
@property (nonatomic ,strong) UIColor *  tShadowColor;

/**文字阴影偏移量,默认为CGSizeMake(0, -1)
 */
@property (nonatomic ,assign) CGSize tShadowOffset;

/** 文字阴影透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic, assign) float shadowAlpha;

/** 文字区域
 */
@property (nonatomic ,assign) CGRect  tFrame;

/** 文字透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic ,assign) float textAlpha;

/**帧动画
 */
@property (nonatomic ,strong) NSArray * frameArray;

/**时间动画
 */
@property (nonatomic ,strong) NSArray * timeArray;

/** 字幕是否需要拉伸
 */
@property (nonatomic, assign) BOOL isStretch;

/**字幕拉伸的区域
 */
@property (nonatomic ) CGRect stretchRect;

/**音乐
 */
//@property (nonatomic, strong) MusicInfo * music;

/** 字幕文字动画
 *  设置字幕动画组后，该属性无效
 */
@property (nonatomic, strong) CaptionAnimation * textAnimate;

/**字幕背景图动画
 *  设置字幕动画组后，该属性无效
 */
@property (nonatomic, strong) CaptionAnimation * imageAnimate;

/** 字幕动画组
 * 设置该动画后，textAnimate、imageAnimate均无效
 */
@property (nonatomic, strong) NSMutableArray<CaptionCustomAnimation*>* animate;

/** 字幕是否开启跟踪，默认为NO
 */
@property (nonatomic, assign) BOOL isEnableTracking;

/** 字幕自定义动画
 * 设置该动画后，textAnimate、imageAnimate均无效
 */
@property (nonatomic, strong) CustomFilter *customAnimate;

/** 字幕自定义出场动画
 * 设置该动画后，textAnimate、imageAnimate均无效
 */
@property (nonatomic, strong) CustomFilter *customOutAnimate;

/** 背景
 */
@property (nonatomic, strong) Caption *backgroundCaption;

/**背景偏移量,默认为CGSizeMake(0, -1)
 */
@property (nonatomic ,assign) CGSize backgroundCaptionOffset;

/**X轴翻转
 */
@property (nonatomic ,assign) BOOL flipX;

/**Y轴翻转
 */
@property (nonatomic ,assign) BOOL flipY;

/**高级动画
 * 设置该动画后，textAnimate、imageAnimate customAnimate customOutAnimate 均无效
 */
@property (nonatomic, strong) CustomFilter *templateAnimate DEPRECATED_ATTRIBUTE;


@property (nonatomic, strong) NSMutableArray<CustomFilter*> *otherAnimates;

/**当前控件是否正在编辑
 *编辑状态要全部显示文字
 */
@property (nonatomic, assign) BOOL editing;


@end


@interface CaptionImage : NSObject<NSCopying, NSMutableCopying>


/** 图片路径
 *   单张图片的情况，只设置该属性即可
 */
@property (nonatomic ,copy) NSString * captionImagePath;

/** 图片文件夹路径
 *  多张图片的情况，与imageName、timeArray及frameArray配合使用
 */
@property (nonatomic ,copy) NSString * imageFolderPath;


/**图片前缀名字
 */
@property (nonatomic ,copy) NSString * imageName;

/**帧动画
 */
@property (nonatomic ,strong) NSArray * frameArray;

/**时间动画
 */
@property (nonatomic ,strong) NSArray * timeArray;

/**入场动画
 */
@property (nonatomic, strong) CustomFilter *animate;

/**出场动画
 */
@property (nonatomic, strong) CustomFilter *animateOut;

/**其他动画，例如：手绘
 */
@property (nonatomic, strong) CustomFilter *otherAnimates;


/** 混合模式
*/
@property (nonatomic, assign) FilterBlendType blendType;

@end

typedef NS_ENUM(NSInteger, CaptionExType) {
    CaptionExTypeNormal,    //普通字幕
    CaptionExTypeTemplate,  //文字模板
    CaptionExTypeSpeech,    //语音识别字幕
    CaptionExTypeStickers,  //贴纸
    CaptionExTypeCoverTemplate, //封面模板
    CaptionExTypeCover,     //封面普通字幕
};

//(由0-1个底图+多个文字组成)

@interface CaptionEx : NSObject<NSCopying, NSMutableCopying>
/** 标识符
 *  记录最后操作的时间,用于二次build时排序依据 (最后操作的置顶)
 */
@property (nonatomic, assign)long nLatestZOrderOnTopTime;
/** 标识符
 *  导出模板用
 */
@property (nonatomic,strong) NSString *identifier;

/** 组Id
 *  导出模板用
 */
@property (nonatomic, assign) int groupId;

/**资源分类ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkResourceId;

/** 字幕类型
 *  导出模板用
 */
@property (nonatomic, assign) CaptionExType type;

/**字幕时间范围（ PECore 默认与虚拟视频一致，不需设置）
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/**字幕旋转角度
 * 设置字幕动画组后，该属性无效，以动画中的rotate值为准
 */
@property (nonatomic ,assign) float angle;

/**字幕缩放大小，默认为1.0
 * 设置字幕动画组后，该属性无效，以动画中的scale值为准
 */
@property (nonatomic ,assign) float scale;

/**透明度(0.0~1.0)，默认1.0
 * 设置字幕动画组后，该属性无效，以动画中的opacity值为准
 */
@property (nonatomic,assign) CGFloat opacity;

/** 字幕图片路径
 *   单张图片的情况，只设置该属性即可
 */
@property (nonatomic ,copy) NSString * captionImagePath;

/** 字幕图片文件夹路径
 *  多张图片的情况，与imageName、timeArray及frameArray配合使用
 */
@property (nonatomic ,copy) NSString * imageFolderPath;

/**图片前缀名字
 */
@property (nonatomic ,copy) NSString * imageName;

/** 贴纸/气泡
 */
@property (nonatomic ,strong) CaptionImage * captionImage;


/**字幕位置，默认为视频中心CGPointMake(0.5, 0.5)
 * 设置字幕动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic ,assign) CGPoint position;

/**字幕大小，相对于实际视频size的字幕大小(CGPointMake(0, 0)〜CGPointMake(1, 1))
 * 设置字幕动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic ,assign) CGSize originalSize;

/**拉伸缩放后字幕大小(isStretch 为 YES 时，拉伸之后的真实大小 )
 */
@property (nonatomic ,readonly) CGSize stretchSize;

/**拉伸缩放后文字大小(isStretch 为 YES 时，拉伸之后的真实大小 
 */
@property (nonatomic ,readonly) CGSize stretchTextSize;

/**帧动画
 */
@property (nonatomic ,strong) NSArray * frameArray;

/**时间动画
 */
@property (nonatomic ,strong) NSArray * timeArray;

/**动画持续时间
 */
@property (nonatomic ,assign) float duration;

/** 字幕是否需要拉伸
 */
@property (nonatomic, assign) BOOL isStretch;

/**字幕拉伸的区域(x，y左上角，0-->1)
 */
@property (nonatomic,assign) CGRect stretchRect;

/**字幕拉伸配置时候，文字个数变化引起的大小变化
 */
@property (nonatomic,weak) id<CaptionExDelegate> delegate;

/** 文字
 */
@property (nonatomic, strong) NSMutableArray<CaptionItem*>* texts;

/** 普通动画
 *  与keyFrameAnimate互斥
 */
@property (nonatomic, strong) CaptionAnimation * normalAnimate;

/** 关键帧动画
 * 与normalAnimate互斥
 */
@property (nonatomic, strong) NSMutableArray<CaptionCustomAnimation*>* keyFrameAnimate;

/** 字幕是否开启跟踪，默认为NO
 */
@property (nonatomic, assign) BOOL isEnableTracking;

/**高级动画(脚本)
 *
 */
@property (nonatomic, strong) CustomFilter *animate;

/**高级动画(脚本)
 *
 */
@property (nonatomic, strong) CustomFilter *animateOut;


/**X轴翻转
 */
@property (nonatomic ,assign) BOOL flipX;

/**Y轴翻转
 */
@property (nonatomic ,assign) BOOL flipY;

/** 文本朗读音频文件地址
 */
@property (nonatomic ,strong) NSString *speechPath;

@end

@class KeyFrameAnimate;

/** 调色
*/
@interface ToningInfo : NSObject<NSCopying, NSMutableCopying>
@property (nonatomic, assign) NSInteger tag;
/** 亮度 ranges from -1.0 to 1.0, with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的brightness值为准
 */
@property (nonatomic, assign) float brightness;

/** 对比度 ranges from 0.0 to 4.0 (max contrast), with 1.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的contrast值为准
 */
@property (readwrite, nonatomic) float contrast;

/** 饱和度 ranges from 0.0 (fully desaturated) to 2.0 (max saturation), with 1.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的saturation值为准
*/
@property (nonatomic, assign) float saturation;


/** 暗角 ranges from 0.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的vignette值为准
 */
@property (nonatomic, assign) float vignette;

/** 锐化 ranges from 0.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的sharpness值为准
 */
@property (nonatomic, assign) float sharpness;

/** 色温 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的whiteBalance值为准
 */
@property (nonatomic, assign) float whiteBalance;

/** 色调 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的tint值为准
 */
@property (nonatomic, assign) float tint;

/** 阴影 ranges from 0.0 to 1.0 , with 0.0 as the normal level
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


/** 关键帧动画
 */
@property (nonatomic, strong) NSArray<KeyFrameAnimate*>*  animate;

/** 持续时间（ PECore 默认与虚拟视频一致，不需设置）
 */
@property (nonatomic,assign) CMTimeRange timeRange;

@end


typedef NS_ENUM(NSInteger, BlurType) {
    BlurTypeNone,            // 无效果
    BlurTypeEdge,            // 边缘模糊
    BlurTypeGauss,           // 高斯模糊
    BlurTypeRadial,          // 径向模糊
};

@interface Blur : NSObject<NSCopying, NSMutableCopying>

/** 设置模糊强度0.0~1.0，默认为0.0
 */
@property (nonatomic, assign)BlurType blurType;

/** 模糊遮罩图片（黑白图，白色区域模糊）
 */
@property (nonatomic , strong) NSURL*  maskImageURL;


/** 设置模糊强度0.0~1.0，默认为0.0
 */
@property (nonatomic, assign)float intensity;


/** 设置模糊中心，默认为屏幕中心 (0.5,0.5)
 */
@property (nonatomic, assign)CGPoint centerPoint;


/** 设置模糊半径，默认为0.0
 */
@property (nonatomic, assign)float radius;


@end

@interface KeyFrameAnimate : NSObject

/**开始时间
 */
@property (nonatomic,assign) CGFloat atTime;

/**在video中的位置大小，默认CGRectMake(0, 0, 1, 1),其中(0, 0)为左上角 (1, 1)为右下角

 */
@property (nonatomic,assign) CGRect rect;


/**强度
 */
@property (nonatomic,assign) float intensity;


/**关键帧（该对象中 timeRange 无效）
 */
@property (nonatomic, strong) ToningInfo* adjustments;

@end

@interface MediaAssetBlur : NSObject<NSCopying, NSMutableCopying>

/** 设置模糊类型，现只支持BlurTypeGauss
 */
@property (nonatomic, assign)BlurType type   DEPRECATED_ATTRIBUTE;

/** 设置模糊强度0.0~1.0，默认为0.5,设置关键帧动画后，以关键帧动画值为准
 */
@property (nonatomic, assign)float intensity;

/** 设置在video中没有添加模糊的区域，默认为CGRectZero
 *  (0, 0)为左上角 (1, 1)为右下角
 *  该属性已废弃
 */
@property (nonatomic, assign)CGRect unblurryRect DEPRECATED_MSG_ATTRIBUTE("Use setPointsLeftTop:rightTop:rightBottom:leftBottom: instead.");

/** 设置模糊时长（ PECore 默认与虚拟视频一致，不需设置）,设置关键帧动画后，以关键帧动画值为准
 *  设置媒体动画后，该属性无效，以动画中的atTime为准
 */
@property (nonatomic, assign)CMTimeRange timeRange;

/** 高斯模糊是否开启跟踪，默认为NO
 */
@property (nonatomic, assign) BOOL isEnableTracking;

/** 模糊遮罩图片（黑白图，白色区域模糊）
 */
@property (nonatomic , strong) NSURL*  maskImageURL;


/**在video中四个顶点的坐标，可设置非矩形。,设置关键帧动画后，以关键帧动画值为准
 * (0, 0)为左上角 (1, 1)为右下角
 * 默认为({0, 0},{1, 0},{1, 1},{0, 1})
 */
@property (nonatomic, readonly) NSArray <NSString *> *pointsArray;


/**在video中四个顶点的坐标，可设置非矩形，设置的值将赋给pointsArray属性。
 * (0, 0)为左上角 (1, 1)为右下角
 *  @param leftTop      媒体在video中的 左上角 顶点坐标
 *  @param rightTop     媒体在video中的 右上角 顶点坐标
 *  @param rightBottom  媒体在video中的 右下角 顶点坐标
 *  @param leftBottom   媒体在video中的 左下角 顶点坐标
 */
- (NSArray *)setPointsLeftTop:(CGPoint)leftTop
                     rightTop:(CGPoint)rightTop
                  rightBottom:(CGPoint)rightBottom
                   leftBottom:(CGPoint)leftBottom;


/** 关键帧动画
 */
@property (nonatomic, strong) NSArray<KeyFrameAnimate*>*  animate;

@end

/** 马赛克
 */
@interface Mosaic : NSObject<NSCopying, NSMutableCopying>

/** 时间范围（ PECore 默认与虚拟视频一致，不需设置）,设置关键帧动画后，以关键帧动画值为准
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/** 马赛克大小(0.0~1.0)，默认为0.1，,设置关键帧动画后，以关键帧动画值为准
 */
@property (nonatomic, assign) float mosaicSize DEPRECATED_MSG_ATTRIBUTE("Use size instead.");
@property (nonatomic, assign) float size;

/**在video中四个顶点的坐标，可设置非矩形，设置关键帧动画后，以关键帧动画值为准
 * (0, 0)为左上角 (1, 1)为右下角
 */
@property (nonatomic, readonly) NSArray *pointsArray;

/** 马赛克是否开启跟踪，默认为NO
 */
@property (nonatomic, assign) BOOL isEnableTracking;

/**在video中四个顶点的坐标，可设置非矩形，设置的值将赋给pointsArray属性。设置关键帧动画后，以关键帧动画值为准
 * (0, 0)为左上角 (1, 1)为右下角
 *  @param leftTop      媒体在video中的 左上角 顶点坐标
 *  @param rightTop     媒体在video中的 右上角 顶点坐标
 *  @param rightBottom  媒体在video中的 右下角 顶点坐标
 *  @param leftBottom   媒体在video中的 左下角 顶点坐标
 */
- (NSArray *)setPointsLeftTop:(CGPoint)leftTop
                     rightTop:(CGPoint)rightTop
                  rightBottom:(CGPoint)rightBottom
                   leftBottom:(CGPoint)leftBottom;

/** 关键帧动画
 */
@property (nonatomic, strong) NSArray<KeyFrameAnimate*>*  animate;

@end

/** 去水印
 */
@interface Dewatermark : NSObject

/** 去水印时间范围（ PECore 默认与虚拟视频一致，不需设置）,设置关键帧动画后，以关键帧动画值为准
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/**在video中的位置大小，默认CGRectMake(0, 0, 1, 1)，设置关键帧动画后，以关键帧动画值为准
 * (0, 0)为左上角 (1, 1)为右下角
 */
@property (nonatomic,assign) CGRect rect;
/** 去水印是否开启跟踪，默认为NO
 */
@property (nonatomic, assign) BOOL isEnableTracking;
/** 关键帧动画
 */
@property (nonatomic, strong) NSArray<KeyFrameAnimate*>*  animate;

@end







@interface Filter : NSObject
/**资源分类ID
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 */
@property (nonatomic, strong) NSString *networkResourceId;
/**滤镜类型
 */
@property (nonatomic,assign)FilterType type;

/**滤镜名称
 */
@property (nonatomic,copy  )NSString *name;

/**滤镜资源地址
 */
@property (nonatomic,copy  )NSString *filterPath;

/**滤镜强度，kFilterType_LookUp时有效,默认为1.0
 */
@property (nonatomic, assign)float intensity;

/**网络封面地址
 */
@property (nonatomic,copy  )NSString *netCover;
/**网络滤镜资源地址
 */
@property (nonatomic,copy  )NSString *netFile;

/**滤镜acv地址
 */
@property (nonatomic,copy  )NSString *acvPath       DEPRECATED_MSG_ATTRIBUTE("Use filterPath instead.");

@end

@interface FaceAttribute : NSObject

/** 五官美颜  脸的宽度 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float faceWidth;
/** 五官美颜  额头高度（暂无功能） ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float forehead;
/** 五官美颜  下颚的宽度 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float chinWidth;
/** 五官美颜  下巴的高度 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float chinHeight;
/** 五官美颜  眼睛宽度 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float eyeWidth;
/** 五官美颜  眼睛高度 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float eyeHeight;
/** 五官美颜  眼睛倾斜 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float eyeSlant;
/** 五官美颜  眼睛距离 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float eyeDistance;
/** 五官美颜  鼻子宽度 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float noseWidth;
/** 五官美颜  鼻子高度 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float noseHeight;
/** 五官美颜  嘴巴宽度 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float mouthWidth;
/** 五官美颜  上嘴唇 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float lipUpper;
/** 五官美颜  下嘴唇 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float lipLower;
/** 五官美颜  微笑 ，取值范围 -1.0 - 1.0 默认 0.0
 */
@property (nonatomic,assign) float smile;

/**瘦脸，0.0~1.0,默认为0.0
    只支持iOS11.0以上
 */
@property (nonatomic, assign) float beautyThinFaceIntensity;

/**大眼，0.0~1.0,默认为0.0
    只支持iOS11.0以上
 */
@property (nonatomic, assign) float beautyBigEyeIntensity;

/** 五官美颜  该脸的位置
 */
@property (nonatomic,assign) CGRect faceRect;

@end



typedef NS_ENUM(NSUInteger, FlowTrackType) {
    kFlowTypeMask,      //涂抹遮罩轨迹
    kFlowTypeAnimation, //动画轨迹
    kFlowTypeErase,     //擦除轨迹
};

@interface FlowTrack : NSObject<NSCopying, NSMutableCopying>

/** 轨迹坐标点数组，0.0 ～ 1.0（相对于媒体本身像素）
 */
@property (nonatomic,strong) NSMutableArray* points;

/** 轨迹类型
 */
@property (nonatomic,assign) FlowTrackType type;

/** 涂抹遮罩/动画/擦除半径，0.0 ～ 1.0（相对于媒体本身像素）
 */
@property (nonatomic,assign) double radius;

/** 当涂抹遮罩轨迹时，表示涂抹的画笔透明度，0.0 ～ 1.0，默认0.5
 *  当动画轨迹时，表示动画压力强度，0.0 ～ 1.0，默认0.5
 *  当擦除轨迹时，表示擦除强度，0.0 ～ 1.0，默认0.5
 */
@property (nonatomic,assign) double intensity;

/** 轨迹边缘硬度，硬度越小则边缘越柔和，0.0 ～ 1.0，默认0.5
 */
@property (nonatomic,assign) double  hardness;

/** 步长，计算轨迹上的一系列点，步长表示点的密度（间距），该值为半径 radius 比例，0.0 ～ 1.0，默认0.5
 */
@property (nonatomic,assign) double  stepRatio;

@end

#pragma mark - FlowEffect 流动效果




@interface FlowEffect  : NSObject<NSCopying, NSMutableCopying>

/** 涂抹遮罩/擦除轨迹(根据用户操作涂抹/擦除的顺序设置)
 *  如果设置 maskImage 涂抹遮罩/擦除图片，该参数无效
 */
@property (nonatomic,strong) NSMutableArray<FlowTrack*>* maskTracks;


/** 涂抹遮罩/擦除图片
 *  如果设置遮罩/擦除图片，则不需要设置 maskTracks 涂抹遮罩/擦除轨迹
 */
@property (nonatomic,strong) UIImage* maskImage;


/** 动画轨迹
 */
@property (nonatomic,strong) NSMutableArray<FlowTrack*>* animationTracks;


/** 分割点，由多个点连接的折线把画面分为多块区域
 */
@property (nonatomic,strong) NSMutableArray<NSMutableArray*>* splitPoints;


/** 流动效果持续时间
 */
@property (nonatomic,assign) float  duration;


/** 加载轨迹完成回调
 */
@property (nonatomic, copy) LoadTracksFinishBlock loadTracksFinishBlock;

@end


typedef NS_ENUM(NSUInteger, SOURCE_RENDER_MODE)
{
    SOURCE_RENDER_MODE_NORMAL = 0,
    SOURCE_RENDER_MODE_ATLAS,
    SOURCE_RENDER_MODE_CLIP_BY_SIZE
};

typedef NS_ENUM(NSUInteger, BLEND_FUNC)
{
    BLEND_FUNC_DEFAULT = 0,
    BLEND_FUNC_NON_PREMULTIPLIED = 1,
    BLEND_FUNC_DISABLE = 2,
    BLEND_FUNC_ADDITIVE = 3,
    BLEND_FUNC_CLEAR = 4,
    BLEND_FUNC_SRC_IN = 5,
    BLEND_FUNC_PLUS = 6,
    BLEND_FUNC_SCREEN = 7,
};

typedef NS_ENUM(NSUInteger, EMITTER_TYPE)
{
    EMITTER_TYPE_GRAVITY = 0,
    EMITTER_TYPE_RADIUS,
    EMITTER_TYPE_GRAVITY_LEAP_LIKE//基于指定中心点+指定点阵中重力触发,与Leap应用类似
};

#pragma mark - Particle 粒子
@interface Particle  : NSObject<NSCopying, NSMutableCopying>
/**
 */
@property (nonatomic, assign)  float fRailLevelY;
/**粒子名字
 */
@property (nonatomic, strong) NSString *name;
/**资源路径
 *  导出模板用
 */
@property (nonatomic, strong) NSString *folderPath;

/**资源分类ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkResourceId;

/** 时间范围
 *  @abstract   timeRange.
 */
@property (nonatomic ,assign) CMTimeRange timeRange;


/** 涂抹坐标点数组，0.0 ～ 1.0（相对于虚拟视频）
 *  @abstract   array of painted coordinate points, 0.0 to 1.0 (relative to virtual video)
 */
@property (nonatomic,strong) NSMutableArray* points;


/**粒子图片路径
 *  @abstract   particle image path
 */
@property (nonatomic,strong)NSString *textureFileName;


/**遮罩图片路径
 *  @abstract   mask image path
 */
@property (nonatomic,strong)NSString *maskPath;


/**遮罩图片是否为图片集
 *  @abstract   whether the masked image is a multiple image set
 */
@property (nonatomic,assign)BOOL maskAtlas;



/**混合方式，参考 enum BLEND_FUNC，默认 BLEND_FUNC_DEFAULT
 *  @abstract   blend mode, see enum BLEND_FUNC, default BLEND_FUNC_DEFAULT
 */
@property (nonatomic,assign)int blendFuncSource;


/**源呈现模式，参考 enum SOURCE_RENDER_MODE，默认 SOURCE_RENDER_MODE_NORMAL
 *  @abstract    source rendering mode, see enum SOURCE_RENDER_MODE, default SOURCE_RENDER_MODE_NORMAL
 */
@property (nonatomic,assign)int sourceRendingMode;


/**粒子触发类型，参考 enum EMITTER_TYPE，默认 EMITTER_TYPE_GRAVITY_LEAP_LIKE
 *  @abstract    particle emitter type, see enum EMITTER_TYPE, default EMITTER_TYPE_GRAVITY_LEAP_LIKE
 */
@property (nonatomic,assign)int emitterType;


/**生命周期，单位：秒, 默认 1.0
 *  @abstract    life cycle, in seconds, default 1.0
 */
@property (nonatomic,assign)float particleLifespan;


/**生命周期变化幅度，单位：秒，默认为 0 ，particleLifespan = particleLifespan +/- particleLifespanVariance
 *  @abstract    lifespan variance in seconds, default 0, particleLifespan = particleLifespan +/- particleLifespanVariance
 */
@property (nonatomic,assign)float particleLifespanVariance;


/**持续时间，默认为 -1，永久显示，单位：秒
 *  @abstract     duration, default to - 1, permanently displayed, unit: seconds
 */
@property (nonatomic,assign)float duration;


/**最大粒子数量，默认50
 *  @abstract     maximum number of particles, default 50
 */
@property (nonatomic,assign)int maxParticles;


/**角度 0 ～ 360，默认为 0
 *  @abstract     the angle is 0 ~ 360, and the default is 0
 */
@property (nonatomic,assign)float angle;


/**角度变化幅度，默认为 0 ，angle = angle +/- angleVariance
 *  @abstract     angle variance, default is 0, angle = angle +/- angleVariance
 */
@property (nonatomic,assign)float angleVariance;

/**开始时粒子角度，默认为 0.0
 *  @abstract     particle angle at start, default 0.0
 */
@property (nonatomic,assign)float rotationStart;


/**开始时粒子角度变化幅度，默认为 0 ，rotationStart = rotationStart +/- rotationStartVariance
 *  @abstract     start of particle angle variance, default is 0, rotationStart = rotationStart +/- rotationStartVariance
 */
@property (nonatomic,assign)float rotationStartVariance;


/**结束时粒子角度，默认为 0
 *  @abstract      ending particle angle, default is 0
 */
@property (nonatomic,assign)float rotationEnd;


/**结束时粒子角度变化幅度，默认为 0 ，rotationEnd = rotationEnd +/- rotationEndVariance
 *  @abstract      end of particle angle variance, default is 0, rotationEnd = rotationEnd +/- rotationEndVariance
 */
@property (nonatomic,assign)float rotationEndVariance;



/**颜色
 *  @abstract      color
 */
@property (nonatomic,assign)float startColorAlpha;
@property (nonatomic,assign)float startColorRed;
@property (nonatomic,assign)float startColorGreen;
@property (nonatomic,assign)float startColorBlue;
@property (nonatomic,assign)float startColorVarianceAlpha;
@property (nonatomic,assign)float startColorVarianceRed;
@property (nonatomic,assign)float startColorVarianceGreen;
@property (nonatomic,assign)float startColorVarianceBlue;
@property (nonatomic,assign)float finishColorAlpha;
@property (nonatomic,assign)float finishColorRed;
@property (nonatomic,assign)float finishColorGreen;
@property (nonatomic,assign)float finishColorBlue;
@property (nonatomic,assign)float finishColorVarianceAlpha;
@property (nonatomic,assign)float finishColorVarianceRed;
@property (nonatomic,assign)float finishColorVarianceGreen;
@property (nonatomic,assign)float finishColorVarianceBlue;



/**开始时粒子大小，默认为 0.5
 *  @abstract    start particle size, default is 0.5
 */
@property (nonatomic,assign)float startParticleSize;


/**开始时粒子大小变化幅度，默认为 0 ，startSize = startSize +/- startSizeVariance
 *  @abstract    start particle size variance, default is 0, startSize = startSize +/- startSizeVariance
 */
@property (nonatomic,assign)float startParticleSizeVariance;


/**结束时粒子大小，默认为 0
 *  @abstract    particle size at end, default to 0
 */
@property (nonatomic,assign)float finishParticleSize;


/**结束时粒子大小变化幅度，默认为 0 ，endSize = endSize +/- endSizeVariance
 *  @abstract    the size of the particle change at the end, default is 0. endSize = endSize +/- endSizeVariance
 */
@property (nonatomic,assign)float finishParticleSizeVariance;


/**重心位置，左上角（0.0，0.0），右下角（1.0，1.0），默认 0.5
 *  @abstract    gravity x-position, upper left corner (0.0, 0.0), lower right corner (1.0, 1.0), default 0.5
 */
@property (nonatomic,assign)float gravityx;


/**重心位置，左上角（0.0，0.0），右下角（1.0，1.0），默认 0.5
 *  @abstract    gravity y-position, upper left corner (0.0, 0.0), lower right corner (1.0, 1.0), default 0.5
 */
@property (nonatomic,assign)float gravityy;

/**当 emitterType 为 EMITTER_TYPE_GRAVITY 时， 粒子发射位置，左上角（0.0，0.0），右下角（1.0，1.0），默认 0.5
 *  @abstract    when emitterType is EMITTER_TYPE_GRAVITY, the particle emission x-position,
 *               top left (0.0, 0.0), bottom right (1.0, 1.0), default 0.5
 */
@property (nonatomic,assign)float sourcePositionx;

/**粒子发射位置变化幅度，左上角（0.0，0.0），右下角（1.0，1.0），默认 0.0
 *  @abstract    the variation range of the x-particle emission position,
 *               the upper left corner (0.0, 0.0), the lower right corner (1.0, 1.0), the default is 0.0
 */
@property (nonatomic,assign)float sourcePositionVariancex;


/**当 emitterType 为 EMITTER_TYPE_GRAVITY 时，粒子发射位置，左上角（0.0，0.0），右下角（1.0，1.0），默认 0.5
 *  @abstract    when emitterType is EMITTER_TYPE_GRAVITY, the particle emission y-position,
 *               top left (0.0, 0.0), bottom right (1.0, 1.0), default 0.5
 */
@property (nonatomic,assign)float sourcePositiony;


/**粒子发射位置，左上角（0.0，0.0），右下角（1.0，1.0），默认 0.0
 *  @abstract    the variation range of the y-particle emission position,
 *               the upper left corner (0.0, 0.0), the lower right corner (1.0, 1.0), the default is 0.0
 */
@property (nonatomic,assign)float sourcePositionVariancey;



/**运动速度，默认为 0.5
 *  @abstract    speed, default is 0.5
 */
@property (nonatomic,assign)float speed;


/**运动速度变化幅度，默认为 0 ，speed = speed +/- speedVariance
 *  @abstract    speed variance, default is 0, speed = speed +/- speedVariance
 */
@property (nonatomic,assign)float speedVariance;


/**向心加速度，默认为 0.0
 *  @abstract    acceleration, default 0.0
 */
@property (nonatomic,assign)float radialAcceleration;


/**向心加速度变化幅度，默认为 0 ，radialAcceleration = radialAcceleration +/- radialAccelVariance
 *  @abstract    acceleration variance, default is 0, radialAcceleration = radialAcceleration +/- radialAccelVariance
 */
@property (nonatomic,assign)float radialAccelVariance;



/**切线加速度，默认为 0.0
 *  @abstract    tangential acceleration, default 0.0
 */
@property (nonatomic,assign)float tangentialAcceleration;


/**切线加速度变化幅度，默认为 0 ，tangentialAcceleration = tangentialAcceleration +/- tangentialAccelVariance
 *  @abstract    tangential acceleration variation, default is 0，tangentialAcceleration = tangentialAcceleration +/- tangentialAccelVariance
 */
@property (nonatomic,assign)float tangentialAccelVariance;



/**最小半径，默认为 0.0
 *  @abstract    min radius, default is 0.0
 */
@property (nonatomic,assign)float minRadius;


/**最小半径变化幅度，默认为 0 ，minRadius = minRadius +/- minRadiusVariance
 *  @abstract    min radius variation, default is 0，minRadius = minRadius +/- minRadiusVariance
 */
@property (nonatomic,assign)float minRadiusVariance;


/**最大半径，默认为 0.0
 *  @abstract    max radius, default is 0.0
 */
@property (nonatomic,assign)float maxRadius;


/**最大半径变化幅度，默认为 0 ，maxRadius = maxRadius +/- maxRadiusVariance
 *  @abstract    max radius variation, default is 0，maxRadius = maxRadius +/- maxRadiusVariance
 */
@property (nonatomic,assign)float maxRadiusVariance;



/**每秒旋转多少度，默认为 0.0
 *  @abstract    the number of degrees of rotation per second, default is 0.0
 */
@property (nonatomic,assign)float rotatePerSecond;


/**每秒旋转度数变化幅度，默认为 0 ，rotatePerSecond = rotatePerSecond +/- rotatePerSecondVariance
 *  @abstract    the number of degrees variation of rotation per second, default is 0，
 *               rotatePerSecond = rotatePerSecond +/- rotatePerSecondVariance
 */
@property (nonatomic,assign)float rotatePerSecondVariance;


/**是否自转，默认为 NO
 *  @abstract    whether to rotate or not, default is NO
 */
@property (nonatomic,assign)BOOL rotationIsDir;


/**翻转，默认为 1, 1 表示不翻转，-1表示翻转
 *  @abstract    y-direction flip, default 1, 1 means no flip, -1 means flip
 */
@property (nonatomic,assign)int yCoordFlipped;


/**是否记录粒子数据，默认为 NO
 *  @abstract    whether to record particle data, default is NO
 */
@property (nonatomic,assign)BOOL enableHistory;


/**粒子轨迹，粒子根据设置的轨迹数据运动
 *  @abstract    track data, particle movement based on track data
 */
@property (nonatomic,strong)NSData *trackData;



/**获取粒子轨迹数据，供下次使用，如果要记录轨迹数据 enableHistory 必须置为 YES
 *  @abstract    Get the particle history data for next time, if you want to record the history data,
 *               enableHistory must be set to YES
 */
@property (nonatomic, copy) GetParticleHistoryDataBlock getHistoryTrackDataBlock;


/**粒子数据
 *  @abstract    particle data
 */
@property (nonatomic,strong)NSData *particleData;

/**获取粒子所有数据，供下次使用，如果要记录数据 enableHistory 必须置为 YES
 *  @abstract    Get the particle history data for next time, if you want to record the history data,
 *               enableHistory must be set to YES
 */
@property (nonatomic, copy) GetParticleHistoryDataBlock getHistoryParticleDataBlock;


/**获取时间，根据粒子返回的数据，获取该粒子的时间线
 *  @abstract    Obtain the time, and obtain the time line of the particle according to the data returned by the particle
 */
-(CMTimeRange) getTimeRangeFromData:(NSData*)data;


/**获取灰度图坐标点
 *  @abstract    Get the coordinate points of gray scale image
 */
-(NSMutableArray*)getPointsFromFilePath:(NSURL*)filePath;



@end


typedef NS_ENUM(NSUInteger, BRUSH_MODE)
{
    BRUSH_MODE_DEFAULT = 0,
    BRUSH_MODE_RANDOM,
    BRUSH_MODE_INCREMENTAL,
    BRUSH_MODE_ANGULAR,
    BRUSH_MODE_PRESSURE,
    BRUSH_MODE_XTILT,
    BRUSH_MODE_YTILT,
    BRUSH_MODE_VELOCITY,

};

typedef NS_ENUM(NSUInteger, BRUSH_APPLICATION)
{
    BRUSH_APPLICATION_ALPHAMASK = 0,    //透明度蒙版，会显示已配置画刷颜色
    BRUSH_APPLICATION_IMAGESTAMP,       //按原始位图显示
    BRUSH_APPLICATION_LIGHTNESSMAP,     //亮度图，会显示已配置画刷颜色

};


typedef NS_ENUM(NSInteger, SHAPE_MODE)
{
    SHAPE_MODE_NORMAL = -1,     //根据设置的坐标点绘制（手指滑动轨迹）
    SHAPE_MODE_LINE,            //直线
    SHAPE_MODE_TRIANGLE,        //三角形
    SHAPE_MODE_RECT,            //矩形
    SHAPE_MODE_oval,            //椭圆形
    SHAPE_MODE_HEXAGON,         //六角形
    SHAPE_MODE_PATH,            //指定轨迹（暂时不支持）

};

typedef NS_ENUM(NSInteger, DOODLEOP_TYPE)
{
    DOODLEOP_TYPE_BRUSH = 0,     //普通画刷
    DOODLEOP_TYPE_CLEAR_COLOR,   //指定颜色显示
    DOODLEOP_TYPE_FILL_COLOR,    //填充区域（暂时支持颜色填充）
    DOODLEOP_TYPE_FILL_IMAGE,    //填充图片
    DOODLEOP_TYPE_FILL_TEXTURE,  //填充纹理
};

typedef NS_ENUM(NSInteger, DOODLEOP_STROKE_MASK_TYPE)
{
    DOODLEOP_STROKE_MASK_NONE = 0,              //无
    DOODLEOP_STROKE_MASK_MOSAIC,                //正方形马赛克
    DOODLEOP_STROKE_MASK_TRIANGLE_PIXELATION,   //三角形马赛克
    DOODLEOP_STROKE_MASK_HEXAGON_PIXELATION,    //六边形马赛克
    DOODLEOP_STROKE_MASK_BLUR_GAUSSIAN,         //高斯模糊马赛克
    DOODLEOP_STROKE_MASK_BLUR_MOTION,           //运动模糊马赛克
    DOODLEOP_STROKE_MASK_WATERCOLOR,            //水彩画马赛克
};

typedef NS_ENUM(NSInteger, DOODLEOP_PAINT_TYPE)
{
    DOODLEOP_PAINT_TYPE_START = 0,      //手指按下，绘制开始
    DOODLEOP_PAINT_TYPE_PAINTING,       //手指按下过程中移动
    DOODLEOP_PAINT_TYPE_END,            //手指松开，绘制结束
};

#pragma mark - doodleEx 涂鸦png画刷
@interface PNGBrush  : NSObject<NSCopying, NSMutableCopying>

/**  素材路径，默认为 NULL
 *   @abstract   file name，default is NULL
 */
@property (nonatomic,strong)NSString* filename;

/**  素材被分割的单元数量，默认为 0
 *   @abstract   number of units in which the material is divided，default is 0
 */
@property (nonatomic,assign)int cells;

/**  每个单元的宽，默认为 0
 *   @abstract   width of cell，default is 0
 */
@property (nonatomic,assign)int cellWidth;

/**  每个单元的高，默认为 0
 *   @abstract   height of cell，default is 0
 */
@property (nonatomic,assign)int cellHeight;

/**  画刷模式 ，参考 BRUSH_MODE ，默认 BRUSH_MODE_DEFAULT
 *   @abstract   mode，Default is BRUSH_MODE_DEFAULT
 */
@property (nonatomic,assign)int mode;

/**  画刷应用类型 ，参考 BRUSH_APPLICATION ，默认为 BRUSH_APPLICATION_ALPHAMASK
 *   @abstract   brush application type ，default is BRUSH_APPLICATION_ALPHAMASK
 */
@property (nonatomic,assign)int brushApplication;

/**  是否自动调整 ，默认为 NO
 *   @abstract  auto adjust，default is NO
 */
@property (nonatomic,assign)BOOL active;

/**  自动间隔 ，默认为 1.0
 *   @abstract  auto spacing，default is 1.0
 */
@property (nonatomic,assign)float spacingCoeff;

/**  间隔 ，默认为 1.0
 *   @abstract  spacing，default is 1.0
 */
@property (nonatomic,assign)float spacing;

/**  颜色反转 ，默认 NO
 *   @abstract  color revert，default is NO
 */
@property (nonatomic,assign)BOOL revertMask;


/**  颜色自动调节 ，默认 NO
 *   @abstract  auto adjust ,depend resource color stat，default is NO
 */
@property (nonatomic,assign)BOOL autoAdjustMidPoint;

/**  调节系数 ，0-255，默认 0
 *   @abstract  auto adjust ,depend resource color stat，default is 0.0
 */
@property (nonatomic,assign)int adjustmentMidPoint;

/**  亮度调节 ，-1.0 ~ 1.0 ，默认 0
 *   @abstract  brightness adjustment -1 to 1，default is 0.0
 */
@property (nonatomic,assign)float brightnessAdjustment;

/**  对比度调整 ，-1.0 ~ 1.0 ，默认 0
 *   @abstract  contrast adjustment，default is 0.0
 */
@property (nonatomic,assign)float contrastAdjustment;


/**  颜色设置为蒙版 ，默认 NO
 *   @abstract  Color is set to mask , default NO
 */
@property (nonatomic,assign)BOOL colorAsMask;

/**  缩放
 *   @abstract  scale , default 1.0
 */
@property (nonatomic,assign)float scale;

/**  画刷硬度，淡入淡出 ，默认为 0.0
 *   @abstract  fade，default is 0.0
 */
@property (nonatomic,assign)float fade;


/**  distMask，默认为 NULL
 *   @abstract   distMask，default is NULL
 */
@property (nonatomic,strong)NSString* distMask;

@end


#define AUTO_BRUSH_CIRCLE (@"circle")
#define AUTO_BRUSH_RECT (@"rect")


#pragma mark - doodleEx 涂鸦自动画刷
@interface AutoBrush  : NSObject<NSCopying, NSMutableCopying>

/**  画刷应用类型 ，参考 BRUSH_APPLICATION ，默认为 BRUSH_APPLICATION_ALPHAMASK
 *   @abstract   brush application type ，default is BRUSH_APPLICATION_ALPHAMASK
 */
@property (nonatomic,assign)int brushApplication;

/**  是否自动调整 ，默认为 NO
 *   @abstract  auto adjust，default is NO
 */
@property (nonatomic,assign)BOOL active;

/**  自动间隔 ，默认为 1.0
 *   @abstract  auto spacing，default is 1.0
 */
@property (nonatomic,assign)float spacingCoeff;

/**  间隔 ，默认为 1.0
 *   @abstract  spacing，default is 1.0
 */
@property (nonatomic,assign)float spacing;

/**  缩放 ，默认为 1.0
 *   @abstract  scale，default is 1.0
 */
@property (nonatomic,assign)float scale;

/**  自动画笔类型 ，默认为 AUTO_BRUSH_CIRCLE
 *   @abstract  mask type，default is AUTO_BRUSH_CIRCLE
 */
@property (nonatomic,strong)NSString* maskType;

/**  画刷直径 ，默认为 0.0
 *   @abstract  diameter，default is 0.0
 */
@property (nonatomic,assign)float diameter;

/**  画刷硬度，淡入淡出 ，默认为 0.0
 *   @abstract  fade，default is 0.0
 */
@property (nonatomic,assign)float fade;

/**  比例 ，默认为 0.0
 *   @abstract  ratio，default is 0.0
 */
@property (nonatomic,assign)float ratio;

/**  随机性 ，默认为 0.0
 *   @abstract  randomness，default is 0.0
 */
@property (nonatomic,assign)float randomness;

/**  密度 ，默认为 0.0
 *   @abstract  density，default is 0.0
 */
@property (nonatomic,assign)float density;


/**  描边颜色
 *   @abstract  outline color
 */
@property (nonatomic ,strong) UIColor* outlineColor;

/**  描边大小 0.0 ~ 1.0
 *   @abstract  outline size
 */
@property (nonatomic,assign)float outlineSize;


/**  荧光笔
 *   @abstract  glowCenterColor
 */
@property (nonatomic,assign)int glowCenterColor;

@end

#pragma mark - doodleEx 涂鸦纹理
@interface TextureGrain  : NSObject<NSCopying, NSMutableCopying>

/**  素材路径，默认为 NULL
 *   @abstract   file name，default is NULL
 */
@property (nonatomic,strong)NSString* filename;

/**  画刷模式 ，参考 BRUSH_MODE ，默认 BRUSH_MODE_DEFAULT
 *   @abstract   mode，Default is BRUSH_MODE_DEFAULT
 */
@property (nonatomic,assign)int mode;

/**  颜色反转 ，默认 NO
 *   @abstract  color revert，default is NO
 */
@property (nonatomic,assign)BOOL revert;

/**  x方向偏移 ，默认为 0.0
 *   @abstract  offsetX，default is 0.0
 */
@property (nonatomic,assign)float offsetX;

/**  y方向偏移 ，默认为 0.0
 *   @abstract  offsetY，default is 0.0
 */
@property (nonatomic,assign)float offsetY;

/**  缩放 ，默认为 1.0
 *   @abstract  scale，default is 1.0
 */
@property (nonatomic,assign)float scale;

/**  角度 ，默认为 0.0
 *   @abstract  angle，default is 0.0
 */
@property (nonatomic,assign)float angle;

/**  比例 ，默认为 1.0
 *   @abstract  ratio，default is 1.0
 */
@property (nonatomic,assign)float ratio;

@end



@interface DoodleOptionEvent : NSObject<NSCopying, NSMutableCopying>

/**  当前坐标点，0.0 ~ 1.0 ,左上角（0，0），右下角（1.0，1.0）
 *   @abstract   Current coordinate point
 */
@property (nonatomic,assign)CGPoint pt;

/**  压力，0.0 ~ 1.0 ，默认 1.0
 *   @abstract   pressure, 0.0 ~ 1.0, default 1.0
 */
@property (nonatomic,assign)float pressure;

/**  当前时间，单位：毫秒
 *   @abstract   time, in milliseconds
 */
@property (nonatomic,assign)int64_t time;

/**  绘制状态，参考 DOODLEOP_PAINT_TYPE ，默认 DOODLEOP_PAINT_TYPE_START
 *   @abstract   point type, default DOODLEOP_PAINT_TYPE_START
 */
@property (nonatomic,assign)int type;

@end


@interface DoodleOption : NSObject<NSCopying, NSMutableCopying>

/**资源分类ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkResourceId;

/** 资源文件夹路径
 *  导出模板用
 *  @abstract Resources folder path.
 */
@property (nonatomic ,copy) NSString * folderPath;

/** 透明度 ，0.0 ~ 1.0 ，默认 1.0
 *  @abstract   opacityValue, 0.0 ~ 1.0, default 1.0
 */
@property (nonatomic,assign)float opacityValue;


/** 画笔粗细 ，0.0 ~ 1.0 ，默认 0.5
 *  @abstract   paint Size, 0.0 ~ 1.0, default 0.5,
 */
@property (nonatomic,assign)float paintSize;


/** 画笔颜色 ，默认为白色
 *  @abstract   color, default white
 */
@property (nonatomic ,strong) UIColor* color;


/** 混合方式，参考 enum BLEND_FUNC，默认 BLEND_FUNC_DEFAULT, 如果是擦除操作，必须设置为 BLEND_FUNC_CLEAR
 *  @abstract   blend mode, see enum BLEND_FUNC, default BLEND_FUNC_DEFAULT；
 *              If it is erase operation, it must be set to BLEND_FUNC_CLEAR；
 */
@property (nonatomic,assign)int blendFunc;


/** 角度传感 ，默认为 NO
 *  @abstract   angle sensor, default NO
 */
@property (nonatomic,assign)BOOL angleSensor;

/** 距离传感器 默认 NO
 *  @abstract   distance sensor, default NO
 */
@property (nonatomic,assign)BOOL distanceSensor;


/** 硬度是否可用 默认 NO
 *  @abstract   hardness, default NO
 */
@property (nonatomic,assign) BOOL  hardness;


/** 纹理质地画刷 ，默认为 NULL
 *  @abstract   texture grain brush, default NULL
 */
@property (nonatomic,strong) TextureGrain* textureGrain;


/** 基础画刷 ，默认为 NULL
 *  @abstract   auto brush, default NULL
 */
@property (nonatomic,strong) AutoBrush* autoBrush;


/** png画刷 ，默认为 NULL
 *  @abstract   png brush, default NULL
 */
@property (nonatomic,strong) PNGBrush* pngBrush;


/** 形状 ，支持如线、矩形、圆等，参考 SHAPE_MODE ，默认为 SHAPE_MODE_NORMAL
 *  @abstract   shape mode,like line,rect,oval etc...see enum SHAPE_MODE，default SHAPE_MODE_NORMAL
 */
@property (nonatomic,assign) int shapeMode;

/** 指令类型，可以用于颜色或者图像填充，参考 DOODLEOP_TYPE ，默认为 DOODLEOP_TYPE_BRUSH
 *  @abstract   option type,see enum DOODLEOP_TYPE，default DOODLEOP_TYPE_BRUSH
 */
@property (nonatomic,assign) int optionType;


/** 填充图像的文件路径，需要将 optionType 设置为 DOODLEOP_TYPE_FILL_IMAGE
 */
@property (nonatomic , strong) NSURL*  fillImageURL;


/**填充图像裁剪位置，默认为(0.0,0.0,1.0,1.0)
 */
@property (nonatomic ,assign) CGRect crop;

/**填充图像显示位置，默认为(0.0,0.0,1.0,1.0)
 */
@property (nonatomic ,assign) CGRect show;

/** 马赛克类型，参考 DOODLEOP_STROKE_MASK_TYPE ，默认为 DOODLEOP_STROKE_MASK_NONE
 */
@property (nonatomic,assign) int strokeMask;

/** 是否使用涂鸦设置的颜色，默认为 NO
 */
@property (nonatomic,assign) BOOL usePaintedColor;

/** 位置信息
 *  @abstract   event array
 */
@property (nonatomic,strong) NSMutableArray<DoodleOptionEvent*>* eventArray;




@end


@interface AnimationEx  : NSObject<NSCopying, NSMutableCopying>


/**开始时间
 *  @abstract  time
 */
@property (nonatomic,assign) CGFloat atTime;


/** 显示位置 ，(0, 0)为左上角 (1, 1)为右下角，默认为 （0，0，1，1）
 *  @abstract   rect, (0, 0) is the upper left corner (1, 1) is the lower right corner.default is (0, 0, 1, 1)
 */
@property (nonatomic,assign) CGRect rect;


/** 旋转角度,默认为 0
 *  @abstract   angle.default is 0.
 */
@property (nonatomic,assign) int angle;


/** 缩放，默认为 1.0
 *  @abstract   scale.default is 1.0.
 */
@property (nonatomic,assign) float scale;


/** 透明度，默认为 1.0
 *  @abstract   alpha.default is 1.0.
 */
@property (nonatomic,assign) float alpha;

@end


#pragma mark - doodleEx 涂鸦
@interface DoodleEx  : NSObject<NSCopying, NSMutableCopying>

/** 时间范围
 *  @abstract   timeRange.
 */
@property (nonatomic ,assign) CMTimeRange timeRange;


/** 涂鸦操作 - 用于撤销/恢复
 *  @abstract   option.
 */
@property (nonatomic,strong) NSMutableArray<DoodleOption*>* optionArrays;



/** 涂鸦操作 - 用于当前正在绘制的操作
 *  @abstract   option.
 */
@property (nonatomic,strong) DoodleOption* paintOption;


/** 涂鸦画面
 *  @abstract   doodle image.
 */
@property (nonatomic,strong) UIImage* image;


/** 涂鸦显示位置 ，(0, 0)为左上角 (1, 1)为右下角，默认为 （0，0，1，1），如果有设置关键帧动画 animation ，以关键帧动画参数为准（注意：缩放前的显示区域）
 *  @abstract   doodle rect, (0, 0) is the upper left corner (1, 1) is the lower right corner.default is (0, 0, 1, 1)
 */
@property (nonatomic,assign) CGRect rect;


/** 涂鸦旋转角度,默认为 0，如果有设置关键帧动画 animation ，以关键帧动画参数为准
 *  @abstract   doodle angle.
 */
@property (nonatomic,assign) int angle;


/** 涂鸦缩放，默认为 1.0，如果有设置关键帧动画 animation ，以关键帧动画参数为准
 *  @abstract   doodle scale.
 */
@property (nonatomic,assign) float scale;


/** 透明度，默认为 1.0
 *  @abstract   alpha.default is 1.0.
 */
@property (nonatomic,assign) float alpha;

/** 涂鸦关键帧动画
 *  @abstract   doodle animations.
 */
@property (nonatomic,strong) NSMutableArray<AnimationEx*>* animations;

/** 是否释放内存，默认为 NO, 如果为 YES ,刷新后释放内存
 *  @abstract   auto release memory.
 */
@property (nonatomic,assign) BOOL autoRelease;

@end

#pragma mark - 封面模板
@interface VECoreCoverTemplate  : NSObject<NSCopying, NSMutableCopying>

/** 资源分类ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/** 资源ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkResourceId;

/** 模板资源路径
 */
@property (nonatomic ,copy) NSString *path;

/** 封面模板字幕
 */
@property (nonatomic, strong) NSMutableArray<CaptionEx*>* subtitleExs;

/** 使用该模板时，视频分辨率
 */
@property (nonatomic, assign) CGSize size;

@end



#pragma mark - 全景视图相关
@interface Panorama  : NSObject<NSCopying, NSMutableCopying>

/** 表示绕x轴旋转，视角在垂直方向移动，取值范围：-1.0 ～ 1.0，(0，0)表示正对球体的中心，即原全景图片的中间
 */
@property (nonatomic,assign) float x;

/** 表示绕y轴旋转，视角在水平方向移动，取值范围：-1.0 ～ 1.0，(0，0)表示正对球体的中心，即原全景图片的中间
*/
@property (nonatomic,assign) float y;


@end
