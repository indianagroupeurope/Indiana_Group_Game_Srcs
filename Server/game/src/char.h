#ifndef __INC_METIN_II_CHAR_H__
#define __INC_METIN_II_CHAR_H__

#include <boost/unordered_map.hpp>

#include "../../common/stl.h"
#include "entity.h"
#include "FSM.h"
#include "horse_rider.h"
#include "vid.h"
#include "constants.h"
#include "affect.h"
#include "affect_flag.h"
#include "cube.h"
#include "mining.h"
#include "attr_transfer.h"

class CBuffOnAttributes;
class CPetSystem;
#ifdef NEW_PET_SYSTEM
class CNewPetSystem;
#endif

#define INSTANT_FLAG_DEATH_PENALTY		(1 << 0)
#define INSTANT_FLAG_SHOP			(1 << 1)
#define INSTANT_FLAG_EXCHANGE			(1 << 2)
#define INSTANT_FLAG_STUN			(1 << 3)
#define INSTANT_FLAG_NO_REWARD			(1 << 4)
#define INSTANT_FLAG_OFFLINE_SHOP		(1 << 5)

#define AI_FLAG_NPC				(1 << 0)
#define AI_FLAG_AGGRESSIVE			(1 << 1)
#define AI_FLAG_HELPER				(1 << 2)
#define AI_FLAG_STAYZONE			(1 << 3)
#define MAX_CARDS_IN_HAND	5
#define MAX_CARDS_IN_FIELD	3


#define SET_OVER_TIME(ch, time)	(ch)->SetOverTime(time)

extern int g_nPortalLimitTime;

enum
{
	MAIN_RACE_WARRIOR_M,
	MAIN_RACE_ASSASSIN_W,
	MAIN_RACE_SURA_M,
	MAIN_RACE_SHAMAN_W,
	MAIN_RACE_WARRIOR_W,
	MAIN_RACE_ASSASSIN_M,
	MAIN_RACE_SURA_W,
	MAIN_RACE_SHAMAN_M,
	MAIN_RACE_WOLFMAN_M,
	MAIN_RACE_MAX_NUM,
};

enum
{
	POISON_LENGTH = 30,
	BLEEDING_LENGTH = 30,
	STAMINA_PER_STEP = 1,
	SAFEBOX_PAGE_SIZE = 9,
	AI_CHANGE_ATTACK_POISITION_TIME_NEAR = 10000,
	AI_CHANGE_ATTACK_POISITION_TIME_FAR = 1000,
	AI_CHANGE_ATTACK_POISITION_DISTANCE = 100,
	SUMMON_MONSTER_COUNT = 3,
};

enum
{
	FLY_NONE,
	FLY_EXP,
	FLY_HP_MEDIUM,
	FLY_HP_BIG,
	FLY_SP_SMALL,
	FLY_SP_MEDIUM,
	FLY_SP_BIG,
	FLY_FIREWORK1,
	FLY_FIREWORK2,
	FLY_FIREWORK3,
	FLY_FIREWORK4,
	FLY_FIREWORK5,
	FLY_FIREWORK6,
	FLY_FIREWORK_CHRISTMAS,
	FLY_CHAIN_LIGHTNING,
	FLY_HP_SMALL,
	FLY_SKILL_MUYEONG,
};

enum EDamageType
{
	DAMAGE_TYPE_NONE,
	DAMAGE_TYPE_NORMAL,
	DAMAGE_TYPE_NORMAL_RANGE,
	//��ų
	DAMAGE_TYPE_MELEE,
	DAMAGE_TYPE_RANGE,
	DAMAGE_TYPE_FIRE,
	DAMAGE_TYPE_ICE,
	DAMAGE_TYPE_ELEC,
	DAMAGE_TYPE_MAGIC,
	DAMAGE_TYPE_POISON,
	DAMAGE_TYPE_SPECIAL,
	DAMAGE_TYPE_BLEEDING,
};

enum EPointTypes
{
	POINT_NONE,						// point_value = 0
	POINT_LEVEL,					// point_value = 1
	POINT_VOICE,					// point_value = 2
	POINT_EXP,						// point_value = 3
	POINT_NEXT_EXP,					// point_value = 4
	POINT_HP,						// point_value = 5
	POINT_MAX_HP,					// point_value = 6
	POINT_SP,						// point_value = 7
	POINT_MAX_SP,					// point_value = 8 
	POINT_STAMINA,					// point_value = 9
	POINT_MAX_STAMINA,				// point_value = 10
	POINT_GOLD,						// point_value = 11
	POINT_ST,						// point_value = 12
	POINT_HT,						// point_value = 13
	POINT_DX,						// point_value = 14
	POINT_IQ,						// point_value = 15
	POINT_DEF_GRADE,				// point_value = 16
	POINT_ATT_SPEED,				// point_value = 17
	POINT_ATT_GRADE,				// point_value = 18
	POINT_MOV_SPEED,				// point_value = 19
	POINT_CLIENT_DEF_GRADE,			// point_value = 20
	POINT_CASTING_SPEED,			// point_value = 21
	POINT_MAGIC_ATT_GRADE,			// point_value = 22
	POINT_MAGIC_DEF_GRADE,			// point_value = 23
	POINT_EMPIRE_POINT,				// point_value = 24
	POINT_LEVEL_STEP,				// point_value = 25
	POINT_STAT,						// point_value = 26
	POINT_SUB_SKILL,				// point_value = 27
	POINT_SKILL,					// point_value = 28
	POINT_WEAPON_MIN,				// point_value = 29
	POINT_WEAPON_MAX,				// point_value = 30
	POINT_PLAYTIME,					// point_value = 31
	POINT_HP_REGEN,					// point_value = 32
	POINT_SP_REGEN,					// point_value = 33
	POINT_BOW_DISTANCE,				// point_value = 34
	POINT_HP_RECOVERY,				// point_value = 35
	POINT_SP_RECOVERY,				// point_value = 36
	POINT_POISON_PCT,				// point_value = 37
	POINT_STUN_PCT,					// point_value = 38
	POINT_SLOW_PCT,					// point_value = 39
	POINT_CRITICAL_PCT,				// point_value = 40
	POINT_PENETRATE_PCT,			// point_value = 41
	POINT_CURSE_PCT,				// point_value = 42
	POINT_ATTBONUS_HUMAN,			// point_value = 43
	POINT_ATTBONUS_ANIMAL,			// point_value = 44
	POINT_ATTBONUS_ORC,				// point_value = 45
	POINT_ATTBONUS_MILGYO,			// point_value = 46
	POINT_ATTBONUS_UNDEAD,			// point_value = 47
	POINT_ATTBONUS_DEVIL,			// point_value = 48
	POINT_ATTBONUS_INSECT,			// point_value = 49
	POINT_ATTBONUS_FIRE,			// point_value = 50
	POINT_ATTBONUS_ICE,				// point_value = 51
	POINT_ATTBONUS_DESERT,			// point_value = 52
	POINT_ATTBONUS_MONSTER,			// point_value = 53
	POINT_ATTBONUS_WARRIOR,			// point_value = 54
	POINT_ATTBONUS_ASSASSIN,		// point_value = 55
	POINT_ATTBONUS_SURA,			// point_value = 56
	POINT_ATTBONUS_SHAMAN,			// point_value = 57
	POINT_ATTBONUS_TREE,			// point_value = 58
	POINT_RESIST_WARRIOR,			// point_value = 59
	POINT_RESIST_ASSASSIN,			// point_value = 60
	POINT_RESIST_SURA,				// point_value = 61
	POINT_RESIST_SHAMAN,			// point_value = 62
	POINT_STEAL_HP,					// point_value = 63
	POINT_STEAL_SP,					// point_value = 64
	POINT_MANA_BURN_PCT,			// point_value = 65
	POINT_DAMAGE_SP_RECOVER,		// point_value = 66
	POINT_BLOCK,					// point_value = 67
	POINT_DODGE,					// point_value = 68
	POINT_RESIST_SWORD,				// point_value = 69
	POINT_RESIST_TWOHAND,			// point_value = 70
	POINT_RESIST_DAGGER,			// point_value = 71
	POINT_RESIST_BELL,				// point_value = 72
	POINT_RESIST_FAN,				// point_value = 73
	POINT_RESIST_BOW,				// point_value = 74
	POINT_RESIST_FIRE,				// point_value = 75
	POINT_RESIST_ELEC,				// point_value = 76
	POINT_RESIST_MAGIC,				// point_value = 77
	POINT_RESIST_WIND,				// point_value = 78
	POINT_REFLECT_MELEE,			// point_value = 79
	POINT_REFLECT_CURSE,			// point_value = 80
	POINT_POISON_REDUCE,			// point_value = 81
	POINT_KILL_SP_RECOVER,			// point_value = 82
	POINT_EXP_DOUBLE_BONUS,			// point_value = 83
	POINT_GOLD_DOUBLE_BONUS,		// point_value = 84
	POINT_ITEM_DROP_BONUS,			// point_value = 85
	POINT_POTION_BONUS,				// point_value = 86
	POINT_KILL_HP_RECOVERY,			// point_value = 87
	POINT_IMMUNE_STUN,				// point_value = 88
	POINT_IMMUNE_SLOW,				// point_value = 89
	POINT_IMMUNE_FALL,				// point_value = 90
	POINT_PARTY_ATTACKER_BONUS,		// point_value = 91
	POINT_PARTY_TANKER_BONUS,		// point_value = 92
	POINT_ATT_BONUS,				// point_value = 93
	POINT_DEF_BONUS,				// point_value = 94
	POINT_ATT_GRADE_BONUS,			// point_value = 95
	POINT_DEF_GRADE_BONUS,			// point_value = 96
	POINT_MAGIC_ATT_GRADE_BONUS,	// point_value = 97
	POINT_MAGIC_DEF_GRADE_BONUS,	// point_value = 98
	POINT_RESIST_NORMAL_DAMAGE,		// point_value = 99
	POINT_HIT_HP_RECOVERY,			// point_value = 100
	POINT_HIT_SP_RECOVERY,			// point_value = 101
	POINT_MANASHIELD,				// point_value = 102
	POINT_PARTY_BUFFER_BONUS,		// point_value = 103
	POINT_PARTY_SKILL_MASTER_BONUS,	// point_value = 104
	POINT_HP_RECOVER_CONTINUE,		// point_value = 105
	POINT_SP_RECOVER_CONTINUE,		// point_value = 106
	POINT_STEAL_GOLD,				// point_value = 107 
	POINT_POLYMORPH,				// point_value = 108
	POINT_MOUNT,					// point_value = 109
	POINT_PARTY_HASTE_BONUS,		// point_value = 110
	POINT_PARTY_DEFENDER_BONUS,		// point_value = 111
	POINT_STAT_RESET_COUNT,			// point_value = 112
	POINT_HORSE_SKILL,				// point_value = 113
	POINT_MALL_ATTBONUS,			// point_value = 114
	POINT_MALL_DEFBONUS,			// point_value = 115
	POINT_MALL_EXPBONUS,			// point_value = 116
	POINT_MALL_ITEMBONUS,			// point_value = 117
	POINT_MALL_GOLDBONUS,			// point_value = 118
	POINT_MAX_HP_PCT,				// point_value = 119
	POINT_MAX_SP_PCT,				// point_value = 120
	POINT_SKILL_DAMAGE_BONUS,		// point_value = 121
	POINT_NORMAL_HIT_DAMAGE_BONUS,	// point_value = 122
	POINT_SKILL_DEFEND_BONUS,		// point_value = 123
	POINT_NORMAL_HIT_DEFEND_BONUS,	// point_value = 124
	POINT_PC_BANG_EXP_BONUS,		// point_value = 125
	POINT_PC_BANG_DROP_BONUS,		// point_value = 126
	POINT_RAMADAN_CANDY_BONUS_EXP,	// point_value = 127
	POINT_ENERGY,					// point_value = 128
	POINT_ENERGY_END_TIME,			// point_value = 129
	POINT_COSTUME_ATTR_BONUS,		// point_value = 130
	POINT_MAGIC_ATT_BONUS_PER,		// point_value = 131
	POINT_MELEE_MAGIC_ATT_BONUS_PER,// point_value = 132
	POINT_RESIST_ICE,				// point_value = 133
	POINT_RESIST_EARTH,				// point_value = 134
	POINT_RESIST_DARK,				// point_value = 135
	POINT_RESIST_CRITICAL,			// point_value = 136
	POINT_RESIST_PENETRATE,			// point_value = 137
	POINT_BLEEDING_PCT,				// point_value = 138
	POINT_BLEEDING_REDUCE,			// point_value = 139
	POINT_ATTBONUS_WOLFMAN,			// point_value = 140
	POINT_RESIST_WOLFMAN,			// point_value = 141
	POINT_RESIST_CLAW,				// point_value = 142
#ifdef __ANTI_RESIST_MAGIC_BONUS__
	POINT_ANTI_RESIST_MAGIC = 143,		// Anti Magic Resistance;
#endif
#ifdef ENABLE_CHEQUE_SYSTEM
	POINT_CHEQUE = 144,					// point_value = 144
#endif
};

