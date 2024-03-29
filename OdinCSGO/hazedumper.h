#pragma once

#include <cstdint>

// 2020-03-03 21:57:27.571700700 UTC

#define	FL_ONGROUND				(1 << 0)	// At rest / on the ground
#define FL_DUCKING				(1 << 1)	// Player flag -- Player is fully crouched
#define	FL_WATERJUMP			(1 << 2)	// player jumping out of water
#define FL_ONTRAIN				(1 << 3)    // Player is _controlling_ a train, so movement commands should be ignored on client during prediction.
#define FL_INRAIN				(1 << 4)	// Indicates the entity is standing in rain
#define FL_FROZEN				(1 << 5)    // Player is frozen for 3rd person camera
#define FL_ATCONTROLS			(1 << 6)    // Player can't move, but keeps key inputs for controlling another entity
#define	FL_CLIENT				(1 << 7)	// Is a player
#define FL_FAKECLIENT			(1 << 8)	// Fake client, simulated server side; don't send network messages to them
#define	FL_INWATER				(1 << 9)	// In water


namespace hazedumper {
	constexpr ::std::int64_t timestamp                               = 1583272647;

	namespace netvars 
	{
		constexpr ::std::ptrdiff_t cs_gamerules_data                 = 0x0;
		constexpr ::std::ptrdiff_t m_ArmorValue                      = 0xB368;
		constexpr ::std::ptrdiff_t m_Collision                       = 0x320;
		constexpr ::std::ptrdiff_t m_CollisionGroup                  = 0x474;
		constexpr ::std::ptrdiff_t m_Local                           = 0x2FBC;
		constexpr ::std::ptrdiff_t m_MoveType                        = 0x25C;
		constexpr ::std::ptrdiff_t m_OriginalOwnerXuidHigh           = 0x31B4;
		constexpr ::std::ptrdiff_t m_OriginalOwnerXuidLow            = 0x31B0;
		constexpr ::std::ptrdiff_t m_SurvivalGameRuleDecisionTypes   = 0x1320;
		constexpr ::std::ptrdiff_t m_SurvivalRules                   = 0xCF8;
		constexpr ::std::ptrdiff_t m_aimPunchAngle                   = 0x302C;
		constexpr ::std::ptrdiff_t m_aimPunchAngleVel                = 0x3038;
		constexpr ::std::ptrdiff_t m_angEyeAnglesX                   = 0xB36C;
		constexpr ::std::ptrdiff_t m_angEyeAnglesY                   = 0xB370;
		constexpr ::std::ptrdiff_t m_bBombPlanted                    = 0x99D;
		constexpr ::std::ptrdiff_t m_bFreezePeriod                   = 0x20;
		constexpr ::std::ptrdiff_t m_bGunGameImmunity                = 0x3930;
		constexpr ::std::ptrdiff_t m_bHasDefuser                     = 0xB378;
		constexpr ::std::ptrdiff_t m_bHasHelmet                      = 0xB35C;
		constexpr ::std::ptrdiff_t m_bInReload                       = 0x3295;
		constexpr ::std::ptrdiff_t m_bIsDefusing                     = 0x391C;
		constexpr ::std::ptrdiff_t m_bIsQueuedMatchmaking            = 0x74;
		constexpr ::std::ptrdiff_t m_bIsScoped                       = 0x3914;
		constexpr ::std::ptrdiff_t m_bIsValveDS                      = 0x75;
		constexpr ::std::ptrdiff_t m_bSpotted                        = 0x93D;
		constexpr ::std::ptrdiff_t m_bSpottedByMask                  = 0x980;
		constexpr ::std::ptrdiff_t m_bStartedArming                  = 0x33E0;
		constexpr ::std::ptrdiff_t m_bUseCustomAutoExposureMax       = 0x9D9;
		constexpr ::std::ptrdiff_t m_bUseCustomAutoExposureMin       = 0x9D8;
		constexpr ::std::ptrdiff_t m_bUseCustomBloomScale            = 0x9DA;
		constexpr ::std::ptrdiff_t m_clrRender                       = 0x70;
		constexpr ::std::ptrdiff_t m_dwBoneMatrix                    = 0x26A8;
		constexpr ::std::ptrdiff_t m_fAccuracyPenalty                = 0x3320;
		constexpr ::std::ptrdiff_t m_fFlags                          = 0x104;
		constexpr ::std::ptrdiff_t m_flC4Blow                        = 0x2990;
		constexpr ::std::ptrdiff_t m_flCustomAutoExposureMax         = 0x9E0;
		constexpr ::std::ptrdiff_t m_flCustomAutoExposureMin         = 0x9DC;
		constexpr ::std::ptrdiff_t m_flCustomBloomScale              = 0x9E4;
		constexpr ::std::ptrdiff_t m_flDefuseCountDown               = 0x29AC;
		constexpr ::std::ptrdiff_t m_flDefuseLength                  = 0x29A8;
		constexpr ::std::ptrdiff_t m_flFallbackWear                  = 0x31C0;
		constexpr ::std::ptrdiff_t m_flFlashDuration                 = 0xA410;
		constexpr ::std::ptrdiff_t m_flFlashMaxAlpha                 = 0xA40C;
		constexpr ::std::ptrdiff_t m_flLastBoneSetupTime             = 0x2924;
		constexpr ::std::ptrdiff_t m_flLowerBodyYawTarget            = 0x3A7C;
		constexpr ::std::ptrdiff_t m_flNextAttack                    = 0x2D70;
		constexpr ::std::ptrdiff_t m_flNextPrimaryAttack             = 0x3228;
		constexpr ::std::ptrdiff_t m_flSimulationTime                = 0x268;
		constexpr ::std::ptrdiff_t m_flTimerLength                   = 0x2994;
		constexpr ::std::ptrdiff_t m_hActiveWeapon                   = 0x2EF8;
		constexpr ::std::ptrdiff_t m_hMyWeapons                      = 0x2DF8;
		constexpr ::std::ptrdiff_t m_hObserverTarget                 = 0x338C;
		constexpr ::std::ptrdiff_t m_hOwner                          = 0x29CC;
		constexpr ::std::ptrdiff_t m_hOwnerEntity                    = 0x14C;
		constexpr ::std::ptrdiff_t m_iAccountID                      = 0x2FC8;
		constexpr ::std::ptrdiff_t m_iClip1                          = 0x3254;
		constexpr ::std::ptrdiff_t m_iCompetitiveRanking             = 0x1A84;
		constexpr ::std::ptrdiff_t m_iCompetitiveWins                = 0x1B88;
		constexpr ::std::ptrdiff_t m_iCrosshairId                    = 0xB3D4;
		constexpr ::std::ptrdiff_t m_iEntityQuality                  = 0x2FAC;
		constexpr ::std::ptrdiff_t m_iFOV                            = 0x31E4;
		constexpr ::std::ptrdiff_t m_iFOVStart                       = 0x31E8;
		constexpr ::std::ptrdiff_t m_iGlowIndex                      = 0xA428;
		constexpr ::std::ptrdiff_t m_iHealth                         = 0x100;
		constexpr ::std::ptrdiff_t m_iItemDefinitionIndex            = 0x2FAA;
		constexpr ::std::ptrdiff_t m_iItemIDHigh                     = 0x2FC0;
		constexpr ::std::ptrdiff_t m_iMostRecentModelBoneCounter     = 0x2690;
		constexpr ::std::ptrdiff_t m_iObserverMode                   = 0x3378;
		constexpr ::std::ptrdiff_t m_iShotsFired                     = 0xA380;
		constexpr ::std::ptrdiff_t m_iState                          = 0x3248;
		constexpr ::std::ptrdiff_t m_iTeamNum                        = 0xF4;
		constexpr ::std::ptrdiff_t m_lifeState                       = 0x25F;
		constexpr ::std::ptrdiff_t m_nFallbackPaintKit               = 0x31B8;
		constexpr ::std::ptrdiff_t m_nFallbackSeed                   = 0x31BC;
		constexpr ::std::ptrdiff_t m_nFallbackStatTrak               = 0x31C4;
		constexpr ::std::ptrdiff_t m_nForceBone                      = 0x268C;
		constexpr ::std::ptrdiff_t m_nTickBase                       = 0x3430;
		constexpr ::std::ptrdiff_t m_rgflCoordinateFrame             = 0x444;
		constexpr ::std::ptrdiff_t m_szCustomName                    = 0x303C;
		constexpr ::std::ptrdiff_t m_szLastPlaceName                 = 0x35B4;
		constexpr ::std::ptrdiff_t m_thirdPersonViewAngles           = 0x31D8;
		constexpr ::std::ptrdiff_t m_vecOrigin                       = 0x138;
		constexpr ::std::ptrdiff_t m_vecVelocity                     = 0x114;
		constexpr ::std::ptrdiff_t m_vecViewOffset                   = 0x108;
		constexpr ::std::ptrdiff_t m_viewPunchAngle                  = 0x3020;
	} // namespace netvars

