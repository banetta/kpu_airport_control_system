// Airport Control System
// coding by LimHS
#include "header\main_header.h"

Leavelist::Leavelist()
{
}

Leavelist::Leavelist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday, int leavebanitem)
	: User(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday), leavepack(leavebanitem)
{
	for (int i = 0; i < 3; i++)
	{
		leavelist_eday[i] = userentryday[i];
		leavelist_lday[i] = userleaveday[i];
	}
}

void Leavelist::banitem_check(int isBanitem)
{
	switch (isBanitem)
	{
	case 1:											//��ȭ�� ���� ������ǰ�� ���� ��� isBanitem�� 1�� �� 
		cout << "��ȭ�� �� ������ǰ ���� ���";
		break;
	case 0:											//��ȭ�� ���� ������ǰ�� ���� ��� isBanitem�� 0�� �� 
		cout << "��ȭ�� �� ������ǰ ����" << endl;
		cout << endl;
		cout << endl;
		cout << "������ǰ ��� �Ϸ� ���" << endl;
		break;
	default:										//Ȥ�� ������ ���� �ٸ� ���� ���� ���
		cout << "��ȭ�� �˻� ����" << endl;
		break;
	}
}