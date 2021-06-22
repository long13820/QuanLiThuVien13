using namespace std; 

//#include <winbgim.h> 
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <string>
             

#include "define.h"


#include "view.h"
#include "local.h"

   
bool isExit = false;

             
int main(int argc, char *argv[])
{
	srand(time(NULL));
	initwindow(w, h, AppTitle);
	ClearScreen();
	
	
	DrawMenu();
	
	while(true){
		Event();
		if(isExit) break;
		delay(50);
	}	
	
	closegraph();	
	return 0;
}

void ClearScreen(){
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(0, 0, w, h);  
}
    
void DrawMenu(){
	settextstyle(BOLD_FONT, HORIZ_DIR, 7);
	setcolor(TEXT_TITLE_COLOR);
	outtextxy(w/2-textwidth(AppTitle)/2, 50, AppTitle);
	
	btnQLDauSach.draw();
	btnQLDocGia.draw();
	btnQLSach.draw();
	btnThongTin.draw();
	btnThoat.draw();
} 
void Event(){
	mx= mousex();my= mousey();
	if(curMenu == 0){
		MenuEvent();
//	}else if(curMenu == btnQLDauSach.id){
//		DauSachEvent();
//	}else if(curMenu == btnQLDocGia.id){
//		DocGiaEvent();
//	}else if(curMenu == btnQLSach.id){
//		MuonTraEvent();
//	}else if(curMenu == btnThongTin.id){
//		ThongTinEvent();
	}
}

