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

@property (nonatomic, assign) int       level;
/** 组Id
 */
@property (nonatomic, assign) int groupId;

/** 可替换类型，默认为MediaReplaceableType_VideoOrPic
 */
@property (nonatomic, assign) MediaReplaceableType replaceType;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) Float64 timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) Float64 timelineTo;

/**  资源地址 图片  视频
 */
@property (nonatomic, strong) NSString *path;
@property(nonatomic, strong)NSMutableArray * addTextList;
@property(nonatomic, strong)NSURL   * addTextOriginalImageUrl;
@property(nonatomic, assign)CGRect  addTextCrop;
@end

NS_ASSUME_NONNULL_END
