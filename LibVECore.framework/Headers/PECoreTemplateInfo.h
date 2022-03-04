//
//  PECoreTemplateInfo.h
//  PESDK
//
//  Created by mac on 2021/12/21.
//

#import <Foundation/Foundation.h>
#import "PECoreTemplateAssetManager.h"
#import "PECoreTemplateOverlay.h"
#import "VECoreTemplateInfo.h"
#import "PECoreTemplateOverlayMedia.h"
#import <LibVECore/PEAssetManager.h>
#import <LibVECore/VECoreTemplateCaption.h>
#import "PECoreTemplateBackground.h"
#import "PECoreTemplateMediaInfo.h"
#import "PECoreTemplateFilter.h"
NS_ASSUME_NONNULL_BEGIN

@interface PECoreTemplateInfo : NSObject
/** 版本号
 */
@property (nonatomic, assign) float ver;
/** 分辨率
 */
@property (nonatomic, assign) CGSize size;
/** 模板资源大小，单位M
 *  不导出媒体资源时才返回
 */
@property (nonatomic, assign) float fileSize;
/** 媒体信息，仅包含可替换媒体
 */
@property (nonatomic, strong) NSMutableArray<PECoreTemplateMediaInfo*> *mediaInfo;
/** 底图
 */
@property (nonatomic, strong) PECoreTemplateBackground *bg;

/** 场景
 */
@property (nonatomic, strong) NSMutableArray<PECoreTemplateAssetManager*>*scenes;
/** 新版字幕
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSubtitleEx*>* subtitleExs;
/** 新版贴纸
 */
@property (nonatomic, strong) NSMutableArray<VECoreTemplateSticker*>* stickers;
/** 画中画
 */
@property (nonatomic, strong) NSMutableArray <PECoreTemplateOverlay*>* pips;
///** 画中画背景
// */
//@property (nonatomic, strong) NSMutableArray <PECoreTemplateOverlay*>* overlayBackgrounds;
/** 边框
 */
@property (nonatomic, strong) NSMutableArray <PECoreTemplateOverlayMedia*>* frames;
/** 叠加
 */
@property (nonatomic, strong) NSMutableArray <PECoreTemplateOverlayMedia*>* overlays;
/** 画笔
 */
@property (nonatomic, strong) NSMutableArray <PECoreTemplateOverlay*>* doodles;
/** 滤镜
*/
@property (nonatomic, strong) PECoreTemplateFilter* filter;
/** 特效
*/
@property (nonatomic, strong) NSMutableArray <VECoreTemplateSpecialEffect*>* specialEffects;
/** 调色
*/
@property (nonatomic, strong) VECoreTemplateToningInfo  *adjust;

/**
 Creates and returns a new instance of the receiver from a json.
 This method is thread-safe.
 
 @param json  A json object in `NSDictionary`, `NSString` or `NSData`.
 
 @return A new instance created from the json, or nil if an error occurs.
 */
- (instancetype)initWithJSON:(id)json;

/**
 Generate a json object from the receiver's properties.
 
 @return A json object in `NSDictionary` or `NSArray`, or nil if an error occurs.
 See [NSJSONSerialization isValidJSONObject] for more information.
 
 @discussion Any of the invalid property is ignored.
 If the reciver is `NSArray`, `NSDictionary` or `NSSet`, it just convert
 the inner object to json object.
 */
- (id)objectToJSONObject;

@end

NS_ASSUME_NONNULL_END
