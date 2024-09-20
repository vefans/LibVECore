//
//  VECore.h
//  VECore
//
//  Created by iOS SDK Team on 2017/5/8.
//  Copyright © 2017年 iOS SDK Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <LibVECore/Scene.h>
#import <LibVECore/CameraManager.h>
#import <LibVECore/VECoreTemplateInfo.h>

@class MusicInfo;
@class FilterAttribute;
@class VECore;
@class FaceRecognition;

@protocol VECoreDelegate<NSObject>

@optional

/** 状态
 */
- (void)statusChanged:(VECore *)sender status:(VECoreStatus)status;
- (void)statusChanged:(VECoreStatus)status;

/** 当前时间
 */
- (void)progressCurrentTime:(CMTime)currentTime;
- (void)progress:(VECore *)sender currentTime:(CMTime)currentTime;

/** 可在customDrawLayer上实时添加layer，实现自绘
 */
- (void)progressCurrentTime:(CMTime)currentTime customDrawLayer:(CALayer *)customDrawLayer;

/** 播放结束
 */
- (void)playToEnd;

- (void)tapPlayerView;

/*
 *  以下两个函数功能类似，如果两个同时存在，优先使用第二个，主要功能有两点：1.人像分割 2.人脸取点
 *  @params pixelBuffer    视频帧
 *  @params asset          媒体对象
 *  @params currentTime    时间
 */
- (NSArray<FaceRecognition*>*)willOutputPixelBuffer:(CVPixelBufferRef)pixelBuffer asset:(MediaAsset*)asset;
- (NSArray<FaceRecognition*>*)willOutputPixelBuffer:(CVPixelBufferRef)pixelBuffer asset:(MediaAsset*)asset currentTime:(CMTime)currentTime;

/*
 *  用于目标追踪等，根据时间线获取虚拟视频画面
 *  @params pixelBuffer    视频帧
 *  @params currentTime    时间
 */
- (void)willOutputPixelBuffer:(CVPixelBufferRef)pixelBuffer currentTime:(CMTime)currentTime;

/*
 *  用于人脸贴纸（人脸贴纸遮挡），在遮挡人脸之前根据当前虚拟视频画面获取人脸位置信息
 *  @params pixelBuffer    视频帧
 *  @params currentTime    时间
 *  @params type           类型，仅仅只有类型为 CaptionExTypeOcclusionStickers 时生效
 */
- (void)willOutputPixelBuffer:(CVPixelBufferRef)pixelBuffer currentTime:(CMTime)currentTime type:(int)type;

/*
 *  用于虚拟直播间，返回媒体的音频数据，当 finish 为 YES 时，由外部进行混音后在播放
 *  @params audioBuffer    媒体音频数据
 *  @params asset          媒体对象
 *  @params finish         是否为最后一个媒体，当 finish 为 YES 时，由外部进行混音后在播放
 */
- (void)willOutputAudioBuffer:(CMSampleBufferRef)audioBuffer asset:(MediaAsset*)asset finish:(BOOL)finish;

/*
 *  用于虚拟直播间，返回多个媒体混音的结果，可直接播放
 *  @params audioData    多个媒体混音的结果
 */
- (void)willOutputAudioData:(NSMutableData*)audioData ;

@end

typedef NS_ENUM(NSInteger, ReverseAudioType) {
    AudioTypeNone,       //无声音
    AudioTypeOriginal,   //保留原声
    AudioTypeReverse   //保留原声
};
typedef NS_ENUM(NSUInteger, VECoreViewFillMode) {
    kVECoreViewFillModeStretch,
    kVECoreViewFillModeScaleAspectFit,
    kVECoreViewFillModeScaleAspectFill
};

typedef NS_ENUM(NSUInteger, VEExportVideoCodecType) {
    VEExportVideoCodecTypeH264,
    VEExportVideoCodecTypeHEVC  API_AVAILABLE(ios(11.0)),
};

//画质级别
typedef NS_ENUM(NSUInteger, VEExportVideoProfileLevelType) {
    VEExportVideoProfileLevelTypeBaseline,  //基本
    VEExportVideoProfileLevelTypeMain,      //主流
    VEExportVideoProfileLevelTypeHigh,      //高级
};

typedef NS_ENUM(NSUInteger, VEExportVideoDynamicRangeType) {
    VEExportVideoDynamicRangeType_SDR,
    VEExportVideoDynamicRangeType_HDR10,
    VEExportVideoDynamicRangeType_HLG  API_AVAILABLE(ios(14.0)),
};

/*!
 @class VECoreVideoExportSettings
 @abstract
    导出视频时的设置
    The settings used for encoding the video.
 */
@interface VECoreVideoExportSettings : NSObject

/*!
 @property size
 @abstract
    分辨率
    Resolution set for exported video.
 */
@property (nonatomic, assign) CGSize size;

/*!
 @property videoBitRate
 @abstract
    码率
    Bitrate set for exported video. The default value is 4.
 */
@property (nonatomic, assign) float videoBitRate;

/*!
 @property fps
 @abstract
    帧率
    Frame rate set for exported video.
 */
@property (nonatomic, assign) NSInteger fps;

/*!
 @property metadata
 @abstract
    视频元数据
    A collection of metadata to be written to the video.
 */
@property (nonatomic, strong) NSArray<AVMetadataItem*> *metadata;

/*!
 @property audioBitRate
 @abstract
    音频码率(单位：Kbps 默认为128)
    Audio bit rate set for exported video. The default value is 128Kbps.
 */
@property (nonatomic, assign) float audioBitRate;

/*!
 @property audioChannelNumbers
 @abstract
    音频通道数，默认为：1
    Number of audio channels set for exported video. The default value is 1.
 */
@property (nonatomic, assign) NSInteger audioChannelNumbers;

/*!
 @property maxExportVideoDuration
 @abstract
    最大导出时长，默认为0 ：不限制
    Maximum export duration set for exported video. The default value is 0. 0 means no limit.
 */
@property (nonatomic, assign) float maxExportVideoDuration;

/*!
 @property videoCodecType
 @abstract
    编码类型，默认为 VEExportVideoCodecTypeH264
    Encoding type set for exported video. The default value is VEExportVideoCodecTypeH264.
 */
@property (nonatomic, assign) VEExportVideoCodecType videoCodecType;

/*!
 @property dynamicRangeType
 @abstract
    动态范围类型，默认为VEExportVideoDynamicRangeType_SDR。
    The default value is VEExportVideoDynamicRangeType_SDR.
 */
