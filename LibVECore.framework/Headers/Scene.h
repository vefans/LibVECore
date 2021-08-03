//
//  Scene.h
//  VECore
//
//  Created by iOS SDK Team on 2017/5/11.
//  Copyright © 2017年 iOS SDK Team. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <LibVECore/CustomFilter.h>
#import <LibVECore/CustomTransition.h>
#import <LibVECore/MaskObject.h>

typedef NS_ENUM(NSInteger, AudioFilterType) {
    AudioFilterTypeNormal,       // 无效果
    AudioFilterTypeBoy,          // 男声
    AudioFilterTypeGirl,         // 女声
    AudioFilterTypeMonster,      // 怪兽
    AudioFilterTypeCartoon,      // 卡通
    AudioFilterTypeCartoonQuick, // 卡通 快
    AudioFilterTypeEcho,         // 回声
    AudioFilterTypeReverb,       // 混响
    AudioFilterTypeRoom,         // 室内
    AudioFilterTypeDance,        // 小舞台
    AudioFilterTypeKTV,          // KTV
    AudioFilterTypeFactory,      // 厂房
    AudioFilterTypeArena,        // 竞技场
    AudioFilterTypeElectri,      // 电音
    AudioFilterTypeCustom,       // 自定义//调整媒体的pitch实现
};

typedef NS_ENUM(NSInteger, VideoRealTimeFilterType) {
    VideoRealTimeFilterTypeNone = 0,  //无
    VideoRealTimeFilterTypeDazzled,   //颤抖
    VideoRealTimeFilterTypeSoulstuff, //灵魂出窍
    VideoRealTimeFilterTypeHeartbeat, //心动
    VideoRealTimeFilterTypeSpotlights //聚光灯
};

typedef NS_ENUM(NSInteger,  TransitionType) {
     TransitionTypeNone             = 0,
     TransitionTypeLeft             = 1,    //左推
     TransitionTypeRight            = 2,    //右推
     TransitionTypeUp               = 3,    //上推
     TransitionTypeDown             = 4,    //下推
     TransitionTypeFade             = 5,    //淡入
     TransitionTypeBlinkBlack       = 6,    //闪黑
     TransitionTypeBlinkWhite       = 7,    //闪白
     TransitionTypeMask             = 8,    //Mask
     TransitionTypeBlinkWhiteInvert = 9,    //闪白-黑白/反色-反色/黑白-黑白
     TransitionTypeBlinkWhiteGray   = 10,   //闪白-中间白色/上下黑白-中间白色/上下原图-原图
     TransitionTypeBulgeDistortion  = 11,   //鱼眼
     TransitionTypeGrid             = 12,   //九宫格
     TransitionTypeCustom           = 13,   //自定义转场
};

typedef NS_ENUM(NSInteger, MediaAssetType) {
    MediaAssetTypeVideo,
    MediaAssetTypeImage
};

typedef NS_ENUM(NSInteger, VECoreStatus) {
    kVECoreStatusUnknown,
    kVECoreStatusWillChangeMedia,
    kVECoreStatusReadyToPlay,
    kVECoreStatusFailed
};

typedef NS_ENUM(NSInteger, JsonAnimationMediaType) {
    JsonAnimationMediaType_Irreplaceable,           //不可替换
    JsonAnimationMediaType_ReplaceableText,         //可替换文字
    JsonAnimationMediaType_ReplaceablePic,          //可替换图片
    JsonAnimationMediaType_ReplaceableVideoOrPic,   //可替换视频或图片
};

typedef NS_ENUM(NSInteger ,CurveSpeedType) {
    CurveSpeedType_None,        //无
    CurveSpeedType_Custom,      //自定义
    CurveSpeedType_Montage,     //蒙太奇
    CurveSpeedType_Hero,        //英雄时刻
    CurveSpeedType_Bullet,      //子弹时刻
    CurveSpeedType_Jump,        //跳接
    CurveSpeedType_FlashIn,     //闪进
    CurveSpeedType_FlashOut,    //闪出
};

typedef NS_ENUM(NSInteger, MediaReplaceableType) {
    MediaReplaceableType_VideoOrPic,    //可替换视频或图片
    MediaReplaceableType_Picture,       //可替换图片
    MediaReplaceableType_Video,         //可替换视频
    MediaReplaceableType_Irreplaceable, //不可替换
};

@class Transition;
@class MediaAsset;
@class CurvedSpeedPoint;
@class AudioVolumePosition;
@class FaceAttribute;

/** 调色
*/
@interface ToningInfo : NSObject<NSCopying, NSMutableCopying>

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

/** 锐化 ranges from -4.0 to 4.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的sharpness值为准
 */
@property (nonatomic, assign) float sharpness;

/** 色温 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的whiteBalance值为准
 */
@property (nonatomic, assign) float whiteBalance;

/** 持续时间
 */
@property (nonatomic,assign) CMTimeRange timeRange;

@end


@interface FaceAttribute : NSObject

