

//==================CHAY DAU SACH============
void RunDauSach(){
	strcpy(mess, "");
	ClearContentThemDauSach();
	
	setlinestyle(SOLID_LINE, 0, 1);
	line(XDS[6]+10, 0, XDS[6]+10, h);
	
	DrawDanhSachDauSach();
	
	//DrawList();
}
//===========================================

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
