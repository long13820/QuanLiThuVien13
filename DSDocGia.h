#pragma once
#include <iostream>
#include <string>
#include "mylib.h"
#include "Muon_Tra.h"
using namespace;


struct DocGia{
	int MADG,gioitinh,trangthai;
	string ho,ten;
};
typedef struct DocGia DOC_GIA;

struct NodeDG{
	DOC_GIA DG;
	struct NodeDG *pLeft;
	struct NodeDG *pRight;
	
};
