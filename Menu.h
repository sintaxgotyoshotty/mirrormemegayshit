#pragma once
#include "GUI.h"
#include "Controls.h"
class CRageBotTab : public CTab
{
public:
	void Setup();
	CLabel ActiveLabel;
	CCheckBox Active;
	CComboBoxYeti psilent;
	CGroupBox AimbotGroup;
	CCheckBox AimbotEnable;
	CCheckBox lag_pred;
	CCheckBox AimbotAutoFire;
	CSlider  AimbotFov;
	CCheckBox AimbotSilentAim;
	CCheckBox PVSFix;
	CComboBoxYeti AimbotResolver;
	CCheckBox AdvancedResolver;
	CCheckBox AutoRevolver;
	CSlider AddFakeYaw;
	CSlider CustomPitch;
	CCheckBox LBY;
	//-------------------------
	//--------------------------
	CCheckBox LowerbodyFix;
	CCheckBox PreferBodyAim;
	CCheckBox AWPAtBody;
	CSlider BaimIfUnderXHealth;
	CSlider XShots;
	CCheckBox EnginePrediction;
	CCheckBox AimbotAimStep;
	CCheckBox pointscaleyes;
	CCheckBox Multienable;
	CSlider pointscaleval;
	CSlider Multival;
	CSlider AimbotAimStep2;
	CSlider shotlimit;
	CCheckBox AimbotKeyPress;
	CKeyBind  AimbotKeyBind;
	CKeyBind  AimbotStopKey;
	CGroupBox TargetGroup;
	CComboBoxYeti TargetSelection;
	CCheckBox TargetFriendlyFire;
	CComboBoxYeti TargetHitbox;
	CComboBoxYeti TargetHitscan;
	CCheckBox TargetMultipoint;
	CSlider   TargetPointscale;
	CSlider   bruteX;
	CSlider   baim;
	CGroupBox AccuracyGroup;
	CCheckBox AccuracyRecoil;
	CCheckBox QuickStop;
	CCheckBox AccuracyAutoWall;
	CSlider AccuracyMinimumDamage;
	CCheckBox AccuracyAutoStop;
	CSlider Multival2;
	CCheckBox massive;

