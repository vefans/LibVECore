//
//  PECoreTemplateAssetManagerBackground.h
//  LibVECore
//
//  Created by iOS VESDK Team on 2021/12/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PEBackgroundType) {
    PEBackgroundTypeColor,    //颜色
    PEBackgroundTypeImage,    //图片
};

@interface PECoreTemplateAssetManagerBackground : NSObject

/** 类型
 */
@property (nonatomic, assign) PEBackgroundType type;

/** 颜色
*/
@property (nonatomic, strong) UIColor *color;

/** 模糊强度0.0~1.0，默认为0.0
 */
@property (nonatomic, assign) float blurIntensity;

///** 图片地址
// */
//@property (nonatomic, copy) NSString *imageFolderPath;
/**在图片中的范围。默认为CGRectMake(0, 0, 1, 1)
 * (0, 0)为左上角 (1, 1)为右下角
 */
@property (nonatomic, assign) CGRect showRectF;
/** 旋转角度
 */
@property (nonatomic, assign) float rotate;

/** 图片地址
 */
@property (nonatomic, copy) NSString *imagePath;

@end

NS_ASSUME_NONNULL_END
