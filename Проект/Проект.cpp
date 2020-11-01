#include <iostream>
#include <Windows.h>
#include "Struct.h"
#include "program.h"
using namespace std;
int main()
{
	Program a;
	a.addReminder("aaalllo", 2020, 11,1,17,56);
	a.addReminder("drink", 2020, 11, 1, 17, 55);
	a.save();
	a.main();
	
}