@property (nonatomic, assign) VEExportVideoDynamicRangeType dynamicRangeType;

/*!
 @property videoProfileLevelType
 @abstract
    画质级别，默认为 VEExportVideoProfileLevelTypeBaseline
    Quality level set for exported video. The default value is VEExportVideoProfileLevelTypeBaseline.
 */
@property (nonatomic, assign) VEExportVideoProfileLevelType videoProfileLevelType;

/*!
 @property fileType
 @abstract
    文件类型，默认为 mp4
    A UTI indicating the format of the file to be written. The default value is AVFileTypeMPEG4.
 */
@property (nonatomic, assign) AVFileType fileType;

@end

@interface VECore : NSObject<NSCopying,NSMutableCopying>

@property(nonatomic, copy)void(^build_Call)(void);

-(void)setVirtualLiveAudio:( BOOL ) isSilence;
 /*!
 @property audioSampleRate
 @abstract
    启用音频数据实时回调 （）
    Bitrate set for exported video. The default value is 4.
 */
@property (nonatomic, assign) BOOL enableAudioSampleBuffer;
/*!
 @property audioSampleRate
 @abstract
    音频采样率 (默认44100)
    Bitrate set for exported video. The default value is 4.
 */
@property (nonatomic, assign) Float64 audioSampleRate;

/** 用于获取视频截图
 */
@property (nonatomic, readonly) AVMutableComposition *composition;
@property (nonatomic, readonly) AVMutableVideoComposition *videoComposition;

/** 是否循环播放。默认为NO
 */
@property(readwrite, nonatomic) BOOL shouldRepeat;

/** 设置播放速度，不会真正使视频变速。默认为1.0
 */
@property (nonatomic, assign) float playRate;
@property (nonatomic,assign) BOOL isAlwaysPlay;

/** 可播放状态
 */
@property (nonatomic, readonly) VECoreStatus status;

/** 视频总时长
 */
@property (nonatomic,readonly) float duration;

/** 当前时间
 */
@property (nonatomic,readonly) CMTime currentTime;

/** 指定播放器视图位置大小
 */
@property (nonatomic,assign) CGRect frame;

/** 播放器视图
 */
@property (nonatomic,readonly) UIView* view;

/** 播放器视图显示方式。默认kVECoreViewFillModeScaleAspectFit
 */
@property (nonatomic,assign) VECoreViewFillMode fillMode;

/** 是否实时更新特效滤镜。默认为NO，且在为NO时记录下当前滤镜的TimeRange保存
 */
@property (nonatomic,assign) BOOL isRealTime;

/** 是否正在播放
 */
@property (nonatomic,readonly) BOOL isPlaying;

/** 预览或者导出支持的最大分辨率
 */
@property (nonatomic,readonly) CGSize supportMaxSize;

/** 字幕
 */
@property (nonatomic, strong) NSMutableArray<Caption*>* captions  DEPRECATED_MSG_ATTRIBUTE("Use captionExs instead.");

/** 字幕
 */
@property (nonatomic, strong) NSMutableArray<CaptionEx*>* captionExs;

/** 封面模板字幕
 */
@property (nonatomic, strong) VECoreCoverTemplate* coverTemplate;

/** 非矩形字幕
 */
@property (nonatomic, strong) NSMutableArray<CaptionLight*>* nonRectangleCaptions;

/** 贴纸
 */
@property (nonatomic, strong) NSMutableArray<Caption*>* stickers  DEPRECATED_MSG_ATTRIBUTE("Use captionExs instead.");

/** 高斯模糊
*/
@property (nonatomic, strong) NSMutableArray<MediaAssetBlur*>* blurs;

/** 马赛克
*/
@property (nonatomic, strong) NSMutableArray<Mosaic*>* mosaics;

/** 去水印
 */
@property (nonatomic, strong) NSMutableArray<Dewatermark*>* dewatermarks;

/** 设置动画资源文件路径，默认为tmp/JsonAnimationAnimate
 */
@property (nonatomic, copy) NSString *animationFolderPath;

/** AE生成的动画json文件中，视频size
 */
@property (nonatomic, readonly) CGSize animationSize;

/** AE生成的动画json文件中，视频/图片信息
 */
@property (nonatomic, readonly) NSMutableArray <JsonAnimationMediaInfo*>* aeSourceInfo;

/** 音效 支持实时调整音量及声音特效 默认未开启
 */
@property (nonatomic, assign) BOOL enableAudioEffect;

//#ifdef USE_MULTIPLE_SHADER
/** 自定义滤镜
 */
@property (nonatomic, strong) NSMutableArray <CustomFilter*>* customFilterArray;

/**设置媒体自定义多滤镜数组，一个滤镜可以由多个滤镜组合而成。
 */
@property (nonatomic, strong) NSMutableArray <CustomMultipleFilter*>* customMultipleFilterArray;
//#else
///** 自定义滤镜
// */
//@property (nonatomic, strong) NSMutableArray <CustomFilter*>* customFilterArray;
//#endif

/** 水印，支持视频/图片
 *  适用于整个虚拟视频添加多个水印的情况，可用于画中画、涂鸦等
 */
@property (nonatomic, strong) NSMutableArray <Watermark*>* watermarkArray  DEPRECATED_MSG_ATTRIBUTE("Use overlayArray instead.");
@property (nonatomic, strong) NSMutableArray <Overlay*>* overlayArray;

/** 水印，支持视频/图片
 *  可用于图片/文字水印，与watermarkArray互不影响
 */
@property (nonatomic, strong) Watermark *logoWatermark  DEPRECATED_MSG_ATTRIBUTE("Use logoOverlay instead.");
@property (nonatomic, strong) Overlay *logoOverlay;

/** 调色
*/
@property (nonatomic, strong) NSMutableArray <ToningInfo*>* toningArray;


/** 粒子
*/
@property (nonatomic, strong) NSMutableArray <Particle*>* particleArray;

/** 涂鸦
*/
@property (nonatomic, strong) NSMutableArray <DoodleEx *>* doodleArray;

/** 片尾黑视频时长，默认为kCMTimeZero
 *  用于画中画、配乐等素材时长可大于主视频的情况
*/
@property (nonatomic, assign) CMTime endBlackVideoDuration;

@property (nonatomic,weak) id<VECoreDelegate> delegate;


