//========================================================================
// GLFW 3.4 - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2016 Google Inc.
// Copyright (c) 2016-2017 Camilla Löwy <elmindreda@glfw.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================
// It is fine to use C99 in this file because it will not be built with VS
//========================================================================

#include "internal.h"

#include <stdlib.h>


//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
//////////////////////////////////////////////////////////////////////////

int _glfwPlatformInit(void)
{
    _glfwInitTimerPOSIX();
    _glfwPollMonitorsNull();

    return GLFW_TRUE;
}

void _glfwPlatformTerminate(void)
{
    free(_glfw.null.clipboardString);
    #if defined(_GLFW_OSMESA)
    _glfwTerminateOSMesa();
    #elif defined(_GLFW_EGLHEADLESS)
    _glfwTerminateEGL();
    #else
    #error "No supported context selected"
    #endif
}

const char* _glfwPlatformGetVersionString(void)
{
    #if defined(_GLFW_OSMESA)
    return _GLFW_VERSION_NUMBER " null OSMesa";
    #elif defined(_GLFW_EGLHEADLESS)
    return _GLFW_VERSION_NUMBER " null EGL Headless";
    #else
    #error "No supported context selected"
    #endif
}

