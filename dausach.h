#pragma once
#include <sstream>
#include "Marcro.h"
#include "ve_hinh.h"
#include "GlobalVariable.h"
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

// ............... HAM HO TRO CAP NHAT DOC GIA...................................
void Update_DauSach(LIST_DAUSACH &lDS, pDAU_SACH &pDS, bool isEdited = false);

//.....................LOAI BO KHOANG TRANG.........................
string getString(string a);

void swap_DS(pDAU_SACH ds1, pDAU_SACH ds2);

bool KiemTraDauSach(pDAU_SACH p1,pDAU_SACH p2);


void Output_ListDStheoTT(LIST_DAUSACH lDS);

// .................. VI DAU SACH TOI DA 100 PHAN TU NEN SU DUNG SELECTION SORT ...........................
void selectionSort_DS(LIST_DAUSACH &lDS);

void XuatDS_TheoTrang(LIST_DAUSACH &lDS, int index);


//..................QUAN LI MENU DAU SACH.........................................
void Menu_DauSach(LIST_DAUSACH &lDS);

//======================================
void Update_DauSach(LIST_DAUSACH &lDS,pDAU_SACH &pDS, bool isEdited){
	DAU_SACH info;
	
	//CAC FLAG DIEU KHIEN QUA TRINH CAP NHAT
	int orginal = 0 ;
	bool isSave = false;
	bool isEscape = false;
	
	//CAC BIEN LUU TRU TAM THOI
	string tensach = "";
	string ISBN = "";
	string tacgia = "";
	string theloai = "";
	int sotrang = 0;
	int namxuatban = 0 ;
	
	CreateBox(X_NOTICE + 13, Y_NOTICE, "NOTICE: ", 52);
	
	
	
}
//======================================

//======================================
void swap_DS(pDAU_SACH ds1,pDAU_SACH ds2){
	DAU_SACH temp = *ds1;
	*ds1 = *ds2;
	*ds2 = temp;
}
//======================================

//======================================
string getString(string a){
	for (int i = 0 ;i < (int)a.length();i++){
		if(a[i]==' '){
			a.erase(i,1);
			i--;
		}
	}
	return a;
	
}
//======================================

//======================================
bool KiemTraDauSach(pDAU_SACH p1,pDAU_SACH p2){
	string temp1 = getString(p1->info.theloai);
	string temp2 = getString(p2->info.theloai);
	
	if(temp1 > temp2){
		return true;
	}
	return false;
	string temp3 = getString(p1->info.tensach);
	string temp4 = getString(p2->info.tensach);
	
	if(temp3 > temp4){
		return true;
	}
	return false;
	
}
//======================================

//======================================
void selectionSort_DS(LIST_DAUSACH &lDS){
	int i, j, min_idx;
	string temp1, temp2, temp3,temp4;
	// DI CHUYEN RANH GIOI CUA MANG DA SAP XEP VA CHUA SAP XEP
    for (i = 0; i < lDS.n - 1; i++)
    {
    	//TIM PHAN TU NHO NHAT TRONG MANG CHUA SAP XEP
    	min_idx = i;
    	for (j = i + 1; j < lDS.n; j++){
    		if(KiemTraDauSach(lDS.ListDS[min_idx],lDS.ListDS[j])){
    			min_idx = j;
			}
		}
		
		//DOI CHO PHAN TU NHO NHAT VOI PHAN TU DAU TIEN
		if(min_idx != i){
			swap_DS(lDS.ListDS[min_idx],lDS.ListDS[i]);
		}
    }
	
}
//======================================


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
void Output_ListDStheoTT(LIST_DAUSACH lDS){
	system("color CE");
	clrscr();
	
	selectionSort_DS(lDS);
}
//=======================================

//=======================================
void Menu_DauSach(LIST_DAUSACH &lDS){
	
	selectionSort_DS(lDS);
	
	system("color 0E");
	clrscr();
	gotoxy(35, 1);
	cout << "CAP NHAT DAU SACH ";
	
	//nDG la so DG hien co trong danh sach tuyen tinh
	int nDS = lDS.n;
	int choose;
	pDAU_SACH pDS;
	
	gotoxy(3, yHotkey);
	SetColor(WHITE);
	cout << "HOTKEY:  ESC - Thoat, INSERT - Them, F2 - Sua, DELETE - Xoa, F4 - Luu, PgUP, PgDn";

	// thu tu trang
	int thututrang, tongtrang;
	thututrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	
	
	
label1:
//	XoaMotVung(79,yDisplay, 30 , 53);
	DisplayDS(keyDisplayDS,6,xDisplayDS);
//	XuatDS_TheoTrang(lDS, thututrang);
//	int kb_hit;
	do{
//		if(_kbhit()){
//			kb_hit = _getch();
//			if (kb_hit == 224 || kb_hit == 0){
//				kb_hit = _getch();
//			}
//			switch(kb_hit){
//				case PAGE_UP:
//					(thututrang > 1) ? thututrang-- : thututrang = tongtrang;
//					XuatDS_TheoTrang(lDS,thututrang);
//					break;
//				case PAGE_DOWN:
//					(thututrang < tongtrang) ? thututrang++ : thututrang = 1;
//					XuatDS_TheoTrang(lDS,thututrang);	
//					break;
//				case KEY_INSERT:
//					pDS = new DAU_SACH;
//					if(pDS == NULL){
//						goto label1;
//					}
//					Update_DauSach(lDS,pDS,false);
//					goto label1;
//				case KEY_F2:
//					 goto label1;
//				case ESC:
//					return;
//					
//			}
//		}
		//	ShowCur(false);
		gotoxy(33, 36);
		cout << "Trang " << thututrang << " / " << tongtrang;
	}while(true);
}
//=======================================


