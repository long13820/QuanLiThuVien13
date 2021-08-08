#pragma once
#include <iostream>
#include "Marcro.h"
using namespace std;


// CAC HAM HO TRO NHAP
void NhapTenSach(string &tensach, int &ordinal, bool &isSave, bool &isEscape);
void NhapISBN(string &isbn, int &ordinal, bool &isSave, bool &isEscape);
void NhapTenTacGia(string &tentacgia, int &ordinal, bool &isSave, bool &isEscape);
void NhapTheLoaiSach(string &theloaisach, int &ordinal, bool &isSave, bool &isEscape);
void NhapSoTrang(int &sotrang, int &ordinal, bool &isSave, bool &isEscape);
void NhapNamXuatBan(int &namxuatban, int &ordinal, bool &isSave, bool &isEscape);
void NhapTrangThaiSach(int &trangthaisach, int &ordinal, bool &isSave, bool &isEscape, int a, int b);
void NhapViTriSach(string &vitrisach, int &ordinal, bool &isSave, bool &isEscape, int a, int b);
//LOAI BO KHOANG SPACE ' ' THUA TRONG STRING 
string ChuanHoaString(string result);

// HAM HO TRO NHAP TEN SACH TU BAN PHIM DE TRA CUU THONG TIN
int NhapTenSachTimKiem(string &result);

//NHAP SO LUONG SACH CAN NHAP VAO
int ChonSoSachNhap(int &trangthaisach, int &ordinal, bool &isSave, bool &isEscape, int a, int b);

//HAM HO TRO NHAP MA DAU SACH TRONG DANH MUC SACH
int NhapMaDauSach(string &result);

//==================================1
void NhapTenSach(string &tensach, int &ordinal, bool &isSave, bool &isEscape)
{
	ShowCur(true);
	// BIEN DEM SO CHU DA NHAP VAO RESULT
	cout << tensach;
	int count = (int)tensach.length();
	int x, y;
	// BIEN CO HIEU
	int nSpace = 0;
	while(true)
	{
	
		x = wherex() - 1;
		y = wherey() - 1;

		while(_kbhit())
		{
			int kb_hit = _getch();

			// CHI NHAN CHU THUONG HOAC CHU IN HOA VA DAU CACH VA SO
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) 
			|| (kb_hit >=  48 && kb_hit <= 57) || kb_hit == SPACE) && count < MAX_TENSACH && count >= 0)
			{

				//XOA DONG THONG BAO
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);

				if (tensach[count - 1] != ' ' && kb_hit == SPACE && count > 0)
				{
					count++;
					cout << (char)kb_hit;
					tensach += (char)kb_hit;
				//	nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					tensach += (char)kb_hit;
				//	nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 5;
					return;
				}
				else
				{
//					if(isEdited) 
//						ordinal = 2;
//					else
					ordinal = 1;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 1;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				tensach.erase(tensach.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "TOI DA 24 KY TU, GOM KY TU CHU VA SO !!!";
				gotoxy(x,y);

			}
		}
	
	}
}
//==================================1

//==================================2
void NhapISBN(string &isbn,int &ordinal, bool &isSave, bool &isEscape){
	// BIEN DEM SO CHU DA NHAP CHO VAO RESULT
	cout << isbn;
	int count = (int)isbn.length();
	int x, y;
	while(true){
		x = wherex() - 1;
		y = wherey() - 1;
		while(_kbhit())
		{
			int kb_hit = _getch();
			//CHI NHAN CHU THUONG HOAC CHU HOA
			//CHI NHAP TEN TOI DA 7 KI TU, DO TU DAI NHAT TV CHI LA 7
			if(((kb_hit >= 65 && kb_hit <= 90)||(kb_hit == 97 && kb_hit == 122) ||(kb_hit >=  48 && kb_hit <= 57)) && count < MAX_ISBN)
			{
				count++;
				
				//XOA DONG THONG BAO
				
				gotoxy(X_NOTICE + 15,Y_NOTICE);
				cout <<setw(42) <<setfill(' ')<<" ";
				gotoxy(x,y);
				
				//CHUYEN HOA IN HOA
				kb_hit = toupper((char)kb_hit);
				cout<< (char)kb_hit;
				isbn += (char)kb_hit;
			}
			else if(kb_hit == 224)
			{
				kb_hit = _getch();
				if(kb_hit == KEY_UP){
					ordinal = 0;
					return;
				}
				else{
					ordinal = 2;
					return;
				}
			}
			else if(kb_hit == ENTER) {
				ordinal = 2;
				return;
			}
			else if(kb_hit == BACKSPACE && count > 0 ){
				cout << "\b" << " "<<"\b";
				count--;
				isbn.erase(isbn.length() - 1 , 1);
			}
			else if(kb_hit == 0){
				kb_hit = _getch();
				if(kb_hit == KEY_F10){
					isSave = true;
					return;
				}
			}
			else if(kb_hit == ESC){
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "TOI DA 4 KY TU, CHI LAY KY TU CHU !!!";
				gotoxy(x, y);
			}

		}
	}
}

