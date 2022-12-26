//
//  VECoreTemplateTheme.h
//  LibVECore
//
//  Created by emmet-mac on 2022/11/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VECoreTemplateTheme : NSObject

/**资源分类ID
 */
@property (nonatomic, strong) NSString *networkCategoryId;

/**资源ID
 */
@property (nonatomic, strong) NSString *networkResourceId;
/**资源路径
 */
@property (nonatomic, strong) NSString *folderPath;
/**名称
 */
@property (nonatomic, strong) NSString *name;
@end

NS_ASSUME_NONNULL_END
