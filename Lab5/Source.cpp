#define _CRT_NO_WARNNINGS 1
#include<stdio.h>
#include<windows.h>
#include<conio.h>
void draw_ship(int x, int y)
{
	if ((x >= 0 && x <= 80) && (y >= 0 && y <= 23))
	{
		COORD c = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		printf(" <-0-> ");
	}
}
void erase_ship(int x, int y)
{
	if ((x >= 0 && x <= 80) && (y >= 0 && y <= 23))
	{
		COORD c = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		printf("      ");
	}
}
int main()
{
	char ch = ' ';
	int x = 40, y = 2;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'w' && y > 0) { erase_ship(x, y); draw_ship(x, --y);}
			if (ch == 'a' && x > 0) { draw_ship(--x, y); }
			if (ch == 's' && y < 23) { erase_ship(x, y); draw_ship(x, ++y);}
			if (ch == 'd' && x < 80) { draw_ship(++x, y); }
			fflush(stdin);
		}
		Sleep(1);
	} while (ch != 'x');
	return 0;
}