// lay max width, height cua man hinh
int w = GetSystemMetrics(SM_CXSCREEN);
int h = GetSystemMetrics(SM_CYSCREEN);

//Window Window;
//SubWindow subWindow;


//Button Main Menu
int btnHeight = 50, btnWidth = 300, btnSpace = 80, btnY = 200;
Button btnQLDauSach(100, w/2-btnWidth/2, btnY + btnSpace, btnWidth, btnHeight, "QUAN LY DAU SACH", 0);
Button btnQLDocGia(101, w/2-btnWidth/2, btnY + 2*btnSpace, btnWidth, btnHeight, "QUAN LY DOC GIA", 0);
Button btnQLSach(102, w/2-btnWidth/2, btnY + 3*btnSpace, btnWidth, btnHeight, "MUON TRA SACH", 0);
Button btnThongTin(103, w/2-btnWidth/2, btnY + 4*btnSpace, btnWidth, btnHeight, "THONG TIN", 0);
Button btnThoat(104, w/2-btnWidth/2, btnY + 5*btnSpace, btnWidth, btnHeight, "THOAT", 0);

// toa do con tro chuot hien tai
int mx = -1, my = -1;



int curMenu=0;





char AppTitle[]="LIBRARY MANAGEMENT";

void ClearScreen();//RESET MAN HINH
void DrawMenu();//VE MENU
void Event(); //BAT SU KIEN
void MenuEvent();//BAT SU KIEN MENU
void ButtonEffect(Button &btn);//HIEU UNG NUT
void SetMenuSelect();


//===========BAT SU KIEN MENU============
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
//		}else if(btnQLDocGia.isMouseHover(mx, my)){
//			SetMenuSelect(btnQLDocGia.id);
//		}else if(btnQLSach.isMouseHover(mx, my)){
//			SetMenuSelect(btnQLSach.id);
//		}else if(btnThongTin.isMouseHover(mx, my)){
//			SetMenuSelect(btnThongTin.id);
//		}else if(btnThoat.isMouseHover(mx, my)){
//			isExit = true;
//		}
	}
}
//==========HIEU UNG NUT=============
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
//==================================
//===============Chon Nut Menu============
void SetMenuSelect(int menuID){
	if(curMenu != menuID){
		curMenu = menuID;
		ClearScreen();
		
		if(curMenu == 0){
			DrawMenu();
		}else if(menuID == btnQLDauSach.id){
			RunDauSach();
		}else if(menuID == btnQLDocGia.id){
			RunDocGia();
		}else if(menuID == btnQLSach.id){
			RunMuonTra();
		}else if(menuID == btnThongTin.id){
			RunThongTin();
		}
	}	
}

