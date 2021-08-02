#pragma once
#include <sstream>
#include "Marcro.h"
#include "ve_hinh.h"
#include "GlobalVariable.h"
#include "Cac_Ham_Nhap.h"
#include "Ngay_Thang.h"
//-------------------DANH MUC SACH-----------------------
struct DanhMucSach{
	string masach;
	int trangthaisach;
	string vitrisach;
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

// Phep toan Empty
int Empty_DauSach(LIST_DAUSACH list);

//PHEP TOAN FULL
int Full_DauSach(LIST_DAUSACH list);


// ............... HAM HO TRO CAP NHAT DOC GIA...................................
void Update_DauSach(LIST_DAUSACH &lDS, pDAU_SACH &pDS, bool isEdited = false);

int ChonCacSach_DS(LIST_DAUSACH &lDS, int &thututrang, int tongtrang);

void Xoa_OutDS_1line(int locate);

void Xoa_OutDS_29lines();

void Xuat_DS(dauSach ds);

void XuatDS_TheoTrang(LIST_DAUSACH &lDS, int index);

void Xuat_ListDStheoTT(LIST_DAUSACH lDS);

//.....................LOAI BO KHOANG TRANG.........................
string getString(string a);

//TIM KIEM THONG TIN DAU SACH THE TEN DAU SACH, CO TRA VE CON CO CHI NUT TIM THAY,KHONG TRA VE NULL
pDAU_SACH TimTen_DS(LIST_DAUSACH lDS, string tensach);

//THEM MOT PHAN TU VAO TRONG DAU SACH
int Insert_DauSach(LIST_DAUSACH &list,pDAU_SACH &pDS);


int InsertOrder_DauSach(LIST_DAUSACH &list, pDAU_SACH &pDS);


void Swap_DS(pDAU_SACH ds1, pDAU_SACH ds2);

bool KiemTraDauSach(pDAU_SACH p1,pDAU_SACH p2);

void Delete_DauSach(LIST_DAUSACH &l, int pos);

// .................. VI DAU SACH TOI DA 100 PHAN TU NEN SU DUNG SELECTION SORT ...........................
void selectionSort_DS(LIST_DAUSACH &lDS);



//..................QUAN LI MENU DAU SACH.........................................
void Menu_DauSach(LIST_DAUSACH &lDS);

bool SearchISBN_DS(LIST_DAUSACH lDS, string ISBN);


//===========================CAC HAM DANH MUC SACH================================
//==========QUAN LI MENU DANH MUC SACH==============
void Menu_DMS(LIST_DAUSACH &lDS);
//KHOI TAO
void initList_DMS(LIST_DMS &list);

NODE_DMS* GetNode_DMS(DMS data);
//HAM KIEM TRA SACH XEM CO AI MUON HAY CHUA, CO THI TRA VE TRUE, KHONG THI FALSE
bool Check_DMS(NODE_DMS* nDMS);

void AddTailList_DMS(LIST_DMS &list, DMS data);

void Output_ListDMS(pDAU_SACH &pDS);

void Output_ListDanhMucSach(pDAU_SACH &pDS);

void XuatDMS_TheoTrang(pDAU_SACH pDS, int index);

void XoaDMS_29lines();

void XoaDMS_1line(int locate);
//TONG SO SACH DUOC MUON CUA MOT DAU SACH
int TongSoSachDuocMuon(LIST_DMS dms);

void NhapDanhMucSach(pDAU_SACH &pDS, int sosach);

int NhapSach(pDAU_SACH &pDS);

//HAM DAU SACH
//======================================
int Empty_DauSach(LIST_DAUSACH list){
	return list.n == 0;
}
//======================================

//======================================
int Full_DauSach(LIST_DAUSACH list){
	return list.n == MAX_DAUSACH;
}
//======================================

//======================================
int Insert_DauSach(LIST_DAUSACH &list, pDAU_SACH &pDS){
	if(Full_DauSach(list)) return 0;
	
	list.ListDS[list.n++] = pDS;
	return 1;
}
//======================================

//======================================
int InsertOrder_DauSach(LIST_DAUSACH &list,pDAU_SACH &pDS){
	if(Full_DauSach(list)){
		return 0;
	} 
	int vitri = 0;
	while(vitri < list.n && KiemTraDauSach(pDS,list.ListDS[vitri])){
		vitri++;
	}
	if(vitri == list.n){
		list.ListDS[list.n] = pDS;
		list.n++;
		return 1;
	}
	list.n++;
	for (int i = list.n-1; i>=vitri;i--)
	{
		list.ListDS[i+1] = list.ListDS[i];
	}
	list.ListDS[vitri] = pDS;
	
	return 1; 
}
//======================================

//======================================
void Update_DauSach(LIST_DAUSACH &lDS,pDAU_SACH &pDS, bool isEdited){
	dauSach info;
	// hien con tro nhap
	ShowCur(true);
	//CAC FLAG DIEU KHIEN QUA TRINH CAP NHAT
	int ordinal = 0 ;
	bool isSave = false;
	bool isEscape = false;
	
	
	int nngang = (int)keyBangNhapDauSach[0].length();
	//CAC BIEN LUU TRU TAM THOI
	string tensach = "";
	string ISBN = "";
	string tacgia = "";
	string theloai = "";
	int sotrang = 0;
	int namxuatban = 0 ;
	
	CreateBox(X_NOTICE + 7, Y_NOTICE, "NOTICE:  ", 52);
	BangNhap(109, yHienThi, nngang, keyBangNhapDauSach, 14);
	BangHuongDan(109, yHienThi + 20, nngang, keyHuongDan2, 7);

	if (isEdited)
	{
		tensach = pDS->info.tensach;		
		ISBN = pDS->info.ISBN;
		tacgia = pDS->info.tacgia;
		theloai = pDS->info.theloai;
		sotrang = pDS->info.sotrang;
		namxuatban = pDS->info.namxuatban;

		gotoxy(111 + (nngang / 3), yHienThi + 3);
		cout << tensach;
		gotoxy(111 + (nngang / 3), yHienThi + 5);
		cout << ISBN;
		gotoxy(111 + (nngang / 3), yHienThi + 7);
		cout << tacgia;
		gotoxy(111 + (nngang / 3), yHienThi + 9);
		cout << theloai;
		gotoxy(111 + (nngang / 3), yHienThi + 11);
		cout << sotrang;
		gotoxy(111 + (nngang / 3), yHienThi + 13);
		cout << namxuatban;
	}

	while (true) {
		switch (ordinal)
		{
			case 0:
				gotoxy(111 + (nngang / 3), yHienThi + 3);
				NhapTenSach(tensach, ordinal, isSave, isEscape);
				break;
			case 1:
				gotoxy(111 + (nngang / 3), yHienThi + 5);
				NhapISBN(ISBN, ordinal, isSave, isEscape);
				break;
			case 2:
				gotoxy(111 + (nngang /3), yHienThi + 7);
				NhapTenTacGia(tacgia, ordinal, isSave, isEscape);
				break;
			case 3:
				gotoxy(111 + (nngang /3), yHienThi + 9);
				NhapTheLoaiSach(theloai, ordinal, isSave, isEscape);
				break;
			case 4:
				gotoxy(111 + (nngang /3), yHienThi + 11);
				NhapSoTrang(sotrang, ordinal, isSave, isEscape);
				break;
			case 5:
				gotoxy(111 + (nngang /3), yHienThi + 13);
				NhapNamXuatBan(namxuatban, ordinal, isSave, isEscape);
				break;
		}
		
		// CHECK SAVE

		if (isSave)
		{
			// CAP NHAT LAI FLAG
			isSave = false;

			// CHECK RONG
			if (tensach.length() == 0)
			{
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (ISBN.length() == 0)
			{
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
				else if (tacgia.length() == 0)
			{
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			else if (theloai.length() == 0)
			{
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";

				// quay lai va dien vao truong du lieu do
				ordinal = 3;
				continue;
			}
			else if (sotrang == 0)
			{
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				// quay lai va dien vao truong du lieu do
				ordinal = 4;
				continue;
			}	
			else if (namxuatban == 0)
			{
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!!";
				ordinal = 5;
				continue;
			} 
			else if(namxuatban > (int)LayNamHienTai()){
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout <<"NAM XUAT BAN KHONG LON HON NAM HIEN TAI !!!";
				ordinal = 5;
				continue;
			}
			
			if(SearchISBN_DS(lDS,ISBN)){
				if(pDS->info.ISBN != ISBN){
					gotoxy(X_NOTICE + 15, Y_NOTICE);
					cout << "ISBN VUA NHAP VAO TRUNG VOI ISBN DA CO";
					
					//QUAY LAI VA DIEN VAO TRG DU LIEU DA CO
					ordinal = 1;
					continue;
				}
			}
			//IMPORT DATA VAO INFO
			info.tensach = ChuanHoaString(tensach);
			info.ISBN = ChuanHoaString(ISBN);
			info.tacgia = ChuanHoaString(tacgia);
			info.theloai= ChuanHoaString(theloai);
			info.sotrang = sotrang;
			info.namxuatban = namxuatban;
			
			if(isEdited){
				pDS->info = info;
				return;
			}
			else{
				//GAN NULL CHO CON TRO TRONG DANH SACH
				initList_DMS(pDS->dms);
				
				pDS->info = info;
				
				int temp = InsertOrder_DauSach(lDS,pDS);
				if(temp == 0){
					// THONG BAO RA
					for (int i = 0; i < 5; i++)
					{
						gotoxy(X_NOTICE + 15, Y_NOTICE);
						Sleep(100);
						cout << "BO NHO DA DAY .KHONG THEM DAU SACH MOI VAO DUOC !";

					}
				}
				else {
					// IN DONG THONG BAO
					for (int i = 0; i < 5; i++)
					{
						gotoxy(X_NOTICE + 15, Y_NOTICE);
						Sleep(100);
						cout << "  LUU THANH CONG !!! ";

					}
				}
				return;
			}
		}
		// THOAT	
		if (isEscape)
		{
			return;
		}
		
	}
	ShowCur(false);
}
//======================================

//======================================
void Swap_DS(pDAU_SACH ds1,pDAU_SACH ds2){
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

void Delete_DauSach(LIST_DAUSACH &list, int pos)
{
	if(pos > list.n-1 || Empty_DauSach(list)){
		return;
	}
	//XOA VI TRI CUOI MANG
	if(pos == list.n-1){
		delete list.ListDS[list.n-1];
		//TRANH TINH TRANG CON TRO BI TREO
		list.ListDS[list.n - 1] = NULL;
		list.n = list.n-1;
		return;
	}
	// CHO NAY QUAN TRONG
	delete list.ListDS[pos];
	
	for (int temp = pos + 1;temp < list.n ; temp++)
	{
		list.ListDS[temp - 1] = list.ListDS[temp];
	}
	delete list.ListDS[list.n-1];
	
	//TRANH TINH TRANG CON TRO BI TREO
	list.ListDS[list.n-1] = NULL;
	list.n = list.n-1;
	return;
}

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
			Swap_DS(lDS.ListDS[min_idx],lDS.ListDS[i]);
		}
    }
	
}
//======================================


//======================================
void Xoa_OutDS_1line(int locate){
	gotoxy(xKhungHienThiDS[0] + 1, yHienThi + 3 + locate);
	cout << setw(27) << setfill(' ') << ' ';
	gotoxy(xKhungHienThiDS[1] + 1, yHienThi + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
	gotoxy(xKhungHienThiDS[2] + 1, yHienThi + 3 + locate);
	cout << setw(18) << setfill(' ') << ' ';
	gotoxy(xKhungHienThiDS[3] + 1, yHienThi + 3 + locate);
	cout << setw(11) << setfill(' ') << ' ';
	gotoxy(xKhungHienThiDS[4] + 1, yHienThi + 3 + locate);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(xKhungHienThiDS[5] + 1, yHienThi + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
}
//======================================

//======================================
void Xoa_OutDS_29lines(){
	for (int i = 0;i < NUMBER_LINES;i++){
		Xoa_OutDS_1line(i);
	}
}
//======================================

//======================================
void Xuat_DS(dauSach ds){
	ShowCur(false);
	Xoa_OutDS_1line(locate);
	gotoxy(xKhungHienThiDS[0] + 3, yHienThi + 3 + locate);
	cout << ds.tensach;
	gotoxy(xKhungHienThiDS[1] + 3, yHienThi + 3 + locate);
	cout << ds.ISBN;
	gotoxy(xKhungHienThiDS[2] + 3, yHienThi + 3 + locate);
	cout << ds.tacgia;
	gotoxy(xKhungHienThiDS[3] + 3, yHienThi + 3 + locate);
	cout << ds.theloai;

	gotoxy(xKhungHienThiDS[4] + 3, yHienThi + 3 + locate);
	cout << ds.sotrang;
	gotoxy(xKhungHienThiDS[5] + 3, yHienThi + 3 + locate);
	cout << ds.namxuatban;
	
	locate++;
}
//======================================

//=======================================
void XuatDS_TheoTrang(LIST_DAUSACH &lDS, int index){
	Xoa_OutDS_29lines();
	locate = 0 ;
	index--;
	if(lDS.n == 0){
		return;
	}
	for (int i = NUMBER_LINES * index ; i< NUMBER_LINES*(1 + index) && i < lDS.n ; i++){
		Xuat_DS(lDS.ListDS[i]->info);
	}
	
}
//=======================================

//=======================================
int ChonCacSach_DS(LIST_DAUSACH &lDS, int &thututrang, int tongtrang){
	int pos = 0;
	int kb_hit;
	
	gotoxy(xKhungHienThiDS[0] + 1, yHienThi + 3 + pos);
	cout<< "<";
	gotoxy(xKhungHienThiDS[0] + 27, yHienThi + 3 +pos);
	cout<< ">";
	while(true)
	{
		if(_kbhit()){
			kb_hit = _getch();
			if(kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			
			switch(kb_hit){
				case KEY_UP:
					//XOA MUC TRUOC
					gotoxy(xKhungHienThiDS[0] + 1, yHienThi + 3 + pos);
					cout << "  ";
					gotoxy(xKhungHienThiDS[0] + 27, yHienThi + 3 + pos);
					cout << "  ";
					
					(pos > 0) ? pos-- : pos = 28;
						
					//TO MAU MUC MOI
					gotoxy(xKhungHienThiDS[0] + 1, yHienThi + 3 + pos);
					cout << "<";
					gotoxy(xKhungHienThiDS[0] + 27, yHienThi + 3 + pos);
					cout << ">";
					break;
				case KEY_DOWN:
					// XOA MUC TRUOC
					gotoxy(xKhungHienThiDS[0] + 1, yHienThi + 3 + pos);
					cout << "  ";
					gotoxy(xKhungHienThiDS[0] + 27, yHienThi + 3 + pos);
					cout << "  ";
					(pos < 28) ? pos++ : pos = 0;
					
					// TO MAU MUC MOI
					gotoxy(xKhungHienThiDS[0] + 1, yHienThi + 3 + pos);
					cout << "<";
					gotoxy(xKhungHienThiDS[0] + 27, yHienThi + 3 + pos);
					cout << ">";
					break;
				case PAGE_UP:
					if(thututrang > 1)
					{
						thututrang--;
					}
					else
					{
						thututrang = tongtrang;
					}
					Xoa_OutDS_29lines();
					XuatDS_TheoTrang(lDS, thututrang);
					pos = 0;
					gotoxy(xKhungHienThiDS[0] + 1, yHienThi + 3 + pos);
					cout << "<";
					gotoxy(xKhungHienThiDS[0] + 27, yHienThi + 3 + pos);
					cout << ">";
					break;
				case ENTER:
					return (pos == 0 && thututrang == 1)? pos : pos + (thututrang - 1)* NUMBER_LINES;
			}	
		}
		gotoxy(33, 36);
		cout << "Trang " << thututrang << " / " << tongtrang;
	}
}
//=======================================

//=======================================
void Xuat_ListDStheoTT(LIST_DAUSACH lDS){
	system("color 0E");
	clrscr();
	
	selectionSort_DS(lDS);
label:
	KhungHienThiDS(keyKhungHienThiDS, 6 ,xKhungHienThiDS);
	gotoxy(10, 1);
	cout << "BANG THONG TIN CAC DAU SACH THEO THU TU THE LOAI VA TEN SACH TANG DAN";
	int nDS = lDS.n;
	int thututrang, tongtrang;
	thututrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	XuatDS_TheoTrang(lDS, thututrang);
	
	int check;
	pDAU_SACH temp;
	string tensach ="";
	
	int kb_hit;
	do
	{
		if(_kbhit()){
			kb_hit = getch();
			if (kb_hit == 224 || kb_hit == 0){
				kb_hit = _getch();
			} 
			switch(kb_hit){
				case PAGE_UP:
					(thututrang > 1) ? thututrang-- : thututrang = tongtrang;
					XuatDS_TheoTrang(lDS, thututrang);
					break;

				case PAGE_DOWN:
					(thututrang <  tongtrang) ? thututrang++ : thututrang = 1;
					XuatDS_TheoTrang(lDS, thututrang);
					break;
				case KEY_F9:
					VeHinhBangNhap(109, 3,50, "         HAY NHAP VAO TEN SACH CAN TRA CUU");		
					gotoxy(119, 5);
					check = NhapTenSachTimKiem(tensach);
					//KIEM TRA DIEU KIEN TRA VE
					if(check == -1){
						gotoxy(119, 10);
						cout << "BAN VUA HUY TAC VU TRA CUU !!!";
						_getch();
						return;
					}
					else if( check == 1)
					{
						tensach = ChuanHoaString(tensach);
						temp = TimTen_DS(lDS, tensach);
						if( temp == NULL){
							gotoxy(113, 10);
							cout << "TEN SACH VUA NHAP KHONG CO TRONG THU VIEN !!!";
							_getch();
							XoaMotVung(109, 1, 35, 50);
						}
						else
						{
							Output_ListDanhMucSach(temp);
							clrscr();
							goto label;
						}
					}
					break;
				// thoat
				case ESC:
					return ;
								
			}
		}
		ShowCur(false);
		gotoxy(2, 35);
		cout << "HotKey: PgUp, PgDn, ESC,      F9  -  TIM THONG TIN SACH ";
		gotoxy(68, 35);
		cout << "Trang " << thututrang << " / " << tongtrang;
	}while(true);
}
//=======================================

//=======================================1
void Menu_DauSach(LIST_DAUSACH &lDS){
	clrscr();
	system("color 0E");
	selectionSort_DS(lDS);
label1:	
	SetColor(WHITE);
	gotoxy(35, 1);
	cout << "CAP NHAT DAU SACH "; 
	//nDS la so DS hien co trong danh sach tuyen tinh
	int nDS = lDS.n;
	int choose;
	pDAU_SACH pDS;
	
	gotoxy(3, yHotkey);
	cout << "HOTKEY:  ESC - Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";

	// thu tu trang
	int thututrang, tongtrang;
	thututrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	
	XoaMotVung(109,yHienThi, 30 , 53);
	KhungHienThiDS(keyKhungHienThiDS,6,xKhungHienThiDS);
	XuatDS_TheoTrang(lDS, thututrang);
	int kb_hit;
	do{
		if(_kbhit()){
			kb_hit = _getch();
			switch(kb_hit){
				case PAGE_UP:
					(thututrang > 1) ? thututrang-- : thututrang = tongtrang;
					XuatDS_TheoTrang(lDS,thututrang);
					break;
				case PAGE_DOWN:
					(thututrang < tongtrang) ? thututrang++ : thututrang = 1;
					XuatDS_TheoTrang(lDS,thututrang);	
					break;
				case KEY_F2:
					pDS = new DAU_SACH;
					if(pDS == NULL){
						goto label1;
					}
					Update_DauSach(lDS,pDS,false);
					goto label1;
				case KEY_F3:
					choose = ChonCacSach_DS(lDS, thututrang, tongtrang);
					if(choose > lDS.n){
						goto label1;
					}
					Update_DauSach(lDS, lDS.ListDS[choose], true);
					goto label1;
				case KEY_F4:
					choose = ChonCacSach_DS(lDS, thututrang, tongtrang);
					if(choose > lDS.n) goto label1;
					
					//NEU CO NGUOI MUON THI KHONG DUOC PHEP XOA
					if(Check_DMS(lDS.ListDS[choose]->dms.pHead)){
						gotoxy(109,20);
						cout << " DAU SACH DA CO DOC GIA MUON NEN KHONG DUOC PHEP XOA !";
						_getch();
						gotoxy(109, 20);
						cout << "                                                      ";	
						goto label1;
					}
					Delete_DauSach(lDS, choose);
					goto label1;
				case ESC:
					return;
					
			}
		}
		gotoxy(33, 36);
		cout << "Trang " << thututrang << " / " << tongtrang;
	}while(true);
}
//=======================================1




//TIM KIEM TUYEN TINH
//=======================================
bool SearchISBN_DS(LIST_DAUSACH lDS,string ISBN){
	for (int i = 0;i <lDS.n;i++){
		if(lDS.ListDS[i]->info.ISBN == ISBN){
			return true;
		}
	}
	return false;
}
pDAU_SACH TimTen_DS(LIST_DAUSACH lDS, string tensach){
	pDAU_SACH temp = NULL;
	for(int i = 0; i< lDS.n;i++){
		temp = lDS.ListDS[i];
		if( temp->info.tensach == tensach){
			return temp;
		}
	}
	return NULL;
}
//=======================================



//HAM DANH MUC SACH
void Menu_DMS(LIST_DAUSACH &lDS)
{
	system("color 0E");
	int choose;
	int nDS = lDS.n;
	int thututrang = 1;
	int tongtrang =(nDS /NUMBER_LINES) + 1;
	int temp = 1;
	
	do
	{
		clrscr();
		
		//HIEN THI BANG CHUA THONG TIN DAU SACH
		KhungHienThiDS(keyKhungHienThiDS, 6, xKhungHienThiDS);
		XuatDS_TheoTrang(lDS, thututrang);
		
		gotoxy(23, 1);
		cout << "CHON DAU SACH DE CAP NHAT DANH MUC SACH";
		
		//CHON DAU SACH MUON NHAP VAO
		choose = ChonCacSach_DS(lDS, thututrang, tongtrang);
		
		//CHECK CAC TRUONG HOP
		if(choose == -1) return;
		else if(choose > lDS.n)
		{
			
			gotoxy(2, yHienThi + 3 + choose % NUMBER_LINES);
			cout << setw(27) << setfill(' ')<< ' ';
			continue;
		}
		if(lDS.ListDS[choose]->dms.pHead != NULL && lDS.ListDS[choose]->dms.n == -1) continue;
		
		//CHON SO SACH NHAP
		int sosach = ChonSoSachNhap();
		if (sosach == -1)
		{
			XoaMotVung(81,3,20,50);
			continue;
		}
		else
		{
			// BAT DAU NHAP THONG TIN SACH
			NhapDanhMucSach(lDS.ListDS[choose], sosach);
		}
	}while(true);
}

//KHOI TAO
//=======================================
void initList_DMS(LIST_DMS &list){
	list.n = 0;
	list.pHead = list.pTail = NULL;
}
//=======================================

//=======================================
NODE_DMS* GetNode_DMS(DMS data){
	NODE_DMS *p = new NODE_DMS;
	if(p == NULL){
		return NULL;
	}
	p->data = data;
	p->pNext = NULL;
	
	return p;
}
//=======================================

//=======================================
bool Check_DMS(NODE_DMS* nDMS){
	for (NODE_DMS* p = nDMS; p !=NULL ; p = p->pNext)
	{
		//SACH DA CO NGUOI MUON
		if(p->data.trangthaisach == 1){
			return true;
		}
	}
	return false;
}
//=======================================

//=======================================
void Output_ListDanhMucSach(pDAU_SACH &pDS){
	// THU TU TRANG

	clrscr();
	
	gotoxy(93, 8);
	cout << "THONG TIN TRA CUU DUOC !";
	gotoxy(82, 10);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 12);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 14);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 16);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 18);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 20);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 22);
	cout << setw(50) << setfill('-') << "-";
	gotoxy(82, 24);
	cout << setw(50) << setfill('-') << "-";