	CCheckBox AccuracyAutoCrouch;
	CCheckBox AccuracyAutoScope;
	CSlider   AccuracyHitchance;
	CComboBoxYeti resolver;
	CComboBoxYeti preso;
	CKeyBind KeyOverride;
	CCheckBox LBYCorrection;
	CCheckBox Override;
	CSlider OverrideCount;
	CKeyBind OverrideKey;
	CComboBoxYeti OverrideMode;
	CKeyBind bigbaim;
	CCheckBox test_awall;
	CCheckBox extrapolation;
	CSlider YawRunningAdd;
	CSlider YawAdd;
	CSlider FakeYawAdd;
	CSlider FreestandingDelta;
	CCheckBox Freestand;
	CCheckBox FlipAA;
	CCheckBox AntiAimEdge;
	CSlider AntiAimOffset;
	CCheckBox ManualAAEnable;
	CKeyBind ManualAASwitch;
	CKeyBind ManualLeft;
	CKeyBind ManualRight;
	CKeyBind ManualBack;
	CComboBoxYeti LBYbreaker;
	CKeyBind Lbybreakerkey;
	CCheckBox BreakLBY;
	CSlider BreakLBYDelta;
	CCheckBox AntiAimKnife;
	CCheckBox AntiAimTarget;
};
class CLegitBotTab : public CTab
{
public:
	void Setup();
	// Master Switch
	CLabel ActiveLabel;
	CCheckBox Active;
	CGroupBox AimbotGroup;
	CCheckBox AimbotEnable;
	CComboBoxYeti aimbotfiremode;
	CCheckBox AimbotFriendlyFire;
	CCheckBox AimbotKeyPress;
	CKeyBind  AimbotKeyBind;
	CCheckBox AimbotSmokeCheck;
	CCheckBox BackTrack;
	CComboBoxYeti legitresolver;
	CGroupBox TriggerGroup;
	CComboBoxYeti triggertype;
	CCheckBox TriggerEnable;
	CKeyBind  TriggerKeyBind;
	CSlider   TriggerDelay;
	CSlider   TriggerBurst;
	CSlider   TriggerBreak;
	CSlider TriggerRecoil; CSlider   TriggerHitChanceAmmount;
	CGroupBox TriggerFilterGroup;
	CCheckBox TriggerHead;
	CCheckBox TriggerChest;
	CCheckBox TriggerStomach;
	CCheckBox TriggerArms;
	CCheckBox TriggerLegs;
	CCheckBox TriggerTeammates;
	CCheckBox TriggerFlashCheck;
	CCheckBox TriggerSmokeCheck;
	CCheckBox aaenable;
	CComboBoxYeti aatyp;
	CComboBoxYeti aatyp2;
	CSlider aatyp3;
	CSlider aimhp;
	CSlider aafl;
	CSlider trighp;
	CGroupBox weapongroup;
	CSlider   WeaponMainSpeed;
	CSlider   WeaponMainFoV;
	CSlider WeaponMainRecoil;
	CComboBoxYeti WeaponMainHitbox;
	CSlider WeaponMainAimtime;
	CSlider WeaoponMainStartAimtime;
	CGroupBox WeaponPistGroup;
	CSlider   WeaponPistSpeed;
	CSlider   WeaponPistFoV;
	CSlider WeaponPistRecoil;
	CComboBoxYeti WeaponPistHitbox;
	CSlider WeaponPistAimtime;
	CSlider WeaoponPistStartAimtime;
	CGroupBox WeaponSnipGroup;
	CSlider   WeaponSnipSpeed;
	CSlider   WeaponSnipFoV;
	CSlider WeaponSnipRecoil;
	CComboBoxYeti WeaponSnipHitbox;
	CSlider WeaponSnipAimtime;
	CSlider WeaoponSnipStartAimtime;
	CGroupBox WeaponMpGroup;
	CSlider   WeaponMpSpeed;
	CSlider   WeaponMpFoV;
	CSlider WeaponMpRecoil;
	CComboBoxYeti WeaponMpHitbox;
	CSlider WeaponMpAimtime;
	CSlider WeaoponMpStartAimtime;
	CGroupBox WeaponShotgunGroup;
	CSlider   WeaponShotgunSpeed;
	CSlider   WeaponShotgunFoV;
	CSlider WeaponShotgunRecoil;
	CComboBoxYeti WeaponShotgunHitbox;
	CSlider WeaponShotgunAimtime;
	CSlider WeaoponShotgunStartAimtime;
	CGroupBox WeaponMGGroup;
	CSlider   WeaponMGSpeed;
	CSlider   WeaponMGFoV;
	CSlider WeaponMGRecoil;
	CComboBoxYeti WeaponMGHitbox;
	CSlider WeaponMGAimtime;
	CSlider WeaoponMGStartAimtime;




};
class CVisualTab : public CTab
{
public:
	void Setup();
	CLabel ActiveLabel;
	CCheckBox Active;
	CCheckBox logs;
	CSlider flashAlpha;
	CGroupBox OptionsGroup;
	CCheckBox OptionsWeapone;
	CComboBoxYeti OptionsBox;
	CCheckBox OptionsName;
	CCheckBox HitmarkerSound;
	CCheckBox OtherHitmarker;
	CCheckBox ChamsEnemyVis;
	CCheckBox ChamsLocal;
	CCheckBox aa_helper;
	CCheckBox ChamsEnemyNoVis;
	CComboBoxYeti helpermat;
	CCheckBox OffscreenESP;
	CComboBoxYeti chamstype;
	CColorSelector urdadyoufaggot;
	CCheckBox ChamsTeamVis;
	CCheckBox ChamsTeamNoVis;
	CCheckBox OptionsGlow_lcl;
	CSlider Glowz_lcl;
	CCheckBox BlendIfScoped;
	CSlider BlendValue;
	CCheckBox NoGlowIfScoped;
	CCheckBox NoChamsIfScoped;
	CComboBoxYeti OptionsHealth;
	CComboBoxYeti OptionsWeapon;
	CComboBoxYeti Weapons;
	CCheckBox armorbar;
	CCheckBox manualaa;
	CKeyBind zoom;
	CCheckBox OptionsInfo;
	CCheckBox BulletTrace;
	CCheckBox Barrels;
	CCheckBox ChamsVisibleOnly;
	CCheckBox Ammo;
	CCheckBox Clock;
	CCheckBox HostageGlow;
	CComboBoxYeti HandCHAMS;
	CComboBoxYeti GunCHAMS;
	CCheckBox Watermark;
	CCheckBox LBYIndicator;
	CCheckBox FPSIndicator;
	CCheckBox PingIndicator;
	CCheckBox GrenadePrediction;
	CCheckBox LocalPlayerESP;
	CCheckBox CanHit;
	CCheckBox OptionsHelmet;
	CCheckBox NightMode;
	CCheckBox OptionsKit;
	CCheckBox SpecList;
	CCheckBox IsScoped;
	CCheckBox CompRank;
	CCheckBox HasDefuser;
	CCheckBox GrenadeTrace;
	CCheckBox Distance;
	CCheckBox DiscoLights;
	CCheckBox Money;
	CCheckBox BackTrackBones;
	CCheckBox DebugLagComp;
	CCheckBox OptionsDefuse;
	CComboBoxYeti OptionsChams;
	CCheckBox OptionsArmor;
	CCheckBox OptionsDefusing;
	CCheckBox SniperCrosshair;
	CSlider  GlowZ;
	CComboBoxYeti OtherThirdpersonAngle;
	CComboBoxYeti FakeAngleChams;
	CCheckBox OptionsSkeleton;
	CCheckBox NightSky;
	CCheckBox hitbone;
	CCheckBox OptionsAimSpot;
	CComboBoxYeti WeaponChams;
	CCheckBox OtherNoScope;
	CCheckBox OptionsCompRank;
	CCheckBox resoinfo;
	CCheckBox fakemedia;
	CCheckBox fakemedia2;
	CCheckBox selfglow;
	CGroupBox FiltersGroup;
	CCheckBox FiltersAll;
	CCheckBox FiltersPlayers;
	CCheckBox FiltersEnemiesOnly;
	CCheckBox FiltersWeapons;
	CCheckBox Backtrackchams;
	CCheckBox FiltersChickens;
	CCheckBox FiltersNades;
	CCheckBox FiltersC4;
	CGroupBox ChamsGroup;
	CCheckBox ModulateSkyBox;

