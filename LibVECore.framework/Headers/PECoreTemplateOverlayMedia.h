//
//  PECoreTemplateOverlayMedia.h
//  LibVECore
//
//  Created by iOS VESDK Team on 2022/1/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateOverlayMedia : NSObject

/** 图片地址
 */
@property (nonatomic, copy) NSString *imageFolderPath;
/** 显示位置
 */
@property (nonatomic, assign) CGRect showRectF;
/** 旋转角度
 */
@property (nonatomic, assign) float     angle;

@property (nonatomic, assign) int       level;

@end

NS_ASSUME_NONNULL_END
