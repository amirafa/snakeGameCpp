#include <iostream>
#include <windows.h>
using namespace std;
#include <time.h>
#include <conio.h>


int game[20][20] = { 0 };
int snake[2][20];
int i = 0, j = 1, k = 2;
int tool = 3;
int xnew;
int ynew;
int food = 10;

int p = 2;//A=left,D=right,S=down,W=up
		  /*int snake[2][20]={-1};
		  int snake[0][0]=0;
		  int snake[1][0]=0;
		  int snake[0][1]=0;
		  int snake[1][1]=1;
		  int snake[0][2]=0;
		  int snake[1][2]=2;*/
void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		COORD pos = { y,x };
		SetConsoleCursorPosition(hConsole, pos);
	}

}

void rand(int a)
{
	srand(time(0));
	int x, y;
	for (int i = 0; i < 10; i++)
	{
		x = rand() % 20;
		y = rand() % 20;
		if (game[x][y] == 0)
			game[x][y] = a;
		else i--;
	}

}







void show()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j<20; j++)
		{
			gotoxy(5 + i, 10 + j);
			if (game[i][j] == 0)
				cout << " ";
			else if (game[i][j] == 1)
				cout << "*";
			else if (game[i][j] == -1)
				cout << "#";
			else if (game[i][j] == 2)
				cout << "@";
		}
		cout << "\n";
	}
	gotoxy(4, 9);
	printf("%c", 36);
	gotoxy(4, 30);
	printf("%c", 36);
	gotoxy(25, 9);
	printf("%c", 36);
	gotoxy(25, 30);
	printf("%c", 36);
	for (int i = 0; i < 20; i++)
	{
		gotoxy(4, i + 10);
		printf("_");
	}
	for (int i = 0; i < 20; i++)
	{
		gotoxy(25, i + 10);
		printf("_");
	}
	for (int i = 0; i < 20; i++)
	{
		gotoxy(5 + i, 9);
		printf("|");
	}
	for (int i = 0; i < 20; i++)
	{
		gotoxy(5 + i, 30);
		printf("|");
	}
}
void move()
{
	//	snake[0][0] = 0; snake[1][0] = 0;
	game[snake[0][0]][snake[1][0]] = 0;
	snake[0][tool] = xnew;
	snake[1][tool] = ynew;
	for (int l = 0; l<tool; l++)
	{
		snake[0][l] = snake[0][l + 1];
		snake[1][l] = snake[1][l + 1];
	}
	game[xnew][ynew] = 2;

}
void eatmove()
{
	snake[0][tool] = xnew;
	snake[1][tool] = ynew;
	game[xnew][ynew] = 2;
	tool++;
	if (food > 1)food--;
	else {
		system("cls");
		gotoxy(50, 20);
		cout << "You Are Winner";
		_getch();

	}
	//gg
}

void main()
{
	game[0][0] = 2;
	game[0][1] = 2;
	game[0][2] = 2;
	snake[0][0] = i;
	snake[1][0] = i;
	snake[0][1] = i;
	snake[1][1] = j;
	snake[0][2] = i;
	snake[1][2] = k;
	rand(1);
	rand(-1);
	show();
	char c;
	c=_getch();
	while(1)
	{
		if (_kbhit())
		{
			c = _getch();
			switch (c)
			{
			case 'a':
				if (p != 2)
					p = 1;
				break;
			case'd':
				if (p != 1)
					p = 2;
				break;
			case's':
				if (p != 4)
					p = 3;
				break;
			case'w':
				if (p != 3)
					p = 4;
				break;

			}
		}
		switch (p)
		{
		case 1: xnew = snake[0][tool - 1];
			ynew = (snake[1][tool - 1] - 1) % 20;
			break;
		case 2: xnew = snake[0][tool - 1];
			ynew = ((snake[1][tool - 1]) + 1)%20;
			break;
		case 3: xnew = ((snake[0][tool-1]) + 1)%20;
			if (snake[0][tool-1] >20)
			xnew = 0;
			else
			ynew = snake[1][tool-1];
			break;
		case 4: xnew = (snake[0][tool-1] -1)%20;
			if (snake[0][tool - 1]<0  )
			xnew = 20;
			else
			ynew = (snake[1][tool - 1]);
			break;
		}
		switch (game[xnew][ynew])
		{
		case 0:
			move();
			break;
		case -1:
			//	flag = 0;
			break;
		case 1:
			eatmove();
			break;
		}
		Sleep(100);
		show();
	}

}