// Airport Control System Main Function
// coding by Banetta Han Sang Kim

#include "header\main_header.h"

int main() {

	FlightSchedule* fs[100];
	ControlTower ct;
	Entrylist* elist[200];
	Leavelist* llist[200];
	Entrylist* banlist[20];


	while (true)	//	Menu ����
	{
		// Menu ���
		cout << "=== Menu ===" << endl;
		cout << "i : File Input" << endl;
		cout << "e : Entry Process" << endl;	//	�Ա� ����
		cout << "l : Leave Process" << endl;	//	�ⱹ ����
		cout << "t : Today Airplain list" << endl;	// ���� ������ ���
		cout << "a : Airplain Access Management" << endl;	// �װ��� ������ ����
		cout << "o : OverEntryUser Check" << endl;	//	�ҹ� ü���� üũ
		cout << "q : Quit Program" << endl;	//	���α׷� ����

		switch (getchar())	//	menu switch�� : getchar()�� �̿�, ���ڸ� �޾Ƽ� ����
		{
		case 'i':	//	�̿��� ���� ���� �Է� �޴�
			cout << "���� �װ��� ������ ������ �ҷ��ɴϴ�";
			createFlightSchedule(fs);
			Sleep(400); cout << '.';  Sleep(400); cout << '.'; Sleep(400); cout << '.'; Sleep(400); cout << '.' << endl;
			Sleep(400);
			cout << "���� �װ��� ������ ���� �ҷ����� �Ϸ�" << endl;
			Sleep(200);
			cout << "�̿��� ������ �ҷ��ɴϴ�";
			createUser(elist);
			createUser(llist);
			createban(banlist);
			Sleep(400); cout << '.';  Sleep(400); cout << '.'; Sleep(400); cout << '.'; Sleep(400); cout << '.' << endl;
			Sleep(200);
			cout << "�̿��� ���� �ҷ����� �Ϸ�" << endl;
			Sleep(200);
			break;
		case 'e':	//	�Ա� ���� �޴�
			while (getchar() != '\n');
			leaveprocess(elist);
			break;
		case 'l':	//	�ⱹ ���� �޴�
			while (getchar() != '\n');
			leaveprocess(llist);
			break;
		case 't':	//	���� ������ ���
			while (getchar() != '\n');
			Airplainlist(fs);
			break;
		case 'a':	//	����� ������ ���� �޴�
			while (getchar() != '\n');
			Airlinemanagement(fs, ct);
			break;
		case 'o':	//	�ҹ� ü���� üũ �޴�
			while (getchar() != '\n');
			Illegal_resident(banlist);
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