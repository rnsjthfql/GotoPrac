#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void cursor(int n) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


int main() {

	int key = 0, x = 0, y = 0;
	while (1) {
		cursor(0);
		system("cls");

		key = _getch();

		if (key == UP) {
			y--;
			if (y < 0)
				y = 0;
			gotoxy(x, y);
			cout << "¡Ú ";
			cout << "(ÁÂÇ¥:" << x << "," << y << ")";
			key = _getch();
		}
		else if (key == DOWN) {
			y++;
			gotoxy(x, y);
			cout << "¡Ú ";
			cout << "(ÁÂÇ¥:" << x << "," << y << ") ";
			key = _getch();
		}
		else if (key == LEFT) {
			x--;
			if (x < 0)
				x = 0;
			gotoxy(x, y);
			cout << "¡Ú ";
			cout << "(ÁÂÇ¥:" << x << "," << y << ")";
			key = _getch();
		}
		else if (key == RIGHT) {
			x++;
			gotoxy(x, y);
			cout << "¡Ú ";
			cout << "(ÁÂÇ¥:" << x << "," << y << ")";
			key = _getch();
		}
	}

	return 0;
}