/**  初始化对象
 *  @abstract  Returns an instance of VECore for reading media data.
 *
 *  @param appkey           在官网中注册的应用Key。
                            Application Key registered in the SDK official website.
 *
 *  @param appsecret        在官网(中注册的应用秘钥。
                            Application secret key registered in the SDK official website.
 *
 *  @param licenceKey       在官网(中注册的licenceKey。
                            The licenseKey registered in the SDK official website.
 
 *  @param  size            视频分辨率
                            Indicates the authored size of the virtual video of the asset.
 
 *  @param  fps             视频帧率(1-30)
                            Indicates the interval which the virtual video, when enabled, should render composed video frames.
 
 *  @param resultFailBlock  初始化失败的回调［error：初始化失败的错误码］
                            A block that will be called when initialization is failed.
 */
- (instancetype) initWithAPPKey:(NSString *)appkey
                      APPSecret:(NSString *)appsecret
                     LicenceKey:(NSString *)licenceKey
                      videoSize:(CGSize)size
                            fps:(int)fps
                     resultFail:(void (^)(NSError *error))resultFailBlock;

- (instancetype) initWithAPPKey:(NSString *)appkey
                      APPSecret:(NSString *)appsecret
                      videoSize:(CGSize)size
                            fps:(int)fps
                     resultFail:(void (^)(NSError *error))resultFailBlock;

/*  获取sdk当前版本号
 *  @abstract   Get the current version number.
 */
- (int)getSDKVersion;
+ (int)getSDKVersion;

/**添加场景
 *  @abstract   Add scenes.
 */
- (void) setScenes:(NSMutableArray <Scene *>*) scenes;

/**获取场景
 *  @abstract   Add scenes.
 */
- (NSMutableArray <Scene *>*) getScenes;

- (NSMutableArray <MusicInfo *>*) getMusics;
- (NSMutableArray <MusicInfo *>*) getDubbingMusics;
/**添加音乐
 *  @abstract   Add musics.
 */
- (void) setMusics:(NSMutableArray<MusicInfo*> *)musics;

/**添加配音
 *  @abstract   Add dubbings.
 */
- (void) setDubbingMusics:(NSMutableArray<MusicInfo*> *) musics;

/**设置一个辅助预览视图
 *  @abstract   Set a secondary preview view.
 */
- (UIView*) auxViewWithCGRect:(CGRect) rect;

/**设置滤镜特效
 *  @abstract   Set filter effects.
 */
- (void) setDyFilters:(NSMutableArray <FilterAttribute *>*)filterAttributes DEPRECATED_MSG_ATTRIBUTE("Use customFilterArray instead.");

/**添加滤镜特效
 *  @abstract   Add filter effect.
 */
- (void) addDyFilter:(VideoRealTimeFilterType) filterType DEPRECATED_MSG_ATTRIBUTE("Use customFilterArray instead.");

/**移除在某个时间点的某一个滤镜特效
 *  @abstract   Remove filter effect.
 *  @param      index       The index of the filter effect to be removed.
 *  @param      currentTime The current time of the filter effect to be removed.
 */
- (void) removeDyFilterAttribute:(NSInteger)index atTime:(CMTime) currentTime DEPRECATED_MSG_ATTRIBUTE("Use customFilterArray instead.");

/**移除滤镜特效
 *  @abstract   Remove all filter effects.
 */
- (void) removeAllDyFilterAttributes DEPRECATED_MSG_ATTRIBUTE("Use customFilterArray instead.");

/**刷新滤镜特效
 *  @abstract   Refresh filter effects.
 */
- (void) filterRefresh:(CMTime) currentTime;

/**刷新当前帧
*/
- (void)refreshCurrentFrame;

/**添加所有滤镜
 *  @abstract   Add all filters
 */
- (void) addGlobalFilters:(NSMutableArray <Filter *>*)filters DEPRECATED_MSG_ATTRIBUTE("Use setFilter instead.");
/**设置滤镜
 *  @abstract   Set filter.
 */
- (void) setGlobalFilter:(NSInteger) index DEPRECATED_MSG_ATTRIBUTE("Use setFilter instead.");

/**设置当前滤镜强度
 *  @abstract   Set current filter strength.
 */
- (void) setGlobalFilterIntensity:(float)intensity DEPRECATED_MSG_ATTRIBUTE("Use setFilter instead.");

/** 设置滤镜，作用于整个虚拟视频
*/
- (void) setFilter:(Filter *)filter;

/**添加MV,需在build之前添加
 *  @abstract   Add MV, you need to add before build.
 */
- (void) addMVEffect:(NSMutableArray<MovieEffect*> *)mveffects;

/**添加AE MV,需在build之前添加
 *  @abstract   Add MV made by AE, you need to add before build.
 */
- (void) setAeJsonMVEffects:(NSMutableArray <JsonAnimation *> *)jsonMVEffects;

/** 设置json动画,不需要build
 *  @abstract   Set AE generated animation, no need to build.
 */
- (void) setJsonAnimation:(JsonAnimation *)jsonAnimation;

/** 改变AEjson动画中一个文字的时间
 *  仅对json中都是可变文字的有效
 *  @abstract   Change the time of a text in an AE animation.
 *  @discussion Only valid for mutable text in animation.
 */
- (void) setAETextStartTime:(float)startTime duration:(float)duration identifier:(NSString*) identifier;

/** 改变AEjson动画中一个文字的显示内容
 *  仅对json中都是可变文字的有效
 *  @abstract   Change the content of a text in an AE animation.
 *  @discussion Only valid for mutable text in animation.
 */
- (void) setAETextContent:(JsonAnimationText *)contentText;

/** 获取AE生成的动画json文件中，视频/图片信息
 *  @abstract   Get video/picture information in an json file generated by AE.
 */
- (NSArray <JsonAnimationMediaInfo *>*)getAESourceInfoWithJosnPath:(NSString *)jsonPath;
- (NSArray <JsonAnimationMediaInfo *>*)getAESourceInfoWithJosnDic:(NSDictionary *)jsonDic;

/**添加涂鸦
 *  @abstract   Add doodles.
 */
- (void)addDoodles:(NSMutableArray <Doodle *>*)doodles;

/**添加图片水印
 *  @param image    水印图片
 *  @param point    水印在视频中相对于左上角的位置(值为：0.0~1.0)
 *  @param scale    水印的缩放比例，默认为1(图片的原始大小)
 */
- (void) addWaterMark:(UIImage *)image withPoint:(CGPoint)point scale:(CGFloat)scale DEPRECATED_MSG_ATTRIBUTE("Use logoOverlay instead.");

