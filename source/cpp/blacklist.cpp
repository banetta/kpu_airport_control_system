// Airport Control System
// coding by LimHS
#include "header\main_header.h"


int Blacklist::reason_print(int upass)
{
	int i;
	switch (upass % 100)
	{
		case 0:
			cout << "Reason : �ҹ�ü�� ��� ����" << endl;
			i = 1;
			return i;
		case 1:
			cout << "Reason : ���Ա� ��� ����" << endl;
			i = 1;
			return i;
		case 2:
			cout << "Reason : �׷�����Ʈ �з�" << endl;
			i = 1;
			return i;
		case 3:
			cout << "Reason : �������� ������" << endl;
			i = 1;
			return i;
		default:
			cout << "������Ʈ �ش���� ����" << endl;
			i = 0;
			return i;
	}
}
