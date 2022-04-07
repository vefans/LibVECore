//
//  PEAssetManager.h
//  PECore
//
//  Created by iOS SDK Team on 2021/8/11.
//  Copyright © 2021年 iOS SDK Team. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <LibVECore/CustomFilter.h>
#import <LibVECore/MaskObject.h>
#import <LibVECore/Common.h>
#import <LibVECore/CameraManager.h>



@class PEImageAsset;
@class FaceAttribute;


@interface PEAssetManager : NSObject

/** 标识符
 */
@property (nonatomic,strong) NSString *identifier;

/** 是否是默认场景
 *  导出模板用
 */
@property (nonatomic, assign) BOOL isDefault;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 媒体管理器背景色
*/
@property (nonatomic, strong) UIColor *backgroundColor;

/** 媒体管理器背景媒体
*/
@property (nonatomic, strong) PEImageAsset *backgroundAsset;

/** 一个媒体管理器中可有多个媒体
 */
@property (nonatomic,strong) NSMutableArray<PEImageAsset*> *assets;


@end


@interface PEImageAsset : NSObject<NSCopying, NSMutableCopying>

/** 标识符
 */
@property (nonatomic,strong) NSString*  identifier;
/**  资源地址 图片  视频
 */
@property (nonatomic,strong) NSURL*  url;
@property (nonatomic,strong) NSString* localIdentifier;

/** 换发
 */
@property (nonatomic, strong) NSURL *hairOriginalUrl;
@property (nonatomic, strong) NSMutableArray * hairArray;
@property (nonatomic, strong) NSMutableArray* faces;

/**  图片填充类型
 *   设置顶点坐标(pointsInImageArray)时，需设置为ImageMediaFillTypeFull
 */
@property (nonatomic,assign) ImageMediaFillType  fillType;

/**  是否有人像
 *
 */
@property(nonatomic, assign)BOOL        isPortrait;

/**图片裁剪范围。默认为CGRectMake(0, 0, 1, 1)
 */
@property (nonatomic,assign) CGRect           crop;

/**图片旋转角度 -360 < x < 360
 */
@property (nonatomic,assign) double           rotate;

/**是否上下镜像
 */
@property (nonatomic,assign) BOOL             isVerticalMirror;

/**是否左右镜像
 */
@property (nonatomic,assign) BOOL             isHorizontalMirror;

/**默认为CGRectMake(0, 0, 1, 1)，其中(0, 0)为左上角 (1, 1)为右下角，
 * rectInImage与pointsInImageArray只有一个有效，以最后设置的为准
 */
@property (nonatomic, assign) CGRect           rectInImage;

/** 图片透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic,assign) float alpha;

/** 调色
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

/**滤镜强度，FilterType_LookUp时有效,默认为1.0
 */
@property (nonatomic, assign)float filterIntensity;



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


/** 设置模糊强度0.0~1.0，默认为0.0
 *  blur是对整个视频有效，而该属性仅对单个媒体有效
 */
@property (nonatomic, assign) float blurIntensity;

/** 设置模糊效果
 *  设置媒体动画后，该属性无效，以动画中的 blur 为准
 */
@property (nonatomic, strong) Blur *blur;
 
/**在 image 中四个顶点的坐标，可设置非矩形。
 * (0, 0)为左上角 (1, 1)为右下角
 * rectInImage与pointsInImageArray只有一个有效，以最后设置的为准
 */
@property (nonatomic, readonly) NSArray *pointsInImageArray;

/** 是否使用rectInImage，默认为YES
 *  YES:使用rectInImage   NO:使用pointsInImageArray
 */
@property (nonatomic, readonly) BOOL isUseRect;

/**在image中四个顶点的坐标，可设置非矩形，设置的值将赋给pointsInImageArray属性。
 * (0, 0)为左上角 (1, 1)为右下角
 *  @param leftTop      媒体在image中的 左上角 顶点坐标
 *  @param rightTop     媒体在image中的 右上角 顶点坐标
 *  @param rightBottom  媒体在image中的 右下角 顶点坐标
 *  @param leftBottom   媒体在image中的 左下角 顶点坐标
 *
 * rectInImage与pointsInImageArray只有一个有效，以最后设置的为准
 */
- (NSArray *)setPointsInImageLeftTop:(CGPoint)leftTop
                            rightTop:(CGPoint)rightTop
                         rightBottom:(CGPoint)rightBottom
                          leftBottom:(CGPoint)leftBottom;


/**设置媒体自定义多滤镜数组，一个滤镜可以由多个滤镜组合而成。
 */
@property (nonatomic, strong) NSMutableArray <CustomMultipleFilter*>* customMultipleFilterArray;


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



/** 要透过的颜色，须与图片中一致，FilterBlendType 需要设置为 FilterBlendTypeChromaColor 否则无效
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

/**智能抠像(天空)
 */
@property (nonatomic, assign) kAutoSegmentType autoSegmentType;
@property (nonatomic, strong)UIImage *autoSegmentImage;

/** 可替换类型，默认为MediaReplaceableType_VideoOrPic
 */
@property (nonatomic, assign) NSInteger replaceType;

/**景深
 */
@property (nonatomic, assign) BOOL isDOF;


@property (nonatomic, strong) NSURL * manualKeyPath;

@end



/** 视频水印
 */
@interface PEOverlay : NSObject<NSCopying, NSMutableCopying>

/** 标识符
 */
@property (nonatomic,strong) NSString*  identifier;

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 类型
 */
@property (nonatomic, assign) OverlayType type;


/** 媒体
 */
@property (nonatomic,strong) PEImageAsset*  asset;


@end