/** 五官美颜  脸的宽度 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float faceWidth;
/** 五官美颜  额头高度（暂无功能） ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float forehead;
/** 五官美颜  下颚的宽度 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float chinWidth;
/** 五官美颜  下巴的高度 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float chinHeight;
/** 五官美颜  眼睛宽度 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float eyeWidth;
/** 五官美颜  眼睛高度 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float eyeHeight;
/** 五官美颜  眼睛倾斜 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float eyeSlant;
/** 五官美颜  眼睛距离 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float eyeDistance;
/** 五官美颜  鼻子宽度 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float noseWidth;
/** 五官美颜  鼻子高度 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float noseHeight;
/** 五官美颜  嘴巴宽度 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float mouthWidth;
/** 五官美颜  上嘴唇 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float lipUpper;
/** 五官美颜  下嘴唇 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float lipLower;
/** 五官美颜  微笑 ，取值范围 0.0 - 1.0 默认 0.5
 */
@property (nonatomic,assign) float smile;

/** 五官美颜  该脸的位置
 */
@property (nonatomic,assign) CGRect faceRect;

@end

typedef NS_ENUM(NSInteger, SceneType) {
    SceneTypeNormal,    //默认
    SceneTypeEnd,       //片尾
};

@interface Scene : NSObject

/** 标识符
 *  导出模板用
 */
@property (nonatomic,strong) NSString *identifier;

/** 类型
 *  导出模板用
 */
@property (nonatomic, assign) SceneType type;

/** 组Id
 *  导出模板用
 */
@property (nonatomic, assign) int groupId;

/** 是否是默认场景
 *  导出模板用
 */
@property (nonatomic, assign) BOOL isDefault;

/** 是否是旁白，默认为NO
 *  导出模板用 
 */
@property (nonatomic, assign) BOOL isNarrator;

/** 场景背景色
*/
@property (nonatomic, strong) UIColor *backgroundColor;

/** 场景背景媒体
*/
@property (nonatomic, strong) MediaAsset *backgroundAsset;

/**一个场景中可有多个媒体
 */
@property (nonatomic,strong) NSMutableArray<MediaAsset*>*  media;

@property (nonatomic,strong) Transition*  transition;

@end

typedef NS_ENUM(NSInteger, MusicType) {
    MusicTypeNormal,            //配乐
    MusicTypeDubbing,           //配音
    MusicTypeSoundEffect,       //音效
};

@interface MusicInfo : NSObject<NSCopying,NSMutableCopying>
/** 标识符 
 */
@property (nonatomic,strong) NSString*  identifier;

/** 类型
 */
@property (nonatomic, assign) MusicType type;

/**资源分类ID
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 */
@property (nonatomic, strong) NSString *networkResourceId;

/**使用音乐地址
 */
@property (nonatomic, strong) NSURL *  url;

/**音乐在整个视频中的时间范围，默认为整个视频的TimeRange
 */
@property (nonatomic, assign) CMTimeRange effectiveTimeRange;

/**音乐截取时间范围
 */
@property (nonatomic, assign) CMTimeRange clipTimeRange;

/** 循环时长(相对于音乐总时长)
 *  isRepeat为YES时有效，默认与clipTimeRange一致
 */
@property (nonatomic,assign) CMTimeRange repeatTimeRange;

/**音乐名称
 */
@property (nonatomic, strong) NSString * name;
/**音频关键帧
 *  设置该属性后，volume无效
 */
@property (nonatomic, strong) NSMutableArray <AudioVolumePosition *> *volumePointArray;
/** 曲线变速
 *  设置该属性后，speed无效
 */
@property (nonatomic, strong) NSMutableArray <CurvedSpeedPoint *>*curvedSpeedPointArray;

/** 曲线变速类型
 */
@property (nonatomic, assign) CurveSpeedType curveSpeedType;

//曲线变速 操作界面 播放进度的显示
/** 原始时间点
 */
@property (nonatomic, strong) NSMutableArray * curvedOriginalTimeArray;
/** 变速后时间点
 */
@property (nonatomic, strong) NSMutableArray * curvedShiftTimeArray;

/**  播放速度，默认为1.0
 */
@property (nonatomic,assign) float speed;

/**音量(0.0-1.0)，默认为1.0
 */
@property (nonatomic, assign) float volume;

/**  去噪级别(0~3)  默认为0.0(不去噪)
 */
@property (nonatomic,assign) int denoiseLevel;

/**音调(大于0.0)，默认为1.0（原音），audioFilterType为AudioFilterTypeCustom时生效
 */
@property (nonatomic, assign) float pitch;

/**是否重复播放，默认为YES
 */
@property (nonatomic, assign) BOOL isRepeat;

/**配乐是否淡入淡出，默认为NO
 */
@property (nonatomic, assign) BOOL isFadeInOut;

/**配乐开头淡入淡出时长，默认为2.0秒
 */
@property (nonatomic, assign) float headFadeDuration;

/**配乐结尾淡入淡出时长，默认为2.0秒
 */
@property (nonatomic, assign) float endFadeDuration;

/**配乐淡入淡出时长，默认为2.0秒
 */
@property (nonatomic, assign) float fadeDuration DEPRECATED_MSG_ATTRIBUTE("Use headFadeDuration and endFadeDuration instead.");

/** 音乐滤镜
 */
@property (nonatomic, assign) AudioFilterType audioFilterType;

@end


typedef NS_ENUM(NSInteger, MVEffectType) {
    MVEffectTypeNormal,      //常规绘制，不做任何处理
    MVEffectTypeMask,        //mask视频为左右结构
    MVEffectTypeScreen,
    MVEffectTypeGray,
    MVEffectTypeGreen,
    MVEffectTypeChroma,      //可透过指定颜色
};

