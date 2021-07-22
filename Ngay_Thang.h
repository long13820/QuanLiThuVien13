#pragma once
#include <time.h>
#include <iostream>
const int MAX_NAM = 9999;
const int MIN_NAM = 1800;

struct NgayThang{
	int ngay,thang,nam;
};
typedef struct NgayThang NGAYTHANG;

//LAY NAM TU HE THONG

int LayNamHienTai();


//===============================1
int LayNamHienTai(){
	time_t baygio = time(0);
	tm *ltime = localtime(&baygio);
	return (ltime->tm_year + 1900);
}
//===============================1
