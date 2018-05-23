//	RFID class functions
//	coding by Banetta

#include "header\main_header.h"

int RFID::RFID_buypick(int *entryday, int *leaveday) {	//	�� ��ȭ���� ����Ⱓ�� ������ ��ȭ������ üũ���ִ� Func

	//if (entryday[0] < buyday[0] && leaveday[0] > buyday[0])	//	����Ⱓ ���� == ���Գ�¥ ������ ���
	//{
	//	if (entryday[1] < buyday[1] && leaveday[1]>buyday[1])	//	����Ⱓ �� == ���Գ�¥ ���� ���
	//	{
	//		if (entryday[2]>buyday[2] && leaveday[2]<buyday[2])	//	����Ⱓ ���� != ���Գ�¥ ������ ���
	//		{
	//			return 0;	//	�ش� ��ǰ�� ����Ⱓ���� ������ ��ǰ�� �ƴ�
	//		}
	//		else if (entryday[2]<buyday[2] && leaveday[2]>buyday[2])	//	����Ⱓ ���� == ���Գ�¥ ������ ���
	//		{
	//			return price;	//	�� ��ǰ�� ����Ⱓ���� �����Ͽ���
	//		}
	//	}
	//}
	//else
	//{
	//	return 0;	//	�� �ܰ�� ���� pass
	//}
	struct tm t;						//�Ա� ��¥�� �ޱ� ���� ���̺귯�� ����ü
	time_t     tm_st;					//�Ա� ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_mm;
	time_t     tm_nd;					//���� ��¥�� �ޱ� ���� �ʴ��� ����
	double     d_diff;

	t.tm_year = leaveday[0] - 1900;	//���� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	t.tm_mon = leaveday[1] - 1;		//���� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	t.tm_mday = leaveday[2];			//���� ���� �Է�
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	tm_st = mktime(&t);						//�Ա� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�

	t.tm_year = entryday[0] - 1900;	//���� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	t.tm_mon = entryday[1] - 1;		//���� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	t.tm_mday = entryday[2];			//���� ���� �Է�
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	tm_nd = mktime(&t);						//�Ա� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�

	t.tm_year = buyday[0] - 1900;	//���� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	t.tm_mon = buyday[1] - 1;		//���� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	t.tm_mday = buyday[2];			//���� ���� �Է�
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	tm_mm = mktime(&t);						//�Ա� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�
	if (tm_st <= tm_mm <= tm_nd)
	{
		return price;
	}
	else
	{
		return 0;
	}



}