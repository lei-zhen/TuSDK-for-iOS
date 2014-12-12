//
//  TuSDKPFCameraViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/3.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKCPResultViewController.h"
#import "TuSDKStillCamera.h"
#import "TuSDKPFCameraView.h"

@class TuSDKPFCameraViewController;

/**
 *  默认相机视图控制器委托
 */
@protocol TuSDKPFCameraDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  获取一个拍摄结果
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuSDKResult *)result;
@optional
/**
 *  获取一个拍摄结果 (异步方法)
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onAsyncTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuSDKResult *)result;
@end

/**
 *  默认相机视图控制器
 */
@interface TuSDKPFCameraViewController : TuSDKCPResultViewController<TuSDKStillCameraDelegate, TuSDKPFCameraViewDelegate, TuSDKPFCameraFilterDelegate>{
@protected
    // 默认样式视图
    TuSDKPFCameraView *_defaultStyleView;
    // 相机对象
    TuSDKStillCamera *_camera;
}

/**
 *  默认相机视图控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFCameraDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFCameraView, 需要继承 TuSDKPFCameraView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  默认相机控制栏视图类 (默认:TuSDKPFCameraConfigView, 需要继承 TuSDKPFCameraConfigView)
 */
@property (nonatomic, strong) Class configBarViewClazz;

/**
 *  默认相机底部栏视图类 (默认:TuSDKPFCameraBottomView, 需要继承 TuSDKPFCameraBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  闪光灯视图类 (默认:TuSDKPFCameraFlashView, 需要继承 TuSDKPFCameraFlashView)
 */
@property (nonatomic, strong) Class flashViewClazz;

/**
 *  滤镜视图类 (默认:TuSDKPFCameraFilterView, 需要继承 TuSDKPFCameraFilterView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  聚焦触摸视图类 (需要继承 TuSDKICFocusTouchView)
 */
@property (nonatomic, strong) Class focusTouchViewClazz;

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFCameraView *defaultStyleView;

/**
 *  相机对象
 */
@property (nonatomic, readonly) TuSDKStillCamera *camera;

/**
 *  摄像头前后方向 (默认为后置优先)
 */
@property (nonatomic) AVCaptureDevicePosition avPostion;

/**
 *  摄像头分辨率模式 (默认：AVCaptureSessionPresetHigh)
 *  @see AVCaptureSession for acceptable values
 */
@property (nonatomic, copy) NSString *sessionPreset;

/**
 *  闪光灯模式 (默认:AVCaptureFlashModeOff)
 */
@property (nonatomic) AVCaptureFlashMode defaultFlashMode;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  视频视图显示比例 (默认:0.75f, 0 < cameraViewRatio <= 1)
 */
@property (nonatomic) CGFloat cameraViewRatio;

/**
 *  是否开启长按拍摄 (默认: NO)
 */
@property (nonatomic) BOOL enableLongTouchCapture;

/**
 *  开启持续自动对焦 (默认: NO)
 */
@property (nonatomic) BOOL enableContinueFoucs;

/**
 *  自动聚焦延时 (默认: 5秒)
 */
@property (nonatomic) NSTimeInterval autoFoucsDelay;

/**
 *  长按延时 (默认: 1.2秒)
 */
@property (nonatomic) NSTimeInterval longTouchDelay;

/**
 *  创建默认样式视图 (如需创建自定义视图，请覆盖该方法，并创建自己的视图类)
 */
- (void)buildDefaultStyleView;

/**
 *  开始启动相机
 */
- (void)startCamera;

/**
 *  继续执行相机
 */
- (void)resumeCamera;

/**
 *  销毁相机
 */
- (void)destoryCamera;
@end
