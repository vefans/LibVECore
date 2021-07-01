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

- (void)statusChanged:(VECore *)sender status:(VECoreStatus)status;

- (void)statusChanged:(VECoreStatus)status;

- (void)progressCurrentTime:(CMTime)currentTime;

- (void)progress:(VECore *)sender currentTime:(CMTime)currentTime;
//可在customDrawLayer上实时添加layer，实现自绘
- (void)progressCurrentTime:(CMTime)currentTime customDrawLayer:(CALayer *)customDrawLayer;

- (void)playToEnd;

- (void)tapPlayerView;

- (NSArray<FaceRecognition*>*)willOutputPixelBuffer:(CVPixelBufferRef)pixelBuffer asset:(MediaAsset*)asset;

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
    VEExportVideoCodecTypeHEVC  API_DEPRECATED_WITH_REPLACEMENT("VEExportVideoCodecTypeHEVC",ios(11.0, 11.0)),
};

typedef NS_ENUM(NSUInteger, VEExportVideoProfileLevelType) {
    VEExportVideoProfileLevelTypeBaseline,
    VEExportVideoProfileLevelTypeMain,
    VEExportVideoProfileLevelTypeHigh,
};

@interface VECore : NSObject<NSCopying,NSMutableCopying>

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

/** 字幕
 */
@property (nonatomic, strong) NSMutableArray<Caption*>* captions;

/** 非矩形字幕
 */
@property (nonatomic, strong) NSMutableArray<CaptionLight*>* nonRectangleCaptions;

/** 贴纸
 */
@property (nonatomic, strong) NSMutableArray<Caption*>* stickers  DEPRECATED_MSG_ATTRIBUTE("Use mosaics instead.");

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

/** 自定义滤镜
 */
@property (nonatomic, strong) NSMutableArray <CustomFilter*>* customFilterArray;

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
       completionHandler:(void (^)(UIImage* image))completionHandler;

/**获取某个时间点的缩略图，包含视频及MV、字幕、贴纸等
 @abstract  Returns thumbnails of the specified times, including videos and MVs, subtitles, stickers, etc.
 *param: outputTimes    获取缩略图的时间点(CMTime)数组
 *param: scale          与原始尺寸的缩放比例
 */
- (void)getImageWithTimes:(NSMutableArray *) outputTimes
                    scale:(float) scale
        completionHandler:(void (^)(UIImage* image, NSInteger idx))completionHandler;

/**取消获取缩略图
 @abstract  Cancels all outstanding image generation requests.
 */
- (void)cancelImage;

/**获取某个时间点的缩略图，只包含视频及MV，不包含字幕、贴纸等
 @abstract  Returns a thumbnail of the specified time, including only videos and MVs, no subtitles, stickers, etc.
 *param: outputTime     获取缩略图的时间点
 *param: scale          与原始尺寸的缩放比例
 */
- (UIImage*)getImageAtTime:(CMTime) outputTime
                     scale:(float) scale;
- (void)getImageAtTime:(CMTime) outputTime
                 scale:(float) scale
            completion:(void (^)(UIImage *image))completionHandler;

/**获取当前时间点的缩略图
 @abstract  Returns a thumbnail of the current time.
 *param: scale          与原始尺寸的缩放比例
 */
- (UIImage *)getCurrentFrameWithScale:(float) scale;

/** @abstract Set the authored size of the virtual video.
 */
- (void) setEditorVideoSize:(CGSize) videoSize;

/**获取预览视频的分辨率
*  @abstract    Get the authored size of the virtual video.
*/
- (CGSize) getEditorVideoSize;

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
/** 取消导出
    @abstract   Cancel export.
 */
- (void)cancelExportMovie:(void(^)(void))cancelBlock;

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
 @param isExportPreviewVideo    是否导出预览视频
 @param previewVideoBitrate      视频码率(例：设置为5M码率，传值为5)
 @param size                                        分辨率大小
 @param previewVideoFps          视频帧率
 @param previewVideoAudioBitRate 音频码率(单位：Kbps 默认为128)
 @param previewVideoAudioChannelNumbers   音频通道数   默认为：1
 @param previewVideoMaxExportDuration 最大导出时长 默认为0 不限制
 @param outputPath                  输出路径
           Output path.
 @param progressHandler       导出进度
 @param completionHandler   完成
 @param failedHandler            失败
*/
- (void)exportTemplateWithOutputPath:(NSString *)outputPath
                                size:(CGSize)size
                      isHasFragments:(BOOL)isHasFragments
                isExportPreviewVideo:(BOOL)isExportPreviewVideo
                 previewVideoBitrate:(float)previewVideoBitrate
                     previewVideoFps:(int)previewVideoFps
            previewVideoAudioBitRate:(int)previewVideoAudioBitRate
     previewVideoAudioChannelNumbers:(int)previewVideoAudioChannelNumbers
       previewVideoMaxExportDuration:(float)previewVideoMaxExportDuration
                previewVideoMetadata:(NSArray<AVMetadataItem*>*)previewVideoMetadata
                     progressHandler:(void (^)(float progress))progressHandler
                   completionHandler:(void (^)(NSString *exportPath, VECoreTemplateInfo *templateInfo))completionHandler
                       failedHandler:(void (^)(NSError *error))failedHandler;

/** 取消导出模板
@abstract   Cancel export template.
*/
- (void)cancelExportTemplate:(void(^)(void))cancelHandler;

/** caf文件转mp3文件 （ 采样率为11025 省道数为2 ） 注意：MIC录制为caf文件转mp3专用
@abstract   CAF file transfer MP3 file
 @param cafFilePath    caf文件路径
 @param mp3FilePath    mp3保存路径
 @param voiceChanger   变声
 @param noise          降噪
 @param volume         音量
 @param sampleRate     音频采样率
*/
+(void)audio_CafToMP3:( NSString * ) cafFilePath atMP3FilePath:( NSString * ) mp3FilePath atVoiceChanger:(NSInteger) voiceChanger atNoise:(NSInteger) noise atVolume:(NSInteger) volume  atSampleRate:(float) sampleRate;
/** m4a文件转mp3文件
@abstract   CAF file transfer MP3 file
 @param m4aFilePath    m4a文件路径
 @param mp3FilePath    mp3保存路径
*/
+(void)audio_M4aToMP3:( NSString * ) m4aFilePath atMP3FilePath:( NSString * ) mp3FilePath atSampleRate:(float) sampleRate  FinishBlock:(void (^)(bool isFinish)) FinishBlock;
@end