enum EPKModes
{
	PK_MODE_PEACE,
	PK_MODE_REVENGE,
	PK_MODE_FREE,
	PK_MODE_PROTECT,
	PK_MODE_GUILD,
	PK_MODE_MAX_NUM
};

enum EPositions
{
	POS_DEAD,
	POS_SLEEPING,
	POS_RESTING,
	POS_SITTING,
	POS_FISHING,
	POS_FIGHTING,
	POS_MOUNTING,
	POS_STANDING
};

enum EBlockAction
{
	BLOCK_EXCHANGE		= (1 << 0),
	BLOCK_PARTY_INVITE		= (1 << 1),
	BLOCK_GUILD_INVITE		= (1 << 2),
	BLOCK_WHISPER		= (1 << 3),
	BLOCK_MESSENGER_INVITE	= (1 << 4),
	BLOCK_PARTY_REQUEST		= (1 << 5),
};

// <Factor> Dynamically evaluated CHARACTER* equivalent.
// Referring to SCharDeadEventInfo.
struct DynamicCharacterPtr {
	DynamicCharacterPtr() : is_pc(false), id(0) {}
	DynamicCharacterPtr(const DynamicCharacterPtr& o)
		: is_pc(o.is_pc), id(o.id) {}

	// Returns the LPCHARACTER found in CHARACTER_MANAGER.
	LPCHARACTER Get() const; 
	// Clears the current settings.
	void Reset() {
		is_pc = false;
		id = 0;
	}

	// Basic assignment operator.
	DynamicCharacterPtr& operator=(const DynamicCharacterPtr& rhs) {
		is_pc = rhs.is_pc;
		id = rhs.id;
		return *this;
	}
	// Supports assignment with LPCHARACTER type.
	DynamicCharacterPtr& operator=(LPCHARACTER character);
	// Supports type casting to LPCHARACTER.
	operator LPCHARACTER() const {
		return Get();
	}

	bool is_pc;
	uint32_t id;
};

/* �����ϴ� ������ */
typedef struct character_point
{
	long			points[POINT_MAX_NUM];

	BYTE			job;
	BYTE			voice;

	BYTE			level;
	DWORD			exp;
	long			gold;
#ifdef ENABLE_CHEQUE_SYSTEM
	long			cheque;
#endif

	int				hp;
	int				sp;

	int				iRandomHP;
	int				iRandomSP;

	int				stamina;

	BYTE			skill_group;
} CHARACTER_POINT;

/* ������� �ʴ� ĳ���� ������ */
typedef struct character_point_instant
{
	long			points[POINT_MAX_NUM];

	float			fRot;

	int				iMaxHP;
	int				iMaxSP;

	long			position;

	long			instant_flag;
	DWORD			dwAIFlag;
	DWORD			dwImmuneFlag;
	DWORD			dwLastShoutPulse;

	WORD			parts[PART_MAX_NUM];

	LPITEM			pItems[INVENTORY_AND_EQUIP_SLOT_MAX];
	BYTE			bItemGrid[INVENTORY_AND_EQUIP_SLOT_MAX];

	// ��ȥ�� �κ��丮.
	LPITEM			pDSItems[DRAGON_SOUL_INVENTORY_MAX_NUM];
	WORD			wDSItemGrid[DRAGON_SOUL_INVENTORY_MAX_NUM];

	// by mhh
	LPITEM			pCubeItems[CUBE_MAX_NUM];
	LPCHARACTER		pCubeNpc;
#ifdef __SASH_SYSTEM__
	LPITEM	pSashMaterials[SASH_WINDOW_MAX_MATERIALS];
#endif
#ifdef __CHANGELOOK_SYSTEM__
	LPITEM	pClMaterials[CL_WINDOW_MAX_MATERIALS];
#endif
	LPITEM			pAttrTransferItems[MAX_ATTR_TRANSFER_SLOT];
	LPCHARACTER		pAttrTransferNpc;

	LPCHARACTER			battle_victim;

	BYTE			gm_level;

	BYTE			bBasePart;	// ��� ��ȣ

	int				iMaxStamina;

	BYTE			bBlockMode;

	int				iDragonSoulActiveDeck;
	LPENTITY		m_pDragonSoulRefineWindowOpener;
	DWORD			real_owner;
	bool			isOfflineShop;
	int				leftTime;
	BYTE			bSaveTime;
	BYTE			bChannel;
	DWORD			dwVID;
} CHARACTER_POINT_INSTANT;

#define TRIGGERPARAM		LPCHARACTER ch, LPCHARACTER causer

typedef struct trigger
{
	BYTE	type;
	int		(*func) (TRIGGERPARAM);
	long	value;
} TRIGGER;

class CTrigger
{
	public:
		CTrigger() : bType(0), pFunc(NULL)
		{
		}

		BYTE	bType;
		int	(*pFunc) (TRIGGERPARAM);
};

EVENTINFO(char_event_info)
{
	DynamicCharacterPtr ch;
};

struct TSkillUseInfo
{
	int	    iHitCount;
	int	    iMaxHitCount;
	int	    iSplashCount;
	DWORD   dwNextSkillUsableTime;
	int	    iRange;
	bool    bUsed;
	DWORD   dwVID;
	bool    isGrandMaster;

	boost::unordered_map<VID, size_t> TargetVIDMap;

	TSkillUseInfo()
		: iHitCount(0), iMaxHitCount(0), iSplashCount(0), dwNextSkillUsableTime(0), iRange(0), bUsed(false),
		dwVID(0), isGrandMaster(false)
   	{}

	bool    HitOnce(DWORD dwVnum = 0);

	bool    UseSkill(bool isGrandMaster, DWORD vid, DWORD dwCooltime, int splashcount = 1, int hitcount = -1, int range = -1);
	DWORD   GetMainTargetVID() const	{ return dwVID; }
	void    SetMainTargetVID(DWORD vid) { dwVID=vid; }
	void    ResetHitCount() { if (iSplashCount) { iHitCount = iMaxHitCount; iSplashCount--; } }
};

typedef struct packet_party_update TPacketGCPartyUpdate;
class CExchange;
class CSkillProto;
class CParty;
class CDungeon;
class CWarMap;
class CAffect;
class CGuild;
class CSafebox;
class CArena;

class CShop;
typedef class CShop * LPSHOP;

class COfflineShop;
typedef class COfflineShop * LPOFFLINESHOP;

class CMob;
class CMobInstance;
typedef struct SMobSkillInfo TMobSkillInfo;

//SKILL_POWER_BY_LEVEL
extern int GetSkillPowerByLevelFromType(int job, int skillgroup, int skilllevel);
//END_SKILL_POWER_BY_LEVEL

namespace marriage
{
	class WeddingMap;
}
enum e_overtime
{
	OT_NONE,
	OT_3HOUR,
	OT_5HOUR,
};

class CHARACTER : public CEntity, public CFSM, public CHorseRider
{
	protected:
		//////////////////////////////////////////////////////////////////////////////////
		// Entity ����
		virtual void	EncodeInsertPacket(LPENTITY entity);
		virtual void	EncodeRemovePacket(LPENTITY entity);
		//////////////////////////////////////////////////////////////////////////////////

	public:
		LPCHARACTER			FindCharacterInView(const char * name, bool bFindPCOnly);
		void				UpdatePacket();

		//////////////////////////////////////////////////////////////////////////////////
		// FSM (Finite State Machine) ����
	protected:
		CStateTemplate<CHARACTER>	m_stateMove;
		CStateTemplate<CHARACTER>	m_stateBattle;
		CStateTemplate<CHARACTER>	m_stateIdle;

	public:
		virtual void		StateMove();
		virtual void		StateBattle();
		virtual void		StateIdle();
		virtual void		StateFlag();
		virtual void		StateFlagBase();
		void				StateHorse();

	protected:
		// STATE_IDLE_REFACTORING
		void				__StateIdle_Monster();
		void				__StateIdle_Stone();
		void				__StateIdle_NPC();
		// END_OF_STATE_IDLE_REFACTORING

	public:
		DWORD GetAIFlag() const	{ return m_pointsInstant.dwAIFlag; }
	
		void				SetAggressive();
		bool				IsAggressive() const;

		void				SetCoward();
		bool				IsCoward() const;
		void				CowardEscape();

		void				SetNoAttackShinsu();
		bool				IsNoAttackShinsu() const;

		void				SetNoAttackChunjo();
		bool				IsNoAttackChunjo() const;

		void				SetNoAttackJinno();
		bool				IsNoAttackJinno() const;

		void				SetAttackMob();
		bool				IsAttackMob() const;

		virtual void			BeginStateEmpty();
		virtual void			EndStateEmpty() {}

		void				RestartAtSamePos();

	protected:
		DWORD				m_dwStateDuration;
		//////////////////////////////////////////////////////////////////////////////////

	public:
		CHARACTER();
		virtual ~CHARACTER();

		void			Create(const char * c_pszName, DWORD vid, bool isPC);
		void			Destroy();

		void			Disconnect(const char * c_pszReason);

	protected:
		void			Initialize();

		//////////////////////////////////////////////////////////////////////////////////
		// Basic Points
#ifdef __SEND_TARGET_INFO__
	private:
		DWORD			dwLastTargetInfoPulse;

	public:
		DWORD			GetLastTargetInfoPulse() const	{ return dwLastTargetInfoPulse; }
		void			SetLastTargetInfoPulse(DWORD pulse) { dwLastTargetInfoPulse = pulse; }
#endif
	public:
		DWORD			GetPlayerID() const	{ return m_dwPlayerID; }

		void			SetPlayerProto(const TPlayerTable * table);
		void			CreatePlayerProto(TPlayerTable & tab);	// ���� �� ���

		void			SetProto(const CMob * c_pkMob);
		WORD			GetRaceNum() const;

		void			Save();		// DelayedSave
		void			SaveReal();	// ���� ����
		void			FlushDelayedSaveItem();

		const char *	GetName() const;
#ifdef ENABLE_YMIR_AFFECT_FIX
		bool			CheckTimeUsed(LPITEM item);
#endif
		const VID &		GetVID() const		{ return m_vid;		}

		void			SetName(const std::string& name) { m_stName = name; }

		void			SetRace(BYTE race);
		bool			ChangeSex();

