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
}

bool readStudentDataFromLine(const wstring& line, SinhVien& sv) {
    int attributeIndex = 0;// Index of the attribute in the line
    int stateMachine = 0;// State machine to determine the current state of the parser flow
    int flag = 0; // Flag
    wstring attributeBuffer = L"";// Value of the current attribute
    for (const wchar_t& chr : line) {
        switch (stateMachine) {
            case STATE_MACHINE_0_NAME:
            {
                if (chr == '“' || chr == '"') {
                    flag = 1;
                    stateMachine = 1;
                }
                else {
                    attributeBuffer += chr;
                    stateMachine = 1;

                }
            }
            break;
            case 1:
            {
                if (chr == '”' && flag == 1) {
                    stateMachine = 2;
                } else if ((chr == ',' || chr == '\n') && flag == 0) {
                    stateMachine = 3;
                }
                else {
                    attributeBuffer += chr;
                }
            }
            break;
            case 2:
            {
                if (chr == ',' || chr == '\n') {
                    stateMachine = 3;
                }
            }
            break;
            case 3:
            {
                setStudentAttrByIndex(sv, attributeIndex, attributeBuffer);
                stateMachine = 0;
                attributeIndex++;
                attributeBuffer = L"";
            }
            break;
        }
    }
    return true;
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
