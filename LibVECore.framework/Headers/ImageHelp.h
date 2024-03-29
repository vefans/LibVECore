//
//  ImageHelp.h
//  SafeAlbum
//
//  Created by MAC_RD on 2024/2/6.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface ImageHelp : NSObject
+ (NSArray<UIBezierPath *> *)extractEdgePathsFromImageData:(unsigned char *)data width:(size_t)width height:(size_t)height;
@end

NS_ASSUME_NONNULL_END
