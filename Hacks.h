#pragma once
#include <windows.h>

namespace Hacks
{
	extern bool GlowActive;
	extern bool NoRecoilActive;
	extern bool AimBotActive;
	extern bool AimBotConfig;

	extern int AimSmoothing;
	extern int AimBone;
	extern float AimFov;

	extern void Glow();
	extern void NoRecoil();
	extern void AimBot();
	extern void Initialize();
	extern void HacksThread();

	extern ProcMem mem;
	extern DWORD gameModule;
	extern DWORD dwEngine;
}