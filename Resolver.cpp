#include "Resolver.h"
#include "Ragebot.h"
#include "Hooks.h"
#include "RenderManager.h"
#include "edge.h"
#include "LagCompensation2.h"
#include "laggycompensation.h"
#include "global_count.h"

#ifdef NDEBUG
#define XorStr( s ) ( XorCompileTime::XorString< sizeof( s ) - 1, __COUNTER__ >( s, std::make_index_sequence< sizeof( s ) - 1>() ).decrypt() )
#else
#define XorStr( s ) ( s )
#endif


inline float RandomFloat(float min, float max)
{
	static auto fn = (decltype(&RandomFloat))(GetProcAddress(GetModuleHandle("vstdlib.dll"), "RandomFloat"));
	return fn(min, max);
}
void ResolverSetup::preso(IClientEntity * pEntity)
{
	switch (Options::Menu.RageBotTab.preso.GetIndex())
	{
	case 1:
	{
		pEntity->GetEyeAnglesXY()->x = 89;
	}
	break;
	case 2:
	{
		pEntity->GetEyeAnglesXY()->x = -89;
	}
	break;
	case 3:
	{
		pEntity->GetEyeAnglesXY()->x = 0;
	}
	break;
	case 4:
	{
		float last_simtime[64] = { 0.f };
		float stored_pitch_1[64] = { 0.f };
		float stored_pitch_2[64] = { 0.f };

		const auto local = hackManager.pLocal();
		if (!local) return;

		for (auto i = 0; i < Interfaces::Engine->GetMaxClients(); ++i)
		{
			CMBacktracking* backtrack;
			const auto player = const_cast <IClientEntity*>(Interfaces::EntList->GetClientEntity(i));

			if (!player || local == player || player->GetTeamNum() == local->GetTeamNum() || player->IsImmune() || player->IsDormant()) 
			{
				last_simtime[i] = 0.f;
				stored_pitch_1[i] = 0.f;
				stored_pitch_2[i] = 0.f;
				continue;
			}

			auto is_legit = false;

			const auto eye = player->GetEyeAnglesXY();
			const auto sim = player->GetSimulationTime();

			if (sim - last_simtime[i] >= 1)
			{
				if (sim - last_simtime[i] == 1)
				{
					is_legit = true;
				}
				last_simtime[i] = sim;
			}

			int missed[65];
			missed[i] = global_count::shots_fired[i] - global_count::hits[i];
			while (missed[i] > 4) missed[i] -= 4;
			while (missed[i] < 0) missed[i] += 4;

			if (!is_legit)
			{
				if (backtrack->IsTickValid(TIME_TO_TICKS(sim)))
				{
					stored_pitch_1[i] = eye->x;
				}
				else
					stored_pitch_2[i] = eye->x;
			}

			auto pitch = 0.f;

			if (GetAsyncKeyState(Options::Menu.RageBotTab.OverrideKey.GetKey()))
			{
				pitch = 89.f;
			}
			else
			{
				if (stored_pitch_1[i] - stored_pitch_2[i] > 15)
				{
					if (missed[i] < 2)
					{
						switch (missed[i])
						{
						case 0:
							pitch = stored_pitch_1[i];
							break;
						case 1:
							pitch = stored_pitch_2[i];
							break;
						}
					}
					else
					{
						switch (missed[i])
						{
						case 2:
							pitch = eye->x;
							break;
						case 3:
							pitch = stored_pitch_1[i];
							break;
						case 4:
							pitch = stored_pitch_2[i];
							break;
						}
					}
				}
				else
				{
					pitch = 89.f;
				}
			}
			player->GetEyeAnglesXY()->x = pitch;
		}
	}
	break;
	case 5:
	{

		float last_simtime[64] = { 0.f };
		float last_pitch[64] = { 0.f };
		float difference[64] = { 0.f };

		bool did_change[64] = { false };

		const auto local = hackManager.pLocal();
		if (!local) return;

		for (auto i = 0; i < Interfaces::Engine->GetMaxClients(); ++i)
		{
			const auto player = const_cast <IClientEntity*>(Interfaces::EntList->GetClientEntity(i));


			if (!player || local == player || player->GetTeamNum() == local->GetTeamNum() || player->IsImmune() || player->IsDormant())
			{
				last_simtime[i] = 0.f;
				last_pitch[i] = 0.f;
				difference[i] = 0.f;
				did_change[i] = false;
				continue;
			}

			const auto eye = player->GetEyeAnglesXY();
			const auto sim = player->GetSimulationTime();

			auto missed = Globals::fired - Globals::hit;
			while (missed > 7) missed -= 7;
			while (missed < 0) missed += 7;

			if (last_pitch[i] != eye->x)
			{
				did_change[i] = true;
				if (fabsf(eye->x - last_pitch[i]) > 88 && fabsf(eye->x - last_pitch[i]) < 160)
					difference[i] = 89.0;
				else if (fabsf(eye->x - last_pitch[i]) > 89)
					difference[i] = 178.0;
				else
					difference[i] = eye->x - last_pitch[i];

			}

			auto angle = 0.f;

			if (did_change[i])
			{
				if (difference[i] < 45 && eye->x != 0)
				{
					switch (missed % 7)
					{
					case 0: angle = -eye->x;
						break;
					case 1: angle = 89;
						break;
					case 2: angle = 0;
						break;
					case 3: angle = -89;
						break;
					case 4: angle = -eye->x;
						break;
					case 5: angle = eye->x + difference[i];
						break;
					case 6: angle = eye->x - difference[i];
						break;
					default: angle = -eye->x;
					}
				}
				else
				{
					switch (missed % 7)
					{
					case 0: angle = eye->x + difference[i];
						break;
					case 1: angle = eye->x - difference[i];
						break;
					case 2: angle = 0;
						break;
					case 3: angle = -eye->x;
						break;
					case 4: angle = 89;
						break;
					case 5: angle = -89;
						break;
					case 6: angle = -eye->x + RandomFloat(-45, 45); // idk lmao, i don't play nospread, i'm just trying to leave a little for everyone who wants a base to build off of. This shit is a guessing game lmao
						break;
					default: angle = -eye->x;
					}
				}
			}
			else
			{
				if (eye->x != 0)
				{
					switch (missed % 7)
					{
					case 0: angle = -eye->x;
						break;
					case 1: angle = 89;
						break;
					case 2: angle = 0;
						break;
					case 3: angle = -89;
						break;
					case 4: angle = -eye->x;
						break;
					case 5: angle = eye->x - eye->x;
						break;
					case 6: angle = eye->x + eye->x;
						break;
					default: angle = -eye->x;
					}
				}
				else
				{
					switch (missed % 7)
					{
					case 0: angle = 89;
						break;
					case 1: angle = 0;
						break;
					case 2: angle = -89;
						break;
					case 3: angle = 89;
						break;
					case 4: angle = 0;
						break;
					case 5: angle = -89;
						break;
					case 6: angle = eye->x - eye->x;
						break;
					default: angle = -eye->x;
					}
				}
			}
			player->GetEyeAnglesXY()->x = angle;

		}
	}
	break;
	}



}


