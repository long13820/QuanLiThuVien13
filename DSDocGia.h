#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

struct DocGia{
	int madg;
	string ho;
	string ten;
	bool gioitinh;
	bool trangthaithe;
};
typedef struct DocGia DG; //data

struct Node_DG{
	DG data;
	struct Node_DG *pLeft;
	struct Node_DG *pRight;
	LIST_MT mt;
};


typedef struct Node_DG *NodeDG; //Node
NodeDG tree=NULL; //tree quan ly toan bo cay dsdg

void KhoiTao(NodeDG &root); //khoi tao cay

NodeDG NewNodeDG();//tao moi node

void ThemDG(NodeDG &tree, NodeDG p);

void DocFileDG(NodeDG &tree);

void GhiFileDG (NodeDG &root);

bool MaTrungKhop(NodeDG tree, int ma);

int TaoMaDG(NodeDG tree);

void NhapDocGia();
void HoanViNodeDG(NodeDG a,NodeDG b);

void NodeThayThe(NodeDG &t,NodeDG &x);

void XoaNodeDG(NodeDG &tree,int ma);

void XoaDG(NodeDG &tree);

void ChinhSuaNodeDG(NodeDG t, int ma);

void ChinhSuaDG(NodeDG &tree);

//===== Sap xep theo ten ====
//---- chuyen cay sang mang ---------
void TreeToArr(NodeDG t,DG *ds[],int &k);

void HoanViDG(DG *a,DG *b);

void SapXepTheoTen(DG *ds[], int &k);


//--- In Ds -------------
void XuatDS(DG *ds[], int &k);
//------------ giai phong ------------
void GiaiPhong(DG *ds[], int &k);

//===== Sap xep theo MaDG tang ====
//Duyet Inoder (LNR)
void DuyetInoder(NodeDG tree);

NodeDG TimDG(NodeDG root, int x);
void ChuanHoa(string &s);
void XoaKiTu(string &s, int vt);


