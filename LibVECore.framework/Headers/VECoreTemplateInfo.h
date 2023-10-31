//
//  VECoreTemplateInfo.h
//  LibVECore
//
//  Created by iOS VESDK Team  on 2021/4/21.
//  Copyright © 2021 iOS VESDK Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LibVECore/VECoreTemplateMediaAsset.h>
#import <LibVECore/VECoreTemplateCaption.h>
#import <LibVECore/VECoreTemplateMusic.h>
#import <LibVECore/VECoreTemplateParticle.h>
#import <LibVECore/VECoreTemplateTheme.h>

#pragma mark - 转场
@interface VECoreTemplateTransition : Transition

/**资源文件夹地址
 */
@property (nonatomic, strong) NSString *folderPath;

- (instancetype)initWithTransition:(Transition *)transition;

@end

#pragma mark - 场景背景
typedef NS_ENUM(NSInteger, BackgroundType) {
    BackgroundTypeColor,    //颜色
    BackgroundTypeImage,    //图片
    BackgroundTypeBlur,     //高斯模糊
};

@interface VECoreTemplateSceneBackground : NSObject

/** 类型
 */
@property (nonatomic, assign) BackgroundType type;

/** 颜色
*/
@property (nonatomic, strong) UIColor *color;

/** 模糊强度0.0~1.0，默认为0.0
 */
@property (nonatomic, assign) float blurIntensity;

/** 图片地址
 */
@property (nonatomic, copy) NSString *imagePath;

@end

#pragma mark - 场景
@interface VECoreTemplateScene : NSObject

/** 标识符
 */
@property (nonatomic,strong) NSString *identifier;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 是否是默认场景
 */
@property (nonatomic, assign) BOOL isDefault;

/** 场景背景媒体
*/
@property (nonatomic, strong) VECoreTemplateSceneBackground *background;

/**一个场景中可有多个媒体
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMediaAsset*>*media;

/** 转场
 */
@property (nonatomic, strong) VECoreTemplateTransition *transition;

- (instancetype)initWithScene:(Scene *)scene;

- (Scene *)getSceneWithFolderPath:(NSString *)folderPath;

@end

#pragma mark - 马赛克

@interface VECoreTemplateMosaicKeyFrameAnimate : KeyFrameAnimate

- (instancetype)initWithMosaicKeyFrameAnimate:(KeyFrameAnimate *)animate;

- (KeyFrameAnimate *)getKeyFrameAnimate;

@end

typedef NS_ENUM(NSInteger, MosaicType) {
    MosaicTypeNormal,       //马赛克
    MosaicTypeBlur,         //高斯模糊
    MosaicTypeDewatermark,  //去水印
};

@interface VECoreTemplateMosaic : NSObject

/**马赛克类型
 */
@property (nonatomic, assign) MosaicType type;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/** 设置模糊强度/马赛克大小0.0~1.0
 */
@property (nonatomic, assign)float intensity;

/**在video中四个顶点的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * 默认为({0, 0},{1, 0},{1, 1},{0, 1})
 */
@property (nonatomic, strong) NSArray <NSString *> *pointsArray;

- (instancetype)initWithMosaic:(id)mosaic;

- (id)getMosaicWithFolderPath:(NSString *)folderPath;

/** 高斯模糊是否开启跟踪，默认为NO
 */
@property (nonatomic, assign) BOOL isEnableTracking;

/** 关键帧动画
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateMosaicKeyFrameAnimate*>*  animates;

@end



#pragma mark - 画中画
@interface VECoreTemplateOverlay : NSObject

@property(nonatomic, assign)VEPIPType   pipType;

/** 标识符
 */
@property (nonatomic,strong) NSString *identifier;

/** 绑定场景标识符
 *  绑定场景后，转场也作用于该画中画
 *  After binding the scene, the transition also apply on the overlay.
 */
@property (nonatomic,strong) NSString*  identifierScene;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 媒体
 */
