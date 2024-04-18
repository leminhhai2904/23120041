#include "SinhVien.h"

vector<SinhVien> readCSV(const wstring& filename) {
    locale loc(locale(), new codecvt_utf8<wchar_t>);

    vector<SinhVien> sinhVien;
    wifstream file(filename);

    file.imbue(loc);

    if (!file.is_open()) {
        wcout << L"Không thể mở tệp " << filename << endl;
        return sinhVien;
    }

    wstring line;
    // getline(file, line); // Skip the header line

    while (getline(file, line)) {
        wstringstream ss(line);
        wstring MSSV, hoTen, khoa, khoaTuyen, ngaySinh, hinhAnh, moTa, amNhac, dienAnh;
        getline(ss, MSSV, L', ');
        getline(ss, hoTen, L',');
        getline(ss, khoa, L',');
        getline(ss, khoaTuyen, L',');
        getline(ss, ngaySinh, L',');
        getline(ss, hinhAnh, L',');
        getline(ss, moTa, L',');
        getline(ss, amNhac, L',');
        getline(ss, dienAnh, L'\n');

        // Xóa dấu ngoặc kép nếu có
        if (!MSSV.empty() && MSSV.front() == L'“' && MSSV.back() == L'”')
            MSSV = MSSV.substr(1, MSSV.size() - 2);
        if (!hoTen.empty() && hoTen.front() == L'“' && hoTen.back() == L'”')
            hoTen = hoTen.substr(1, hoTen.size() - 2);
        if (!khoa.empty() && khoa.front() == L'“' && khoa.back() == L'”')
            khoa = khoa.substr(1, khoa.size() - 2);
        if (!khoaTuyen.empty() && khoaTuyen.front() == L'“' && khoaTuyen.back() == L'”')
            khoaTuyen = khoaTuyen.substr(1, khoaTuyen.size() - 2);
        if (!ngaySinh.empty() && ngaySinh.front() == L'“' && ngaySinh.back() == L'”')
            ngaySinh = ngaySinh.substr(1, ngaySinh.size() - 2);
        if (!hinhAnh.empty() && hinhAnh.front() == L'“' && hinhAnh.back() == L'”')
            hinhAnh = hinhAnh.substr(1, hinhAnh.size() - 2);
        if (!moTa.empty() && moTa.front() == L'“' && moTa.back() == L'”')
            moTa = moTa.substr(1, moTa.size() - 2);
        if (!amNhac.empty() && amNhac.front() == L'“' && amNhac.back() == L'”')
            amNhac = amNhac.substr(1, amNhac.size() - 2);
        if (!dienAnh.empty() && dienAnh.front() == L'“' && dienAnh.back() == L'”')
            dienAnh = dienAnh.substr(1, dienAnh.size() - 2);

        SinhVien sv;
        sv.MSSV = MSSV;
        sv.hoTen = hoTen;
        sv.khoa = khoa;
        sv.khoaTuyen = khoaTuyen;
        sv.ngaySinh = ngaySinh;
        sv.hinhAnh = hinhAnh;
        sv.moTa = moTa;
        sv.amNhac = amNhac;
        sv.dienAnh = dienAnh;

        sinhVien.push_back(sv);
    }

    file.close();
    return sinhVien;
}
