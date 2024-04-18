#include "WriteFile.h"

void WriteToHTMLFile() {
	wofstream fo("23120041.txt");
	fo << L"Lê Minh Hải nèeeee";
	fo.close();
}