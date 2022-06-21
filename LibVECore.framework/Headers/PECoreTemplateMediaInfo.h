//
//  PECoreTemplateMediaInfo.h
//  PESDK
//
//  Created by iOS VESDK Team on 2022/1/29.
//

#import <Foundation/Foundation.h>
#import <LibVECore/scene.h>
NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateMediaInfo : NSObject

/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 可替换类型，默认为MediaReplaceableType_VideoOrPic
 */
@property (nonatomic, assign) MediaReplaceableType replaceType;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/**  资源地址 图片  视频
 */
@property (nonatomic, strong) NSString *path;
@end

NS_ASSUME_NONNULL_END
