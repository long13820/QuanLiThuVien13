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

// VE HINH BANG NHAP
void VeHinhBangNhap(int x, int y, int dorong, string str);

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

// ve bang nhap thong tin
void BangNhap(int x, int y, int nngang, string key[], int nkey);

// ve bang huong dan Guides
void BangGuides(int x, int y, int nngang, string key[], int nkey);

string keyMainMenu[5] = { " ***MENU CHINH*** ", "QUAN LY DOC GIA", "QUAN LY DAU SACH ", "QUAN LY SACH", "THOAT" };

string keyDisplayDG[5] = { "MA DG", "     HO DG", "TEN DG", "PHAI  ", "TT THE" };

string keyDisplayDS[6] = {"        DAU SACH", "  ISBN", "    TAC GIA", "  THE LOAI ", " SO TRANG", " NXB"};

string keyDocGia[3] = { "            CAP NHAT DOC GIA                 ",
							"     HIEN THI DANH SACH TAT CA DOC GIA       ",
							"  HIEN THI DS CAC DOC GIA MUON SACH QUA HAN  " };
string keySach[3] = { "       TRA SACH       ",
								" SACH MUON NHIEU NHAT ",
								"       MUON SACH      " };
								
string keyDauSach[3] = { "    CAP NHAT DAU SACH   ",
							"  HIEN THI CAC DAU SACH " ,
							" CAP NHAT DANH MUC SACH "};
							
string keyBangNhapDauSach[14] = {"               CAP NHAT DAU SACH               ",
									"                                                     ",
									" TEN SACH     :",
									"                                                     ",
									" ISBN         :",
									"                                                     ",
									" TAC GIA      :",
									"                                                     ",
									" THE LOAI     :",
									"                                                     ",
									" SO TRANG     :",
									"                                                     ",
									" NAM XUAT BAN :",
									"                                                     " };

string keyGuide2[7] = { "                     GUIDES                   ",
						"-> TEN SACH     : Toi da 24 ky tu, gom co chu va so ",
						"-> ISBN         : Gom 6 ky tu, chi lay ky tu chu    ",
						"-> TAC GIA      : Toi da 17 ky tu, chi lay ky tu chu" ,
						"-> THE LOAI     : Toi da 11 ky tu, chi lay ky tu chu" ,
						"-> SO TRANG     : So trang khong qua 999999         " ,
						"-> NAM XUAT BAN : Nam XB khong lon hon nam hien tai " };

int xDisplayDS[7] = { 1, 30, 40, 59, 74, 84, 95 };
int xMainMenus[5] = { 18,50,76, 105,130 };
int yDocGia[3] = { 20, 24, 28};
int yDauSach[3] = { 20, 24, 28 };
int ySach[3] = { 20,23,26 };
//int xMainMenus[5] = { 8,34,60, 89,113 };

int xDisplayDG[6] = { 3,13, 32,46,53,65 };



//===========================================2
void DrawMainMenu(string key[], int nKey){
	for (int i=0; i < nKey;i++)
	{
		CreateBox(xMainMenus[i],yMainMenu, key[i],(int)key[i].length());
	}
}
//===========================================2

//===========================================1
void CreateBox(int x,int y, string text, int length)
{
	gotoxy(x - 2, y - 1);
	cout << char(201) << setw(length) << setfill(char(205)) << char(205) << char(187);

	gotoxy(x - 2, y);
	cout << char(186) << text << setw(length - text.length() + 1) << setfill(' ') << char(186);

	gotoxy(x - 2, y + 1);
	cout << char(200) << setw(length) << setfill(char(205)) << char(205) << char(188);
}
//===========================================1

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
	ShowCur(false);
}
//===========================================

//===========================================3
void MenuDauSach(string key[], int nKey)
{
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xDauSach, yDauSach[i], key[i], (int)key[i].length());
	}
}
//===========================================3

//===========================================
void MenuSach(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSach, ySach[i], key[i],(int)key[i].length());
	}
	ShowCur(false);
}
//===========================================


//===========================================4
int ChonMucTrongMenu(string key[], int xSubMenu, int ykey[], int nKey){
	int currposSubMainMenu = 0;
	
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
//===========================================4

//===========================================5
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
//===========================================5

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
	for (int i =0 ; i< ndoc ;i++){
		gotoxy(x , y + i);
		XoaMotDong(witdh + 6);
	}
}
//===========================================

//===========================================
void BangNhap(int x, int y , int nngang, string key[], int nkey){
	int i;
//	SetColor(WHITE);
	for (i = 0; i < nkey + 2; i++)
	{
		gotoxy(x, y + i);
		if (i == 0)
		{
			cout << char(218) << setw(nngang + 10) << setfill(char(196)) << char(191);
		}
		else if (i == nkey + 1)
		{
			cout << char(192) << setw(nngang + 10) << setfill(char(196)) << char(217);
		}
		else {
			cout << char(124);
			cout << key[i - 1];
			gotoxy(x + nngang + 10, y + i);
			cout << char(124);
		}
	}
}
//===========================================

//===========================================
void BangGuides(int x,int y,int nngang, string key[],int nkey){
	int i;
	// ve khung
	for (i = 0; i < nkey + 2; i++)
	{
		gotoxy(x, y + i);
		if (i == 0)
		{
			cout << char(218) << setw(nngang + 10) << setfill(char(196)) << char(191);
		}
		else if (i == nkey + 1)
		{
			cout << char(192) << setw(nngang + 10) << setfill(char(196)) << char(217);
		}
		else {
			cout << char(124);
			cout << key[i - 1];
			gotoxy(x + nngang + 10, y + i);
			cout << char(124);
		}
	}
}
//===========================================

//===========================================
void VeHinhBangNhap(int x, int y, int dorong, string str){
	gotoxy(x, y - 1);
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x, y );
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x, y + 1);
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x + (int)str.length()/ 3, y + 1);
	
	gotoxy(x, y );
	cout << str;
	gotoxy(x, y + 2);
	cout << setw(4) << setfill(' ') << " ";
	gotoxy(x + dorong - 4, y + 2);
	cout << setw(4) << setfill(' ') << " ";
	gotoxy(x, y + 3);
	cout << setw(dorong) << setfill(' ') << " ";
}
//===========================================
