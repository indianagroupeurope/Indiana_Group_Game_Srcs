#include "stdafx.h"
#include <sstream>
#include "utils.h"
#include "log.h"
#include "dev_log.h"
#include "config.h"
#include "offlineshop_config.h"

enum
{
	GOLD_MAX = 2000000000,
	ITEM_MAX_COUNT = 200,
};

using namespace std;

BYTE g_bOfflineShopSaveTime = 5;

bool g_bNeedMoney = false;
DWORD g_dwNeedMoney = 0;
int g_iTotalOfflineShopCount = 1000;

bool g_bNeedItem = false;
int g_iItemVnum = 0;
BYTE g_bItemCount = 0;

int tezgahPaketi = 0;

int g_bMinLevel = 50;

int time1gGold = 50000;
int time2gGold = 100000;
int time3gGold = 250000;
int time4gGold = 500000;

bool g_bOfflineShopMapAllowLimit = false;
static set<int> s_set_offlineshop_map_allows;

bool g_bEnableRespawnOfflineShop = true;
BYTE g_bOfflineShopSocketMax = 3;

bool offlineshop_map_allow_find(int mapIndex)
{
	if (g_bAuthServer)
		return false;
	
	if (s_set_offlineshop_map_allows.find(mapIndex) == s_set_offlineshop_map_allows.end())
		return false;
	
	return true;
}

void offlineshop_map_allow_add(int mapIndex)
{
	if (offlineshop_map_allow_find(mapIndex))
	{
		fprintf(stderr, "Multiple map allow detected!");
		exit(1);
	}
	
	fprintf(stdout, "OFFLINESHOP_MAP_ALLOW: %d\n", mapIndex);
	s_set_offlineshop_map_allows.insert(mapIndex);
}

