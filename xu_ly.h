#pragma once
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <conio.h>
//#include "DSDocGia.h"
//#include "DauSach.h"
#include <string>
#include "ve_hinh.h"
#include "DauSach.h"
using namespace std;

//PHAN GIOI THIEU
void GioiThieu();


// XU LY MENU CHINH
void MainMenu();

// HIEU UNG MAN HINH CHINH
void ManHinhChinh();

//// load du lieu doc gia tu File 
//void Load_DG(NODE_DG &tree);
//LOAD DU LIEU DAU SACH TU FILE
void Load_DS(LIST_DAUSACH &lDS);
//HIEU UNG CHU CHAY
char dongChuChay[] = "   WELCOME TO MANAGER LIBRARY";

int *mangMaDocGia;

//===================================================================2
void GioiThieu(){
	system("color 0E");
	ShowCur(false);
	string a;
	
	//LAY TU FILE O CHE DO CHI DOC
	ifstream inFile("introduce.txt",ios::in);
	if(inFile.good()) //KIEM TRA XEM FILE CO KET NOI DUOC HAY KHONG ?
	{
		while(!inFile.eof())
		{
			getline(inFile,a);
			SetColor(WHITE);
			Sleep(30);
			cout<<a<<endl;
		}
	}
	else  //TRA VE LOI
	{
		cout << "Lien ket voi File introduce khong thanh cong! " << "\n";
	}
	
	SetColor(WHITE);
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
	
	// NHAN ENTER DE THOAT KHOI VONG LAP
	gotoxy(75, 35);
	cout << "PRESS ENTER TO CONTINUE!! ";
	cin.ignore();
	
	return;
}
//===================================================================2

//===================================================================
void Load_DS(LIST_DAUSACH &lDS){
	fstream inFile;
	dauSach info;
	inFile.open("DauSach.txt", ios::in);
	pDAU_SACH pDS;
	DMS dms;
	int sodausach, sosach;
	if(inFile.is_open()){
		string temp;
		inFile >> sodausach;
		getline(inFile, temp);
		
		for (int i = 0;i < sodausach; i++)
		{
			pDS = new DAU_SACH;
			if(pDS == NULL) continue;
			
			//LOAD THONG TIN VAO BIEN TAM
			
			getline(inFile, info.tensach);
			getline(inFile, info.ISBN);
			getline(inFile, info.tacgia);
			getline(inFile, info.theloai);
			inFile >> info.sotrang;
			inFile >> info.namxuatban;
			
			//LOAD THONG TIN VAO DAU SACH
			pDS->info = info;
			
			inFile >> sosach;
			getline(inFile, temp);
			initList_DMS(pDS->dms);
			for (int j = 0; j< sosach; j++)
			{
				getline(inFile , dms.masach);
				inFile >> dms.trangthaisach;
				if(dms.trangthaisach == 1) pDS->soluongsachdamuon++;
				getline(inFile, temp);
				getline(inFile, dms.vitrisach);
				AddTailList_DMS(pDS->dms, dms);
			}
			
			Insert_DauSach(lDS, pDS);
		}
	}
	else {
		cout << "KET NOI VOI FILE DauSach THAT BAI! ";
	}
	inFile.close();
}
//===================================================================

//===================================================================3
void ManHinhChinh(){
	system("color 0E");
	clrscr();

	
	string a;
	int y=0;
	
	//LAY TU FILE VA CHI DOC
	ifstream inFile("QuanLyThuVien.txt",ios::in);
	
	//KIEM TRA XEM FILE CO KET NOI DC KO
	if(inFile.good()){
		while(!inFile.eof()){
			getline(inFile,a);
			SetColor(WHITE);
			Sleep(100);
			gotoxy(40, y++);
			cout <<a<<endl;
		}
	}
	else  //TRA VE LOI
	{
		cout << "Lien ket voi File QuanlyThuVien khong thanh cong! " << "\n";
	}
	
	DrawMainMenu(keyMainMenu, 5);
		
	inFile.close();
	return;
}
//===================================================================3

//===================================================================1
void MainMenu(LIST_DAUSACH &lDS){
	// set console window.
	SetConsoleTitle(_T("QUAN LY THU VIEN"));
	resizeConsole(GWIDTH, GHEIGHT);
	
	//LOAD DATA TU FILE
//	Load_DG(tree);
	Load_DS(lDS);
	
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
	clrscr();
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
				Xuat_ListDStheoTT(lDS);
			}
			else if( result == 2)
			{
				Menu_DMS(lDS);
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
//=============================================================1
