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
	string buyday;	//	item buy date 물건 구매 일자
	int price;	//	item price 물건 가격
};

RFID::RFID()
{
}

RFID::~RFID()
{
}

#endif // !__RF_D_
