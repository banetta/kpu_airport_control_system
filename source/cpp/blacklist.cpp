// Airport Control System
// coding by LimHS
#include "header\main_header.h"

Blacklist::Blacklist(int usernum, int userreason) : blacknum(usernum)
{
	srand((int)time(NULL));									//�õ庰 �ٸ� ������ �������� ����
	reason = (((rand() % 8999) + 1000) * 10) + rand() % 10;	//������	1~7�ڸ��� �ް� ������ �ڸ��� 4~9�� ���� ���� ������ ������Ʈ

}

void Blacklist::reason_print(User *user)
{
	if (user->blacklist() == blacknum)
	{
		switch (reason % 10)
		{
		case 0:
			cout << "Reason : �ҹ�ü�� ��� ����" << endl;
			break;
		case 1:
			cout << "Reason : ���Ա� ��� ����" << endl;
			break;
		case 2:
			cout << "Reason : �׷�����Ʈ �з�" << endl;
			break;
		case 3:
			cout << "Reason : �������� ������" << endl;
			break;
		default:
			break;
		}
	}
	else
	{
		cout << "������Ʈ �ش���� ����" << endl;
	}

}
