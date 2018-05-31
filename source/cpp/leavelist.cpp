// Airport Control System
// coding by LimHS
#include "header\main_header.h"

Leavelist::Leavelist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday)
	: User(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday)
{
	for (int i = 0; i < 3; i++)
	{
		leavelist_eday[i] = userentryday[i];
		leavelist_lday[i] = userleaveday[i];
	}
	leavepack.isBanitem_init();
}

void Leavelist::banitem_check()
{
	int i = leavepack.sendban();
	switch (i)
	{
	case 0:	
		cout << "��ȭ�� �� ������ǰ ����" << endl;
		cout << "������ǰ ��� �Ϸ� ���" << endl;
			break;
	default:									
		cout << "��ȭ�� �� ������ǰ ���� ���" << endl;
		break;
	}
}