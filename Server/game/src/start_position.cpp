#include "stdafx.h"
#include "start_position.h"


char g_nation_name[4][32] =
{
	"",
	"신수국",
	"천조국",
	"진노국",
};

//	LC_TEXT("신수국")
//	LC_TEXT("천조국")
//	LC_TEXT("진노국")

long g_start_map[7] =
{
	0,
	1,
	21,
	41,
	7,
	27,
	47
};

DWORD g_start_position[7][2] =
{
	{0, 0},
	{469300, 964200},
	{55700, 157900},
	{969600, 278400},
	{768000, 896000},
	{819200, 896000},
	{870400, 896000}
};

DWORD arena_return_position[4][2] =
{
	{       0,  0       },
	{   347600, 882700  }, // 자양현
	{   138600, 236600  }, // 복정현
	{   857200, 251800  }  // 박라현
};


DWORD g_create_position[7][2] = 
{
	{0, 0},
	{474900, 965900},
	{60000, 155800},
	{963700, 278300},
	{808600, 936000},
	{859800, 936000},
	{911000, 936000}
};

DWORD g_create_position_canada[7][2] = 
{
	{0, 0},
	{457100, 946900},
	{45700, 166500},
	{966300, 288300},
	{808600, 936000},
	{859800, 936000},
	{911000, 936000}
};
