#include "program.h"

Program::Program()
{
	/*
	
	*/
}

void Program::opredVrem()
{
	
	while (true)
	{
		realTimeSec = time(NULL);
	}
}

void Program::opredDate()
{
	while (true)
	{	
		_localtime64_s(realDateTm, &realTimeSec);
		realDate.year = realDateTm->tm_year + 1900;
		realDate.mon = realDateTm->tm_mon + 1;
		realDate.mday = realDateTm->tm_mday;
		realDate.hour = realDateTm->tm_hour;
		realDate.min = realDateTm->tm_min;
		Sleep(10000);
		
	}
	
}

void Program::addReminder(string textReminder, int year, int mon, int mday, int hour, int min)
{
	//cout << 3;
	dateStruct dateReminder;
	dateReminder.textReminderWindow = textReminder;
	dateReminder.year = year;
	dateReminder.mon = mon;
	dateReminder.mday = mday;
	dateReminder.hour = hour;
	dateReminder.min = min;
	vecZadani.push_back(dateReminder);
	sortVecZadani();
}

void Program::sortVecZadani()
{
	for (int i = 0; i < vecZadani.size() - 1; i++)
	{
		for (int j = 0; j < vecZadani.size() - i - 1; j++)
		{
			if (vecZadani[j].year > vecZadani[j + 1].year)
			{
				swap(vecZadani[j], vecZadani[j + 1]);
			}
			else if (vecZadani[j].year == vecZadani[j + 1].year)
			{
				if (vecZadani[j].mon > vecZadani[j + 1].mon)
				{
					swap(vecZadani[j], vecZadani[j + 1]);
				}
				else if (vecZadani[j].mon == vecZadani[j + 1].mon)
				{
					if (vecZadani[j].mday > vecZadani[j + 1].mday)
					{
						swap(vecZadani[j], vecZadani[j + 1]);
					}
					else if (vecZadani[j].mday == vecZadani[j + 1].mday)
					{
						if (vecZadani[j].hour > vecZadani[j + 1].hour)
						{
							swap(vecZadani[j], vecZadani[j + 1]);
						}
						else if (vecZadani[j].hour == vecZadani[j + 1].hour)
						{
							if (vecZadani[j].min > vecZadani[j + 1].min)
							{
								swap(vecZadani[j], vecZadani[j + 1]);
							}
						}
					}
				}
			}
		}
	}
}

void Program::fromStringToWchar_t(string text, wchar_t* text2)
{
	for (int i = 0; text[i]; i++)
	{
		text2[i] = text[i];
	}
}

void Program::provZad()
{
	
	while (true)
	{
		if (realDate.year == vecZadani[0].year && realDate.mon == vecZadani[0].mon && realDate.mday == vecZadani[0].mday && realDate.hour == vecZadani[0].hour && realDate.min == vecZadani[0].min)
		{
			wchar_t* textReminder = new wchar_t[vecZadani[0].textReminderWindow.length()];
			fromStringToWchar_t(vecZadani[0].textReminderWindow, textReminder);
			MessageBox(NULL, textReminder, (LPCWSTR)L"Reminder", MB_OK);
			vecZadani.erase(vecZadani.begin());
		}
	}
	
}

void Program::main()
{
	thread opredVremThread(&Program::opredVrem, this);
	opredVremThread.detach();
	thread opredDateThread(&Program::opredDate, this);
	opredDateThread.detach();
	thread provZadThread(&Program::provZad, this);
	provZadThread.detach();
}

void Program::save()
{
	ofstream fout("Save.txt");
	for (int i = 0; i < vecZadani.size(); i++)
	{
		fout << vecZadani[i].year << ' ' << vecZadani[i].mon << ' ' << vecZadani[i].mday << ' ' << vecZadani[i].hour << ' ' << vecZadani[i].min << ' ' << vecZadani[i].textReminderWindow << '\n';
	}
	fout.close();
}