		DWORD			GetAID() const;
		DWORD			yeniBirim_miktar();
		void			yeniBirim_guncelle(DWORD yeniBirim);
		void			EnYakinIsinlayici();
		#ifdef ENABLE_SHOP_SISTEM
		DWORD			Ep_Miktar();
		void			Set_Ep(DWORD black);
		void			Refresh_Ep();
		#endif
		int				GetChangeEmpireCount() const;
		void			SetChangeEmpireCount();
		int				ChangeEmpire(BYTE empire);

		BYTE			GetJob() const;
		BYTE			GetCharType() const;

		bool			IsPC() const		{ return GetDesc() ? true : false; }
		bool			IsNPC()	const		{ return m_bCharType != CHAR_TYPE_PC; }
		bool			IsMonster()	const	{ return m_bCharType == CHAR_TYPE_MONSTER; }
		bool			IsStone() const		{ return m_bCharType == CHAR_TYPE_STONE; }
		bool			IsDoor() const		{ return m_bCharType == CHAR_TYPE_DOOR; } 
		bool			IsBuilding() const	{ return m_bCharType == CHAR_TYPE_BUILDING;  }
		bool			IsWarp() const		{ return m_bCharType == CHAR_TYPE_WARP; }
		bool			IsGoto() const		{ return m_bCharType == CHAR_TYPE_GOTO; }
//		bool			IsPet() const		{ return m_bCharType == CHAR_TYPE_PET; }

		DWORD			GetLastShoutPulse() const	{ return m_pointsInstant.dwLastShoutPulse; }
		void			SetLastShoutPulse(DWORD pulse) { m_pointsInstant.dwLastShoutPulse = pulse; }
		int				GetLevel() const		{ return m_points.level;	}
		void			SetLevel(BYTE level);

		BYTE			GetGMLevel() const;
		BOOL 			IsGM() const;
		void			SetGMLevel(); 

		DWORD			GetExp() const		{ return m_points.exp;	}
		void			SetExp(DWORD exp)	{ m_points.exp = exp;	}
		bool			blockExp;  // block exp
#ifdef NEW_PET_SYSTEM
		DWORD			PetGetNextExp() const;
#endif
		DWORD			GetNextExp() const;
		LPCHARACTER		DistributeExp();	// ���� ���� ���� ����� �����Ѵ�.
		void			DistributeHP(LPCHARACTER pkKiller);
		void			DistributeSP(LPCHARACTER pkKiller, int iMethod=0);

		void			SetPosition(int pos);
		bool			IsPosition(int pos) const	{ return m_pointsInstant.position == pos ? true : false; }
		int				GetPosition() const		{ return m_pointsInstant.position; }

		void			SetPart(BYTE bPartPos, WORD wVal);
		WORD			GetPart(BYTE bPartPos) const;
		WORD			GetOriginalPart(BYTE bPartPos) const;

		void			SetHP(int hp)		{ m_points.hp = hp; }
		int				GetHP() const		{ return m_points.hp; }

		void			SetSP(int sp)		{ m_points.sp = sp; }
		int				GetSP() const		{ return m_points.sp; }

		int				LastDropTime;
		int				CountDrops;

		void			SetStamina(int stamina)	{ m_points.stamina = stamina; }
		int				GetStamina() const		{ return m_points.stamina; }

		void			SetMaxHP(int iVal)	{ m_pointsInstant.iMaxHP = iVal; }
		int				GetMaxHP() const	{ return m_pointsInstant.iMaxHP; }

		void			SetMaxSP(int iVal)	{ m_pointsInstant.iMaxSP = iVal; }
		int				GetMaxSP() const	{ return m_pointsInstant.iMaxSP; }

		void			SetMaxStamina(int iVal)	{ m_pointsInstant.iMaxStamina = iVal; }
		int				GetMaxStamina() const	{ return m_pointsInstant.iMaxStamina; }

		void			SetRandomHP(int v)	{ m_points.iRandomHP = v; }
		void			SetRandomSP(int v)	{ m_points.iRandomSP = v; }

		int				GetRandomHP() const	{ return m_points.iRandomHP; }
		int				GetRandomSP() const	{ return m_points.iRandomSP; }

		int				GetHPPct() const;

		void			SetRealPoint(BYTE idx, int val);
		int				GetRealPoint(BYTE idx) const;

		void			SetPoint(BYTE idx, int val);
		int				GetPoint(BYTE idx) const;
		int				GetLimitPoint(BYTE idx) const;
		int				GetPolymorphPoint(BYTE idx) const;

		const TMobTable &	GetMobTable() const;
		BYTE				GetMobRank() const;
		BYTE				GetMobBattleType() const;
		BYTE				GetMobSize() const;
		DWORD				GetMobDamageMin() const;
		DWORD				GetMobDamageMax() const;
		WORD				GetMobAttackRange() const;
		DWORD				GetMobDropItemVnum() const;
		float				GetMobDamageMultiply() const;

		// NEWAI
		bool			IsBerserker() const;
		bool			IsBerserk() const;
		void			SetBerserk(bool mode);

		bool			IsStoneSkinner() const;

		bool			IsGodSpeeder() const;
		bool			IsGodSpeed() const;
		void			SetGodSpeed(bool mode);

		bool			IsDeathBlower() const;
		bool			IsDeathBlow() const;

		bool			IsReviver() const;
		bool			HasReviverInParty() const;
		bool			IsRevive() const;
		void			SetRevive(bool mode);
		// NEWAI END

		bool			IsRaceFlag(DWORD dwBit) const;
		bool			IsSummonMonster() const;
		DWORD			GetSummonVnum() const;

		DWORD			GetPolymorphItemVnum() const;
		DWORD			GetMonsterDrainSPPoint() const;

		void			MainCharacterPacket();	// ���� ����ĳ���Ͷ�� �����ش�.

		void			ComputePoints();
		void			ComputeBattlePoints();
		void			PointChange(BYTE type, int amount, bool bAmount = false, bool bBroadcast = false);
		void			PointsPacket();
		void			ApplyPoint(BYTE bApplyType, int iVal);
#ifdef NEW_PET_SYSTEM
		void			SendPetLevelUpEffect(int vid, int type, int value, int amount);
#endif
		void			CheckMaximumPoints();	// HP, SP ���� ���� ���� �ִ밪 ���� ������ �˻��ϰ� ���ٸ� �����.

		bool			Show(long lMapIndex, long x, long y, long z = LONG_MAX, bool bShowSpawnMotion = false);

		void			Sitdown(int is_ground);
		void			Standup();

		void			SetRotation(float fRot);
		void			SetRotationToXY(long x, long y);
		float			GetRotation() const	{ return m_pointsInstant.fRot; }

		void			MotionPacketEncode(BYTE motion, LPCHARACTER victim, struct packet_motion * packet);
		void			Motion(BYTE motion, LPCHARACTER victim = NULL);

		void			ChatPacket(BYTE type, const char *format, ...);
		void			MonsterChat(BYTE bMonsterChatType);
		void			SendGreetMessage();

		void			ResetPoint(int iLv);

		void			SetBlockMode(BYTE bFlag);
		void			SetBlockModeForce(BYTE bFlag);
		bool			IsBlockMode(BYTE bFlag) const	{ return (m_pointsInstant.bBlockMode & bFlag)?true:false; }

		bool			IsPolymorphed() const		{ return m_dwPolymorphRace>0; }
		bool			IsPolyMaintainStat() const	{ return m_bPolyMaintainStat; } // ���� ������ �����ϴ� ��������.
		void			SetPolymorph(DWORD dwRaceNum, bool bMaintainStat = false);
		DWORD			GetPolymorphVnum() const	{ return m_dwPolymorphRace; }
		int				GetPolymorphPower() const;

		// FISING	
		void			fishing();
		void			fishing_take();
		// END_OF_FISHING

		// MINING
		void			mining(LPCHARACTER chLoad);
		void			mining_cancel();
		void			mining_take();
		// END_OF_MINING

		void			ResetPlayTime(DWORD dwTimeRemain = 0);

		void			CreateFly(BYTE bType, LPCHARACTER pkVictim);

		void			ResetChatCounter();
		BYTE			IncreaseChatCounter();
		BYTE			GetChatCounter() const;

	protected:
		DWORD			m_dwPolymorphRace;
		bool			m_bPolyMaintainStat;
		DWORD			m_dwLoginPlayTime;
		DWORD			m_dwPlayerID;
		VID				m_vid;
		std::string		m_stName;
#ifdef NEW_PET_SYSTEM
		BYTE			m_stImmortalSt;
#endif
		BYTE			m_bCharType;
#ifdef NEW_PET_SYSTEM
		DWORD			m_newpetskillcd[3];
#endif

		CHARACTER_POINT		m_points;
		CHARACTER_POINT_INSTANT	m_pointsInstant;

		int				m_iMoveCount;
		DWORD			m_dwPlayStartTime;
		BYTE			m_bAddChrState;
		bool			m_bSkipSave;
		std::string		m_stMobile;
		char			m_szMobileAuth[5];
		BYTE			m_bChatCounter;

		// End of Basic Points

		//////////////////////////////////////////////////////////////////////////////////
		// Move & Synchronize Positions
		//////////////////////////////////////////////////////////////////////////////////
	public:
		bool			IsStateMove() const			{ return IsState((CState&)m_stateMove); }
		bool			IsStateIdle() const			{ return IsState((CState&)m_stateIdle); }
		bool			IsWalking() const			{ return m_bNowWalking || GetStamina()<=0; }
		void			SetWalking(bool bWalkFlag)	{ m_bWalking=bWalkFlag; }
		void			SetNowWalking(bool bWalkFlag);	
		void			ResetWalking()			{ SetNowWalking(m_bWalking); }

		bool			Goto(long x, long y);	// �ٷ� �̵� ��Ű�� �ʰ� ��ǥ ��ġ�� BLENDING ��Ų��.
		void			Stop();

		bool			CanMove() const;		// �̵��� �� �ִ°�?

		void			SyncPacket();
		bool			Sync(long x, long y);	// ���� �� �޼ҵ�� �̵� �Ѵ� (�� �� ���ǿ� ���� �̵� �Ұ��� ����)
		bool			Move(long x, long y);	// ������ �˻��ϰ� Sync �޼ҵ带 ���� �̵� �Ѵ�.
		void			OnMove(bool bIsAttack = false);	// �����϶� �Ҹ���. Move() �޼ҵ� �̿ܿ����� �Ҹ� �� �ִ�.
		DWORD			GetMotionMode() const;
		float			GetMoveMotionSpeed() const;
		float			GetMoveSpeed() const;
		void			CalculateMoveDuration();
		void			SendMovePacket(BYTE bFunc, BYTE bArg, DWORD x, DWORD y, DWORD dwDuration, DWORD dwTime=0, int iRot=-1);
		DWORD			GetCurrentMoveDuration() const	{ return m_dwMoveDuration; }
		DWORD			GetWalkStartTime() const	{ return m_dwWalkStartTime; }
		DWORD			GetLastMoveTime() const		{ return m_dwLastMoveTime; }
		DWORD			GetLastAttackTime() const	{ return m_dwLastAttackTime; }

		void			SetLastAttacked(DWORD time);	// ���������� ���ݹ��� �ð� �� ��ġ�� ������

		bool			SetSyncOwner(LPCHARACTER ch, bool bRemoveFromList = true);
		bool			IsSyncOwner(LPCHARACTER ch) const;

		bool			WarpSet(long x, long y, long lRealMapIndex = 0);
		void			SetWarpLocation(long lMapIndex, long x, long y);
		void			WarpEnd();
		const PIXEL_POSITION & GetWarpPosition() const { return m_posWarp; }
		bool			WarpToPID(DWORD dwPID);

		void			SaveExitLocation();
		void			ExitToSavedLocation();

		void			StartStaminaConsume();
		void			StopStaminaConsume();
		bool			IsStaminaConsume() const;
		bool			IsStaminaHalfConsume() const;

