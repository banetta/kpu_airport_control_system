// coding by Banetta

// #pragma once
#ifndef __RF_D_
#define __RF_D_

// main header include
#include "main_header.h"

class RFID
{
public:
	RFID();
	~RFID();
	void tariffpay_check();

private:
	string buyday;	//	item buy date ���� ���� ����
	int price;	//	item price ���� ����
};

RFID::RFID()
{
}

RFID::~RFID()
{
}

#endif // !__RF_D_