player_info_t GetInfo2(int Index) {
	player_info_t Info;
	Interfaces::Engine->GetPlayerInfo(Index, &Info);
	return Info;
}




static int GetSequenceActivity(IClientEntity* pEntity, int sequence)
{
	const model_t* pModel = pEntity->GetModel();
	if (!pModel)
		return 0;

	auto hdr = Interfaces::ModelInfo->GetStudiomodel(pEntity->GetModel());

	if (!hdr)
		return -1;

	static auto get_sequence_activity = reinterpret_cast<int(__fastcall*)(void*, studiohdr_t*, int)>(Utilities::Memory::FindPatternV2("client_panorama.dll", "55 8B EC 83 7D 08 FF 56 8B F1 74 3D"));

	return get_sequence_activity(pEntity, hdr, sequence);
}

float NormalizeFloatToAngle(float input)
{
	for (auto i = 0; i < 3; i++) {
		while (input < -180.0f) input += 360.0f;
		while (input > 180.0f) input -= 360.0f;
	}
	return input;
}


float override_yaw(IClientEntity* player, IClientEntity* local) {
	Vector eye_pos, pos_enemy;
	CalcAngle(player->GetEyePosition(), local->GetEyePosition(), eye_pos);
	if (Render::TransformScreen(player->GetOrigin(), pos_enemy)) {
		if (GUI.GetMouse().x < pos_enemy.x)
			return (eye_pos.y - 90);
		else if (GUI.GetMouse().x > pos_enemy.x)
			return (eye_pos.y + 90);
		else
			return (eye_pos.y - 180);
	}
	return eye_pos.y + 180;
}

