//
//  MaskObject.h
//  LibVECore
//
//  Created by iOS SDK Team on 2020/10/27.
//  Copyright © 2020 iOS SDK Team. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger, VECoreTextAlignment){
    VECoreTextAlignment_Horizontal_Left     = 0,    //横排居左
    VECoreTextAlignment_Horizontal_Center   = 1,    //横排居中
    VECoreTextAlignment_Horizontal_Right    = 2,    //横排居右
    VECoreTextAlignment_Vertical_Top        = 3,    //竖排居顶
    VECoreTextAlignment_Vertical_Center     = 4,    //竖排居中
    VECoreTextAlignment_Vertical_Bottom     = 5,    //竖排居底
};

@interface AnimatePosition : NSObject

/**time
 */
@property (nonatomic,assign) CGFloat atTime;

/**Set center point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    center point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint center;

/**Set mask size
 */
@property (nonatomic, assign) CGSize size;

/**Set mask distance
 */
@property (nonatomic, assign) float distance;

/**Set rectangle mask corner radius (0-1.0)
 */
@property (nonatomic, assign) float cornerRadius;

/**Set mask angle ,0-360, anticlockwise
 */
@property (nonatomic, assign) float degrees;

/**Set mask feather (0-1.0)
*/
@property (nonatomic, assign) float featherStep;

/**Decide whether to invert the mask
*/
@property (nonatomic, assign) BOOL invert;

/**Set mask edge color
*/
@property (nonatomic, strong) UIColor* edgeColor;

/**Set mask edge size (0-1.0)
*/
@property (nonatomic, assign) float edgeSize;


/**Set top left point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    top left  point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint topLeft;

/**Set top right point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    top right point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint topRight;

/**Set top bottom right point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    bottom right point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint bottomRight;

/**Set bottom left point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    bottom left point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint bottomLeft;

@end



@interface MaskObject : NSObject

/**资源ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkResourceId;

/**资源文件夹地址
 */
@property (nonatomic, strong) NSString *folderPath;

/**  名称
 */
@property (nonatomic, copy) NSString* name;

@property (nonatomic, copy) NSString* maskName;

/**  顶点着色器脚本
 */
@property (nonatomic, copy) NSString* vert;

/** 片元着色器脚本
 */
@property (nonatomic, copy) NSString *frag;

/**  mask图片/视频路径
 */
@property (nonatomic, copy) NSString *maskImagePath;

/** 视频mask是否重复播放，默认为NO
 */
@property (nonatomic, assign) BOOL isRepeat;

/** 动画组
 */
@property (nonatomic, strong) NSMutableArray<AnimatePosition*>*  animate;




/**Set center point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    center point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint center;

/**Set mask size
 */
@property (nonatomic, assign) CGSize size;

/**Set mask distance
 */
@property (nonatomic, assign) float distance;

/**Set rectangle mask corner radius (0-1.0)
 */
@property (nonatomic, assign) float cornerRadius;

/**Set mask angle ,0-360, anticlockwise
 */
@property (nonatomic, assign) float degrees;

/**Set mask feather (0-1.0)
*/
@property (nonatomic, assign) float featherStep;

/**Decide whether to invert the mask
*/
@property (nonatomic, assign) BOOL invert;

/**Set mask edge color
*/
@property (nonatomic, strong) UIColor* edgeColor;

/**Set mask edge size (0-1.0)
*/
@property (nonatomic, assign) float edgeSize;



/**Set top left point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    top left  point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint topLeft;

/**Set top right point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    top right point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint topRight;

/**Set top bottom right point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    bottom right point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint bottomRight;

/**Set bottom left point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    bottom left point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint bottomLeft;

@property (nonatomic, strong) NSString *text;

/** 文字行间距(-1.0〜1.0),默认为0.0
 */
@property (nonatomic ,assign) float lineSpacing;

/** 文字字间距(-1.0〜1.0),默认为0.0
 */
@property (nonatomic ,assign) float wordSpacing;

/**文字字体大小
 */
@property (nonatomic ,assign) float fontSize;

/**文字对齐方式,default is VECoreTextAlignment_Horizontal_Center.
 */
@property (nonatomic ,assign) VECoreTextAlignment textAlignment;

@end
