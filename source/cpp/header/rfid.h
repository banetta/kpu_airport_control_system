// coding by Banetta

// #pragma once
#ifndef __RF_D_
#define __RF_D_

// main header include
#include "main_header.h"

class RFID
{
public:
	RFID() {};
	~RFID() {};
	int RFID_buypick(int *entryday, int *leaveday);	//	������ ������ ����ִ� �Լ�
	void RFID_init(int, int*);
	

private:
	int price;
	int buyday[3];
};

#endif // !__RF_D_
