#pragma once
#include <tchar.h>
#include <iostream>
#include <fstream>
//#include "DSDocGia.h"
//#include "DauSach.h"
#include "mylib.h"
#include <string>
using namespace std;

void Introduce();
// xu ly MeNu chinh
void MainMenu();





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
	else  //Tra ve loi
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
	
	CayLoading();
}
void MainMenu(){
	int result;
	
	// set console window.
	SetConsoleTitle(_T("QUAN LY THU VIEN"));
	resizeConsole(GWIDTH, GHEIGHT);
	
	
	
	
	// hieu ung introduce.
	Introduce();
	
	
//	int type;
//	bool check = true;
}
