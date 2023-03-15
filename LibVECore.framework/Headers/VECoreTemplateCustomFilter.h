//
//  VECoreTemplateCustomFilter.h
//  LibVECore
//
//  Created by iOS VESDK Team  on 2021/4/21.
//  Copyright © 2021 iOS VESDK Team. All rights reserved.
//

#import <LibVECore/CustomFilter.h>
#import <LibVECore/Common.h>
#import <LibVECore/Scene.h>

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

@property(nonatomic, assign)VEPIPType   pipType;

@property (nonatomic, assign) float tag;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/** 内置滤镜素材
 */
@property (nonatomic, copy) NSString *lookUpFilterPath;

@property (nonatomic, strong) VECoreTemplateCustomFilterExtra *extra;

- (instancetype)initWithCustomFilter:(CustomFilter *)filter;

- (CustomFilter *)getCustomFilterWithFolderPath:(NSString *)folderPath;

- (CustomMultipleFilter *)getCustomMultipleFilterWithFolderPath:(NSString *)folderPath;

@property (nonatomic, strong) NSMutableArray * animates;

/** 层次，数值越大，越靠前，0 为最底层，默认为 0
 */
@property(nonatomic,assign) int level;

@end

#pragma mark - 特效
@interface VECoreTemplateSpecialEffect : CustomFilter

@property (nonatomic, assign)VEPIPType  pipType;

/** 特效覆盖类型
 */
@property (nonatomic, assign) NSInteger nApplyRange;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/** 特效脚本名称
 */
@property (nonatomic, copy) NSMutableArray *specialEffectName;

/**  设置滤镜特效周期时长（单位：秒）,默认为1.0
     如果持续时间大于周期时间，自动循环设置特效
 */
@property (nonatomic, assign) float speed;

@property (nonatomic, strong) NSMutableArray *uniformParam;

- (instancetype)initWithCustomFilter:(CustomFilter *)filter;

- (CustomFilter *)getCustomFilterWithFolderPath:(NSString *)folderPath;

- (CustomMultipleFilter *)getCustomMultipleFilterWithFolderPath:(NSString *)folderPath;

/** 层次，数值越大，越靠前，0 为最底层，默认为 0
 */
@property(nonatomic,assign) int level;

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

#pragma mark - 3D动画
@interface VECoreTemplateAnimation3D : Animation3D

/**  json资源地址
 */
@property (nonatomic,strong) NSString *path;

/** 动画时长
 */
@property (nonatomic, assign) float duration;

- (instancetype)initWithAnimation3D:(Animation3D *)animate;

- (Animation3D *)getAnimation3DWithFolderPath:(NSString *)folderPath;

@end