//==================================2

//==================================3
void NhapTenTacGia(string &tentacgia,int &ordinal,bool &isSave,bool &isEscape){
	ShowCur(true);
	//BIEN DEM SO CHU DA DC NHAP VAO RESULT
	cout<< tentacgia;
	int count = (int)tentacgia.length();
	int x,y;
	//BIEN CO HIEU
	int nSpace = 0;
	if(count > 0 && tentacgia[count-1] != ' ') nSpace = 1;
	while(true){
		x= wherex() - 1;
		y= wherey() - 1;
		while(_kbhit()){
			int kb_hit = _getch();
			//CHI NHAN CHU THUONG HOAC CHU IN HOA VA DAU CACH
			if(((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <=122) || kb_hit== SPACE)&& count < MAX_TENTG && count >= 0){
				//XOA DONG THONG BAO
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				
				if(nSpace == 1 && kb_hit == SPACE){
					count++;
					cout <<(char)kb_hit;
					tentacgia += (char)kb_hit;
					nSpace = 0;
				}
				else if(kb_hit != SPACE){
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					tentacgia += (char)kb_hit;
					nSpace = 1;
				}
								
			}
			else if(kb_hit == 224){
				kb_hit =_getch();
				if(kb_hit == KEY_UP){
					ordinal = 1;
					return;
				}
				else {
					ordinal = 3;
					return;
				}
			}
			else if(kb_hit == ENTER){
				ordinal = 3;
				return;
			}
			else if(kb_hit == BACKSPACE &&count >0){
				cout << "\b" << " "<< "\b";
				count--;
				tentacgia.erase(tentacgia.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "TOI DA 17 KY TU, CHI LAY KY TU CHU !!!";
				gotoxy(x, y);
			}
		}
	} 
}
//==================================3

//==================================4
void NhapTheLoaiSach(string &theloaisach, int &ordinal, bool &isSave, bool &isEscape)
{
	ShowCur(true);
	//BIEN DEM SO CHU DA DUOC NHAP VAO CHO RESULT
	cout << theloaisach;
	int count = (int)theloaisach.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;

	while (true)
	{

		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit())
		{
			int kb_hit = _getch();

			// chi nhan chu thuong hoac  chu in hoa va dau cach
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE) 
				&& count < MAX_THELOAISACH && count >= 0)
			{


				// xoa dong thong bao
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					theloaisach += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					theloaisach += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 2;
					return;
				}
				else
				{
					ordinal = 4;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 4;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				theloaisach.erase(theloaisach.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "TOI DA 11 KY TU, CHI LAY KY TU CHU !!!";
				gotoxy(x, y);
			}
		}

	}
}
//==================================4

//==================================5
void NhapSoTrang(int &sotrang, int &ordinal, bool &isSave, bool &isEscape){
	ShowCur(true);
	// DEM SO CHU SO
	int temp = sotrang;
	int count = 0;
	int x, y;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}

	if (count)
	{
		cout << sotrang;
	}
	while (true)
	{

		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit())
		{
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57 && count < 6)
			{

				// XOA DONG THONG BAO
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);


				int f = kb_hit - 48;
				cout << f;
				sotrang = sotrang * 10 + (f);
				count++;
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 3;
					return;
				}
				else
				{
					ordinal = 5;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 5;
				return;
			}
			else if (kb_hit == BACKSPACE && count >0)
			{
				cout << "\b" << " " << "\b";
				count--;
				sotrang /= 10;
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "CHI CHAP NHAN KY TU SO VA CHIEU DAI <= 6 ";
				gotoxy(x, y);
			}
		}
	}
}
//==================================5