//	normalBGColor();
	gotoxy(82, 11);
	cout << "TEN SACH: " << pDS->info.tensach;
	gotoxy(82, 13);
	cout << "TAC GIA: " << pDS->info.tacgia;
	gotoxy(82, 15);
	cout << "THE LOAI: " << pDS->info.theloai;
	gotoxy(82, 17);
	cout << "NAM XUAT BAN: " << pDS->info.namxuatban;
	gotoxy(82, 19);
	cout << "ISBN: " << pDS->info.ISBN;
	gotoxy(82 ,21);
	cout << "TONG SO SACH CUA DAU SACH: " << pDS->dms.n;
	gotoxy(82, 23); 
	cout << "SO SACH CON TRONG THU VIEN:  " << pDS->dms.n - TongSoSachDuocMuon(pDS->dms);
	
	int thututrang = 1;
	int tongtrang = ((pDS->dms.n + 1) / NUMBER_LINES ) + 1;
	gotoxy(8, 1);
	cout << " BANG DANH MUC SACH CUA DAU SACH : " << pDS->info.tensach;
	
	int kb_hit;	
	do
	{
	//	XoaMotVung(65,2,  30, 67);
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit)
			{
			case PAGE_UP:
				(thututrang > 1) ? thututrang-- : thututrang = tongtrang;
			//	OutputDMS_PerPage(pDS, tttrang);
				break;

			case PAGE_DOWN:
				(thututrang <  tongtrang) ? thututrang++ : thututrang = 1;
			//	OutputDMS_PerPage(pDS, tttrang);
				break;
			case ESC:
				return;
			}
		}
		ShowCur(false);
		gotoxy(54, 35);
		cout << "Trang " << thututrang << " / " << tongtrang;

	} while (true);

}
//=======================================

