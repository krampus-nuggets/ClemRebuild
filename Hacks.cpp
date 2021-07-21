#include "Includes.h"

ProcMem Hacks::mem;
DWORD Hacks::gameModule;
DWORD Hacks::dwEngine;
bool Hacks::GlowActive = false;
bool Hacks::NoRecoilActive = false;
bool Hacks::AimBotActive = false;
bool Hacks::AimBotConfig = false;

int Hacks::AimSmoothing = 60;
int Hacks::AimBone = 4;
float Hacks::AimFov = 4.f;

void Hacks::Glow()
{
	if (Hacks::GlowActive)
	{
		for (int i = 0; i < 32; i++)
		{
			if (Entity::isValid(Entity::getEntBase(i)) && Entity::getEntTeam(i) != LocalPlayer::getLocalTeam())
			{
				if (Entity::getEntHp(Entity::getEntBase(i)) >= 70)
				{
					Entity::glowEsp(Entity::getGlowObj(), Entity::getGlowIndex(Entity::getEntBase(i)), 0, 255, 0, 255);
				}
				else if (Entity::getEntHp(Entity::getEntBase(i)) > 35 && Entity::getEntHp(Entity::getEntBase(i)) < 70)
				{
					Entity::glowEsp(Entity::getGlowObj(), Entity::getGlowIndex(Entity::getEntBase(i)), 255, 255, 0, 255);
				}
				else
				{
					Entity::glowEsp(Entity::getGlowObj(), Entity::getGlowIndex(Entity::getEntBase(i)), 255, 0, 0, 255);
				}
			}
		}
	}
}
void Hacks::NoRecoil()
{
	if (Hacks::NoRecoilActive && Engine::IsInGame())
	{
		static D3DXVECTOR3 OldVectorPunch;
		if (LocalPlayer::getShotsFired() > 1) {
			D3DXVECTOR3 MyViewAngles = LocalPlayer::getLocalViewAngles();
			D3DXVECTOR3 ViewAngles;
			D3DXVECTOR3 LocalPlayerPunch = LocalPlayer::getLocalPunchAngles();
			ViewAngles.x = MyViewAngles.x + OldVectorPunch.x;
			ViewAngles.y = MyViewAngles.y + OldVectorPunch.y;

			D3DXVECTOR3 NewAngles;
			NewAngles.x = ViewAngles.x - LocalPlayerPunch.x * 1.2;
			NewAngles.y = ViewAngles.y - LocalPlayerPunch.y * 1.2f;
			NewAngles.z = 0.0f;
			LocalPlayer::setLocalViewAngles(ClampAngles(NewAngles));

			OldVectorPunch.x = LocalPlayerPunch.x * 1.2f;
			OldVectorPunch.y = LocalPlayerPunch.y * 1.2f;
		}
		else
		{
			OldVectorPunch.x = 0.0f;
			OldVectorPunch.y = 0.0f;
			OldVectorPunch.z = 0.0f;
		}
	}
}

void Hacks::AimBot()
{

	if (GetAsyncKeyState(VK_LBUTTON) && Hacks::AimBotActive)
	{
		LocalPlayer::AimAtPlayer(LocalPlayer::getClosestTarget(Hacks::AimFov), Hacks::AimSmoothing, Hacks::AimBone);
	}
}

void Hacks::Initialize()
{
	char process[] = "csgo.exe";
	char client_dll[] = "client.dll";
	char engine_dll[] = "engine.dll";
	Hacks::mem.Process(process);
	Hacks::gameModule = Hacks::mem.Module(client_dll);
	Hacks::dwEngine = Hacks::mem.Module(engine_dll);
}

void Hacks::HacksThread()
{
	Hacks::Glow();
	Hacks::NoRecoil();
	Hacks::AimBot();
}