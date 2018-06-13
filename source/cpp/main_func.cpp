//by us
#include "header\main_header.h"
time_t inittime(int* i) {

	struct tm t;
	t.tm_year = i[0] - 1900;   //출국 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = i[1] - 1;      //출국 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = i[2];         //출국 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화
	return mktime(&t);                  //출국 날짜를 받은 구조체의 변수를 초단위 변수에 입력
}

void createUser(Entrylist* elist[]) {

	int fpassnum, fage, fentrtday[3], fleaveday[3];
	string fname, fregion, fseat;
	ifstream file;

	file.open("entry.txt", ios::in);

	if (file.is_open() == false)
	{
		cout << "file is empty." << endl;
		cout << file.is_open() << endl;
	}
	else
	{
		for (int i = 0; !file.eof(); i++)
		{
			file >> fpassnum >> fname >> fage >> fregion >> fseat >> fentrtday[0] >> fentrtday[1] >> fentrtday[2] >> fleaveday[0] >> fleaveday[1] >> fleaveday[2];

			elist[i] = new Entrylist(fpassnum, fname, fage, fregion, fseat, fentrtday, fleaveday);
		}
	}
	if (file.is_open() == true)
	{
		file.close();
	}
}

void createban(Entrylist* blist[]) {

	int fpassnum, fage, fentrtday[3], fleaveday[3];
	string fname, fregion, fseat;
	ifstream file;

	file.open("Illegal_resident.txt", ios::in);

	if (file.is_open() == false)
	{
		cout << "file is empty." << endl;
		cout << file.is_open() << endl;
	}
	else
	{
		for (int i = 0; !file.eof(); i++)
		{
			file >> fpassnum >> fname >> fage >> fregion >> fseat >> fentrtday[0] >> fentrtday[1] >> fentrtday[2] >> fleaveday[0] >> fleaveday[1] >> fleaveday[2];

			blist[i] = new Entrylist(fpassnum, fname, fage, fregion, fseat, fentrtday, fleaveday);
		}
	}
	if (file.is_open() == true)
	{
		file.close();
	}
}

void createUser(Leavelist* llist[]) {

	int fpassnum, fage, fentrtday[3], fleaveday[3];
	string fname, fregion, fseat;
	ifstream file;

	file.open("leave.txt", ios::in);

	if (file.is_open() == false)
	{
		cout << "file is empty." << endl;
	}
	else
	{
		for (int i = 0; !file.eof(); i++)
		{
			file >> fpassnum >> fname >> fage >> fregion >> fseat >> fentrtday[0] >> fentrtday[1] >> fentrtday[2] >> fleaveday[0] >> fleaveday[1] >> fleaveday[2];

			llist[i] = new Leavelist(fpassnum, fname, fage, fregion, fseat, fentrtday, fleaveday);
		}
	}
	if (file.is_open() == true)
	{
		file.close();
	}
}

void createFlightSchedule(FlightSchedule* fschedule[]) {

	string qairline;
	string qdestination;
	int qseat[3];
	int qhour;
	string qshit;
	int qmin;
	ifstream file;
	int i = 0;
	file.open("Leave_Airplane.txt", ios::in);

	if (file.is_open() == false)
	{
		cout << "file is empty." << endl;
		cout << file.is_open() << endl;
	}
	else
	{
		for (i = 0; !file.eof(); i++)
		{
			file >> qairline >> qdestination >> qseat[0] >> qseat[1] >> qseat[2] >> qhour >> qshit >> qmin;

			fschedule[i] = new FlightSchedule(qairline, qdestination, qseat, qhour, qshit, qmin);
		}
	}
	if (file.is_open() == true)
	{
		file.close();
	}

	file.open("Entry_Airplane.txt", ios::in);

	if (file.is_open() == false)
	{
		cout << "file is empty." << endl;
		cout << file.is_open() << endl;
	}
	else
	{
		for (i; !file.eof(); i++)
		{
			file >> qairline >> qdestination >> qseat[0] >> qseat[1] >> qseat[2] >> qhour >> qshit >> qmin;

			fschedule[i] = new FlightSchedule(qairline, qdestination, qseat, qhour, qshit, qmin);
		}
	}
	if (file.is_open() == true)
	{
		file.close();
	}
}

