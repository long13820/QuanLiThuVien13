// lay max width, height cua man hinh
int w = GetSystemMetrics(SM_CXSCREEN);
int h = GetSystemMetrics(SM_CYSCREEN);

int curMenu = 0;

// toa do con tro chuot hien tai
int mx = -1, my = -1;


// Button Main Menu
int btnHei = 60, btnWid = 300, btnSpace = 80, btnY = 200;
Button btnQLDauSach(100, w/2-btnWid/2, btnY + btnSpace, btnWid, btnHei, "QUAN LY DAU SACH", 0);
Button btnQLDocGia(101, w/2-btnWid/2, btnY + 2*btnSpace, btnWid, btnHei, "QUAN LY DOC GIA", 0);
Button btnQLSach(102, w/2-btnWid/2, btnY + 3*btnSpace, btnWid, btnHei, "MUON TRA SACH", 0);
Button btnThongTin(103, w/2-btnWid/2, btnY + 4*btnSpace, btnWid, btnHei, "THONG TIN", 0);
Button btnThoat(104, w/2-btnWid/2, btnY + 5*btnSpace, btnWid, btnHei, "THOAT", 0);

char AppTitle[]="QUAN LI THU VIEN";

/*============FUNCTION==============*/
void ClearScreen();
void DrawMenu();
void ButtonEffect(Button &btn);
void MenuEvent();
void Event();
void SetMenuSelect(int menuID);
/*==================================*/


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
void ButtonEffect(Button &btn){
	if(btn.isChoose) return;
	
	if(btn.isMouseHover(mousex(), mousey())){
		if(btn.isHover == false){
			btn.isHover = true;
			btn.draw();
		}
	}else{
		if(btn.isHover == true){
			btn.isHover = false;
			btn.draw(); 
		} 
	} 
}
void MenuEvent(){
	ButtonEffect(btnQLDauSach);
	ButtonEffect(btnQLDocGia);
	ButtonEffect(btnQLSach);
	ButtonEffect(btnThongTin);
	ButtonEffect(btnThoat);	

	//Menu Click Event
	if(GetAsyncKeyState(VK_LBUTTON)){
		if(btnQLDauSach.isMouseHover(mx, my)){
			SetMenuSelect(btnQLDauSach.id);
		}
		else if(btnQLDocGia.isMouseHover(mx, my)){
			SetMenuSelect(btnQLDocGia.id);
		}
		else if(btnQLSach.isMouseHover(mx, my)){
			SetMenuSelect(btnQLSach.id);
		}
		else if(btnThongTin.isMouseHover(mx, my)){
			SetMenuSelect(btnThongTin.id);
		}
		else if(btnThoat.isMouseHover(mx, my)){
			exit(0);
		}
	}
}
void Event(){
	mx= mousex();my = mousey();
	if(curMenu = 0){
		MenuEvent();
	}
//	else if(curMenu == btnQLDauSach.id){
//		DauSachEvent();
//	}
//	else if(curMenu == btnQLDocGia.id){
//		DocGiaEvent();
//	}
//	else if(curMenu == btnQLSach.id){
//		MuonTraEvent();
//	}
//	else if(curMenu == btnThongTin.id){
//		ThongTinEvent();
//	}
}
void SetMenuSelect(int menuID){
	if(curMenu != menuID){
		curMenu = menuID;
		ClearScreen();
		
		if(curMenu == 0){
			DrawMenu();
		}
//		else if(menuID == btnQLDauSach.id){
//			RunDauSach();
//		}
//		else if(menuID == btnQLDocGia.id){
//			RunDocGia();
//		}
//		else if(menuID == btnQLSach.id){
//			RunMuonTra();
//		}
//		else if(menuID == btnThongTin.id){
//			RunThongTin();
//		}	
	}	
}
