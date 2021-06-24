struct DauSach{
	char ISBN[11];
	char tensach[23];
	int sotrang;
	char tacgia[13];
	int namxuatban;
	char theloai[13];
	
	NodeSach *First=NULL;
	
	//CAC THUOC TINH THEM
	int soluotmuon; //so luot muon sach
	int soluong; //so luong sach cua dau sach
	
	DauSach(){
		
	}
	DauSach(char *isbn,char *ten, int st, char *tg, int nxb, char *tl)
	{
		strcpy(ISBN,isbn);
		strcpy(tensach,ten);
		sotrang = st;
		strcpy(tacgia,tg);
		namxuatban=nxb;
		strcpy(theloai,tl);
		
		First= NULL;
		
		soluong=0;
		soluotmuon=0;
	}
};
struct DS_DauSach{
	int n;
	DauSach *nodes[MAX_SIZE_DAUSACH];
	
	DS_DauSach(){
	}
	~DS_DauSach(){
		
	}
};
