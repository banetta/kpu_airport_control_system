// Airport Control System
// coding by LimHS
#include "header\main_header.h"

EntryList::EntryList(int userpassnum, string username, int userage, string userregion, int entryyear, int entrymonth, int entryday)
	: User(userpassnum, username, userage, userregion)
{
	entrylist_day[0] = entryyear;	//�Ա��� �Է�
	entrylist_day[1] = entrymonth;	//�Ա��� �Է�
	entrylist_day[2] = entryday;	//�Ա��� �Է�
}

void EntryList::banitem_check(int isBanitem)
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

void EntryList::overEntrylist_check()
{
	int lenghtofstay;					//ü���Ⱓ�� �޴� ����
	struct tm t;						//�Ա� ��¥�� �ޱ� ���� ���̺귯�� ����ü
	time_t     tm_st;					//�Ա� ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_nd;					//���� ��¥�� �ޱ� ���� �ʴ��� ����
	double     d_diff;

	t.tm_year = entrylist_day[0] - 1900;	//���� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	t.tm_mon = entrylist_day[1] - 1;		//���� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	t.tm_mday = entrylist_day[2];			//���� ���� �Է�
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ

	tm_st = mktime(&t);						//�Ա� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�
	time(&tm_nd);							//���� ��¥�� �ʴ��� ������ �Է�

	d_diff = difftime(tm_nd, tm_st);		//�Ա� ��¥���� ���� ��¥���� �ʴ��� ���̸� ���

	lenghtofstay = d_diff / (60 * 60 * 24); //�ʴ����� �ϴ����� ��ȯ �� ü���Ⱓ ������ �Է�

	cout << "Lenght of stay : " << lenghtofstay << endl; //�Ա����� ������� ü���Ⱓ ���
}