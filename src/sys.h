//sys.h
#ifndef _SYS_H_
#define _SYS_H_

//============================================================================
//Resolution (real & virtual)

//Portrait 2:3 aspect ratio
#define SYS_WIDTH 512
#define SYS_HEIGHT 768
#define SYS_FULLSCREEN 0

//main game coordinate system: width is 1000, height is 1500
#define G_WIDTH 1000
#define G_HEIGHT 1500

//============================================================================
//Platform layer

void SYS_Pump();
void SYS_Show();
bool SYS_GottaQuit();
void SYS_Sleep( int ms );
bool SYS_KeyPressed( int key );
ivec2 SYS_MousePos();
bool SYS_MouseButtonPressed( int button );

//============================================================================
//define keys... no Mac/Windows!

#define SYS_KEY_UP GLFW_KEY_UP
#define SYS_KEY_DOWN GLFW_KEY_DOWN
#define SYS_KEY_LEFT GLFW_KEY_LEFT
#define SYS_KEY_RIGHT GLFW_KEY_RIGHT

#define SYS_MB_LEFT GLFW_MOUSE_BUTTON_LEFT
#define SYS_MB_RIGHT GLFW_MOUSE_BUTTON_RIGHT
#define SYS_MB_MIDDLE GLFW_MOUSE_BUTTON_MIDDLE

#endif
