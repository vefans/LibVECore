//
//  PECore.h
//  PECore
//
//  Created by iOS SDK Team on 2021/11/8.
//  Copyright © 2021年 iOS SDK Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <LibVECore/PEAssetManager.h>
#import <LibVECore/Common.h>
#import <LibVECore/PECoreTemplateInfo.h>

@class PECore;
@class FaceRecognition;


typedef NS_ENUM(NSInteger, PECoreStatus) {
    kPECoreStatusUnknown,
    kPECoreStatusWillChangeImage,
    kPECoreStatusReady,
    kPECoreStatusFailed
};

@protocol PECoreDelegate<NSObject> 

@optional

- (void)statusChanged:(PECore *)sender status:(PECoreStatus)status;


- (NSArray<FaceRecognition*>*)willOutputPixelBuffer:(CVPixelBufferRef)pixelBuffer asset:(PEImageAsset*)asset;

- (void)willOutputPixelBuffer:(CVPixelBufferRef)pixelBuffer currentTime:(CMTime)currentTime;

@end



typedef NS_ENUM(NSUInteger, PECoreViewFillMode) {
    kPECoreViewFillModeStretch,
    kPECoreViewFillModeScaleAspectFit,
    kPECoreViewFillModeScaleAspectFill
};

@interface PECore : NSObject<NSCopying,NSMutableCopying>


/** 当前状态
 */
@property (nonatomic, readonly) PECoreStatus status;


/** 指定图片视图位置
 */
@property (nonatomic,assign) CGRect frame;

/** 图片视图
 */
@property (nonatomic,readonly) UIView* view;

/** 图片视图显示方式。默认kPECoreViewFillModeScaleAspectFit
 */
@property (nonatomic,assign) PECoreViewFillMode fillMode;

/** 预览或者导出支持的最大分辨率
 */
@property (nonatomic,readonly) CGSize supportMaxSize;

/** 字幕
 */
@property (nonatomic, strong) NSMutableArray<Caption*>* captions;

/** 字幕
 */
@property (nonatomic, strong) NSMutableArray<CaptionEx*>* captionExs;


/** 高斯模糊
*/
@property (nonatomic, strong) NSMutableArray<MediaAssetBlur*>* blurs;

/** 马赛克
*/
@property (nonatomic, strong) NSMutableArray<Mosaic*>* mosaics;

/** 去水印
 */
@property (nonatomic, strong) NSMutableArray<Dewatermark*>* dewatermarks;


/** 自定义滤镜
 */
@property (nonatomic, strong) NSMutableArray <CustomFilter*>* customFilterArray;


/**设置媒体自定义多滤镜数组，一个滤镜可以由多个滤镜组合而成。
 */
@property (nonatomic, strong) NSMutableArray <CustomMultipleFilter*>* customMultipleFilterArray;


/** 水印，支持图片
 *  适用于整体添加多个水印的情况，可用于涂层、涂鸦等
 */
@property (nonatomic, strong) NSMutableArray <PEOverlay*>* overlayArray;

/** 水印，支持图片
 *  可用于图片/文字水印
 */
@property (nonatomic, strong) PEOverlay *logoOverlay;

/** 调色
*/
@property (nonatomic, strong) NSMutableArray <ToningInfo*>* adjustmentsArray;


/** 粒子
*/
@property (nonatomic, strong) NSMutableArray <Particle*>* particlesArray;

/** 涂鸦笔
*/
@property (nonatomic, strong) NSMutableArray <DoodleEx *>* doodleArray;

/** 代理
*/
@property (nonatomic,weak) id<PECoreDelegate> delegate;


/**  初始化对象
 *  @abstract  Returns an instance of PECore for reading media data.
 *
 *  @param appkey           在官网中注册的应用Key。
                            Application Key registered in the SDK official website.
 *
 *  @param appsecret        在官网(中注册的应用秘钥。
                            Application secret key registered in the SDK official website.
 *
 *  @param licenceKey       在官网(中注册的licenceKey。
                            The licenseKey registered in the SDK official website.
 
 *  @param  size            图片分辨率
                            Indicates the authored size of the Image of the asset.
 
 
 *  @param resultFailBlock  初始化失败的回调［error：初始化失败的错误码］
                            A block that will be called when initialization is failed.
 */
- (instancetype) initWithAPPKey:(NSString *)appkey
                      APPSecret:(NSString *)appsecret
                     LicenceKey:(NSString *)licenceKey
                           size:(CGSize)size
                     resultFail:(void (^)(NSError *error))resultFailBlock;

- (instancetype) initWithAPPKey:(NSString *)appkey
                      APPSecret:(NSString *)appsecret
                           size:(CGSize)size
                     resultFail:(void (^)(NSError *error))resultFailBlock;

/*  获取sdk当前版本号
 *  @abstract   Get the current version number.
 */
- (int)getPESDKVersion;
+ (int)getPESDKVersion;

/**添加媒体管理器
 *  @abstract   Add asset manager.
 */
- (void) setAssetManager:(NSMutableArray <PEAssetManager *>*) assetManagers;

/**获取媒体管理器
 *  @abstract   Get asset manager.
 */
- (NSMutableArray <PEAssetManager *>*) getAssetManagers;


/**设置一个辅助预览视图
 *  @abstract   Set a secondary preview view.
 */
- (UIView*) auxViewWithCGRect:(CGRect) rect;


/**刷新当前帧
*/
- (void)refreshCurrentFrame;