@property (nonatomic, strong) VECoreTemplateMediaAsset *media;

- (instancetype)initWithOverlay:(Overlay *)overlay;

- (Overlay *)getOverlayWithFolderPath:(NSString *)folderPath;

/** 多轨界面显示层级坐标
 */
@property(nonatomic,assign)float          fRailLevelY;

/**主题的画中画使用改参数： 0:循环 1:片头 2:片尾
 */
@property (nonatomic , assign)ThemeMediaType themeMaterialType;
@end

#pragma mark - 涂鸦笔
@interface VECoreTemplateDoodleItem : NSObject

/** 资源文件夹路径
 */
@property (nonatomic ,copy) NSString * folderPath;

/** 资源分类ID
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/** 资源ID
 */
@property (nonatomic, strong) NSString *networkResourceId;

/** 透明度 ，0.0 ~ 1.0 ，默认 1.0
 *  @abstract   opacity, 0.0 ~ 1.0, default 1.0
 */
@property (nonatomic, assign) float opacity;

/** 画笔粗细 ，0.0 ~ 1.0 ，默认 0.5
 *  @abstract   size, 0.0 ~ 1.0, default 0.5,
 */
@property (nonatomic, assign) float size;

/**  画刷硬度，淡入淡出 ，默认为 0.0
 *   @abstract  hardness，default is 0.0
 */
@property (nonatomic,assign)float hardness;
@property (nonatomic,assign)float density;
@property (nonatomic,assign)int   glowCenterColor;
@property (nonatomic,assign)float diameter;
@property (nonatomic,assign)float ratio;
/** 画笔颜色 ，默认为白色
 *  @abstract   color, default white
 */
@property (nonatomic, strong) UIColor* color;

/** 形状 ，支持如线、矩形、圆等，参考 SHAPE_MODE ，默认为 SHAPE_MODE_NORMAL
 *  @abstract   shape mode,like line,rect,oval etc...see enum SHAPE_MODE，default SHAPE_MODE_NORMAL
 */
@property (nonatomic, assign) int shapeMode;

/** 位置信息的json文件地址
 *  @abstract   points info
 */
@property (nonatomic, strong) NSString *points;

@end

@interface VECoreTemplateDoodleExAnimation : NSObject

/**开始时间
 *  @abstract  time
 */
@property (nonatomic,assign) CGFloat atTime;

/** 显示位置 ，(0, 0)为左上角 (1, 1)为右下角，默认为 （0，0，1，1）
 *  @abstract   rect, (0, 0) is the upper left corner (1, 1) is the lower right corner.default is (0, 0, 1, 1)
 */
@property (nonatomic,assign) CGRect showRectF;

/** 旋转角度,默认为 0
 *  @abstract   angle.default is 0.
 */
@property (nonatomic,assign) int rotate;

@end

@interface VECoreTemplateDoodleEx : NSObject

@property(nonatomic, assign)VEPIPType   pipType;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/** 涂鸦显示位置 ，(0, 0)为左上角 (1, 1)为右下角，默认为 （0，0，1，1），如果有设置关键帧动画 animation ，以关键帧动画参数为准
 *  @abstract   doodle rect, (0, 0) is the upper left corner (1, 1) is the lower right corner.default is (0, 0, 1, 1)
 */
@property (nonatomic,assign) CGRect showRectF;

/** 涂鸦旋转角度,默认为 0，如果有设置关键帧动画 animation ，以关键帧动画参数为准
 *  @abstract   doodle angle.
 */
@property (nonatomic,assign) int angle;

/** 涂鸦关键帧动画
 *  @abstract   doodle animations.
 */
@property (nonatomic,strong) NSMutableArray<VECoreTemplateDoodleExAnimation*>* keyFrameAnimates;

/** 涂鸦操作
 *  @abstract   option.
 */
@property (nonatomic,strong) NSMutableArray<VECoreTemplateDoodleItem*>* item;

