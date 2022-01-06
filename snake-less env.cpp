#include <iostream>
#include <stdio.h>
#include <time.h>
#include<Windows.h> //for gotoxy
using namespace std;
//____________________________________
void gotoxy(short x, short y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//____________________________________
int game[20][40] = { 0 };
void foll(int a) {   //a=food or wall
	srand(time(0));
	int  x, y;
	for (int i = 0; i < 10; i++) {
		x = rand() % 20;
		y = rand() % 40;
		if (game[x][y] != 0) i--;
		else game[x][y] = a;
	}
}
void show(){
	int cnt = 3;
	char a = 177; char b = 219;
	for (int i = 0; i < 20; i++) {
		gotoxy(20,cnt);
		for (int j = 0; j < 40; j++) {
			if (game[i][j] != 0) cout << b;
			else cout << a;
		}
		cout << endl;
		cnt++;
	}
	cin.get();
	cin.get();
}

int main() {
	foll(1);
	show();
}