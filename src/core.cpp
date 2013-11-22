//core.cpp
#include "stdafx.h"
#include "base.h"
#include "core.h"

//---------------------------------------------------------------------------
//Loading textures (from BMP files)
#define MAX_TEXTURES 32

struct Texture {
  bool used;
  float w, h; //In 0..1 terms
  int pixw, pixh;
  GLuint tex;
} g_textures[ MAX_TEXTURES ] = { 0 };

int CORE_LoadBmp ( const char filename[], bool wrap );
void CORE_UnloadBMP ( int texid );

//---------------------------------------------------------------------------
struct CORE_BMPFileHeader {
  byte mark[2];
  byte filesize[4];
  byte reserved[4];
  byte pixdataoffset[4];

  byte hdrsize[4];
  byte width[4];
  byte height[4];
  byte colorplanes[2];
  byte bpp[2];
  byte compression[4];
  byte pixdatasize[4];
  byte hres[4];
  byte vres[4];
  byte numcol[4];
  byte numimportantcolors[4];
};