/**添加文字水印
 *  @param waterText    水印文字
 *  @param waterColor   水印文字的颜色
 *  @param waterFont    水印文字的字体
 *  @param point        水印在视频中相对于左上角的位置(值为：0.0~1.0)
 */
- (void) addWaterMark:(NSString *)waterText color:(UIColor *)waterColor font:(UIFont *)waterFont withPoint:(CGPoint)point DEPRECATED_MSG_ATTRIBUTE("Use logoOverlay instead.");

/**移除水印
 */
- (void)removeWaterMark DEPRECATED_MSG_ATTRIBUTE("Use logoOverlay instead.");

/** 实时改变视频／配乐 音量
 @abstract  Change video/music sound in real time.
 */
- (void) setVolume:(float) volume identifier:(NSString*) identifier;

/** 实时改变视频／配乐 音调,audioFilterType为AudioFilterTypeCustom时生效
 *  大于0.0,原音为1.0
 @abstract  Change video/music sound in real time, effective when audioFilterType is AudioFilterTypeCustom.
            More than 0.0, the original sound is 1.0.
 */
- (void) setPitch:(float)pitch identifier:(NSString*) identifier;

/* 设置音效，实时生效
 * 返回当前音效默认的音调pitch值
 @abstract  Set the sound effect, take effect in real time.
 @result    The default pitch value of the current sound effect.
 */
- (float)setAudioFilter:(AudioFilterType)type identifier:(NSString *)identifier;

/** 改变均衡器参数
 */
- (void)setEq:(NSMutableArray <EqObject*> *) eq identifier:(NSString *)identifier;

/** 改变去噪级别 
 */
- (void)setDenoiseLevel:(float)level identifier:(NSString *)identifier;

/** 播放器静音
 @abstract  Player mute.
 */
- (void)playerMute:(BOOL)mute;

/**添加片尾LOGO
    @abstract  Add end of the logo.
 *  @param logoImage    LOGO图片
 *  @param userName     用户名
 *  @param showDuration 展示时长
 *  @param fadeDuration 淡入时长
 */
- (void) addEndLogoMark:(UIImage *)logoImage userName:(NSString *)userName showDuration:(float)showDuration fadeDuration:(float)fadeDuration;

/** 获取片尾LOGO图片
    @abstract   Get the end of the logo picture.
 *  @param logoImage    LOGO图片
 *  @param userName     用户名
 *  @param imageSize    图片大小
 */
- (UIImage *)getEndLogoImage:(UIImage *)logoImage userName:(NSString *)userName imageSize:(CGSize)imageSize;

/**移除片尾LOGO
    @abstract   Remove the end of the logo.
 */
- (void)removeEndLogoMark;

/** 添加片尾媒体，仅导出时有效
 *  @param media 片尾资源
 *  @param isChangeTimeline 是否改变虚拟视频时间线
 */
- (void)setEndingMedia:(MediaAsset *)media isChangeTimeline:(BOOL)isChangeTimeline;

/**构建虚拟视频 用于播放和导出，build后自动seek到当前帧
    @abstract   Build virtual video for playback and export.
 */
- (void) build;

/**暂停播放
 @abstract  Pauses playback.
 */
- (void) pause;

/**开始播放
 @abstract  Begin playback.
 */
- (void) play;

- (void) reversePlay;

/**停止播放，清空播放器，如需再次播放或导出，须调用prepare
 @abstract      Stop playing.
 @discussion    clear the player, if you want to play or export again, you must call prepare.
 */
- (void) stop;

/** @abstract   Build player.
 */
- (void) prepare;

/**seek到某一个时间点
 @abstract      Moves the playback cursor.
 @discussion    The time seeked to may differ from the specified time for efficiency.
 */
- (void) seekToTime:(CMTime)time;

/**seek到某一个时间点
 @abstract      Moves the playback cursor.
 @discussion    The time seeked to will be within the range [time-tolerance, time+tolerance] and may differ from the specified time for efficiency.
 */
- (void) seekToTime:(CMTime)time toleranceTime:(CMTime) tolerance completionHandler:(void (^)(BOOL finished))completionHandler;

/**获取某一个素材的开始时间
 @abstract  Get the start time of a piece of material.
 */
- (CMTimeRange) passThroughTimeRangeAtIndex:(NSInteger) index;

/**获取某一个转场的开始时间
 @abstract  Get the start time of a transition
 */
- (CMTimeRange) transitionTimeRangeAtIndex:(NSInteger) index;

/**获取当前时间点的缩略图
@abstract  Returns a CFRetained CGImageRef for an asset at current time.
*/
- (CGImageRef)copyCurrentCGImage;

/*!
    @method            copyCGImageAtTime:actualTime:error:
    @abstract        Returns a CFRetained CGImageRef for an asset at or near the specified time.
    @param            requestedTime
                    The time at which the image of the asset is to be created.
    @param            actualTime
                    A pointer to a CMTime to receive the time at which the image was actually generated. If you are not interested
                    in this information, pass NULL.
    @param          maximumSize
                    Specifies the maximum dimensions for generated image.  Default (CGSizeZero) is the virtual video's dimensions.
    @param            outError
                    An error object describing the reason for failure, in the event that this method returns NULL.
    @result            A CGImageRef.
    @discussion        Returns the CGImage synchronously. Ownership follows the Create Rule.
*/
- (CGImageRef)copyCGImageAtTime:(CMTime)requestedTime actualTime:(CMTime *)actualTime maximumSize:(CGSize)maximumSize error:(NSError **)outError;

/*!
    @method            generateCGImagesAsynchronouslyForTimes:completionHandler:
    @abstract        Returns a series of CGImageRefs for an asset at or near the specified times.
    @param            requestedTimes
                    An NSArray of NSValues, each containing a CMTime, specifying the asset times at which an image is requested.
    @param          maximumSize
                    Specifies the maximum dimensions for generated image.  Default (CGSizeZero) is the virtual video's dimensions.
    @param            handler
                    A block that will be called when an image request is complete.
    @discussion        Employs an efficient "batch mode" for getting images in time order.
                    The client will receive exactly one handler callback for each requested time in requestedTimes.
                    Changes to generator properties (snap behavior, maximum size, etc...) will not affect outstanding asynchronous image generation requests.
                    The generated image is not retained.  Clients should retain the image if they wish it to persist after the completion handler returns.
*/
- (void)generateCGImagesAsynchronouslyForTimes:(NSArray<NSValue *> *)requestedTimes maximumSize:(CGSize)maximumSize completionHandler:(AVAssetImageGeneratorCompletionHandler)handler;

