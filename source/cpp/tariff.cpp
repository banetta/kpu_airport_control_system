//	Airport Control System Tariff Functions
//	공항관리시스템에서 관세와 관련된 함수를 구현한 파트
//	coding by Banetta Han Sang Kim

#include "header\main_header.h"

void TARIFF::calcTariff(Entrylist *user) {
	pay_amount = getRFID_amount(user);
	
	if (pay_amount >= 200000)
	{
		tariff_amount = ((pay_amount * 0.2) * 0.1);
	}
	else
	{
		tariff_amount = NULL;
	}
	
}

void TARIFF::getRFID_amount(Entrylist *user) {

	if (pay_amount >= 200000)
	{
		tariff_amount = (pay_amount / 20) * 100;
	}
	else
	{
		tariff_amount = NULL;
	}
}

void TARIFF::Tariff_print() {

	cout << "이 이용자에게 부가될 총 관세는 " << tariff_amount << " 입니다." << endl;
}