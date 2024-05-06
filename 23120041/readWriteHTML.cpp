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
        wstring SOTHICH = L"";
        for (const auto& soThich : sv.soThich) {
            SOTHICH += L"<li>";
            SOTHICH += soThich;
            SOTHICH += L"</li>";
            SOTHICH += L"\n";
        }
        return SOTHICH;
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

void readFileTemplate(const SinhVien& sv, wstring filename_template) {
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    // Đặt tên file html
    wstring filename_html = L"Websites\\";
    filename_html.append(sv.MSSV);
    filename_html += L".html";
    wofstream file_html(filename_html);
    file_html.imbue(loc);
    // Đặt tên file template
    filename_template += L".html";
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
        // wcout << HTMLLine << endl;
        file_html << HTMLLine << endl;
    }

    file_template.close();
    file_html.close();
}

void WriteWebsite(vector<SinhVien> data, wstring filename_template) {
    int choice = -1;
    wcout << L"Bạn muốn tạo bao nhiêu website sinh viên?\n"
        << L"1. Tất cả sinh viên\n"
        << L"2. Một hoặc một vài sinh viên\n"
        << L"0. Không tạo website\n"
        << L"Lựa chọn của bạn là: ";
    wcin >> choice;
    switch (choice) {
    case 1:
    {
        wcout << L"Tạo website cho tất cả các sinh viên\n";
        for (const auto& sinhVien : data) {
            readFileTemplate(sinhVien, filename_template);
        }
    }
    break;
    case 2:
    {
        int n;
        wcout << L"Số lượng sinh viên bạn muốn tạo: ";
        wcin >> n;
        if (n == 1) {
            wcout << L"Nhập số thứ tự của sinh viên muốn tạo: ";
        }
        else {
            wcout << L"Nhập số thứ tự của các sinh viên muốn tạo: ";
        }
        int* doWriteHTML = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            wcin >> doWriteHTML[i];
        }
        int index = 1;
        for (const auto& sinhVien : data) {
            for (int i = 1; i <= n; i++) {
                if (index == doWriteHTML[i]) {
                    readFileTemplate(sinhVien, filename_template);
                }
            }
            index++;
        }
        if (n == 1) {
            wcout << L"Đã tạo website của sinh viên trên\n";
        }
        else {
            wcout << L"Đã tạo website của các sinh viên trên\n";
        }
        wcout << L"Lưu ý: STT của sinh viên không có trong danh sách thì sẽ không tạo\n";
    }
    break;
    case 0:
    {
        wcout << L"Không tạo website cho sinh viên\n";
    }
    break;
    default:
    {
        wcout << L"Lựa chọn của bạn không hợp lệ!!\n";
    }
    break;
    }
    wcout << L"-------------------------------------\n";
}

void ChooseHTMLTemplate(wstring& filename_template) {
    filename_template = L"Websites\\Sources\\Templates\\template";
    wcout << L"Danh sách template HTML:\n"
        << L"0. Template mặc định\n"
        << L"1. Template hiện đại\n"
        << L"Lựa chọn của bạn là: ";
        int choice = -1;
    wcin >> choice;
    switch (choice) {
    case 0:
    {
        wcout << L"Bạn đã chọn thành công template mặc định\n";
    }
    break;
    case 1:
    {
        wcout << L"Bạn đã chọn thành công template hiện đại\n";
        filename_template += L"_hiendai";
    }
    break;
    default:
    {
        wcout << L"Lựa chon của bạn không hợp lệ!!\n";
        wcout << L"Hệ thống tự chọn template mặc định\n";
    }
    break;
    }
    wcout << L"-------------------------------------\n";
}