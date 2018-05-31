// Airport Control System
// coding by LimHS
#include "header\main_header.h"

Entrylist::Entrylist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday)
	: User(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday)
{
	for (int i = 0; i < 3; i++)
	{
		entrylist_eday[i] = userentryday[i];	//	�Ա����� �Է�
		entrylist_lday[i] = userleaveday[i];
	}
	
	int j = 0;	//	�Ա��� ��ȭ�� index ��ȣ ������ ���� ����
	for (int i = (rand() % 6); i < 5; i++)	//	�Ա����� ��ȭ�� ������ (5-i)��ŭ ������
	{
		entrypack[j] = new Entryitem;	//	�Ա��� ��ȭ�� ���� index ��ȣ�� �־��ְ� ++
		entrypack[j]->item_init();
		entrypack[(j + 1)] = NULL;
		j++;
	}
}

void Entrylist::banitem_check()
{
	int i = NULL;
	for (int j = 0; j < 5; j++)
	{
		if (entrypack[j] != NULL)
		{
			i = entrypack[j]->sendban();
			if (i == 0) {
				cout << "��ȭ�� �� ������ǰ ����" << endl;
				cout << "������ǰ ��� �Ϸ� ���" << endl;
			}
			else {
				cout << "��ȭ�� �� ������ǰ ���� ���" << endl;
			}
		}
	}
	
}

void Entrylist::overEntrylist_check()
{
	int lenghtofstay;					//ü���Ⱓ�� �޴� ����
	//struct tm t;						//�Ա� ��¥�� �ޱ� ���� ���̺귯�� ����ü
	time_t     tm_st;					//�Ա� ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_nd;					//���� ��¥�� �ޱ� ���� �ʴ��� ����
	double     d_diff;

	tm_st = inittime(entrylist_eday);	//	�Ա���¥�� �Է�

	//t.tm_year = entrylist_eday[0] - 1900;	//���� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	//t.tm_mon = entrylist_eday[1] - 1;		//���� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	//t.tm_mday = entrylist_eday[2];			//���� ���� �Է�
	//t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ

	//tm_st = mktime(&t);						//�Ա� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�
	time(&tm_nd);							//���� ��¥�� �ʴ��� ������ �Է�

	d_diff = difftime(tm_nd, tm_st);		//�Ա� ��¥���� ���� ��¥���� �ʴ��� ���̸� ���

	lenghtofstay = d_diff / (60 * 60 * 24); //�ʴ����� �ϴ����� ��ȯ �� ü���Ⱓ ������ �Է�

	cout << "Lenght of stay : " << lenghtofstay << endl; //�Ա����� ������� ü���Ⱓ ���
}

int Entrylist::passing_price() {

	int pay = NULL;
	for (int i = 0; entrypack[(i + 1)] == NULL; i++)
	{
			pay += entrypack[i]->passing_price(entrylist_eday, entrylist_lday);
		
	}
	
	return pay;

}