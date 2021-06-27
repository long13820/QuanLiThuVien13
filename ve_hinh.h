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

//hieu ung chon cac muc trong SubMenu
int ChooseSubMenu(string key[], int xSubMenu, int ykey[], int nkey);


void EffectiveMenu(int pos , int flag);

void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag);
// ve cac Menu con
void SubMainMenu1(string key[], int nKey);
void SubMainMenu2(string key[], int nKey);
void SubMainMenu3(string key[], int nKey);

void EffectiveMenu(int pos , int flag);

void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag);
// highlight o Menu con
void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor);



string keySubMainMenu1[3] = { "            CAP NHAT DOC GIA                 ",
							"     HIEN THI DANH SACH TAT CA DOC GIA       ",
							"  HIEN THI DS CAC DOC GIA MUON SACH QUA HAN  " };
string keySubMainMenu2[3] = { "    CAP NHAT DAU SACH   ",
							"  HIEN THI CAC DAU SACH " ,
							" CAP NHAT DANH MUC SACH "};


string keySubMainMenu1[3] = { "            CAP NHAT DOC GIA                 ",
							"     HIEN THI DANH SACH TAT CA DOC GIA       ",
							"  HIEN THI DS CAC DOC GIA MUON SACH QUA HAN  " };

int xMainMenus[5] = { 8,40,66, 95,120 };
int ySubMainMenus1[3] = { 20, 24, 28};
int ySubMainMenus2[3] = { 22, 26, 30 };
int ySubMainMenus3[3] = { 20,23,26 };
//int xMainMenus[5] = { 8,34,60, 89,113 };
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
	while(true)
	{
		if(_kbhit()){
			kb_hit =  _getch();
			if(kb_hit == 224 || kb_hit == 0)
			{
				kb_hit =_getch();
			}
			
			switch(kb_hit)
			{
				case KEY_LEFT:
					Beep(500,50);
					if(currposMainMenu > 0)
					{
						currposMainMenu = currposMainMenu - 1 ;
					}
					else{
						currposMainMenu= nKey - 2 ;
					}
					EffectiveMenu(currposMainMenu, 2);
					break;
				case KEY_RIGHT:
					Beep(400,50); //key right
					if(currposMainMenu < nKey - 2)
					{
						currposMainMenu = currposMainMenu + 1 ;
					}
					else {
						currposMainMenu = 0 ;//move to first value in menu system	
					}
					EffectiveMenu(currposMainMenu, 1);
					break ;
				case ENTER: //enter
					Beep(600, 50);
					return currposMainMenu;

			}
			}
		}
	}

//===========================================

//===========================================
void EffectiveMenu(int pos, int flag){
	// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
	if (flag == 1)
	{
		ShowCur(false);
		gotoxy(xMainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(BLACK);
		SetColor(WHITE);
		cout << keyMainMenu[pos + 1] ;
		
		gotoxy(xMainMenus[(pos + 3) % 4 + 1] - 1 , yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 3)% 4 + 1];
	}
	else if (flag == 2)
	{
		// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
		ShowCur(false);
		
		gotoxy(xMainMenus[pos + 1] - 1 , yMainMenu);
		SetBGColor(BLACK);
		SetColor(WHITE);
		cout <<  keyMainMenu[pos + 1];
		
		gotoxy(xMainMenus[(pos + 1) % 4 + 1] - 1, yMainMenu);
		normalBGColor();
		cout <<keyMainMenu[(pos + 1) % 4 + 1 ];
	}	
}
//===========================================

//===========================================
void SubMainMenu1(string key[], int nKey){
	normalBGColor();
	SetBGColor(BLACK);
	for (int i=0; i< nKey ;i++)
	{
		CreateBox(xSubMainMenus1, ySubMainMenus1[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu1[0], 0, xSubMainMenus1, ySubMainMenus1, GREEN, AQUA);
	ShowCur(false);
}
//===========================================

//===========================================
void SubMainMenu2(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus2, ySubMainMenus2[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu2[0], 0, xSubMainMenus2, ySubMainMenus2, GREEN, AQUA);
	ShowCur(false);
}
//===========================================

//===========================================
void SubMainMenu3(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus3, ySubMainMenus3[i], key[i],(int)key[i].length());
	}
	HighLight1(keySubMainMenu3[0], 0, xSubMainMenus3, ySubMainMenus3, GREEN, AQUA);
	ShowCur(false);
}
//===========================================


//===========================================
void HighLight1(string key , int index, int x, int y[], int newColor, int oldColor){
	//DEN DIA CHI CAN HIGHLIGHT
	gotoxy(x-1, y[index]);
	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}
//===========================================

//===========================================
int ChooseSubMenu(string key[], int xSubMenu, int ykey[], int nKey){
	int currposSubMainMenu = 0;
	ShowCur(false);
	
	int kb_hit;
	while(true)
	{
		if(_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0) {kb_hit = _getch();}
			
			switch(kb_hit){
				case KEY_UP:
					if(currposSubMainMenu > 0){
						currposSubMainMenu = currposSubMainMenu - 1;
					}
					else{
						currposSubMainMenu = nKey - 1;
					}
					
			}
		}
	}
}
//===========================================

//===========================================
void EffectiveSubMenu(string key[], int xSubMenu, int ykey[],int nKey, int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if(flag == 1){
		ShowCur(false);
		
		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << key[pos];
		
		gotoxy(xSubMenu - 1,ykey[(pos + nKey - 1) % nKey]);
		SetBGColor(BLACK);
		SetColor(LIGHT_YELLOW);
		cout <<key[(pos + 1)% nKey];
	}
	
}
//===========================================