/*!
    @method            cancelAllCGImageGeneration
    @abstract        Cancels all outstanding image generation requests.
    @discussion        Calls the handler block with AVAssetImageGeneratorCancelled for each image time in every previous invocation of -generateCGImagesAsynchronouslyForTimes:completionHandler:
                    for which images have not yet been supplied.
*/
- (void)cancelAllCGImageGeneration;

/**获取某个时间点的缩略图，包含视频及MV、字幕、贴纸等
 @abstract  Returns a thumbnail of the specified time, including videos and MVs, subtitles, stickers, etc.
 *param: outputTime     获取缩略图的时间点
 *param: scale          与原始尺寸的缩放比例
 */
- (void)getImageWithTime:(CMTime) outputTime
                   scale:(float) scale
       completionHandler:(void (^)(UIImage* image))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use copyCGImageAtTime:actualTime:maximumSize:error: instead.");

/**获取某个时间点的缩略图，包含视频及MV、字幕、贴纸等
 @abstract  Returns thumbnails of the specified times, including videos and MVs, subtitles, stickers, etc.
 *param: outputTimes    获取缩略图的时间点(CMTime)数组
 *param: scale          与原始尺寸的缩放比例
 */
- (void)getImageWithTimes:(NSMutableArray *) outputTimes
                    scale:(float) scale
        completionHandler:(void (^)(UIImage* image, NSInteger idx))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use generateCGImagesAsynchronouslyForTimes:maximumSize:completionHandler: instead.");

/**取消获取缩略图
 @abstract  Cancels all outstanding image generation requests.
 */
- (void)cancelImage DEPRECATED_MSG_ATTRIBUTE("Use cancelAllCGImageGeneration instead.");

/**获取某个时间点的缩略图，只包含视频及MV，不包含字幕、贴纸等
 @abstract  Returns a thumbnail of the specified time, including only videos and MVs, no subtitles, stickers, etc.
 *param: outputTime     获取缩略图的时间点
 *param: scale          与原始尺寸的缩放比例
 */
- (UIImage*)getImageAtTime:(CMTime) outputTime
                     scale:(float) scale DEPRECATED_MSG_ATTRIBUTE("Use copyCGImageAtTime:actualTime:maximumSize:error: instead.");
- (void)getImageAtTime:(CMTime) outputTime
                 scale:(float) scale
            completion:(void (^)(UIImage *image))completionHandler DEPRECATED_MSG_ATTRIBUTE("Use copyCGImageAtTime:actualTime:maximumSize:error: instead.");

/**获取当前时间点的缩略图
 @abstract  Returns a thumbnail of the current time.
 *param: scale          与原始尺寸的缩放比例
 */
- (UIImage *)getCurrentFrameWithScale:(float) scale DEPRECATED_MSG_ATTRIBUTE("Use copyCurrentCGImage instead.");

/** @abstract Set the authored size of the virtual video.
 */
- (void) setEditorVideoSize:(CGSize) videoSize;

/**获取预览视频的分辨率
*  @abstract    Get the authored size of the virtual video.
*/
- (CGSize) getEditorVideoSize;

- (int)getFps;

/** 设置视频背景色，默认为黑色
 @abstract  Set the video background color, the default is black.
 *params: red        红色(0.0~1.0)
 *params: green      绿色(0.0~1.0)
 *params: blue       蓝色(0.0~1.0)
 *params: alpha      透明通道(0.0~1.0)
 */
- (void)setBackGroundColorWithRed:(float)red
                            Green:(float)green
                             Blue:(float)blue
                            Alpha:(float)alpha;

/** 实时改变场景的背景色
 @abstract  Change the background color of the scene in real time.
 */
- (void) setSceneBgColor:(UIColor *)bgColor identifier:(NSString*) identifier;

-(NSMutableData *)getPushAudioData;

-(CMSampleBufferRef)getAudioData;

-(BOOL)getAudioMix;

-(BOOL)inputAudioMIC:( NSMutableData * ) audioData;

/**获取视频的音频码率
 @abstract  Returns the audio bitrate of the video.
 */
+ (float)getAudioBitRate:(NSURL *)url;

/** 获取视频的元信息
 @abstract  Provides access to an array of AVMetadataItems for all metadata identifiers for which a value is available.
 */
+ (NSArray<AVMetadataItem*>*) assetMetadata:(NSURL*)url;

/** 导出视频
    @abstract   Export video.
 *params: movieURL     输出路径
                       Output path.
 *params: size         分辨率大小
                       Set the size of the exported video.
 *params: bitrate      视频码率(例：设置为5M码率，传值为5)
 *params: fps          视频帧率
 *params: audioBitRate 音频码率(单位：Kbps 默认为128)
 *params: audioChannelNumbers   音频通道数   默认为：1
 *params: maxExportVideoDuration 最大导出时长 默认为0 不限制
 *params: progress     导出进度
 *params: success      完成
 *params: fail         失败
 */
- (void)exportMovieURL:(NSURL*) movieURL
                  size:(CGSize) size
               bitrate:(float)bitrate
                   fps:(int)fps
          audioBitRate:(int)audioBitRate
   audioChannelNumbers:(int)audioChannelNumbers
maxExportVideoDuration:(float)maxExportVideoDuration
              progress:(void(^)(float progress))progress
               success:(void(^)(void))success
                  fail:(void(^)(NSError *error))fail;

/** metadata  设置metadata
 */
- (void)exportMovieURL:(NSURL*) movieURL
                  size:(CGSize) size
               bitrate:(float)bitrate
                   fps:(int)fps
              metadata:(NSArray<AVMetadataItem*>*) metadata
          audioBitRate:(int)audioBitRate
   audioChannelNumbers:(int)audioChannelNumbers
maxExportVideoDuration:(float)maxExportVideoDuration
              progress:(void(^)(float progress))progress
               success:(void(^)(void))success
                  fail:(void(^)(NSError *error))fail;

/** exportVideoCodecType  编码类型
    exportVideoProfileLevelType 画质
 */
- (void)exportMovieURL:(NSURL*) movieURL
                  size:(CGSize) size
               bitrate:(float)bitrate
                   fps:(int)fps
              metadata:(NSArray<AVMetadataItem*>*) metadata
          audioBitRate:(int)audioBitRate
   audioChannelNumbers:(int)audioChannelNumbers
