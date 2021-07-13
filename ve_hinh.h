#pragma once
#include <iostream>
#include "Marcro.h"
#include "mylib.h"
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iomanip>      // std::setw, setfill
using namespace std;


// VE MENU CHINH
void DrawMainMenu(string key[], int nKey);

// TAO O HINH CHU NHAT THAY DOI THEO CHIEU DAI TEXT TRUYEN VAO
void CreateBox(int x, int y, string text, int length);

//IN RA DONG CHU CHAY VAO CONSOLE
void ChuChay(char dChu[], int x ,int y);

//hieu ung chon cac muc trong MainMenu
int ChooseMainMenu(int nKey);

//hieu ung chon cac muc trong SubMenu
int ChonMucTrongMenu(string key[], int xSubMenu, int ykey[], int nkey);

// ham hien thi bang thong tin dau sach
void DisplayDS(string key[], int nKey, int xDisplay[]);

// ham hien thi bang thong tin doc gia
void DisplayDG(string key[], int nKey, int xDisplay[]);

// xoa mot dong
void XoaMotDong(int width);

// xoa mot phan man hinh
void XoaMotVung(int x, int y, int ndoc, int width);


void EffectiveMenu(int pos , int flag);

void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag);
// ve cac Menu con
void MenuDocGia(string key[], int nKey);
void MenuDauSach(string key[], int nKey);
void MenuSach(string key[], int nKey);

void EffectiveMenu(int pos , int flag);

void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag);
// highlight o Menu con
void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor);


string keyMainMenu[5] = { " ***MENU CHINH*** ", "QUAN LY DOC GIA", "QUAN LY DAU SACH ", "QUAN LY SACH", "THOAT" };

string keyDisplayDG[5] = { "MA DG", "     HO DG", "TEN DG", "PHAI  ", "TT THE" };

string keyDisplayDS[6] = {"        DAU SACH", " ISBN ", "    TAC GIA", "  THE LOAI ", " SO TRG ", " NXB"};

string keyDocGia[3] = { "            CAP NHAT DOC GIA                 ",
							"     HIEN THI DANH SACH TAT CA DOC GIA       ",
							"  HIEN THI DS CAC DOC GIA MUON SACH QUA HAN  " };
string keySach[3] = { "       TRA SACH       ",
								" SACH MUON NHIEU NHAT ",
								"       MUON SACH      " };
								
string keyDauSach[3] = { "    CAP NHAT DAU SACH   ",
							"  HIEN THI CAC DAU SACH " ,
							" CAP NHAT DANH MUC SACH "};
int xDisplayDS[7] = { 1, 35, 42, 61, 73, 83 , 93 };
int xMainMenus[5] = { 18,50,76, 105,130 };
int yDocGia[3] = { 20, 24, 28};
int yDauSach[3] = { 20, 24, 28 };
int ySach[3] = { 20,23,26 };
//int xMainMenus[5] = { 8,34,60, 89,113 };

int xDisplayDG[6] = { 3,13, 32,46,53,65 };



//===========================================
void DrawMainMenu(string key[], int nKey){
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
					//Beep(500,50);
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
					//Beep(400,50); //key right
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
					//Beep(600, 50);
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
		gotoxy(xMainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(AQUA);
		cout << keyMainMenu[pos + 1] ;
		
		gotoxy(xMainMenus[(pos + 3) % 4 + 1] - 1 , yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 3)% 4 + 1];
	}
	else if (flag == 2)
	{
		// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
		
		gotoxy(xMainMenus[pos + 1] - 1 , yMainMenu);
		SetBGColor(AQUA);
		cout <<  keyMainMenu[pos + 1];
		
		gotoxy(xMainMenus[(pos + 1) % 4 + 1] - 1, yMainMenu);
		normalBGColor();
		cout <<keyMainMenu[(pos + 1) % 4 + 1 ];
	}	
}
//===========================================

//===========================================
void MenuDocGia(string key[], int nKey){
	normalBGColor();
	SetBGColor(BLACK);
	for (int i=0; i< nKey ;i++)
	{
		CreateBox(xDocGia, yDocGia[i], key[i], (int)key[i].length());
	}
	HighLight1(keyDocGia[0], 0, xDocGia, yDocGia, GREEN, AQUA);
	ShowCur(false);
}
//===========================================

//===========================================
void MenuDauSach(string key[], int nKey)
{
//	normalBGColor();
//	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xDauSach, yDauSach[i], key[i], (int)key[i].length());
	}
