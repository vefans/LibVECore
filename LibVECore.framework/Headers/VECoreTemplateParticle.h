//
//  VECoreTemplateParticle.h
//  PEPictureEdit
//
//  Created by mac on 2022/5/19.
//

#import <LibVECore/Scene.h>

NS_ASSUME_NONNULL_BEGIN

@interface VECoreTemplateParticle : NSObject

@property (nonatomic, assign)VEPIPType  pipType;

/**资源分类ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 *  导出模板用
 */
@property (nonatomic, strong) NSString *networkResourceId;
/**资源路径
 *  粒子素材
 */
@property (nonatomic, strong) NSString *folderPath;
/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;
/**粒子名字
 */
@property (nonatomic, strong) NSString *name;
/**粒子大小
 */
@property (nonatomic, assign) float  size;
/**粒子数目
 */
@property (nonatomic, assign) float  density;
/**粒子历史数据BUG
 */
@property (nonatomic, strong) NSString *historyPoints;

/**
 */
@property (nonatomic, assign)  float fRailLevelY;


-(instancetype)initWithParticle:( Particle * ) particle;

- (Particle *)getCustomParticleWithFolderPath:(NSString *)folderPath;

/** 层次，数值越大，越靠前，0 为最底层，默认为 0
 */
@property(nonatomic,assign) int level;

@end

NS_ASSUME_NONNULL_END
