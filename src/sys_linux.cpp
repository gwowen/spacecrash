//sys_linux.cpp
#include "stdafx.h"
#include "base.h"
#include "sys.h"

//-----------------------------------------------------------------------------
//provided by game
extern int Main( void );

//-----------------------------------------------------------------------------
//Platform layer implementation

//=============================================================================
int main( int argc, char *argv[] ) {
  int retval = -1;

  if( glfwInit() == GL_TRUE ) {
    if( glfwOpenWindow( SYS_WIDTH, SYS_HEIGHT, 0, 0, 0, 0, 8, 0, SYS_FULLSCREEN ? GLFW_FULLSCREEN : GLFW_WINDOW ) == GL_TRUE )  {
      retval = Main();
      glfwCloseWindow();
    }
    glfwTerminate();
  }
  return retval;
}

//------------------------------------------------------------------------------
void SYS_Pump() {

}

//------------------------------------------------------------------------------
void SYS_Show() {
  glfwSwapBuffers();
}

//-----------------------------------------------------------------------------
bool SYS_GottaQuit() {
  return glfwGetKey( GLFW_KEY_ESC ) || !glfwGetWindowParam( GLFW_OPENED );
}

//-----------------------------------------------------------------------------
void SYS_Sleep( int ms ) {
  usleep( 1000 * ms );
}

//-----------------------------------------------------------------------------
bool SYS_KeyPressed( int key ) {
  return glfwGetKey( key );
}

//-----------------------------------------------------------------------------
ivec2 SYS_MousePos() {
  int x, y;
  ivec pos;
  glfwGetMousePos( &x, &y );
  pos.x = x;
  pos.y = SYS_HEIGHT - y;
  return pos;
}

//------------------------------------------------------------------------------
bool SYS_MouseButtonPressed( int button ) {
  return glfwGetMouseButton( button );
}
									   
