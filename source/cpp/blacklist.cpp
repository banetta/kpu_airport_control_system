// Airport Control System
// coding by LimHS
#include "header\main_header.h"


int Blacklist::reason_print(int upass)
{
	switch (upass % 100)
	{
		case 0:
			cout << "Reason : �ҹ�ü�� ��� ����" << endl;
			reason = 1;
			return reason;
		case 1:
			cout << "Reason : ���Ա� ��� ����" << endl;
			reason = 1;
			return reason;
		case 2:
			cout << "Reason : �׷�����Ʈ �з�" << endl;
			reason = 1;
			return reason;
		case 3:
			cout << "Reason : �������� ������" << endl;
			reason = 1;
			return reason;
		default:
			cout << "������Ʈ �ش���� ����" << endl;
			reason = 0;
			return reason;
	}
}