		void			ResetStopTime();
		DWORD			GetStopTime() const;

	protected:
		void			ClearSync();

		float			m_fSyncTime;
		LPCHARACTER		m_pkChrSyncOwner;
		CHARACTER_LIST	m_kLst_pkChrSyncOwned;	// ���� SyncOwner�� �ڵ�

		PIXEL_POSITION	m_posDest;
		PIXEL_POSITION	m_posStart;
		PIXEL_POSITION	m_posWarp;
		long			m_lWarpMapIndex;

		PIXEL_POSITION	m_posExit;
		long			m_lExitMapIndex;

		DWORD			m_dwMoveStartTime;
		DWORD			m_dwMoveDuration;

		DWORD			m_dwLastMoveTime;
		DWORD			m_dwLastAttackTime;
		DWORD			m_dwWalkStartTime;
		DWORD			m_dwStopTime;

		bool			m_bWalking;
		bool			m_bNowWalking;
		bool			m_bStaminaConsume;
		// End

		// Quickslot ����
	public:
		void			SyncQuickslot(BYTE bType, BYTE bOldPos, BYTE bNewPos);
		bool			GetQuickslot(BYTE pos, TQuickslot ** ppSlot);
		bool			SetQuickslot(BYTE pos, TQuickslot & rSlot);
		bool			DelQuickslot(BYTE pos);
		bool			SwapQuickslot(BYTE a, BYTE b);
		void			ChainQuickslotItem(LPITEM pItem, BYTE bType, BYTE bOldPos);

	protected:
		TQuickslot		m_quickslot[QUICKSLOT_MAX_NUM];

		////////////////////////////////////////////////////////////////////////////////////////
		// Affect
	public:
		void			StartAffectEvent();
		void			ClearAffect(bool bSave=false);
		void			ComputeAffect(CAffect * pkAff, bool bAdd);
		bool			AddAffect(DWORD dwType, BYTE bApplyOn, long lApplyValue, DWORD dwFlag, long lDuration, long lSPCost, bool bOverride, bool IsCube = false);
		void			RefreshAffect();
		bool			RemoveAffect(DWORD dwType);
		bool			IsAffectFlag(DWORD dwAff) const;

		bool			UpdateAffect();	// called from EVENT
		int				ProcessAffect();

		void			LoadAffect(DWORD dwCount, TPacketAffectElement * pElements);
		void			SaveAffect();

		// Affect loading�� ���� �����ΰ�?
		bool			IsLoadedAffect() const	{ return m_bIsLoadedAffect; }		

		bool			IsGoodAffect(BYTE bAffectType) const;

		void			RemoveGoodAffect();
		void			RemoveBadAffect();

		CAffect *		FindAffect(DWORD dwType, BYTE bApply=APPLY_NONE) const;
		const std::list<CAffect *> & GetAffectContainer() const	{ return m_list_pkAffect; }
		bool			RemoveAffect(CAffect * pkAff);

	protected:
		bool			m_bIsLoadedAffect;
		TAffectFlag		m_afAffectFlag;
		std::list<CAffect *>	m_list_pkAffect;

	public:
		// PARTY_JOIN_BUG_FIX
		void			SetParty(LPPARTY pkParty);
		LPPARTY			GetParty() const	{ return m_pkParty; }

		bool			RequestToParty(LPCHARACTER leader);
		void			DenyToParty(LPCHARACTER member);
		void			AcceptToParty(LPCHARACTER member);

		/// �ڽ��� ��Ƽ�� �ٸ� character �� �ʴ��Ѵ�.
		/**
		 * @param	pchInvitee �ʴ��� ��� character. ��Ƽ�� ���� ������ �����̾�� �Ѵ�.
		 *
		 * ���� character �� ���°� ��Ƽ�� �ʴ��ϰ� �ʴ���� �� �ִ� ���°� �ƴ϶�� �ʴ��ϴ� ĳ���Ϳ��� �ش��ϴ� ä�� �޼����� �����Ѵ�.
		 */
		void			PartyInvite(LPCHARACTER pchInvitee);

		/// �ʴ��ߴ� character �� ������ ó���Ѵ�.
		/**
		 * @param	pchInvitee ��Ƽ�� ������ character. ��Ƽ�� ���������� �����̾�� �Ѵ�.
		 *
		 * pchInvitee �� ��Ƽ�� ������ �� �ִ� ��Ȳ�� �ƴ϶�� �ش��ϴ� ä�� �޼����� �����Ѵ�.
		 */
		void			PartyInviteAccept(LPCHARACTER pchInvitee);

		/// �ʴ��ߴ� character �� �ʴ� �źθ� ó���Ѵ�.
		/**
		 * @param [in]	dwPID �ʴ� �ߴ� character �� PID
		 */
		void			PartyInviteDeny(DWORD dwPID);

		bool			BuildUpdatePartyPacket(TPacketGCPartyUpdate & out);
		int				GetLeadershipSkillLevel() const;

		bool			CanSummon(int iLeaderShip);

		void			SetPartyRequestEvent(LPEVENT pkEvent) { m_pkPartyRequestEvent = pkEvent; }

	protected:

		/// ��Ƽ�� �����Ѵ�.
		/**
		 * @param	pkLeader ������ ��Ƽ�� ����
		 */
		void			PartyJoin(LPCHARACTER pkLeader);

		/**
		 * ��Ƽ ������ �� �� ���� ����� �����ڵ�.
		 * Error code �� �ð��� �������ΰ��� ���� ���氡����(mutable) type �� ����(static) type ���� ������.
		 * Error code �� ���� PERR_SEPARATOR ���� ������ ���氡���� type �̰� ������ ���� type �̴�.
		 */
		enum PartyJoinErrCode {
			PERR_NONE		= 0,	///< ó������
			PERR_SERVER,			///< ���������� ��Ƽ���� ó�� �Ұ�
			PERR_DUNGEON,			///< ĳ���Ͱ� ������ ����
			PERR_OBSERVER,			///< ���������
			PERR_LVBOUNDARY,		///< ��� ĳ���Ϳ� �������̰� ��
			PERR_LOWLEVEL,			///< �����Ƽ�� �ְ������� 30���� ����
			PERR_HILEVEL,			///< �����Ƽ�� ������������ 30���� ����
			PERR_ALREADYJOIN,		///< ��Ƽ���� ��� ĳ���Ͱ� �̹� ��Ƽ��
			PERR_PARTYISFULL,		///< ��Ƽ�ο� ���� �ʰ�
			PERR_SEPARATOR,			///< Error type separator.
			PERR_DIFFEMPIRE,		///< ��� ĳ���Ϳ� �ٸ� ������
			PERR_MAX				///< Error code �ְ�ġ. �� �տ� Error code �� �߰��Ѵ�.
		};

		/// ��Ƽ �����̳� �Ἲ ������ ������ �˻��Ѵ�.
		/**
		 * @param 	pchLeader ��Ƽ�� leader �̰ų� �ʴ��� character
		 * @param	pchGuest �ʴ�޴� character
		 * @return	��� PartyJoinErrCode �� ��ȯ�� �� �ִ�.
		 */
		static PartyJoinErrCode	IsPartyJoinableCondition(const LPCHARACTER pchLeader, const LPCHARACTER pchGuest);

		/// ��Ƽ �����̳� �Ἲ ������ ������ ������ �˻��Ѵ�.
		/**
		 * @param 	pchLeader ��Ƽ�� leader �̰ų� �ʴ��� character
		 * @param	pchGuest �ʴ�޴� character
		 * @return	mutable type �� code �� ��ȯ�Ѵ�.
		 */
		static PartyJoinErrCode	IsPartyJoinableMutableCondition(const LPCHARACTER pchLeader, const LPCHARACTER pchGuest);

		LPPARTY			m_pkParty;
		DWORD			m_dwLastDeadTime;
		LPEVENT			m_pkPartyRequestEvent;

		/**
		 * ��Ƽ��û Event map.
		 * key: �ʴ���� ĳ������ PID
		 * value: event�� pointer
		 *
		 * �ʴ��� ĳ���͵鿡 ���� event map.
		 */
		typedef std::map< DWORD, LPEVENT >	EventMap;
		EventMap		m_PartyInviteEventMap;
#ifdef WJ_SHOW_STROKE_INFO
		std::map<DWORD, DWORD>		m_CharacterStrokeInfo;
#endif

		// END_OF_PARTY_JOIN_BUG_FIX

		////////////////////////////////////////////////////////////////////////////////////////
		// Dungeon
	public:
		void			SetDungeon(LPDUNGEON pkDungeon);
		LPDUNGEON		GetDungeon() const	{ return m_pkDungeon; }
		LPDUNGEON		GetDungeonForce() const;
	protected:
		LPDUNGEON	m_pkDungeon;
		int			m_iEventAttr;

		////////////////////////////////////////////////////////////////////////////////////////
		// Guild
	public:
		void			SetGuild(CGuild * pGuild);
		CGuild*			GetGuild() const	{ return m_pGuild; }

		void			SetWarMap(CWarMap* pWarMap);
		CWarMap*		GetWarMap() const	{ return m_pWarMap; }

	protected:
		CGuild *		m_pGuild;
		DWORD			m_dwUnderGuildWarInfoMessageTime;
		CWarMap *		m_pWarMap;

		////////////////////////////////////////////////////////////////////////////////////////
		// Item related
	public:
		bool			CanHandleItem(bool bSkipRefineCheck = false, bool bSkipObserver = false); // ������ ���� ������ �� �� �ִ°�?

		bool			IsItemLoaded() const	{ return m_bItemLoaded; }
		void			SetItemLoaded()	{ m_bItemLoaded = true; }

		void			ClearItem();
#ifdef __HIGHLIGHT_SYSTEM__
		void			SetItem(TItemPos Cell, LPITEM item, bool isHighLight = false);
#else
		void			SetItem(TItemPos Cell, LPITEM item);
#endif
		LPITEM			GetItem(TItemPos Cell) const;
		LPITEM			GetInventoryItem(WORD wCell) const;
		bool			IsEmptyItemGrid(TItemPos Cell, BYTE size, int iExceptionCell = -1) const;

		void			SetWear(BYTE bCell, LPITEM item);
		LPITEM			GetWear(BYTE bCell) const;

		// MYSHOP_PRICE_LIST
		void			UseSilkBotary(void); 		/// ��� ������ �������� ���

		/// DB ĳ�÷� ���� �޾ƿ� �������� ����Ʈ�� �������� �����ϰ� ������ ������ ����� ó���Ѵ�.
		/**
		 * @param [in] p	�������� ����Ʈ ��Ŷ
		 *
		 * ������ �� ó�� ��� ������ ������ ��� �� UseSilkBotary ���� DB ĳ�÷� �������� ����Ʈ�� ��û�ϰ�
		 * ������� ������ �� �Լ����� ���� ��ܺ����� ����� ó���Ѵ�.
		 */
		void			UseSilkBotaryReal(const TPacketMyshopPricelistHeader* p);
		// END_OF_MYSHOP_PRICE_LIST

		bool			UseItemEx(LPITEM item, TItemPos DestCell);
		bool			UseItem(TItemPos Cell, TItemPos DestCell = NPOS);

		// ADD_REFINE_BUILDING
		bool			IsRefineThroughGuild() const;
		CGuild *		GetRefineGuild() const;
		int				ComputeRefineFee(int iCost, int iMultiply = 5) const;
		void			PayRefineFee(int iTotalMoney);
		void			SetRefineNPC(LPCHARACTER ch);
		// END_OF_ADD_REFINE_BUILDING

		bool			RefineItem(LPITEM pkItem, LPITEM pkTarget);
		bool			DropItem(TItemPos Cell,  BYTE bCount=0);
		bool			DestroyItem(TItemPos Cell);
		bool			SellItem(TItemPos Cell);
		bool			GiveRecallItem(LPITEM item);
		void			ProcessRecallItem(LPITEM item);

