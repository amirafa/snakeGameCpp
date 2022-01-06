#include <iostream>
#include <stdio.h>
#include <conio.h> //for _getch
#include <stdlib.h>
#include<Windows.h>
#include<random>
using namespace std;

int mar[10][10] = { 0 };
int dir = 1;
int d = 0;
int main() {
	mar[4][2] = 1;
restart:
	while (1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (mar[i][j] == 1) cout << "*";
				else cout << " ";
			}
			cout << endl;
		}
		char b;
		if (_kbhit()) {
			b = _getch();
			if (_kbhit())
				b = _getch();
			//_________________________
			if (b == 'd') { dir = 1; d = 0; }
			if (b == 'a') { dir = -1; d = 0; }
			if (b == 'w') { dir = -1; d = 1; }
			if (b == 's') { dir = 1; d = 1; }
		}
		Sleep(500);
			system("cls");
			if (d==0) {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (mar[i][j] != 0) {
							mar[i][j + dir] = mar[i][j];
							mar[i][j] = mar[i][j - dir];
							if (mar[9][9] == 1 || mar[0][0] == 1) dir *= -1;   //reverse (optional)
							break;
						}
					}
				}
				goto restart;
			}
			if (d==1) {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (mar[i][j] != 0) {
							mar[i+dir][j] = mar[i][j];
							mar[i][j] = mar[i-dir][j];
						//	if (mar[9][9] == 1 || mar[0][0] == 1) dir *= -1;   //reverse (optional)
							break;
						}
					}
				}
				goto restart;
			}
	}
	cin.get();
	cin.get();
}