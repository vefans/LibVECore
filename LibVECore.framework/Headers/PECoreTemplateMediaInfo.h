//
//  PECoreTemplateMediaInfo.h
//  PESDK
//
//  Created by mac on 2022/1/29.
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

/**  资源地址 图片  视频
 */
@property (nonatomic, strong) NSString *path;
@end

NS_ASSUME_NONNULL_END