		//	void			PotionPacket(int iPotionType);
		void			EffectPacket(int enumEffectType);
		void			SpecificEffectPacket(const char filename[128]);

		// ADD_MONSTER_REFINE
		bool			DoRefine(LPITEM item, bool bMoneyOnly = false);
		// END_OF_ADD_MONSTER_REFINE

		bool			DoRefineWithScroll(LPITEM item);
		bool			RefineInformation(BYTE bCell, BYTE bType, int iAdditionalCell = -1);

		void			SetRefineMode(int iAdditionalCell = -1);
		void			ClearRefineMode();

		bool			GiveItem(LPCHARACTER victim, TItemPos Cell);
		bool			CanReceiveItem(LPCHARACTER from, LPITEM item) const;
		void			ReceiveItem(LPCHARACTER from, LPITEM item);
		bool			GiveItemFromSpecialItemGroup(DWORD dwGroupNum, std::vector <DWORD> &dwItemVnums, 
							std::vector <DWORD> &dwItemCounts, std::vector <LPITEM> &item_gets, int &count);

		bool			MoveItem(TItemPos pos, TItemPos change_pos, BYTE num);
		bool			PickupItem(DWORD vid);
		bool			EquipItem(LPITEM item, int iCandidateCell = -1);
		bool			UnequipItem(LPITEM item);

		// ���� item�� ������ �� �ִ� �� Ȯ���ϰ�, �Ұ��� �ϴٸ� ĳ���Ϳ��� ������ �˷��ִ� �Լ�
		bool			CanEquipNow(const LPITEM item, const TItemPos& srcCell = NPOS, const TItemPos& destCell = NPOS);

		// �������� item�� ���� �� �ִ� �� Ȯ���ϰ�, �Ұ��� �ϴٸ� ĳ���Ϳ��� ������ �˷��ִ� �Լ�
		bool			CanUnequipNow(const LPITEM item, const TItemPos& srcCell = NPOS, const TItemPos& destCell = NPOS);

		bool			SwapItem(BYTE bCell, BYTE bDestCell);
		LPITEM			AutoGiveItem(DWORD dwItemVnum, BYTE bCount=1, int iRarePct = -1, bool bMsg = true);
		void			AutoGiveItem(LPITEM item, bool longOwnerShip = false);
		
		int				GetEmptyInventory(BYTE size) const;
		int				GetEmptyDragonSoulInventory(LPITEM pItem) const;
		void			CopyDragonSoulItemGrid(std::vector<WORD>& vDragonSoulItemGrid) const;

		int				CountEmptyInventory() const;

		int				CountSpecifyItem(DWORD vnum) const;
		void			RemoveSpecifyItem(DWORD vnum, DWORD count = 1);
		LPITEM			FindSpecifyItem(DWORD vnum) const;
		LPITEM			FindItemByID(DWORD id) const;

		int				CountSpecifyTypeItem(BYTE type) const;
		void			RemoveSpecifyTypeItem(BYTE type, DWORD count = 1);

		bool			IsEquipUniqueItem(DWORD dwItemVnum) const;

		// CHECK_UNIQUE_GROUP
		bool			IsEquipUniqueGroup(DWORD dwGroupVnum) const;
		// END_OF_CHECK_UNIQUE_GROUP

		void			SendEquipment(LPCHARACTER ch);
		// End of Item

	protected:

		/// �� �����ۿ� ���� ���������� �����Ѵ�.
		/**
		 * @param [in]	dwItemVnum ������ vnum
		 * @param [in]	dwItemPrice ������ ����
		 */
#ifdef ENABLE_CHEQUE_SYSTEM
		void			SendMyShopPriceListCmd(DWORD dwItemVnum, DWORD dwItemPrice, DWORD dwItemPriceCheque);
#else
		void			SendMyShopPriceListCmd(DWORD dwItemVnum, DWORD dwItemPrice);
#endif

		bool			m_bNoOpenedShop;	///< �̹� ���� �� ���λ����� �� ���� �ִ����� ����(������ ���� ���ٸ� true)

		bool			m_bItemLoaded;
		int				m_iRefineAdditionalCell;
		bool			m_bUnderRefine;
		DWORD			m_dwRefineNPCVID;

	public:
		////////////////////////////////////////////////////////////////////////////////////////
		// Money related
		INT				GetGold() const		{ return m_points.gold;	}
		void			SetGold(INT gold)	{ m_points.gold = gold;	}
		bool			DropGold(INT gold);
		INT				GetAllowedGold() const;
		void			GiveGold(INT iAmount);	// ��Ƽ�� ������ ��Ƽ �й�, �α� ���� ó��
#ifdef ENABLE_CHEQUE_SYSTEM
		INT				GetCheque() const		{ return m_points.cheque;	}
		void			SetCheque(INT cheque)	{ m_points.cheque = cheque; }
		bool			DropCheque(INT cheque);
		void			GiveCheque(INT iAmount);
#endif
		// End of Money

		////////////////////////////////////////////////////////////////////////////////////////
		// Shop related
	public:
		void			SetShop(LPSHOP pkShop);
		LPSHOP			GetShop() const { return m_pkShop; }
		void			ShopPacket(BYTE bSubHeader);

		void			SetShopOwner(LPCHARACTER ch) { m_pkChrShopOwner = ch; }
		LPCHARACTER		GetShopOwner() const { return m_pkChrShopOwner;}

		void			OpenMyShop(const char * c_pszSign, TShopItemTable * pTable, BYTE bItemCount);
		LPSHOP			GetMyShop() const { return m_pkMyShop; }
		void			CloseMyShop();

	protected:

		LPSHOP			m_pkShop;
		LPSHOP			m_pkMyShop;
		std::string		m_stShopSign;
		LPCHARACTER		m_pkChrShopOwner;
		// End of shop
		
		////////////////////////////////////////////////////////////////////////////////////////
		// OfflineShop related
	public:
		// Give me point
		void			SetOfflineShop(LPOFFLINESHOP pkOfflineShop);
		LPOFFLINESHOP	GetOfflineShop() const { return m_pkOfflineShop; }
		// Return owner
		void			SetOfflineShopOwner(LPCHARACTER ch) { m_pkChrOfflineShopOwner = ch; }
		LPCHARACTER		GetOfflineShopOwner() const { return m_pkChrOfflineShopOwner; }
		// Give me real owner
		void			SetOfflineShopRealOwner(DWORD dwVID) { m_pointsInstant.real_owner = dwVID; }
		DWORD			GetOfflineShopRealOwner() const { return m_pointsInstant.real_owner; }
		// Is Offline Shop NPC?
		void			SetOfflineShopNPC(bool flag) { m_pointsInstant.isOfflineShop = flag; }
		bool			IsOfflineShopNPC() const { return m_pointsInstant.isOfflineShop; }
		// Open My Offline Shop
		void			OpenMyOfflineShop(const char * c_pszSign, TShopItemTable * pTable, BYTE bItemCount, BYTE bTime);
		// Offline Shop Timer
		void			SetOfflineShopTimer(int iTime) { m_pointsInstant.leftTime = iTime; }
		int				GetOfflineShopTimer() { return m_pointsInstant.leftTime; }
		void			SetOfflineShopSaveTime(BYTE bSaveTime) { m_pointsInstant.bSaveTime = bSaveTime; }
		BYTE			GetOfflineShopSaveTime() { return m_pointsInstant.bSaveTime; }
		// Set Title 
		void			SetOfflineShopSign(const char * c_pszSign);
		// Destroy Offline Shop
		void			DestroyOfflineShop();
		// Offline Shop Save Time
		void			SatilmayanlariGeriAl(LPCHARACTER ch);
		void			StartOfflineShopUpdateEvent();
		void			StopOfflineShopUpdateEvent();
		// Configure Offline Shop Channel
		void			SetOfflineShopChannel(BYTE bChannel) { m_pointsInstant.bChannel = bChannel; }
		BYTE			GetOfflineShopChannel() { return m_pointsInstant.bChannel; }
		// Configure Offline Shop NPC VID
		void			SetOfflineShopVID(DWORD dwVID) { m_pointsInstant.dwVID = dwVID; }
		DWORD			GetOfflineShopVID() { return m_pointsInstant.dwVID; }

	protected:
		LPOFFLINESHOP	m_pkOfflineShop;
		LPCHARACTER		m_pkChrOfflineShopOwner;
		std::string		m_stOfflineShopSign;
		// End Of OfflineShop

		////////////////////////////////////////////////////////////////////////////////////////
		// Exchange related
	public:
		bool			ExchangeStart(LPCHARACTER victim);
		void			SetExchange(CExchange * pkExchange);
		CExchange *		GetExchange() const	{ return m_pkExchange;	}

	protected:
		CExchange *		m_pkExchange;
		// End of Exchange

		////////////////////////////////////////////////////////////////////////////////////////
		// Battle
	public:
		struct TBattleInfo
		{
			int iTotalDamage;
			int iAggro;

			TBattleInfo(int iTot, int iAggr)
				: iTotalDamage(iTot), iAggro(iAggr)
				{}
		};
		typedef std::map<VID, TBattleInfo>	TDamageMap;

		typedef struct SAttackLog
		{
			DWORD	dwVID;
			DWORD	dwTime;
		} AttackLog;

		bool				Damage(LPCHARACTER pAttacker, int dam, EDamageType type = DAMAGE_TYPE_NORMAL);
		bool				__Profile__Damage(LPCHARACTER pAttacker, int dam, EDamageType type = DAMAGE_TYPE_NORMAL);
		void				DeathPenalty(BYTE bExpLossPercent);
		void				ReviveInvisible(int iDur);

		bool				Attack(LPCHARACTER pkVictim, BYTE bType = 0);
		bool				IsAlive() const		{ return m_pointsInstant.position == POS_DEAD ? false : true; }
		bool				CanFight() const;
#ifdef WJ_SHOW_STROKE_INFO
		bool				GetStrokeByVid(DWORD dwTargetVID, DWORD * iAmount);
		void				RegisterStroke(DWORD dwTargetVID);
#endif

		bool				CanBeginFight() const;
		void				BeginFight(LPCHARACTER pkVictim); // pkVictimr�� �ο�� �����Ѵ�. (��������, ������ �� �ֳ� üũ�Ϸ��� CanBeginFight�� ���)

		bool				CounterAttack(LPCHARACTER pkChr); // �ݰ��ϱ� (���͸� ���)

		bool				IsStun() const;
		void				Stun();
		bool				IsDead() const;
		void				Dead(LPCHARACTER pkKiller = NULL, bool bImmediateDead=false);

#ifdef NEW_PET_SYSTEM
		void				SetImmortal(int st) { m_stImmortalSt = st; };
		bool				IsImmortal() { return 1 == m_stImmortalSt; };
		void				SetNewPetSkillCD(int s, DWORD time) { m_newpetskillcd[s] = time; };
		DWORD				GetNewPetSkillCD(int s) { return m_newpetskillcd[s]; };
#endif

		void				Reward(bool bItemDrop);
		void				RewardGold(LPCHARACTER pkAttacker);

		bool				Shoot(BYTE bType);
		void				FlyTarget(DWORD dwTargetVID, long x, long y, BYTE bHeader);

		void				ForgetMyAttacker();
		void				AggregateMonster();
		void				AttractRanger();
		void				PullMonster();

		int					GetArrowAndBow(LPITEM * ppkBow, LPITEM * ppkArrow, int iArrowCount = 1);
		void				UseArrow(LPITEM pkArrow, DWORD dwArrowCount);

		void				AttackedByPoison(LPCHARACTER pkAttacker);
		void				RemovePoison();

		void				AttackedByBleeding(LPCHARACTER pkAttacker);
		void				RemoveBleeding();

