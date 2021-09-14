//
//  VEAudioRecorder.h
//  LibVECore
//
//  Created by mac on 2021/9/10.
//

#import <Foundation/Foundation.h>

@class VEAudioRecorder;
@protocol VEAudioRecorderDelegate <NSObject>
@optional
/**  返回当前录制时间
 *  @param recorder                                   self
 *  @param currentTime                              当前录制时间
 *  @param rms                                          声音振幅百分比 （ 可用于实时绘制音波图 ）
 */
- (void)audioRecorder:(VEAudioRecorder *)recorder currentTime:(NSTimeInterval)currentTime rms:(float)rms;
/**  返回结束录制后的mp3文件路径
 *  @param recorder                                    self
 *  @param filePath                                      mp3文件保存路径
 */
- (void)audioRecorderStop:(VEAudioRecorder *)recorder filePath:(NSString *)filePath;
/**  返回当前录制的实时数据包
 *  @param recorder                                     self
 *  @param data                                           音频数据包
 *  @param numberOfPackets                       音频数据大小
 */
- (void)audioRecorder:(VEAudioRecorder *)recorder inputData:(NSData *)data numberOfPackets:(UInt32)numberOfPackets;
/**  返回错误信息
 *  @param recorder                                     self
 *  @param error                                          错误信息
 */
- (void)audioRecorder:(VEAudioRecorder *)recorder errorOccur:(NSError *)error;
@end

NS_ASSUME_NONNULL_BEGIN

@interface VEAudioRecorder : NSObject

/**  初始化对象
 *  @abstract  Returns an instance of VECore for reading media data.
 *
 *  @param appkey           在官网中注册的应用Key。
                            Application Key registered in the SDK official website.
 *
 *  @param appsecret        在官网(中注册的应用秘钥。
                            Application secret key registered in the SDK official website.
 *
 *  @param licenceKey       在官网(中注册的licenceKey。
                            The licenseKey registered in the SDK official website.s.
 
 *  @param delegate  代理
 */
- (instancetype) initWithAPPKey:(NSString *)appkey
                      APPSecret:(NSString *)appsecret
                     LicenceKey:(NSString *)licenceKey
                     atDelegate:( id ) delegate;

- (instancetype) initWithAPPKey:(NSString *)appkey
                      APPSecret:(NSString *)appsecret
                     atDelegate:( id ) delegate;

/**  设置声道数
 */
-(void)setChannelsPerFrame:(int) channelsPerFrame;
/**  设置音量
 */
-(void)setVolume:( float ) volume;
/**  设置变声
 */
-(void)setVoiceChanger:( float ) voiceChanger;
/**  设置降噪等级
 */
-(void)setNoise:( float ) noise;
/**  设置 文件路径+文件名+.mp3（注：文件格式必须为mp3）
 */
-(void)setFilePath:( NSString * )  path;
/**  设置采样率
 */
-(void)setSampleRate:( float ) sampleRate;
/**  开始录制
 */
-(void)start;
/**  暂停录制
 */
-(void)pause;
/**  停止录制
 */
-(void)stop;
/**  代理
 */
@property (nonatomic, weak) id<VEAudioRecorderDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