maxExportVideoDuration:(float)maxExportVideoDuration
  exportVideoCodecType:(VEExportVideoCodecType)exportVideoCodecType
exportVideoProfileLevelType:(VEExportVideoProfileLevelType)exportVideoProfileLevelType
              progress:(void(^)(float progress))progress
               success:(void(^)(void))success
                  fail:(void(^)(NSError *error))fail;

- (void)exportVideoUrl:(NSURL *)url
              settings:(VECoreVideoExportSettings *)settings
              progress:(void(^)(float progress))progress
               success:(void(^)(void))success
                  fail:(void(^)(NSError *error))fail;

/** 取消导出
    @abstract   Cancel export.
 */
- (void)cancelExportMovie:(void(^)(void))cancelBlock;

/** 导出音频
 @abstract   Export audio.
 *@params fileType    输出音频类型，目前支持三种（AVFileTypeMPEGLayer3，AVFileTypeAppleM4A，AVFileTypeWAVE）
                             Output audio type, currently supports three.
 */
- (void)exportAudioUrl:(NSURL *)url
          audioBitRate:(int)audioBitRate
   audioChannelNumbers:(int)audioChannelNumbers
              fileType:(AVFileType)fileType
              progress:(void(^)(float progress))progress
               success:(void(^)(void))success
                  fail:(void(^)(NSError *error))fail;

/** 倒序
    @abstract   Reverse.
 *params: url           视频源地址
                        Source video address.
 *params: outputUrl     输出路径
                        Output path.
 *params: timeRange     倒序时间范围
 *params: videoSpeed    视频速度
 *params: progressBlock 倒序进度回调
 *params: finishBlock   结束回调
 *params: failBlock     失败回调
 *params: cancel        是否取消
 */
+ (void)exportReverseVideo:(NSURL *)url
                 outputUrl:(NSURL *)outputUrl
                 timeRange:(CMTimeRange)timeRange
                 audioType:(ReverseAudioType)audioType
                videoSpeed:(float)speed
             progressBlock:(void (^)(NSNumber *prencent))progressBlock
             callbackBlock:(void (^)(void))finishBlock
                      fail:(void (^)(NSError *error))failBlock
                    cancel:(BOOL *)cancel;

+ (void)extractFramesFromVideo:(NSURL *)url
                     outputUrl:(NSURL *)outputUrl
                     timeRange:(CMTimeRange)timeRange
                 frameDuration:(CMTime)frameDuration
                 progressBlock:(void (^)(float progress))progressBlock
                 callbackBlock:(void (^)(void))finishBlock
                          fail:(void (^)(NSError *error))failBlock
                        cancel:(BOOL *)cancel;

/** 从视频中提取音频
    @abstract   Extract audio from the video.
 *params: type                  输出音频类型，目前支持三种（AVFileTypeMPEGLayer3，AVFileTypeAppleM4A，AVFileTypeWAVE）
                                Output audio type, currently supports three.
 *params: videoUrl              视频源地址
                                Source video address.
 *params: trimStart             从原始视频截取的开始时间 单位：秒 默认 0
 *params: duration              截取的持续时间 默认视频原始时长
 *params: outputFolder          输出文件存放的文件夹路径
                                Folder path where the output file is stored.
 *params: samplerate            输出采样率
 *params: completionHandle      导出回调
 */
+ (void)video2audiowithtype:(AVFileType)type
                   videoUrl:(NSURL*)videoUrl
                  trimStart:(float)start
                   duration:(float)duration
           outputFolderPath:(NSString*)outputFolder
                 samplerate:(int )samplerate
                 completion:(void(^)(BOOL result,NSString*outputFilePath))completionHandle;

+ (void)video2audiowithtype:(AVFileType)type
                   videoUrl:(NSURL*)videoUrl
                  trimStart:(float)start
                   duration:(float)duration
           outputFolderPath:(NSString*)outputFolder
                 samplerate:(int )samplerate
            progressHandler:(void (^)(float progress))progressHandler
          completionHandler:(void(^)(BOOL result,NSString*outputFilePath))completionHandler;
+ (void)video2audiowithtype:(AVFileType)type
                   videoUrl:(NSURL *)videoUrl
                  trimStart:(float)start
                   duration:(float)duration
           outputFolderPath:(NSString *)outputFolder
                 samplerate:(int)samplerate
               bitrate_kbps:(int)bitrate_kbps
            progressHandler:(void (^)(float progress))progressHandler
          completionHandler:(void (^)(BOOL, NSString *))completionHandler;
/** 判断图片是否是Gif,并返回图片时长
 *  返回0:则非Gif
 @abstract  Determine if the image is Gif.
 @return    The duration of the image.Returns 0, then non-Gif.
 */
+ (float)isGifWithData:(NSData *)imageData;

/** 获取带滤镜的图
 @abstract  Add a filter to the image.
 */
+ (UIImage *)getFilteredImage:(UIImage *)inputImage filter:(Filter *)filter;

/** 获取视频实际时长，去掉片头和片尾的黑帧
@abstract  Get the actual duration of the video, remove the black frame from the beginning and end of the video.
*/
+ (CMTimeRange)getActualTimeRange:(NSURL *)path;

/** Gif 
   @abstract   Gif.
 *params: exportInfo                   视频源地址
 *params: outputPath                  输出路径
                            Output path.
 *params: progressHandle          进度回调
 *params: completionHandler     结束回调
 *params: failedHandler              失败回调
 *params: cancel                         是否取消
*/
+ (void)exportGifWithInfo:(GifExportInfo *)exportInfo
               outputPath:(NSString *)outputPath
          progressHandler:(void (^)(float progress))progressHandler
        completionHandler:(void (^)(void))completionHandler
            failedHandler:(void (^)(void))failedHandler
                   cancel:(BOOL *)cancel;

/** 导出Json
    @abstract   Export Json.
 *params: movieURL     输出路径
                       Output path.
 *params: size         分辨率大小
                       Set the size of the exported video.
 *params: bitrate      视频码率(例：设置为5M码率，传值为5)
 *params: fps          视频帧率
 *params: audioBitRate 音频码率(单位：Kbps 默认为128)
 *params: audioChannelNumbers   音频通道数   默认为：1
 *params: progress     导出进度
 *params: success      完成
 *params: fail         失败
 
 *版本说明：
 *20200923 0.1只支持导出视频 及 时间参数
 *20210309 0.2支持字幕(暂不支持花字及动画)
 */
