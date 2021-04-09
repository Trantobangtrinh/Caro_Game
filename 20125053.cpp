#include <iostream>
#include <conio.h>      
#include <Windows.h>    
#include <Mmsystem.h>   // phat nhac
#include <string>
#include <cstdlib>     // random
#include <ctime>       // random
#include <fstream>     // thu vien doc ghi file text
#pragma comment(lib, "Winmm.lib") // thu vien phat nhac
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13
#define SPACE 32
#define BACK 8
#define width 800
#define height 800
using namespace std;
struct Player{
	string name;
	string mode;
	string level;
	string result;
};
Player p[100];
char lv;
int c;
int num, res;
char mangkt[7][7];
int n = 3;
int b = 1;
char ch1 = 'X';
char ch2 = 'O';
char md;
// definition function
void nhap(Player p[100], int& num, char lv, char md, int res);
void statistic(Player p[100], int& num);
void win(int c,char turn);
void printstep(int step);
bool checkwin(char mangkt[7][7], int& hang, int& cot, char k, int n);
void menu(int a);
void play();
int textsetting(int choice, int sel, int a, int b, int k);
void nguoinguoi(int hang, int cot);
void nguoimay(int hang, int cot , char &md);
void draw(int hang, int cot);
// ham set man hinh console
void resizeConsole(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, w, h, TRUE);
}
//ham to mau
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
// Ham dich chuyen con tro.
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
// ham ve man hinh choi
void drawtable() {
	system("cls");
	textcolor(14);
	for (int i = 0; i < 11; ++i) {
		cout << "*";
		if (i == 0 || i == 10) {
			for (int j = 0; j < 104; ++j) {
				cout << "*";
			}
		}
		else
			for (int j = 0; j < 104; ++j)
				cout << " ";
		cout << "*";
		cout << endl;
	}
	for (int i = 0; i < 36; ++i) {
		cout << "\t\t\t\t\t\t\t\t\t    ";
		cout << "*";
		if (i == 35)
			for (int j = 0; j < 28; ++j)
				cout << "*";
		else
			for (int j = 0; j < 28; ++j)
				cout << " ";
		cout << "*";
		cout << endl;
	}
	int x, y;
	switch (n) {
	case 3:
		x = 24;
		y = 25;
		break;
	case 5:
		x = 20;
		y = 23;
		break;
	case 7:
		x = 15;
		y = 21;
		break;
	}
	gotoxy(x, y);
	draw(n, n);
}
//ham ve ban co
void draw(int hang, int cot) {
	textcolor(15);
	switch (n) {
	case 3:
		//tren
		cout << "\t\t" << char(218);
		for (int i = 0; i < hang - 1; ++i) {
			cout << char(196) << char(196) << char(196) << char(194);
		}
		cout << char(196) << char(196) << char(196);
		cout << char(191) << endl;
		//giua
		for (int i = 0; i < hang - 1; ++i) {
			cout << "\t\t\t\t";
			for (int i = 0; i < hang + 1; ++i)
				cout << char(179) << "   ";
			cout << endl << "\t\t\t\t" << char(195);
			for (int j = 0; j < cot - 1; ++j)
				cout << char(196) << char(196) << char(196) << char(197);
			cout << char(196) << char(196) << char(196);
			cout << char(180) << endl;
		}
		cout << "\t\t\t\t";
		for (int j = 0; j < cot + 1; ++j) {
			cout << char(179) << "   ";
		}
		//duoi
		cout << endl << "\t\t\t\t" << char(192);
		for (int i = 0; i < cot - 1; ++i)
			cout << char(196) << char(196) << char(196) << char(193);
		cout << char(196) << char(196) << char(196);
		cout << char(217);
		break;

	case 5:
		//tren
		cout << "\t    " << char(218);
		for (int i = 0; i < hang - 1; ++i) {
			cout << char(196) << char(196) << char(196) << char(194);
		}
		cout << char(196) << char(196) << char(196);
		cout << char(191) << endl;
		//giua
		for (int i = 0; i < hang - 1; ++i) {
			cout << "\t\t\t    ";
			for (int i = 0; i < hang + 1; ++i)
				cout << char(179) << "   ";
			cout << endl << "\t\t\t    " << char(195);
			for (int j = 0; j < cot - 1; ++j)
				cout << char(196) << char(196) << char(196) << char(197);
			cout << char(196) << char(196) << char(196);
			cout << char(180) << endl;
		}
		cout << "\t\t\t    ";
		for (int j = 0; j < cot + 1; ++j) {
			cout << char(179) << "   ";
		}
		//duoi
		cout << endl << "\t\t\t    " << char(192);
		for (int i = 0; i < cot - 1; ++i)
			cout << char(196) << char(196) << char(196) << char(193);
		cout << char(196) << char(196) << char(196);
		cout << char(217);
		break;
	case 7:
		cout << "\t\t" << char(218);
		for (int i = 0; i < hang - 1; ++i) {
			cout << char(196) << char(196) << char(196) << char(194);
		}
		cout << char(196) << char(196) << char(196);
		cout << char(191) << endl;
		//giua
		for (int i = 0; i < hang - 1; ++i) {
			cout << "\t\t\t";
			for (int i = 0; i < hang + 1; ++i)
				cout << char(179) << "   ";
			cout << endl << "\t\t\t" << char(195);
			for (int j = 0; j < cot - 1; ++j)
				cout << char(196) << char(196) << char(196) << char(197);
			cout << char(196) << char(196) << char(196);
			cout << char(180) << endl;
		}
		cout << "\t\t\t";
		for (int j = 0; j < cot + 1; ++j) {
			cout << char(179) << "   ";
		}
		//duoi
		cout << endl << "\t\t\t" << char(192);
		for (int i = 0; i < cot - 1; ++i)
			cout << char(196) << char(196) << char(196) << char(193);
		cout << char(196) << char(196) << char(196);
		cout << char(217);
		break;
	}
	return;

}
// ham print nguoi thang
void win(int c, char turn) {
	while (!(_kbhit())) {
		textcolor(rand() % 15 + 1);
		switch (c) {
		case 1:

			if (turn == '1') {
				gotoxy(20, 3);
				cout << "     ___  __    _         __  __   _   __    __ _____    __";
				gotoxy(20, 4);
				cout << "    / _ \\/ /   /_\\ /\\_/\\ /__\\/__\\ / | / / /\\ \\ \\_   \\/\\ \\ \\";
				gotoxy(20, 5);
				cout << "   / /_)/ /   //_\\\\\\_ _//_\\ / \\// | | \\ \\/  \\/ / / /\\/  \\/ /";
				gotoxy(20, 6);
				cout << "  / ___/ /___/  _  \\/ \\//__/ _  \\ | |  \\  /\\  /\\/ /_/ /\\  /";
				gotoxy(20, 7);
				cout << "  \\/   \\____/\\_/ \\_/\\_/\\__/\\/ \\_/ |_|   \\/  \\/\\____/\\_\\ \\/";
				res = 1;
			}
			else if (turn == '0') {
				gotoxy(20, 3);
				cout << "     ___  __    _         __  __   ____    __    __ _____    __";
				gotoxy(20, 4);
				cout << "    / _ \\/ /   /_\\ /\\_/\\ /__\\/__\\ |___ \\  / / /\\ \\ \\_   \\/\\ \\ \\";
				gotoxy(20, 5);
				cout << "   / /_)/ /   //_\\\\\\_ _//_\\ / \\//   __) | \\ \/  \\/ / / /\\/  \\/ /";
				gotoxy(20, 6);
				cout << "  / ___/ /___/  _  \\/ \\//__/ _  \\  / __/   \\  /\\  /\\/ /_/ /\\  /";
				gotoxy(20, 7);
				cout << "  \\/   \\____/\\_/ \\_/\\_/\\__/\\/ \\_/ |_____|   \\/  \\/\\____/\\_\\ \\/";
				res = 2;
			}
			num = 2;

			break;
		case 2:

			if (turn == '1') {
				gotoxy(15, 3);
				cout << " ____    ____  __    ______ .___________.  ______   .______     ____    ____";
				gotoxy(15, 4);
				cout << " \\   \\  /   / |  |  /      ||           | /  __  \\  |   _  \\    \\   \\  /   /";
				gotoxy(15, 5);
				cout << "  \\   \\/   /  |  | |  ,----'`---|  |----`|  |  |  | |  |_)  |    \\   \\/   /";
				gotoxy(15, 6);
				cout << "   \\      /   |  | |  |         |  |     |  |  |  | |      /      \\_    _/";
				gotoxy(15, 7);
				cout << "    \\    /    |  | |  `----.    |  |     |  `--'  | |  |\\  \\----.   |  |";
				gotoxy(15, 8);
				cout << "     \\__/     |__|  \\______|    |__|      \\______/  | _| `._____|   |__|";
				res = 3;
			}
			else if (turn == '0') {
				gotoxy(12, 3);
				cout << " _______   _______  _______  _______     ___   .___________. _______  _______   ";
				gotoxy(12, 4);
				cout << "|       \\ |   ____||   ____||   ____|   /   \\  |           ||   ____||       \\ ";
				gotoxy(12, 5);
				cout << "|  .--.  ||  |__   |  |__   |  |__     /  ^  \\ `---|  |----`|  |__   |  .--.  | ";
				gotoxy(12, 6);
				cout << "|  |  |  ||   __|  |   __|  |   __|   /  /_\\  \\    |  |     |   __|  |  |  |  | ";
				gotoxy(12, 7);
				cout << "|  '--'  ||  |____ |  |     |  |____ /  _____  \\   |  |     |  |____ |  '--'  | ";
				gotoxy(12, 8);
				cout << "|_______/ |_______||__|     |_______/__/     \\__\\  |__|     |_______||_______/  ";
				res = 4;
			}
			num = 1;

			break;
		}
		Sleep(1000);
	}

	int ch = _getch();

	if (ch == ENTER) {
		nhap(p, num, c, md, res);
		return;
	}
	if (ch == BACK)
		return;

}
//ham print buoc con lai (hard)
void printstep(int step) {
	int x = 77;
	int y = 15;
	gotoxy(x+1, y);
	cout << "   _____ _ ";
	gotoxy(x+1, y + 1);
	cout << "  / ____| | ";
	gotoxy(x+1, y + 2);
	cout << " | (___ | |_ ___ _ __  ___ ";
	gotoxy(x+1, y + 3);
	cout << "  \\___ \\| __/ _ \\ '_ \\/ __| ";
	gotoxy(x+1, y + 4);
	cout << "  ____) | ||  __/ |_) \\__ \\ ";
	gotoxy(x+1, y + 5);
	cout << " |_____/ \\__\\___| .__/|___/ ";
	gotoxy(x+1, y + 6);
	cout << "                | | " ;
	gotoxy(x+1, y + 7);
	cout << "                |_| " ;
	switch (step) {
	case 7:
		textcolor(11);
		gotoxy(x + 12, y + 10);
		cout << "  ______ " ;
		gotoxy(x + 12, y + 11);
		cout << " |____  |" ;
		gotoxy(x + 12, y + 12);
		cout << "     / / " ;
		gotoxy(x + 12, y + 13);
		cout << "    / /  " ;
		gotoxy(x + 12, y + 14);
		cout << "   / /   " ;
		gotoxy(x + 12, y + 15);
		cout << "  /_/    " ;
		break;
	case 6:
		textcolor(11);
		gotoxy(x + 12, y + 10);
		cout << "    __   " ;
		gotoxy(x + 12, y + 11);
		cout << "   / /   " ;
		gotoxy(x + 12, y + 12);
		cout << "  / /_   " ;
		gotoxy(x + 12, y + 13);
		cout << " | '_ \\ " ;
		gotoxy(x + 12, y + 14);
		cout << " | (_) | " ;
		gotoxy(x + 12, y + 15);
		cout << "  \\___/ " ;
		break;
	case 5:
		textcolor(11);
		gotoxy(x + 12, y + 10);
		cout << "  _____  " ;
		gotoxy(x + 12, y + 11);
		cout << " | ____| " ;
		gotoxy(x + 12, y + 12);
		cout << " | |__   " ;
		gotoxy(x + 12, y + 13);
		cout << " |___ \\ ";
		gotoxy(x + 12, y + 14);
		cout << "  ___) | " ;
		gotoxy(x + 12, y + 15);
		cout << " |____/  ";
		break;
	case 4:
		textcolor(11);
		gotoxy(x + 12, y + 10);
		cout << "  _  _   " ;
		gotoxy(x + 12, y + 11);
		cout << " | || |  " ;
		gotoxy(x + 12, y + 12);
		cout << " | || |_ " ;
		gotoxy(x + 12, y + 13);
		cout << " |__   _|" ;
		gotoxy(x + 12, y + 14);
		cout << "    | |  " ;
		gotoxy(x + 12, y + 15);
		cout << "    |_|  " ;
		break;
	case 3:
		textcolor(12);
		gotoxy(x + 12, y + 10);
		cout << "  ____   " ;
		gotoxy(x + 12, y + 11);
		cout << " |___ \\ " ;
		gotoxy(x + 12, y + 12);
		cout << "   __) | " ;
		gotoxy(x + 12, y + 13);
		cout << "  |__ <  " ;
		gotoxy(x + 12, y + 14);
		cout << "  ___) | " ;
		gotoxy(x + 12, y + 15);
		cout << " |____/  ";
		break;
	case 2:
		textcolor(12);
		gotoxy(x + 12, y + 10);
		cout << "  ___    " ;
		gotoxy(x + 12, y + 11);
		cout << " |__ \\  " ;
		gotoxy(x + 12, y + 12);
		cout << "    ) |  " ;
		gotoxy(x + 12, y + 13);
		cout << "   / /   " ;
		gotoxy(x + 12, y + 14);
		cout << "  / /_   " ;
		gotoxy(x + 12, y + 15);
		cout << " |____|  " ;
		break;
	case 1:
		textcolor(12);
		gotoxy(x + 12, y + 10);
		cout << "  __     " ;
		gotoxy(x + 12, y + 11);
		cout << " /_ |    " ;
		gotoxy(x + 12, y + 12);
		cout << "  | |    " ;
		gotoxy(x + 12, y + 13);
		cout << "  | |    " ;
		gotoxy(x + 12, y + 14);
		cout << "  | |    " ;
		gotoxy(x + 12, y + 15);
		cout << "  |_|    ";
		break;
	case 0:
		textcolor(12);
		gotoxy(x + 12, y + 10);
		cout << "   ___   " ;
		gotoxy(x + 12, y + 11);
		cout << "  / _ \\ " ;
		gotoxy(x + 12, y + 12);
		cout << " | | | | " ;
		gotoxy(x + 12, y + 13);
		cout << " | | | | " ;
		gotoxy(x + 12, y + 14);
		cout << " | |_| | " ;
		gotoxy(x + 12, y + 15);
		cout << "  \\___/ " ;
	}
}
// ham print ket qua hoa
void printdraw() {
	while (!(_kbhit())) {
		textcolor(rand() % 15 + 1);
		gotoxy(20, 3);
		cout << "    ____  ____  ___ _       __ ";
		gotoxy(20, 4);
		cout << "   / __ \\/ __ \\/   | |     / /" << endl;
		gotoxy(20, 5);
		cout << "  / / / / /_/ / /| | | /| / / " << endl;
		gotoxy(20, 6);
		cout << " / /_/ / _, _/ ___ | |/ |/ / " << endl;
		gotoxy(20, 7);
		cout << "/_____/_/ |_/_/  |_|__/|__/ " << endl;
		Sleep(1000);
	}
	res = 5;
	int ch = _getch();

	if (ch == ENTER) {
		nhap(p, num, c, md, res);
		return;
	}
	if (ch == BACK)
		return;
}
// ham check ngang
int ngang(char mangkt[7][7], int& hang, int& cot, char k, int n)
{
	int dem = 0;
	for (int i = cot; i < n; i++) {
		if (mangkt[hang][i] == k)
			++dem;
		else
			break;
	}
	for (int i = cot - 1; i >= 0; i--) {
		if (mangkt[hang][i] == k)
			++dem;
		else
			break;
	}
	//cout << dem;
	return dem;
}
// ham check doc
int doc(char mangkt[7][7], int& hang, int& cot, char k, int n)
{
	int dem = 0;
	for (int i = hang; i < n; i++)
		if (mangkt[i][cot] == k)
			++dem;
		else
			break;
	for (int i = hang - 1; i >= 0; i--)
		if (mangkt[i][cot] == k)
			++dem;
		else
			break;
	//cout << dem;
	return dem;
}
// ham check cheo chinh
int cheochinh(char mangkt[7][7], int& hang, int& cot, char k, int n) {
	int dem = 0;
	int j = cot;
	for (int i = hang; i < n; i++) {
		if (j < n) {
			if (mangkt[i][j] == k)
				++dem;
			else
				break;
			j++;
		}
	}
	j = cot - 1;
	for (int i = hang - 1; i >= 0; i--) {
		if (j >= 0) {
			if (mangkt[i][j] == k)
				++dem;
			else
				break;
			j--;
		}
	}
	return dem;
}
//ham check cheo phu
int cheophu(char mangkt[][7], int& hang, int& cot, char k, int n) {
	int dem = 0;
	int j = cot;
	for (int i = hang; i < n; i++) {
		if (j >= 0) {
			if (mangkt[i][j] == k)
				++dem;
			else
				break;
			j--;
		}
	}
	j = cot + 1;
	for (int i = hang - 1; i >= 0; i--) {
		if (j < n) {
			if (mangkt[i][j] == k)
				++dem;
			else
				break;
			j++;
		}
	}
	return dem;
}
//ham check win tong
bool checkwin(char mangkt[7][7], int& hang, int& cot, char k, int n) {
	switch (n) {
	case 3:
		if (doc(mangkt, hang, cot, k, n) == 3 || ngang(mangkt, hang, cot, k, n) == 3 || cheochinh(mangkt, hang, cot, k, n) == 3 || cheophu(mangkt, hang, cot, k, n) == 3)
			return true;
		break;
	case 5:
		if (doc(mangkt, hang, cot, k, n) >= 5 || ngang(mangkt, hang, cot, k, n) >= 5 || cheochinh(mangkt, hang, cot, k, n) >= 5 || cheophu(mangkt, hang, cot, k, n) == 5)
			return true;
		break;
	case 7:
		if (doc(mangkt, hang, cot, k, n) >=6 || ngang(mangkt, hang, cot, k, n) >= 6 || cheochinh(mangkt, hang, cot, k, n) >= 6 || cheophu(mangkt, hang, cot, k, n) >= 6)
			return true;
		break;
	}
	return false;
}
// nguoi vs nguoi
void nguoinguoi(int hang, int cot) {
	int count = 0;
	drawtable();
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			mangkt[i][j] = NULL;
		}
	}
	int x = 39;
	int y = 28;
	gotoxy(x, y);
	int n = hang;
	switch (n) {
	case 3:
		hang = 1;
		cot = 1;
		break;
	case 5:
		hang = 2;
		cot = 2;
		break;
	case 7:
		hang = 3;
		cot = 3;
		break;
	}
	bool loop = true;
	char turn = '1';
	while (loop) {
		int ch = _getch();
		switch (ch){
		case UP:
			hang--;
			y -= 2;
			break;
		case DOWN:
			hang++;
			y += 2;
			break;
		case RIGHT:
			cot++;
			x += 4;
			break;
		case LEFT:
			cot--;
			x -= 4;
			break;
		case ENTER:
			if (turn == '1'){
				if (mangkt[hang][cot] == NULL) {
					mangkt[hang][cot] = '1';
					count++;
					textcolor(9);
					cout << ch1;
					if (checkwin(mangkt, hang, cot, turn, n) == true) {
						win(c, turn);
						loop = false;
						break;
					}
					else if (count == n * n)
						printdraw();
					turn = '0';
				}
			}
			else if (turn == '0') {
				if (mangkt[hang][cot] == NULL) {
					mangkt[hang][cot] = '0';
					count++;
					textcolor(13);
					cout << ch2;
					if (checkwin(mangkt, hang, cot, turn, n) == true) {
						win(c, turn);
						loop = false;
						break;
					}
					else if (count == n * n)
						printdraw();
					turn = '1';
				}
			}
			break;
		case BACK:
			return;
		}
		switch (n) {
		case 3:
			if (hang > 2)
				hang = 0;
			if (hang < 0)
				hang = 2;
			if (cot < 0)
				cot = 2;
			if (cot > 2)
				cot = 0;
			if (x < 35)
				x = 43;
			if (x > 43)
				x = 35;
			if (y > 30)
				y = 26;
			if (y < 26)
				y = 30;
			break;
		case 5:
			if (hang > 4)
				hang = 0;
			if (hang < 0)
				hang = 4;
			if (cot < 0)
				cot = 4;
			if (cot > 4)
				cot = 0;
			if (y < 24)
				y = 32;
			if (y > 32)
				y = 24;
			if (x < 31)
				x = 47;
			if (x > 47)
				x = 31;
			break;
		case 7:
			if (hang < 0)
				hang = 6;
			if (hang > 6)
				hang = 0;
			if (cot < 0)
				cot = 6;
			if (cot > 6)
				cot = 0;
			if (y < 22)
				y = 34;
			if (y > 34)
				y = 22;
			if (x < 27)
				x = 51;
			if (x > 51)
				x = 27;
			break;
		}

		gotoxy(x, y);
	}
}
// mang danh dau de chan
void mang(char mangkt[7][7], int& hang, int& cot, int n)
{
	char k = '1';
	//3x3
	switch (n)
	{
	case 3:
		if (ngang(mangkt, hang, cot, k, n) == 2)
		{
			for (int i = cot; i < n; i++)
				if (mangkt[hang][i] == NULL)
					mangkt[hang][i] = '*';

			for (int i = cot - 1; i >= 0; i--)
				if (mangkt[hang][i] == NULL)
					mangkt[hang][i] = '*';

		};

		if (doc(mangkt, hang, cot, k, n) == 2)
		{
			for (int i = hang; i < n; i++)
				if (mangkt[i][cot] == NULL)
					mangkt[i][cot] = '*';

			for (int i = hang - 1; i >= 0; i--)
				if (mangkt[i][cot] == NULL)
					mangkt[i][cot] = '*';

		}

		if (cheochinh(mangkt, hang, cot, k, n) == 2)
		{
			int j = cot;
			for (int i = hang; i < n; i++)
				if (j < n)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j++;
				}


			j = cot - 1;
			for (int i = hang - 1; i >= 0; i--)
				if (j >= 0)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j--;
				}
		};

		if (cheophu(mangkt, hang, cot, k, n) == 2)
		{
			int j = cot;
			for (int i = hang; i < n; i++)
				if (j >= 0)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j--;
				}


			j = cot + 1;
			for (int i = hang - 1; i >= 0; i--)
				if (j < n)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j++;
				}
		};
		break;
	case 5:
		if (ngang(mangkt, hang, cot, k, n) >= 3)
		{
			for (int i = cot; i < n; i++)
				if (mangkt[hang][i] == NULL)
					mangkt[hang][i] = '*';

			for (int i = cot - 1; i >= 0; i--)
				if (mangkt[hang][i] == NULL)
					mangkt[hang][i] = '*';

		};

		if (doc(mangkt, hang, cot, k, n) >= 3)
		{
			for (int i = hang; i < n; i++)
				if (mangkt[i][cot] == NULL)
					mangkt[i][cot] = '*';

			for (int i = hang - 1; i >= 0; i--)
				if (mangkt[i][cot] == NULL)
					mangkt[i][cot] = '*';

		}

		if (cheochinh(mangkt, hang, cot, k, n) >= 3)
		{
			int j = cot;
			for (int i = hang; i < n; i++)
				if (j < n)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j++;
				}


			j = cot - 1;
			for (int i = hang - 1; i >= 0; i--)
				if (j >= 0)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j--;
				}
		};

		if (cheophu(mangkt, hang, cot, k, n) >= 3)
		{
			int j = cot;
			for (int i = hang; i < n; i++)
				if (j >= 0)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j--;
				}


			j = cot + 1;
			for (int i = hang - 1; i >= 0; i--)
				if (j < n)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j++;
				}
		};
		break;

	case 7:
		if (ngang(mangkt, hang, cot, k, n) >= 3)
		{
			for (int i = cot; i < n; i++)
				if (mangkt[hang][i] == NULL)
					mangkt[hang][i] = '*';

			for (int i = cot - 1; i >= 0; i--)
				if (mangkt[hang][i] == NULL)
					mangkt[hang][i] = '*';

		};

		if (doc(mangkt, hang, cot, k, n) >= 3 )
		{
			for (int i = hang; i < n; i++)
				if (mangkt[i][cot] == NULL)
					mangkt[i][cot] = '*';

			for (int i = hang - 1; i >= 0; i--)
				if (mangkt[i][cot] == NULL)
					mangkt[i][cot] = '*';

		}

		if (cheochinh(mangkt, hang, cot, k, n) >= 3)
		{
			int j = cot;
			for (int i = hang; i < n; i++)
				if (j < n)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j++;
				}


			j = cot - 1;
			for (int i = hang - 1; i >= 0; i--)
				if (j >= 0)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j--;
				}
		};

		if (cheophu(mangkt, hang, cot, k, n) >= 3)
		{
			int j = cot;
			for (int i = hang; i < n; i++)
				if (j >= 0)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j--;
				}


			j = cot + 1;
			for (int i = hang - 1; i >= 0; i--)
				if (j < n)
				{
					if (mangkt[i][j] == NULL)
						mangkt[i][j] = '*';
					j++;
				}
		};
		break;
	}
}
// nguoi vs may 3 che do
void nguoimay(int hang, int cot, char &md) {
	srand(time(NULL));
	drawtable();
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			mangkt[i][j] = NULL;
		}
	}
	int step33 = 4;
	int step55 = 6;
	int step77 = 8;
	int step;
	int x = 39;
	int y = 28;
	gotoxy(x, y);
	int count = 0;
	int n = hang;
	switch (n){
	case 3:
		hang = 1;
		cot = 1;
		break;
	case 5:
		hang = 2;
		cot = 2;
		break;
	case 7:
		hang = 3;
		cot = 3;
	}
	int row;
	int col;
	bool loop = true;
	char turn = '1';
	switch (n) {
	case 3:
		step = step33;
		break;
	case 5:
		step = step55;
		break;
	case 7:
		step = step77;
		break;
	}
	switch (md) {
	case 'e':
		while (loop)
		{
			int ch = _getch();
			switch (ch)
			{
			case UP:
				hang--;
				y -= 2;
				break;
			case DOWN:
				hang++;
				y += 2;
				break;
			case RIGHT:
				cot++;
				x += 4;
				break;
			case LEFT:
				cot--;
				x -= 4;
				break;
			case ENTER:
				if (turn == '1')
				{
						mangkt[hang][cot] = '1';
						textcolor(9);
						cout << ch1;
						count++;

						if (checkwin(mangkt, hang, cot, turn, n) == true) {
							win (c,turn);
							_getch();
							loop = false;
							break;
						}
						else if (count == n * n) {
							printdraw();
							_getch();
						}
						turn = '0';
					
				}

				if (turn == '0')
				{
					do {
						row = rand() % n;
						col = rand() % n;
					} while (mangkt[row][col] != NULL);
					
					mangkt[row][col] = '0';
					gotoxy(10, 10);
					switch (n) {
					case 3:
						y = 2 * row + 26;
						x = 4 * col + 35;
						break;
					case 5:
						y = 2 * row + 24;
						x = 4 * col + 31;
						break;
					case 7:
						y = 2 * row + 22;
						x = 4 * col + 27;
						break;
					}
					gotoxy(x, y);
					
					textcolor(13);
					cout << ch2;
					hang = row;
					cot = col;
					count++;

					if (checkwin(mangkt, row, col, turn, n) == true) {
						win (c,turn);
						_getch();
						loop = false;
						break;
					}
					else if (count == n * n) {
						printdraw();
						_getch();
					}
					turn = '1';
					
				}
				break;
			case BACK:
				return;
			}
			switch (n) {
			case 3:
				if (hang > 2)
					hang = 0;
				if (hang < 0)
					hang = 2;
				if (cot < 0)
					cot = 2;
				if (cot > 2)
					cot = 0;
				if (x < 35)
					x = 43;
				if (x > 43)
					x = 35;
				if (y > 30)
					y = 26;
				if (y < 26)
					y = 30;
				break;
			case 5:
				if (hang > 4)
					hang = 0;
				if (hang < 0)
					hang = 4;
				if (cot < 0)
					cot = 4;
				if (cot > 4)
					cot = 0;
				if (y < 24)
					y = 32;
				if (y > 32)
					y = 24;
				if (x < 31)
					x = 47;
				if (x > 47)
					x = 31;
				break;
			case 7:
				if (hang < 0)
					hang = 6;
				if (hang > 6)
					hang = 0;
				if (cot < 0)
					cot = 6;
				if (cot > 6)
					cot = 0;
				if (y < 22)
					y = 34;
				if (y > 34)
					y = 22;
				if (x < 27)
					x = 51;
				if (x > 51)
					x = 27;
				break;
			}

			gotoxy(x, y);
		}
		break;
	case 'm':
		while (loop)
		{
			int ch = _getch();
			switch (ch)
			{
			case UP:
				hang--;
				y -= 2;
				break;
			case DOWN:
				hang++;
				y += 2;
				break;
			case RIGHT:
				cot++;
				x += 4;
				break;
			case LEFT:
				cot--;
				x -= 4;
				break;
			case ENTER:
				if (turn == '1')
				{
					if (mangkt[hang][cot] != '0' && mangkt[hang][cot] != '1') {
						mangkt[hang][cot] = '1';
						textcolor(9);
						cout << ch1;
						count++;

						if (checkwin(mangkt, hang, cot, turn, n) == true) {
							win(c,turn);
							loop = false;
							break;
						}
						else if (count == n * n)
							printdraw();
						turn = '0';
					}
				}

				if (turn == '0') {
					int k = 0;
					mang(mangkt, hang, cot, n);

					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
						{
							if (mangkt[i][j] == '*')
							{
								row = i;
								col = j;
								k = 10;
								break;
							}
						}
					if (k != 10) {
						do {
							row = rand() % n;
							col = rand() % n;
						} while (mangkt[row][col] != NULL);
					}
					switch (n) {
						case 3:
							y = 2 * row + 26;
							x = 4 * col + 35;
							break;
						case 5:
							y = 2 * row + 24;
							x = 4 * col + 31;
							break;
						case 7:
							y = 2 * row + 22;
							x = 4 * col + 27;
							break;
					}
					gotoxy(x, y);
						
					mangkt[row][col] = '0';
					hang = row;
					cot = col;
					textcolor(13);
					cout << ch2;
					count++;

					if (checkwin(mangkt, row, col, turn, n) == true) {
						win(c, turn);
						loop = false;
						break;
					}
					else if (count == n * n) {
						printdraw();
						_getch();
					}
					turn = '1';
						
				}
				break;
			case BACK:
				return;
			}
			switch (n) {
			case 3:
				if (hang > 2)
					hang = 0;
				if (hang < 0)
					hang = 2;
				if (cot < 0)
					cot = 2;
				if (cot > 2)
					cot = 0;
				if (x < 35)
					x = 43;
				if (x > 43)
					x = 35;
				if (y > 30)
					y = 26;
				if (y < 26)
					y = 30;
				break;
			case 5:
				if (hang > 4)
					hang = 0;
				if (hang < 0)
					hang = 4;
				if (cot < 0)
					cot = 4;
				if (cot > 4)
					cot = 0;
				if (y < 24)
					y = 32;
				if (y > 32)
					y = 24;
				if (x < 31)
					x = 47;
				if (x > 47)
					x = 31;
				break;
			case 7:
				if (hang < 0)
					hang = 6;
				if (hang > 6)
					hang = 0;
				if (cot < 0)
					cot = 6;
				if (cot > 6)
					cot = 0;
				if (y < 22)
					y = 34;
				if (y > 34)
					y = 22;
				if (x < 27)
					x = 51;
				if (x > 51)
					x = 27;
				break;
			}
			
			gotoxy(x, y);
		}
		break;
	case 'h':
		while (loop)
		{
			turn = '1';
			
			int ch = _getch();
			switch (ch)
			{
			case UP:
				hang--;
				y -= 2;
				break;
			case DOWN:
				hang++;
				y += 2;
				break;
			case RIGHT:
				cot++;
				x += 4;
				break;
			case LEFT:
				cot--;
				x -= 4;
				break;
			case ENTER:
				if (turn == '1')
				{
					if (mangkt[hang][cot] == NULL || mangkt[hang][cot]=='*') {
						mangkt[hang][cot] = '1';
						textcolor(9);
						cout << ch1;
						count++;

						step--;
						if (checkwin(mangkt, hang,cot, turn, n) == true) {
							win(c,turn);
							loop = false;
							_getch();
							break;
							
						}
						else if (count == n * n)
							printdraw();

						turn = '0';
					}
				}
				if (turn == '0') {
					int k = 0;
					mang(mangkt, hang, cot, n);

					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
						{
							if (mangkt[i][j] == '*')
							{
								row = i;
								col = j;
								k = 10;
								break;
							}
						}
					
					printstep(step);
					if (k != 10) {
						do {
							row = rand() % n;
							col = rand() % n;
						} while (mangkt[row][col] != NULL);
					}
					if (step == n) {
						switch (n) {
						case 3:
							if (mangkt[1][1] == NULL) {
								row = 1;
								col = 1;
							}
							break;
						case 5:
							if (mangkt[2][2] == NULL) {
								row = 2;
								col = 2;
							}
							break;
						case 7:
							if (mangkt[3][3] == NULL) {
								row = 3;
								col = 3;
							}
							break;
						}
					}
					switch (n) {
					case 3:
						y = 2 * row + 26;
						x = 4 * col + 35;
						break;
					case 5:
						y = 2 * row + 24;
						x = 4 * col + 31;
						break;
					case 7:
						y = 2 * row + 22;
						x = 4 * col + 27;
						break;
					}
					gotoxy(x, y);
					
					mangkt[row][col] = '0';
					hang = row;
					cot = col;
					textcolor(13);
					cout << ch2;
					count++;
					if (checkwin(mangkt, row, col, turn, n) == true || step == 0) {
						win(c,turn);
						loop = false;
						_getch();
						break;
						
					}
					if (count == n * n)
						printdraw();
					turn = '1';
					
				}
				break;
			case BACK:
				return;
			}
			switch (n) {
			case 3:
				if (hang > 2)
					hang = 0;
				if (hang < 0)
					hang = 2;
				if (cot < 0)
					cot = 2;
				if (cot > 2)
					cot = 0;
				if (x < 35)
					x = 43;
				if (x > 43)
					x = 35;
				if (y > 30)
					y = 26;
				if (y < 26)
					y = 30;
				break;
			case 5:
				if (hang > 4)
					hang = 0;
				if (hang < 0)
					hang = 4;
				if (cot < 0)
					cot = 4;
				if (cot > 4)
					cot = 0;
				if (y < 24)
					y = 32;
				if (y > 32)
					y = 24;
				if (x < 31)
					x = 47;
				if (x > 47)
					x = 31;
				break;
			case 7:
				if (hang < 0)
					hang = 6;
				if (hang > 6)
					hang = 0;
				if (cot < 0)
					cot = 6;
				if (cot > 6)
					cot = 0;
				if (y < 22)
					y = 34;
				if (y > 34)
					y = 22;
				if (x < 27)
					x = 51;
				if (x > 51)
					x = 27;
				break;
			}

			gotoxy(x, y);
		}
		break;
	}
}
//ham ve menu setting
int textsetting(int choice, int sel, int a, int b, int k) {
	system("cls");
	textcolor(rand()%15+1);
	cout << endl << endl << endl << endl;
	cout << "                              _____  ______  _______  _______  _____  _   _   _____" << endl;
	cout << "                             / ____||  ____||__   __||__   __||_   _|| \\ | | / ____|" << endl;
	cout << "                            | (___  | |__      | |      | |     | |  |  \\| || |  __ " << endl;
	cout << "                             \\___ \\ |  __|     | |      | |     | |  | . ` || | |_ |" << endl;
	cout << "                             ____) || |____    | |      | |    _| |_ | |\\  || |__| |" << endl;
	cout << "                            |_____/ |______|   |_|      |_|   |_____||_| \\_| \\_____|" << endl;
	textcolor(7);
	cout << endl << endl << endl << endl << endl << endl;
	if (a == 0)
		textcolor(10);
	cout << "             ___             " << endl;
	cout << "            |_ _|__ ___ _ _  " << endl;
	cout << "             | |/ _/ _ \\ ' \\" << endl;
	cout << "            |___\\__\\___/_||_|" << endl;
	textcolor(7);
	
	if (choice == 0 && a==0)
		textcolor(10);
	gotoxy(35, 17);
	cout << "       ___      ___          ____ " ;
	gotoxy(35, 18);
	cout << "      / _ \\___ / _/__ ___ __/ / /_" ;
	gotoxy(35, 19);
	cout << "     / // / -_) _/ _ `/ // / / __/" ;
	gotoxy(35, 20);
	cout << "    /____/\\__/_/ \\_,_/\\_,_/_/\\__/" ;
	textcolor(7);
	if ( a == 0 && choice == 1) 
		textcolor(10);
	gotoxy(70, 17);
	cout << "     _______                     " ;
	gotoxy(70, 18);
	cout << "    / ___/ /  ___ ____  ___ ____ " ;
	gotoxy(70, 19);
	cout << "   / /__/ _ \\/ _ `/ _ \\/ _ `/ -_) ";
	gotoxy(70, 20);
	cout << "   \\___/_//_/\\_,_/_//_/\\_, /\\__/" ;
	gotoxy(70, 21);
	cout << "                      /___/";
	textcolor(7);
	if (choice == 1 && a == 0 && k == 1){
		
		cout << endl << "         Please enter the symbol player 1 (or you) want to play:      ";
		textcolor(10);
		cin >> ch1;
		textcolor(7);
		cout << endl << "         Please enter the symbol player 2 want (or you want computer) to play:       ";
		textcolor(10);
		cin >> ch2;
	}
	textcolor(7);
	cout << endl << endl << endl << endl;
	if (a == 1)
		textcolor(10);
	cout << "        ___ _        " << endl;
	cout << "       / __(_)______ " << endl;
	cout << "       \\__ \\ |_ / -_)" << endl;
	cout << "       |___/_/__\\___|" << endl;
	textcolor(7);
	if (sel == 3 && a == 1)
		textcolor(10);
	gotoxy(30, 25);
	cout << "  ____    ____";
	gotoxy(30, 26);
	cout << " |__ /_ _|__ /" ;
	gotoxy(30, 27);
	cout << "  |_ \\ \\ /|_ \\";
	gotoxy(30, 28);
	cout << " |___/_\\_\\___/";
	textcolor(7);
	if (sel == 5 && a == 1)
		textcolor(10);
	gotoxy(55, 25);
	cout << "  ___     ___ ";
	gotoxy(55, 26);
	cout << " | __|_ _| __|";
	gotoxy(55, 27);
	cout << " |__ \\ \\ /__ \\";
	gotoxy(55, 28);
	cout << " |___/_\\_\\___/";
	textcolor(7);
	if (sel == 7 && a==1)
		textcolor(10);
	gotoxy(80, 25);
	cout << "  ____     ____ ";
	gotoxy(80, 26);
	cout << " |__  |_ _|__  |";
	gotoxy(80, 27);
	cout << "   / /\\ \\ / / /";
	gotoxy(80, 28);
	cout << "  /_/ /_\\_\\/_/";
	cout << endl << endl << endl << endl << endl;
	textcolor(7);
	if (a == 2)
		textcolor(10);
	cout << "                __  __         _    " << endl;
	cout << "               |  \\/  |_  _ __(_)__" << endl;
	cout << "               | |\\/| | || (_-< / _|" << endl;
	cout << "               |_|  |_|\\_,_/__/_\\__|" << endl;
	if (b == 1 && a==2) {
		textcolor(10);
		gotoxy(50, 33);
		cout << "   ___       ";
		gotoxy(50, 34);
		cout << "  / _ \\ _ _";
		gotoxy(50, 35);
		cout << " | (_) | ' \\ ";
		gotoxy(50, 36);
		cout << "  \\___/|_||_|";
	}
	textcolor(7);
	if (b == 0 && a == 2) {
		textcolor(10);
		gotoxy(75, 33);
		cout << "   ___   __  __";
		gotoxy(75, 34);
		cout << "  / _ \\ / _|/ _|";
		gotoxy(75, 35);
		cout << " | (_) |  _|  _|";
		gotoxy(75, 36);
		cout << "  \\___/|_| |_|";
	}
	textcolor(7);
	return sel;
}
//ham dieu khien setting
void setting() {
	int ch;
	int a = 0;
	int sel = 3;
	int choice = 0;
	int k = 0;
	while (true) {
		bool lap2 = true;
		bool lap0 = true;
		bool lap1 = true;
		textsetting(choice, sel, a, b, k);
		ch = _getch();
		switch (ch) {
		case UP:
			a--;
			break;
		case DOWN:
			a++;
			break;
		case ENTER:
			switch (a) {
			case 0:
				while (lap2 == true) {
					textsetting(choice, sel, a, b, k);
					ch = _getch();
					switch (ch) {
					case LEFT:
						choice--;
						break;
					case RIGHT:
						choice++;
						break;
					case ENTER:
						switch(choice){
						case 0:
							ch1 = 'X';
							ch2 = 'O';
							break;
						case 1:
							k = 1;
							textsetting(choice, sel, a, b, k);
							break;
						}
						a = 1;
						lap2 = false;
						break;
					case BACK:
						return setting();
					}

					if (choice < 0)
						choice = 1;
					if (choice > 1)
						choice = 0;
				}
			case 1:
				while (lap0 == true) {
					textsetting(choice, sel, a, b, k);
					ch = _getch();
					switch (ch) {
					case LEFT:
						sel -= 2;
						break;
					case RIGHT:
						sel += 2;
						break;
					case ENTER:
						n = sel;
						lap0 = false;
						a = 2;
						break;
					case BACK:
						return setting();
					}
					if (sel < 3)
						sel = 7;
					if (sel > 7)
						sel = 3;
				}
			case 2:
				while (lap1 == true) {
					textsetting(choice, sel, a, b, k);
					ch = _getch();
					switch (ch) {
					case ENTER:
						b = abs(b - 1);
						if (b == 0) {
							PlaySound(NULL, 0, 0);
							break;
						}
						if (b == 1) {
							PlaySound(TEXT("song.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
							break;
						}
						break;
					case BACK:
						return setting();
					}
				}
			}
			break;
		case BACK:
			return;
		}
		if (a > 2)
			a = 0;
		if (a < 0)
			a = 2;
	}
	
}
// ham ve che do choi
void drawmode(int c) {
	system("cls");
	cout << endl << endl << endl << endl << endl;
	textcolor(rand()%10+1);
	cout << "                                       ____    ___" << endl;
	cout << "                                      /\\  _`\\ /\\_ \\" << endl;
	cout << "                                      \\ \\ \\L\\ \\//\\ \\      __     __  __" << endl;
	cout << "                                       \\ \\ ,__/ \\ \\ \\   /'__`\\  /\\ \\/\\ \\ " << endl;
	cout << "                                        \\ \\ \\/   \\_\\ \\_/\\ \\L\\.\\_\\ \\ \\_\\ \\" << endl;
	cout << "                                         \\ \\_\\   /\\____\\ \\__/.\\_\\/`____  \\" << endl; 
	cout << "                                          \\/_/   \\/____/\\/__/\\/_/ `/___/> \\" << endl;
	cout << "                                                                     /\\___/" << endl;
	cout << "                                                                     \\/__/ " << endl;
	textcolor(6);
	cout << endl << endl << endl << endl << endl << endl;
	if (c == 1)
		textcolor(11);
	cout << "                                                ____        ____" << endl;
	cout << "                                               |  _ \\__   _|  _ \\" << endl;
	cout << "                                               | |_) \\ \\ / / |_) |" << endl;
	cout << "                                               |  __/ \\ V /|  __/" << endl;
	cout << "                                               |_|     \\_/ |_|" << endl;
	textcolor(6);
	cout << endl << endl << endl << endl;
	if (c == 2)
		textcolor(11);
	cout << "                                                ____         ____" << endl;
	cout << "                                               |  _ \\__   __/ ___|" << endl;
	cout << "                                               | |_) \\ \\ / / |" << endl;
	cout << "                                               |  __/ \\ V /| |___" << endl;
	cout << "                                               |_|     \\_/  \\____|" << endl;
	textcolor(6);
}
// ham ve cap do choi
void drawlevel(int r) {
	system("cls");
	cout << endl << endl << endl;
	textcolor(rand()%15+1);
	cout << "                                       ____    ___" << endl;
	cout << "                                      /\\  _`\\ /\\_ \\" << endl;
	cout << "                                      \\ \\ \\L\\ \\//\\ \\      __     __  __" << endl;
	cout << "                                       \\ \\ ,__/ \\ \\ \\   /'__`\\  /\\ \\/\\ \\ " << endl;
	cout << "                                        \\ \\ \\/   \\_\\ \\_/\\ \\L\\.\\_\\ \\ \\_\\ \\" << endl;
	cout << "                                         \\ \\_\\   /\\____\\ \\__/.\\_\\/`____  \\" << endl;
	cout << "                                          \\/_/   \\/____/\\/__/\\/_/ `/___/> \\" << endl;
	cout << "                                                                     /\\___/" << endl;
	cout << "                                                                     \\/__/ " << endl;
	cout << endl << endl << endl << endl;
	textcolor(6);
	if (r == 1)
		textcolor(11);
	cout << "                                                _____" << endl;
	cout << "                                               | ____|__ _ ___ _   _" << endl;
	cout << "                                               |  _| / _` / __| | | |" << endl;
	cout << "                                               | |__| (_| \\__ \\ |_| |" << endl;
	cout << "                                               |_____\\__,_|___/\\__, |" << endl;
	cout << "                                                               |___/" << endl;
	cout << endl << endl << endl;
	textcolor(6);
	if (r == 2)
		textcolor(11);
	cout << "                                         __  __          _ _" << endl;
	cout << "                                        |  \\/  | ___  __| (_)_   _ _ __ ___" << endl;
	cout << "                                        | |\\/| |/ _ \\/ _` | | | | | '_ ` _ \\" << endl;
	cout << "                                        | |  | |  __/ (_| | | |_| | | | | | |" << endl;
	cout << "                                        |_|  |_|\\___|\\__,_|_|\\__,_|_| |_| |_|" << endl;
	cout << endl << endl << endl;
	textcolor(6);
	if (r == 3)
		textcolor(11);
	cout << "                                               _   _               _" << endl;
	cout << "                                              | | | | __ _ _ __ __| |" << endl;
	cout << "                                              | |_| |/ _` | '__/ _` |" << endl;
	cout << "                                              |  _  | (_| | | | (_| |" << endl;
	cout << "                                              |_| |_|\\__,_|_|  \\__,_|" << endl;
	textcolor(6);
                                      
}
// ham dieu khien menu de bat dau choi
void play() {
	int ch;
	c = 1;
	int r = 1;
	while (true) {
		drawmode(c);
		ch = _getch();
		switch (ch) {
		case UP:
			c--;
			break;
		case DOWN:
			c++;
			break;
		case ENTER:
			switch (c) {
			case 1:
				lv = 'p';
				nguoinguoi(n, n);
				break;
			case 2:
				lv = 'c';
				while (true) {
					drawlevel(r);
					ch = _getch();
					switch (ch) {
					case UP:
						r--;
						break;
					case DOWN:
						r++;
						break;
					case ENTER:
						switch (r) {
						case 1:
							md = 'e';
							nguoimay(n, n, md);
							break;
						case 2:
							md = 'm';
							nguoimay(n, n, md);
							break;
						case 3:
							md = 'h';
							nguoimay(n, n, md);
							break;
						}
					case BACK:
						return;
					}
					if (r > 3)
						r = 1;
					if (r < 1)
						r = 3;
				}

			}
			break;
		case BACK:
			return;
		}
			if (c > 2)
				c = 1;
			if (c < 1)
				c = 2;
		}
}

void nhap(Player p[100], int& num, char c, char md, int res) {
	std::fstream fs;
	// Mo tap tin cho phep doc hoac ghi hoac chinh sua (append)
	fs.open("statistic.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	
	switch (c) {
	case 1:
		num = 2;
		break;
	case 2:
		num = 1;
		break;
	}
	
	system("cls");
	cout << endl << endl << endl;
	for (int i = 0; i < num; ++i) {
		cout << "Please enter your name, player "<< i+1 << ": ";
		string name;
		cin >> name;
		cout << endl << endl;
		p[i].name = name;
		fs << p[i].name << endl;
		switch (lv) {
		case 'p':
			p[i].mode = "PvP";
			md = ' ';
			break;
		case 'c':
			p[i].mode = "PvC";
			break;
		}
		fs << p[i].mode << endl;
		switch (md) {
		case 'e':
			p[i].level = "Easy";
			break;
		case 'm':
			p[i].level = "Medium";
			break;
		case 'h':
			p[i].level = "Hard";
			break;
		case ' ':
			p[i].level = "Blank";
		}
		fs << p[i].level << endl;
		switch (res) {
		case 1:
			if (abs(i - res)%2 != 0)
				p[i].result = "WIN";
			else
				p[i].result = "LOSE";
			break;
		case 2:
			if (abs(i - res) % 2 != 0)
				p[i].result = "WIN";
			else
				p[i].result = "LOSE";
			break;
		case 3:
			p[i].result = "WIN";
			break;
		case 4:
			p[i].result = "LOSE";
			break;
		case 5:
			p[i].result = "DRAW";
			break;
		}
		fs << p[i].result << endl;
	}
	int ch = _getch();
	if (ch == BACK)
		return;
	// Dong tap tin
	fs.close();
}
void read(Player p[100], int &num){
	num = 0;
	ifstream inp;
	inp.open("statistic.txt");
	while (!inp.eof())
	{
		inp >> p[num].name;
		inp >> p[num].mode;
		inp >> p[num].level;
		inp >> p[num].result;
		++num;
	}
	--num;
	inp.close();
}
void write(Player p[100], int& num) {
	system("cls");
	for (int i = 0; i < 20; ++i)
		cout << endl;
	cout << "\t\t" << "Number\t\tName\t\tMode\t\tLevel\t\tResult" << endl;
	for (int i = 0; i < num; ++i)
	{
		cout << "\t\t" << i + 1 << "\t\t";
		cout << p[i].name << "\t\t";
		cout << p[i].mode << "\t\t";
		cout << p[i].level << "\t\t";
		cout << p[i].result << endl;
	}

	int ch;
	ch = _getch();
	if (ch == BACK)
		return;
	
}
void deletestatistic(){
	ofstream out;
	out.open("statistic.txt");
	out << " ";
	out.close();
	system("cls");
	return;
}
void text_statistic(int f) {
	system("cls");
	textcolor(rand()%15+1);
	cout << endl << endl << endl << endl;
	cout << "                             _____ _____ ___ _____ _____ _____ _____ _____ _____ " << endl;
	cout << "                            /  ___|_   _/ _ \\_   _|_   _/  ___|_   _|_   _/  __ \\" << endl;
	cout << "                            \\ `--.  | |/ /_\\ \\| |   | | \\ `--.  | |   | | | /  \\/" << endl;
	cout << "                             `--. \\ | ||  _  || |   | |  `--. \\ | |   | | | |    " << endl;
	cout << "                            /\\__/ / | || | | || |  _| |_/\\__/ / | |  _| |_| \\__/\\" << endl;
	cout << "                            \\____/  \\_/\\_| |_/\\_/  \\___/\\____/  \\_/  \\___/ \\____/" << endl;
	textcolor(7);
	cout << endl << endl << endl << endl << endl;
	if (f == 1)
		textcolor(9);
	cout << "                                   _                 __ _        _   _     _   _      " << endl;
	cout << "                            /\\   /(_) _____      __ / _\\ |_ __ _| |_(_)___| |_(_) ___ " << endl;
	cout << "                            \\ \\ / / |/ _ \\ \\ /\\ / / \\ \\| __/ _` | __| / __| __| |/ __|" << endl;
	cout << "                             \\ V /| |  __/\\ V  V /  _\\ \\ || (_| | |_| \\__ \\ |_| | (__ " << endl;
	cout << "                              \\_/ |_|\\___| \\_/\\_/   \\__/\\__\\__,_|\\__|_|___/\\__|_|\\___|" << endl;
	textcolor(7);
	cout << endl << endl << endl;
	if (f == 2)
		textcolor(9);
	cout << "                            ___     _      _         __ _        _   _     _   _ " << endl;
	cout << "                           /   \\___| | ___| |_ ___  / _\\ |_ __ _| |_(_)___| |_(_) ___" << endl;
	cout << "                          / /\\ / _ \\ |/ _ \\ __/ _ \\ \\ \\| __/ _` | __| / __| __| |/ __|" << endl;
	cout << "                         / /_//  __/ |  __/ ||  __/ _\\ \\ || (_| | |_| \\__ \\ |_| | (__" << endl;
	cout << "                        /___,' \\___|_|\\___|\\__\\___| \__/\\__\\__,_|\\__|_|___/\\__|_|\\___|" << endl;
	textcolor(7);
	cout << endl << endl;

}
// ham xem thong ke
void statistic(Player p[100], int &num) {
	int ch;
	int f = 1;
	read(p, num);
	cout << num << '\n';
	while (true) {
		text_statistic(f);
		ch = _getch();
		switch (ch) {
		case UP:
			f--;
			break;
		case DOWN:
			f++;
			break;
		case ENTER:
			switch (f) {
			case 1:
				write(p, num);
				break;
			case 2:
				deletestatistic();
				break;
			}
			break;
		case BACK :
			return;
		}
		if (f < 1)
			f = 2;
		if (f > 2)
			f = 1;

	}
}
//ham ve menu chinh
void menu(int a) {
	system("cls");
	textcolor(rand()%15+1);
	cout << endl << endl << endl;
	cout << "              CCCCCCCCCCCCC               AAA               RRRRRRRRRRRRRRRRR        OOOOOOOOO" << endl;
	cout << "           CCC::::::::::::C              A:::A              R::::::::::::::::R     OO:::::::::OO" << endl;
	cout << "         CC:::::::::::::::C             A:::::A             R::::::RRRRRR:::::R  OO:::::::::::::OO" << endl;
	cout << "        C:::::CCCCCCCC::::C            A:::::::A            RR:::::R     R:::::RO:::::::OOO:::::::O" << endl;
	cout << "       C:::::C       CCCCCC           A:::::::::A             R::::R     R:::::RO::::::O   O::::::O" << endl;
	cout << "      C:::::C                        A:::::A:::::A            R::::R     R:::::RO:::::O     O:::::O" << endl;
	cout << "      C:::::C                       A:::::A A:::::A           R::::RRRRRR:::::R O:::::O     O:::::O" << endl;
	cout << "      C:::::C                      A:::::A   A:::::A          R:::::::::::::RR  O:::::O     O:::::O" << endl;
	cout << "      C:::::C                     A:::::A     A:::::A         R::::RRRRRR:::::R O:::::O     O:::::O" << endl;
	cout << "      C:::::C                    A:::::AAAAAAAAA:::::A        R::::R     R:::::RO:::::O     O:::::O" << endl;
	cout << "      C:::::C                   A:::::::::::::::::::::A       R::::R     R:::::RO:::::O     O:::::O" << endl;
	cout << "       C:::::C       CCCCCC    A:::::AAAAAAAAAAAAA:::::A      R::::R     R:::::RO::::::O   O::::::O" << endl;
	cout << "        C:::::CCCCCCCC::::C   A:::::A             A:::::A   RR:::::R     R:::::RO:::::::OOO:::::::O" << endl;
	cout << "         CC:::::::::::::::C  A:::::A               A:::::A  R::::::R     R:::::R OO:::::::::::::OO" << endl;
	cout << "           CCC::::::::::::C A:::::A                 A:::::A R::::::R     R:::::R   OO:::::::::OO" << endl;
	cout << "              CCCCCCCCCCCCCAAAAAAA                   AAAAAAARRRRRRRR     RRRRRRR     OOOOOOOOO" << endl;
	textcolor(6);
	cout << endl << endl << endl;
	if (a == 1) textcolor(11);
	cout << "                                               ____  _" << endl;
	cout << "                                              |  _ \\| | __ _ _   _" << endl;
	cout << "                                              | |_) | |/ _` | | | |" << endl;
	cout << "                                              |  __/| | (_| | |_| |" << endl;
	cout << "                                              |_|   |_|\\__,_|\\__, |" << endl;
	cout << "                                                             |___/" << endl;
	cout << endl;
	textcolor(6);
	if (a == 2) textcolor(11);
	cout << "                                        ____       _   _   _" << endl;
	cout << "                                       / ___|  ___| |_| |_(_)_ __   __ _ ___" << endl;
	cout << "                                       \\___ \\ / _ \\ __| __| | '_ \\ / _` / __|" << endl;
	cout << "                                        ___) |  __/ |_| |_| | | | | (_| \\__ \\" << endl;
	cout << "                                       |____/ \\___|\\__|\\__|_|_| |_|\\__, |___/" << endl;
	cout << "                                                                   |___/" << endl;
	cout << endl;
	textcolor(6);
	if (a == 3) textcolor(11);
	cout << "                                      ____  _        _   _     _   _" << endl;
	cout << "                                     / ___|| |_ __ _| |_(_)___| |_(_) ___ ___" << endl;
	cout << "                                     \\___ \\| __/ _` | __| / __| __| |/ __/ __|" << endl;
	cout << "                                      ___) | || (_| | |_| \\__ \\ |_| | (__\\__ \\" << endl;
	cout << "                                     |____/ \\__\\__,_|\\__|_|___/\\__|_|\\___|___/" << endl;

                                          
	cout << endl;
	textcolor(6); 
	if (a == 4) textcolor(11);
	cout << "                                                _____      _ _" << endl;
	cout << "                                               | ____|_  _(_) |_" << endl;
	cout << "                                               |  _| \\ \\/ / | __|" << endl;
	cout << "                                               | |___ >  <| | |_" << endl;
	cout << "                                               |_____/_/\\_\\_|\\__|" << endl;
                   
                 


	textcolor(6);
                         
	
}
int main() {
	resizeConsole(width, height);
	gotoxy(40, 25);
	textcolor(11);
	string welcome = "WELCOME TO CARO GAME";
	int x = 0;
	while (welcome[x] != '\0')
	{
		cout << welcome[x];
		Sleep(200);
		x++;
	};
	PlaySound(TEXT("song.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	int a=1, ch;
	while (true) {
		menu(a);
		ch = _getch();
		switch (ch) {
		case UP:
			a--;
			break;
		case DOWN:
			a++;
			break;
		case ENTER:
			switch (a) {
			case 1:
				system("cls");
				play();
				break;
			case 2:
				system("cls");
				setting();
				break;
			case 3:
				system("cls");
				read(p, num);
				statistic(p, num);
				break;
			case 4:
				system("cls");
				gotoxy(40, 25);
				string bye = "THANK YOU FOR USING";
				int x = 0;
				while (bye[x] != '\0')
				{
					cout << bye[x];
					Sleep(200);
					x++;
				};
				return 0;
			}

		}
		if (a > 4)
			a = 1;
		if (a < 1)
			a = 4;
	}
	return 0;
}  