- (instancetype)initWithDoodleEx:(DoodleEx *)doodleEx;

- (DoodleEx *)getDoodleExWithFolderPath:(NSString *)folderPath;

/** 层次，数值越大，越靠前，0 为最底层，默认为 0
 */
@property(nonatomic,assign) int level;
@property(nonatomic,assign) float scale;
@end

#pragma mark - 水印
@interface VECoreTemplateLogo : NSObject

/** 资源地址
 */
@property (nonatomic, strong) NSString *path;

/** 裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 */
@property (nonatomic, assign) CGRect cropRect;

/**在video中的范围。默认为CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 */
@property (nonatomic, assign) CGRect showRectF;

/** 透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic,assign) float alpha;

/** 旋转角度 -360 < x < 360
 */
@property (nonatomic,assign) double rotate;

- (instancetype)initWithOverlay:(Overlay *)overlay;

- (Overlay *)getOverlayWithFolderPath:(NSString *)folderPath;

@end

#pragma mark - 调色
@interface VECoreTemplateToningInfo : ToningInfo

@property(nonatomic, assign)VEPIPType   pipType;

@property(nonatomic, strong)VECoreTemplateCustomFilter *filter;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/** 关键帧动画
 */
@property (nonatomic, strong) NSMutableArray
*  keyAnimates;

- (instancetype)initWithTone:(ToningInfo *)tone;

- (ToningInfo *)getToningInfo;

@end

#pragma mark - 滤镜 调节 关键帧
@interface VECoreTemplateKeyFrameAnimate : NSObject

- (instancetype)initWithKeyAnimate:(KeyFrameAnimate *) keyAnimate;

- (KeyFrameAnimate *)getKeyAnimate;

/**开始时间
 */
@property (nonatomic,assign) CGFloat atTime;
/**强度
 */
@property (nonatomic,assign) float intensity;

@property (nonatomic, strong) VECoreTemplateToningInfo *  toningInfo;
@end

#pragma mark - 特效 关键帧
@interface VECoreTemplateEffectKeyFrameAnimate : NSObject

- (instancetype)initWithKeyAnimate:(KeyFrameAnimate *) keyAnimate;

- (KeyFrameAnimate *)getKeyAnimate;
/**开始时间
 */
@property (nonatomic,assign) CGFloat atTime;
@property (nonatomic,assign) float speed;
@property (nonatomic, strong) NSMutableArray *uniformParam;

@end


#pragma mark - 封面模板
@interface VECoreTemplateCoverTemplate : NSObject

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
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSubtitleEx*>* subtitleExs;

/** 使用该模板时，视频分辨率
 */
@property (nonatomic, assign) CGSize size;

- (instancetype)initWithCoverTemplate:(VECoreCoverTemplate *)coverTemplate videoSize:(CGSize)videoSize;

- (VECoreCoverTemplate *)getCoverTemplateWithFolderPath:(NSString *)folderPath videoSize:(CGSize)videoSize;

@end

#pragma mark - 媒体信息
@interface VECoreTemplateMediaInfo : NSObject

@property(nonatomic, strong)NSMutableArray * addTextList;
@property(nonatomic, strong)NSURL   * addTextOriginalImageUrl;
@property(nonatomic, assign)CGRect  addTextCrop;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 可替换类型，默认为MediaReplaceableType_VideoOrPic
 */
@property (nonatomic, assign) MediaReplaceableType replaceType;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/**  资源地址 图片  视频
 */
@property (nonatomic, strong) NSString *path;

/** YES：主媒体      NO：画中画
 */
@property (nonatomic, assign) BOOL isMainVideo;

@end

#pragma mark - 组片段信息
@interface VECoreGroupFragment : NSObject

/** 是否是默认片段
 */
@property (nonatomic, assign) BOOL isDefaultFragment;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

@property (nonatomic, strong) NSString *coverPath;