//=======================================
int TongSoSachDuocMuon(LIST_DMS dms){
	int dem = 0;
	NODE_DMS *temp = NULL;
	for (temp = dms.pHead; temp !=NULL;temp=temp->pNext){
		//TINH CA SACH DA MUON VA DA MUON NHUNG LAM MAT
		if(temp->data.trangthaisach == 1 || temp->data.trangthaisach == 2){
			dem++;
		}
	}
	return dem;
}
//=======================================

//=======================================
void AddTailList_DMS(LIST_DMS &list, DMS data)
{
	//TAO NODE
	NODE_DMS *p = GetNode_DMS(data);
	if(list.pHead == NULL){
		list.pHead = list.pTail = p;
	}
	else
	{
		list.pTail->pNext = p;
		list.pTail = p;
	}
	list.n++;
}
//=======================================

//=======================================
void NhapDanhMucSach(pDAU_SACH &pDS, int sosach)
{
	clrscr();
	system("color 0E");
	int check = 0 ;
	SetColor(WHITE);
	gotoxy(39, 2);
	cout << "BAN DANG NHAP THONG TIN VAO DANH MUC SACH CUA DAU SACH : " << pDS->info.tensach;
	gotoxy(60, 16);
	cout << "SO SACH CAN NHAP: " << sosach << endl;
	gotoxy(52, 31);
	cout << " HotKey:   F10 - Luu ,  ESC - Thoat ";
	
	//NHAP SACH THEO SO SACH DA CHO TRUOC
	for (int i =0 ; i < sosach && check != -1;i++)
	{
		//NHAP SACH
		check = NhapSach(pDS);
		
		XoaMotVung(38, yHienThi + 2, 10, (int)keyBangNhapDanhMucSach[0].length());
		
		gotoxy(60, 18);
		cout << "SO SACH DA NHAP : " << i + 1;		
	}
	
	Output_ListDMS(pDS);
}
//=======================================

