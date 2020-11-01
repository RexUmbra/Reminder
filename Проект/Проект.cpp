#include <iostream>
#include <Windows.h>
#include "Struct.h"
#include "program.h"
using namespace std;
int main()
{
	
	Program a;
	wchar_t* b = new wchar_t[5];
	a.fromStringToWchar_t("aaaattw", b);

	MessageBox(NULL, (LPCWSTR)(b), (LPCWSTR)L"Reminder", MB_OK);
	//a.addReminder("aaalllo1", 2020, 11,1,17,56);
	//a.addReminder("drink", 2020, 11, 1, 17, 55);
	//a.save();
	//a.download();
	//a.main();
	
}