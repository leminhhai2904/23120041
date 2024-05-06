#include "menu.h"

void Menu() {
	wcout << L"CHƯƠNG TRÌNH TẠO WEBSITE CHO SINH VIÊN\n\n";
        wcout << L"=================MENU================\n"
            << L"1. Chọn template cho trang web\n"
            << L"2. In danh sách sinh viên ra màn hình\n"
            << L"3. Phát sinh website sinh viên\n"
            << L"4. Xóa màn hình hiện tại\n"
            << L"0. Thoát chương trình\n\n"
            << "=====================================\n";
}
int ChonMenu()
{
	int n = 0;
	wcout << L"\nLựa chọn của bạn là: ";
	wcin >> n;
	if (n >= 0 || n <= 4)
		return n;
	else return ChonMenu();
}