// Airport Control System Main Function
// coding by Banetta Han Sang Kim

// a

#include "header\main_header.h"

// ���� �Լ� ����
void initUser();	//	User�� �Է¹޴� �Լ�

int main() {
	FlightSchedule fs;
	ControlTower ct;
	//initUser();	//	User �Է� �Լ�
	while (true)	//	Menu ����
	{
		// Menu ���
		cout << "=== Menu ===" << endl;
		cout << "e : Entry Process" << endl;	//	�Ա� ����
		cout << "l : Leave Process" << endl;	//	�ⱹ ����
		cout << "t : Ticketing" << endl;	// Ƽ�� �߱�
		cout << "o : OverEntryUser Check" << endl;	//	�ҹ� ü���� üũ
		cout << "q : Quit Program\n> ";	//	���α׷� ����
		switch (getchar())	//	menu switch�� : getchar()�� �̿�, ���ڸ� �޾Ƽ� ����
		{
		case 'e':	//	�Ա� ���� �޴�
			fs.takeoff_check(0,ct);
			break;
		case 'l':	//	�ⱹ ���� �޴�
			fs.takeoff_check(1,ct);
			break;
		case 't':	//	Ƽ�� �߱� �޴�

			break;
		case 'o':	//	�ҹ� ü���� üũ �޴�

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

//void initUser() {	//	User �Է� �Լ� �ùķ��̼��� ���� �ӽ÷� �Է������� ������������� ��ü ����
//	
//	User* user_list[10];	//	�ùķ��̼ǿ� �ʿ��� User 10�� ����
//	for (int i = 0; i < 9; i++)	//	User ���� �Է�
//	{
//		user_list[i] = new User("Kim", "23");	//	stack������ ���� ��������
//	}
//}