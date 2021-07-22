#pragma once
#include <iostream>
//////#include <string>
//#include "Muon_Tra.h"
#include "GlobalVariable.h"
#include "ve_hinh.h"
#include <fstream>

using namespace std;

struct DocGia{
	int madg;
	string ho;
	string ten;
	bool gioitinh;
	bool trangthai;
};
typedef struct DocGia DG; //data

struct Node_DG{
	DG data;
	struct Node_DG *pLeft;
	struct Node_DG *pRight;
};
typedef struct Node_DG *NodeDG; //Node #*

NodeDG tree=NULL; //tree quan ly toan bo cay dsdg

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

void DocFileDG(NodeDG &tree)
{
	ifstream filein;
	filein.open("ds_dg.txt", ios_base::in);
	while (filein.eof() != true)
	{
		NodeDG x = NewNodeDG();
		filein >> x->data.madg;
		filein.ignore();
		getline(filein, x->data.ho, '|');
		getline(filein, x->data.ten, '|');
		filein >> x->data.gioitinh;
		filein.ignore();
		filein >> x->data.trangthai;
		cout << x->data.madg << " " << x->data.ho << " " << x->data.ten <<" "<< x->data.gioitinh<< " " << x->data.trangthai;

		ThemDG(tree, x);
	}
	filein.close();
}

void GhiFileDG (NodeDG &root)
{
    ofstream fileout;
	fileout.open("ds_dg.txt", ios_base::out);
    while (root!=NULL)
	{
        GhiFileDG(root->pLeft);
        fileout << root->data.madg <<"|";
        fileout << root->data.ho << "|";
        fileout << root->data.ten << "|";
        fileout << root->data.gioitinh << "|";
        fileout << root->data.trangthai << "\n";
        GhiFileDG(root->pRight);
	}
	fileout.close();
}
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

	cout << "Nhap ten: ";getline(cin, p->data.ten);
	cout << "Nhap gioi tinh: ";cin >> p->data.gioitinh;

    cin.ignore(); // dat sau ham nhap so
	p->data.trangthai = 1;
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
	tam->data.trangthai = a->data.trangthai;
	//---------
	a->data.madg = b->data.madg;
	a->data.ho = b->data.ho;
	a->data.ten = b->data.ten;
	a->data.gioitinh = b->data.gioitinh;
	a->data.trangthai = b->data.trangthai;
	//-----------
	b->data.madg = tam->data.madg;
	b->data.ho = tam->data.ho;
	b->data.ten = tam->data.ten;
	b->data.gioitinh = tam->data.gioitinh;
	b->data.trangthai = tam->data.trangthai;
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
//			ChuanHoa(t->data.ho);
//			ChuanHoa(t->data.ten);
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
		cout << "Ho ten:" << ds[i]->ho << " " << ds[i]->ten << endl;
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
		cout << "Ho ten:" << tree->data.ho << " " << tree->data.ten << endl;
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
//    NhapDocGia();
//    NhapDocGia();
//    NhapDocGia();
    DocFileDG(tree);
    DuyetInoder(tree);
    TreeToArr(tree,ds,n);
    cout << "Sap Xep Theo Ten:\n";
    SapXepTheoTen(ds,n);
    XuatDS(ds,n);
//    XoaDG(tree);
//    ChinhSuaDG(tree);
//    DuyetInoder(tree);

    return 0;
}