- (void)exportJsonWithSize:(CGSize) size
                    bitrate:(float)bitrate
                        fps:(int)fps
               audioBitRate:(int)audioBitRate
        audioChannelNumbers:(int)audioChannelNumbers
                 outputPath:(NSString *)outputPath
            progressHandler:(void (^)(float progress))progressHandler
          completionHandler:(void (^)(NSString *exportPath))completionHandler
              failedHandler:(void (^)(NSError *error))failedHandler
                     cancel:(BOOL *)cancel;

/** 导出模板
@abstract   Export template.
 @param outputPath                  输出路径
 @param size                                        分辨率大小
 @param exportInfo                  导出信息
 @param progressHandler       导出进度
 @param completionHandler   完成
 @param failedHandler            失败
*/
- (void)exportTemplateWithOutputPath:(NSString *)outputPath
                                size:(CGSize)size
                          exportInfo:(TemplateExportInfo *)exportInfo
                     progressHandler:(void (^)(float progress))progressHandler
                   completionHandler:(void (^)(NSString *exportPath, VECoreTemplateInfo *templateInfo))completionHandler
                       failedHandler:(void (^)(NSError *error))failedHandler;

- (void)exportTemplateWithOutputPath:(NSString *)outputPath
                        templateInfo:(VECoreTemplateInfo *)templateInfo
                          exportInfo:(TemplateExportInfo *)exportInfo
                     progressHandler:(void (^)(float))progressHandler
                   completionHandler:(void (^)(NSString *exportPath, VECoreTemplateInfo *templateInfo))completionHandler
                       failedHandler:(void (^)(NSError *))failedHandler;

/** 取消导出模板
@abstract   Cancel export template.
*/
- (void)cancelExportTemplate:(void(^)(void))cancelHandler;
/** 音频数据转mp3文件 （ 采样率为自定义 声道数为2, 任意一段音频数据都可以转为mp3 ）
@abstract   audio data transfer MP3 file
 @param data    音频数据
 @param mp3FilePath    mp3保存路径
 @param sampleRate     音频采样率 ( 声道数固定为2 )
*/
+(void)audio_DataToMP3:( NSMutableData * ) data
         atMP3FilePath:( NSString * ) mp3FilePath
          atSampleRate:(float) sampleRate;

+(void)audio_DataToMP3:( NSMutableData * ) data
         atMP3FilePath:( NSString * ) mp3FilePath
          atSampleRate:(float) sampleRate
       progressHandler:(void (^)(float progress))progressHandler;

+(void)audio_DataToMP3:( NSMutableData * ) data
         atMP3FilePath:( NSString * ) mp3FilePath
          atSampleRate:(float) sampleRate
               atBrate:( NSInteger ) brate
            atChannels:( NSInteger ) channels;

/** caf文件转mp3文件 （ 采样率为11025 声道数为2 ） 注意：MIC录制为caf文件转mp3专用
@abstract   CAF file transfer MP3 file
 @param cafFilePath    caf文件路径
 @param mp3FilePath    mp3保存路径
 @param voiceChanger   变声
 @param noise          降噪
 @param volume         音量0~100；50为正常音量
 @param sampleRate     音频采样率
*/
+(void)audio_CafToMP3:( NSString * ) cafFilePath atMP3FilePath:( NSString * ) mp3FilePath atVoiceChanger:(NSInteger) voiceChanger atNoise:(NSInteger) noise atVolume:(NSInteger) volume  atSampleRate:(float) sampleRate DEPRECATED_MSG_ATTRIBUTE("Use audio_DataToMP3:atMP3FilePath:atSampleRate: instead.");
/** m4a文件转mp3文件
@abstract   CAF file transfer MP3 file
 @param m4aFilePath    m4a文件路径
 @param mp3FilePath    mp3保存路径
*/
+(void)audio_M4aToMP3:( NSString * ) m4aFilePath atMP3FilePath:( NSString * ) mp3FilePath atSampleRate:(float) sampleRate  FinishBlock:(void (^)(bool isFinish)) FinishBlock;

+(void)audio_M4aToMP3:( NSString * ) m4aFilePath
        atMP3FilePath:( NSString * ) mp3FilePath
         atSampleRate:(float) sampleRate
      progressHandler:(void (^)(float progress))progressHandler
    completionHandler:(void (^)(bool isFinished)) completionHandler;

/** 获取消除后的图像 （消除笔）
 @abstract  Obtain the erased image (elimination pen)
 @param originalImage    原始图像
 @param grayscaleImage    灰度图(需要擦除的地方)
 */
-(void)getImageWithDeLogoProcess:( UIImage * ) originalImage atGrayscaleImage:( UIImage * ) grayscaleImage  atFailBlock:(void(^)(UIImage * image))failBlock;
/** 获取消除后的图像 （消除笔）同步擦除
 */
-(UIImage*)getImageWithDeLogoSynchronizeProcess:( UIImage * ) originalImage atGrayscaleImage:( UIImage * ) grayscaleImage;

/** 获取消除后的图像 （消除笔）
 @abstract  Obtain the erased image (elimination pen)
 @param originalImage    原始图像
 @param grayscaleBuffer    灰度图(需要擦除的地方)
 */
-(void)getImageWithDeLogoProcess:( UIImage * ) originalImage atGrayscaleBuffer:( CVPixelBufferRef  ) grayscaleBuffer atFailBlock:(void(^)(UIImage * image))failBlock;


/** 暗通道去雾   （去雾）
 @abstract  Realizing Single Image Haze Removal Using Dark Channel Prior
 @param originalImage    原始图像
 */
-(void)getImageWithDehazeProcess:( UIImage * ) originalImage atFailBlock:(void(^)(UIImage * image))failBlock;


-(BOOL)getSdkDisabled;

+(UIImage *)getImageFromPath:( NSURL * ) path;

+(bool)getMusicBeatIsAvailable:( NSString * ) musicPath;

/**  获取HDR图片
 *  @abstract Get HDR pictures.
 *
 *  @param originalImage        原图
 *  @param outPutFilePath     输出图片路径
 *
 *  成功返回 YES，失败返回 NO；
 */
- (BOOL)getHDRImageFromImage:(UIImage *)originalImage outPutFilePath:(NSString*)outPutFilePath;