bool playerStoppedMoving(IClientEntity* pEntity)
{
	for (int w = 0; w < 13; w++)
	{
		AnimationLayer currentLayer = pEntity->GetAnimOverlays()[1];
		const int activity = pEntity->GetSequenceActivity(currentLayer.m_nSequence);
		float flcycle = currentLayer.m_flCycle, flprevcycle = currentLayer.m_flPrevCycle, flweight = currentLayer.m_flWeight, flweightdatarate = currentLayer.m_flWeightDeltaRate;
		uint32_t norder = currentLayer.m_nOrder;
		if (activity == ACT_CSGO_IDLE_ADJUST_STOPPEDMOVING)
			return true;
	}
	return false;
}

int IClientEntity::GetSequenceActivity(int sequence)
{
	auto hdr = Interfaces::ModelInfo->GetStudiomodel(this->GetModel());

	if (!hdr)
		return -1;

	static auto getSequenceActivity = (DWORD)(Utilities::Memory::FindPatternV2("client_panorama.dll", "55 8B EC 83 7D 08 FF 56 8B F1 74"));
	static auto GetSequenceActivity = reinterpret_cast<int(__fastcall*)(void*, studiohdr_t*, int)>(getSequenceActivity);

	return GetSequenceActivity(this, hdr, sequence);
}




#define M_PI 3.14159265358979323846
void VectorAnglesBrute(const Vector& forward, Vector &angles)
{
	float tmp, yaw, pitch;
	if (forward[1] == 0 && forward[0] == 0)
	{
		yaw = 0;
		if (forward[2] > 0) pitch = 270; else pitch = 90;
	}
	else
	{
		yaw = (atan2(forward[1], forward[0]) * 180 / M_PI);
		if (yaw < 0) yaw += 360; tmp = sqrt(forward[0] * forward[0] + forward[1] * forward[1]); pitch = (atan2(-forward[2], tmp) * 180 / M_PI);
		if (pitch < 0) pitch += 360;
	} angles[0] = pitch; angles[1] = yaw; angles[2] = 0;
}


Vector calc_angle_trash(Vector src, Vector dst)
{
	Vector ret;
	VectorAnglesBrute(dst - src, ret);
	return ret;
}

bool IsAdjustingBalance(IClientEntity* player, AnimationLayer *layer)
{
	for (int i = 0; i < 15; i++)
	{
		const int activity = player->GetSequenceActivity(layer[i].m_nSequence);
		if (activity == 979)
		{
			return true;
		}
	}
	return false;
}

float save1[64];
float save2[64];
float avgspin[64];

float __fastcall ang_dif(float a1, float a2)
{
	float val = fmodf(a1 - a2, 360.0);

	while (val < -180.0f) val += 360.0f;
	while (val >  180.0f) val -= 360.0f;

	return val;
}
/*
bool is_kiduaswitch(IClientEntity* target, float lby, float oldlby, bool update, float complby) 
{

	if (target->IsDormant())
		return false;

		lby = target->GetLowerBodyYaw();

		if (oldlby != lby && update)
		{
			oldlby = lby;
			complby = lby;
		}

		if (oldlby - lby <= -60 || oldlby - lby >= 60 && oldlby != lby && complby == oldlby && update)
		{
			return true;
		}
} 
*/

