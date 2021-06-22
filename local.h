
// lay max width, height cua man hinh
int w = GetSystemMetrics(SM_CXSCREEN);
int h = GetSystemMetrics(SM_CYSCREEN);

//Window Window;
//SubWindow subWindow;

int XDS[7] = {10, 200, 500, 600, 800, 900, 1100};
//Button Main Menu
int btnHeight = 50, btnWidth = 300, btnSpace = 80, btnY = 200;
Button btnQLDauSach(100, w/2-btnWidth/2, btnY + btnSpace, btnWidth, btnHeight, "QUAN LY DAU SACH", 0);
Button btnQLDocGia(101, w/2-btnWidth/2, btnY + 2*btnSpace, btnWidth, btnHeight, "QUAN LY DOC GIA", 0);
Button btnQLSach(102, w/2-btnWidth/2, btnY + 3*btnSpace, btnWidth, btnHeight, "MUON TRA SACH", 0);
Button btnThongTin(103, w/2-btnWidth/2, btnY + 4*btnSpace, btnWidth, btnHeight, "THONG TIN", 0);
Button btnThoat(104, w/2-btnWidth/2, btnY + 5*btnSpace, btnWidth, btnHeight, "THOAT", 0);
// Button Dau Sach
Button btnQuayVe(201, 10, 10, 100, 50, "< MENU", 0);
Button btnClearTimDauSach(202, 800, 70, 100, 50, "CLEAR", 0);
Button btnPrevDauSach(203, 10, 770, 150, 50, "TRANG TRUOC", 0);
Button btnNextDauSach(204, XDS[6]-150, 770, 150, 50, "TRANG SAU", 0);

EditText edTimDauSach(1000, 50, 70, 700, 50, "Tim dau sach:", "", "Nhap ten sach vao day");

// Them Dau Sach
EditText edThemISBN(1002, XDS[6]+50, 290, 700, 40, "ISBN :","","Chi nhan so va chu cai, toi da 10 ki tu");
EditText edThemTenSach(1003, XDS[6]+50, 340, 700, 40, "Ten sach :","","Chi nhan chu cai va so, toi da 22 ki tu");
EditText edThemSoTrang(1004, XDS[6]+50, 390, 700, 40, "So trang :","","Chi nhan so, toi da 5 ki tu");
EditText edThemTacGia(1005, XDS[6]+50, 440, 700, 40, "Tac gia :","","Chi nhan chu cai, toi da 12 ki tu");
EditText edThemNXB(1006, XDS[6]+50, 490, 700, 40, "Nam xuat ban :","","Chi nhan so");
EditText edThemTheLoai(1007, XDS[6]+50, 540, 700, 40, "The loai :","","Chi nhan chu cai, toi da 12 ki tu");

Button btnThemDauSach(205, (w-15+XDS[6])/2 - 50, 590, 150, 50, "THEM", 0);


// toa do con tro chuot hien tai
int mx = -1, my = -1;



int curMenu=0;


char mess[50];
char AppTitle[]="LIBRARY MANAGEMENT";
char DauSachTitle[]="DANH SACH DAU SACH";



void ClearScreen();//RESET MAN HINH
void DrawMenu();//VE MENU
void Event(); //BAT SU KIEN
void MenuEvent();//BAT SU KIEN MENU
void ButtonEffect(Button &btn);//HIEU UNG NUT
void SetMenuSelect(int menuID);//CHON NUT MENU
void RunDauSach();//CHAY DAU SACH
void DrawDanhSachDauSach();//VE DANH SACH DAU SACH
void ClearContentThemDauSach();//XOA NOI DUNG THEM DAU SACH
void DrawList();//

//==================CLEAR MAN HINH================
void ClearScreen(){
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(0, 0, w, h);  
}
//==========================================

//=================VE MENU========================    
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
//========================================

//=======================BAT SU KIEN===================
void Event(){
	mx= mousex();my= mousey();
	if(curMenu == 0){
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
//===============================================
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
//===========================================

//==========HIEU UNG NUT=============
void ButtonEffect(Button &btn){
	if(btn.isChoose) return;
	
	if(btn.isMouseHover(mousex(), mousey())){
		if(btn.isHover == false){
			btn.isHover = true;
			btn.draw();
		}
	}
	else{
		if(btn.isHover == true){
			btn.isHover = false;
			btn.draw(); 
		} 
	} 
}
//====================================================


//===============CHON NUT MENU===============
void SetMenuSelect(int menuID){
	if(curMenu != menuID){
		curMenu = menuID;
		ClearScreen();
		
		if(curMenu == 0){
			DrawMenu();
		}
		else if(menuID == btnQLDauSach.id){
			RunDauSach();
		}
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
//==========================================





//==================
//void DrawList(){
//	ClearLayoutListDauSach();
//	DrawBorderList();
//	char ch[6][20] = {"ISBN", "Ten sach", "So trang", "Tac gia", "NXB", "The loai"};
//		
//	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
//	for(int i=0; i < 6; i++){
//		setbkcolor(BG_COLOR);
//		outtextxy(XDS[i] + (XDS[i+1]-XDS[i])/2 - textwidth(ch[i])/2, 170, ch[i]);
//	}
//	
//	// caculate Total Page 
//	// Num per page = 13
//	
//	
//	setcolor(TEXT_COLOR);
//	if(strlen(edTimDauSach.content) == 0){
//		totalPageDauSach = (DSDS.n-1) / 13 + 1;
//		for(int i = 13*(curPageDauSach-1); i < 13*curPageDauSach ; i++){
//			if (i >= DSDS.n) break;
//			DrawItemDauSach(i, -1);
//		}
//	}else{
//		totalPageDauSach = (sizeListIndexDauSachSearch-1) / 13 + 1;
//		int j = 0;
//		for(int i = 13*(curPageDauSach-1); i < 13*curPageDauSach ; i++){
//			if (i >= sizeListIndexDauSachSearch) break;
//			DrawItemDauSach(listIndexDauSachSearch[i], j++);
//		}
//	}
//	
//	// num page
//	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
//	char chPage[20];
//	sprintf(chPage, "TRANG %d / %d", curPageDauSach, totalPageDauSach);
//	outtextxy((XDS[0]+XDS[6])/2 - textwidth(chPage)/2, 785, chPage);
//	
//	// tips
//	setcolor(TIPS);
//	rectangle(XDS[0], 880, XDS[6], 980);
//	outtextxy(30, 890, "Click chuot trai: Hieu chinh dau sach");
//	outtextxy(30, 920, "Click chuot phai: Xem thong tin, danh muc sach");
//}
