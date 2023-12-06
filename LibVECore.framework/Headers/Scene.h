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
#import <LibVECore/Common.h>

typedef NS_ENUM(NSInteger, VEPIPType){
    VEPIPType_Collage = 0,//画中画
    VEPIPType_Effect = 1,//特效
    VEPIPType_Ton = 2,//调色
    VEPIPType_Subtitle = 3,//字幕
    VEPIPType_Sticker = 4,//贴纸
    VEPIPType_Graffti = 5,//标记
    VEPIPType_Doodle = 6,//涂鸦
    VEPIPType_Filter    = 7,//滤镜
    VEPIPType_Particles = 8,//粒子

    VEPIPType_TEXT_SPEECH = 9,//文字(识别字幕)
    VEPIPType_WordTemplate = 10,//文字模板
};

typedef NS_ENUM(NSInteger, VEAudioSampleBits) {
    VEAudioSampleBits_16i,       //16位 short
    VEAudioSampleBits_32i,      //32位 int
    VEAudioSampleBits_32f      //32位 float
};

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
    AudioFilterTypeElectri,      // 电子
    AudioFilterTypeCustom,       // 自定义//调整媒体的pitch实现
};

typedef NS_ENUM(NSInteger, AntiShakeType) {
    antiShakeTypeNormal,        //无
    antiShakeTypeLeast,           //裁切最少
    antiShakeTypeRecommend,//推荐
    antiShakeTypeMostStable,  //最稳定
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
    MediaReplaceableType_VideoOrPic,    //不限制(优先图片)
    MediaReplaceableType_Picture,       //可替换图片
    MediaReplaceableType_Video,         //可替换视频
    MediaReplaceableType_Irreplaceable, //不可替换
    MediaReplaceableType_PriorityVideo,//不限制(优先视频)
};
typedef NS_ENUM(NSInteger, ThemeMediaType) {
    ThemeMediaType_Loop,    //循环
    ThemeMediaType_Head,    //片头
    ThemeMediaType_End,     //片尾
};
@class Transition;
@class MediaAsset;
@class CurvedSpeedPoint;
@class AudioVolumePosition;
@class FaceAttribute;

typedef NS_ENUM(NSInteger, SceneType) {
    SceneTypeNormal,    //默认
    SceneTypeEnd,       //片尾
    SceneTypeHead,      //片头
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
    MusicTypeSpeech,            //文字转语音
};

@interface CvDataInfo : NSObject <NSCopying,NSMutableCopying>
/**虚拟CV的作者ID*/
@property (nonatomic, strong) NSString*  userId ;
/**虚拟CV的语速*/
@property (nonatomic, assign) double rateConifg ;
/**虚拟CV的音高*/
@property (nonatomic, assign) double pitchConifg ;
/**虚拟CV的音量*/
@property (nonatomic, assign) double volumeConifg ;
/**虚拟CV情绪文本内容*/
@property (nonatomic, strong) NSString*  text ;
/**虚拟CV情绪名称*/
@property (nonatomic, strong) NSString*  emotionDes;
/**虚拟CV情绪Code*/
@property (nonatomic, strong) NSString*  emotionCode;
/**虚拟CV情绪下标*/
@property (nonatomic, assign) int emotionPosition ;
/**虚拟CV作者名字*/
@property (nonatomic, strong) NSString*  showName ;
/**神经语音人物*/
@property (nonatomic, strong) NSString*  languageStyle ;
@end

//MARK: 均衡器数值
@interface EqObject : NSObject<NSCopying,NSMutableCopying>
@property(nonatomic, assign)int frequecy;
@property(nonatomic, assign)float gain;
@end

@interface CaptionExTTS : NSObject<NSCopying, NSMutableCopying>
/** 音调
 */
@property(nonatomic, assign)float  pitch;

@property(nonatomic, strong)NSString *locale;

@property(nonatomic, strong)NSString *shortName;

@property(nonatomic, strong)NSString *sortId;

@property(nonatomic, assign)float        speed;

@property(nonatomic, strong)NSString    *type;

@property(nonatomic, strong)NSString    *text;

@end

@interface MusicInfo : NSObject<NSCopying,NSMutableCopying>
/** 标识符
 */
@property (nonatomic,strong) NSString*  identifier;
/** 踩点
 */
@property (nonatomic,strong) NSMutableArray*  time_list;
@property (nonatomic,assign) BOOL  isAutoClick;


/** CV对应的字幕标识符
 *  导出模板用
 */
@property (nonatomic,strong) NSString *captionIdentifier;



/** 标识符
 *  导出模板用
 */
@property (nonatomic,strong) NSString *speechUserId;
/** 文字转语音参数
 */
