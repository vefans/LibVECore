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

@end



@interface MaskObject : NSObject

/**资源文件夹地址
 */
@property (nonatomic, strong) NSString *folderPath;

/**  名称
 */
@property (nonatomic, copy) NSString* name;

/**  顶点着色器脚本
 */
@property (nonatomic, copy) NSString* vert;

/** 片元着色器脚本
 */
@property (nonatomic, copy) NSString *frag;

/**  mask图片路径
 */
@property (nonatomic, copy) NSString *maskImagePath;


/** 动画组
 */
@property (nonatomic, strong) NSArray<AnimatePosition*>*  animate;




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

@end
