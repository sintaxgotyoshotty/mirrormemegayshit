#pragma once

#include "Hacks.h"



class CVisuals : public CHack
{
public:
	void Init();
	void Draw();
	void Move(CUserCmd *pCmd, bool &bSendPacket);
private:
	void DrawFPS();
	void DrawPing();
	void DrawCrosshair();
	void NoScopeCrosshair();
	void DrawRecoilCrosshair();
	void SpreadCrosshair();
	void AutowallCrosshair();
};