#pragma once
#include <iostream>
#include "Marcro.h"

using namespace std;


// ham ho tro Nhap Ten Sach.
void NhapTenSach(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapISBN(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapTenTacGia(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapTheLoaiSach(string &result, int &ordinal, bool &isSave, bool &isEscape);
void NhapSoTrang(int &sotrang, int &ordinal, bool &isSave, bool &isEscape);
void NhapNamXuatBan(int &namxuatban, int &ordinal, bool &isSave, bool &isEscape);

//LOAI BO KHOANG SPACE ' ' THUA TRONG STRING 
string ChuanHoaString(string result);

// ham ho tro nhap ten sach tu ban phim de tra cuu thong tin.
int NhapTenSachTimKiem(string &result);
//==================================1
void NhapTenSach(string &result, int &ordinal, bool &isSave, bool &isEscape)
{
	ShowCur(true);
	// BIEN DEM SO CHU DA NHAP VAO RESULT
	cout << result;
	int count = (int)result.length();
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

				if (result[count - 1] != ' ' && kb_hit == SPACE && count > 0)
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
				result.erase(result.length() - 1, 1);
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
void NhapISBN(string &result,int &ordinal, bool &isSave, bool &isEscape){
	// BIEN DEM SO CHU DA NHAP CHO VAO RESULT
	cout << result;
	int count = (int)result.length();
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
				result += (char)kb_hit;
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
				result.erase(result.length() - 1 , 1);
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
				cout << "TOI DA 6 KY TU, CHI LAY KY TU CHU !!!";
				gotoxy(x, y);
			}

		}
	}
}

//==================================2

//==================================3
void NhapTenTacGia(string &result,int &ordinal,bool &isSave,bool &isEscape){
	ShowCur(true);
	//BIEN DEM SO CHU DA DC NHAP VAO RESULT
	cout<< result;
	int count = (int)result.length();
	int x,y;
	//BIEN CO HIEU
	int nSpace = 0;
	
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
					result += (char)kb_hit;
					nSpace = 0;
				}
				else if(kb_hit != SPACE){
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
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
				result.erase(result.length() - 1, 1);
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
void NhapTheLoaiSach(string &result, int &ordinal, bool &isSave, bool &isEscape)
{
	ShowCur(true);
	//BIEN DEM SO CHU DA DUOC NHAP VAO CHO RESULT
	cout << result;
	int count = (int)result.length();
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
				result.erase(result.length() - 1, 1);
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
	for (int i = 1; i < result.length();i++){
		if(result[0] == ' '){
			result.erase(0, 1);
		}
		else if( result[i - 1] == ' '&& result[i] == ' '){
			result.erase(i - 1 , 1);
			i--;
		}
		else if(result[result.length() - 1] == ' '){
			result.erase(result.length() - 1, 1);
		}
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
				return  -1;
			}


		}
	}
}
//==================================8
