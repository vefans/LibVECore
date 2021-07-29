//
//  CameraFile.h
//  VECore
//
//  Created by iOS SDK Team on 2017/5/22.
//  Copyright © 2017年 iOS SDK Team. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <LibVECore/Scene.h>

@interface CameraFile : NSObject
@property (nonatomic , copy) NSString  * fileName;
@property (nonatomic , copy) NSURL  * url;
@property (nonatomic , copy) NSURL  * fileReversUrl;

@property (nonatomic , assign) double duration;

@property (nonatomic , assign) double speed;
@end

NS_CLASS_DEPRECATED_IOS(6_0, 8_0, "Use MovieEffect instead")
// 相机随拍聚焦特效
@interface CameraMVEffect : NSObject

// 视频资源地址
@property (nonatomic , strong) NSURL*  url;
// 混合类型
@property (nonatomic , assign) MVEffectType type;

@end

/** 可设置画面每帧的动画
 */
@interface CameraCustomAnimate : NSObject

/**开始时间
 */
@property (nonatomic,assign) CGFloat atTime;


/**画面裁剪位置，默认为CGRectZero
 */
@property (nonatomic ,assign) CGRect crop;


/**动画类型
 */
@property (nonatomic,assign) AnimationInterpolationType type;


/**等比例缩放，默认1.0
 */
@property (nonatomic, assign) float scale;

@end
