//	RFID class functions
//	coding by Banetta

#include "header\main_header.h"

int RFID::RFID_buypick(int *entryday, int *leaveday) {	//	�� ��ȭ���� ����Ⱓ�� ������ ��ȭ������ üũ���ִ� Func

	struct tm t;						//��¥�� �ޱ� ���� ���̺귯�� ����ü
	time_t     tm_st;					//�ⱹ ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_mm;					//���� ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_nd;					//�Ա� ��¥�� �ޱ� ���� �ʴ��� ����
	double     d_diff;

	t.tm_year = leaveday[0] - 1900;	//�ⱹ �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	t.tm_mon = leaveday[1] - 1;		//�ⱹ ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	t.tm_mday = leaveday[2];			//�ⱹ ���� �Է�
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	tm_st = mktime(&t);						//�ⱹ ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�

	t.tm_year = entryday[0] - 1900;	//�Ա� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	t.tm_mon = entryday[1] - 1;		//�Ա� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	t.tm_mday = entryday[2];			//�Ա� ���� �Է�
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	tm_nd = mktime(&t);						//�Ա� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�

	t.tm_year = buyday[0] - 1900;	//���� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	t.tm_mon = buyday[1] - 1;		//���� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	t.tm_mday = buyday[2];			//���� ���� �Է�
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	tm_mm = mktime(&t);						//���� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�
	if (tm_st <= tm_mm <= tm_nd)	{return price;} //�ⱹ ��¥�� �Ա� ��¥ ���̿� ���� ��¥�� ������ ��� ��ǰ�� ������ ��ȯ�Ѵ�.
	else {return 0;}
}