/**  音频数据转码
 *  @abstract Audio data transcoding
 *
 *  @param data        音频数据
 *  @param originalSamepleRate     原始采样数
 *  @param originalSampleBit        原始采样位数 （ VEAudioSampleBits ）
 *  @param originalChannels     原始通道数
 *  @param outSamepleRate     输出采样数   （ VEAudioSampleBits ）
 *  @param outSampleBit        输出采样位数
 *  @param outChannels     输出通道数
 *
 *  转换后的音频数据
 */
+( NSMutableData * )audioTranscod:( NSMutableData * ) data atOriginalSamepleRate:( Float64 ) originalSamepleRate atOriginalSampleBit:( VEAudioSampleBits ) originalSampleBit atOriginalChannels:( int ) originalChannels   atOutSamepleRate:( Float64 ) outSamepleRate atOutSampleBit:( VEAudioSampleBits ) outSampleBit atOutChannels:( int ) outChannels;
/**  音频混音
 *  @abstract audio mixing
 *
 *  @param bufferArray        音频数据组( 元素结构为 NSData * )
 *  @param sampleBit     采样位数
 *
 *  转换后的音频数据
 */
+(NSMutableData *)audioRemixWithBufferArray:( NSMutableArray * ) bufferArray atSampleBit:( VEAudioSampleBits ) sampleBit;

#pragma mark- 虚拟直播间 音频处理
- (void)willOutputAudioData:(NSMutableData*)audioData;
- (void)willAudioBuffer:(CMSampleBufferRef)audioBuffer  asset:(MediaAsset*)asset  finish:(BOOL)finish;
#pragma mark- 音频单独播放
- (void)willOutputAudioData:(NSMutableData*)audioData sampleRate:(int)sampleRate bitsPerChannel:(int)bitsPerChannel channels:(int)channels asset:(MediaAsset*)asset finish:(BOOL)finish;

/** 仅当 isAlwaysPlay 为YES时有效
 */
- (void)deleteOverlay:(Overlay*)overlay;
- (void)replaceOverlay:(Overlay *)overlay withNewOverlay:(Overlay *)newOverlay API_DEPRECATED("No longer supported. ", ios(9.0, 9.0));
- (void)deleteMediaAsset:(MediaAsset*)media;

/** 仅当 isAlwaysPlay 为YES时有效
 */
- (void)deleteMusic:(MusicInfo*)music;

//是否启用层级调整 （ true为是 ）
+(void)setIsEnableAdjustmentHierarchical:(BOOL)enableAdjustmentHierarchical;

+(UIImage *)rotateImage:( UIImage * ) image atPitch:( float ) pitch atYaw:( float ) yaw atRoll:( float ) rolll  atCenter:( CGPoint ) center;
+(UIImage *)perspectiveTransform:( UIImage * ) image atArray:( NSMutableArray * ) array;

//获取webm媒体信息
+(WebmMediaInfo*)getWebmInfo:(NSString*)webmFile;
//提取webm音频数据编码为mp3文件
+(BOOL)getMP3FileFromWebmFilePath:(NSString*)webmFile outputMP3File:(NSString*)mp3File;
//提取webm缩略图 (时间单位：秒)
+(UIImage*)getImageFromWebmFilePath:(NSString*)webmFile time:(float)time scale:(float)scale;
//提取webm指定时间段数据 (时间单位：秒)
+(void)getWebmDataFromFilePath:(NSString*)webmFile timeRange:(CMTimeRange)timeRange completion:(void (^)(NSMutableArray<WebmDecodeData*>*))completion;

//获取 AI Token
+(NSString *)getToken_AI:( NSString * ) appkey;
/**  私有云TTS ( 文字转语音 )
 *  @abstract Private Cloud TTS (text-to-Speech)
 *
 *  @param locale        语言
 *  @param shortName     人物角色
 *  @param synthesisText  文字
 *  @param filePath  音频文件地址
 *  @param isOnlyReturnAudioPath  是否只返回音频文件地址
 *  获取mp3音频文件地址 或者 NSMutableArray
 */
+(id)getTTSATWithLocale:( NSString * ) locale atShortName:( NSString * ) shortName atText:( NSString * ) synthesisText atFilePath:( NSString * ) filePath isOnlyReturnAudioPath:(BOOL)isOnlyReturnAudioPath;


/**  设置需要被追踪区域
 *  @abstract Set the area that needs to be tracked
 *
 *  @param pixel        需要被追踪区域的画面
 *  @param trackRect     需要被追踪区域（左上角为（0，0），右下角为（1.0，1.0））
 */
-(bool)startTrackWithPixelBufferRef:(CVPixelBufferRef)pixel trackRect:(CGRect)trackRect;


/**  追踪
 *  @abstract tracking
 *
 *  @param pixel        输入画面
 *
 *  返回追踪结果（左上角为（0，0），右下角为（1.0，1.0）），追踪失败返回（0，0，0，0）
 */
-(CGRect)trackWithCVPixelBufferRef:(CVPixelBufferRef)pixel;


/**  结束追踪，释放资源
 *  @abstract End tracking and release resources
 *
 */
-(bool)endTrack;

//草稿进入时 不需要
+(void)RecountLevel;

-(void)segmentation_ImageWithImageData:( NSMutableData * ) imageData atView:( UIView * ) view   atCancelBtn:( UIButton * ) cancelBtn atIsDebug:( BOOL ) isDebug  atCompletionHandler:( void(^)( NSString * message, id messageBody ) )  segmentationCompletionHandler;

/*@abstract  去水印  de-watermarking.
 @param imageData                  图像数据
 @param grayScaleImageData    灰度图数据
 @param view                            需要依附的控件 ( 必须传 )
 @param segmentationCompletionHandler  返回参数  （  message == @"DeWatermarkImage" 表示messageBody 为 去水印后的图像数据  ）
 */
-(void)deWatermark_ImageWithImageData:( NSMutableData * ) imageData atGrayScaleImageData:( NSMutableData * ) grayScaleImageData atView:( UIView * ) view  atCancelBtn:( UIButton * ) cancelBtn  atIsDebug:( BOOL ) isDebug  atCompletionHandler:( void(^)( NSString * message, id messageBody ) ) deWatermarkCompletionHandler;

-(void)superResolution_ImageWithImageData:( NSMutableData * ) imageData atView:( UIView * ) view atCancelBtn:( UIButton * ) cancelBtn   atIsDebug:( BOOL ) isDebug  atCompletionHandler:( void(^)( NSString * message, id messageBody ) ) superResolutionCompletionHandler;
@end
