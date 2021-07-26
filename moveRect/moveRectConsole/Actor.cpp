#include "Actor.h"

moveRectconsole::Actor::Actor()
{
	init();
}

int32_t moveRectconsole::Actor::update()
{
	
	Display();

	return int32_t(0);
}

int32_t moveRectconsole::Actor::Display()
{

	COORD prevPos = pos;
	move();
	if(prevPos.X != pos.X || prevPos.Y != pos.Y)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), prevPos);
		std::cout << " " << std::endl;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		std::cout << "o" << std::endl;
	}


	return int32_t(0);
}

int32_t moveRectconsole::Actor::init()
{
	pos.X = 30;
	pos.Y = 20;

	// Ŀ�� ������ ����
	static HANDLE hOut;
	CONSOLE_CURSOR_INFO cInfo;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cInfo.dwSize = 1;
	cInfo.bVisible = false;
	SetConsoleCursorInfo(hOut, &cInfo);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << "o" << std::endl;

	return int32_t(0);
}

int32_t moveRectconsole::Actor::move()
{
	char input = getInput();
	if (input == 87 || input == 119) { pos.Y--; } // W,w
	if (input == 65 || input == 97) { pos.X--; } // A,a
	if (input == 83 || input == 115) { pos.Y++; } // S,s
	if (input == 68 || input == 100) { pos.X++; } // D,d
	pos.X = pos.X < 0 ? 0 : pos.X;
	pos.Y = pos.Y < 0 ? 0 : pos.Y;

	return 0;
}

char moveRectconsole::Actor::getInput()
{
	char inputKey = 0;
	if (_kbhit())
	{
		inputKey = _getch();
	}

	return char(inputKey);
}