//==================================6
void NhapNamXuatBan(int &namxuatban, int &ordinal, bool &isSave, bool &isEscape){
	// dem so chu so
	int temp = namxuatban;
	int count =  0;
	int x, y;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	 }
	if (count)
	{
		cout << namxuatban;
	}
	while (true)
	{
		x = wherex() - 1;
		y = wherey() - 1;
		while (_kbhit())
		{
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57 && count <= 3)
			{
				// xoa dong thong bao
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);


				int f = kb_hit - 48;
				cout << f;
				namxuatban = namxuatban * 10 + (f);
				count++;
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{

					ordinal = 4;
					return;
				}
				else
				{
					ordinal = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				
				ordinal = 0;
				return;
			}
			else if (kb_hit == BACKSPACE && count >0)
			{
				cout << "\b" << " " << "\b";
				count--;
				namxuatban /= 10;
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(X_NOTICE + 15, Y_NOTICE);
				cout << "CHI CHAP NHAN KY TU SO VA CHIEU DAI <= 4"; 
				gotoxy(x, y);
			}
		}
	}
}
//==================================6

//==================================7
string ChuanHoaString(string result){
//	for (int i = 1; i < result.length();i++){
//		if(result[0] == ' '){
//			result.erase(0, 1);
//		}
//		else if( result[i - 1] == ' '&& result[i] == ' '){
//			result.erase(i - 1 , 1);
//			i--;
//		}
//		else if(result[result.length() - 1] == ' '){
//			result.erase(result.length() - 1, 1);
//		}
//	}
 	// Xoa khoang trang cuoi chuoi
	if (result[result.length() - 1] == ' ')
	{
		result.erase(result.length() - 1, 1);
	}
	return result;
}
//==================================7


//==================================8
int NhapTenSachTimKiem(string &result){
	ShowCur(true);
	//BIEN DEM SO CHU DA DUOC NHAP VAO CHO RESULT
	cout << result;
	//BIEN CO HIEU
	int nSpace = 0;
	int count = (int)result.length();
	
	while(true){
		int kb_hit = _getch();
		// chi nhan chu thuong hoac  chu in hoa va dau cach va so
		if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)|| (kb_hit >= 48 && kb_hit <= 57) || kb_hit == SPACE) && count < 35 && count >= 0)
		{
			if (nSpace == 1 && kb_hit == SPACE)
			{
				count++;
				cout << (char)kb_hit;
				result += (char)kb_hit;
				nSpace = 0;
			}
			else if (kb_hit != SPACE)
			{
				count++;
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				result += (char)kb_hit;
				nSpace = 1;
			}
	
		}
			else if (kb_hit == ENTER)
			{
				return 1;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
		
			}
			else if (kb_hit == ESC)
			{
				return -1;
			}

	}
}
//==================================8

//==================================9
int ChonSoSachNhap()
{
	int soluong = 3;
	gotoxy(125, 5);
	cout << soluong;
	

	SetColor(WHITE);
	gotoxy(110, 3);
	cout << "SO LUONG SACH CAN NHAP HIEN TAI  ";
	gotoxy(103, 7);
	
	SetColor(WHITE);
	cout << "<- Left arrow (-)             ";
	SetColor(WHITE);
	cout << "(+) Right arrow ->";
	gotoxy(110, 9);
	while(true)
	{
		while(_kbhit())
		{
			int kb_hit = _getch();
			if(kb_hit == 224)
			{
				kb_hit = _getch();
				if(kb_hit == KEY_RIGHT)
				{
					soluong++;
//					gotoxy(104, 5);
//					cout << "                    ";
					SetColor(WHITE);
					gotoxy(125, 5);
					cout << soluong ;
				}
				else if (kb_hit == KEY_LEFT)
				{

					if (soluong >= 2)
					{
						soluong--;
//						gotoxy(104, 5);
//						cout << "                    ";
						SetColor(WHITE);
						gotoxy(125, 5);
						cout << soluong;
					}
				}
			}
			else if (kb_hit == ENTER)
			{
				return soluong;
			}
			else if (kb_hit == ESC)
			{
				return -1;
			}
		}
	}

}
//==================================9

