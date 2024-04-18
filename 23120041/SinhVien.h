#ifndef _SinhVien_H_
#define _SinhVien_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <fstream>
#include <locale>
#include <Windows.h>
#include <codecvt>


using namespace std;

struct SinhVien {
	wstring MSSV;
	wstring hoTen;
	wstring khoa;
	wstring khoaTuyen;
	wstring ngaySinh;
	wstring hinhAnh;
	wstring moTa;
	wstring amNhac;
	wstring dienAnh;
};

vector<SinhVien> readCSV(const wstring& filename);

#endif 

// C:\\Users\\Phuoc\\Documents\\23120041\\23120041\\File\\data.csv