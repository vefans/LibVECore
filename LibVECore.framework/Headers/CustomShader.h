//
//  CustomFilter.h
//  VECore
//
//  Created by iOS SDK Team on 2018/11/27.
//  Copyright © 2018年 iOS SDK Team. All rights reserved.
//

#ifndef CUSTOMSHADER_H
#define CUSTOMSHADER_H

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>

struct GLVectore4 {
    
    float one;
    float two;
    float three;
    float four;
};
typedef struct GLVectore4 GLVectore4;

struct GLMatrix4x4 {
    
    GLVectore4 one;
    GLVectore4 two;
    GLVectore4 three;
    GLVectore4 four;
};
typedef struct GLMatrix4x4 GLMatrix4x4;

struct GLVectore3 {
    
    float one;
    float two;
    float three;
};
typedef struct GLVectore3 GLVectore3;

struct GLMatrix3x3 {
    
    GLVectore3 one;
    GLVectore3 two;
    GLVectore3 three;
};
typedef struct GLMatrix3x3 GLMatrix3x3;

//纹理类型
typedef NS_ENUM(NSInteger, TextureType) {
    TextureType_Sample2DMain,                      // 主画面纹理
    TextureType_Sample2DBuffer,                    // 图像数据
    
};

//纹理模式
typedef NS_ENUM(NSInteger, TextureWarpMode) {
    TextureWarpModeClampToEdge,               // 位于纹理边缘或者靠近纹理边缘的纹理单元将用于纹理计算，但不使用纹理边框上的纹理单元,默认使用该模式
    TextureWarpModeRepeat,                    // 纹理边界重复
    TextureWarpModeMirroredRepeat,            // 超出纹理范围的坐标整数部分被忽略，但当整数部分为奇数时进行取反，形成镜像效果
    
};

typedef NS_ENUM(NSInteger, TextureFilterMode) {
    TextureFilterLinear,                     // 使用纹理中坐标最接近的若干个颜色，通过加权平均算法得到需要绘制的像素颜色,默认使用该模式
    TextureFilterNearest,                    // 使用纹理中坐标最接近的一个像素的颜色作为需要绘制的像素颜色
    
};

//uniform 变量类型
typedef NS_ENUM(NSInteger, SHADER_UNIFORM_TYPE)
{
    UNIFORM_INT,
    UNIFORM_FLOAT,
    UNIFORM_ARRAY,
    UNIFORM_MATRIX4X4,
    UNIFORM_MATRIX3X3,
};

//内置滤镜
typedef NS_ENUM(NSInteger, BuiltInFilter_TYPE)
{
    BuiltInFilter_None,
    BuiltInFilter_illusion,                     //幻觉
    BuiltInFilter_pencilSketch,                 //铅笔素描
    BuiltInFilter_pencilColor,                  //铅笔彩色
    BuiltInFilter_pencilLightWater,             //铅笔+淡水彩
    BuiltInFilter_pencilCharcoalSketches,       //炭笔素描
    BuiltInFilter_pencilCrayon,                 //蜡笔画
    BuiltInFilter_grayCrosspoint,               //黑白交叉
    BuiltInFilter_colorCrosspoint,              //彩色交叉
    BuiltInFilter_freezeFrame,                  //画面定格
    BuiltInFilter_lookUp,                       //lookUp滤镜
};



#endif /* Header_h */
