/*
DE TAI CUA NHOM GAME ME CUNG
NHOM GAME ME CUNG DH18CS01  :
Nguyen Nguyet Phuong Bao  MSSV :1851010013 ";
Nguyen Huynh Minh Quang   MSSV :1851010107 ";
*/
#include <iostream>
#include<conio.h>
using namespace std;
#include"console.h"
#include<Windows.h>
#include<string>
#include<fstream>
const int M = 100;
void TextColor(int color);
void clrscr();
void resizeConsole(int width, int height);
void build1(char k[M][M]);
void build2(char k[M][M]);
void build3(char k[M][M]);
bool ktTrong(char k[M][M], int x, int y, char a);
void gotoXY(int column, int line);
void background();
void move(char k[M][M], int &diem);
void ketQua(int diem, string name);
void output1(char k[M][M]);
void level1(char k[M][M], string name, int diem);
void level2(char k[M][M], string name, int diem);
void level3(char k[M][M], string name, int diem);
void Openfile();

void main()
{
	resizeConsole(800, 550); // rong , cao dieu chinh o cmd
	char k[M][M];
	int diem;
	int c;
	bool exit = true;
	string name;
	diem = 1;
	background();
	TextColor(9);
	cout << "TEN TOI LA: " << endl;
	getline(cin, name);
	system("cls");
	TextColor(9);
	gotoXY(30, 5);
	cout << "CHAO ";
	TextColor(7);
	cout << name;
	TextColor(9);
	cout << " DEN VOI GAME ME CUNG BASIC";
	gotoXY(30, 7);
	TextColor(14);
	cout << "MOI ";
	TextColor(7);
	cout << name;
	TextColor(14);
	cout << " CHON CAP DO PHU HOP: ";
	TextColor(13);
	gotoXY(30, 10);
	cout << "Level 1 nhan phim 1 va enter ";
	gotoXY(30, 11);
	cout << "Level 2 nhan phim 2 va enter";
	gotoXY(30, 12);
	cout << "Level 3 nhan phim 3 va enter";
	gotoXY(30, 13);
	cout << "Ket thuc game nhan phim 4 va enter ";

	TextColor(9);
	//clrscr();
	while (exit == true) {
		do {
			cin >> c;
			if (c > 5 || c <= 0)
				cout << "Khong hop le.Xin nhap lai: ";
		} while (c > 5 || c <= 0);
		clrscr();
		switch (c)
		{
		case 1:
		{
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 5";
			cout << "\n\n\t\t\t Nhan'w' de di chuyen len";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 4";
			cout << "\n\n\t\t\t Nhan's' de di chuyen xuong";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 3";
			cout << "\n\n\t\t\t Nhan'a' de di chuyen trai";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 2";
			cout << "\n\n\t\t\t Nhan'd' de di chuyen Phai";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t BAT DAU  ..... 1";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t L E V E L - 1";
			Sleep(500);
			clrscr();

			level1(k, name, diem);

			TextColor(13);
			gotoXY(30, 10);
			cout << "De choi tiep level 1 nhan phim 1 va enter ";
			gotoXY(30, 11);
			cout << "De choi tiep level 2 nhan phim 2 va enter";
			gotoXY(30, 12);
			cout << "De choi tiep level 3 nhan phim 3 va enter";
			gotoXY(30, 13);
			cout << "Ket thuc game nhan phim 4 va enter ";
			gotoXY(30, 14);
			cout << "Xem lai ket qua choi nhan phim 5 va enter ";
			TextColor(9);
			break;
		}
		case 2:
		{
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 5";
			cout << "\n\n\t\t\t Nhan'w' de di chuyen len";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 4";
			cout << "\n\n\t\t\t Nhan's' de di chuyen xuong";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 3";
			cout << "\n\n\t\t\t Nhan'a' de di chuyen trai";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 2";
			cout << "\n\n\t\t\t Nhan'd' de di chuyen Phai";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t BAT DAU  ..... 1";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t L E V E L - 2";
			Sleep(500);
			clrscr();

			level2(k, name, diem);

			TextColor(13);
			gotoXY(30, 10);
			cout << "De choi tiep level 1 nhan phim 1 va enter ";
			gotoXY(30, 11);
			cout << "De choi tiep level 2 nhan phim 2 va enter";
			gotoXY(30, 12);
			cout << "De choi tiep level 3 nhan phim 3 va enter";
			gotoXY(30, 13);
			cout << "Ket thuc game nhan phim 4 va enter ";
			gotoXY(30, 14);
			cout << "Xem lai ket qua choi nhan phim 5 va enter ";
			TextColor(9);
			break;
		}
		case 3:
		{
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 5";
			cout << "\n\n\t\t\t Nhan'w' de di chuyen len";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 4";
			cout << "\n\n\t\t\t Nhan's' de di chuyen xuong";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 3";
			cout << "\n\n\t\t\t Nhan'a' de di chuyen trai";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t CHUAN BI ..... 2";
			cout << "\n\n\t\t\t Nhan'd' de di chuyen Phai";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t BAT DAU  ..... 1";
			Sleep(1000);
			clrscr();
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t L E V E L - 3";
			Sleep(500);
			clrscr();

			level3(k, name, diem);

			TextColor(13);
			gotoXY(30, 10);
			cout << "De choi tiep level 1 nhan phim 1 va enter ";
			gotoXY(30, 11);
			cout << "De choi tiep level 2 nhan phim 2 va enter";
			gotoXY(30, 12);
			cout << "De choi tiep level 3 nhan phim 3 va enter";
			gotoXY(30, 13);
			cout << "Ket thuc game nhan phim 4 va enter ";
			gotoXY(30, 14);
			cout << "Xem lai ket qua choi nhan phim 5 va enter ";
			TextColor(9);
			break;
		}
		case 5:
		{
			TextColor(13);
			gotoXY(30, 1);
			cout << "De choi tiep level 1 nhan phim 1 va enter ";
			gotoXY(30, 2);
			cout << "De choi tiep level 2 nhan phim 2 va enter";
			gotoXY(30, 3);
			cout << "De choi tiep level 3 nhan phim 3 va enter";
			gotoXY(30, 4);
			cout << "Ket thuc game nhan phim 4 va enter ";
			gotoXY(30, 5);
			cout << "Xem lai ket qua choi nhan phim 5 va enter ";
			TextColor(9);
		Openfile();
		
		break;
		}
		case 4:
		{
			exit = false;
		}

		}
	}

	gotoXY(30, 5);
	TextColor(5);
	cout << "GOOG BYE!" << endl;
	gotoXY(20, 15);

}

