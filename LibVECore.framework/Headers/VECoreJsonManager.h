//
//  VECoreJsonManager.h
//  LibVECore
//
//  Created by iOS SDK Team on 2020/9/22.
//  Copyright © 2020 iOS SDK Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface VECoreJsonExportInfo : NSObject

/** 宽
 */
@property (nonatomic, assign) float width;

/** 高
 */
@property (nonatomic, assign) float height;

/** 帧率
 */
@property (nonatomic, assign) int fps;

/** 码率，单位M
 */
@property (nonatomic, assign) float bitRate;

/** 音频码率，单位M
 */
@property (nonatomic, assign) float audioBitRate;

/** 音频声道数
 */
@property (nonatomic, assign) int audioChannel;

@end

@interface VECoreJsonMediaObject : NSObject

/** 类型：0(视频)、1(图片)、2(GIF)
 */
@property (nonatomic, assign) int type;

/** 地址
 */
@property (nonatomic, copy) NSString *path;

/** 宽
 */
@property (nonatomic, assign) float width;

/** 高
 */
@property (nonatomic, assign) float height;

/** 帧率
 */
@property (nonatomic, assign) int fps;

/** 码率，单位M
 */
@property (nonatomic, assign) float bitRate;

/** 原时长
 */
@property (nonatomic, assign) float duration;

/** 截取开始时间
 */
@property (nonatomic, assign) float trimIn;

/** 截取结束时间
 */
@property (nonatomic, assign) float trimOut;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

@end


@interface VECoreJsonScene : NSObject

@property (nonatomic, strong) NSMutableArray<VECoreJsonMediaObject *>*medias;

@end



@interface VECoreJsonAudio : NSObject

/** 地址
 */
@property (nonatomic, copy) NSString *path;

/** 码率，单位Kbps
 */
@property (nonatomic, assign) float bitRate;

/** 采样率
 */
@property (nonatomic, assign) float sampleRate;

/** 声道数
 */
@property (nonatomic, assign) int channel;

/** 原时长
 */
@property (nonatomic, assign) float duration;

/** 截取开始时间
 */
@property (nonatomic, assign) float trimIn;

/** 截取结束时间
 */
@property (nonatomic, assign) float trimOut;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

@end

@interface VECoreJsonCaption : NSObject

/**字幕背景色，默认无
 */
@property (nonatomic, assign) float backgroundColorR;
@property (nonatomic, assign) float backgroundColorG;
@property (nonatomic, assign) float backgroundColorB;
@property (nonatomic, assign) float backgroundColorA;

/** 在虚拟视频中的开始时间
 */
@property (nonatomic, assign) float timelineFrom;

/** 在虚拟视频中的结束时间
 */
@property (nonatomic, assign) float timelineTo;

/**字幕旋转角度
 * 设置字幕动画组后，该属性无效，以动画中的rotate值为准
 */
@property (nonatomic ,assign) float angle;

/**字幕缩放大小，默认为1.0
 * 设置字幕动画组后，该属性无效，以动画中的scale值为准
 */
@property (nonatomic ,assign) float scale;

/**透明度(0.0~1.0)，默认1.0
 * 设置字幕动画组后，该属性无效，以动画中的opacity值为准
 */
@property (nonatomic,assign) CGFloat opacity;

/**字幕类型 0 带文字,1 不带文字
 */
@property (nonatomic ,assign) NSInteger type;

/** 字幕图片路径
 *   单张图片的情况，只设置该属性即可
 */
@property (nonatomic ,copy) NSString * captionImagePath;

/** 字幕图片文件夹路径
 *  多张图片的情况，与imageName、timeArray及frameArray配合使用
 */
@property (nonatomic ,copy) NSString * imageFolderPath;

/**图片前缀名字
 */
@property (nonatomic ,copy) NSString * imageName;

/**动画持续时间
 */
@property (nonatomic ,assign) float animateDuration;

/**字幕位置，默认为视频中心CGPointMake(0.5, 0.5)
 * 设置字幕动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic ,assign) float positionX;
@property (nonatomic ,assign) float positionY;

/**字幕大小，相对于实际视频size的字幕大小(CGPointMake(0, 0)〜CGPointMake(1, 1))
 * 设置字幕动画组后，该属性无效，以动画中的rect值为准
 */
@property (nonatomic ,assign) float width;
@property (nonatomic ,assign) float height;

/** 文字区域
 */
