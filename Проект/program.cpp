#include "program.h"

Program::Program()
{
	amountReminder = 0;
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
	amountReminder++;
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
	//wstring temp = wstring(text.begin(), text.end());
	//text2 = temp.c_str();
	
	for (int i = 0; text[i]; i++)
	{
		if (text[i] == ' ')
		{
			text2[i] = ' ';
		}
		else
		{
			text2[i] == text[i];
		}
	}
	
	//CA2W text2(str.c_str(), CP_UTF8);
}

void Program::provZad()
{
	
	while (true)
	{
		if (vecZadani.size() && realDate.year == vecZadani[0].year && realDate.mon == vecZadani[0].mon && realDate.mday == vecZadani[0].mday && realDate.hour == vecZadani[0].hour && realDate.min == vecZadani[0].min)
		{
			wchar_t* textReminder = new wchar_t[vecZadani[0].textReminderWindow.length()-2];
			fromStringToWchar_t(vecZadani[0].textReminderWindow, textReminder);
			MessageBox(NULL, textReminder, (LPCWSTR)L"Reminder", MB_OK);
			vecZadani.erase(vecZadani.begin());
			amountReminder--;
		}
	}
	
}

void Program::main()
{
	cout << "Hi, welcome to program 'reminder', i can help you with your reminder or goal, same for convenience, I have a mini calendar) \n";
	system("PAUSE");
	thread();
	string ans;
	while (true)
	{
		system("CLS");
		cout << "if you wont add a remind write 'add remind' \n";
		cout << "if you wont upload all remind write 'download' \n";
		cout << "if you wont save and close program write 'save' \n";
		cout << "if you wont add goal write 'add goal' \n";
		cout << "if you wont use a calendar write 'calendar' \n";
		getline(cin,ans);
		if (ans == "add remind")
		{
			system("CLS");
			int year, mon, mday, hour, min;
			string remind;
			cout << "write year month day of month hour min and text remind (1963 11 22 12 00 put on a helmet)\n";
			cin >> year >> mon >> mday >> hour >> min;
			getline(cin, remind);
			addReminder(remind, year, mon, mday, hour, min);
		}
		if (ans == "download")
		{
			download();
		}
		if (ans == "save")
		{
			save();
			exit(0);
		}
		if (ans == "add goal")
		{
			system("CLS");
			cout << "purchase the pro version to gain access to the 'goal'";
		}
		if (ans == "calendar")
		{
			system("CLS");
			cout << "purchase the pro version to gain access to the 'calendar'";
		}
	}
	
	
}

void Program::save()
{
	ofstream fout("Save.txt");
	//fout.open("Save.txt");
	fout << amountReminder << '\n';
	for (int i = 0; i < vecZadani.size(); i++)
	{
		fout << vecZadani[i].year << ' ' << vecZadani[i].mon << ' ' << vecZadani[i].mday << ' ' << vecZadani[i].hour << ' ' << vecZadani[i].min << ' ' << vecZadani[i].textReminderWindow << '\n';
	}
	fout.close();

	amountReminder = 0;
}

void Program::download()
{
	ifstream fin("Save.txt");
	//fin.open("Save.txt");
	int year, mon, mday, hour, min;
	string textReminderWindow;
	fin >> amountReminder;
	//cout << amountReminder;
	for (int i = 0; i < amountReminder; i++)
	{
		//cout << i;
		fin >> year >>  mon >> mday >> hour >> min >> textReminderWindow;
		addReminder(textReminderWindow, year, min, mday, hour, min);
	}
	fin.close();
	//cout << vecZadani[0].min <<vecZadani[1].min ;

}

void Program::threadF()
{
	thread opredVremThread(&Program::opredVrem, this);
	opredVremThread.detach();
	thread opredDateThread(&Program::opredDate, this);
	opredDateThread.detach();
	thread provZadThread(&Program::provZad, this);
	provZadThread.detach();
}