void leaveprocess(Leavelist* llist[])
{
	Blacklist bl;
	int j;
	char z;
	for (int i = 0; i < 200; i++)
	{
		j = 0;
		cout << "-----------------------------------------------" << endl;
		llist[i]->showyou();
		j = bl.reason_print(llist[i]->blacklist());
		if (j == 0)
		{
			llist[i]->banitem_check();
			cout << "-Departure process completed-" << endl;
		}
		cout << "-----------------------------------------------" << endl;

		cout << endl;
		cout << "Shall we proceed to the next person?	y/n" << endl;
		cout << "[Leave]:# ";
		switch (getchar())
		{
		case'n':
			while (getchar() != '\n');
			cout << endl;
			cout << "-Departure process program end-" << endl;
			cout << "-----------------------------------------------" << endl;
			return;
		case'y':
			while (getchar() != '\n');
			break;
		default:
			while (getchar() != '\n');
			cout << endl;
			cout << "error!! worng char keep process" << endl;
			cout << endl;
			break;
		}
	}
}

void leaveprocess(Entrylist* elist[])
{
	Blacklist bl;
	TARIFF ta;
	int j;
	for (int i = 0; i < 200; i++)
	{
		j = 0;
		cout << "-----------------------------------------------" << endl;
		elist[i]->showyou();
		j = bl.reason_print(elist[i]->blacklist());
		if (j == 0)
		{
			elist[i]->banitem_check();
			ta.Tariff_print(elist[i]);
			cout << "-Departure process completed-" << endl;

		}
		cout << "-----------------------------------------------" << endl;

		cout << endl;
		cout << "Shall we proceed to the next person?	y/n" << endl;
		cout << "[Entry]:# ";
		switch (getchar())
		{
		case'n':
			while (getchar() != '\n');
			cout << endl;
			cout << "-Departure process program end-" << endl;
			cout << "-----------------------------------------------" << endl;
			return;
		case'y':
			while (getchar() != '\n');
			break;
		default:
			while (getchar() != '\n');
			cout << endl;
			cout << "error!! worng char keep process" << endl;
			cout << endl;
			break;
		}
	}
}

void Airplainlist(FlightSchedule* fschedule[])
{
	int i = 0;
	while (true)
	{
		cout << "Choose Schedule:" << endl;
		cout << "L. 『Leave Airline』" << endl;
		cout << "E. 『Entry Airline』" << endl;
		cout << "Q. 『Quit』" << endl;
		cout << "[Schedule]:# ";
		switch (getchar())
		{
		case'l':
		case'L':
			while (getchar() != '\n');
			cout << "『Leave Airline』" << endl;
			cout << setw(21) << "【 Airline 】" << setw(19) << "【 Destination 】" << setw(14) << "【 First 】" << setw(17) << "【 Bussiness 】" << setw(16) << "【 Economy 】" << setw(14) << "【 Time 】" << endl;
			for (i = 0; i < 80; i++)
			{
				fschedule[i]->showthat();
			}
			break;
		case'e':
		case'E':
			while (getchar() != '\n');
			cout << "\n『Entry Airline』" << endl;
			cout << setw(21) << "【 Airline 】" << setw(19) << "【 Destination 】" << setw(14) << "【 First 】" << setw(17) << "【 Bussiness 】" << setw(16) << "【 Economy 】" << setw(14) << "【 Time 】" << endl;
			for (i = 80; i < 100; i++)
			{
				fschedule[i]->showthat();
			}
			break;
		case'q':
		case'Q':
			while (getchar() != '\n');
			cout << endl;
			cout << "Schedule Print end" << endl;
			cout << endl;
			return;
		default:
			while (getchar() != '\n');
			cout << endl;
			cout << "error!! worng char" << endl;
			cout << endl;
			break;
		}
	}
}

void Airlinemanagement(FlightSchedule* fschedule[], ControlTower &ct)
{
	cout << "-----------------------------------------------" << endl;
	for (int i = 0; i < 100; i++)
	{
		fschedule[i]->takeoff_check(ct);
	}
	cout << endl;
	cout << endl;
	cout << "-Airline Management process program end-" << endl;
	cout << "-----------------------------------------------" << endl;
}

void Illegal_resident(Entrylist* blist[])
{
	for (int i = 0; i < 20; i++)
	{
		cout << "-----------------------------------------------" << endl;
		blist[i]->showyou();
		blist[i]->overEntrylist_check();
		cout << "-----------------------------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "Shall we proceed to the next person?	y/n" << endl;
		cout << "[Illegal]:# ";
		switch (getchar())
		{
		case'n':
			while (getchar() != '\n');
			cout << endl;
			cout << "-Illegal Resident process program end-" << endl;
			cout << "-----------------------------------------------" << endl;
			return;
		case'y':
			while (getchar() != '\n');
			break;
		default:
			while (getchar() != '\n');
			cout << endl;
			cout << "error!! worng char keep process" << endl;
			cout << endl;
			break;
		}
	}
}