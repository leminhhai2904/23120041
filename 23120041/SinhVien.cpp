#include "SinhVien.h"

void setStudentAttrByIndex(SinhVien& sv, int index, const wstring& value) {
    switch (index) {
    case 0:
        sv.MSSV = value;
        break;
    case 1:
        sv.hoTen = value;
        break;
    case 2:
        sv.khoa = value;
        break;
    case 3:
        sv.khoaTuyen = value;
        break;
    case 4:
        sv.ngaySinh = value;
        break;
    case 5:
        sv.hinhAnh = value;
        break;
    case 6:
        sv.moTa = value;
        break;
    case 7:
        sv.amNhac = value;
        break;
    case 8:
        sv.dienAnh = value;
        break;
    default:
        break;
    }
    if (index >= 7) {
        sv.soThich.push_back(value);
    }
}

int readStudentDataFromLine(const wstring& line, SinhVien& sv) {
    int attributeIndex = 0;// Index of the attribute in the line
    int stateMachine = 0;// State machine to determine the current state of the parser flow
    int flag = 0; // Flag
    wstring attributeBuffer = L"";// Value of the current attribute
    for (auto ptr = line.begin(); ptr < line.end(); ) { // [ATTENTION] We will control the increment manually
        wchar_t chr = *ptr;
        switch (stateMachine) {
        case 0:
        {
            if (chr == L'“' || chr == L'"') {
                flag = 1;
                stateMachine = 1;
            }
            else if (chr == L' ') {// [ATTENTION] Skip the space character
                // Do nothing
            }
            else {
                attributeBuffer += chr;
                stateMachine = 1;
                flag = 0;// [ATTENTION] Set flag to 0 (Flag maybe be 1 in the previous loop)
            }
            ptr++;
        }
        break;
        case 1:
        {
            if ((chr == L'”' || chr == L'"') && flag == 1) {
                stateMachine = 2;
            }
            else if ((chr == L',' || chr == L'\n') && flag == 0) {
                stateMachine = 3;
            }
            else {
                attributeBuffer += chr;
            }
            ptr++;
        }
        break;
        case 2:
        {
            if (chr == L',' || chr == L'\n') {
                stateMachine = 3;
            }
            ptr++;
        }
        break;
        case 3:
        {
            setStudentAttrByIndex(sv, attributeIndex, attributeBuffer);
            stateMachine = 0;
            attributeIndex++;
            attributeBuffer = L"";
            // [ATTENTION] At this step, we just set the attribute to variable, so we should not increment the pointer
        }
        break;
        }
    }

    // [ATTENTION] We should set the last attribute after the loop
    if (attributeBuffer.size() > 0) {
        setStudentAttrByIndex(sv, attributeIndex, attributeBuffer);
        attributeIndex++;
        attributeBuffer = L"";
    }

    return attributeIndex;
}

vector<SinhVien> readStudentListFromCSV(const wstring& filename) {
    locale loc(locale(), new codecvt_utf8<wchar_t>);

    vector<SinhVien> sinhVien;
    wifstream file(filename);

    file.imbue(loc);

    if (!file.is_open()) {
        wcout << L"Không thể mở tệp " << filename << endl;
        return sinhVien;
    }

    wstring line;
    while (getline(file, line)) {
        SinhVien sv;

        if (readStudentDataFromLine(line, sv))
            sinhVien.push_back(sv);
    }

    file.close();
    return sinhVien;
}