	CCheckBox ChamsThruWalls;
	CComboBoxYeti Chams;
	CCheckBox ChamsPlayers;
	CCheckBox ChamsEnemyOnly;
	CGroupBox OtherGroup;
	CComboBoxYeti OtherCrosshair;
	CComboBoxYeti OtherRecoilCrosshair;
	CCheckBox AutowallCrosshair;
	CCheckBox OptionsGlow;
	CCheckBox EntityGlow;
	CCheckBox OtherEntityGlow;
	CCheckBox DisablePostProcess;
	CCheckBox OtherRadar;
	CCheckBox OtherNoVisualRecoil;
	CCheckBox OtherNoSky;
	CCheckBox OtherNoFlash;
	CCheckBox OtherNoSmoke;
	CCheckBox OtherAsusWalls;
	CComboBoxYeti OtherNoHands;
	CCheckBox AAIndicators;
	CCheckBox BulletTracers;
	CComboBoxYeti localmaterial;
	CComboBoxYeti scopemat;
	CSlider asusamount;
	CComboBoxYeti asustype;
	CSlider beamtime;
	CSlider lagcomptime;
	CSlider beamsize;
	CCheckBox cheatinfo;
	CCheckBox RemoveZoom;
	CComboBoxYeti sound;
	CCheckBox SpreadCross;
	CSlider SpreadCrossSize;
	CCheckBox DamageIndicator;
	CSlider OtherViewmodelFOV;
	CComboBoxYeti SpreadCrosshair;
	CSlider OtherFOV;
	CGroupBox worldgroup;
	CCheckBox colmodupdate;
	CSlider colmod;
	CCheckBox customskies2;
	CComboBoxYeti customskies;
};
class CLogoTab : public CTab
{
public:
	void Setup();

};

class CColorTab : public CTab
{
public:
	void Setup();

	CGroupBox ColorsGroup;
	CGroupBox ConfigGroup;
	CGroupBox OtherOptions;
	CListBox ConfigListBox;
	CButton SaveConfig;
	CButton LoadConfig;
	CButton RemoveConfig;
	CTextField NewConfigName;
	CComboBoxYeti MenuBar;
	CButton AddConfig;
	CColorSelector NameCol;
	CColorSelector LagComp;
	CColorSelector HandChamsCol;
	CColorSelector WeaponChamsCol;
	CColorSelector GunChamsCol;
	CColorSelector BoxCol;
	CColorSelector Skeleton;
	CColorSelector GlowEnemy; //no one has fucking team esp on so i'm not even gonna bother making a color selector for that
	CColorSelector GlowLocal;
	CColorSelector GlowOtherEnt;
	CColorSelector WorldColor;
	CColorSelector Skyboxcolor;
	CColorSelector spreadcrosscol;
	CColorSelector Weapons;
	CColorSelector Ammo;
	CColorSelector Money; //we don't really need to be able to change the color for all the flags it's just retarded
	CColorSelector Offscreen;
	CColorSelector ChamsLocal;
	CColorSelector ChamsEnemyVis;
	CColorSelector ChamsEnemyNotVis;
	CColorSelector ChamsTeamVis;
	CColorSelector ChamsTeamNotVis;
	CColorSelector Bullettracer;
	CColorSelector Menu;