//lam mau 
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// me cung level 1
void build1(char k[M][M])
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 20; j++)
		{
			if (i == 0)
			{
				if (i == 0 && j == 0)
					k[i][j] = 218;
				else
					if (i == 0 && j == 20 - 1)
						k[i][j] = 191;
					else
						k[i][j] = 196;
			}
			else
				if (i == 15 - 1)
				{
					if (i == 15 - 1 && j == 0)
						k[i][j] = 192;
					else
						if (i == 15 - 1 && j == 20 - 1)
							k[i][j] = 217;
						else
							k[i][j] = 196;

				}
				else
					if (j == 20 - 1 && i == 13)
						k[i][j] = 127; // diem toi
					else

						if (j == 0 || j == 20 - 1)
							k[i][j] = 179;
						else
							if (i > 1 && i < 15 - 1 && j > 0 && j < 3)
								k[i][j] = 176;
							else
								if ((i > 8 && i < 15 - 1) && (j == 3 || j == 4))
									k[i][j] = 176;
								else
									if (j == 4 && i > 0 && i < 8)
										k[i][j] = 176;
									else
										if (j > 5 && j < 10 && i != 3 && i>0 && i < 15 - 1)
											k[i][j] = 176;
										else
											if (j == 11 && i > 1 && i < 15 - 1)
												k[i][j] = 176;
											else
												if (j > 12 && j < 20 - 1 && i>0 && i < 4)
													k[i][j] = 176;
												else
													if (j > 12 && j < 18 && i>4 && i < 13)
														k[i][j] = 176;

													else
														k[i][j] = ' ';

		}
}
//xuat me cung
void output1(char k[M][M])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
			cout << k[i][j];
		cout << endl;
	}
}
//di chuyen
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Di chuyen me cung va tinh nang bat phim..
void move(char k[M][M], int& diem)
{
	char a;
	bool check = true;
	int x, y;
	x = 1; y = 1;
	gotoXY(x, y);
	cout << "$";
	while (!(x == 18 && y == 13))
	{
		if (_kbhit())
		{
			a = _getch();
			if ( a=='d') //phai
			{
				gotoXY(x, y);
				clrscr();
				output1(k);
				if (ktTrong(k, x, y, a) == true)
				{
					diem++;
					x += 1;
					gotoXY(x, y);
					cout << "$";
				}
				else
				{
					gotoXY(x, y);
					cout << "$";
				}
			}
			if (a == 'a') // trai
			{
				gotoXY(x, y);
				clrscr();
				output1(k);
				if (ktTrong(k, x, y, a) == true)
				{
					diem++;
					x -= 1;
					gotoXY(x, y);
					cout << "$";
				}
				else
				{
					gotoXY(x, y);
					cout << "$";
				}
			}
			if (a == 'w')//len
			{
				gotoXY(x, y);
				clrscr();
				output1(k);
				if (ktTrong(k, x, y, a) == true)
				{
					diem++;
					y -= 1;
					gotoXY(x, y);
					cout << "$";
				}
				else
				{
					gotoXY(x, y);
					cout << "$";
				}
			}
			if (a == 's') //xuong
			{
				gotoXY(x, y);
				clrscr();
				output1(k);
				if (ktTrong(k, x, y, a) == true)
				{
					diem++;
					y += 1;
					gotoXY(x, y);
					cout << "$";
				}
				else
				{
					gotoXY(x, y);
					cout << "$";
				}
			}
		}


	}
}
//Kiem tra co the di duoc hay khong
bool ktTrong(char k[M][M], int x, int y, char a)
{
	switch (a)
	{
	case'd': // phai
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
				if (k[y][x + 1] == ' ')
					return true;
				else
					return false;
		}
		break;
	}
	case'a'://trai
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
				if (k[y][x - 1] == ' ')
					return true;
				else
					return false;
		}
		break;
	}
	case'w'://len
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
				if (k[y - 1][x] == ' ')
					return true;
				else
					return false;
		}
		break;
	}
	case's'://xuong
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
				if (k[y + 1][x] == ' ')
					return true;
				else
					return false;
		}
		break;
	}
	}
}
// Xet ket qua
void ketQua(int diem, string name)
{
	int i = 1, a;
	if (diem > 0 && diem < 45)
	{
		gotoXY(25, 5);
		cout << name << " da hoan thanh ";
		TextColor(12);
		cout << "XUAT SAC" << endl;
		//Sleep(100);
	}
	else
	{
		gotoXY(25, 5);
		cout << name << " da hoan thanh ";
		TextColor(12);
		cout << "TOT" << endl;
		//Sleep(100);
	}

}
//me cung level 2
void build2(char k[M][M])
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 20; j++)
		{
			//khung me cung
			if (i == 0)
			{
				if (i == 0 && j == 0)
					k[i][j] = 218;
				else
					if (i == 0 && j == 20 - 1)
						k[i][j] = 191;
					else
						k[i][j] = 196;
			}
			else
				if (i == 15 - 1)
				{
					if (i == 15 - 1 && j == 0)
						k[i][j] = 192;
					else
						if (i == 15 - 1 && j == 20 - 1)
							k[i][j] = 217;
						else
							k[i][j] = 196;

				}
				else
					if (j == 20 - 1 && i == 13)
						k[i][j] = 157; // diem toi
					else

						if (j == 0 || j == 20 - 1)
							k[i][j] = 179;
			// cac vien me cung
						else
							if (i > 1 && i < 11 && j == 1) //1
								k[i][j] = 176;
							else
								if ((i == 1 || i == 2) && (j == 3 || j == 15 || j == 17))//2
									k[i][j] = 176;
								else
									if ((i == 12 || i == 13) && (j == 1 || j == 2)) //3
										k[i][j] = 176;
									else
										if ((i == 4 || i == 6) && (j > 2 && j < 8))//4
											k[i][j] = 176;
										else
											if ((j == 8 || j == 15) && (i > 3 && i < 10))//5
												k[i][j] = 176;
											else
												if (i == 2 && j > 4 && j < 15 && j != 9)//6
													k[i][j] = 176;
												else
													if ((i > 7 && i < 15 - 1) && (j > 2 && j < 7))//7
														k[i][j] = 176;
													else
														if ((i == 10 || i == 12) && (j > 7 && j < 16))//8
															k[i][j] = 176;
														else
															if ((i > 3 && i < 13) && j == 17)//9
																k[i][j] = 176;
															else
																if ((j > 9 && j < 15) && i == 4)//10
																	k[i][j] = 176;
																else
																	if ((i == 13 && j == 15) || (i == 12 && j == 18))//11
																		k[i][j] = 176;

																	else
																		k[i][j] = ' ';

		}
}
//me cung level 3
void build3(char k[M][M])
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 20; j++)
		{
			//khung me cung
			if (i == 0)
			{
				if (i == 0 && j == 0)
					k[i][j] = 218;
				else
					if (i == 0 && j == 20 - 1)
						k[i][j] = 191;
					else
						k[i][j] = 196;
			}
			else
				if (i == 15 - 1)
				{
					if (i == 15 - 1 && j == 0)
						k[i][j] = 192;
					else
						if (i == 15 - 1 && j == 20 - 1)
							k[i][j] = 217;
						else
							k[i][j] = 196;

				}
				else
					if (j == 20 - 1 && i == 13)
						k[i][j] = 157; // diem toi
					else

						if (j == 0 || j == 20 - 1)
							k[i][j] = 179;
			// cac vien me cung
						else
							if (j > 3 && j < 17 && j != 5 && j != 12 && i == 2) //1
								k[i][j] = 176;
							else
								if (j == 2 && i > 2 && i < 12)//2
									k[i][j] = 176;
								else
									if (i == 13 && j > 0 && j < 15) //3
										k[i][j] = 176;
									else
										if (j == 4 && i > 3 && i < 10)//4
											k[i][j] = 176;
										else
											if (i == 11 && j > 3 && j < 14)//5
												k[i][j] = 176;
											else
												if (j == 6 && i > 3 && i < 12 && i != 7)//6
													k[i][j] = 176;
												else
													if (j == 8 && i > 5 && i < 11)//7
														k[i][j] = 176;
													else
														if (i == 10 && (j == 9 || j == 10))//8
															k[i][j] = 176;
														else
															if (j == 14 && i > 8 && i < 13)//9
																k[i][j] = 176;
															else
																if (j == 16 && (i == 10 || i == 12 || i == 11))//10
																	k[i][j] = 176;
																else
																	if (i == 4 && (j > 6 && j < 12))//11
																		k[i][j] = 176;
																	else
																		if (i > 4 && i < 9 && j>9 && j < 12)//12
																			k[i][j] = 176;
																		else
																			if (i == 7 && j > 11 && j < 17)//13
																				k[i][j] = 176;
																			else
																				if ((i == 4 || i == 5) && j > 12 && j < 17)//14
																					k[i][j] = 176;
																				else
																					if (j == 18 && (i > 0 && i < 11))//15
																						k[i][j] = 176;
																					else
																						if ((i == 8 && j == 12) || (i == 9 && j == 12) || (i == 8 && j == 16) || (i == 12 && (j == 17 || j == 18)))//16
																							k[i][j] = 176;
																						else
																							k[i][j] = ' ';

		}
}
//Giao dien luc vao
void background()
{

	TextColor(10);
	cout << "\n\n\n";
	cout << "\t\t CHAO ";
	Sleep(500);
	cout << " MUNG ";
	Sleep(500);
	cout << " DEN ";
	Sleep(500);
	cout << " VOI ";
	Sleep(500);
	cout << " GAME ";
	Sleep(500);
	cout << " ME ";
	Sleep(500);
	cout << " CUNG ";
	Sleep(500);
	cout << " DON ";
	Sleep(500);
	cout << " GIAN ";
	Sleep(500);
	cout << " BANG ";
	Sleep(500);
	cout << " C++ ";
	Sleep(500);
	cout << "\n\n\t\t\t\t WELCOME TO THE MAZE GAME \n\n\n";
	Sleep(1000);
	cout << "\t\t\t\t" << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << "\n";
	cout << "\t\t\t\t" << (char)179 << "=.= =============.======" << (char)179 << "\n";
	cout << "\t\t\t\t" << (char)179 << "=.=...............======" << (char)179 << "\n";
	cout << "\t\t\t\t" << (char)179 << "=.===.== =.======.======" << (char)179 << "\n";
	cout << "\t\t\t\t" << (char)179 << "=.===.== =.======.======" << (char)179 << "\n";
	cout << "\t\t\t\t" << (char)179 << "=.....====.======.======" << (char)179 << "\n";
	cout << "\t\t\t\t" << (char)179 << "===========............." << (char)179 << "\n";
	cout << "\t\t\t\t" << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << "\n";
	Sleep(1000);
	/*;
	cout << "\t\t\t\t Nguyen Nguyet Phuong Bao";
	Sleep(1000);
	cout <<"\n\t\t\t\t Nguyen Huynh Minh Quang\n\n";
	*/
}
//xoa man hinh 
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
// thay doi kich thuoc cdm
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
//level 1
void level1(char k[M][M], string name, int diem)
{
	build1(k);
	output1(k);
	int x, y;
	x = 1; y = 1;
	gotoXY(x, y);
	cout << "$";
	move(k, diem);
	TextColor(14);
	ketQua(diem, name);
	//Luu ket qua vao file can xem lai
	fstream file;
	file.open("kq.txt",ios::app);
	if (diem > 0 && diem < 45)
	{
		file << "\n \n";
		file << name << " da hoan thanh level 1 XUAT SAC ! ";
		file << " voi so buoc di la: " << diem;
	}
	else
	{
		file << "\n \n";
		file << name << " da hoan thanh level 1 TOT !";
		file << " voi so buoc di la: " << diem;

	}
	file.close();


}
//level 2
void level2(char k[M][M], string name, int diem)
{
	build2(k);
	output1(k);
	int x, y;
	x = 1; y = 1;
	gotoXY(x, y);
	cout << "$";
	move(k, diem);
	TextColor(14);
	ketQua(diem, name);
	//Luu ket qua vao file can xem lai
	fstream file;
	file.open("kq.txt", ios::app);
	if (diem > 0 && diem < 45)
	{
		file << "\n \n";
		file << name << " da hoan thanh level 2  XUAT SAC ! ";
		file << " voi so buoc di la: " << diem;
	}
	else
	{
		file << "\n \n";
		file << name << " da hoan thanh level 2  TOT !";
		file << " voi so buoc di la: " << diem;

	}
	file.close();

}
//level 3
void level3(char k[M][M], string name, int diem)
{
	build3(k);
	output1(k);
	int x, y;
	x = 1; y = 1;
	gotoXY(x, y);
	cout << "$";
	move(k, diem);
	TextColor(14);
	ketQua(diem, name);
	//Luu ket qua vao file can xem lai
	fstream file;
	file.open("kq.txt", ios::app);
	if (diem > 0 && diem < 45)
	{
		file << "\n \n";
		file << name << " da hoan thanh level 3 XUAT SAC ! ";
		file << " voi so buoc di la: " << diem;
	}
	else
	{
		file << "\n \n";
		file << name << " da hoan thanh level 3 TOT !";
		file << " voi so buoc di la: " << diem;

	}
	file.close();

}
//Doc file
void Openfile()
{
	fstream file;
	file.open("kq.txt");
	string s1(istreambuf_iterator<char>(file.rdbuf()), istreambuf_iterator<char>()); // doc toan bo file 
	cout << s1.data() << endl;
	file.close();
}