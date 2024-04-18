#include "SinhVien.h"

int main() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    wstring filename = L"File\\data-demo.csv";
    vector<SinhVien> data = readCSV(filename);

    for (const auto& sinhVien : data) {
        wcout << L"MSSV: " << sinhVien.MSSV << endl;
        wcout << L"Họ và tên: " << sinhVien.hoTen << endl;
        wcout << L"Khoa: " << sinhVien.khoa << endl;
        wcout << L"khoaTuyen: " << sinhVien.khoaTuyen << endl;
        wcout << L"ngaySinh: " << sinhVien.ngaySinh << endl;
        wcout << L"moTa: " << sinhVien.moTa << endl;
        wcout << L"amNhac: " << sinhVien.amNhac << endl;
        wcout << L"dienAnh: " << sinhVien.dienAnh << endl;
        wcout << L"---------------------------------" << endl;
    }

    return 0;
}

