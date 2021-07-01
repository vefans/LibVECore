//
//  VECoreTemplateMusic.h
//  LibVECore
//
//  Created by iOS VESDK Team  on 2021/4/21.
//  Copyright © 2021 iOS VESDK Team. All rights reserved.
//

#import <LibVECore/Scene.h>

@interface VECoreTemplateMusic : MusicInfo

/** 地址
 */
@property (nonatomic, strong) NSString *path;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/** 截取开始时间
 */
@property (nonatomic, assign) float trimTimeStart;

/** 截取结束时间
 */
@property (nonatomic, assign) float trimTimeEnd;

/**配乐开头淡入淡出时长，默认为2.0秒
 */
@property (nonatomic, assign) float fadeInDuration;

/**配乐结尾淡入淡出时长，默认为2.0秒
 */
@property (nonatomic, assign) float fadeOutDuration;

- (instancetype)initWithMusic:(MusicInfo *)music;

- (MusicInfo *)getMusicInfoWithFolderPath:(NSString *)folderPath;

@end