	namespace signatures 
	{
		constexpr ::std::ptrdiff_t anim_overlays                     = 0x2980;
		constexpr ::std::ptrdiff_t clientstate_choked_commands       = 0x4D28;
		constexpr ::std::ptrdiff_t clientstate_delta_ticks           = 0x174;
		constexpr ::std::ptrdiff_t clientstate_last_outgoing_command = 0x4D24;
		constexpr ::std::ptrdiff_t clientstate_net_channel           = 0x9C;
		constexpr ::std::ptrdiff_t convar_name_hash_table            = 0x2F0F8;
		constexpr ::std::ptrdiff_t dwClientState                     = 0x589D9C;
		constexpr ::std::ptrdiff_t dwClientState_GetLocalPlayer      = 0x180;
		constexpr ::std::ptrdiff_t dwClientState_IsHLTV              = 0x4D40;
		constexpr ::std::ptrdiff_t dwClientState_Map                 = 0x28C;
		constexpr ::std::ptrdiff_t dwClientState_MapDirectory        = 0x188;
		constexpr ::std::ptrdiff_t dwClientState_MaxPlayer           = 0x388;
		constexpr ::std::ptrdiff_t dwClientState_PlayerInfo          = 0x52B8;
		constexpr ::std::ptrdiff_t dwClientState_State               = 0x108;
		constexpr ::std::ptrdiff_t dwClientState_ViewAngles          = 0x4D88;
		constexpr ::std::ptrdiff_t dwEntityList                      = 0x4D44A04;
		constexpr ::std::ptrdiff_t dwForceAttack                     = 0x3175FA8;
		constexpr ::std::ptrdiff_t dwForceAttack2                    = 0x3175FB4;
		constexpr ::std::ptrdiff_t dwForceBackward                   = 0x3175FE4;
		constexpr ::std::ptrdiff_t dwForceForward                    = 0x3175FC0;
		constexpr ::std::ptrdiff_t dwForceJump                       = 0x51EE660;
		constexpr ::std::ptrdiff_t dwForceLeft                       = 0x3175FD8;
		constexpr ::std::ptrdiff_t dwForceRight                      = 0x3175FFC;
		constexpr ::std::ptrdiff_t dwGameDir                         = 0x628578;
		constexpr ::std::ptrdiff_t dwGameRulesProxy                  = 0x526193C;
		constexpr ::std::ptrdiff_t dwGetAllClasses                   = 0xD56E6C;
		constexpr ::std::ptrdiff_t dwGlobalVars                      = 0x589AA0;
		constexpr ::std::ptrdiff_t dwGlowObjectManager               = 0x528C8B8;
		constexpr ::std::ptrdiff_t dwInput                           = 0x5195F90;
		constexpr ::std::ptrdiff_t dwInterfaceLinkList               = 0x8FAD34;
		constexpr ::std::ptrdiff_t dwLocalPlayer                     = 0xD30B84;
		constexpr ::std::ptrdiff_t dwMouseEnable                     = 0xD36728;
		constexpr ::std::ptrdiff_t dwMouseEnablePtr                  = 0xD366F8;
		constexpr ::std::ptrdiff_t dwPlayerResource                  = 0x317434C;
		constexpr ::std::ptrdiff_t dwRadarBase                       = 0x5179774;
		constexpr ::std::ptrdiff_t dwSensitivity                     = 0xD365C4;
		constexpr ::std::ptrdiff_t dwSensitivityPtr                  = 0xD36598;
		constexpr ::std::ptrdiff_t dwSetClanTag                      = 0x89E00;
		constexpr ::std::ptrdiff_t dwViewMatrix                      = 0x4D36344;
		constexpr ::std::ptrdiff_t dwWeaponTable                     = 0x5196A54;
		constexpr ::std::ptrdiff_t dwWeaponTableIndex                = 0x324C;
		constexpr ::std::ptrdiff_t dwYawPtr                          = 0xD36388;
		constexpr ::std::ptrdiff_t dwZoomSensitivityRatioPtr         = 0xD3B5D0;
		constexpr ::std::ptrdiff_t dwbSendPackets                    = 0xD39DA;
		constexpr ::std::ptrdiff_t dwppDirect3DDevice9               = 0xA6030;
		constexpr ::std::ptrdiff_t find_hud_element                  = 0x2877C270;
		constexpr ::std::ptrdiff_t force_update_spectator_glow       = 0x3991D2;
		constexpr ::std::ptrdiff_t interface_engine_cvar             = 0x3E9EC;
		constexpr ::std::ptrdiff_t is_c4_owner                       = 0x3A59A0;
		constexpr ::std::ptrdiff_t m_bDormant                        = 0xED;
		constexpr ::std::ptrdiff_t m_flSpawnTime                     = 0xA360;
		constexpr ::std::ptrdiff_t m_pStudioHdr                      = 0x294C;
		constexpr ::std::ptrdiff_t m_pitchClassPtr                   = 0x5179A18;
		constexpr ::std::ptrdiff_t m_yawClassPtr                     = 0xD36388;
		constexpr ::std::ptrdiff_t model_ambient_min                 = 0x58CDBC;
		constexpr ::std::ptrdiff_t set_abs_angles                    = 0x1CF110;
		constexpr ::std::ptrdiff_t set_abs_origin                    = 0x1CEF50;
	} // namespace signatures
} // namespace hazedumpernamespace hazedumper