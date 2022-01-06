#include <iostream>
#include <stdio.h>
#include <conio.h> //for _getch
#include <stdlib.h>
#include<Windows.h>
#include<random>
using namespace std;

//void gotoxy is for using gotoxy in VS
void gotoxy(short x, short y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//Start Dir
int samt = 1, l = 1;
//Ghaza________1_________
class Ghaza {
public:
	void ghaza(int &ghx, int &ghy, char x) {
		ghx = (rand() % 19) + 4;
		ghy = (rand() % 76) + 2;
		gotoxy(ghy, ghx);
		cout << x;
	}
};
Ghaza gh1;
//MarPosition_____2_________________
class MarPos
{
private:
	int x, y, tx, ty;
public:
	void setx(int a) { x = a; }      void sety(int a) { y = a; }      void settx(int a) { tx = a; }     void setty(int a) { ty = a; }
	int getx() { return x; }     int gety() { return y; }     int gettx() { return tx; }     int getty() { return ty; }
};
//Finish____3_______________________
class Fin {
public:
	void fing() {
		if (l == 4) {
			system("cls");
			gotoxy(1, 11);
			cout << "  \t\t   *             You Win              *\n";
			_getch();
			exit(0);
		}
		system("cls");
		gotoxy(35, 10);
		cout << "*** Level " << l << " ***";
		_getch();
		_getch();
	}
};
//Main___________________________________________
void main() {
start:
	MarPos mar[15];
	int samtha[2][4] = { { -1,0,1,0 },{ 0,1,0,-1 } };
	int tul = 5, i, samt = 1, li = 3, p = 0, ghx, ghy;    //p>score  l>level  li>live
	char c;
	system("cls");
	cout << "\n        PROJECT : SNAKE GAME      CREATED BY : AMIR.H.RAFATI      ";
	cout << "\n\n\n\n\n\n\t\t\t    press any key for start     \n\n\t\t\t\t  Esc = exit  ";
	c = _getch();
	//For Escape
	if (c == 27)      //27 for Esc
		return;
	//___________________________________________________________________________________________________________
restart:
	//_______________live and scores UI____________________
	int khodesh[2][16] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
	system("cls");
	tul = 5;
	cout << "score : " << p;
	gotoxy(37, 2);
	cout << "level : " << l;
	gotoxy(1, 25);
	cout << " Esc=Exit\t\t        R=Restart \t\t   live: ";
	gotoxy(65, 25);
	char heart = 3;
	for (i = 0; i<li; i++)
		cout << heart<<" ";
	//Start position
	for (i = 0; i<tul; i++)
	{
		mar[i].setx(12);
		mar[i].sety(2);
		mar[i].settx(12);
		mar[i].setty(2);
	}
	//ghaza rand position perform
	gh1.ghaza(ghx, ghy, 6);  // 6 is ascii Code
							 //Mavane'e
	int m[10][2];
	int mx, my;
	for (i = 0; i<10; i++) {
		mx = (rand() % 76) + 2;
		my = (rand() % 19) + 4;
		m[i][0] = mx;
		m[i][1] = my;
		gotoxy(mx, my);
		char cc = 178;
		cout << cc;
	}
	//Movement to 4 directions at the begining
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			if (_kbhit())
				c = _getch();
			if (c == 27)
				return;
			else if (c == 77 || c == 'd') //77 right
				samt = 1;
			else if (c == 75 || c == 'a') //75 left
				samt = 3;
			else if (c == 72 || c == 'w') //72 up
				samt = 0;
			else if (c == 80 || c == 's') //80 down
				samt = 2;
			else if (c == 'r') {    //restart
				p = 0;   //score to begining
				goto restart;
			}
		}
		mar[0].settx(mar[0].getx());
		mar[0].setty(mar[0].gety());
		mar[0].setx(mar[0].getx() + samtha[0][samt]);
		mar[0].sety(mar[0].gety() + samtha[1][samt]);
		khodesh[0][0] = mar[0].getx();
		khodesh[1][0] = mar[0].gety();
		gotoxy(mar[0].gety(), mar[0].getx());
		char head = 22;

		if (samt == 0) head = 24;
	if (samt==1) head = 26;
	if (samt == 3) head = 27;
		if (samt == 2) head = 25;
		cout << head;
		for (i = 1; i<tul; i++)
		{
			khodesh[0][i] = mar[i].getx();
			khodesh[1][i] = mar[i].gety();
			mar[i].settx(mar[i].getx());
			mar[i].setty(mar[i].gety());
			mar[i].setx(mar[i - 1].gettx());
			mar[i].sety(mar[i - 1].getty());
			gotoxy(mar[i].gety(), mar[i].getx());
			cout << "=";
		}
		//sleep for refreshing
		Sleep(160 - l * 10);
		//Passed block
		gotoxy(mar[tul - 1].getty(), mar[tul - 1].gettx());
		cout << " ";
		gotoxy(36, 2);
		//Live & Loosing Process   (li=live)
		if (mar[0].gety() <= 1 || mar[0].gety()>79 || mar[0].getx() <= 3 || mar[0].getx() >= 24 || (mar[0].gety() == m[0][0] && mar[0].getx() == m[0][1]) || (mar[0].gety() == m[1][0] && mar[0].getx() == m[1][1]) || (mar[0].gety() == m[2][0] && mar[0].getx() == m[2][1]) || (mar[0].gety() == m[3][0] && mar[0].getx() == m[3][1]) || (mar[0].gety() == m[4][0] && mar[0].getx() == m[4][1]) || (mar[0].gety() == m[5][0] && mar[0].getx() == m[5][1]) || (mar[0].gety() == m[6][0] && mar[0].getx() == m[6][1]) || (mar[0].gety() == m[7][0] && mar[0].getx() == m[7][1]) || (mar[0].gety() == m[8][0] && mar[0].getx() == m[8][1]) || (mar[0].gety() == m[9][0] && mar[0].getx() == m[9][1]) || (mar[0].getx() == khodesh[0][1] && mar[0].gety() == khodesh[1][1]) || (mar[0].getx() == khodesh[0][2] && mar[0].gety() == khodesh[1][2]) || (mar[0].getx() == khodesh[0][3] && mar[0].gety() == khodesh[1][3]) || (mar[0].getx() == khodesh[0][4] && mar[0].gety() == khodesh[1][4]) || (mar[0].getx() == khodesh[0][5] && mar[0].gety() == khodesh[1][5]) || (mar[0].getx() == khodesh[0][6] && mar[0].gety() == khodesh[1][6]) || (mar[0].getx() == khodesh[0][7] && mar[0].gety() == khodesh[1][7])
			|| (mar[0].getx() == khodesh[0][8] && mar[0].gety() == khodesh[1][8]) || (mar[0].getx() == khodesh[0][9] && mar[0].gety() == khodesh[1][9]) || (mar[0].getx() == khodesh[0][10] && mar[0].gety() == khodesh[1][10]) || (mar[0].getx() == khodesh[0][11] && mar[0].gety() == khodesh[1][11]) || (mar[0].getx() == khodesh[0][12] && mar[0].gety() == khodesh[1][12]) || (mar[0].getx() == khodesh[0][13] && mar[0].gety() == khodesh[1][13]) || (mar[0].getx() == khodesh[0][14] && mar[0].gety() == khodesh[1][14]) || (mar[0].getx() == khodesh[0][15] && mar[0].gety() == khodesh[1][15]))
		{
			if (li>0) {
				li--;
				goto restart;
			}
			gotoxy(36, 10);
			cout << " GAME OVER\n\n\n\t\t\t       press R or restart game \n\n\n\t\t\t          press E for exit";
			char g;
			g = _getch();
			if (g == 'r') {
				p = 0;  //score
				goto start;
			}
			else if (g == 'e')
				exit(0);
		}
		//Eating ghaza score
		if (mar[0].getx() == ghx && mar[0].gety() == ghy)
		{
			gotoxy(60, 2);
			p += 10 * l;   //P (from10) multiple in level
			cout << "score : " << p;
			tul++;
			//each level need 15 tul to go next level
			if (tul<10)
				gh1.ghaza(ghx, ghy, 6);
			else
			{
				l++;
				//______________________________
				//if for finishing game
				Fin f1;
				f1.fing();
				goto restart;
			}
		}
	}
}