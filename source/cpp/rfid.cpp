//	RFID class functions
//	coding by Banetta
//

#include "header\main_header.h"

int RFID::RFID_amount(User* user) {

	return RFID_buypick();
	
}

int RFID::RFID_buypick(int *entryday, int *leaveday) {	//	�� ��ȭ���� ����Ⱓ�� ������ ��ȭ������ üũ���ִ� Func

	if (entryday[0] < buyday[0] && leaveday[0] > buyday[0])	//	����Ⱓ ���� == ���Գ�¥ ������ ���
	{
		if (entryday[1] < buyday[1] && leaveday[1]>buyday[1])	//	����Ⱓ �� == ���Գ�¥ ���� ���
		{
			if (entryday[2]>buyday[2] && leaveday[2]<buyday[2])	//	����Ⱓ ���� != ���Գ�¥ ������ ���
			{
				return 0;	//	�ش� ��ǰ�� ����Ⱓ���� ������ ��ǰ�� �ƴ�
			}
			else if (entryday[2]<buyday[2] && leaveday[2]>buyday[2])	//	����Ⱓ ���� == ���Գ�¥ ������ ���
			{
				return 1;	//	�� ��ǰ�� ����Ⱓ���� �����Ͽ���
			}
		}
	}
	else
	{
		return 0;	//	�� �ܰ�� ���� pass
	}
}