		void				AttackedByFire(LPCHARACTER pkAttacker, int amount, int count);
		void				RemoveFire();

		void				UpdateAlignment(int iAmount);
		int					GetAlignment() const;

		//����ġ ��� 
		int					GetRealAlignment() const;
		void				ShowAlignment(bool bShow);

		void				SetKillerMode(bool bOn);
		bool				IsKillerMode() const;
		void				UpdateKillerMode();

		BYTE				GetPKMode() const;
		void				SetPKMode(BYTE bPKMode);

		void				ItemDropPenalty(LPCHARACTER pkKiller);

		void				UpdateAggrPoint(LPCHARACTER ch, EDamageType type, int dam);

		//
		// HACK
		// 
	public:
		void SetComboSequence(BYTE seq);
		BYTE GetComboSequence() const;

		void SetLastComboTime(DWORD time);
		DWORD GetLastComboTime() const;

		int GetValidComboInterval() const;
		void SetValidComboInterval(int interval);

		BYTE GetComboIndex() const;

		void IncreaseComboHackCount(int k = 1);
		void ResetComboHackCount();
		void SkipComboAttackByTime(int interval);
		DWORD GetSkipComboAttackByTime() const;

	protected:
		BYTE m_bComboSequence;
		DWORD m_dwLastComboTime;
		int m_iValidComboInterval;
		BYTE m_bComboIndex;
		int m_iComboHackCount;
		DWORD m_dwSkipComboAttackByTime;

	protected:
		void				UpdateAggrPointEx(LPCHARACTER ch, EDamageType type, int dam, TBattleInfo & info);
		void				ChangeVictimByAggro(int iNewAggro, LPCHARACTER pNewVictim);

		DWORD				m_dwFlyTargetID;
		std::vector<DWORD>	m_vec_dwFlyTargets;
		TDamageMap			m_map_kDamage;	// � ĳ���Ͱ� ������ �󸶸�ŭ�� �������� �־��°�?
//		AttackLog			m_kAttackLog;
		DWORD				m_dwKillerPID;

		int					m_iAlignment;		// Lawful/Chaotic value -200000 ~ 200000
		int					m_iRealAlignment;
		int					m_iKillerModePulse;
		BYTE				m_bPKMode;

		// Aggro
		DWORD				m_dwLastVictimSetTime;
		int					m_iMaxAggro;
		// End of Battle

		// Stone
	public:
		void				SetStone(LPCHARACTER pkChrStone);
		void				ClearStone();
		void				DetermineDropMetinStone();
		DWORD				GetDropMetinStoneVnum() const { return m_dwDropMetinStone; }
		BYTE				GetDropMetinStonePct() const { return m_bDropMetinStonePct; }

	protected:
		LPCHARACTER			m_pkChrStone;		// ���� ������ ��
		CHARACTER_SET		m_set_pkChrSpawnedBy;	// ���� ������ ���
		DWORD				m_dwDropMetinStone;
		BYTE				m_bDropMetinStonePct;
		// End of Stone

	public:
		enum
		{
			SKILL_UP_BY_POINT,
			SKILL_UP_BY_BOOK,
			SKILL_UP_BY_TRAIN,

			// ADD_GRANDMASTER_SKILL
			SKILL_UP_BY_QUEST,
			// END_OF_ADD_GRANDMASTER_SKILL
		};

		void				SkillLevelPacket();
		bool				SkillCanUp(DWORD dwVnum);
		void				SkillLevelUp(DWORD dwVnum, BYTE bMethod = SKILL_UP_BY_POINT);
		bool				SkillLevelDown(DWORD dwVnum);
		// ADD_GRANDMASTER_SKILL
		bool				UseSkill(DWORD dwVnum, LPCHARACTER pkVictim, bool bUseGrandMaster = true);
		void				ResetSkill();
		void				SetSkillLevel(DWORD dwVnum, BYTE bLev);
		int					GetUsedSkillMasterType(DWORD dwVnum);

		bool				IsLearnableSkill(DWORD dwSkillVnum) const;
		// END_OF_ADD_GRANDMASTER_SKILL

		bool				CheckSkillHitCount(const BYTE SkillID, const VID dwTargetVID);
		bool				CanUseSkill(DWORD dwSkillVnum) const;
		bool				IsUsableSkillMotion(DWORD dwMotionIndex) const;
		int					GetSkillLevel(DWORD dwVnum) const;
		int					GetSkillMasterType(DWORD dwVnum) const;
		int					GetSkillPower(DWORD dwVnum, BYTE bLevel = 0) const;

		time_t				GetSkillNextReadTime(DWORD dwVnum) const;
		void				SetSkillNextReadTime(DWORD dwVnum, time_t time);
		void				SkillLearnWaitMoreTimeMessage(DWORD dwVnum);

		void				ComputePassiveSkill(DWORD dwVnum);
		int					ComputeSkill(DWORD dwVnum, LPCHARACTER pkVictim, BYTE bSkillLevel = 0);
		int					ComputeSkillAtPosition(DWORD dwVnum, const PIXEL_POSITION& posTarget, BYTE bSkillLevel = 0);
		void				ComputeSkillPoints();

		void				SetSkillGroup(BYTE bSkillGroup); 
		BYTE				GetSkillGroup() const		{ return m_points.skill_group; }

		int					ComputeCooltime(int time);

		void				GiveRandomSkillBook();

		void				DisableCooltime();
		bool				LearnSkillByBook(DWORD dwSkillVnum, BYTE bProb = 0);
		bool				LearnGrandMasterSkill(DWORD dwSkillVnum);

	private:
		bool				m_bDisableCooltime;
		DWORD				m_dwLastSkillTime;	///< ���������� skill �� �� �ð�(millisecond).
		// End of Skill

		// MOB_SKILL
	public:
		bool				HasMobSkill() const;
		size_t				CountMobSkill() const;
		const TMobSkillInfo * GetMobSkill(unsigned int idx) const;
		bool				CanUseMobSkill(unsigned int idx) const;
		bool				UseMobSkill(unsigned int idx);
		void				ResetMobSkillCooltime();
	protected:
		DWORD				m_adwMobSkillCooltime[MOB_SKILL_MAX_NUM];
		// END_OF_MOB_SKILL

		// for SKILL_MUYEONG
	public:
		void				StartMuyeongEvent();
		void				StopMuyeongEvent();

	private:
		LPEVENT				m_pkMuyeongEvent;

		// for SKILL_CHAIN lighting
	public:
		int					GetChainLightningIndex() const { return m_iChainLightingIndex; }
		void				IncChainLightningIndex() { ++m_iChainLightingIndex; }
		void				AddChainLightningExcept(LPCHARACTER ch) { m_setExceptChainLighting.insert(ch); }
		void				ResetChainLightningIndex() { m_iChainLightingIndex = 0; m_setExceptChainLighting.clear(); }
		int					GetChainLightningMaxCount() const;
		const CHARACTER_SET& GetChainLightingExcept() const { return m_setExceptChainLighting; }

	private:
		int					m_iChainLightingIndex;
		CHARACTER_SET m_setExceptChainLighting;

		// for SKILL_EUNHYUNG
	public:
		void				SetAffectedEunhyung();
		void				ClearAffectedEunhyung() { m_dwAffectedEunhyungLevel = 0; }
		bool				GetAffectedEunhyung() const { return m_dwAffectedEunhyungLevel; }

	private:
		DWORD				m_dwAffectedEunhyungLevel;

		//
		// Skill levels
		//
	protected:
		TPlayerSkill*					m_pSkillLevels;
		boost::unordered_map<BYTE, int>		m_SkillDamageBonus;
		std::map<int, TSkillUseInfo>	m_SkillUseInfo;

		////////////////////////////////////////////////////////////////////////////////////////
		// AI related
	public:
		void			AssignTriggers(const TMobTable * table);
		LPCHARACTER		GetVictim() const;	// ������ ��� ����
		void			SetVictim(LPCHARACTER pkVictim);
		LPCHARACTER		GetNearestVictim(LPCHARACTER pkChr);
		LPCHARACTER		GetProtege() const;	// ��ȣ�ؾ� �� ��� ����

		bool			Follow(LPCHARACTER pkChr, float fMinimumDistance = 150.0f);
		bool			Return();
		bool			IsGuardNPC() const;
		bool			IsChangeAttackPosition(LPCHARACTER target) const;
		void			ResetChangeAttackPositionTime() { m_dwLastChangeAttackPositionTime = get_dword_time() - AI_CHANGE_ATTACK_POISITION_TIME_NEAR;}
		void			SetChangeAttackPositionTime() { m_dwLastChangeAttackPositionTime = get_dword_time();}

		bool			OnIdle();

		void			OnAttack(LPCHARACTER pkChrAttacker);
		void			OnClick(LPCHARACTER pkChrCauser);

		VID				m_kVIDVictim;

	protected:
		DWORD			m_dwLastChangeAttackPositionTime;
		CTrigger		m_triggerOnClick;
		// End of AI

		////////////////////////////////////////////////////////////////////////////////////////
		// Target
	protected:
		LPCHARACTER				m_pkChrTarget;		// �� Ÿ��
		CHARACTER_SET	m_set_pkChrTargetedBy;	// ���� Ÿ������ ������ �ִ� �����

	public:
		void				SetTarget(LPCHARACTER pkChrTarget);
		void				BroadcastTargetPacket();
		void				ClearTarget();
		void				CheckTarget();
		LPCHARACTER			GetTarget() const { return m_pkChrTarget; }

		////////////////////////////////////////////////////////////////////////////////////////
		// Safebox
	public:
		int					GetSafeboxSize() const;
		void				QuerySafeboxSize();
		void				SetSafeboxSize(int size);

		CSafebox *			GetSafebox() const;
		void				LoadSafebox(int iSize, DWORD dwGold, int iItemCount, TPlayerItem * pItems);
		void				ChangeSafeboxSize(BYTE bSize);
		void				CloseSafebox();

		/// â�� ���� ��û
		/**
		 * @param [in]	pszPassword 1�� �̻� 6�� ������ â�� ��й�ȣ
		 *
		 * DB �� â���⸦ ��û�Ѵ�.
		 * â��� �ߺ����� ���� ���ϸ�, �ֱ� â�� ���� �ð����� ���� 10�� �̳����� �� �� ���Ѵ�.
		 */
		void				ReqSafeboxLoad(const char* pszPassword);

		/// â�� ���� ��û�� ���
		/**
		 * ReqSafeboxLoad �� ȣ���ϰ� CloseSafebox ���� �ʾ��� �� �� �Լ��� ȣ���ϸ� â�� �� �� �ִ�.
		 * â������ ��û�� DB �������� ���������� �޾��� ��� �� �Լ��� ����ؼ� ��û�� �� �� �ְ� ���ش�.
		 */
		void				CancelSafeboxLoad( void ) { m_bOpeningSafebox = false; }

		void				SetMallLoadTime(int t) { m_iMallLoadTime = t; }
		int					GetMallLoadTime() const { return m_iMallLoadTime; }

		CSafebox *			GetMall() const;
		void				LoadMall(int iItemCount, TPlayerItem * pItems);
		void				CloseMall();

		void				SetSafeboxOpenPosition();
		float				GetDistanceFromSafeboxOpen() const;

	protected:
		CSafebox *			m_pkSafebox;
		int					m_iSafeboxSize;
		int					m_iSafeboxLoadTime;
		bool				m_bOpeningSafebox;	///< â�� ���� ��û ���̰ų� �����ִ°� ����, true �� ��� �����û�̰ų� ��������.

		CSafebox *			m_pkMall;
		int					m_iMallLoadTime;

		PIXEL_POSITION		m_posSafeboxOpen;

