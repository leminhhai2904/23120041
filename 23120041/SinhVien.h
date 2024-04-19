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

#define STATE_MACHINE_0_NAME 0

using namespace std;

struct SinhVien {
	wstring MSSV = L"";
	wstring hoTen = L"";
	wstring khoa = L"";
	wstring khoaTuyen = L"";
	wstring ngaySinh = L"";
	wstring hinhAnh = L"";
	wstring moTa = L"";
	wstring amNhac = L"";
	wstring dienAnh = L"";
	vector<wstring> soThich;
};

void setStudentAttrByIndex(SinhVien& sv, int index, const wstring& value);
int readStudentDataFromLine(const wstring& line, SinhVien& sv);
vector<SinhVien> readStudentListFromCSV(const wstring& filename);

#endif 