@property (nonatomic, strong) CaptionExTTS *captionTTS;

/** 虚拟CV信息
 *  导出模板用
 */
@property (nonatomic,strong) CvDataInfo*  mCvDataInfo;

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

/**  是否音调校正，设置曲线变速后无效，Default is NO。
 *   Tone correction, invalid after setting curve speed change.
 */
@property (nonatomic,assign) BOOL speedHoldPitch;

/**音量，默认为1.0
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
/** 均衡器数值数组
 */
@property (nonatomic, strong) NSMutableArray <EqObject*>* eq;

/** 是否为主题中的音乐的标识符
 */
@property (nonatomic,assign) BOOL isTemplateTheme;

/** 是否静音，只有 isAlwaysPlay 为 YES 时该属性生效，默认为：NO
 */
@property (nonatomic , assign) BOOL isMute;

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


/**设置多脚本转场，一个转场可以由多个滤镜组合而成
 */
@property (nonatomic, strong) CustomMultipleFilter* customMultipleFilter;

/**  自定义转场（单个脚本转场）
 */
@property (nonatomic,strong) CustomTransition* customTransition;

/**  特效灰度图地址
 */
@property (nonatomic,strong) NSURL*  maskURL;

@property (nonatomic,assign) CMTimeRange timeRange;
@property (nonatomic,assign) BOOL isTemplateTheme;



@end