		////////////////////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////////
		// Mounting
	public:
		void				MountVnum(DWORD vnum);
		DWORD				GetMountVnum() const { return m_dwMountVnum; }
		DWORD				GetLastMountTime() const { return m_dwMountTime; }

		bool				CanUseHorseSkill();

		// Horse
		virtual	void		SetHorseLevel(int iLevel);

		virtual	bool		StartRiding();
		virtual	bool		StopRiding();

		virtual	DWORD		GetMyHorseVnum() const;

		virtual	void		HorseDie();
		virtual bool		ReviveHorse();

		virtual void		SendHorseInfo();
		virtual	void		ClearHorseInfo();

		void				HorseSummon(bool bSummon, bool bFromFar = false, DWORD dwVnum = 0, const char* name = 0);

		LPCHARACTER			GetHorse() const			{ return m_chHorse; }	 // ���� ��ȯ���� ��
		LPCHARACTER			GetRider() const; // rider on horse
		void				SetRider(LPCHARACTER ch);

		bool				IsRiding() const;

#ifdef __PET_SYSTEM__
	public:
		CPetSystem*			GetPetSystem()				{ return m_petSystem; }

	protected:
		CPetSystem*			m_petSystem;

	public:
#endif

#ifdef NEW_PET_SYSTEM
	public:
		CNewPetSystem*			GetNewPetSystem() { return m_newpetSystem; }

	protected:
		CNewPetSystem*			m_newpetSystem;

	public:
#endif

	public:
		LPITEM*	GetAttrTransferItem() {return m_pointsInstant.pAttrTransferItems;}
		bool IsAttrTransferOpen () const	{return (m_pointsInstant.pAttrTransferNpc?true:false);}
		void SetAttrTransferNpc(LPCHARACTER npc)	{m_pointsInstant.pAttrTransferNpc = npc;}
		bool CanDoAttrTransfer() const;

	protected:
		LPCHARACTER			m_chHorse;
		LPCHARACTER			m_chRider;

		DWORD				m_dwMountVnum;
		DWORD				m_dwMountTime;

		BYTE				m_bSendHorseLevel;
		BYTE				m_bSendHorseHealthGrade;
		BYTE				m_bSendHorseStaminaGrade;

		////////////////////////////////////////////////////////////////////////////////////////
		// Detailed Log
	public:
		void				DetailLog() { m_bDetailLog = !m_bDetailLog; }
		void				ToggleMonsterLog();
		void				MonsterLog(const char* format, ...);
	private:
		bool				m_bDetailLog;
		bool				m_bMonsterLog;

		////////////////////////////////////////////////////////////////////////////////////////
		// Empire

	public:
		void 				SetEmpire(BYTE bEmpire);
		BYTE				GetEmpire() const { return m_bEmpire; }

	protected:
		BYTE				m_bEmpire;

		////////////////////////////////////////////////////////////////////////////////////////
		// Regen
	public:
		void				SetRegen(LPREGEN pkRegen);

	protected:
		PIXEL_POSITION			m_posRegen;
		float				m_fRegenAngle;
		LPREGEN				m_pkRegen;
		size_t				regen_id_; // to help dungeon regen identification
		// End of Regen

		////////////////////////////////////////////////////////////////////////////////////////
		// Resists & Proofs
	public:
		bool				CannotMoveByAffect() const;	// Ư�� ȿ���� ���� ������ �� ���� �����ΰ�?
		bool				IsImmune(DWORD dwImmuneFlag);
		void				SetImmuneFlag(DWORD dw) { m_pointsInstant.dwImmuneFlag = dw; }

	protected:
		void				ApplyMobAttribute(const TMobTable* table);
		// End of Resists & Proofs

		////////////////////////////////////////////////////////////////////////////////////////
		// QUEST
		// 
	public:
		void				SetQuestNPCID(DWORD vid);
		DWORD				GetQuestNPCID() const { return m_dwQuestNPCVID; }
		LPCHARACTER			GetQuestNPC() const;

		void				SetQuestItemPtr(LPITEM item);
		void				ClearQuestItemPtr();
		LPITEM				GetQuestItemPtr() const;

		void				SetQuestBy(DWORD dwQuestVnum)	{ m_dwQuestByVnum = dwQuestVnum; }
		DWORD				GetQuestBy() const			{ return m_dwQuestByVnum; }

		int					GetQuestFlag(const std::string& flag) const;
		void				SetQuestFlag(const std::string& flag, int value);

		void				ConfirmWithMsg(const char* szMsg, int iTimeout, DWORD dwRequestPID);

	private:
		DWORD				m_dwQuestNPCVID;
		DWORD				m_dwQuestByVnum;
		LPITEM				m_pQuestItem;

		// Events
	public:
		bool				StartStateMachine(int iPulse = 1);
		void				StopStateMachine();
		void				UpdateStateMachine(DWORD dwPulse);
		void				SetNextStatePulse(int iPulseNext);

		// ĳ���� �ν��Ͻ� ������Ʈ �Լ�. ������ �̻��� ��ӱ����� CFSM::Update �Լ��� ȣ���ϰų� UpdateStateMachine �Լ��� ����ߴµ�, ������ ������Ʈ �Լ� �߰���.
		void				UpdateCharacter(DWORD dwPulse);

	protected:
		DWORD				m_dwNextStatePulse;

		// Marriage
	public:
		LPCHARACTER			GetMarryPartner() const;
		void				SetMarryPartner(LPCHARACTER ch);
		int					GetMarriageBonus(DWORD dwItemVnum, bool bSum = true);

		void				SetWeddingMap(marriage::WeddingMap* pMap);
		marriage::WeddingMap* GetWeddingMap() const { return m_pWeddingMap; }

	private:
		marriage::WeddingMap* m_pWeddingMap;
		LPCHARACTER			m_pkChrMarried;

		// Warp Character
	public:
		void				StartWarpNPCEvent();

	public:
		void				StartSaveEvent();
		void				StartRecoveryEvent();
		void				StartCheckSpeedHackEvent();
		void				StartDestroyWhenIdleEvent();

		LPEVENT				m_pkDeadEvent;
		LPEVENT				m_pkStunEvent;
		LPEVENT				m_pkSaveEvent;
		LPEVENT				m_pkRecoveryEvent;
		LPEVENT				m_pkTimedEvent;
		LPEVENT				m_pkFishingEvent;
		LPEVENT				m_pkAffectEvent;
		LPEVENT				m_pkPoisonEvent;
		LPEVENT				m_pkBleedEvent;
		LPEVENT				m_pkFireEvent;
		LPEVENT				m_pkWarpNPCEvent;
		//DELAYED_WARP
		//END_DELAYED_WARP

		// MINING
		LPEVENT				m_pkMiningEvent;
		// END_OF_MINING
		LPEVENT				m_pkWarpEvent;
		LPEVENT				m_pkCheckSpeedHackEvent;
		LPEVENT				m_pkDestroyWhenIdleEvent;
		LPEVENT				m_pkPetSystemUpdateEvent;
		LPEVENT				m_pkOfflineShopUpdateEvent;
#ifdef NEW_PET_SYSTEM
		LPEVENT				m_pkNewPetSystemUpdateEvent;
		LPEVENT				m_pkNewPetSystemExpireEvent;
#endif

		bool IsWarping() const { return m_pkWarpEvent ? true : false; }

		bool				m_bHasPoisoned;
		bool				m_bHasBleeded;

		const CMob *		m_pkMobData;
		CMobInstance *		m_pkMobInst;

		std::map<int, LPEVENT> m_mapMobSkillEvent;

		friend struct FuncSplashDamage;
		friend struct FuncSplashAffect;
		friend class CFuncShoot;

	public:
		int				GetPremiumRemainSeconds(BYTE bType) const;

	private:
		int				m_aiPremiumTimes[PREMIUM_MAX_NUM];

		// CHANGE_ITEM_ATTRIBUTES
		static const DWORD		msc_dwDefaultChangeItemAttrCycle;	///< ����Ʈ ������ �Ӽ����� ���� �ֱ�
		static const char		msc_szLastChangeItemAttrFlag[];		///< �ֱ� ������ �Ӽ��� ������ �ð��� Quest Flag �̸�
		static const char		msc_szChangeItemAttrCycleFlag[];		///< ������ �Ӽ����� ���� �ֱ��� Quest Flag �̸�
		// END_OF_CHANGE_ITEM_ATTRIBUTES

		// PC_BANG_ITEM_ADD
	private :
		bool m_isinPCBang;

	public :
		bool SetPCBang(bool flag) { m_isinPCBang = flag; return m_isinPCBang; }
		bool IsPCBang() const { return m_isinPCBang; }
		// END_PC_BANG_ITEM_ADD

		// NEW_HAIR_STYLE_ADD
	public :
		bool ItemProcess_Hair(LPITEM item, int iDestCell);
		// END_NEW_HAIR_STYLE_ADD

	public :
		void ClearSkill();
		void ClearSubSkill();

		// RESET_ONE_SKILL
		bool ResetOneSkill(DWORD dwVnum);
		// END_RESET_ONE_SKILL

	private :
		void SendDamagePacket(LPCHARACTER pAttacker, int Damage, BYTE DamageFlag);

	// ARENA
	private :
		CArena *m_pArena;
		bool m_ArenaObserver;
		int m_nPotionLimit;

	public :
		void 	SetArena(CArena* pArena) { m_pArena = pArena; }
		void	SetArenaObserverMode(bool flag) { m_ArenaObserver = flag; }

		CArena* GetArena() const { return m_pArena; }
		bool	GetArenaObserverMode() const { return m_ArenaObserver; }

		void	SetPotionLimit(int count) { m_nPotionLimit = count; }
		int		GetPotionLimit() const { return m_nPotionLimit; }
	// END_ARENA

		//PREVENT_TRADE_WINDOW
	public:
		bool	IsOpenSafebox() const { return m_isOpenSafebox ? true : false; }
		void 	SetOpenSafebox(bool b) { m_isOpenSafebox = b; }

		int		GetSafeboxLoadTime() const { return m_iSafeboxLoadTime; }
		void	SetSafeboxLoadTime() { m_iSafeboxLoadTime = thecore_pulse(); }
		//END_PREVENT_TRADE_WINDOW
	private:
		bool	m_isOpenSafebox;

	public:
		int		GetSkillPowerByLevel(int level, bool bMob = false) const;
		
		//PREVENT_REFINE_HACK
		int		GetRefineTime() const { return m_iRefineTime; }
		void	SetRefineTime() { m_iRefineTime = thecore_pulse(); } 
		int		m_iRefineTime;
		//END_PREVENT_REFINE_HACK

		//RESTRICT_USE_SEED_OR_MOONBOTTLE
		int 	GetUseSeedOrMoonBottleTime() const { return m_iSeedTime; }
		void  	SetUseSeedOrMoonBottleTime() { m_iSeedTime = thecore_pulse(); }
		int 	m_iSeedTime;
		//END_RESTRICT_USE_SEED_OR_MOONBOTTLE
		
		//PREVENT_PORTAL_AFTER_EXCHANGE
		int		GetExchangeTime() const { return m_iExchangeTime; }
		void	SetExchangeTime() { m_iExchangeTime = thecore_pulse(); }
		int		m_iExchangeTime;
		//END_PREVENT_PORTAL_AFTER_EXCHANGE
		
		int 	m_iMyShopTime;
		int		GetMyShopTime() const	{ return m_iMyShopTime; }
		void	SetMyShopTime() { m_iMyShopTime = thecore_pulse(); }

		// Hack ������ ���� üũ.
		bool	IsHack(bool bSendMsg = true, bool bCheckShopOwner = true, int limittime = g_nPortalLimitTime);

		// MONARCH
		BOOL	IsMonarch() const;
		// END_MONARCH
		void Say(const std::string & s);

