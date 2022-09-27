//
//  CustomFilter.h
//  VECore
//
//  Created by iOS SDK Team on 2018/11/27.
//  Copyright © 2018年 iOS SDK Team. All rights reserved.
//

#ifndef CUSTOMFILTER_H
#define CUSTOMFILTER_H

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>
#import <LibVECore/CustomShader.h>
#import <LibVECore/Common.h>//

@interface ShaderParams : NSObject

/** uniform 变量类型（包含 int/float/ma4/array类型）
 */
@property (nonatomic ,assign) SHADER_UNIFORM_TYPE type;

/** 时间，设置不同时间点对应不同的参数
 */
@property (nonatomic ,assign) float time;

/** 设置shader 中 uniform float 类型变量参数
 */
@property (nonatomic ,assign) float fValue;

/** 设置shader 中 uniform int 类型变量参数
 */
@property (nonatomic ,assign) int iValue;

/** 设置shader 中 uniform mat4 类型变量参数
 */
@property (nonatomic,assign) GLMatrix4x4    matrix4;

/** 设置shader 中 uniform mat3 类型变量参数
 */
@property (nonatomic,assign) GLMatrix3x3    matrix3;

/** 设置shader 中 uniform 数组 类型变量参数
 */
@property (nonatomic,strong) NSMutableArray<NSNumber *>*array;

@end


@interface TextureParams : NSObject

/** 纹理类型
 */
@property (nonatomic, assign)TextureType type;

/** 纹理图片或者视频
 */
@property (nonatomic, retain) NSMutableArray *pathArray;
@property (nonatomic, copy) NSString*  path DEPRECATED_MSG_ATTRIBUTE("Use pathArray instead.");

/** shader 纹理变量名
 */
@property (nonatomic, copy)NSString* name;

/** 如果 shader 需要多个输入纹理，index 用于 name 和 inputFilterName 对应
    如果 shader 只需要一个输入纹理，index 可以不需要设置
 */
@property (nonatomic, assign) int index;

/** 纹理warp模式
 */
@property (nonatomic, assign)TextureWarpMode warpMode;

/** 纹理filter模式
*/
@property (nonatomic, assign)TextureFilterMode filterMode;

@end

typedef NS_ENUM(NSInteger, CustomFilterOverlayType) {
    CustomFilterOverlayTypeMainVideo,        //主视频
    CustomFilterOverlayTypePIP,              //画中画
    CustomFilterOverlayTypeVirtualVideo,     //虚拟视频
};
typedef NS_ENUM(NSInteger, CustomAnimationType) {
    CustomAnimationTypeIn,          //入场
    CustomAnimationTypeOut,         //出场
    CustomAnimationTypeCombined,    //组合
};

@interface CustomFilter : NSObject<NSCopying, NSMutableCopying>

/**资源文件夹地址
 */
@property (nonatomic, strong) NSString *folderPath;

/**资源分类ID
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 */
@property (nonatomic, strong) NSString *networkResourceId;

/** 特效覆盖类型
 */
@property (nonatomic, assign) CustomFilterOverlayType overlayType;

/** 自定义动画类型
 */
@property (nonatomic, assign) CustomAnimationType animateType;

/**  自定义滤镜名称
 */
@property (nonatomic, copy) NSString* name;

/**  顶点着色器脚本
 */
@property (nonatomic, copy) NSString* vert;

/** 片元着色器脚本
    shader内置变量名：
    time             :时间线
    resolution       :视图窗口分辨率
 */
@property (nonatomic, copy) NSString* frag;

/**  script
 */
@property (nonatomic, copy) NSString* script;

@property (nonatomic, copy) NSString* scriptName;
/**
 *  动画在视频中的显示位置
 */
@property (nonatomic, assign) CGRect rectInVideo;

/**  设置滤镜持续时间
 */
@property (nonatomic,assign) CMTimeRange timeRange;

/**  设置滤镜特效周期时长（单位：秒）,默认为1.0
     如果持续时间大于周期时间，自动循环设置特效
 */
@property (nonatomic,assign) float cycleDuration;

/*
 * 是否重复循环，如果持续时间大于周期时间，假如 repeatMode 设置为 YES ,只循环1次；假如 repeatMode 设置为 NO,重复循环；默认为 NO
 */
@property (nonatomic,assign) BOOL repeatMode;


/** 内置滤镜类型
 */
@property (nonatomic, assign)BuiltInFilter_TYPE builtInType;


/** 内置滤镜素材
 */
@property (nonatomic, copy) NSString*  path;

/**滤镜强度，builtInType为BuiltInFilter_lookUp时有效,默认为1.0
 * 如果有设置 filterAnimation 动画，以 filterAnimation 参数为准，该参数无效
 */
@property (nonatomic, assign)float lookUpFilterIntensity;

/** 滤镜动画组
 */
@property (nonatomic, strong) NSArray<KeyFrameAnimate*>*  filterAnimation;

/**滤镜条纹启用，builtInType为BuiltInFilter_Mosaic时有效,默认为YES
 */
@property (nonatomic, assign)BOOL isStrip;


/** 当前作为输入源的特效名字，如果当前特效由多个特效组成时，
    会根据 inputFilterName 将上一个或者多个特效的结果作为输入继续处理，默认为 nil
 */
@property (nonatomic, copy) NSMutableArray*  inputFilterName;


/**  设置shader中 uniform sampler2D 类型参数（纹理参数）
 */
- (NSError *) setShaderTextureParams:(TextureParams *)textureParams;

/**  设置shader变量参数
 *
 *  @param params       设置参数，根据时间点设置不同参数
 *  @param isRepeat     参数是否重复使用
 *  @param uniform      shader中变量的名字
 */
- (NSError *) setShaderUniformParams:(NSMutableArray<ShaderParams*> *)params
                            isRepeat:(BOOL)isRepeat
                          forUniform:(NSString *)uniform;

@end



/** 同时支持多个特效
 */

@interface CustomMultipleFilter : NSObject<NSCopying, NSMutableCopying>

@property (nonatomic, assign) NSInteger tag;
@property (nonatomic, strong) NSString *name;
/**资源文件夹地址
 */
@property (nonatomic, strong) NSString *folderPath;

/**资源分类ID
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 */
@property (nonatomic, strong) NSString *networkResourceId;

/**  设置滤镜持续时间
 */
@property (nonatomic,assign) CMTimeRange timeRange;

/** 特效覆盖类型
 */
@property (nonatomic, assign) CustomFilterOverlayType overlayType;

/** 特效数组
 */
- (instancetype)initWithFilterArray:(NSMutableArray<CustomFilter*>*)filterArray;

@property (nonatomic, strong) NSMutableArray<CustomFilter*>* filterArray;

@end


#endif /* Header_h */
