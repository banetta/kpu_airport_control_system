// Airport Control System Main Function
// coding by Banetta Han Sang Kim

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

//void createFlightSchedule(FlightSchedule* fschedule[]) {
//
//	string qairline;
//	string qdestination;
//	int qseat[3];
//	int qhour;
//	string qshit;
//	int qmin;
//	ifstream file;
//	int i = 0;
//	file.open("Leave_Airplane.txt", ios::in);
//
//	if (file.is_open() == false)
//	{
//		cout << "file is empty." << endl;
//		cout << file.is_open() << endl;
//	}
//	else
//	{
//		for (i = 0; !file.eof(); i++)
//		{
//			file >> qairline >> qdestination >> qseat[0] >> qseat[1] >> qseat[2] >> qhour >> qshit >> qmin;
//
//			fschedule[i] = new FlightSchedule(qairline, qdestination, qseat, qhour, qshit, qmin);
//		}
//	}
//	if (file.is_open() == true)
//	{
//		file.close();
//	}
//
//	file.open("Entry_Airplane.txt", ios::in);
//
//	if (file.is_open() == false)
//	{
//		cout << "file is empty." << endl;
//		cout << file.is_open() << endl;
//	}
//	else
//	{
//		for (i; !file.eof(); i++)
//		{
//			file >> qairline >> qdestination >> qseat[0] >> qseat[1] >> qseat[2] >> qhour >> qshit >> qmin;
//
//			fschedule[i] = new FlightSchedule(qairline, qdestination, qseat, qhour, qshit, qmin);
//		}
//	}
//	if (file.is_open() == true)
//	{
//		file.close();
//	}
//}

void leaveprocess(Leavelist* llist[])
{
	Blacklist bl;
	int j;
	for (int i = 0 ; i < 200; i++)
	{
		j = 0;
		cout << "-------------------------------" << endl;
		llist[i]->showyou();
		j = bl.reason_print(llist[i]->blacklist());
		if (j == 0)
		{
			llist[i]->banitem_check();
			cout << "-Departure process completed-" << endl;
		}
		cout << "-------------------------------" << endl;
	}
}

void leaveprocess(Entrylist* elist[])
{
	Blacklist bl;
	int j;
	for (int i = 0; i < 200; i++)
	{
		j = 0;
		cout << "-------------------------------" << endl;
		elist[i]->showyou();
		j = bl.reason_print(elist[i]->blacklist());
		if (j == 0)
		{
			elist[i]->banitem_check();
			TARIFF ta;
			ta.calcTariff(elist[i]);
			cout << "-Departure process completed-" << endl;
			
		}
		cout << "-------------------------------" << endl;
	}
}

int main() {

	//initUser();	//	User �Է� �Լ�
	//FlightSchedule* fs[100];
	//ControlTower ct;
	Entrylist* elist[200];
	Leavelist* llist[200];
	Entrylist* banlist[20];


	while (true)	//	Menu ����
	{
		// Menu ���
		cout << "=== Menu ===" << endl;
		cout << "e : Entry Process" << endl;	//	�Ա� ����
		cout << "l : Leave Process" << endl;	//	�ⱹ ����
		cout << "t : Today Airplain list" << endl;	// ���� ������ ���
		cout << "o : OverEntryUser Check" << endl;	//	�ҹ� ü���� üũ
		cout << "i : File Input" << endl;
		cout << "q : Quit Program" << endl;	//	���α׷� ����

		switch (getchar())	//	menu switch�� : getchar()�� �̿�, ���ڸ� �޾Ƽ� ����
		{
		case 'e':	//	�Ա� ���� �޴�
			leaveprocess(elist);
			break;
		case 'l':	//	�ⱹ ���� �޴�
			leaveprocess(llist);
			break;
		case 't':	//	���� ������ ���

			break;
		case 'o':	//	�ҹ� ü���� üũ �޴�
			break;

		case 'i':	//	�̿��� ���� ���� �Է� �޴�
			cout << "���� �װ��� ������ ������ �ҷ��ɴϴ�...." << endl;
			//createFlightSchedule(fs);
			cout << "���� �װ��� ������ ���� �ҷ����� �Ϸ�" << endl;
			cout << "�̿��� ������ �ҷ��ɴϴ�...." << endl;
			createUser(elist);
			createUser(llist);
			cout << "�̿��� ���� �ҷ����� �Ϸ�" << endl;
			break;
		case 'q':	//	���α׷� ���� �޴�
			cout << endl;
			cout << endl;
			cout << "end of program" << endl;
			return 0;	//	���α׷� ����
		default:	//	error ��� ��� (�޴� �߸� �Է½�)
			cout << endl;
			cout << "error!! worng char" << endl;
			cout << endl;
			break;
		}
		while (getchar() != '\n');	//	getchar()���� ���ۿ� �Է°��� ���Ƽ� ���߽����� �� �� �ֱ� ������ ���۸� ���� �۾��� �Ѵ�.
	}
	
}