@interface MovieEffect : NSObject

/** MV路径
 */
@property (nonatomic,strong) NSURL*  url;

/** MV显示时长
 */
@property (nonatomic,assign) CMTimeRange timeRange;

/** 循环时长
 *  shouldRepeat为YES时有效，默认与timeRange一致
 */
@property (nonatomic,assign) CMTimeRange repeatTimeRange;

/** MV类型
 */
@property (nonatomic,assign) MVEffectType type;

/** 要透过的颜色，须与视频中一致
 *  type为MVEffectTypeChroma时有效
*/
@property (nonatomic,strong) UIColor *chromaColor;

/**要透过颜色的透明度低阀值，0.0~1.0,默认为0.1
 */
@property (nonatomic, assign) float chromaAlphaLower;

/**要透过颜色的透明度高阀值，0.0~2.0,默认为0.5
 */
@property (nonatomic, assign) float chromaAlphaUpper;

/**要透过颜色的边缘修整
 *  chromaEdgeSize > 0时，chromaAlphaUpper无效
 *  chromaEdgeSize == 0时，chromaAlphaUpper生效
 */
@property (nonatomic, assign) float chromaEdgeSize;

/** MV显示透明度
 */
@property (nonatomic,assign) float alpha;
/** 是否循环播放。默认为YES
 */
@property(readwrite, nonatomic) BOOL shouldRepeat;

/**画面裁剪位置，默认为(0.0,0.0,1.0,1.0)
 */
@property (nonatomic ,assign) CGRect crop;

@end

@interface Transition : NSObject<NSCopying, NSMutableCopying>
/* 转场属性 描述的是 当前场景如何向后一个场景过渡
 */

/**  转场类型
 */
@property (nonatomic,assign)  TransitionType   type;

/**资源分类ID
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 */
@property (nonatomic, strong) NSString *networkResourceId;

/**  持续时间
 */
@property (nonatomic,assign) CGFloat duration;
/** 上下左右推过程中的点
 */
@property (nonatomic,strong) NSArray *positions;
/**  自定义转场
 */
@property (nonatomic,strong) CustomTransition* customTransition;

/**  特效灰度图地址
 */
@property (nonatomic,strong) NSURL*  maskURL;

@property (nonatomic,assign) CMTimeRange timeRange;

@end

typedef NS_ENUM(NSInteger, ImageMediaFillType) {
    ImageMediaFillTypeFull, // 全填充
    ImageMediaFillTypeFit,  // 适配 静止
    ImageMediaFillTypeAspectFill,
    ImageMediaFillTypeFitZoomOut, // 适配 缩小
    ImageMediaFillTypeFitZoomIn   // 适配 放大
};

typedef NS_ENUM(NSInteger, VideoMediaFillType) {
    VideoMediaFillTypeFit,  // 适配 静止
    VideoMediaFillTypeFull // 全填充
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
    kFilterType_LookUp              // lookup滤镜
};

typedef NS_ENUM(NSInteger, AnimationInterpolationType) {
    AnimationInterpolationTypeLinear, // 线性(匀速)
    AnimationInterpolationTypeAccelerateDecelerate, //在动画开始结束的地方速率改变比较慢，中间加速
    AnimationInterpolationTypeAccelerate, // 加速
    AnimationInterpolationTypeDecelerate, // 减速
    AnimationInterpolationTypeCycle, 
};

typedef NS_ENUM(NSInteger, BlendType)
{
    BLEND_GL_ZERO,
    BLEND_GL_ONE,
    BLEND_GL_SRC_ALPHA,
    BLEND_GL_ONE_MINUS_SRC_ALPHA,
    
};

typedef NS_ENUM(NSInteger, BlendEquation)
{
    EQUATION_GL_FUNC_ADD,
};

typedef NS_ENUM(NSInteger, MediaAssetBlurType) {
    MediaAssetBlurTypeNone,            // 无效果
    MediaAssetBlurTypeZoomOut,         // 渐变模糊，由中心像四周扩散
    MediaAssetBlurTypeNormal,          // 高斯模糊
    
};

@interface MediaAssetBlur : NSObject<NSCopying, NSMutableCopying>

/** 设置模糊类型，现只支持MediaAssetBlurTypeNormal
 */
@property (nonatomic, assign)MediaAssetBlurType type   DEPRECATED_ATTRIBUTE;

/** 设置模糊强度0.0~1.0，默认为0.5
 */
@property (nonatomic, assign)float intensity;

/** 设置在video中没有添加模糊的区域，默认为CGRectZero
 *  (0, 0)为左上角 (1, 1)为右下角
 *  该属性已废弃
 */
@property (nonatomic, assign)CGRect unblurryRect DEPRECATED_MSG_ATTRIBUTE("Use setPointsLeftTop:rightTop:rightBottom:leftBottom: instead.");

/** 设置模糊时长
 *  设置媒体动画后，该属性无效，以动画中的atTime为准
 */
@property (nonatomic, assign)CMTimeRange timeRange;


/**在video中四个顶点的坐标，可设置非矩形。
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

@end

@interface MediaAssetAnimatePosition : NSObject

/**开始时间
 */
@property (nonatomic,assign) CGFloat atTime;

/**旋转锚点，默认CGPointMake(0.5, 0.5)
 */
