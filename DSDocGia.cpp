#include "DSDocGia.h"

void KhoiTao(NodeDG &root) //khoi tao cay
{
   root = NULL;
}

NodeDG NewNodeDG()//tao moi node
{
    NodeDG p =new Node_DG;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}

void ThemDG(NodeDG &tree, NodeDG p)
{
	if (tree == NULL)
	{
		tree = p;
	}
	else
	{
		if (p->data.madg > tree->data.madg)
		{
			ThemDG(tree->pRight, p);
		}
		else if (p->data.madg < tree->data.madg)
		{
			ThemDG(tree->pLeft, p);
		}
	}
}

void Load_DG(NodeDG &t)
{
	// khoi tao cay doc gia
	KhoiTao(tree);

	fstream filein;
	DocGia dg;
	MUON_TRA mt;
	filein.open("DocGia.txt", ios::in);
	int sodocgia, sosachmuontra;

	if (filein.is_open())
	{
		string temp;
		filein >> sodocgia;

		for (int i = 0 ; i < sodocgia; i++)
		{
			filein >> dg.madg;
			getline(filein, temp);
			getline(filein, dg.ho);
			getline(filein, dg.ten);
			filein >> dg.gioitinh;
			filein >> dg.trangthaithe;

			// them data vao cay doc gia.
			ThemDG(t, dg);
			//pDG = Find_DG(t, dg.MADG);

			
			filein >> sosachmuontra;
			getline(filein, temp);

			for (int j = 0; j <  sosachmuontra; j++)
			{
				getline(filein, mt.MASACH);
				filein >> mt.ngaymuon.ngay;
				filein >> mt.ngaymuon.thang;
				filein >> mt.ngaymuon.nam;
				filein >> mt.ngaytra.ngay;
				filein >> mt.ngaytra.thang;
				filein >> mt.ngaytra.nam;

				getline(filein, temp);
				getline(filein, mt.tensach);
				filein >> mt.trangthaithe;
				getline(filein, temp);
				getline(filein, mt.vitrisach);

				// cap nhat du lieu vao
				AddHeadList_MT(pDG->mt, mt);
			}
		}
	}
	else {
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}
	filein.close();
}


///
void Save(NodeDG t, fstream &file)
{
	file << t->data.madg << endl;
	file << t->data.ho << endl;
	file << t->data.ten << endl;
	file << t->data.gioitinh << endl;
	file << t->data.trangthaithe << endl;
	file << t->mt.n << endl;
	for (NODE_MT* p = t->mt.pHead ; p != NULL; p = p->pNext )
	{
		file << p->data.MASACH << endl;

		file << p->data.ngaymuon.ngay << endl;
		file << p->data.ngaymuon.thang << endl;
		file << p->data.ngaymuon.nam << endl;

		file << p->data.ngaytra.ngay << endl;
		file << p->data.ngaytra.thang << endl;
		file << p->data.ngaytra.nam << endl;

		file << p->data.tensach << endl;
		file << p->data.trangthaithe << endl;
		file << p->data.vitrisach << endl;
	}
}

// ouput tree vao file theo kieu duyet tin thu tu...
void OutFile_DG(NodeDG t, fstream &file)
{
	if (t != NULL)
	{
		Save(t, file);
		OutFile_DG(t->pLeft, file);
		OutFile_DG(t->pRight, file);	
	}
}

void Save_DG(NodeDG t)
{
	fstream outFile;
	outFile.open("DocGia.txt", ios::out);
	if (outFile.is_open())
	{
		// so doc gia..
		outFile << countDG(t) << endl;
		OutFile_DG(t, outFile);
	}
	else
	{
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}
	outFile.close();
}
///
bool MaTrungKhop(NodeDG tree, int ma)
{
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		if (tree->data.madg == ma)
		{
			return 1;
		}
		else if (tree->data.madg < ma)
		{
			MaTrungKhop(tree->pRight, ma);
		}
		else
		{
			MaTrungKhop(tree->pLeft, ma);
		}
	}
}

int TaoMaDG(NodeDG tree)
{
	int ma;//100-999
	do
	{
		ma = rand() % (999 - 100 + 1) + 100;
	} while (MaTrungKhop(tree,ma)==true);
	return ma;
}



