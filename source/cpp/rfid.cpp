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

	time_t     tm_st;               //�ⱹ ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_mm;               //���� ��¥�� �ޱ� ���� �ʴ��� ����
	time_t     tm_nd;               //�Ա� ��¥�� �ޱ� ���� �ʴ��� ����

	tm_st = inittime(leaveday);	//	�ⱹ��¥ �Է�
	tm_mm = inittime(entryday);	//	�Ա���¥ �Է�
	tm_nd = inittime(buyday);	//	���ų�¥ �Է�

	if (tm_st <= tm_mm <= tm_nd) { //�ⱹ ��¥�� �Ա� ��¥ ���̿� ���� ��¥�� ������ ��� ��ǰ�� ������ ��ȯ�Ѵ�.
		return price; 
	} 
	else { 
		return 0; 
	}
}
