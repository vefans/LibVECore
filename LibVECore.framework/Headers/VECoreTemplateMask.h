//
//  VECoreTemplateMask.h
//  LibVECore
//
//  Created by iOS VESDK Team  on 2021/4/21.
//  Copyright © 2021 iOS VESDK Team. All rights reserved.
//

#import <LibVECore/MaskObject.h>

@interface VECoreTemplateMaskAnimate : AnimatePosition

/**Set center point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    center point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint centerF;

/**Set mask size
 */
@property (nonatomic, assign) CGSize sizeF;

- (instancetype)initWithMaskAnimate:(AnimatePosition *)animate;

- (AnimatePosition *)getMaskAnimateWithFolderPath:(NSString *)folderPath;

@end

@interface VECoreTemplateMask : MaskObject

/** 动画组
 */
@property (nonatomic, strong) NSMutableArray <VECoreTemplateMaskAnimate*>*animates;

/**Set center point
    (0.5,0.5) means in the media center,
    (0, 0) means in the upper left corner of the media,
    (1, 1) means in the lower right corner of the media
        
    center point (0.0 ,0.0) - (1.0 ,1.0)
*/
@property (nonatomic, assign) CGPoint centerF;

/**Set mask size
 */
@property (nonatomic, assign) CGSize sizeF;

- (instancetype)initWithMask:(MaskObject *)mask;

- (MaskObject *)getMaskWithFolderPath:(NSString *)folderPath;

@end