@property (nonatomic,assign) CGPoint anchorPoint;

/**旋转角度,如果设置了动画的旋转角度，媒体的旋转角度无效
 */
@property (nonatomic,assign) CGFloat rotate;

/**在video中的位置大小，默认CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 * rect与pointsArray只有一个有效，以最后设置的为准
 */
@property (nonatomic,assign) CGRect rect;

/**透明度(0.0~1.0)，默认1.0
 */
@property (nonatomic,assign) CGFloat opacity;

/** 亮度 ranges from -1.0 to 1.0, with 0.0 as the normal level
 */
@property (nonatomic, assign) float brightness;

/** 对比度 ranges from 0.0 to 4.0 (max contrast), with 1.0 as the normal level
 */
@property (readwrite, nonatomic) float contrast;

/** 饱和度 ranges from 0.0 (fully desaturated) to 2.0 (max saturation), with 1.0 as the normal level
 */
@property (nonatomic, assign) float saturation;

/** 暗角 ranges from 0.0  to 1.0 (max vignette), with 0.0 as the normal level
 */
@property (nonatomic, assign) float vignette;

/** 锐化 ranges from -4.0 to 4.0 (max sharpness) , with 0.0 as the normal level
 */
@property (nonatomic, assign) float sharpness;

/** 色温 ranges from -1.0 to 1.0 (max whiteBalance) , with 0.0 as the normal level
 */
@property (nonatomic, assign) float whiteBalance;

/**动画类型
 */
@property (nonatomic,assign) AnimationInterpolationType type;

/**轨迹
 */
@property (nonatomic,strong) UIBezierPath*  path;

/** 内容放大 fillScale必须大于或等于1.0,默认为1.0
 */
@property (nonatomic,assign) CGFloat fillScale;

/** 设置模糊效果
 */
@property (nonatomic, strong) MediaAssetBlur *blur;

/**视频(或图片)裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 */
@property (nonatomic,assign) CGRect crop;

/**在video中四个顶点的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * rect与pointsArray只有一个有效，以最后设置的为准
 */
@property (nonatomic, readonly) NSArray *pointsArray;

/** 是否使用rect，默认为YES
 *  YES:使用rect   NO:使用pointsArray
 */
@property (nonatomic, readonly) BOOL isUseRect;

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

/**音频
 */
@interface AudioVolumePosition : NSObject

/**
 *  time factor (0~1)
 */
@property (nonatomic, assign) float timeFactor;

/**
 *  Curve speed (0~2)
 */
@property (nonatomic, assign) float vloume;

@end

/**曲线变速
 */
@interface CurvedSpeedPoint : NSObject

/**
 *  time factor (0~1)
 */
@property (nonatomic, assign) float timeFactor;

/**
 *  Curve speed (0.1~10)
 */
@property (nonatomic, assign) float speed;

@end

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
};

@interface MediaAsset : NSObject<NSCopying, NSMutableCopying>

/** 标识符
 */
@property (nonatomic,strong) NSString*  identifier;
/**  资源地址 图片  视频
 */
@property (nonatomic,strong) NSURL*  url;
@property (nonatomic,strong) NSString* localIdentifier;

/**  资源类型 图片 或者 视频
 */
@property (nonatomic,assign) MediaAssetType      type;

/** 可替换类型，默认为MediaReplaceableType_VideoOrPic
 */
@property (nonatomic, assign) MediaReplaceableType replaceType;

/**  图片填充类型
 *   设置顶点坐标(pointsInVideoArray)时，需设置为ImageMediaFillTypeFull
 */
@property (nonatomic,assign) ImageMediaFillType  fillType;

/**  视频填充类型，默认为VideoMediaFillTypeFit
 */
@property (nonatomic,assign) VideoMediaFillType  videoFillType;

/** 资源显示时间段  开始 与 持续时间
 *  图片设置持续时间  视频可以指定时间段
 */
@property (nonatomic,assign) CMTimeRange      timeRange;

/** 视频实际时长，去掉片头和片尾的黑帧
@abstract  Tthe actual duration of the video, remove the black frame from the beginning and end of the video.
*/
@property (nonatomic,assign) CMTimeRange videoActualTimeRange;

/**  在场景中开始时间
 */
@property (nonatomic,assign) CMTime startTimeInScene;

/** 是否重复播放，默认为NO
 *  设置为YES时，必须同时设置timeRangeInVideo
 */
@property (nonatomic, assign) BOOL isRepeat;

/**是否倒序
 */
@property (nonatomic, assign) BOOL isReverse;

/** 在整个视频中的持续时间范围
 *  只在isRepeat为YES时有效
 */
@property (nonatomic ,assign) CMTimeRange timeRangeInVideo;

/** 重复显示时间段  开始 与 持续时间(相对于媒体总时长)
 *  只在isRepeat为YES时有效，默认与timeRange一致
 */
@property (nonatomic,assign) CMTimeRange repeatTimeRange;

/**  播放速度 作用在图片段只会表现为播放时间改变 作用在视频上可以加速或者减速
 */
@property (nonatomic,assign) float            speed;

/** 曲线变速
 *  设置该属性后，speed无效
 */
@property (nonatomic, strong) NSMutableArray <CurvedSpeedPoint *>*curvedSpeedPointArray;

/** 曲线变速类型
 */
