#ifndef __INC_SERVICE_H__
#define __INC_SERVICE_H__

#define ENABLE_CHEQUE_SYSTEM
#define ENABLE_PORT_SECURITY
#define ENABLE_YMIR_AFFECT_FIX
#define NEW_PET_SYSTEM
#define ENABLE_OFFLINE_SHOP_SYSTEM
#define WJ_SHOW_STROKE_INFO
#define ITEM_BUFF_SYSTEM
#define ENABLE_SHOP_SISTEM
#define WJ_ENABLE_TRADABLE_ICON
#define __SEND_TARGET_INFO__

enum eCommonDefines {
	MAP_ALLOW_LIMIT = 64, // 32 default
};

// #define __AUCTION__
#define _IMPROVED_PACKET_ENCRYPTION_
#define __PET_SYSTEM__
#define __UDP_BLOCK__
#define __SASH_SYSTEM__
#define __HIGHLIGHT_SYSTEM__
#define __ANTI_RESIST_MAGIC_BONUS__
#define __APPLY_RESIST_HUMAN__
#define __NEW_ARROW_SYSTEM__
#define __WEAPON_COSTUME_SYSTEM__
#define __7AND8TH_SKILLS__
#define __CHANGELOOK_SYSTEM__
#define __NEW_EXCHANGE_WINDOW__
#define __VIEW_TARGET_PLAYER_HP__
#define __VIEW_TARGET_DECIMAL_HP__
#define __WJ_SHOW_MOB_INFO__
#define __WHISPER_LOG__
#define __VERSION_162__
#ifdef __VERSION_162__
	#define HEALING_SKILL_VNUM 265
#endif
#define __DUNGEON_FOR_GUILD__
#ifdef __DUNGEON_FOR_GUILD__
	#define __MELEY_LAIR_DUNGEON__
	#ifdef __MELEY_LAIR_DUNGEON__
		#define __DESTROY_INFINITE_STATUES_GM__
		#define __LASER_EFFECT_ON_75HP__
		#define __LASER_EFFECT_ON_50HP__
	#endif
#endif
#endif
