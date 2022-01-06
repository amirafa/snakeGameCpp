#include <stdio.h>
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
//____________________________________
void gotoxy(short x, short y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//____________________________________
//global
int game[20][40] = { 0 };
int snake[2][20] = { 0 };
int samt = 1;
int flag = 1;
int tool = 3;
int speed = 100;
int nfood = 10;
//
void mvnt1();
void mvnt2();
void wallfood(int a);
void Print();
//________________________Swap________________________
void Swap() {
	char a;
	//___win____________________
	if (nfood < 1) {
		system("cls");
		gotoxy(33, 11); cout << "<< You Win >>\n";
		gotoxy(24, 13); cout << "Any Key to restart , Esc to Exit";
		a = _getch();
		if (a == 27) exit(0);
		else { flag = 0; }
	}
	//___Lose___________________
	if (game[snake[0][tool]][snake[1][tool]] == 8 || game[snake[0][tool]][snake[1][tool]] == 7 || (snake[0][tool - 1] > 19 || snake[0][tool - 1] < 0) || (snake[1][tool - 1] >39 || snake[1][tool - 1] < 0)) {
		system("cls");
		gotoxy(33, 11); cout << "<< GAME OVER >>\n";
		gotoxy(24, 13); cout << "Any Key to restart , Esc to Exit";
		a = _getch();
		if (a == 27) exit(0);
		else { flag = 0; }
	}
	//___Eat And Swap_____________
	if (game[snake[0][tool]][snake[1][tool]] == 9) { game[snake[0][tool]][snake[1][tool]] = 7; tool++; nfood--; }
	else {
		game[snake[0][0]][snake[1][0]] = 0;
		for (int i = 0; i < tool; i++) {
			snake[0][i] = snake[0][i + 1];
			snake[1][i] = snake[1][i + 1];
		}
		game[snake[0][tool]][snake[1][tool]] = 7;
	}
}
//__________________Move(1)_____________________________
void mvnt1() {
	for (int z = 0; z < tool; z++) game[3][z + tool] = 7;
	int count = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			if (game[i][j] == 7) {
				snake[0][count] = i;
				snake[1][count] = j;
				count++;
			}
		}
	}
}
//_______________________Move(2)___________________________
void mvnt2() {
	if (_kbhit()) {           //dual kbhit for arrow keys (2 buffer)
		char c = _getch();
		if (_kbhit())
			c = _getch();
		if (c == 'd' || c == 77 && samt != -1)  samt = 1;
		if (c == 'a' || c == 75 && samt != 1)  samt = -1;
		if (c == 's' || c == 80 && samt != -2)  samt = 2;
		if (c == 'w' || c == 72 && samt != 2)  samt = -2;
		if (c == 'q') speed += 100; if (c == 'e') { if (speed > 100) speed -= 100; }
	}
	Sleep(speed);
	if (samt == 1) {
		snake[0][tool] = snake[0][tool - 1];
		snake[1][tool] = (snake[1][tool - 1]) + 1;
		Swap();
	}
	if (samt == -1) {
		snake[0][tool] = snake[0][tool - 1];
		snake[1][tool] = (snake[1][tool - 1]) - 1;
		Swap();
	}
	if (samt == 2) {
		snake[1][tool] = snake[1][tool - 1];
		snake[0][tool] = (snake[0][tool - 1]) + 1;
		Swap();
	}
	if (samt == -2) {
		snake[1][tool] = snake[1][tool - 1];
		snake[0][tool] = (snake[0][tool - 1]) - 1;
		Swap();
	}
	Print();
}
//______________________WallFood_______________________________
void wallfood(int a) {
	srand(time(0));
	int x, y;
	for (int i = 0; i < 10; i++) {
		x = rand() % 20;
		y = rand() % 40;
		if (game[x][y] != 0) i--;
		else game[x][y] = a;
	}
}
//_______________________Print________________________________
void Print() {
	//______________Kadr:
	char f = 205, g = 186, h = 201, l = 187, m = 188, n = 200;
	gotoxy(20, 1); for (int k = 1; k < 41; k++) cout << f;
	gotoxy(20, 22); for (int k = 1; k < 41; k++) cout << f;
	int ct = 1; gotoxy(19, 2); for (int k = 1; k < 21; k++) { cout << g; gotoxy(19, 2 + ct); ct++; }
	ct = 1; gotoxy(60, 2); for (int k = 1; k < 21; k++) { cout << g; gotoxy(60, 2 + ct); ct++; }
	gotoxy(19, 1); cout << h; gotoxy(60, 1); cout << l;
	gotoxy(60, 22); cout << m; gotoxy(19, 22); cout << n;
	gotoxy(25, 23); cout << "w -> speed down , e -> speed up\n\t\t\t\tCREATED BY A.H.RAFATI";
	//________________
	int cnt = 2;
	char a = ' ', b = 176, d = 235, e = 254;
	for (int i = 0; i < 20; i++) {
		gotoxy(20, cnt);
		for (int j = 0; j < 40; j++) {
			if (game[i][j] == 0)cout << a;     //0:empty 8:wall 9:food 7:snake
			if (game[i][j] == 8)cout << b;
			if (game[i][j] == 9)cout << d;
			if (game[i][j] == 7)cout << e;
		}
		cout << endl;
		cnt++;
	}
}
//_____________________Main__________________________________
int main() {
	//restart
	while (1) {
		tool = 3;
		flag = 1;
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 40; j++) {
				game[i][j] = 0;
				samt = 1;
			}
		mvnt1();
		wallfood(8);
		wallfood(9);
		Print();
		Sleep(2000);
		//Loop while flag==1
		while (flag == 1) {
			mvnt2();
		}
	}
	cin.get();
	cin.get();
}
