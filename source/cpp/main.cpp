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

int main() {

	//initUser();	//	User �Է� �Լ�
	FlightSchedule fs;
	ControlTower ct;
	Entrylist* elist[100];
	Leavelist* llist[100];

	while (true)	//	Menu ����
	{
		// Menu ���
		cout << "=== Menu ===" << endl;
		cout << "e : Entry Process" << endl;	//	�Ա� ����
		cout << "l : Leave Process" << endl;	//	�ⱹ ����
		cout << "t : Ticketing" << endl;	// Ƽ�� �߱�
		cout << "o : OverEntryUser Check" << endl;	//	�ҹ� ü���� üũ
		cout << "i : File Input" << endl;
		cout << "q : Quit Program" << endl;	//	���α׷� ����

		switch (getchar())	//	menu switch�� : getchar()�� �̿�, ���ڸ� �޾Ƽ� ����
		{
		case 'e':	//	�Ա� ���� �޴�
			fs.takeoff_check(0, ct);
			break;
		case 'l':	//	�ⱹ ���� �޴�
			fs.takeoff_check(1, ct);
			break;
		case 't':	//	Ƽ�� �߱� �޴�

			break;
		case 'o':	//	�ҹ� ü���� üũ �޴�

			break;

		case 'i':	//	�̿��� ���� ���� �Է� �޴�

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