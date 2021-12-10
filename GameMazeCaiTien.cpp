#include <iostream>
#include<conio.h>
using namespace std;
#include"console.h"
#include<Windows.h>
#include<string>
#include<fstream>
char p[200][200];
char p2[200][200];
int chieuDai = 0;
int chieuRong = 0;
int chieuDai2 =0;
int chieuRong2 =0;
int soKiTu;
char nv[7][3];
//vi tri dau tien
int x = 2 ;
int y = 1 ;
//
int diem = 0;
string name;
struct nguoiChoi
{
	string ten;
	int diem;
};
nguoiChoi player[100]; // 100 nguoi choi
//Di chuyen doi tuong
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Xoa man hinh
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
void InputTen(string name)
{
	
	ofstream out("diem.txt", std::ofstream::app);
	out<< name << endl; 
	out.close();
}
void InputDiem(int diem)
{
	
	ofstream out("diem.txt", std::ofstream::app);
	out << diem<< endl ;
	out.close();
}
 //doc danh sach file
//dem dong trong file
int line()
{
	ifstream f1;
   char c;
   int numchars, numlines;
 
   f1.open("diem.txt");
 
   numchars = 0;
   numlines = 0;
   f1.get(c);
   while (f1) {
     while (f1 && c != '\n') {
       numchars = numchars + 1;
       f1.get(c);
     }
     numlines = numlines + 1;
     f1.get(c);
   }
   return numlines;
}
// doc diem file
void docDiem()
{
	int i = 0;
	ofstream output;
	ifstream input;
	input.open("diem.txt",ios::in);
	if(input.is_open())
	{
		while (i < line()/2){
			string a;
			int b;
			input >> a;
			input.ignore();
			input >> b;
			input.ignore();
			player[i].ten = a;
			player[i].diem = b;
			i++;
		}
	}
	input.close();
}
// xep hang nguoi choi
void xepHang()
{
	int a = line()/2;
	for(int i = 0; i < a - 1 ; i++)
	{
		for(int j = i + 1; j < a;j++)
		{
			if(player[i].diem > player[j].diem){
                // Hoan vi 2 so a[i] va a[j]
               nguoiChoi p1 = player[i];
                player[i] = player[j];
                player[j] = p1; 
			}
		}
	}
}
void high_Score()
{
	clrscr();
	docDiem();
	xepHang();
	cout <<"\n\n\n\n\t\t\t\t HIGH SCORE "<<endl;
	cout <<"\n\n\tSTT\t\t\tNAME"<< endl;
	for(int m = 0; m < line()/2 ; m++)
	{
		cout <<"\n\t"<<m+1 <<"\t\t\t"<< player[m].ten<< endl;
	}
}
//tạo map

void map_Level1()
{
	int i =0;
	int j =0;
	chieuRong =0;
	chieuDai = 0;
	ifstream f1;
	char c;
	f1.open("map1.txt");
	f1.get(c);
    while (f1) {
     while (f1 && c != '\n') {
		f1.get(c);
		if(c !='\n')
		{
			p[i][j] = c;
		}
		//cout << p[i][j];
		i++;
		if(j == 0)
			chieuRong++;
     }
	 f1.get(c);
	 //cout << endl;
	 //p[i][j] = c;
	 j++;
	 i = 0;
   }
	chieuDai = j;
	//chieuRong = i;
   //cout << endl <<chieuRong <<"  "<< chieuDai << endl;;
}
void map_Level2()
{
	int i =0;
	int j =0;
	chieuRong2 =0;
	chieuDai2 = 0;
	ifstream f1;
	char c;
	f1.open("map2.txt");
	f1.get(c);
    while (f1) {
     while (f1 && c != '\n') {
		f1.get(c);
		if(c !='\n')
		{
			p2[i][j] = c;
		}
		//cout << p[i][j];
		i++;
		if(j == 0)
			chieuRong2++;
     }
	 f1.get(c);
	 //cout << endl;
	 //p[i][j] = c;
	 j++;
	 i = 0;
   }
	chieuDai2 = j;

	//cout<< chieuDai2 << "	" << chieuRong2;
}
void inputNV()
{
		for(int i=0;i<3;i++)
		{
			for(int j = 0; j < 7;j++)
			{
				nv[i][j] ='0';
				if(i == 0 || i == 2)
					if(j == 2 || j == 3)
						nv[i][j] =' ';
				if(i == 1)
					if(j == 0 || j == 1 || j == 4 ||j == 5)
						nv[i][j] =' ';
			}
		}
		
}
void outPutNV()
{
	int a = x;
	int c = a;
	int b = y;
	for(int i=0;i<3;i++)
		{
			for(int j = 0; j< 7;j++)
			{ 
				
				gotoXY(a,b);
				cout << nv[i][j];
				a=a+1;
			}
			a = c;
			b = b + 1;
			cout << endl;
		}
}
// di ngang
void outPutNV_GoToX()
{
	int a = x;
	int c = a;
	int b = y;
	for(int i=0;i<3;i++)
		{
			//b = c;
			for(int j = 0; j< 7;j++)
			{ 
				gotoXY(a,b);
				cout << nv[i][j];
				a=a+1;
			}
			a = c;
			b = b + 1;
			cout << endl;
		}
}
// di xuong
void outPutNV_GoToYDow()
{
	int a = x;
	int c = a;
	int b = y;
	for(int i=0;i<3;i++)
		{
			for(int j = 0; j< 7;j++)
			{ 
				
				gotoXY(a,b);
				cout << nv[i][j];
				a=a+1;
			}
			a = c;
			b = b+1;
			cout << endl;
		}
}
//dilen
void outPutNV_GoToYTop()
{
	int a = x;
	int c = a;
	int b = y;
	for(int i=0;i<3;i++)
		{
			for(int j = 0; j< 7;j++)
			{ 
				
				gotoXY(a,b);
				cout << nv[i][j];
				a=a+1;
			}
			a = c;
			b = b-1;
			cout << endl;
		}
}

void level_1()
{
	//demKiTu();
	map_Level1();
	for(int i = 0; i < chieuDai;i++)
	{
		for(int j = 0; j< chieuRong;j++)
			cout << p[j][i];
		cout << endl;
		
	}
}
void level_2()
{
	map_Level2();
	for(int i = 0; i < chieuDai2;i++)
	{
		for(int j = 0; j< chieuRong2;j++)
			cout << p2[j][i];
		cout << endl;
		
	}
}
// kiem tra co di chuyen duoc khong
bool checkNull(char q[200][200],char a)
{
	int m,n;
	m = x;
	n = y;	
	switch (a)
	{
	case'd': // phai
	{
		if(q[m+7][n] == ' ' && q[m+7][n+1] == ' ' && q[m+7][n+2] == ' ')
			return true;
		else
			return false;
		break;
	}
	case'a'://trai
	{
		if(q[m-1][n] == ' ' && q[m-1][n+1] == ' ' && q[m-1][n+2] == ' ')
			return true;
		else
			return false;
		break;
	}
	case'w'://len
	{
		if(q[m][n-1] == ' ' && q[m+1][n-1] == ' ' && q[m+2][n-1] == ' ' && q[m+3][n-1] == ' ' && q[m+4][n-1] == ' '
			&& q[m+5][n-1] == ' '&& q[m+6][n-1] == ' ')
			return true;
		else
			return false;
		break;
	}
	case's'://xuong
	{
		if(q[m][n+3] == ' ' && q[m+1][n+3] == ' ' && q[m+2][n+3] == ' ' && q[m+3][n+3] == ' ' && q[m+4][n+3] == ' '
			&& q[m+5][n+3] == ' '&& q[m+6][n+3] == ' ')
			return true;
		else
			return false;
		break;
		
	}
	}
}
bool checkWin()
{
	int m,n;
	m = x;
	n = y;
	if(p[m+7][n] == 'x' && p[m+7][n+1] == 'x' && p[m+7][n+2] == 'x')
			return true;
		else
			return false;
}
//diChuyen
void play_level1()
{
	char a;
	bool flag = true;
	inputNV();
	level_1();
	outPutNV();
	while (flag == true )
	{
		
		if (_kbhit())
		{
			a = _getch();
			if(checkNull(p,a)){
				if ( a=='d') //phai
				{
					
						clrscr();
						level_1();
						x++;
						outPutNV_GoToX();
					
					
				}
				if (a == 'a') // trai
				{
					clrscr();
					level_1();
					x--;
					outPutNV_GoToX();
				
				}
				if (a == 'w')//len
				{
					clrscr();
					level_1();
					y-=1;
					outPutNV_GoToYTop();
				
				}
				if (a == 's') //xuong
				{
					clrscr();
					level_1();
					y+=1;
					outPutNV_GoToYDow();
				
				}
				gotoXY(120,4);
				//cout << x <<"  "<< y;
			}
			else
			{
				clrscr();
				level_1();
				outPutNV();
			}	
			diem++;
		}
		// test win
		/*level_1();
		x = 97;
		y = 28;
		outPutNV();
		getch();*/
		if(checkWin() == true)
			flag = false;
	}
}
void play_level2()
{
	char a;
	bool flag = true;
	inputNV();
	level_2();
	y = 4;
	outPutNV();
	while (flag == true )
	{
		
		if (_kbhit())
		{
			a = _getch();
			if(checkNull(p2,a)){
				if ( a =='d') //phai
				{
					
						clrscr();
						level_2();
						x++;
						outPutNV_GoToX();
					
					
				}
				if (a == 'a') // trai
				{
					clrscr();
					level_2();
					x--;
					outPutNV_GoToX();
				
				}
				if (a == 'w')//len
				{
					clrscr();
					level_2();
					y-=1;
					outPutNV_GoToYTop();
				
				}
				if (a == 's') //xuong
				{
					clrscr();
					level_2();
					y+=1;
					outPutNV_GoToYDow();
				
				}
				gotoXY(120,4);
				cout << x <<"  "<< y;
			}
			else
			{
				clrscr();
				level_2();
				outPutNV();
			}	
			diem++;
		}
		// test win
		/*level_1();
		x = 97;
		y = 28;
		outPutNV();
		getch();*/
		if(checkWin() == true)
			flag = false;
	}
}
void game()
{
	int a;
	cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  WELCOME TO GAME MAZE" << endl;
	cout <<"\n\n\t\t\t  WHAT YOUR NAME?" << endl;
	cout <<"\n\n\t\t\t  My Name :________________" << endl;
	gotoXY(35,15);
	cin >> name;
	InputTen(name);
	clrscr();
	bool flag = true;
	while(flag){
		cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  Ban Muon choi leve1 - An Phim 1" << endl;
		cout <<"\n\n\t\t\t  Ban Muon choi leve2 - An Phim 2" << endl;
		cout <<"\n\n\t\t\t  Ban Co muon ket thuc - an phim 0" << endl;
		do {
			cin >> a;
			if (a !=0 && a!= 1 && a!= 2)
				cout << "Khong hop le.Xin nhap lai: ";
		} while (a !=0 && a!= 1 && a!= 2);
		clrscr();
		switch(a){
		case 0:
		{
			flag = false;
			break;
		}
		case 1 :
		{
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  W - di chuyen di len" << endl;
			Sleep(500);
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  S - di chuyen di xuong" << endl;
			Sleep(500);
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  A - di chuyen di qua trai" << endl;
			Sleep(500);
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  D - di chuyen di qua phai" << endl;
			Sleep(500);
			clrscr();
			play_level1(); 
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  Chuc Mung Ban Da Vuot Qua level 1" << endl;
			break;
		}
		case 2 :
		{
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  W - di chuyen di len" << endl;
			Sleep(500);
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  S - di chuyen di xuong" << endl;
			Sleep(500);
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  A - di chuyen di qua trai" << endl;
			Sleep(500);
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  D - di chuyen di qua phai" << endl;
			Sleep(500);
			clrscr();
			play_level2(); 
			clrscr();
			cout <<"\n\n\n\n\n\n\n\n\n\t\t\t  Chuc Mung Ban Da Vuot Qua level 2" << endl;
			flag = false;
			break;
		}
		}	
		
	}
	InputDiem(diem);
}
int main()
{
	game();
	high_Score();
	getch();

	return 0;	
}