@property (nonatomic, assign) CurveSpeedType curveSpeedType;

//曲线变速 操作界面 播放进度的显示
/** 原始时间点
 */
@property (nonatomic, strong) NSMutableArray * curvedOriginalTimeArray;
/** 变速后时间点
 */
@property (nonatomic, strong) NSMutableArray * curvedShiftTimeArray;

/**  音量  默认为1.0
 */
@property (nonatomic,assign) float            volume;

/**  去噪级别(0~3)  默认为0.0(不去噪)
 */
@property (nonatomic,assign) int denoiseLevel;

/** 音量淡入时长，默认为0秒
 */
@property (nonatomic, assign) float audioFadeInDuration;

/** 音量淡出时长，默认为0秒
 */
@property (nonatomic, assign) float audioFadeOutDuration;

/**音调(大于0.0)，默认为1.0（原音），audioFilterType为AudioFilterTypeCustom时生效
 */
@property (nonatomic, assign) float pitch;

/**视频(或图片)裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 * 设置媒体动画后，该属性无效，以动画中的crop为准
 */
@property (nonatomic,assign) CGRect           crop;

/**视频(或图片)旋转角度 -360 < x < 360
 */
@property (nonatomic,assign) double           rotate;

/**是否上下镜像
 */
@property (nonatomic,assign) BOOL             isVerticalMirror;

/**是否左右镜像
 */
@property (nonatomic,assign) BOOL             isHorizontalMirror;

/**在video中的范围。默认为CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 * rectInVideo与pointsInVideoArray只有一个有效，以最后设置的为准
 * 设置媒体动画后，该属性及pointsInVideoArray属性均无效，以动画中的rect或pointsArray值为准
 */
@property (nonatomic, assign) CGRect           rectInVideo;

/** 视频(或图片)透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic,assign) float alpha;

/** 显示时长
 */
@property (nonatomic, readonly) CMTime duration;

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

/** 锐化 ranges from -4.0 to 4.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的sharpness值为准
 */
@property (nonatomic, assign) float sharpness;

/** 色温 ranges from -1.0 to 1.0 , with 0.0 as the normal level
 *  设置媒体动画后，该属性无效，以动画中的whiteBalance值为准
 */
@property (nonatomic, assign) float whiteBalance;

/**滤镜资源分类ID
 */
@property (nonatomic, strong) NSString *filterNetworkCategoryId;

/**滤镜资源ID
 */
@property (nonatomic, strong) NSString *filterNetworkResourceId;

/** 滤镜类型
 */
@property (nonatomic , assign) FilterType filterType;

/**滤镜资源地址
 */
@property (nonatomic , strong)  NSURL*   filterUrl;

/**滤镜强度，kFilterType_LookUp时有效,默认为1.0
 */
@property (nonatomic, assign)float filterIntensity;

/**滤镜时间(相对于媒体时间),默认和媒体时间一样
 */
@property (nonatomic, assign)CMTimeRange      filterTimeRange;

/**mask资源地址，可实现不规则媒体显示
 * 设置不规则mask后，rotate属性只支持90的倍数
 */
@property (nonatomic , strong) NSURL*  maskURL;


/**mosaic资源地址，可实现马赛克显示
 */
@property (nonatomic , strong) NSURL*  mosaicURL;

/**mosaic显示区域（矩形）
 */
@property (nonatomic , assign) CGRect rectMosaic;

/**mosaic旋转角度
 */
@property (nonatomic , assign) float mosaicAngle;


/** 媒体动画组
 */
@property (nonatomic, strong) NSArray<MediaAssetAnimatePosition*>*  animate;

/** 音乐滤镜
 */
@property (nonatomic, assign) AudioFilterType audioFilterType;

/**设置混合参数
 * 设置源因子，默认为：BLEND_GL_SRC_ALPHA
 */
@property (nonatomic, assign) BlendType srcFactor;

/**设置混合参数
 * 设置目标因子，默认为：BLEND_GL_ONE_MINUS_SRC_ALPHA
 */
@property (nonatomic, assign) BlendType dstFactor;

/**设置混合参数
 * 设置混合模式，默认为：EQUATION_GL_FUNC_ADD
 */
@property (nonatomic, assign) BlendEquation blendModel;

/** 设置模糊效果
 *  设置媒体动画后，该属性无效，以动画中的blur为准
 */
@property (nonatomic, strong) MediaAssetBlur *blur;

/** 设置模糊强度0.0~1.0，默认为0.0
 *  blur是对整个视频有效，而该属性仅对单个媒体有效
 */
@property (nonatomic, assign) float blurIntensity;

/** 设置媒体边框羽化宽度(0.0-1.0f),默认开启（0.1f)
 *  该属性只有设置blurIntensity时才有效
 */
@property (nonatomic, assign) float borderBlurIntensity;

/** 设置媒体边框模糊效果，默认为NO
 */
@property (nonatomic, assign) BOOL isBlurredBorder  DEPRECATED_ATTRIBUTE;

/**在video中四个顶点的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * rectInVideo与pointsInVideoArray只有一个有效，以最后设置的为准
 * 设置媒体动画后，该属性及rectInVideo属性均无效，以动画中的rect或pointsArray值为准
 */
@property (nonatomic, readonly) NSArray *pointsInVideoArray;