void NhapDocGia(){
    cout << "Nhap doc gia moi: ";
    NodeDG p = NewNodeDG();

    cout << "Nhap ho: ";getline(cin, p->data.ho);
	ChuanHoa(p->data.ho);
	cout << "Nhap ten: ";getline(cin, p->data.ten);
	ChuanHoa(p->data.ten);
	cout << "Nhap gioi tinh: ";cin >> p->data.gioitinh;

    cin.ignore(); // dat sau ham nhap so
	p->data.trangthaithe = 1;
	p->data.madg = TaoMaDG(tree);
	ThemDG(tree, p);
}

void HoanViNodeDG(NodeDG a,NodeDG b)
{
	NodeDG tam = new Node_DG;
	tam->data.madg = a->data.madg;
	tam->data.ho = a->data.ho;
	tam->data.ten = a->data.ten;
	tam->data.gioitinh = a->data.gioitinh;
	tam->data.trangthaithe = a->data.trangthaithe;
	//---------
	a->data.madg = b->data.madg;
	a->data.ho = b->data.ho;
	a->data.ten = b->data.ten;
	a->data.gioitinh = b->data.gioitinh;
	a->data.trangthaithe = b->data.trangthaithe;
	//-----------
	b->data.madg = tam->data.madg;
	b->data.ho = tam->data.ho;
	b->data.ten = tam->data.ten;
	b->data.gioitinh = tam->data.gioitinh;
	b->data.trangthaithe = tam->data.trangthaithe;
	delete tam;
}

void NodeThayThe(NodeDG &t,NodeDG &x)
{
	if (t->pLeft != NULL)
	{
		NodeThayThe(t->pLeft,x);
	}
	else//trai cung
	{
		HoanViNodeDG(t, x);
		x = t;//x se luu vi tri node nay de ty nua giai phong
		t = t->pRight;
	}
}

void XoaNodeDG(NodeDG &tree,int ma)
{
	if (tree!= NULL)
	{
		if (tree->data.madg == ma)
		{
			NodeDG x = tree;//x se luu node can giai phong
			if (tree->pLeft == NULL)
			{
				tree = tree->pRight;
			}
			else if (tree->pRight == NULL)
			{
				tree = tree->pLeft;
			}
			else if (tree->pLeft != NULL && tree->pRight != NULL)
			{
				//tim node thay the: node trai ngoai cung cay con phai
				NodeThayThe(tree->pRight, x);
			}
			delete x;
		}
		else if (tree->data.madg < ma)
		{
			XoaNodeDG(tree->pRight, ma);
		}
		else if (tree->data.madg > ma)
		{
			XoaNodeDG(tree->pLeft, ma);
		}
	}
}

void XoaDG(NodeDG &tree)
{
	int a;
	cout << "Nhap ma DG: ";cin >> a;
	bool kt = MaTrungKhop(tree, a);
	if (kt == true)
	{
		//xoa
		XoaNodeDG(tree, a);
		cout << "Xoa Thanh Cong!" << endl;
	}
	else
	{
		cout << "Ma khong ton tai!" << endl;
	}
}

void ChuanHoa(string &s)
{
	int i = 0;
	
	while(s[i] != '\0')
    {
		if(s[i] == ' ')
        {
            while(s[i + 1] == ' ')
            {
                s.erase(i+1,1);
            }
            s[i+1]=toupper(s[i+1]);
			if (s[i+1]=='\0')
            {
            	s.erase(i,1);
			} 
        }
        i++;
    }
    while (s[0]==' ')
    {
    	s.erase(0,1);
	}
	s[0]=toupper(s[0]);
	cout << s;
}