void ResolverSetup::Resolve(IClientEntity* pEntity, int CurrentTarget)
{

	IClientEntity* pLocal = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());

	if (Options::Menu.RageBotTab.resolver.GetIndex() > 0)
	{
		if (Options::Menu.RageBotTab.resolver.GetIndex() == 1)
		{
			bool in_air[64] = { false };
			bool change[64] = { false };
			bool fakewalk[64] = { false };
			bool wasmoving[64] = { false };
			bool wasfakewalk[64] = { false };
			bool lowdelta[64] = { false };
			bool highdelta[64] = { false };
			bool didsync[64] = { false };
			bool spin[64] = { false };
			bool moving[64] = { false };
			bool hadmovingdif[64] = { false };
			bool hadslowlby[64] = { false };
			bool has_fake979[64] = { false };
			bool was_inair[64] = { false };
			bool did_fakewalk_change[64] = { false };

			float delta[64] = { 0.f };
			float oldlby[64] = { 0.f };
			float last_sim[64] = { 0.f };
			float last_sync[64] = { 0.f };
			float movinglby[64] = { 0.f };
			float deltaDiff[64] = { 0.f };
			float slowlby[64] = { 0.f };
			float temp_dif[64] = { 0.f };
			float movingdif[64] = { 0.f };
			float fakewalk_change[64] = { 0.f };

			static float add_time[65];

			static bool updated_once[65];
			static bool lbybreak[65];
			static bool nextflick[65];
			static bool lbybacktrack[65];

			const auto local = hackManager.pLocal();
			if (!local) return;

			createmove_backtrack* cmbacktrack;

			for (auto i = 0; i < Interfaces::Engine->GetMaxClients(); ++i)
			{
				const auto player = const_cast <IClientEntity*>(Interfaces::EntList->GetClientEntity(i));

				if (!player || local == player || player->GetTeamNum() == local->GetTeamNum() || player->IsImmune() || player->IsDormant())
				{
					wasfakewalk[i] = false;
					hadmovingdif[i] = false;
					didsync[i] = false;
					didsync[i] = false;
					change[i] = false;
					highdelta[i] = false;
					lowdelta[i] = false;
					temp_dif[i] = 0.f;
					oldlby[i] = 0.f;
					last_sim[i] = 0.f;
					continue;
				}
			
				auto update = false;
				auto nofake = false;

				const auto lby = player->GetLowerBodyYaw();
				const auto eye = player->GetEyeAnglesXY();
				const auto sim = player->GetSimulationTime();
				const auto speed = player->GetVelocity().Length2D();

				float lbyDelta = ang_dif(lby, save1[i]);
				float lbyDelta2 = ang_dif(save1[i], save2[i]);

				int missed[65];
				
				missed[i] = global_count::shots_fired[i] - global_count::hits[i];
				while (missed[i] > 3) missed[i] -= 3;
				while (missed[i] < 0) missed[i] += 3;
				
				for (int s = 0; s < 14; s++)
				{
					auto anim_layer = pEntity->GetAnimOverlay(s);
					if (!anim_layer.m_pOwner)
						continue;
					auto anime = &pEntity->GetAnimOverlays()[1];
					auto activity = GetSequenceActivity(pEntity, anime->m_nSequence);

					if (activity == -1)
						continue;

					if (sim - last_sim[i] >= 1)
					{
						if (sim - last_sim[i] == 1 && !IsAdjustingBalance(player, anime))
						{
							didsync[i] = true;
							nofake = true;
						}
						last_sim[i] = sim;
					}

					if (!(player->GetFlags() & FL_ONGROUND))
					{
						in_air[i] = true;
						was_inair[i] = true;
					}
					else
					{
						in_air[i] = false;
						if (speed >= 90.f)
						{
							hadslowlby[i] = true;
							movinglby[i] = lby;
							moving[i] = true;

							add_time[i] = 0.22f;
							nextflick[i] = sim + add_time[i];
						}
						else if (speed > 1.f && speed < 90.f)
						{
							add_time[i] = 0.22f;
							nextflick[i] = sim + add_time[i];

							if (IsAdjustingBalance(player, anime))
							{
								fakewalk[i] = true;
								wasfakewalk[i] = true;

								if (oldlby[i] - lby >= 60 || oldlby[i] - lby <= -60)
								{
									did_fakewalk_change[i] = true;
									fakewalk_change[i] = oldlby[i] - lby;
								}
							}
							else
							{
								hadslowlby[i] = true;
								moving[i] = true;
								slowlby[i] = lby;
							}
						}
						else
						{
							if (!nofake)
							{
								if (didsync[i])
									last_sync[i] = eye->y;

								if (lby != save1[i] && save1[i] != save2[i])
								{
									avgspin[i] = (lbyDelta + lbyDelta2) / 2.f;
									deltaDiff[i] = fabsf(lbyDelta - lbyDelta2);
									spin[i] = true;
								}

								if (sim >= nextflick[i] && !player->IsDormant() && backtracking->IsTickValid(TIME_TO_TICKS(sim)))
								{
									lbybreak[i] = true;
									add_time[i] = 1.1f;
									nextflick[i] = sim + add_time[i];
								}
								else
								{
									lbybreak[i] = false;
									lbybacktrack[i] = false;
								}

								if (oldlby[i] != lby && !spin[i] && !player->IsDormant())
								{
									oldlby[i] = lby;
							
									lbybreak[i] = true;
									update = true;
									delta[i] = fabsf(lby - oldlby[i]);

									if (delta[i] < -45 || delta[i] > 45)
										change[i] = true;
									else
										change[i] = false;

									add_time[i] = Interfaces::Globals->interval_per_tick + 1.1f;
									nextflick[i] = sim + add_time[i];
								}
								else
									lbybreak[i] = false;

								if (wasmoving[i] && oldlby[i] != lby && slowlby[i] != lby)
								{	
									movingdif[i] = slowlby[i] - lby;
									if (movingdif[i] < -50 || movingdif[i] >= 50)
									{
											hadmovingdif[i] = true;				
									}
									
								}

								
							}
						}
					}

					auto yaw = 0.f;

					if (in_air)
					{
						switch (missed[i])
						{
						case 0: yaw = lby - 15;
							break;
						case 1: yaw = lby - 105;
							break;
						case 2: yaw = lby + 35;
							break;
						case 3: yaw = lby - 180;
							break;
						}
					}
					else
					{
						if (moving)
						{
							yaw = lby;
						}
						else if (GetAsyncKeyState(Options::Menu.RageBotTab.OverrideKey.GetKey()))
						{
							Vector viewangles; Interfaces::Engine->GetViewAngles(viewangles); 

							auto attargets = calc_angle_trash(player->m_VecORIGIN(), local->m_VecORIGIN()).y;
							auto delta = fabsf(viewangles.y - attargets);
							auto rightDelta = Vector(player->GetEyeAnglesXY()->x, attargets + 90, player->GetEyeAnglesXY()->z);
							auto leftDelta = Vector(player->GetEyeAnglesXY()->x, attargets - 90, player->GetEyeAnglesXY()->z);

							if (delta > 0)
								player->GetEyeAngles() = QAngle(rightDelta.x, rightDelta.y, rightDelta.z);
							else
								player->GetEyeAngles() = QAngle(leftDelta.x, leftDelta.y, leftDelta.z);

						}
						else if (fakewalk)
						{
							if (wasmoving[i])
							{
								cmbacktrack->tickoverride(player, QAngle(eye->x, movinglby[i], 0), sim);
								yaw = movinglby[i];
							}
							else
							{
								switch (missed[i])
								{
								case 0: yaw = lby - 50;
									break;
								case 1: yaw = lby + 35;
									break;
								case 2: yaw = lby - 120;
									break;
								case 3: yaw = lby + 35;
									break;
								}

							}
						}
						else if (speed < 90.f && !fakewalk && speed > 1.f)
						{
							if (wasmoving[i])
							{
								switch (missed[i])
								{
								case 0: yaw = movinglby[i];
									break;
								case 1: yaw = lby;
									break;
								case 2: yaw = lby;
									break;
								case 3: yaw = movinglby[i];
									break;
								}
							}
							else
							{
								if (did_fakewalk_change[i])
								{
									switch (missed[i])
									{
									case 0: yaw = lby - fakewalk_change[i];
										break;
									case 1: yaw = lby ;
										break;
									case 2: yaw = lby - fakewalk_change[i] ;
										break;
									case 3: yaw = lby;
										break;
									}
								}
								else
									yaw = lby;
							}
						}
						else if (speed <= 1.f)
						{
							if (lbybreak[i] && !player->IsDormant())
							{
								//	cmbacktrack->tickoverride(player, QAngle(eye->x, lby, 0), sim);
									yaw = lby;
							}
							else if (!lbybreak[i] && !lbybacktrack[i])
							{
								if (nofake)
								{
									yaw = eye->y;
								}
								else if (change[i] && wasmoving[i])
								{
									if (hadmovingdif)
									{
										switch (missed[i])
										{
										case 0: yaw = movinglby[i];
											break;
										case 1: yaw = movinglby[i];
											break;
										case 2: yaw = movinglby[i] - 15;
											break;
										case 3: yaw = lby - movingdif[i];
											break;
										default: movinglby[i];
										}
									}
									else
									{
										switch (missed[i])
										{
										case 0: yaw = movinglby[i];
											break;
										case 1: yaw = movinglby[i] - 15;
											break;
										case 2: yaw = lby - delta[i];
											break;
										case 3: yaw = movinglby[i];
											break;
										}
									}
								}
								else if (change[i] && !wasmoving[i])
								{
									
									if (hadslowlby[i])
									{
										switch (missed[i])
										{
										case 0: yaw = slowlby[i];
											break;
										case 1: yaw = slowlby[i] - 15;
											break;
										case 2: yaw = lby - delta[i];
											break;
										case 3: yaw = lby - 15;
											break;
										}
									}
									else
									{
										switch (missed[i])
										{
										case 0: yaw = lby - delta[i];
											break;
										case 1: yaw = lby - delta[i] + 15;
											break;
										case 2: yaw = lby - delta[i];
											break;
										case 3: yaw = lby - delta[i] - 15;
											break;
										}
									}
									
								}
								else
								{
									if (anim_layer.m_flWeight == 1.f && !spin && !wasmoving[i] && change[i])
									{

										switch (missed[i])
										{
										case 0: yaw = lby - delta[i];
											break;
										case 1: yaw = lby - delta[i] - 15;
											break;
										case 2: yaw = lby - delta[i];
											break;
										case 3: yaw = lby;
											break;
										}
									}
									else if (anim_layer.m_flWeight == 0.f && !didsync[i] && !wasmoving[i] && !change[i] && !spin[i])
									{
										switch (missed[i])
										{
										case 0: yaw = lby - 90;
											break;
										case 1: yaw = lby - 110;
											break;
										case 2: yaw = lby - 30;
											break;
										case 3: yaw = lby - 60;
											break;
										}
									}
									else if (anim_layer.m_flWeight == 0.f && !didsync[i] && !wasmoving[i] && change[i] && !spin[i])
									{
										switch (missed[i])
										{
										case 0: yaw = lby - delta[i];
											break;
										case 1: yaw = lby - delta[i] - 15;
											break;
										case 2: yaw = lby - delta[i];
											break;
										case 3: yaw = lby - delta[i] + 25;
											break;
										}
									}
									else
									{
										if (!nofake && didsync[i] && (lby - last_sync[i] <= -90.f || lby - last_sync[i] >= 90.f) && !spin[i] && !change[i])
										{
											switch (missed[i])
											{
											case 0: yaw = last_sync[i];
												break;
											case 1: yaw = last_sync[i] - 45;
												break;
											case 2: yaw = last_sync[i];
												break;
											case 3: yaw = last_sync[i] + 45;
												break;
											}
										}
										else if (!nofake && didsync[i] && (lby - last_sync[i] <= -90.f || lby - last_sync[i] >= 90.f) && spin[i] && !change[i])
										{
											switch (missed[i])
											{
											case 0: yaw = last_sync[i];
												break;
											case 1: yaw = last_sync[i] - deltaDiff[i];
												break;
											case 2: yaw = lby - deltaDiff[i];
												break;
											case 3: yaw = last_sync[i];
												break;
											}
										}
										else 
										{
											if (spin)
											{
												switch (missed[i])
												{
												case 0: yaw = lby - deltaDiff[i];
													break;
												case 1: yaw = lby - 15;
													break;
												case 2: yaw = lby - deltaDiff[i] + 15;
													break;
												case 3: yaw = lby;
													break;
												}
											}
											else
											{
												switch (missed[i])
												{
												case 0: yaw = lby - 90;
													break;
												case 1: yaw = lby - 135;
													break;
												case 2: yaw = lby;
													break;
												case 3: yaw = lby - 60;
													break;
												}
											}
										
										}
									}
								}
							}
							else
							{
								switch (missed[i])
								{
								case 0: yaw = lby;
									break;
								case 1: yaw = lby - 120;
									break;
								case 2: yaw = lby - 35;
									break;
								case 3: yaw = lby - 90;
									break;
								}
							}
						}	
					}	
					player->GetEyeAnglesXY()->y = yaw;
				}
			}
		}
	}

	if (Options::Menu.LegitBotTab.legitresolver.GetIndex() == 1 && Options::Menu.RageBotTab.resolver.GetIndex() < 1)
	{
		const auto local = hackManager.pLocal();
		auto legit = false;

		bool did_change[64] = { false };
		float last_lby[64] = { 0.f };
		float difference[64] = { 0.f };
		float moving_lby[64] = { 0.f };
		float last_simtime[64] = { 0.f };
		bool  was_moving[64] = { false };

		if (!local) return;


		for (auto i = 0; i < Interfaces::Engine->GetMaxClients(); ++i)
		{
			const auto player = const_cast <IClientEntity*>(Interfaces::EntList->GetClientEntity(i));

			if (!player || local == player || player->GetTeamNum() == local->GetTeamNum() || player->IsImmune() || player->IsDormant()) {
				last_simtime[i] = 0.f;
				difference[i] = 0.f;
				last_lby[i] = 0.f;
				did_change[i] = false;
				was_moving[i] = false;
				continue;
			}


			const auto lby = player->GetLowerBodyYaw();
			const auto eye = player->GetEyeAnglesXY();
			const auto sim = player->GetSimulationTime();
			const auto vel = player->GetVelocity().Length2D();

			auto missed = Globals::fired - Globals::hit;
			while (missed > 3) missed -= 3;
			while (missed < 0) missed += 3;



			if (sim - last_simtime[i] >= 1)
			{
				if (sim - last_simtime[i] == 1)
				{
					legit = true;
				}
				else
				{
					legit = false;
				}
				last_simtime[i] = sim;
			}

			if (last_lby[i] != lby && fabsf(lby - last_lby[i]) > 35 && vel < 1 && !legit)
			{
				did_change[i] = true;
				difference[i] = fabsf(lby - last_lby[i]);
			}

			auto angle = 0.f;

			if (!(pLocal->GetFlags() % FL_ONGROUND))
			{
				if (legit)
					angle = eye->y;
				else
				{
					switch (missed % 3)
					{
					case 0: angle = lby;
						break;
					case 1: angle = lby - 90;
						break;
					case 2: angle = lby - 180;
						break;
					}
				}
			}
			else
			{
				if (vel > 1)
				{
					was_moving[i] = true;
					moving_lby[i] = lby;
					angle = lby;
				}
				else
				{
					if (legit)
						angle = eye->y;
					else
					{
						if (was_moving[i])
						{
							if (did_change[i])
							{
								switch (missed % 3)
								{
								case 0: angle = moving_lby[i];
									break;
								case 1: angle = lby - difference[i];
									break;
								case 2: angle = moving_lby[i];
									break;
								}
							}
							else
							{
								switch (missed % 3)
								{
								case 0: angle = moving_lby[i];
									break;
								case 1: angle = lby;
									break;
								case 2: angle = moving_lby[i] - 15;
									break;								
								}
							}
						}
						else
						{
							if (did_change[i])
							{
								switch (missed % 3)
								{
								case 0: angle = lby - difference[i];
									break;
								case 1: angle = lby - difference[i] + 15;
									break;
								case 2: angle = lby;
									break;
								}
							}
							else
							{
								switch (missed % 3)
								{
								case 0: angle = lby - 45;
									break;
								case 1: angle = lby - 90;
									break;
								case 2: angle = lby;
									break;
								}
							}
						}

					}
				}
			}
			player->GetEyeAnglesXY()->y = angle;


		}


	}


}

