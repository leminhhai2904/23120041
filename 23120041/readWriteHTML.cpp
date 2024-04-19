#include "SinhVien.h"
#include "readWriteHTML.h"

wstring setStudentAttrByTypeData(const wstring& typeData, const SinhVien& sv) {
    if (!(typeData.compare(L"MSSV")))
        return sv.MSSV;
    if (!(typeData.compare(L"hoTen")))
        return sv.hoTen;
    if (!(typeData.compare(L"khoa")))
        return sv.khoa;
    if (!(typeData.compare(L"khoaTuyen")))
        return sv.khoaTuyen;
    if (!(typeData.compare(L"ngaySinh")))
        return sv.ngaySinh;
    if (!(typeData.compare(L"hinhAnh")))
        return sv.hinhAnh;
    if (!(typeData.compare(L"moTa")))
        return sv.moTa;
    if (!(typeData.compare(L"soThich"))) {
        return L"SOTHICH";

    }
}

wstring writeHTMLFromLine(const wstring& line, const SinhVien& sv) {
    int stateMachine = 0;
    wstring attributeBuffer = L"";
    wstring typeData = L"";
    for (auto ptr = line.begin(); ptr < line.end(); ) {
        wchar_t chr = *ptr;
        switch (stateMachine) {
        case 0:
        {
            if (chr == L'{') {
                stateMachine = 1;
            }
            else if (chr == L'\n') {
                attributeBuffer += chr;
                stateMachine = 4;
            }
            else {
                attributeBuffer += chr;
            }
            ptr++;
        }
        break;
        case 1:
        {
            if (chr == L'{') {
                stateMachine = 2;
            }
            ptr++;
        }
        break;
        case 2:
        {
            if (chr == L'}') {
                stateMachine = 3;
            }
            else {
                typeData += chr;
            }
            ptr++;
        }
        break;
        case 3:
        {
            attributeBuffer.append(setStudentAttrByTypeData(typeData, sv));
            stateMachine = 0;
            typeData = L"";
            ptr++;
        }
        break;
        case 4:
        {
            return attributeBuffer;
        }
        break;
        }
    }

    // [ATTENTION] We should set the last attribute after the loop
    if (attributeBuffer.size() > 0) {
        return attributeBuffer;
    }
}

void readFileTemplate(const SinhVien& sv) {
    wstring filename_html = L"File\\";
    filename_html.append(sv.MSSV);
    filename_html += L".html";
    wofstream file_html(filename_html);

    locale loc(locale(), new codecvt_utf8<wchar_t>);
    wstring filename_template = L"File\\template.html";
    wifstream file_template(filename_template);
    file_template.imbue(loc);

    if (!file_template.is_open()) {
        wcout << L"Không thể mở tệp " << filename_template << endl;
        return;
    }

    wstring line;
    while (getline(file_template, line)) {
        wstring HTMLLine = L"";
        HTMLLine.append(writeHTMLFromLine(line, sv));
        wcout << HTMLLine << endl;
        file_html << HTMLLine << endl;
    }

    file_template.close();
    file_html.close();
}