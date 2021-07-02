#pragma once
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include "DSDocGia.h"
//#include "DauSach.h"
#include <string>
#include "ve_hinh.h"
using namespace std;

void Introduce();


// XU LY MENU CHINH
void MainMenu();

// hieu ung man hinh chinh
void ManHinhChinh();

// load du lieu doc gia tu File 
void Load_DG(NODE_DG &tree);

//HIEU UNG CHU CHAY
char dongChuChay[] = "   WELCOME TO MANAGER LIBRARY";

int *mangMaDocGia;

//===================================================================
void Introduce(){
	system("color CE");
	ShowCur(false);
	string a;
	
	//LAY TU FILE O CHE DO CHI DOC
	ifstream inFile("introduce.txt",ios::in);
	if(inFile.good()) //KIEM TRA XEM FILE CO KET NOI DUOC HAY KHONG ?
	{
		while(!inFile.eof())
		{
			getline(inFile,a);
			SetColor(LIGHT_YELLOW);
			Sleep(30);
			cout<<a<<endl;
		}
	}
	else  //TRA VE LOI
	{
		cout << "Lien ket voi File introduce khong thanh cong! " << "\n";
	}
	
	SetColor(LIGHT_YELLOW);
	gotoxy(xTen+10,yTen);
	cout << "HOTEN : NGUYEN HOANG LONG";
	gotoxy(xTen+10, yTen + 1);
	cout << "MSSV  : N18DCCN108";
	gotoxy(xTen+10, yTen + 2);
	cout << "LOP   : D18CQCN03-N";
	gotoxy(xTen+40,yTen);
	cout << "HOTEN : HO DUC HOANG";
	gotoxy(xTen+40, yTen + 1);
	cout << "MSSV  : N18DCAT024";
	gotoxy(xTen+40, yTen + 2);
	cout << "LOP   : D18CQCAT02-N";
	gotoxy(xTen+70,yTen);
	cout << "HOTEN : TRUONG MINH LAP";
	gotoxy(xTen+70, yTen + 1);
	cout << "MSSV  : N18DCCN103";
	gotoxy(xTen+70, yTen + 2);
	cout << "LOP   : D18CQCN01-N";
	
	//CayLoading(LIGHT_YELLOW);
//	ShowCur(false);
	
	// NHAN ENTER DE THOAT KHOI VONG LAP
	gotoxy(45, 35);
	SetBGColor(BLUE);
	cout << "PRESS ENTER TO CONTINUE!! ";
	normalBGColor();
	
	while(!_kbhit())
	{
		gotoxy(35,30);
		SetColor(1 +rand() % 15);
		Sleep(100);
		//cout<<"LIBRARY MANAGEMENT";
	}
	SetBGColor(AQUA);
	SetColor(AQUA);
	cin.ignore();
	
	return;
}
//===================================================================

//===================================================================
void Load_DG(NODE_DG &tree){
	
}
//===================================================================

//===================================================================
void ManHinhChinh(){
	system("color CE");
	clrscr();
	normalTextColor();
//	ShowCur(false);
	VeKhungMenu();

	normalBGColor();
	DrawMainMenu(keyMainMenu, 5);
	normalBGColor();
	
	string a;
	int y=0;
	
	//LAY TU FILE VA CHI DOC
	ifstream inFile("QuanLyThuVien.txt",ios::in);
	
	//KIEM TRA XEM FILE CO KET NOI DC KO
	if(inFile.good()){
		while(!inFile.eof()){
			getline(inFile,a);
			SetBGColor(3);
			SetColor(11);
			Sleep(100);
			gotoxy(25, y++);
			cout <<a<<endl;
		}
	}
	else  //TRA VE LOI
	{
		cout << "Lien ket voi File QuanlyThuVien khong thanh cong! " << "\n";
	}
	normalBGColor();
	SetBGColor(BLACK);
	
	// SET KHUNG
	gotoxy(xOrdinal + 44, yOrdinal + 34);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);

	gotoxy(xOrdinal + 44, yOrdinal + 35);
	cout << char(186) << setw(40) << setfill(' ') << char(186);

	gotoxy(xOrdinal + 44, yOrdinal + 36);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);

	ChuChay(dongChuChay, xOrdinal + 50, yOrdinal + 35);
	inFile.close();
	return;
}
//===================================================================
void MainMenu(TREE_DG &tree){
	// set console window.
	SetConsoleTitle(_T("QUAN LY THU VIEN"));
	resizeConsole(GWIDTH, GHEIGHT);
	
//	//Load data from file
//	Load_DG(tree);
	
	// hieu ung introduce.
	Introduce();
	
	clrscr();//XOA MAN HINH
	
	int type;
	bool check = true;
	int result;
	//VONG LAP VO HAN DE XU LY
	while(true)
	{
label:
	 ManHinhChinh();
	 if(check) {type= ChooseMainMenu(5);}
	 gotoxy(55,32);
	 cout << "ESC: VE MENU CHINH";
	 
	 switch(type)
	 {
	 	case 0:
	 		MenuDocGia(keyDocGia, 3);
	 		
	 		result = ChonMucTrongMenu(keyDocGia,xDocGia, yDocGia, 3);
	 		
	 		if(result == -1){
	 			check = true ;	
	 			goto label;
			}
			if (result == 0)
			{
				Menu_DocGia(tree);
			}
//	 		check = false;
//			type = 0;
//			goto label;
	 		break;
	 	case 1:
	 		MenuDauSach(keyDauSach, 3);
	 		
	 		result = ChonMucTrongMenu(keyDauSach, xDauSach, yDauSach, 3);
	 		
	 		if(result == -1)
	 		{
	 			check = true;
				goto label;	
			}
			
//			check = false;
//			type = 1;
//			goto label;
			break;
		case 2:
	 		MenuSach(keySach, 3);
	
	 		result = ChonMucTrongMenu(keySach, xSach, ySach, 3);
	 		
	 		if(result == -1)
	 		{
	 			check = true;
				goto label;	
			}
			
//			check = false;
//			type = 2;
//			goto label;
			break;
//		case 3:
//			//LUU DATA TU CHUONG TRINH VAO FILE
//			return;
	 }
	 				
	}
	
}
