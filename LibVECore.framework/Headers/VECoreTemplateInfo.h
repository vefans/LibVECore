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
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

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

@end

#pragma mark - 画中画
@interface VECoreTemplateOverlay : NSObject

/** 标识符
 */
@property (nonatomic,strong) NSString *identifier;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 媒体
 */
@property (nonatomic, strong) VECoreTemplateMediaAsset *media;

- (instancetype)initWithOverlay:(Overlay *)overlay;

- (Overlay *)getOverlayWithFolderPath:(NSString *)folderPath;

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

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

- (instancetype)initWithTone:(ToningInfo *)tone;

- (ToningInfo *)getToningInfo;

@end

#pragma mark - 媒体信息
@interface VECoreTemplateMediaInfo : NSObject

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 可替换类型，默认为MediaReplaceableType_VideoOrPic
 */
@property (nonatomic, assign) MediaReplaceableType replaceType;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/**  资源地址 图片  视频
 */
@property (nonatomic, strong) NSString *path;

@end

#pragma mark - 组片段信息
@interface VECoreGroupFragment : NSObject

/** 是否是默认片段
 */
@property (nonatomic, assign) BOOL isDefaultFragment;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

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

/** 时长
 */
@property (nonatomic, assign) float duration;

/** 分辨率
 */
@property (nonatomic, assign) CGSize size;

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

/** 马赛克、去水印、高斯模糊
*/
@property (nonatomic, strong) NSMutableArray<VECoreTemplateMosaic*>* mosaics;

/** 画中画
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateOverlay*>* overlays;

/** 涂鸦
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateOverlay*>* doodles;

/** 水印
 */
@property (nonatomic, strong) VECoreTemplateLogo *logoOverlay;

/** 滤镜
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateCustomFilter*>* customFilters;

/** 特效
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateSpecialEffect*>* specialEffects;

/** 调色
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateToningInfo*>* tonings;

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

@end