	CComboBoxYeti LocalGlowMode;

	CColorSelector scoped_c;

	CSlider sky_r;
	CSlider sky_g;
	CSlider sky_b;

	CSlider AmbientRed;
	CSlider AmbientGreen;
	CCheckBox ambient;
	CSlider AmbientBlue;


	CGroupBox gcol;
	CSlider outl_r;
	CSlider outl_g;
	CSlider outl_b;

	CSlider inl_r;
	CSlider inl_g;
	CSlider inl_b;

	CSlider inr_r;
	CSlider inr_g;
	CSlider inr_b;


	CSlider outr_r;
	CSlider outr_g;
	CSlider outr_b;

	CSlider cr;
	CSlider cg;
	CSlider cb;
};
class CMiscTab : public CTab
{
public:
	void Setup();
	CCheckBox DisablePostProcess;
	CGroupBox OtherGroup;
	CCheckBox OtherAutoJump;
	CCheckBox meme;
	CCheckBox OtherAutoStrafe;
	CComboBoxYeti OtherSafeMode;
	CComboBoxYeti freestandtype;
	CKeyBind OtherCircleButton;
	CCheckBox AutoDefuse;
	CCheckBox OtherCircleStrafe;
	CCheckBox NoSpreadHVH;
	CCheckBox CircleStrafe;
	CKeyBind CircleStrafeKey;
	CKeyBind OtherCircle;
	CTextField CustomClantag;
	CCheckBox CheatsByPass;
	CCheckBox DebugHitbones;
	CCheckBox PreserveKillfeed;

