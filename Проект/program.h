#pragma once
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <Windows.h>
#include <time.h>
#include <stddef.h>
#include <stdio.h>
#include <ctime>
#include <vector>
#include <thread>
#include <fstream>
#include "Struct.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Program
{
private:
	vector<dateStruct> vecZadani;
	time_t realTimeSec;
	tm* realDateTm = new tm;
	dateStruct realDate;
public:
	Program();
	void opredVrem();
	void opredDate();
	void addReminder(string textReminder, int year,int mon,int mday, int hour, int min);
	void sortVecZadani();
	void fromStringToWchar_t(string text, wchar_t *text2);
	void provZad();
	void main();
	void save();


};

