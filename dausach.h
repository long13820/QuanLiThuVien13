

//==================CHAY DAU SACH============
void RunDauSach(){
	strcpy(mess, "");
	ClearContentThemDauSach();
	
	setlinestyle(SOLID_LINE, 0, 1);
	line(XDS[6]+10, 0, XDS[6]+10, h);
	
	DrawDanhSachDauSach();
	
	//DrawList();
	
	Window = THEM_DAU_SACH;
	subWindow = NHAP_SACH;
	
	if(Window== THEM_DAU_SACH){
		DrawThemDauSach();
	}
}
//===========================================

//==================VE DANH SACH DAU SACH===================
void DrawList(){
	ClearLayoutListDauSach();
	DrawBorderList();
	char ch[6][20] = {"ISBN", "TEN SACH", "SO TRANG", "TAC GIA", "NXB", "THE LOAI"};
	
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	for(int i=0; i < 6; i++){
		setbkcolor(BG_COLOR);
		outtextxy(XDS[i] + (XDS[i+1]-XDS[i])/2 - textwidth(ch[i])/2, 170, ch[i]);
	}
	
	// caculate Total Page 
	// Num per page = 13
	
	
	//setcolor(TEXT_COLOR);
//	if(strlen(edTimDauSach.content) == 0){
//		totalPageDauSach = (DSDS.n-1) / 13 + 1;
//		for(int i = 13*(curPageDauSach-1); i < 13*curPageDauSach ; i++){
//			if (i >= DSDS.n) break;
//			DrawItemDauSach(i, -1);
//		}
//	}
//	else{
//		totalPageDauSach = (sizeListIndexDauSachSearch-1) / 13 + 1;
//		int j = 0;
//		for(int i = 13*(curPageDauSach-1); i < 13*curPageDauSach ; i++){
//			if (i >= sizeListIndexDauSachSearch) break;
//			DrawItemDauSach(listIndexDauSachSearch[i], j++);
//		}
//	}
//	
	// num page
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	char chPage[20];
	sprintf(chPage, "TRANG %d / %d", curPageDauSach, totalPageDauSach);
	outtextxy((XDS[0]+XDS[6])/2 - textwidth(chPage)/2, 785, chPage);
	
	// tips
	setcolor(TIPS);
	rectangle(XDS[0], 880, XDS[6], 980);
	outtextxy(30, 890, "Click chuot trai: Hieu chinh dau sach");
	outtextxy(30, 920, "Click chuot phai: Xem thong tin, danh muc sach");
}
//===================================================================

//==================XOA NOI DUNG THEM DAU SACH===================
void ClearContentThemDauSach(){	
	memset(edThemISBN.content, 0, sizeof(edThemISBN.content));
	memset(edThemTenSach.content, 0, sizeof(edThemTenSach.content));
	memset(edThemSoTrang.content, 0, sizeof(edThemSoTrang.content));
	memset(edThemTacGia.content, 0, sizeof(edThemTacGia.content));
	memset(edThemNXB.content, 0, sizeof(edThemNXB.content));
	memset(edThemTheLoai.content, 0, sizeof(edThemTheLoai.content));
}
//================================================================

//=================VE DANH SACH DAU SACH==========
void DrawDanhSachDauSach(){
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_TITLE_COLOR);
	outtextxy((XDS[0]+XDS[6])/2-textwidth(DauSachTitle)/2, 15, DauSachTitle);
	btnQuayVe.draw();
	btnClearTimDauSach.draw();
	btnPrevDauSach.draw();
	btnNextDauSach.draw();
	
	edTimDauSach.draw();
}
//=============================================

//==================XOA LAYOUT DANH SACH DAU SACH================
void ClearLayoutListDauSach(){
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(XDS[0], 150, XDS[6], 750);
}
//=============================================================

//===================
void DrawBorderList(){
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(XDS[0], 150, XDS[6], 750);// VE KHUNG HCN
	line(XDS[0], 150 + 25 + 2*20, XDS[6], 150 + 25 + 2*20);//DUONG TACH TABLE
	for(int i=0; i < 6; i++){
		line(XDS[i+1], 150, XDS[i+1], 750);
	}//VE KHUNG TABLE
}
//========================================================
