//by us
#include "header\main_header.h"
time_t inittime(int* i) {

	struct tm t;
	t.tm_year = i[0] - 1900;   //�ⱹ �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	t.tm_mon = i[1] - 1;      //�ⱹ ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	t.tm_mday = i[2];         //�ⱹ ���� �Է�
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	return mktime(&t);                  //�ⱹ ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�
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
		switch (getchar())
		{
		case'n':
			cout << endl;
			cout << "-Departure process program end-" << endl;
			cout << "-----------------------------------------------" << endl;
			while (getchar() != '\n');
			return;
		case'y':
			break;
		default:
			cout << endl;
			cout << "error!! worng char keep process" << endl;
			cout << endl;
			break;
		}
		while (getchar() != '\n');
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
		switch (getchar())
		{
		case'n':
			cout << endl;
			cout << "-Departure process program end-" << endl;
			cout << "-----------------------------------------------" << endl;
			while (getchar() != '\n');
			return;
		case'y':
			break;
		default:
			cout << endl;
			cout << "error!! worng char keep process" << endl;
			cout << endl;
			break;
		}
		while (getchar() != '\n');
	}
}

void Airplainlist(FlightSchedule* fschedule[])
{
	int i = 0;

	cout << "��Leave Airline��" << endl;
	cout << setw(21) << "�� Airline ��" << setw(19) << "�� Destination ��" << setw(14) << "�� First ��" << setw(17) << "�� Bussiness ��" << setw(16) << "�� Economy ��" << setw(14) << "�� Time ��" << endl;
	for (i; i < 80; i++)
	{
		fschedule[i]->showthat();
	}
	cout << "\n��Entry Airline��" << endl;
	cout << setw(21) << "�� Airline ��" << setw(19) << "�� Destination ��" << setw(14) << "�� First ��" << setw(17) << "�� Bussiness ��" << setw(16) << "�� Economy ��" << setw(14) << "�� Time ��" << endl;
	for (i; i < 100; i++)
	{
		fschedule[i]->showthat();
	}
}

void Airlinemanagement(FlightSchedule* fschedule[], ControlTower &ct)
{
	for (int i = 0; i < 100; i++)
	{
		fschedule[i]->takeoff_check(ct);
	}
}

void Illegal_resident(Entrylist* blist[])
{
	for (int i = 0; i < 20; i++)
	{
		blist[i]->showyou();
		blist[i]->overEntrylist_check();
	}

}
// ���� �Լ� ����
