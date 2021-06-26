#include <iostream>
#include "Marcro.h"
#include "mylib.h"

#include <iomanip>      // std::setw, setfill
using namespace std;

string keyMainMenu[5] = { " ***MENU CHINH*** ", "QUAN LY DOC GIA", "QUAN LY DAU SACH ", "QUAN LY SACH", "THOAT" };

//VE CAY LOADING
void CayLoading(int Color);

//VE KHUNG MENU
void VeKhungMenu();

// VE MENU CHINH
void DrawMainMenu(string key[], int nKey);

// TAO O HINH CHU NHAT THAY DOI THEO CHIEU DAI TEXT TRUYEN VAO
void CreateBox(int x, int y, string text, int length);

//IN RA DONG CHU CHAY VAO CONSOLE
void ChuChay(char dChu[], int x ,int y);

//hieu ung chon cac muc trong MainMenu
int ChooseMainMenu(int nKey);


int xMainMenus[5] = { 8,40,66, 95,120 };
//===========================================
void CayLoading(int Color){
	SetColor(Color);
	for (int i=xLoading; i<=xLoading +130 ;i++)
	{
		gotoxy(i,yLoading);
		Sleep(15);
		cout <<  char(219);
	}
}
//===========================================

//===========================================
void VeKhungMenu(){
	ShowCur(false);
	int i;
	gotoxy(xOrdinal,yOrdinal);
	
	//VE HANG NGANG TREN
	for (int i=0;i <= xMax;i++)
	{
		SetColor(WHITE);
		cout << char(219);
	}
	//VE HANG NGANG DUOI
	gotoxy(xOrdinal, yOrdinal + 15);
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		cout << char(219);
	}

	// VE HANG DOC TRAI
	for (int i = 0; i < yOrdinal + 15; i++)
	{
		gotoxy(xOrdinal, yOrdinal + i);
		SetBGColor(WHITE);
		cout << "  ";
	}

	//VE HANG DOC PHAI
	for (int i = 0; i < yOrdinal + 15; i++)
	{
		gotoxy(xMax - 1, yOrdinal + i);
		SetBGColor(WHITE);
		cout << "   ";
	}
}
//===========================================

//===========================================
void DrawMainMenu(string key[], int nKey){
	normalBGColor();
	for (int i=0; i < nKey;i++)
	{
		CreateBox(xMainMenus[i],yMainMenu, key[i],(int)key[i].length());
	}
}
//===========================================

//===========================================
void CreateBox(int x,int y, string text, int length)
{
	gotoxy(x - 2, y - 1);
	cout << char(201) << setw(length) << setfill(char(205)) << char(205) << char(187);

	gotoxy(x - 2, y);
	cout << char(186) << text << setw(length - text.length() + 1) << setfill(' ') << char(186);

	gotoxy(x - 2, y + 1);
	cout << char(200) << setw(length) << setfill(char(205)) << char(205) << char(188);
}
//===========================================

//===========================================
void ChuChay(char dChu[], int x ,int y){
	SetColor(WHITE);
	ShowCur(false);
	char c[40];
	int length = (int)strlen(dChu);
	
	for (int i=0; i<length;i++)
	{
		strncpy(c,dChu+i,40);
		c[39]='\0';
		Sleep(100);
		gotoxy(x,y);
		cout<<"                                  ";
		gotoxy(x, y); // VI TRI DE IN DONG CHU CHAY
		cout << c;
		if (i == length - 1) i = 0;  // CHAY VO HAN

		if (_kbhit()) {
			normalBGColor();
			return;  // CO PHIM NHAN VAO THI DUNG
		}
	}
}
//===========================================

//===========================================
int ChooseMainMenu(int nKey){
	int currposMainMenu = -1;
	ShowCur(false);
	
	int kb_hit;
}
//===========================================