		enum MONARCH_COOLTIME
		{
			MC_HEAL = 10,
			MC_WARP	= 60,
			MC_TRANSFER = 60,
			MC_TAX = (60 * 60 * 24 * 7),
			MC_SUMMON = (60 * 60),
		};

		enum MONARCH_INDEX
		{ 
			MI_HEAL = 0,
			MI_WARP,
			MI_TRANSFER,
			MI_TAX,
			MI_SUMMON,
			MI_MAX
		};

		DWORD m_dwMonarchCooltime[MI_MAX];
		DWORD m_dwMonarchCooltimelimit[MI_MAX];

		void  InitMC();
		DWORD GetMC(enum MONARCH_INDEX e) const;
		void SetMC(enum MONARCH_INDEX e);
		bool IsMCOK(enum MONARCH_INDEX e) const;
		DWORD GetMCL(enum MONARCH_INDEX e) const;
		DWORD GetMCLTime(enum MONARCH_INDEX e) const;

	public:
		bool ItemProcess_Polymorph(LPITEM item);

		// by mhh
		LPITEM*	GetCubeItem() { return m_pointsInstant.pCubeItems; }
		bool IsCubeOpen () const	{ return (m_pointsInstant.pCubeNpc?true:false); }
		void SetCubeNpc(LPCHARACTER npc)	{ m_pointsInstant.pCubeNpc = npc; }
		bool CanDoCube() const;

	public:
		bool IsSiegeNPC() const;

	private:
		//�߱� ����
		//18�� �̸� ����
		//3�ð� : 50 % 5 �ð� 0%
		e_overtime m_eOverTime;

	public:
		bool IsOverTime(e_overtime e) const { return (e == m_eOverTime); }
		void SetOverTime(e_overtime e) { m_eOverTime = e; }

	private:
		int		m_deposit_pulse;

	public:
		void	UpdateDepositPulse();
		bool	CanDeposit() const;

	private:
		void	__OpenPrivateShop();

	private:
		void	__OpenOfflineShop();

	public:
		struct AttackedLog
		{
			DWORD 	dwPID;
			DWORD	dwAttackedTime;
			
			AttackedLog() : dwPID(0), dwAttackedTime(0)
			{
			}
		};

		AttackLog	m_kAttackLog;
		AttackedLog m_AttackedLog;
		int			m_speed_hack_count;

	private :
		std::string m_strNewName;

	public :
		const std::string GetNewName() const { return this->m_strNewName; }
		void SetNewName(const std::string name) { this->m_strNewName = name; }

	public :
		void GoHome();

	private :
		std::set<DWORD>	m_known_guild;

	public :
		void SendGuildName(CGuild* pGuild);
		void SendGuildName(DWORD dwGuildID);

	private :
		DWORD m_dwLogOffInterval;

	public :
		DWORD GetLogOffInterval() const { return m_dwLogOffInterval; }

	public:
		bool UnEquipSpecialRideUniqueItem ();

		bool CanWarp () const;

	private:
		DWORD m_dwLastGoldDropTime;
#ifdef ENABLE_CHEQUE_SYSTEM
		DWORD m_dwLastChequeDropTime;
#endif

	public:
		void AutoRecoveryItemProcess (const EAffectTypes);

	public:
		void BuffOnAttr_AddBuffsFromItem(LPITEM pItem);
		void BuffOnAttr_RemoveBuffsFromItem(LPITEM pItem);

	private:
		void BuffOnAttr_ValueChange(BYTE bType, BYTE bOldValue, BYTE bNewValue);
		void BuffOnAttr_ClearAll();

		typedef std::map <BYTE, CBuffOnAttributes*> TMapBuffOnAttrs;
		TMapBuffOnAttrs m_map_buff_on_attrs;
		// ���� : ��Ȱ�� �׽�Ʈ�� ���Ͽ�.
	public:
		void SetArmada() { cannot_dead = true; }
		void ResetArmada() { cannot_dead = false; }
	private:
		bool cannot_dead;

#ifdef __PET_SYSTEM__
	private:
		bool m_bIsPet;
	public:
		void SetPet() { m_bIsPet = true; }
		bool IsPet() { return m_bIsPet; }
#endif

#ifdef NEW_PET_SYSTEM
	private:
		bool m_bIsNewPet;
		int m_eggvid;
	public:
		void SetNewPet() { m_bIsNewPet = true; }
		bool IsNewPet() const { return m_bIsNewPet ? true : false; }
		void SetEggVid(int vid) { m_eggvid = vid; }
		int GetEggVid() { return m_eggvid; }
#endif

	//���� ������ ����.
	private:
		float m_fAttMul;
		float m_fDamMul;
	public:
		float GetAttMul() { return this->m_fAttMul; }
		void SetAttMul(float newAttMul) {this->m_fAttMul = newAttMul; }
		float GetDamMul() { return this->m_fDamMul; }
		void SetDamMul(float newDamMul) {this->m_fDamMul = newDamMul; }

	private:
		bool IsValidItemPosition(TItemPos Pos) const;

		//���� ���� ��� ��Ŷ �ӽ� ����
	private:
		unsigned int itemAward_vnum;
		char		 itemAward_cmd[20];
		//bool		 itemAward_flag;
	public:
		unsigned int GetItemAward_vnum() { return itemAward_vnum; }
		char*		 GetItemAward_cmd() { return itemAward_cmd;	  }
		//bool		 GetItemAward_flag() { return itemAward_flag; }
		void		 SetItemAward_vnum(unsigned int vnum) { itemAward_vnum = vnum; }
		void		 SetItemAward_cmd(char* cmd) { strcpy(itemAward_cmd,cmd); }
		//void		 SetItemAward_flag(bool flag) { itemAward_flag = flag; }

	public:
		//��ȥ��
		
		// ĳ������ affect, quest�� load �Ǳ� ���� DragonSoul_Initialize�� ȣ���ϸ� �ȵȴ�.
		// affect�� ���� �������� �ε�Ǿ� LoadAffect���� ȣ����.
		void	DragonSoul_Initialize();

		bool	DragonSoul_IsQualified() const;
		void	DragonSoul_GiveQualification();

		int		DragonSoul_GetActiveDeck() const;
		bool	DragonSoul_IsDeckActivated() const;
		bool	DragonSoul_ActivateDeck(int deck_idx);

		void	DragonSoul_DeactivateAll();
		// �ݵ�� ClearItem ���� �ҷ��� �Ѵ�.
		// �ֳ��ϸ�....
		// ��ȥ�� �ϳ� �ϳ��� deactivate�� ������ ���� active�� ��ȥ���� �ִ��� Ȯ���ϰ�,
		// active�� ��ȥ���� �ϳ��� ���ٸ�, ĳ������ ��ȥ�� affect��, Ȱ�� ���¸� �����Ѵ�.
		// 
		// ������ ClearItem ��, ĳ���Ͱ� �����ϰ� �ִ� ��� �������� unequip�ϴ� �ٶ���,
		// ��ȥ�� Affect�� ���ŵǰ�, �ᱹ �α��� ��, ��ȥ���� Ȱ��ȭ���� �ʴ´�.
		// (Unequip�� ������ �α׾ƿ� ��������, �ƴ��� �� �� ����.)
		// ��ȥ���� deactivate��Ű�� ĳ������ ��ȥ�� �� Ȱ�� ���´� �ǵ帮�� �ʴ´�.
		void	DragonSoul_CleanUp();
		// ��ȥ�� ��ȭâ
	public:
		bool		DragonSoul_RefineWindow_Open(LPENTITY pEntity);
		bool		DragonSoul_RefineWindow_Close();
		LPENTITY	DragonSoul_RefineWindow_GetOpener() { return  m_pointsInstant.m_pDragonSoulRefineWindowOpener; }
		bool		DragonSoul_RefineWindow_CanRefine();

	private:
		// SyncPosition�� �ǿ��Ͽ� Ÿ������ �̻��� ������ ������ �� ����ϱ� ���Ͽ�,
		// SyncPosition�� �Ͼ ���� ���.
		timeval		m_tvLastSyncTime;
		int			m_iSyncHackCount;
	public:
		void			SetLastSyncTime(const timeval &tv) { memcpy(&m_tvLastSyncTime, &tv, sizeof(timeval)); }
		const timeval&	GetLastSyncTime() { return m_tvLastSyncTime; }
		void			SetSyncHackCount(int iCount) { m_iSyncHackCount = iCount;}
		int				GetSyncHackCount() { return m_iSyncHackCount; }

	public:
		struct S_CARD
		{
			DWORD	type;
			DWORD	value;
		};

		struct CARDS_INFO
		{
			S_CARD	cards_in_hand[MAX_CARDS_IN_HAND];
			S_CARD	cards_in_field[MAX_CARDS_IN_FIELD];
			DWORD	cards_left;
			DWORD	field_points;
			DWORD	points;
		};
		
		void			Cards_open(DWORD safemode);
		void			Cards_clean_list();
		DWORD			GetEmptySpaceInHand();
		void			Cards_pullout();
		void			RandomizeCards();
		bool			CardWasRandomized(DWORD type, DWORD value);
		void			SendUpdatedInformations();
		void			SendReward();
		void			CardsDestroy(DWORD reject_index);
		void			CardsAccept(DWORD accept_index);
		void			CardsRestore(DWORD restore_index);
		DWORD			GetEmptySpaceInField();
		DWORD			GetAllCardsCount();
		bool			TypesAreSame();
		bool			ValuesAreSame();
		bool			CardsMatch();
		DWORD			GetLowestCard();
		bool			CheckReward();
		void			CheckCards();
		void			RestoreField();
		void			ResetField();
		void			CardsEnd();
		void			GetGlobalRank(char * buffer, size_t buflen);
		void			GetRundRank(char * buffer, size_t buflen);
	protected:
		CARDS_INFO	character_cards;
		S_CARD		randomized_cards[24];

#ifdef __SASH_SYSTEM__
	protected:
		bool		m_bSashCombination, m_bSashAbsorption;

	public:
		bool		IsSashCombinationOpen() const {return (m_bSashCombination ? true : false);}
		bool		IsSashAbsorptionOpen() const {return (m_bSashAbsorption ? true : false);}
		bool		isSashOpened(bool bCombination) {return bCombination ? m_bSashCombination : m_bSashAbsorption;}
		void		OpenSash(bool bCombination);
		void		CloseSash();
		void		ClearSashMaterials();
		bool		CleanSashAttr(LPITEM pkItem, LPITEM pkTarget);
		LPITEM*		GetSashMaterials() {return m_pointsInstant.pSashMaterials;}
		bool		SashIsSameGrade(long lGrade);
		DWORD		GetSashCombinePrice(long lGrade);
		void		GetSashCombineResult(DWORD & dwItemVnum, DWORD & dwMinAbs, DWORD & dwMaxAbs);
		BYTE		CheckEmptyMaterialSlot();
		void		AddSashMaterial(TItemPos tPos, BYTE bPos);
		void		RemoveSashMaterial(BYTE bPos);
		BYTE		CanRefineSashMaterials();
		void		RefineSashMaterials();
#endif
#ifdef __CHANGELOOK_SYSTEM__
	protected:
		bool	m_bChangeLook;
	
	public:
		bool	isChangeLookOpened() {return m_bChangeLook;}
		void	ChangeLookWindow(bool bOpen = false, bool bRequest = false);
		void	ClearClWindowMaterials();
		LPITEM*	GetClWindowMaterials() {return m_pointsInstant.pClMaterials;}
		BYTE	CheckClEmptyMaterialSlot();
		void	AddClMaterial(TItemPos tPos, BYTE bPos);
		void	RemoveClMaterial(BYTE bPos);
		void	RefineClMaterials();
		bool	CleanTransmutation(LPITEM pkItem, LPITEM pkTarget);
#endif
};

ESex GET_SEX(LPCHARACTER ch);

#endif