typedef NS_ENUM(NSInteger, VideoMediaFillType) {
    VideoMediaFillTypeFit,  // 适配 静止
    VideoMediaFillTypeFull // 全填充
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

/** 暗角 ranges from -1.0  to 1.0 (max vignette), with 0.0 as the normal level
 */
@property (nonatomic, assign) float vignette;

/** 锐化 ranges from 0.0 to 1.0 (max sharpness) , with 0.0 as the normal level
 */
@property (nonatomic, assign) float sharpness;

/** 色温 ranges from -1.0 to 1.0 (max whiteBalance) , with 0.0 as the normal level
 */
@property (nonatomic, assign) float whiteBalance;

/** 调色
 */
@property (nonatomic, strong) ToningInfo* adjustments;

/**动画类型
 */
@property (nonatomic,assign) AnimationInterpolationType type;

/**轨迹
 */
@property (nonatomic,strong) UIBezierPath*  path;

/** 内容放大 fillScale必须大于或等于1.0,默认为1.0
 */
@property (nonatomic,assign) CGFloat fillScale;


/** 设置模糊强度0.0~1.0，默认为0.0
 */
@property (nonatomic, assign) float blurIntensity  DEPRECATED_MSG_ATTRIBUTE("Use blur instead.");

/** 设置模糊效果（关键帧中模糊类型必须一致）
 */
@property (nonatomic, strong) Blur *blur;

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
 *  音量
 */
@property (nonatomic, assign) float volume;

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

@interface Animation3D : NSObject<NSCopying, NSMutableCopying>

/**资源分类ID
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 */
@property (nonatomic, strong) NSString *networkResourceId;

/**  json资源地址
 */
@property (nonatomic,strong) NSURL*  url;

/** 动画  开始 与 持续时间
 */
@property (nonatomic,assign) CMTimeRange timeRange;

@end

// HDR
@interface HDR : NSObject<NSCopying, NSMutableCopying>

/** hdr 文件路径
 */
@property (nonatomic, strong) NSURL *filePath;

/** hdr 强度设置
 */
@property(nonatomic, assign) float  intensity;

@end


// 去雾
@interface Dehaze : NSObject<NSCopying, NSMutableCopying>

/** 去雾之后的图像
 */
@property (nonatomic, strong) NSURL *filePath;

/**  强度设置
 */
@property(nonatomic, assign) float  intensity;

@end


@interface MediaAsset : NSObject<NSCopying, NSMutableCopying>

@property(nonatomic, strong)MusicInfo   *webmMusicinfo;

@property(nonatomic, strong)NSMutableArray * addTextList;
@property(nonatomic, strong)NSURL   * addTextOriginalImageUrl;
@property(nonatomic, assign)CGRect  addTextCrop;
@property (nonatomic, assign) BOOL addTextReplaceType;

@property (nonatomic, strong)NSMutableArray *occlusionStickers;

/** 标识符
 */
@property (nonatomic,strong) NSString*  identifier;
/**  资源地址 图片  视频
 */
@property (nonatomic,strong) NSURL*  url;
@property (nonatomic,strong) NSURL*  coverOriginalUrl;
@property (nonatomic,strong) NSString* localIdentifier;

/** 视频帧回调，实现该回调后，url无效
 *  Video frame callback. After implementing the callback, the url is invalid.
 */
@property (nonatomic, copy) void(^videoPixelBufferRefHandler) (CVPixelBufferRef *pixelBufferRef);

@property (nonatomic, copy) void(^audioDateHandler) (NSMutableData **audioDate);

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

/**  是否音调校正，设置曲线变速后无效，Default is NO。
 *   Tone correction, invalid after setting curve speed change.
 */
@property (nonatomic,assign) BOOL speedHoldPitch;

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
/** 媒体是否隐藏
 */
@property (nonatomic, assign) BOOL isMediaHide;

/** 显示时长
 */
@property (nonatomic, readonly) CMTime duration;

/** 亮度 ranges from -1.0 to 1.0, with 0.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 brightness值 或者 adjustments值为准
 */
@property (nonatomic, assign) float brightness;

/** 对比度 ranges from -1.0 to 1.0 (max contrast), with 0.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 contrast值 或者 adjustments为准
 */
@property (readwrite, nonatomic) float contrast;

/** 饱和度 ranges from -1.0 (fully desaturated) to 1.0 (max saturation), with 0.0 as the normal level
 *  如果 adjustments 不为空，该属性无效；如果设置媒体动画后，该属性无效，以动画中的 saturation值 或者 adjustments值为准
*/
@property (nonatomic, assign) float saturation;


/** 暗角 ranges from -1.0 to 1.0 , with 0.0 as the normal level
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
 */
@property (nonatomic, strong) ToningInfo* adjustments;


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

/**滤镜强度，kFilterType_LookUp/kFilterType_Mosaic 时有效,默认为1.0
 * 如果有设置 filterAnimation 动画，以 filterAnimation 参数为准，该参数无效
 */
@property (nonatomic, assign)float filterIntensity;

/** 滤镜动画组
 */
@property (nonatomic, strong) NSArray<KeyFrameAnimate*>*  filterAnimation;

/**滤镜条纹启用，kFilterType_Mosaic时有效,默认为YES
 */
@property (nonatomic, assign)BOOL isStrip;

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

/** 设置模糊强度0.0~1.0，默认为0.0
 *  设置媒体动画后，该属性无效，以动画中的 blurIntensity 为准
 */
@property (nonatomic, assign) float blurIntensity DEPRECATED_MSG_ATTRIBUTE("Use blur instead.");


/** 设置模糊效果
 *  设置媒体动画后，该属性无效，以动画中的 blur 为准
 */
@property (nonatomic, strong) Blur *blur;


/** 设置媒体边框羽化宽度(0.0-1.0f),默认开启（0.1f)
 *  该属性只有设置blurIntensity时才有效
 */
@property (nonatomic, assign) float borderBlurIntensity DEPRECATED_ATTRIBUTE; 

/** 设置媒体边框模糊效果，默认为NO
 */
@property (nonatomic, assign) BOOL isBlurredBorder  DEPRECATED_ATTRIBUTE;

/**在video中四个顶点的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * rectInVideo与pointsInVideoArray只有一个有效，以最后设置的为准
 * 设置媒体动画后，该属性及rectInVideo属性均无效，以动画中的rect或pointsArray值为准
 */
@property (nonatomic, readonly) NSArray *pointsInVideoArray;

/** 是否通过导入文件生成的animate，Default is NO.
 *  Whether to generate animation by importing files
 */
@property (nonatomic, assign) BOOL importMorph;

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

/**设置媒体其他动画（例如：手绘画笔）
 */
@property (nonatomic, strong) CustomFilter* customOtherAnimate;

/**3d动画
 */
@property (nonatomic, strong) Animation3D*  animation3D;


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
@property (nonatomic, assign) float factor DEPRECATED_ATTRIBUTE;

/**抠图透明度低阀值，0.0~1.0,默认为0.1
 */
@property (nonatomic, assign) float cutoutAlphaLower;

/**抠图透明度高阀值，0.0~2.0,默认为0.5
 */
@property (nonatomic, assign) float cutoutAlphaUpper;

/**抠图边缘修整
 *  cutoutEdgeSize == 1 时，cutoutAlphaUpper无效
 *  cutoutEdgeSize == 0 或者 2 时，cutoutAlphaUpper生效
 */
@property (nonatomic, assign) float cutoutEdgeSize;

/**蒙版
 */
@property (nonatomic, strong) MaskObject *mask;
@property (nonatomic, assign)BOOL masked;//0 未使用蒙版 1 媒体已经是使用蒙版之后的图片

/**智能抠像
 */
@property (nonatomic, assign) kAutoSegmentType autoSegmentType;
@property (nonatomic, strong) NSURL *autoSegmentImageUrl;
@property (nonatomic, strong) UIImage *autoSegmentImage;
@property (nonatomic, strong) UIImage *autoSegmentMaskImage;    //抠像黑白图
@property (nonatomic, assign) BOOL isGIF;

/**景深
 */
@property (nonatomic, assign) BOOL isDOF;

/**流动效果
 */
@property (nonatomic, strong) FlowEffect* flowEffect;

/** 均衡器数值数组
 */
@property (nonatomic, strong) NSMutableArray <EqObject*>* eq;
/** 音频分离 true为分离
 */
@property(nonatomic, assign)BOOL    audioSeparate;

@property (nonatomic, strong) NSURL *antiShakeUrl;
@property (nonatomic, strong) NSURL *antiShakeTrf;
@property (nonatomic, assign) AntiShakeType   antiShakeType;

/**HDR
 */
@property (nonatomic, strong) HDR* hdr;

/**去雾
 */
@property (nonatomic, strong) Dehaze* dehaze;

/** 马赛克涂鸦
 *操作步骤：
 *  1.先将当前媒体设置为填充图片（optionType/fillImageURL）
 *  2.设置马赛克类型（strokeMask），将画刷设置为常规画刷（optionType），更新坐标点（eventArray）
*/
@property (nonatomic, strong) NSMutableArray <DoodleEx *>* maskDoodleArray;

/** 全景图
 */
@property (nonatomic, strong) Panorama* panorama;
@property (nonatomic, assign) BOOL  isGyroscope;


/** 层次，数值越大，越靠前，0 为最底层，默认为 0
 */
@property(nonatomic,assign) int level;

/** 是否静音，只有 isAlwaysPlay 为 YES 时该属性生效，默认为：NO
 */
@property (nonatomic , assign) BOOL isMute;

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


/** 视频水印
 */
@interface Overlay : NSObject<NSCopying, NSMutableCopying>

/** 标识符
 */
@property (nonatomic,strong) NSString*  identifier;

/** 绑定场景标识符
 *  绑定场景后，转场也作用于该画中画
 *  After binding the scene, the transition also apply on the overlay.
 */
@property (nonatomic,strong) NSString*  identifierScene;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 类型
 */
@property (nonatomic, assign) OverlayType type;

/** 在虚拟视频中的持续时间范围
 */
@property (nonatomic ,assign) CMTimeRange timeRange;

/** 媒体
 */
@property (nonatomic,strong) MediaAsset*  media;

/**是否循环播放，默认为YES
 */
@property (nonatomic, assign) BOOL isRepeat;

/** 多轨界面显示层级坐标
 */
@property(nonatomic,assign)float          fOverlayRailLevelY;

/** 是否为主题中的画中画的标识符
 */
@property (nonatomic,assign) BOOL isTemplateTheme;

/**主题的画中画使用改参数： 0:循环 1:片头 2:片尾
 */
@property (nonatomic , assign)ThemeMediaType themeMaterialType;



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

@interface TemplateExportInfo : NSObject

/** 是否导出片段信息，默认为NO
 */
@property (nonatomic, assign) BOOL isHasFragments;

/** 是否导出素材，默认为NO
*/
@property (nonatomic, assign) BOOL isExportTemplateMedias;

/** 是否导出封面，默认为NO
 */
@property (nonatomic, assign) BOOL isExportCoverMedia;

/** 是否导出的五官美颜参数，默认为NO
 */
@property (nonatomic, assign) BOOL isExportMediaMultipleFaceAttribute;

/** 是否导出预览视频，默认为NO
 */
@property (nonatomic, assign) BOOL isExportPreviewVideo;

/** 视频码率，单位为M (例：设置为5M码率，传值为5)
 */
@property (nonatomic, assign) float previewVideoBitrate;

/** 视频帧率
 */
@property (nonatomic, assign) int previewVideoFps;

/** 音频码率(单位：Kbps 默认为128)
 */
@property (nonatomic, assign) int previewVideoAudioBitRate;

/** 音频通道数   默认为：1
 */
@property (nonatomic, assign) int previewVideoAudioChannelNumbers;

/** 最大导出时长 默认为0 不限制
 */
@property (nonatomic, assign) float previewVideoMaxExportDuration;

/** 视频的元信息
 */
@property (nonatomic, strong) NSArray <AVMetadataItem*>*previewVideoMetadata;

/** 素材默认来源  0相册; 1拍摄
 */
@property (nonatomic, assign) NSInteger mediaSource;
@property (nonatomic, assign) BOOL isPuzzleSplitScreen;
@property (nonatomic, assign) BOOL isTemplate;
@property (nonatomic, assign) BOOL isPuzzle;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *desc;
@property (nonatomic, strong) NSString *author;
@property (nonatomic, assign) long createTime;
@property (nonatomic, assign) long updateTime;
 
@end