	CSlider freerange;
	CCheckBox aa_helper;
	CCheckBox aa_helper2;
	CCheckBox fakelag_model;
	CCheckBox AutoAccept;
	CComboBoxYeti namechange;
	CCheckBox left2;
	CCheckBox SniperCrosshair;
	CSlider CircleAmount;
	CKeyBind OtherSlowMotion;
	CKeyBind FakeWalk;
	CComboBoxYeti FakeLagTyp;
	CCheckBox autofw;
	CKeyBind fw;
	CComboBoxYeti FakeYaw;
	CComboBoxYeti FakeYaw2;
	CComboBoxYeti FakeYaw3;
	CKeyBind manualleft;
	CKeyBind manualright;
	CKeyBind manualback;
	CKeyBind manualfront;
	CKeyBind backup_key;
	CKeyBind default_key;
	CGroupBox AntiAimGroup;
	CCheckBox AntiAimEnable;
	CComboBoxYeti AntiAimPitch;
	CComboBoxYeti AntiAimYaw;
	CComboBoxYeti backup_aa;
	CSlider staticr;
	CSlider staticf;
	CSlider ThirdPersonVal;
	CComboBoxYeti AntiAimYaw3;
	CComboBoxYeti AntiAimYawrun;
	CCheckBox Radar;
	CCheckBox OtherTeamChat;
	CSlider ClanTagSpeed;
	CSlider	  OtherChatDelay;
	CComboBoxYeti NameChanger;
	CCheckBox AutoPistol;
	CComboBoxYeti ClanTag;
	CCheckBox TrashTalk;
	CKeyBind  OtherAirStuck;
	CCheckBox OtherSpectators;
	CCheckBox OtherThirdperson;
	CComboBoxYeti OtherClantag;
	CCheckBox EnableBuyBot;
	CComboBoxYeti BuyBot;
	CCheckBox unstable;
	CCheckBox TestExploit;
	CGroupBox BuyBotGroup;
	CKeyBind ThirdPersonKeyBind;
	CSlider FakeWalkSpeed;
	CSlider ThirdPersonValue;
	CSlider twitchr;
	CSlider twitchr2;
	CSlider twitchf;
	CSlider spinf;
	CSlider randlbyr;
	CSlider randlbyf;
	CSlider lby1;
	CCheckBox squaredance;
	CComboBoxYeti antilby;
	CCheckBox experimental;
	CSlider BreakLBYDelta;
	CGroupBox FakeLagGroup;
	CSlider RadarX;
	CSlider RadarY;
	CCheckBox FakeLagEnable;
	CSlider Fakelagjump;
	CCheckBox PingSpike;
	CKeyBind LagSpikeKey;
	CComboBoxYeti KnifeModel;
	CButton   SkinApply;
	CCheckBox SkinEnable;
	CSlider FakelagMove;
	CSlider FakelagStand;
	CCheckBox fl_onshot;
	CCheckBox FakelagBreakLC;
	CSlider   FakeLagChoke;
	CCheckBox FakelagOnground;
	CCheckBox antilby2;
	CSlider FakeLagChoke2;
	CKeyBind lagkey;
	CKeyBind debugvoice;
	CComboBoxYeti inverse_type;
	CComboBoxYeti ConfigBox;
	CGroupBox ConfigGroup;
	CCheckBox dev_help;
	CCheckBox fakemedia;
	CKeyBind zoom;
	CComboBoxYeti fl_spike;
};
class Cskintab : public CTab
{
public:
	//	void Setup();
	CLabel SkinActive;
	CCheckBox SkinEnable;
	// Knife
	CGroupBox KnifeGroup;
	CGroupBox applygrp;
	CButton   SkinApply;
	CComboBoxYeti KnifeModel;
	CComboBoxYeti KnifeSkin;
	CTextField knifeskin2;
	CGroupBox PistolGroup;
	CComboBoxYeti GLOCKSkin;
	CComboBoxYeti USPSSkin;
	CComboBoxYeti DEAGLESkin;
	CComboBoxYeti MAGNUMSkin;
	CComboBoxYeti DUALSSkin;
	CComboBoxYeti FIVESEVENSkin;
	CComboBoxYeti P2000Skin;
	CComboBoxYeti P250Skin;
	CComboBoxYeti CZSkin;
	// MPs
	// Rifles
	CGroupBox Riflegroup;
	CComboBoxYeti M41SSkin;
	CComboBoxYeti M4A4Skin;
	CComboBoxYeti AK47Skin;
	CComboBoxYeti AUGSkin;
	CComboBoxYeti FAMASSkin;
	CComboBoxYeti GALILSkin;
	CComboBoxYeti SG553Skin;
	// Machineguns
	CGroupBox MachinegunsGroup;
	CComboBoxYeti NEGEVSkin;
	CComboBoxYeti M249Skin;
	CGroupBox MPGroup;
	CComboBoxYeti MAC10Skin;
	CComboBoxYeti P90Skin;
	CComboBoxYeti UMP45Skin;
	CComboBoxYeti BIZONSkin;
	CComboBoxYeti MP7Skin;
	CComboBoxYeti MP9Skin;
	// Snipers
	CGroupBox Snipergroup;
	CComboBoxYeti SCAR20Skin;
	CComboBoxYeti G3SG1Skin;
	CComboBoxYeti SSG08Skin;
	CComboBoxYeti r8skin;
	CComboBoxYeti AWPSkin;
	// Shotguns
	CGroupBox Shotgungroup;
	CComboBoxYeti MAG7Skin;
	CComboBoxYeti XM1014Skin;
	CComboBoxYeti SAWEDOFFSkin;
	CComboBoxYeti NOVASkin;
	// Skinsettings
	CGroupBox SkinsettingsGroup;
	CCheckBox StatTrakEnable;
};
class PhantomWindow : public CWindow
{
public:
	void Setup();
	CRageBotTab RageBotTab;
	CLegitBotTab LegitBotTab;
	CVisualTab VisualsTab;
	CLogoTab LogoTab;
	CMiscTab MiscTab;
	Cskintab skintab;
	CColorTab ColorsTab;
	CButton   SkinApply;
	CButton SaveButton1;
	CButton LoadButton1;
	CButton SaveButton;
	CButton LoadButton;
	CButton UnloadButton;
	CButton PanicButton;
	CButton ThirdButton;
	CButton ByPass;
	CButton FirstButton;
	CComboBox ConfigBox;
};
namespace Options
{
	void SetupMenu();
	void DoUIFrame();
	extern PhantomWindow Menu;
};