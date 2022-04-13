//
//  VECoreTemplateCustomFilter.h
//  LibVECore
//
//  Created by iOS VESDK Team  on 2021/4/21.
//  Copyright © 2021 iOS VESDK Team. All rights reserved.
//

#import <LibVECore/CustomFilter.h>
#import <LibVECore/Common.h>

#pragma mark - 滤镜
@interface VECoreTemplateCustomFilterExtra : NSObject

/** 滤镜类型
 */
@property (nonatomic, assign) FilterType type;

/**滤镜条纹启用，kFilterType_Mosaic时有效,默认为YES
 */
@property (nonatomic, assign)BOOL strip;

@end

@interface VECoreTemplateCustomFilter : CustomFilter

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/** 内置滤镜素材
 */
@property (nonatomic, copy) NSString *lookUpFilterPath;

@property (nonatomic, strong) VECoreTemplateCustomFilterExtra *extra;

- (instancetype)initWithCustomFilter:(CustomFilter *)filter;

- (CustomFilter *)getCustomFilterWithFolderPath:(NSString *)folderPath;

- (CustomMultipleFilter *)getCustomMultipleFilterWithFolderPath:(NSString *)folderPath;

@end

#pragma mark - 特效
@interface VECoreTemplateSpecialEffect : CustomFilter

/** 特效覆盖类型
 */
@property (nonatomic, assign) NSInteger nApplyRange;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/** 特效脚本名称
 */
@property (nonatomic, copy) NSMutableArray *specialEffectName;

- (instancetype)initWithCustomFilter:(CustomFilter *)filter;

- (CustomFilter *)getCustomFilterWithFolderPath:(NSString *)folderPath;

- (CustomMultipleFilter *)getCustomMultipleFilterWithFolderPath:(NSString *)folderPath;

@end

#pragma mark - 动画
@interface VECoreTemplateCustomAnimation : CustomFilter

/** 动画类型
 */
@property (nonatomic, assign) CustomAnimationType type;

/** 动画时长
 */
@property (nonatomic, assign) float duration;

- (instancetype)initWithCustomFilter:(CustomFilter *)filter;

- (CustomFilter *)getCustomFilterWithFolderPath:(NSString *)folderPath;

@end
