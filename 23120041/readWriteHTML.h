#ifndef _READWRITEHTML_H_
#define _READWRITEHTML_H_

#include "SinhVien.h"

void readFileTemplate(const SinhVien& sv, wstring filename_template);
wstring setStudentAttrByTypeData(const wstring& typeData, const SinhVien& sv);
wstring writeHTMLFromLine(const wstring& line, const SinhVien& sv);
void WriteWebsite(vector<SinhVien> data, wstring filename_template);
void ChooseHTMLTemplate(wstring &filename_template);

#endif // !_READWRITEHTML_H_
