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
	void tariffpay_check();

private:
	char buyday[10];	//	item buy date ���� ���� ����
	int price;	//	item price ���� ����
};

#endif // !__RF_D_