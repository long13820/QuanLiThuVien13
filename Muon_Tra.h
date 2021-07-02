#pragma once
#include "Ngay_Thang.h"

struct MuonTra{
	string MASACH;
	NGAYTHANG ngaymuon;
	NGAYTHANG ngaytra;
	int trangthai;
	
};
typedef struct MuonTra MUON_TRA;

struct NodeMuonTra{
	MUON_TRA data;
	struct NodeMuonTra *pNext;
};

typedef struct NodeMuonTra *NODE_MT;

struct ListMT{
	int n;//SO PHAN TU
	NODE_MT pHead;
	NODE_MT ptail;
};
typedef struct ListMT LIST_MT;