//==================================10
void NhapTrangThaiSach(int &trangthaisach, int &ordinal, bool &isSave, bool &isEscape, int a, int b)
{
	gotoxy(a,b);
	ShowCur(true);
	int count = 0;
	
	int x = wherex() - 1 , y = wherey() - 1;
	if(trangthaisach == 3)
	{
		trangthaisach = 0;
		gotoxy(x,y);
		cout << trangthaisach << ": CHO MUON DUOC";
		
	}
	while(true)
	{
		while(_kbhit())
		{
			int kb_hit = getch();
			if((kb_hit == 48 || kb_hit == 49 || kb_hit == 50) && count < 1)
			{
				count++;
				trangthaisach = kb_hit - 48;
				//XOA DONG THONG BAO
				gotoxy(a - 7, Y_NOTICE + 2);
				cout<< setw(49) <<setfill(' ')<< " ";
				gotoxy(x, y);
				if(trangthaisach == 0) cout << trangthaisach <<":   CHO MUON DUOC ";
				else if(trangthaisach == 1) cout<< trangthaisach <<":   DA DUOC MUON  ";
				else if(trangthaisach == 2) cout<< trangthaisach <<":   DA THANH LY   ";
			}
			else if(kb_hit == 224)
			{
				kb_hit = _getch();
				if( kb_hit == KEY_UP)
				{
					ordinal = 2;
					return;
				}
				else
				{
					ordinal = 2;
					return;
				}
			}
			else if( kb_hit == BACKSPACE && count > 0)
			{
				gotoxy(x, y);
				trangthaisach = 3;
				cout << " " << setw(17) << setfill(' ') << " ";
				count--;
				// CHUYEN VE VI TRI BAN DAU
				gotoxy(x, y);
			}
			else if( kb_hit == 0)
			{
				kb_hit = _getch();
				if(kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if(kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(a - 7, Y_NOTICE + 2);
				cout << "BAN HAY NHAP 0, 1, 2, HOAC Backspace DE XOA !!!";
				gotoxy(x, y);
			}
		}
	}
}
//==================================10

//==================================11
void NhapViTriSach(string &vitrisach, int &ordinal, bool &isSave, bool &isEscape, int a, int b)
{
	gotoxy(a,b);
	ShowCur(true);
	//BIEN DEM SO CHU DA DUOC NHAP VAO CHO VI TRI SACH
	cout << vitrisach;
	int count =(int)vitrisach.length();
	int x, y;
	//BIEN CO HIEU
	int nSpace = 0;
	
	while(true)
	{
		x = wherex() - 1;
		y = wherey() - 1;
		while(_kbhit())
		{
			int kb_hit = _getch();
			
			// CHI NHAN CHU THUONG HOAC CHU IN HOA VA DAU CACH, DAU PHAY HOAC SO
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57 )
			|| kb_hit == SPACE || kb_hit == 44) && count < MAX_TENTG && count >= 0)
			{
				
				//XOA DONG THONG BAO
				gotoxy(a - 7, Y_NOTICE + 2);
				cout << setw(48) << setfill(' ') << " ";
				gotoxy(x, y);
				// CHUAN HOA KHOANG TRANG
				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					vitrisach += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					vitrisach += (char)kb_hit;
					nSpace = 1;
				}
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 1;
					return;
				}
				else
				{
					ordinal = 1;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 1;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				vitrisach.erase(vitrisach.length() - 1, 1);


			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else
			{
				gotoxy(a - 7 , Y_NOTICE + 2);
				cout << "TOI DA 17  KY TU, BAO GOM CHU, SO VA DAU PHAY !";
				gotoxy(x, y);
			}
		}
	}
}
//==================================11

//==================================12
int NhapMaDauSach(string &result)
{
	ShowCur(true);
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	while(true)
	{
		while(_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va so
			// chi nhap ten toi da 7 ky tu, vi tu dai nhat tieng viet chi la 7.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57)
			 || kb_hit == 44) && count <= 10 && count >= 0)
			{
				count++;
				// chuyen qua in hoa
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				result += (char)kb_hit;
			}
			else if (kb_hit == ENTER)
			{
				return 1 ;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);
			}
			else if (kb_hit == ESC)
			{
				return  -1;
			}
		}
	}
}
//==================================12