/** 是否使用rectInVideo，默认为YES
 *  YES:使用rectInVideo   NO:使用pointsInVideoArray
 */
@property (nonatomic, readonly) BOOL isUseRect;

/**在video中四个顶点的坐标，可设置非矩形，设置的值将赋给pointsInVideoArray属性。
 * (0, 0)为左上角 (1, 1)为右下角
 *  @param leftTop      媒体在video中的 左上角 顶点坐标
 *  @param rightTop     媒体在video中的 右上角 顶点坐标
 *  @param rightBottom  媒体在video中的 右下角 顶点坐标
 *  @param leftBottom   媒体在video中的 左下角 顶点坐标
 *
 * rectInVideo与pointsInVideoArray只有一个有效，以最后设置的为准
 * 设置媒体动画后，该属性及rectInVideo属性均无效，以动画中的rect或pointsArray值为准
 */
- (NSArray *)setPointsInVideoLeftTop:(CGPoint)leftTop
                            rightTop:(CGPoint)rightTop
                         rightBottom:(CGPoint)rightBottom
                          leftBottom:(CGPoint)leftBottom;

/**设置媒体自定义滤镜。
 */
@property (nonatomic, strong) CustomFilter* customFilter DEPRECATED_MSG_ATTRIBUTE("Use customFilterArray instead.");

/**设置媒体自定义滤镜数组。
 */
@property (nonatomic, strong) NSMutableArray <CustomFilter*>* customFilterArray DEPRECATED_MSG_ATTRIBUTE("Use customMultipleFilterArray instead.");

/**设置媒体自定义多滤镜数组，一个滤镜可以由多个滤镜组合而成。
 */
@property (nonatomic, strong) NSMutableArray <CustomMultipleFilter*>* customMultipleFilterArray;

/**设置媒体自定义动画。
 */
@property (nonatomic, strong) CustomFilter* customAnimate;

/**设置媒体自定义出场动画
 */
@property (nonatomic, strong) CustomFilter* customOutAnimate;

/**美颜磨皮，0.0~1.0,默认为0.0
 */
@property (nonatomic, assign) float beautyBlurIntensity;

/**美颜亮肤，0.0~1.0,默认为0.0
 */
@property (nonatomic, assign) float beautyBrightIntensity;

/**美颜红润，0.0~1.0,默认为0.0
 */
@property (nonatomic, assign) float beautyToneIntensity;

/**瘦脸，0.0~1.0,默认为0.0
    只支持iOS11.0以上
 */
@property (nonatomic, assign) float beautyThinFaceIntensity;

/**大眼，0.0~1.0,默认为0.0
    只支持iOS11.0以上
 */
@property (nonatomic, assign) float beautyBigEyeIntensity;

/** 五官美颜,如果设置了该参数，瘦脸beautyThinFaceIntensity / 大眼beautyBigEyeIntensity 参数无效,
    如果是图片并且检测到多张脸，根据 faceRect 匹配对应的脸，并设置对应参数（一张脸对应一份参数设置）；
    如果是视频并且检测到多张脸，默认使用数组中的第一个 FaceAttribute 参数设置到全部脸部数据（所有脸部五官参数共用一份参数设置）；
    只支持iOS11.0以上
 */
@property (nonatomic, strong)  NSMutableArray<FaceAttribute*>* multipleFaceAttribute;

/**美颜细节，0.0~1.0,默认为0.5
 */
@property (nonatomic, assign) float beautyDetail    DEPRECATED_ATTRIBUTE;


/** 要透过的颜色，须与视频或者图片中一致，FilterBlendType 需要设置为 FilterBlendTypeChromaColor 否则无效
*/
@property (nonatomic,strong) UIColor *chromaColor;

/** 混合模式
*/
@property (nonatomic, assign) FilterBlendType blendType;

/**抠图精度，0.0~1.0,默认为0.5
 */
@property (nonatomic, assign) float factor;

/**抠图透明度低阀值，0.0~1.0,默认为0.1
 */
@property (nonatomic, assign) float cutoutAlphaLower;

/**抠图透明度高阀值，0.0~2.0,默认为0.5
 */
@property (nonatomic, assign) float cutoutAlphaUpper;

/**抠图边缘修整
 *  cutoutEdgeSize > 0时，cutoutAlphaUpper无效
 *  cutoutEdgeSize == 0时，cutoutAlphaUpper生效  
 */
@property (nonatomic, assign) float cutoutEdgeSize;

/**蒙版
 */
@property (nonatomic, strong) MaskObject *mask;

/**智能抠像
 */
@property (nonatomic, assign) BOOL autoSegment;

@end



// Mask 用于异形
@interface MaskAsset : NSObject
// Mask类型  图片--灰度图 视频
@property (nonatomic , assign) MediaAssetType type;// 视频Mask 图片Mask
// mask资源地址
@property (nonatomic , strong) NSURL*  url;
// Mask持续时间
@property (nonatomic , assign) CMTimeRange timeRange; // 时间段
// 当mask为视频时 是否重复
@property (nonatomic , assign) BOOL isRepeat;// 在视频上是否重复
@end

@interface FilterAttribute : NSObject

/**滤镜特效类型
 */
@property (nonatomic,assign) VideoRealTimeFilterType filterType;
@property (nonatomic,assign) CMTimeRange timeRange;

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

#pragma mark - Caption

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

