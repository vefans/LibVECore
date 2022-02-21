//
//  PETemplateExportInfo.h
//  LibVECore
//
//  Created by mac on 2021/12/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PETemplateExportInfo : NSObject
/** 是否导出素材，默认为NO
*/
@property (nonatomic, assign) BOOL isExportTemplateMedias;
/** 是否导出素材，默认为NO
*/
@property (nonatomic, assign) BOOL isExportTemplate;

/** 是否导出片段信息，默认为NO
 */
@property (nonatomic, assign) BOOL isHasFragments;
@end

NS_ASSUME_NONNULL_END
