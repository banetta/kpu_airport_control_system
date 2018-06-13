// Airport Control System
// coding by LimHS
#include "header\main_header.h"

Entrylist::Entrylist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday)
	: User(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday)
{
	isBanitem = rand() % 20;
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

int Entrylist::sendban() {
	return isBanitem;
}
void Entrylist::banitem_check()
{
	int i = NULL;
	for (int j = 0; j < 5; j++)
	{
		if (entrypack[j] != NULL)
		{
			i = sendban();
			if (i == 0) {
				cout << "��ȭ�� �� ������ǰ ����" << endl;
				cout << "������ǰ ��� �Ϸ� ���" << endl;
				break;
			}
			else  {
				cout << "��ȭ�� �� ������ǰ ���� ���" << endl;
				break;
			}
		}
	}
	
}

void Entrylist::overEntrylist_check()
{
	int lenghtofstay;					//ü���Ⱓ�� �޴� ����
	time_t     tm_st;					//�Ա� ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_nd;					//���� ��¥�� �ޱ� ���� �ʴ��� ����
	double     d_diff;

	tm_st = inittime(entrylist_eday);	//	�Ա���¥�� �Է�

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