@property (nonatomic ,assign) float textLeftX;
@property (nonatomic ,assign) float textLeftY;
@property (nonatomic ,assign) float textWidth;
@property (nonatomic ,assign) float textHeight;

/** 文字透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic ,assign) float textAlpha;

/**文字内容
 */
@property (nonatomic ,copy) NSString * text;

/**文字字体名称
 */
@property (nonatomic ,copy) NSString * fontName;

/**文字字体路径
 */
@property (nonatomic ,copy) NSString * fontPath;

/**文字字体大小
 */
@property (nonatomic ,assign) float fontSize;

/**文字字体加粗，默认为NO
 */
@property (nonatomic ,assign) BOOL isBold;

/**文字字体斜体，默认为NO
 */
@property (nonatomic ,assign) BOOL isItalic;

/**文字对齐方式 默认为CaptionTextAlignmentCenter
 */
@property (nonatomic ,assign) NSInteger textAlignment;

/**文字颜色，默认为whiteColor
 */
@property (nonatomic, assign) float textColorR;
@property (nonatomic, assign) float textColorG;
@property (nonatomic, assign) float textColorB;
@property (nonatomic, assign) float textColorA;

/** 文字竖排，默认为NO
 *  仅支持一列
 *  设置富文本后，该属性无效
 */
@property (nonatomic ,assign) BOOL isVertical;

/**文字是否描边，默认为NO
 */
@property (nonatomic ,assign) BOOL isStroke;

/**文字描边颜色，默认黑色blackColor
 */
@property (nonatomic, assign) float strokeColorR;
@property (nonatomic, assign) float strokeColorG;
@property (nonatomic, assign) float strokeColorB;
@property (nonatomic, assign) float strokeColorA;

/**文字描边宽度,默认为0.0
 */
@property (nonatomic ,assign) float strokeWidth;

/** 文字描边透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic, assign) float strokeAlpha;

/**文字内描边颜色，默认黑色blackColor
 */
@property (nonatomic, assign) float innerStrokeColorR;
@property (nonatomic, assign) float innerStrokeColorG;
@property (nonatomic, assign) float innerStrokeColorB;
@property (nonatomic, assign) float innerStrokeColorA;

/**文字内描边宽度,默认为0.0
 */
@property (assign,nonatomic) float innerStrokeWidth;

/** 文字内描边透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic, assign) float innerStrokeAlpha;

/**文字是否设置阴影，默认为NO
 */
@property (nonatomic ,assign) BOOL isShadow;

/**文字阴影颜色，默认黑色blackColor
 */
@property (nonatomic, assign) float shadowColorR;
@property (nonatomic, assign) float shadowColorG;
@property (nonatomic, assign) float shadowColorB;
@property (nonatomic, assign) float shadowColorA;

/**文字阴影偏移量,默认为CGSizeMake(0, -1)
 */
@property (nonatomic ,assign) float shadowOffsetWidth;
@property (nonatomic ,assign) float shadowOffsetHeight;

/** 文字阴影透明度(0.0〜1.0),默认为1.0
 */
@property (nonatomic, assign) float shadowAlpha;

/** 字幕是否需要拉伸
 */
@property (nonatomic, assign) BOOL isStretch;

/**字幕拉伸的区域
 */
@property (nonatomic ,assign) float stretchLeftX;
@property (nonatomic ,assign) float stretchLeftY;
@property (nonatomic ,assign) float stretchWidth;
@property (nonatomic ,assign) float stretchHeight;

/**帧动画
 */
@property (nonatomic ,strong) NSArray * frameArray;

/**时间动画
 */
@property (nonatomic ,strong) NSArray * timeArray;

@end


@interface VECoreJsonVirtualVideo : NSObject

@property (nonatomic, strong) VECoreJsonExportInfo *exportInfo;

@property (nonatomic, strong) NSMutableArray<VECoreJsonScene *>*scenes;

@property (nonatomic, strong) NSMutableArray<VECoreJsonAudio *>*audios;

@property (nonatomic, strong) NSMutableArray<VECoreJsonCaption *>*captions;

@end


@interface VECoreJsonInfo : NSObject

/** 版本号
 *  0.1:只支持导出视频 及 时间参数      20200923
 *  0.2:支持字幕、贴纸                         20210302
 */
@property (nonatomic, assign) float ver;

@property (nonatomic, strong) VECoreJsonVirtualVideo *virtualVideo;

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