void calculate_angle(Vector src, Vector dst, Vector &angles)
{
	Vector delta = src - dst;
	vec_t hyp = delta.Length2D();
	angles.y = (atan(delta.y / delta.x) * 57.295779513082f);
	angles.x = (atan(delta.z / hyp) * 57.295779513082f);
	angles[2] = 0.0f;
	if (delta.x >= 0.0) angles.y += 180.0f;
}





void ResolverSetup::CM(IClientEntity* pEntity)
{
	for (int x = 1; x < Interfaces::Engine->GetMaxClients(); x++)
	{

		pEntity = (IClientEntity*)Interfaces::EntList->GetClientEntity(x);

		if (!pEntity
			|| pEntity == hackManager.pLocal()
			|| pEntity->IsDormant()
			|| !pEntity->IsAlive())
			continue;

	
	}
}

void ResolverSetup::FSN(IClientEntity* pEntity, ClientFrameStage_t stage)
{
	if (stage == ClientFrameStage_t::FRAME_NET_UPDATE_POSTDATAUPDATE_START)
	{
		for (int i = 1; i < Interfaces::Engine->GetMaxClients(); i++)
		{

			pEntity = (IClientEntity*)Interfaces::EntList->GetClientEntity(i);

			if (!pEntity || pEntity == hackManager.pLocal() || pEntity->IsDormant() || !pEntity->IsAlive())
				continue;
			int entID;
			ResolverSetup::Resolve(pEntity, stage);
			ResolverSetup::preso(pEntity);
		}
	}
}


/*
if (!(pEntity->GetFlags() & FL_ONGROUND))
{

switch (missed % 15)
{
case 0: angle = attargets.y + 180.f;
break;
case 1: angle = velocityAngle.y + 180.f;
break;
case 2: angle = primaryBaseAngle;
break;
case 3: angle = primaryBaseAngle - 45.f;
break;
case 4: angle = primaryBaseAngle + 90.f;
break;
case 5: angle = primaryBaseAngle - 130.f;
break;
case 6: angle = primaryBaseAngle - 180.f;
break;
case 7: angle = secondaryBaseAngle;
break;
case 8: angle = secondaryBaseAngle - 40.f;
break;
case 9: angle = secondaryBaseAngle - 90.f;
break;
case 10: angle = secondaryBaseAngle - 130.f;
break;
case 11: angle = secondaryBaseAngle - 70.f;
break;
case 12: angle = primaryBaseAngle + 45.f;
break;
case 13: angle = primaryBaseAngle + 135.f;
break;
case 14: angle = primaryBaseAngle - 90.f;
break;
}
}
*/