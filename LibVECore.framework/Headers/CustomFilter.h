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


/** 纹理warp模式
 */
@property (nonatomic, assign)TextureWarpMode warpMode;

/** 纹理filter模式
*/
@property (nonatomic, assign)TextureFilterMode filterMode;

@end


@interface CustomFilter : NSObject

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



/** 内置滤镜类型
 */
@property (nonatomic, assign)BuiltInFilter_TYPE builtInType;


/** 内置滤镜素材
 */
@property (nonatomic, copy) NSString*  path;

/**滤镜强度，builtInType为BuiltInFilter_lookUp时有效,默认为1.0
 */
@property (nonatomic, assign)float lookUpFilterIntensity;

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

#endif /* Header_h */
