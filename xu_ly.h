#pragma once
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <conio.h>
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


//LOAD DU LIEU DAU SACH TU FILE
void Load_DS(LIST_DAUSACH &lDS);
//SAVE TAT CA DAU SACH VAO FILE
void Save_DS(LIST_DAUSACH lDS);



//===================================================================2
void GioiThieu(){
	system("color 0E");
	ShowCur(false);
	string a;
	
	
	SetColor(WHITE);
	
	gotoxy(60,1); cout << "  _   _ _   _   _  _    _    _    ___  _ _  _ _    _ _  _  ___  _  _    ";
	gotoxy(60,2); cout << " / \\ | | | / \\ | \\| |  | |  | |  |_ _|| U || | |  | | || || __|| \\| |   ";
	gotoxy(60,3); cout << "( o )| U || o || \\\\ |  | |_ | |   | | |   || U |  | V || || _| | \\\\ |   ";
	gotoxy(60,4); cout << " \\_,7|___||_n_||_|\\_|  |___||_|   |_| |_n_||___|   \\_/ |_||___||_|\\_|   ";	
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
			for (int j = 0; j < sosach; j++)
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

//===================================================================
void Save_DS(LIST_DAUSACH lDS)
{
	fstream outFile;
	outFile.open("DauSach.txt", ios::out);
	if(outFile.is_open())
	{
		outFile << lDS.n + 1 <<endl;
		for (int i = 0 ; i <= lDS.n ;i++)
		{
			outFile <<lDS.ListDS[i]->info.tensach <<endl;
			outFile <<lDS.ListDS[i]->info.ISBN<<endl;
			outFile <<lDS.ListDS[i]->info.tacgia<<endl;
			outFile <<lDS.ListDS[i]->info.theloai<<endl;
			outFile <<lDS.ListDS[i]->info.sotrang<<endl;
			outFile <<lDS.ListDS[i]->info.namxuatban<<endl;
			
			outFile <<lDS.ListDS[i]->dms.n <<endl;
			
			for (NODE_DMS* p  = lDS.ListDS[i]->dms.pHead ; p != NULL ;  p = p->pNext )
			{
				outFile << p->data.masach << endl;
				outFile << p->data.trangthaisach << endl;
				outFile << p->data.vitrisach << endl;
			}
		}
	}
	else
	{
		cout << "KET NOI VOI FILE DauSach THAT BAI! ";
	}
	outFile.close();
}
//===================================================================

//===================================================================3
void ManHinhChinh(){
	system("color 0E");
	clrscr();

	
	string a;
	int y=0;
	SetColor(WHITE);
	gotoxy(60,1); cout << "  _   _ _   _   _  _    _    _    ___  _ _  _ _    _ _  _  ___  _  _    ";
	gotoxy(60,2); cout << " / \\ | | | / \\ | \\| |  | |  | |  |_ _|| U || | |  | | || || __|| \\| |   ";
	gotoxy(60,3); cout << "( o )| U || o || \\\\ |  | |_ | |   | | |   || U |  | V || || _| | \\\\ |   ";
	gotoxy(60,4); cout << " \\_,7|___||_n_||_|\\_|  |___||_|   |_| |_n_||___|   \\_/ |_||___||_|\\_|   ";	
//	DrawMainMenu(keyMainMenu, 5);
		
	return;
}
//===================================================================3

//===================================================================1
void MainMenu(LIST_DAUSACH &lDS){
	int result;
	// set console window.
	SetConsoleTitle(_T("QUAN LY THU VIEN"));
	resizeConsole(GWIDTH, GHEIGHT);
	
	//LOAD DATA TU FILE
	Load_DS(lDS);
	

	// HIEU UNG INTRODUCE.
	GioiThieu();
	clrscr();//XOA MAN HINH
	

	char ch;
	//VONG LAP VO HAN DE XU LY
	do
	{
		system("cls");
		cout<<"\n\t\tMAIN MENU\n";
		cout<<"\n\t01. QUAN LY SACH";
		cout<<"\n\t02. QUAN LY DOC GIA";
		cout<<"\n\t03. QUAN LY MUON SACH";
		cout<<"\n\t04. QUAN LY TRA SACH";
		cout<<"\n\t05. THONG KE";
		cout<<"\n\t06. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-6) ";
		cin>>ch; fflush(stdin);
		switch(ch)
		{
			case '1':
				system("cls");
				QuanLiDauSach(lDS);
				break;
			case '2':
			//	DG_management();
				break;
			case '3':
			//	PhieuMuon_management();
				break;
			case '4':
			//	Tra_management();
				break;
			case '6':
				exit(0);
				default :cout<<"\a";
		}
	}while(ch!=6);
		
}
	

//=============================================================1
