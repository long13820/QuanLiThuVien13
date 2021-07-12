#pragma once
#include <iostream>
//////#include <string>
//#include "Muon_Tra.h"
#include "GlobalVariable.h"
#include "ve_hinh.h"
//#include "mylib.h"
using namespace std;

struct DocGia{
	int MADG,gioitinh,trangthai;
	string ho,ten;
};
typedef struct DocGia DOC_GIA;

struct NodeDG{
	DOC_GIA data;
	struct NodeDG *pLeft;
	struct NodeDG *pRight;
	//LIST_MT dsmt;
};

typedef struct NodeDG NODE_DG;
typedef NODE_DG* TREE_DG;

//Ap dung duyet theo thu tu Inoder de cac phan tu trong mang theo thu tu tang dan(LNR)
void Create_ArrMADG(NODE_DG tree, int* arr);

//// ham xuat thong tin DG 
//int Output_ListDG(TREE_DG &t, LIST_TEMPLIST &l, DOC_GIA &dg, int &tttrang);

void Menu_DocGia(NODE_DG &tree);

//===========================================
void Create_ArrMADG(TREE_DG tree, int* arr){
	if(tree == NULL){
		return;
	}
	Create_ArrMADG(tree->pLeft,arr); //VISIT LEFT SUBTREE
	arr[index++] = tree->data.MADG;
	Create_ArrMADG(tree->pRight,arr);//VISIT RIGHT SUBTREE
}
//===========================================

//============================================
void Menu_DocGia(TREE_DG &tree){
	system("color CE");
	clrscr();
	//normalBGColor();
	int tttrang = 1 ;
	int esc = 1;
	clrscr();
	gotoxy(26, 1);
	cout << "CAP NHAT DOC GIA ";

	gotoxy(3, yHotkey );
	SetColor(WHITE);
	cout << "ESC-Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
	normalBGColor();
	do
	{
		DOC_GIA data;
		
		index = 0;
		int* arrMADG = new int[nDG];
		DisplayDG(keyDisplayDG, 5, xDisplayDG);
		Create_ArrMADG(tree,arrMADG);
//		esc = 
		
	}while(true);
}
//============================================