@interface Doodle :NSObject

@property (nonatomic,copy)NSString *path;

@property (nonatomic,assign)CMTimeRange timeRange;


@end

@interface DoodleLayer : CALayer<NSCopying, NSMutableCopying>

@property (nonatomic,copy)NSString *path;

@property (nonatomic,assign)CMTimeRange timeRange;

@end


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

/**字幕时间范围
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
@property (nonatomic, strong) MusicInfo * music;

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
@property (nonatomic, strong) CustomFilter *templateAnimate;


/**当前控件是否正在编辑
 *编辑状态要全部显示文字
 */
@property (nonatomic, assign) BOOL editing;

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

/** 字幕时间范围
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

/** 动画中的文字资源
 */
@interface JsonAnimationText : NSObject

/**标识符,可用于实时改变文字的时间等
 */
@property (nonatomic, copy) NSString *identifier;

/**在json中的大小
 */
@property (nonatomic ,assign) CGSize size;

/** 修改文字的开始显示时间
 *  默认为-1,不修改，按照json文件中的设置显示
 *  仅对json中都是可变文字的有效
 */
@property (nonatomic, assign) float startTime;

/** 修改文字的显示时长
 *  默认为-1,不修改，按照json文件中的设置显示
 *  仅对json中都是可变文字的有效
 */
@property (nonatomic, assign) float duration;

/** 文字图片
 */
@property (nonatomic ,copy) NSString * imagePath;

/**文字内容
 *  设置该属性后，imagePath将无效
 */
@property (nonatomic ,copy) NSString * text;

/**文字对齐方式 默认为CaptionTextAlignmentCenter
 */
@property (nonatomic ,assign) CaptionTextAlignment textAlignment;

/**文字颜色，默认为whiteColor
 */
@property (nonatomic ,strong) UIColor * textColor;

/** 文字透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic ,assign) float alpha;

/** 文字竖排，默认为NO
 *  仅支持一列
 */
@property (nonatomic ,assign) BOOL isVerticalText;

/**文字字体名称
 */
@property (nonatomic ,copy) NSString * fontName;

/**文字字体大小，为0时将自适应字体大小
 */
@property (nonatomic ,assign) float fontSize;

/**文字边距
 */
@property (nonatomic ,assign) UIEdgeInsets edgeInsets;

/**文字字体加粗，默认为NO
 */
@property (nonatomic ,assign) BOOL isBold;

/**文字字体斜体，默认为NO
 */
@property (nonatomic ,assign) BOOL isItalic;

/**文字描边颜色，默认黑色blackColor
 */
@property (nonatomic ,strong) UIColor * strokeColor;

/**文字描边宽度,默认为0.0
 */
@property (nonatomic ,assign) float strokeWidth;

/** 文字描边透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic, assign) float strokeAlpha;

/**文字是否设置阴影，默认为NO
 */
@property (nonatomic ,assign) BOOL isShadow;

/**文字阴影颜色，默认黑色blackColor
 */
@property (nonatomic ,strong) UIColor * shadowColor;

/**文字阴影偏移量,默认为CGSizeMake(0, -1)
 */
@property (nonatomic ,assign) CGSize shadowOffset;

@end

/** AE生成json文件动画所需要的背景资源(视频或图片)
 */
@interface JsonAnimationBGSource : NSObject<NSCopying, NSMutableCopying>

/** 标识符
 */
@property (nonatomic,strong) NSString*  identifier;

/** 资源文件路径
 */
@property (nonatomic, copy) NSString *path;

/**  资源类型 图片 或者 视频，默认MediaAssetTypeVideo
 */
@property (nonatomic,assign) MediaAssetType type;

/**  图片填充类型，默认为ImageMediaFillTypeFit
 */
@property (nonatomic,assign) ImageMediaFillType  fillType;

/**  视频填充类型，默认为VideoMediaFillTypeFit
 */
@property (nonatomic,assign) VideoMediaFillType  videoFillType;

/**视频(或图片)裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 */
@property (nonatomic, assign) CGRect crop;

/** 资源显示时间段  开始 与 持续时间
 *  图片设置持续时间  视频可以指定时间段
 */
@property (nonatomic,assign) CMTimeRange timeRange;

/** 在整个视频中的持续时间范围
 */
@property (nonatomic ,assign) CMTimeRange timeRangeInVideo;

/**  在整个视频中的开始时间
 */
@property (nonatomic,assign) CMTime startTimeInVideo DEPRECATED_MSG_ATTRIBUTE("Use timeRangeInVideo instead.");

/**  音量  默认为1.0
 */
@property (nonatomic,assign) float volume;

/**是否重复播放，默认为NO
 */
@property (nonatomic, assign) BOOL isRepeat;

/** 配乐
 */
@property (nonatomic, strong) MusicInfo *music;

@end

/** AE生成json文件动画
 */
@interface JsonAnimation : NSObject<NSCopying, NSMutableCopying>

/** 动画唯一名称
 */
@property (nonatomic, copy) NSString *name  DEPRECATED_ATTRIBUTE;

/** json文件路径
 */
@property (nonatomic, copy) NSString *jsonPath;

/** json文件路径字典
 *  与jsonPath二者设置其一即可，以jsonPath优先
*/
@property (nonatomic, strong) NSDictionary *jsonDictionary;

/** 动画所有固定图片路径
 */
