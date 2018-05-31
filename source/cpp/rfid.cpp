//	RFID class functions
//	coding by Banetta

#include "header\main_header.h"

void RFID::RFID_init(int a, int* b) {

	price = a;
	for (int i = 0; i < 3; i++)
	{
		buyday[i] = b[i];
	}

}

int RFID::RFID_buypick(int *entryday, int *leaveday) {	

	//struct tm t;                  //��¥�� �ޱ� ���� ���̺귯�� ����ü
	time_t     tm_st;               //�ⱹ ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_mm;               //���� ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_nd;               //�Ա� ��¥�� �ޱ� ���� �ʴ��� ����

	tm_st = inittime(leaveday);	//	�ⱹ��¥ �Է�
	tm_mm = inittime(entryday);	//	�Ա���¥ �Է�
	tm_nd = inittime(buyday);	//	���ų�¥ �Է�

	//t.tm_year = leaveday[0] - 1900;   //�ⱹ �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	//t.tm_mon = leaveday[1] - 1;      //�ⱹ ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	//t.tm_mday = leaveday[2];         //�ⱹ ���� �Է�
	//t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	//tm_st = mktime(&t);                  //�ⱹ ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�

	//t.tm_year = entryday[0] - 1900;   //�Ա� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	//t.tm_mon = entryday[1] - 1;      //�Ա� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	//t.tm_mday = entryday[2];         //�Ա� ���� �Է�
	//t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	//tm_nd = mktime(&t);                  //�Ա� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�

	//t.tm_year = buyday[0] - 1900;   //���� �⵵�� �Է�, �Լ� Ư���� ������ -1900�� �ؾ���
	//t.tm_mon = buyday[1] - 1;      //���� ���� �Է�, �Լ� Ư���� ���� -1�� �ؾ���
	//t.tm_mday = buyday[2];         //���� ���� �Է�
	//t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //�������� ��� 0���� �ʱ�ȭ
	//tm_mm = mktime(&t);                  //���� ��¥�� ���� ����ü�� ������ �ʴ��� ������ �Է�


	if (tm_st <= tm_mm <= tm_nd) { //�ⱹ ��¥�� �Ա� ��¥ ���̿� ���� ��¥�� ������ ��� ��ǰ�� ������ ��ȯ�Ѵ�.
		return price; 
	} 
	else { 
		return 0; 
	}
}