void offlineshop_config_init()
{
	if (!g_bAuthServer)
	{
		FILE * file;

		char buf[256], token_string[256], value_string[256];

		if (!(file = fopen("OFFLINE_SHOP_CONFIG", "r")))
		{
			fprintf(stderr, "Can not open [OFFLINE_SHOP_CONFIG]\n");
			exit(1);
		}

		while (fgets(buf, 256, file))
		{
			parse_token(buf, token_string, value_string);

			TOKEN("OFFLINE_SHOP_SAVE_TIME")
			{
				g_bOfflineShopSaveTime = MINMAX(1, g_bOfflineShopSaveTime, 10);
				str_to_number(g_bOfflineShopSaveTime, value_string);
				// sys_log(0, "OFFLINE_SHOP_SAVE_TIME: %d\n", g_bOfflineShopSaveTime);
			}

			TOKEN("OFFLINE_SHOP_NEED_MONEY")
			{
				char arg1[256];
				char arg2[256];
				two_arguments(value_string, arg1, sizeof(arg1), arg2, sizeof(arg2));

				if (!*arg1 || !*arg2)
				{
					fprintf(stderr, "OFFLINE_SHOP_NEED_MONEY syntax: offline_shop_need_money <disable or enable> <money>\n");
					exit(1);
				}
				else if (!isnhdigit(*arg2))
				{
					fprintf(stderr, "Second argument must be integer!\n");
					exit(1);
				}

				if (!strcmp(arg1, "enable"))
					g_bNeedMoney = true;
				else if (!strcmp(arg1, "disable"))
					g_bNeedMoney = false;
				else if (isnhdigit(*arg1))
					str_to_number(g_bNeedMoney, arg1);
				
				// Check overflow and configure the money.
				g_dwNeedMoney = MINMAX(1, g_dwNeedMoney, GOLD_MAX);

				str_to_number(g_dwNeedMoney, arg2);
				// sys_log(0, "OFFLINE_SHOP_NEED_MONEY: %s - Money %u\n", g_bNeedMoney ? "Enabled" : "Disabled", g_dwNeedMoney);
			}

			TOKEN("OFFLINE_SHOP_TOTAL_COUNT")
			{
				str_to_number(g_iTotalOfflineShopCount, value_string);
				// sys_log(0, "OFFLINE_SHOP_TOTAL_COUNT: %d\n", g_iTotalOfflineShopCount);
			}

			TOKEN("OFFLINE_SHOP_NEED_ITEM")
			{
				char arg1[256];
				char arg2[256];
				char arg3[256];
				three_arguments(value_string, arg1, sizeof(arg1), arg2, sizeof(arg2), arg3, sizeof(arg3));

				if (!*arg1 || !*arg2 || !*arg3)
				{
					fprintf(stderr, "OFFLINE_SHOP_NEED_ITEM syntax: offline_shop_need_item <enable or disable> <item_vnum> <item_count>\n");
					exit(1);
				}
				else if (!isnhdigit(*arg2) || !isnhdigit(*arg3))
				{
					fprintf(stderr, "Second argument and third argument must be integer!\n");
					exit(1);
				}

				if (!strcmp(arg1, "enable"))
					g_bNeedItem = true;
				else if (!strcmp(arg1, "disable"))
					g_bNeedItem = false;
				else if (isnhdigit(*arg1))
					str_to_number(g_bNeedItem, arg1);
				
				
				// Item count can be maximum 200.
				g_bItemCount = MINMAX(1, g_bItemCount, ITEM_MAX_COUNT);

				str_to_number(g_iItemVnum, arg2);
				str_to_number(g_bItemCount, arg3);
				// sys_log(0, "OFFLINE_SHOP_NEED_ITEM: %s %d %d\n", g_bNeedItem ? "Enabled" : "Disabled", g_iItemVnum, g_bItemCount);
			}
			
			TOKEN("OFFLINE_SHOP_MIN_LEVEL")
			{
				g_bMinLevel = MINMAX(1, g_bMinLevel, 120);
				str_to_number(g_bMinLevel, value_string);
				// sys_log(0, "OFFLINE_SHOP_MIN_LEVEL: %d\n", g_bMinLevel);
			}
	
			TOKEN("TEZGAH_PAKETI")
			{
				str_to_number(tezgahPaketi, value_string);
			}

			TOKEN("1_SAAT_PAZAR_UCRETI")
			{
				str_to_number(time1gGold, value_string);
			}
			
			TOKEN("2_SAAT_PAZAR_UCRETI")
			{
				str_to_number(time2gGold, value_string);
			}
			
			TOKEN("3_SAAT_PAZAR_UCRETI")
			{
				str_to_number(time3gGold, value_string);
			}
			
			TOKEN("SURESIZ_PAZAR_UCRETI")
			{
				str_to_number(time4gGold, value_string);
			}

			TOKEN("OFFLINE_SHOP_MAP_ALLOW_LIMIT")
			{
				char arg1[256];
				one_argument(value_string, arg1, sizeof(arg1));

				if (!*arg1)
				{
					fprintf(stderr, "OFFLINE_SHOP_MAP_ALLOW_LIMIT syntax: offline_shop_map_allow_limit <enable or disable> or < 0 or 1 >\n");
					exit(1);
				}

				if (!strcmp(arg1, "enable"))
					g_bOfflineShopMapAllowLimit = true;
				else if(!strcmp(arg1, "disable"))
					g_bOfflineShopMapAllowLimit = false;
				else if(isnhdigit(*arg1))
					str_to_number(g_bOfflineShopMapAllowLimit, arg1);
			}

			TOKEN("OFFLINE_SHOP_MAP_ALLOW")
			{
				if (!g_bOfflineShopMapAllowLimit)
				{
					fprintf(stderr, "OFFLINE_SHOP_MAP_ALLOW_LIMIT must be enable for this option!\n");
					exit(1);
				}

				char * p = value_string;
				string stNum;

				for(; *p; p++)
				{
					if (isnhspace(*p))
					{
						if (stNum.length())
						{
							int index = 0;
							str_to_number(index, stNum.c_str());
							offlineshop_map_allow_add(index);
							stNum.clear();
						}
					}
					else
						stNum += *p;
				}

				if (stNum.length())
				{
					int index = 0;
					str_to_number(index, stNum.c_str());
					offlineshop_map_allow_add(index);
				}

				continue;
			}
			
			TOKEN("OFFLINE_SHOP_RESPAWN")
			{
				char arg1[256];
				one_argument(value_string, arg1, sizeof(arg1));
				
				if (!*arg1)
				{
					fprintf(stderr, "OFFLINE_SHOP_RESPAWN syntax : offline_shop_respawn: <string or integer>\n");
					exit(1);
				}
				
				if (!strcmp(arg1, "enable"))
					g_bEnableRespawnOfflineShop = true;
				else if (!strcmp(arg1, "disable"))
					g_bEnableRespawnOfflineShop = false;
				else if (isnhdigit(*arg1))
					str_to_number(g_bEnableRespawnOfflineShop, value_string);
			}
			
			TOKEN("OFFLINE_SHOP_SOCKET_MAX")
			{
				str_to_number(g_bOfflineShopSocketMax, value_string);
				g_bOfflineShopSocketMax = MINMAX(3, g_bOfflineShopSocketMax, 6);
				// fprintf(stderr, "OFFLINE_SHOP_SOCKET_MAX: %d\n", g_bOfflineShopSocketMax);				
			}
		}
	}
}