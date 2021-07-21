#include "Includes.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using std::cout;

void ClemX::UpdateMenu()
{
	system("CLS");
	SetConsoleTextAttribute(hConsole, 11);
	cout << "ClemRebuild v3\n";
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\n----------\n \n";

	if (Hacks::AimBotConfig)
	{
		SetConsoleTextAttribute(hConsole, 11);

		cout << "Current aimbot options : \n\n1.) Smoothing (lock-on slowness) : " << Hacks::AimSmoothing << "\n2.) Bone to aim : " << Hacks::AimBone << "\n3.) Aimbot FOV : " << Hacks::AimFov;
		cout << "\n\nFor the bones, put 8 to aim for the head and 4 for the middle body the rest beats the race \nThe FoV will determine the distance before the aimbot locks-on (legit recommendation: 4)";
		cout << "\n\nPlease enter the smoothing value (recommendation legit = 60):\n";
		
		cin >> Hacks::AimSmoothing;
		cout << "Your new smoothing value has been set: " << Hacks::AimSmoothing << "\n";

		cout << "\nPlease enter the new bone value:\n";

		cin >> Hacks::AimBone;
		cout << "Your new lock-on bone has been set: " << Hacks::AimBone << "\n";

		cout << "\nPlease enter the desired FoV value:\n";

		cin >> Hacks::AimFov;
		cout << "Your new FoV value has been set: " << Hacks::AimFov << "\n";

		cout << "\nValidating options, please wait... \n";

		Sleep(2500);
		Hacks::AimBotConfig = !Hacks::AimBotConfig;
		ClemX::UpdateMenu();
	}
	else
	{
		// STATE: Wallhack [F1]
		if (Hacks::GlowActive)
		{
			SetConsoleTextAttribute(hConsole, 10);
			cout << "[F1] Glow Wallhack : Active\n";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "[F1] Glow Wallhack : Inactive\n";
		}

		// STATE: No Recoil [F2]
		if (Hacks::NoRecoilActive)
		{
			SetConsoleTextAttribute(hConsole, 10);
			cout << "[F2] NoRecoil : Active\n";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "[F2] NoRecoil : Inactive\n";
		}

		// STATE: Aimbot [F3] | STATE: Aimbot Config [F4]
		if (Hacks::AimBotActive)
		{
			SetConsoleTextAttribute(hConsole, 10);
			cout << "[F3] AimBot : Active\n";
			SetConsoleTextAttribute(hConsole, 11);
			cout << "	[F4] Configure the aimbot\n";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "[F3] AimBot : Inactive\n";
		}

		// INFO: Aimbot Trigger
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\n----------\n";

		SetConsoleTextAttribute(hConsole, 11);
		cout << "Aimbot Trigger : ";

		SetConsoleTextAttribute(hConsole, 12);
		cout << "Left-Click \n";

		SetConsoleTextAttribute(hConsole, 7);
		cout << "\n----------\n";
		cout << "\n";

		// INFO: ESP Health Info
		SetConsoleTextAttribute(hConsole, 11);
		cout << "WallHack Glow colors : \n";
		cout << "+ of 70 life : ";
		SetConsoleTextAttribute(hConsole, 10);
		cout << "GREEN \n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Between 35 and 70 of life : ";
		SetConsoleTextAttribute(hConsole, 14);
		cout << "YELLOW \n";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Between 0 and 35 of life : ";
		SetConsoleTextAttribute(hConsole, 12);
		cout << "RED \n";
	}
}

void ClemX::KeyBinds()
{
	// ON-KEY-PRESS: F1 [ESP]
	if (GetAsyncKeyState(VK_F1) & 1)
	{
		Hacks::GlowActive = !Hacks::GlowActive;
		ClemX::UpdateMenu();
	}

	// ON-KEY-PRESS: F2 [No Recoil]
	if (GetAsyncKeyState(VK_F2) & 1)
	{
		Hacks::NoRecoilActive = !Hacks::NoRecoilActive;
		ClemX::UpdateMenu();
	}

	// ON-KEY-PRESS: F3 [Aimbot]
	if (GetAsyncKeyState(VK_F3) & 1)
	{
		Hacks::AimBotActive = !Hacks::AimBotActive;
		ClemX::UpdateMenu();
	}

	// ON-KEY-PRESS: F4 [Aimbot Config]
	if (GetAsyncKeyState(VK_F4) & 1)
	{
		Hacks::AimBotConfig = !Hacks::AimBotConfig;
		ClemX::UpdateMenu();
	}
}