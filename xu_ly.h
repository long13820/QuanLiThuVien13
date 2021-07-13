#pragma once
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include "DSDocGia.h"
//#include "DauSach.h"
#include <string>
#include "ve_hinh.h"
#include "DauSach.h"
using namespace std;

//PHAN GIOI THIEU
void GioiThieu();


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
void GioiThieu(){
	system("color 0E");
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
	
	//CayLoading(LIGHT_YELLOW);**//SAU KHI XONG SE THEM
	ShowCur(false);
	
	// NHAN ENTER DE THOAT KHOI VONG LAP
	gotoxy(75, 35);
	cout << "PRESS ENTER TO CONTINUE!! ";
//	SetBGColor(AQUA);
//	SetColor(AQUA);
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
	system("color 0E");
	clrscr();

	DrawMainMenu(keyMainMenu, 5);
	
	string a;
	int y=0;
	
	//LAY TU FILE VA CHI DOC
	ifstream inFile("QuanLyThuVien.txt",ios::in);
	
	//KIEM TRA XEM FILE CO KET NOI DC KO
	if(inFile.good()){
		while(!inFile.eof()){
			getline(inFile,a);
			Sleep(100);
			gotoxy(40, y++);
			cout <<a<<endl;
		}
	}
	else  //TRA VE LOI
	{
		cout << "Lien ket voi File QuanlyThuVien khong thanh cong! " << "\n";
	}
	
	// SET KHUNG
	gotoxy(xOrdinal + 64, yOrdinal + 34);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);

	gotoxy(xOrdinal + 64, yOrdinal + 35);
	cout << char(186) << setw(40) << setfill(' ') << char(186);

	gotoxy(xOrdinal + 64, yOrdinal + 36);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);

	ChuChay(dongChuChay, xOrdinal + 70, yOrdinal + 35);
	inFile.close();
	return;
}
//===================================================================
void MainMenu(TREE_DG &tree,LIST_DAUSACH &lDS){
	// set console window.
	SetConsoleTitle(_T("QUAN LY THU VIEN"));
	resizeConsole(GWIDTH, GHEIGHT);
	
//Load data from file
//	Load_DG(tree);
	
	
//	// Load mang ma doc gia
//	fstream inFile;
//	inFile.open("MangSoNgauNhien.txt", ios::in);
//	int n; // so phan tu cua mang
//	inFile >> n;
//	mangMaDocGia = new int[n];
//	for(int i = 0; i < n; i++)
//	{
//		inFile >>  mangMaDocGia[i];
//	}
//	inFile.close();
//	
//		clrscr();
	// HIEU UNG INTRODUCE.
	GioiThieu();
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
	 gotoxy(75,32);
	 cout << "ESC: VE MENU CHINH";
	 
	 switch(type)
	 {
//	 	case 0:
//	 		MenuDocGia(keyDocGia, 3);
//	 		
//	 		result = ChonMucTrongMenu(keyDocGia,xDocGia, yDocGia, 3);
//	 		
//	 		if(result == -1){
//	 			check = true ;	
//	 			goto label;
//			}
//			if (result == 0)
//			{
//				Menu_DocGia(tree);
//			}
//	 		check = false;
//			type = 0;
//			goto label;
//	 		break;
	 	case 1:
	 		MenuDauSach(keyDauSach, 3);
	 		
	 		result = ChonMucTrongMenu(keyDauSach, xDauSach, yDauSach, 3);
	 		
	 		if(result == -1)
	 		{
	 			check = true;
				goto label;	
			}
			if(result == 0){
				Menu_DauSach(lDS);
			}
			else if( result == 1){
				Output_ListDStheoTT(lDS);
			}
			check = false;
			type = 1;
			goto label;
			break;
//		case 2:
//	 		MenuSach(keySach, 3);
//	
//	 		result = ChonMucTrongMenu(keySach, xSach, ySach, 3);
//	 		
//	 		if(result == -1)
//	 		{
//	 			check = true;
//				goto label;	
//			}
//			
//			check = false;
//			type = 2;
//			goto label;
//			break;
//		case 3:
//			//LUU DATA TU CHUONG TRINH VAO FILE
//			return;
	 }
	 				
	}
	
}
