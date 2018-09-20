//
//  SuperPlayerControlView.h
//  TXLiteAVDemo
//
//  Created by annidyfeng on 2018/6/25.
//  Copyright © 2018年 Tencent. All rights reserved.
//
#import <UIKit/UIKit.h>

#import "SuperPlayer.h"
#import "SuperPlayerControlViewDelegate.h"
#import "SuperPlayerModel.h"
#import "PlayerSlider.h"
#import "SuperPlayerFastView.h"
#import "MMMaterialDesignSpinner.h"
#import "MoreContentView.h"

@interface SuperPlayerControlView : UIView

/** 标题 */
@property (nonatomic, strong) UILabel                 *titleLabel;
/** 开始播放按钮 */
@property (nonatomic, strong) UIButton                *startBtn;
/** 当前播放时长label */
@property (nonatomic, strong) UILabel                 *currentTimeLabel;
/** 视频总时长label */
@property (nonatomic, strong) UILabel                 *totalTimeLabel;
/** 全屏按钮 */
@property (nonatomic, strong) UIButton                *fullScreenBtn;
/** 锁定屏幕方向按钮 */
@property (nonatomic, strong) UIButton                *lockBtn;
/** 系统菊花 */
@property (nonatomic, strong) MMMaterialDesignSpinner *activity;
/** 返回按钮*/
@property (nonatomic, strong) UIButton                *backBtn;
/** 关闭按钮*/
@property (nonatomic, strong) UIButton                *closeBtn;
/** bottomView*/
@property (nonatomic, strong) UIImageView             *bottomImageView;
/** topView */
@property (nonatomic, strong) UIImageView             *topImageView;
/** 弹幕按钮 */
@property (nonatomic, strong) UIButton                *danmakuBtn;
/// 是否禁用弹幕
@property BOOL                                        disableDanmakuBtn;
/** 截图按钮 */
@property (nonatomic, strong) UIButton                *captureBtn;
/** 更多按钮 */
@property (nonatomic, strong) UIButton                *moreBtn;
/** 更多的View */
@property (nonatomic, strong) UIScrollView            *moreView;
/** 切换分辨率按钮 */
@property (nonatomic, strong) UIButton                *resolutionBtn;
/** 分辨率的View */
@property (nonatomic, strong) UIView                  *resolutionView;
/** 播放按钮 */
@property (nonatomic, strong) UIButton                *playeBtn;
/** 加载失败按钮 */
@property (nonatomic, strong) UIButton                *middleBtn;
/** 快进快退View*/
@property (nonatomic, strong) SuperPlayerFastView     *fastView;
/** 当前选中的分辨率btn按钮 */
@property (nonatomic, weak  ) UIButton                *resoultionCurrentBtn;
/** 占位图 */
@property (nonatomic, strong) UIImageView             *placeholderImageView;
/** 分辨率的名称 */
@property (nonatomic, strong) NSArray<SuperPlayerUrl *> *resolutionArray;
/** 更多设置View */
@property (nonatomic, strong) MoreContentView        *moreContentView;
/** 返回直播 */
@property (nonatomic, strong) UIButton               *backLiveBtn;
/** 显示控制层 */
@property (nonatomic, assign, getter=isShowing) BOOL  showing;

@property NSString *liveUrl;

@property (nonatomic, weak) id<SuperPlayerControlViewDelegate> delegate;

@property CGFloat videoRatio;

/** 滑杆 */
@property (nonatomic, strong) PlayerSlider   *videoSlider;

/** 重播按钮 */
@property (nonatomic, strong) UIButton       *repeatBtn;

/**
 * 取消自动隐藏控制层view
 */
- (void)playerCancelAutoFadeOutControlView;


/**
 * 切换分辨率功能
 * @param resolutionArray 分辨率名称的数组
 * @param defualtIndex 当前分辨率
 */
- (void)playerResolutionArray:(NSArray<SuperPlayerUrl *> *)resolutionArray defaultIndex:(NSInteger)defualtIndex;
- (void)playerResolutionIndex:(NSInteger)defualtIndex;

/**
 * progress显示缓冲进度
 */
- (void)playerPlayableProgress:(CGFloat)progress;

/**
 * 正常播放
 * @param currentTime 当前播放时长
 * @param totalTime   视频总时长
 * @param value       slider的value(0.0~1.0)
 */
- (void)playerCurrentTime:(NSInteger)currentTime totalTime:(NSInteger)totalTime sliderValue:(CGFloat)value;

- (void)playerRemoveAllPoints;
- (void)playerAddVideoPoint:(CGFloat)where text:(NSString *)text time:(NSInteger)time;

/**
 * 播放按钮状态 (播放、暂停状态)
 */
- (void)playerPlayBtnState:(BOOL)state;

/**
 * 视频标题
 */
- (void)playerTitle:(NSString *)title;

/**
 * 背景图片
 */
- (void)playerBackgroundImage:(UIImage *)image;
- (void)playerBackgroundImageUrl:(NSURL *)imageUrl placeholderImage:(UIImage *)placeholderImage;

/**
 * 视频加载失败提示
 */
- (void)playerIsFailed:(NSString *)error;

/**
 * 视频网络不好提示
 */
- (void)playerBadNet:(NSString *)tips;

- (void)playerMiddleBtn;

/**
 * 开始播放（隐藏placeholderImageView）
 */
- (void)playerIsPlaying;

/**
 * 加载的菊花
 */
- (void)playerIsActivity:(BOOL)animated;

/**
 * 拖拽快进 快退
 * @param draggedTime 拖拽的时长
 * @param totalTime   视频总时长
 * @param sliderValue 进度条位置
 */
- (void)playerDraggedTime:(NSInteger)draggedTime totalTime:(NSInteger)totalTime sliderValue:(CGFloat)sliderValue thumbnail:(UIImage *)thumbnail;

- (void)playerDraggedLight:(CGFloat)draggedValue;

- (void)playerDraggedVolume:(CGFloat)draggedValue;

/**
 * 滑动调整进度结束结束
 */
- (void)playerDraggedEnd;

/**
 * 播放完了
 */
- (void)playerPlayEnd;


- (void)playerShowOrHideControlView;

/**
 * 锁定屏幕方向按钮状态
 */
- (void)playerLockBtnState:(BOOL)state;

/**
 *  隐藏控制层
 */
- (void)playerHideControlView;

/**
 *  显示控制层
 */
- (void)playerShowControlView;

/** 重置ControlView */
- (void)playerResetControlView;

/** 更多设置中的类容 */
- (void)playerControlViewLive:(BOOL)isLive;

- (void)autoFadeOutControlView;

/**
 * 时移隐藏
 */
- (void)playerBackLiveBtnHidden:(BOOL)hidden;

- (void)playerShowTips:(NSString *)tips delay:(NSTimeInterval)delay;

@end