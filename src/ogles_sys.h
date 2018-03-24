#pragma once

#include "EGL/egl.h"
#include "GLES3/gl3.h"

struct SysContext
{
	// Windows variables
	HWND				nativeWindow;
	HDC					deviceContext;

	// EGL variables
	EGLDisplay			eglDisplay;
	EGLConfig			eglConfig;
	EGLSurface			eglSurface;
	EGLContext			eglContext;

	// Callback funcs
	void (*renderFunc)	();
	void (*keyFunc)		(unsigned char, bool);
	void (*updateFunc)	(float deltaTime);
};

void sysInit(SysContext* sysCtx, int screenW, int screenH);

void sysMainLoop(SysContext* sysCtx);

void sysRegisterRenderFunc(SysContext* sysCtx, void (*func)());
void sysRegisterUpdateFunc(SysContext* sysCtx, void (*func)(float));
void sysRegisterKeyFunc(SysContext* sysCtx, void (*func)(unsigned char, bool));

void sysCleanUp(SysContext* sysCtx);

void printSystemSpecs();

void Debug(const char* formatStr, ...);

