#include "menu.h"
#include "SinhVien.h"
#include "readWriteHTML.h"

int main() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    wstring filename_data = L"Websites\\Sources\\data.csv";
    wstring filename_template = L"Websites\\Sources\\Templates\\template";
    vector<SinhVien> data = readStudentListFromCSV(filename_data);
    
    while (true)
    {
        Menu();
        int chon = ChonMenu();
        switch (chon) {
        case 1:
        {
            ChooseHTMLTemplate(filename_template);
        }
        break;
        case 2:
        {
            PrintListStudents(data);
        }
        break;
        case 3:
        {
            WriteWebsite(data, filename_template);
        }
        break;
        case 4:
        {
            system("cls");
        }
        break;
        case 0:
        {
            wcout << L"Bạn đã thoát chương trình thành công!\n";
            return 0;
        }
        break;
        default:
        {
            wcout << L"Lựa chọn của bạn không hợp lệ!!\n"
                << L"Bạn hãy vui lòng chọn lại!\n";
        }
        break;
        }
    }
    return 0;
}
