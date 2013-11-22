#include "stdafx.h"
#include "base.h"
#include "sys.h"
#include "core.h"

#define SHIP_W 250
#define SHIP_H 270

int g_ship_LL, g_ship_L, g_ship_C, g_ship_R, g_shipRR;
int g_bkg;

//-----------------------------------------------------------------------------
void StartGame() {
  g_ship_LL = CORE_LoadBmp( "data/ShipLL.bmp", false );
  g_ship_L = CORE_LoadBmp( "data/ShipL.bmp", false );
  g_ship_C = CORE_LoadBmp( "data/ShipC.bmp", false );
  g_ship_R = CORE_LoadBmp( "data/ShipR.bmp", false );
  g_ship_RR = CORE_LoadBmp( "data/ShipRR.bmp", false );
  g_bkg = CORE_LoadBmp( "data/bkg0.bmp", false );
}
//---------------------------------------------------------------
void EndGame() {
  CORE_UnloadBmp( g_ship_LL );
  CORE_UnloadBmp( g_ship_L );
  CORE_UnloadBmp( g_ship_C );
  CORE_UnloadBmp( g_ship_R );
  CORE_UnloadBmp( g_ship_RR );
  CORE_UnloadBmp( g_bkg );
}

//-----------------------------------------------------------------------------
void Render() {
  glClear( GL_COLOR_BUFFER_BIT );

  CORE_RenderCenteredSprite( vmake( G_WIDTH / 2.0f, G_HEIGHT / 2.0f ), vmake( G_WIDTH, G_HEIGHT ) );

  if( SYS_KeyPressed( SYS_KEY_LEFT ) )
    CORE_RenderCenteredSprite( vmake( G_WIDTH / 2.0f, 200.f ), vmake( SHIP_W, SHIP_H ), g_ship_LL );
  else if (SYS_KeyPressed( SYS_KEY_RIGHT ) )
    CORE_RenderCenteredSprite( vmake( G_WIDTH / 2.0f, 200.f ), vmake( SHIP_W, SHIP_H ), g_ship_RR );
  else
    CORE_RenderCenteredSprite( vmake( G_WIDTH / 2.0f, 200.f ), vmake( SHIP_W, SHIP_H ), g_ship_C );
}

//-----------------------------------------------------------------------------
void RunGame() {
}



//-----------------------------------------------------------------------------
void ProcessInput() {
}

//-----------------------------------------------------------------------------
// Game State (apart from entities and other standalone modules
float g_time = 0.f;

//-----------------------------------------------------------------------------
//Main - the game's "Main" - not int main( int argc, char *argv[])!
int Main( void ) {
  //start things up, load resources
  StartGame();

  //set up rendering-----------------------------------------------------------
  glViewport( 0, 0, SYS_WIDTH, SYS_HEIGHT );
  glClearColor( 0.0f, 0.1f, 0.3f, 0.0f );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho( 0, 0, G_WIDTH, 0.0, G_HEIGHT, 0.0, 1.0 );
  glEnable( GL_TEXTURE_2D );
  glEnable( GL_BLEND );
  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

  //main game loop------------------------------------------------------------
  while( !SYS_GottaQuit() ) {
    Render();
    ProcessInput();
    RunGame();
    SYS_Show();
    SYS_Pump();
    SYS_Sleep( 16 );
    g_time += 1.f/60.f;
  }

  return 0;
}

