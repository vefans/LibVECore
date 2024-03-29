//
//  PECoreTemplateFilter.h
//  LibVECore
//
//  Created by iOS VESDK Team on 2022/3/1.
//

#import <Foundation/Foundation.h>
#import <LibVECore/CustomFilter.h>

NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateFilter : NSObject

@property(nonatomic, assign)NSInteger   filterType;

@property(nonatomic, assign)float           filterIntensity;

@property(nonatomic, strong)NSString *  filterPath;

@property(nonatomic, strong)NSString *   filterNetworkCategoryId;

@property(nonatomic, strong)NSString *   filterNetworkResourceId;

@property(nonatomic, assign)int             level;

- (instancetype)initWithFilter:(CustomMultipleFilter *)filter;
- (CustomMultipleFilter *)getFilterWithFolderPath:(NSString *)folderPath;

- (instancetype)initWithCustomFilter:(CustomFilter *)filter;
- (CustomFilter *)getCustomFilterWithFolderPath:(NSString *)folderPath;

@end

NS_ASSUME_NONNULL_END