void ChinhSuaNodeDG(NodeDG t, int ma)
{
	if (t != NULL)
	{
		if (t->data.madg == ma)
		{
			cin.ignore();
			cout << "Nhap ho: ";getline(cin, t->data.ho);
			cout << "Nhap ten: ";getline(cin, t->data.ten);
			cout << "Nhap phai: ";cin >> t->data.gioitinh;
			ChuanHoa(t->data.ho);
			ChuanHoa(t->data.ten);
		}
		else if (t->data.madg > ma)
		{
			ChinhSuaNodeDG(t->pLeft, ma);
		}
		else if (t->data.madg < ma)
		{
			ChinhSuaNodeDG(t->pRight, ma);
		}
	}
}
void ChinhSuaDG(NodeDG &tree)
{
	int a;
	cout << "Nhap ma can hieu chinh: ";cin >> a;
	bool kt = MaTrungKhop(tree, a);
	if (kt == true)
	{
		ChinhSuaNodeDG(tree, a);
		cout << "Da hieu chinh thong tin" << endl;
	}
	else
	{
		cout << "Ma khong ton tai." << endl;
	}
}

//===== Sap xep theo ten ====
//---- chuyen cay sang mang ---------
void TreeToArr(NodeDG t,DG *ds[],int &k)
{
	if (t != NULL)
	{
		//data
		ds[k] = new DG;
		ds[k]->madg = t->data.madg;
		ds[k]->ho = t->data.ho;
		ds[k]->ten = t->data.ten;
		ds[k]->gioitinh = t->data.gioitinh;
		k++;
		TreeToArr(t->pLeft, ds, k);
		TreeToArr(t->pRight, ds, k);
	}
}

void HoanViDG(DG *a,DG *b)
{
	DG *tam = new DG;
	tam->madg = a->madg;
	tam->ho = a->ho;
	tam->ten = a->ten;
	tam->gioitinh = a->gioitinh;
	//*DS muon
	//---------
	a->madg = b->madg;
	a->ho = b->ho;
	a->ten = b->ten;
	a->gioitinh = b->gioitinh;
	//*DS muon
	//-----------
	b->madg = tam->madg;
	b->ho = tam->ho;
	b->ten = tam->ten;
	b->gioitinh = tam->gioitinh;
	//*DS muon
	delete tam;
}

void SapXepTheoTen(DG *ds[], int &k)
{
	for (int i = 0;i < k-1;i++)
	{
		for (int j = i + 1;j < k;j++)
		{
			if (ds[i]->ten > ds[j]->ten)
			{
				HoanViDG(ds[i], ds[j]);
			}
			else if (ds[i]->ten == ds[j]->ten)
			{
				if (ds[i]->ho > ds[j]->ho)
				{
					HoanViDG(ds[i], ds[j]);
				}
			}
		}
	}
}


//--- In Ds -------------
void XuatDS(DG *ds[], int &k)
{
	for (int i = 0;i < k;i++)
	{
		cout << "\t\t======== Doc Gia " << i << " ========" << endl;
		cout << "Ma : " << ds[i]->madg << endl;
		cout << "Ho ten:" << ds[i]->ho << ds[i]->ten << endl;
		cout << "Phai: " << ds[i]->gioitinh << endl;
	}
}
//------------ giai phong ------------
void GiaiPhong(DG *ds[], int &k)
{
	for (int i = 0;i < k;i++)
	{
		delete ds[i];
	}
}


//===== Sap xep theo MaDG tang ====
//Duyet Inoder (LNR)
void DuyetInoder(NodeDG tree)
{
    if(tree != NULL)
    {
        DuyetInoder(tree->pLeft);
        cout << "Ma : " << tree->data.madg << endl;
		cout << "Ho ten:" << tree->data.ho << tree->data.ten << endl;
		cout << "Gioi tinh: " << tree->data.gioitinh << endl;
        DuyetInoder(tree->pRight);
   }
}
NodeDG TimDG(NodeDG root, int x)
{
   NodeDG p;
   p = root;
   while (p != NULL && p->data.madg !=x)
    if(x < p->data.madg)
        p = p->pLeft;
    else
        p = p->pRight;
    return(p);
}

int main()
{

    DG *ds[1000];
    int n=0;
    KhoiTao(tree);
    NhapDocGia();
    NhapDocGia();
    //NhapDocGia();
    //DocFileDG(tree);
    GhiFileDG(tree);
    DuyetInoder(tree);
    TreeToArr(tree,ds,n);
    cout << "Sap Xep Theo Ten:\n";
    SapXepTheoTen(ds,n);
    XuatDS(ds,n);
//    XoaDG(tree);
    ChinhSuaDG(tree);
    DuyetInoder(tree);

    return 0;
}