@property (nonatomic, strong) NSString *sceneIdentifier;

@property (nonatomic, strong) NSMutableArray<NSString *> *overlayIdentifiers;

@property (nonatomic, strong) NSMutableArray<NSString *>*subtitleIdentifiers;

@end

#pragma mark - 组信息
@interface VECoreGroupInfo : NSObject

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 是否是旁白，默认为NO
 */
@property (nonatomic, assign) BOOL isNarrator;

/** 片段
 */
@property (nonatomic, strong) NSMutableArray<VECoreGroupFragment *>* fragments;

@end

#pragma mark - 模板
@interface VECoreTemplateInfo : NSObject

/** 版本号
 */
@property (nonatomic, assign) float ver;

@property (nonatomic, strong) NSString *verName;

/** 时长
 */
@property (nonatomic, assign) Float64 duration;

/** 分辨率
 */
@property (nonatomic, assign) CGSize size;

/** 模板资源大小，单位M
 *  不导出媒体资源时才返回
 */
@property (nonatomic, assign) float fileSize;

/** 媒体信息，仅包含可替换媒体
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateMediaInfo*> *mediaInfo;

/** 编组信息
 */
@property (nonatomic, strong) NSMutableArray<VECoreGroupInfo*> *groupsInfo;

/** 场景
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateScene*>*scenes;

/** 片尾
 */
@property (nonatomic, assign) BOOL isHasEndScene;

/** 字幕
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSubtitle*>* subtitles;

/** 新版字幕
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSubtitleEx*>* subtitleExs;

/** 语音转字幕
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSubtitleEx*>* speechSubtitles;

/** 字幕模板
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSubtitleTemplate*>* subtitlesTemplate;

/** 贴纸
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSticker*>* stickers;

/** 配乐
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMusic*> *musics;

/** 配音
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMusic*> *dubbings;

/** 音效
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMusic*> *soundEffects;

/** 文字转语音
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMusic*> *speechs;

/** 马赛克、去水印、高斯模糊
*/
@property (nonatomic, strong) NSMutableArray<VECoreTemplateMosaic*>* mosaics;

/** 画中画
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateOverlay*>* overlays;

/** 涂鸦
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateOverlay*>* doodles;

/** 涂鸦笔
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateDoodleEx*>* doodlePens;

/** 水印
 */
@property (nonatomic, strong) VECoreTemplateLogo *logoOverlay;

/** 封面
 */
@property (nonatomic, strong) NSString *coverPath;
/** 封面 原始图像
 */
@property (nonatomic, strong) NSURL *coverOriginalPath;

/** 封面普通字幕
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSubtitleEx*>* coverSubtitleExs;

/** 封面模板字幕
 */
@property (nonatomic, strong) VECoreTemplateCoverTemplate *coverTemplate;

/** 滤镜
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateCustomFilter*>* customFilters;

/** 特效
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateSpecialEffect*>* specialEffects;

/** 调色
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateToningInfo*>* tonings;

/** 粒子
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateParticle *>*particles;

@property (nonatomic, strong) NSMutableArray    *pipList;

/**
 Creates and returns a new instance of the receiver from a json.
 This method is thread-safe.
 
 @param json  A json object in `NSDictionary`, `NSString` or `NSData`.
 
 @return A new instance created from the json, or nil if an error occurs.
 */
- (instancetype)initWithJSON:(id)json;

/**
 Generate a json object from the receiver's properties.
 
 @return A json object in `NSDictionary` or `NSArray`, or nil if an error occurs.
 See [NSJSONSerialization isValidJSONObject] for more information.
 
 @discussion Any of the invalid property is ignored.
 If the reciver is `NSArray`, `NSDictionary` or `NSSet`, it just convert
 the inner object to json object.
 */
- (id)objectToJSONObject;
/** 主题
*/
@property (nonatomic, strong) VECoreTemplateTheme *theme;
@end
