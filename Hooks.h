#pragma once

extern float last_real;
extern float lineLBY;
extern float lineRealAngle;
extern float lineFakeAngle;
extern float lspeed;
extern float pitchmeme;
extern float lby2;
extern bool DoUnload;
extern bool bGlovesNeedUpdate;
extern int missedLogHits[65];
#include "Utilities.h"
#include "Interfaces.h"
template<class T>
static T* Find_Hud_Element(const char* name)
{
	static auto pThis = *reinterpret_cast<DWORD**>(Utilities::Memory::FindPatternV2("client_panorama.dll", "B9 ? ? ? ? E8 ? ? ? ? 85 C0 0F 84 ? ? ? ? 8D 58") + 1);
	static auto find_hud_element = reinterpret_cast<DWORD(__thiscall*)(void*, const char*)>(Utilities::Memory::FindPatternV2("client_panorama.dll", "55 8B EC 53 8B 5D 08 56 57 8B F9 33 F6 39"));
	return (T*)find_hud_element(pThis, name);
}
namespace Hooks
{
	void Initialise();
	void DrawBeamd(Vector src, Vector end, Color color);
	void UndoHooks();


	extern Utilities::Memory::VMTManager VMTPanel; 
	extern Utilities::Memory::VMTManager VMTClient; 
	extern Utilities::Memory::VMTManager VMTClientMode;
	extern Utilities::Memory::VMTManager VMTModelRender;
	extern Utilities::Memory::VMTManager VMTPrediction; 
	extern Utilities::Memory::VMTManager VMTRenderView;
	extern Utilities::Memory::VMTManager VMTEventManager;
	extern Utilities::Memory::VMTManager VMTCreateMove;
};

namespace Resolver
{
	extern bool didhitHS;
	extern bool hitbaim;
	extern bool lbyUpdate;

}


namespace bigboi
{
	extern bool freestand;
	extern int indicator;
	extern int freestandval;
	
}
extern bool warmup;
extern bool m_round_changed;