/** 设置滤镜，作用于整个虚拟视频
*/
- (void) setFilter:(Filter *)filter;

/**添加涂鸦
 *  @abstract   Add doodles.
 */
- (void)addDoodles:(NSMutableArray <Doodle *>*)doodles;


/** @abstract   init and build.
 */
- (void) build;

/** @abstract   clear.
 */
-(void)clear;


/**导出图片
@abstract  Returns a CFRetained CGImageRef for an asset .
*/
- (CGImageRef)copyCurrentCGImage;

/*!
    @method         copyCGImageMaximumSize:error:
    @abstract       Returns a CFRetained CGImageRef for an asset .
    @param          maximumSize
                    Specifies the maximum dimensions for generated image.
    @param          outError
                    An error object describing the reason for failure, in the event that this method returns NULL.
    @result            A CGImageRef.
    @discussion        Returns the CGImage synchronously. Ownership follows the Create Rule.
*/
- (CGImageRef)copyCGImageMaximumSize:(CGSize)maximumSize error:(NSError **)outError;


/** @abstract Set the authored size of the image.
 */
- (void) setEditorImageSize:(CGSize) imageSize;

/**获取预览视频的分辨率
*  @abstract    Get the authored size of the image.
*/
- (CGSize) getEditorImageSize;

/** 设置背景色，默认为黑色
 @abstract  Set the background color, the default is black.
 *params: red        红色(0.0~1.0)
 *params: green      绿色(0.0~1.0)
 *params: blue       蓝色(0.0~1.0)
 *params: alpha      透明通道(0.0~1.0)
 */
- (void)setBackGroundColorWithRed:(float)red
                            Green:(float)green
                             Blue:(float)blue
                            Alpha:(float)alpha;


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

/** 获取消除后的图像 （消除笔）
 @abstract  Obtain the erased image (elimination pen)
 @param originalImage    原始图像
 @param grayscaleImage    灰度图(需要擦除的地方)
 */
-(void)getImageWithDeLogoProcess:( UIImage * ) originalImage atGrayscaleImage:( UIImage * ) grayscaleImage  atFailBlock:(void(^)(UIImage * image))failBlock;

/** 暗通道去雾   （去雾）
 @abstract  Realizing Single Image Haze Removal Using Dark Channel Prior
 @param originalImage    原始图像
 */
-(void)getImageWithDehazeProcess:( UIImage * ) originalImage atFailBlock:(void(^)(UIImage * image))failBlock;

/** 导出模板
@abstract   Export template.
 @param outputPath                  输出路径
 @param exportInfo                  导出信息
 @param progressHandler       导出进度
 @param completionHandler   完成
 @param failedHandler            失败
*/
- (void)exportTemplateWithOutputPath:(NSString *)outputPath
                          exportInfo:(TemplateExportInfo *)exportInfo
                     progressHandler:(void (^)(float))progressHandler
                   completionHandler:(void (^)(NSString *exportPath, PECoreTemplateInfo *templateInfo))completionHandler
                       failedHandler:(void (^)(NSError *))failedHandler;

+ (int)getSDKVersion;
-(void)tidyUpLevel:( NSMutableArray * ) array atHighestArray:( NSMutableArray * ) highestArray  atOverlayBackgrounds:( NSMutableArray * ) overlayBackgrounds;
+(void)setEnableAdjustmentHierarchical:( BOOL ) enableAdjustmentHierarchical;

/**  获取HDR图片
 *  @abstract Get HDR pictures.
 *
 *  @param originalImage        原图
 *  @param outPutFilePath     输出图片路径
 *
 *  成功返回 YES，失败返回 NO；
 */
- (BOOL)getHDRImageFromImage:(UIImage *)originalImage outPutFilePath:(NSString*)outPutFilePath;

+(void)setLevelCounti:( NSInteger ) level;
+(NSInteger)getLevelNumber;

/*@abstract  分割图像  Segmenting an image.
 @param imageData                  图像数据
 @param view                            需要依附的控件 ( 必须传 )
 @param segmentationCompletionHandler  返回参数  （  message == @"SegmentationImage" 表示messageBody 为 分割后的图像数据  ）
 */
-(void)segmentation_ImageWithImageData:( NSMutableData * ) imageData atView:( UIView * ) view   atCancelBtn:( UIButton * ) cancelBtn atIsDebug:( BOOL ) isDebug atCompletionHandler:( void(^)( NSString * message, id messageBody ) )  segmentationCompletionHandler;

/*@abstract  去水印  de-watermarking.
 @param imageData                  图像数据
 @param grayScaleImageData    灰度图数据
 @param view                            需要依附的控件 ( 必须传 )
 @param segmentationCompletionHandler  返回参数  （  message == @"DeWatermarkImage" 表示messageBody 为 去水印后的图像数据  ）
 */
-(void)deWatermark_ImageWithImageData:( NSMutableData * ) imageData atGrayScaleImageData:( NSMutableData * ) grayScaleImageData atView:( UIView * ) view atCancelBtn:( UIButton * ) cancelBtn  atIsDebug:( BOOL ) isDebug atCompletionHandler:( void(^)( NSString * message, id messageBody ) ) deWatermarkCompletionHandler;

-(void)superResolution_ImageWithImageData:( NSMutableData * ) imageData atView:( UIView * ) view atCancelBtn:( UIButton * ) cancelBtn  atIsDebug:( BOOL ) isDebug    atCompletionHandler:( void(^)( NSString * message, id messageBody ) ) superResolutionCompletionHandler;

@end
