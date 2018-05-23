//	Airforce Control System Tariff Header
//	항공관리시스템에 관세와 관련된 정보가 모여있는 Header
//	coding by Banetta

//	Tariff class Header

#ifndef __TAR_FF_	//	#pragma once
#define __TAR_FF_

#include "main_header.h"

class TARIFF
{
public:
	TARIFF() { pay_amount = NULL; tariff_amount = NULL; };
	~TARIFF() {};
	void calcTariff(Entrylist*);
	void getRFID_amount(Entrylist*);
	void Tariff_print();

private:
	int pay_amount;
	int tariff_amount;
};


#endif // !__TAR_FF_
