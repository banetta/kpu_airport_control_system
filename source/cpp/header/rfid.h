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
	RFID(int, int*);
	int RFID_buypick(int *entryday, int *leaveday);	//	������ ������ ����ִ� �Լ�

private:
	int price;
	int buyday[3];
};

RFID::RFID(int inprice, int *buyday) {

}

#endif // !__RF_D_