@property (nonatomic, strong) NSArray *nonEditableImagePathArray;

/** 动画背景视频/图片
 */
@property (nonatomic, strong) NSMutableArray <Scene *>*bgSourceArray;
@property (nonatomic, strong) NSArray <JsonAnimationBGSource *>*backgroundSourceArray DEPRECATED_MSG_ATTRIBUTE("Use bgSourceArray instead.");

/** 动画中所有文字资源
 *  须与json中的显示顺序一致，可通过接口getAESourceInfoWithJosnPath:获取资源的信息
 */
@property (nonatomic, strong) NSArray <JsonAnimationText *>*textSourceArray;

/** 导出帧率，默认为18
 */
@property (nonatomic, assign) int exportFps;

/** 动画中图片裁剪后最大宽或高，默认为720.0
 *  对于1080P的图片，设置为720会导致图片不清晰，可根据需求设置
 */
@property (nonatomic, assign) float targetImageMaxSize;

/**是否循环播放，默认为NO
 */
@property (nonatomic, assign) BOOL  isRepeat;

/** 片头时长，
 *  用于循环时，不可循环的片头时长，默认为0
 */
@property (nonatomic, assign) float  openingDuration;

/** 片尾时长
 *  用于循环时，不可循环的片尾时长，默认为0
 */
@property (nonatomic, assign) float  endingDuration;

@property (nonatomic, assign) BOOL  ispiantou;
@property (nonatomic, assign) BOOL  ispianwei;
@property (nonatomic, assign) BOOL  isJson1V1;

@end

@interface JsonAnimationMediaInfo : NSObject

/** 资源类型
 */
@property (nonatomic, assign) JsonAnimationMediaType type;

/** 资源名称
 */
@property (nonatomic, strong) NSString *name;

/** 资源大小
 */
@property (nonatomic, assign) CGSize size;

/** 资源显示开始时间
 */
@property (nonatomic, assign) float startTime;

/** 资源显示时长
 */
@property (nonatomic, assign) float duration;

@end

@interface TransitionPostion : NSObject<NSCopying, NSMutableCopying>

@property(nonatomic,assign)float postion;
@property(nonatomic,assign)float atTime;
@end


/** 去水印
 */
@interface Dewatermark : NSObject

/** 去水印时间范围
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/**在video中的位置大小，默认CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 */
@property (nonatomic,assign) CGRect rect;

@end

UIKIT_EXTERN API_DEPRECATED("Watermark is deprecated. Use Overlay instead", ios(2.0, 9.0))
/** 视频水印
 */
@interface Watermark : NSObject

/** 持续时间范围
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/** 媒体
 */
@property (nonatomic,strong) MediaAsset*  media;

/**是否循环播放，默认为YES
 */
@property (nonatomic, assign) BOOL isRepeat;

@end

typedef NS_ENUM(NSInteger, OverlayType) {
    OverlayTypeNormal,  //画中画
    OverlayTypeDoodle,  //涂鸦
    OverlayTypeCover,   //封面
    OverlayTypeLogo,    //水印
};

/** 视频水印
 */
@interface Overlay : NSObject<NSCopying, NSMutableCopying>

/** 标识符
 */
@property (nonatomic,strong) NSString*  identifier;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 类型
 */
@property (nonatomic, assign) OverlayType type;

/** 持续时间范围
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/** 媒体
 */
@property (nonatomic,strong) MediaAsset*  media;

/**是否循环播放，默认为YES
 */
@property (nonatomic, assign) BOOL isRepeat;

@end

/** 马赛克
 */
@interface Mosaic : NSObject<NSCopying, NSMutableCopying>

/** 时间范围
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/** 马赛克大小(0.0~1.0)，默认为0.1
 */
@property (nonatomic, assign) float mosaicSize DEPRECATED_MSG_ATTRIBUTE("Use size instead.");
@property (nonatomic, assign) float size;

/**在video中四个顶点的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 */
@property (nonatomic, readonly) NSArray *pointsArray;


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

@end

@interface GifInputInfo : NSObject

/** 资源地址 图片  视频
*/
@property (nonatomic, strong) NSURL *url;

/** 资源类型 图片 或者 视频
*/
@property (nonatomic, assign) MediaAssetType type;

/** 资源显示时间段  开始 与 持续时间
 *  图片设置持续时间  视频可以指定时间段
*/
@property (nonatomic, assign) CMTimeRange timeRange;

/** 视频实际时长，去掉片头和片尾的黑帧
@abstract  Tthe actual duration of the video, remove the black frame from the beginning and end of the video.
*/
@property (nonatomic,assign) CMTimeRange videoActualTimeRange;

@end

@interface GifExportInfo : NSObject

/** 源资源
*/
@property (nonatomic, strong) NSArray <GifInputInfo *>*inputArray;

/** 水印
*/
@property (nonatomic, strong) UIImage *watermarkImage;

/**水印在Gif中的位置
 * (0, 0)为左上角 (1, 1)为右下角
 */
@property (nonatomic, assign) CGRect rectInVideo;

/** 分辨率
*/
@property (nonatomic, assign) CGSize size;

/** 帧率，默认为15
*/
@property (nonatomic, assign) int fps;

/** 是否循环播放，默认为YES
*/
@property (nonatomic, assign) BOOL isRepeat;

@end
