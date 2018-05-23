// Airport Control System
// coding by LimHS
#include "header\main_header.h"

LeaveList::LeaveList(int userpassnum, string username, int userage, string userregion, int leaveyear, int leavemonth, int leaveday)
	: User(userpassnum, username, userage, userregion)
{
	leavelist_day[0] = leaveyear;	//�ⱹ�� �Է�
	leavelist_day[1] = leavemonth;	//�ⱹ�� �Է�
	leavelist_day[2] = leaveday;	//�ⱹ�� �Է�
}

void LeaveList::banitem_check(int isBanitem)
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