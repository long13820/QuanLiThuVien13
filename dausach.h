#pragma once
#include <iostream>
#include "Marcro.h"
#include "ve_hinh.h"

//-------------------DANH MUC SACH-----------------------
struct DanhMucSach{
	string maSach;
	int ttSach;
	string viTriSach;
};
typedef struct DanhMucSach DMS;

struct NodeDMS{
	DMS data;
	struct NodeDMS* pNext;
};
typedef struct NodeDMS NODE_DMS;

struct ListDMS{
	int n = 0 ;
	NODE_DMS *pHead, *pTail;
};
typedef struct ListDMS LIST_DMS;

//----------------------DAU SACH-------------------------
struct dausach{
	string tensach;
	string ISBN;
	string tacgia;
	string theloai;
	int sotrang;
	int namxuatban;
};
typedef struct dausach dauSach;

struct DauSach{
	dauSach info;
	LIST_DMS dms;
	int soluongsachdamuon = 0;
}; 
typedef struct DauSach DAU_SACH;
typedef struct DauSach* pDAU_SACH;


struct ListDauSach{
	// n + 1  = so phan tu , n = chi so index
	int n = 0 ;
	 
	// mang con tro dung cap phat dong, vung nho heap
	//pDAU_SACH *ListDS = new pDAU_SACH[MAX_DAUSACH];

	// vi so luong dau sach chi co 100 nen dung mang cap phat tinh luon, vung nho stack
	
	pDAU_SACH ListDS[MAX_DAUSACH];
	
};
typedef struct ListDauSach LIST_DAUSACH;

void Xoa_OutDMS_1lines(int locate);
void Xoa_OutDMS_29lines();

void XuatDS_TheoTrang(LIST_DAUSACH &lDS, int index);

//..................quan ly menu dau sach.........................................
void Menu_DauSach(LIST_DAUSACH &lDS);


//======================================
void Xoa_OutDMS_1lines(int locate){
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + locate);
	cout << setw(27) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[2] + 1, yDisplay + 3 + locate);
	cout << setw(18) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] + 1, yDisplay + 3 + locate);
	cout << setw(11) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[4] + 1, yDisplay + 3 + locate);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[5] + 1, yDisplay + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
}
//======================================

//======================================
void Xoa_OutDMS_29lines(){
	for (int i = 0;i < NUMBER_LINES;i++){
		Xoa_OutDMS_1lines(i);
	}
}
//======================================

//=======================================
void XuatDS_TheoTrang(LIST_DAUSACH &lDS, int index){
	
}
//=======================================


//=======================================
void Menu_DauSach(LIST_DAUSACH &lDS){
	system("color CE");
	clrscr();
	gotoxy(35, 1);
	cout << "CAP NHAT DAU SACH ";
	
	//nDG la so DG hien co trong danh sach tuyen tinh
	int nDS = lDS.n;
	int choose;
	pDAU_SACH pDS;
	
	gotoxy(3, yHotkey);
	SetColor(WHITE);
	cout << "HotKey:  ESC - Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
	normalBGColor();
	
	// thu tu trang
	int thututrang, tongtrang;
	thututrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	
	
	
label1:
	
	DisplayDS(keyDisplayDS,6,xDisplayDS);
	XuatDS_TheoTrang(lDS, thututrang);
	int kb_hit;
	do{
		if(_kbhit()){
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0){
				kb_hit = _getch();
			}
			switch(kb_hit){
				case PAGE_UP:
					(thututrang > 1) ? thututrang-- : thututrang = tongtrang;
					XuatDS_TheoTrang(lDS,thututrang);
					break;
				case PAGE_DOWN:
					(thututrang < tongtrang) ? thututrang++ : thututrang = 1;	
					break;
				case KEY_F2:
					pDS = new DAU_SACH;
					if(pDS == NULL){
						goto label1;
					}
					goto label1;
				case KEY_F3:
					 goto label1;
				case ESC:
					return;
					
			}
		}
	}while(true);
}
//=======================================