//	HighLight1(keyDauSach[0], 0, xDauSach, yDauSach, GREEN, AQUA);
//	ShowCur(false);
}
//===========================================

//===========================================
void MenuSach(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSach, ySach[i], key[i],(int)key[i].length());
	}
	HighLight1(keySach[0], 0, xSach, ySach, GREEN, AQUA);
	ShowCur(false);
}
//===========================================


//===========================================
void HighLight1(string key , int index, int x, int y[], int newColor, int oldColor){
	//DEN DIA CHI CAN HIGHLIGHT
	gotoxy(x-1, y[index]);
//	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}
//===========================================

//===========================================
int ChonMucTrongMenu(string key[], int xSubMenu, int ykey[], int nKey){
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
					EffectiveSubMenu(key,xSubMenu,ykey,nKey,currposSubMainMenu,2);
					//Beep(300,10);
					break;
				case KEY_DOWN:
					if(currposSubMainMenu < nKey - 1){
						currposSubMainMenu = currposSubMainMenu + 1;
					}
					else{
						currposSubMainMenu = 0;
					}
					EffectiveSubMenu(key,xSubMenu,ykey,nKey,currposSubMainMenu,1);
					//Beep(250,10);
					break;
				case ESC:
					return -1;	
				case ENTER:
					//Beep(600, 10);
					return currposSubMainMenu;
			}
		}
	}
}
//===========================================

//===========================================
void EffectiveSubMenu(string key[], int xSubMenu, int ykey[],int nKey, int pos, int flag)
{
	// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
	if(flag == 1){
		
		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(AQUA);
		cout << key[pos];
		
		gotoxy(xSubMenu - 1,ykey[(pos + nKey - 1) % nKey]);
		SetBGColor(BLACK);
		cout <<key[(pos + nKey - 1)% nKey];
	}
	else if (flag == 2){
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
		ShowCur(false);
		
		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(AQUA);
		cout << key[pos];

		gotoxy(xSubMenu - 1, ykey[(pos + 1) % nKey]);
		SetBGColor(BLACK);
		cout << key[(pos + 1) % nKey];
	}
}
//===========================================

//===========================================
void DisplayDG(string key[],int nKey, int xDisplay[]){
	ShowCur(true);
	//normalBGColor();
	system("color CE");
	//HIEN THI CAC DANH MUC TRONG BANG HIEN THI
	for (int i=0; i< nKey ;i++){
		gotoxy(xDisplay[i] + 3, yDisplay + 1);
		cout << key[i];
	}
	//HIEN THI COT HAI BEN
	SetColor(WHITE);
	for (int j = yDisplay;j <= yDisplay + 32 ;j++)
	{
		for (int i = 0 ; i <nKey + 1;i++)
		{
			gotoxy(xDisplay[i], j);
			cout <<char(186);
		}
	}
	//HIEN THI DONG HAI BEN
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{
		gotoxy(i, yDisplay);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 32);
		if (i == xDisplay[nKey])
		{
			cout << char(188); //nga 3 sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(202);
		else if (i == xDisplay[0])
			cout << char(200); //nga 3 sang phai
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
}
//===========================================

//===========================================
void DisplayDS(string key[],int nKey, int xDisplay[])
{
	system("color 0E");
	//HIEN THI CAC DANH MUC TRONG BANG HIEN THI
	for (int i = 0; i < nKey;i++){
		gotoxy(xDisplay[i] + 1 , yDisplay + 1);
		cout << key[i];
	}
	//HIEN THI COT HAI BEN 
	SetColor(WHITE);
	for (int j = yDisplay; j <= yDisplay + 32; j++)
	{
		for (int i = 0; i < nKey + 1; i++)
		{
			gotoxy(xDisplay[i], j);

			cout << char(186);
		}
	}

	//HIEN THI DONG HAI BEN
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{

		gotoxy(i, yDisplay);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4]  || i == xDisplay[5])
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 32);
		if (i == xDisplay[0])
		{
			cout << char(200); //qeo sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(188); //qeo sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
			cout << char(202);
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
}
//===========================================


//===========================================
void XoaMotDong(int width){
	cout << " " << setw(width) << setfill(' ') << " ";
}
//===========================================

//===========================================
void XoaMotVung(int x, int y, int ndoc, int witdh){
	for (int i =0 ; i<ndoc ;i++){
		gotoxy(x , y + i);
		XoaMotDong(witdh + 6);
	}
}
//===========================================
