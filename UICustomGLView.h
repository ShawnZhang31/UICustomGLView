//
//说明:继承UIView类，这个类中封装了CAEAGLLayer，用于绘制OpenGL场景，
//如果EAGL平面有Alpha通道的话，必须将该视图设置为不透明才能正常工作。
//
//  Created by Seventy-Three on 16/7/22.
//  Copyright © 2016年 panxsoft.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

/**
 *使用OpenGLES来绘制追踪结果和追踪时的摄像头图像。
 */
@interface UICustomGLView : UIView
{
@private
    /**
     * 缓存区域的像素大小
     *
     */
    GLint backingWidth;
    /**
     * 缓存区域的像素大小
     *
     */
    GLint backingHeight;
    
    /**
     * OpenGL绘图环境
     *
     */
    EAGLContext *context;
    
    /**
     * 渲染该视图的渲染缓存和帧缓存的OpenGL命名
     *
     */
    GLuint viewRenderbuffer, viewFramebuffer;
    
    /**
     * 帧缓存附带的深度缓存的OpenGL命名，如果不存在直接设置为0
     *
     */
    GLuint depthRenderbuffer;
}

@property (nonatomic) GLint backingWidth;
@property (nonatomic) GLint backingHeight;

/*
 * 绘制视图的方法
 */
-(void)drawView;
/**
 * 设置OpenGL绘图上下文的方法
 *
 * 这个方法将绑定帧缓存并且清除缓存。
 */
-(void)setOpenGLContext;
/**
 * 交换OpenGL绘制缓存的方法。
 *
 * 显示帧缓存。在调用OpenGL绘制方法之后调用该方法来显示绘制结果。
 */
-(void)swapOpenGLBuffers;

@end