//=======================================
int NhapSach(pDAU_SACH &pDS)
{
	DMS info;
	
	//HIEN CON TRO NHAP
	ShowCur(true);
	
	int nngang = (int)keyBangNhapDanhMucSach[0].length();
	SetColor(WHITE);
	CreateBox(40, Y_NOTICE + 2, "NOTICE: ",66);
	BangNhap(38, yHienThi + 2, nngang, keyBangNhapDanhMucSach, 8);
	BangHuongDan(38, yHienThi + 22, nngang, keyHuongDan3, 4);
	
	// CAC FLAG DIEU KHIEN QUA TRINH CAP NHAT
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;
	
	int stt = pDS->dms.n + 1;
	stringstream ss;
	ss <<stt;
	
	string masach = pDS->info.ISBN + ss.str();
	
	int trangthaisach = 3;
	gotoxy(40 + (nngang / 3), yHienThi + 5);
	cout << masach;
	
	while(true)
	{
		switch(ordinal)
		{
			case 1:
				NhapTrangThaiSach(trangthaisach, ordinal, isSave, isEscape, 40 + (nngang / 3), yHienThi + 7);
				break;
			case 2:
				NhapViTriSach(vitrisach, ordinal, isSave, isEscape, 40 + (nngang / 3), yHienThi + 9);
				break;
		}
		if(isSave)
		{
			//CAP NHAT LAI FLAG
			isSave = false;
			
			//CHECK RONG;
			if(trangthaisach == 3)
			{
				gotoxy(55, Y_NOTICE + 2);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				
				//QUAY LAI VA DIEN VAO TRUONG DU LIEU DO
				ordinal = 1;
				continue;
			}
			if(vitrisach.length() == 0)
			{
				gotoxy(55, Y_NOTICE + 2);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				
				//QUAY LAI VA DIEN VAO TRUONG DU LIEU DO
				ordinal = 2;
				continue;
			}
			
			//IMPORT DATA VAO INFO
			info.masach = masach;
			info.trangthaisach = trangthaisach;
			info.vitrisach = vitrisach;
			
			AddTailList_DMS(pDS->dms, info);
			return 0 ;
		}
		if (isEscape)
		{
			return -1;
		}
	}
}
//=======================================

//=======================================
void Output_ListDMS(pDAU_SACH &pDS)
{
	//THU TU TRANG
	clrscr();
	int check1;
	int check2;
	int check3;
	int trangthaisach, tongtrang;
	trangthaisach = 1;
	tongtrang = ((pDS->dms.n + 1) / NUMBER_LINES) + 1;
	NODE_DMS* temp = NULL, *temp1 = NULL;
	gotoxy(8,1);
	cout<< " BANG DANH MUC SACH CUA DAU SACH : " << pDS->info.tensach;

label:
	KhungHienThiDMS(keyKhungHienThiDMS, 3, xKhungHienThiDMS);
//	XuatDMS_TheoTrang(pDS, thututrang);
	
}
//=======================================

//=======================================
void XuatDMS_TheoTrang(pDAU_SACH pDS, int index)
{
	
}
//=======================================
