//	Airport Control System Tariff Functions
//	공항관리시스템에서 관세와 관련된 함수를 구현한 파트
//	coding by Banetta Han Sang Kim

#include "header\main_header.h"

void TARIFF::calcTariff(Entrylist* elist) {
	
	getRFID_amount(elist);
	if (pay_amount >= 200000)
	{
		tariff_amount = (pay_amount * 0.2);
	}
	else
	{
		tariff_amount = NULL;
	}
	
}

void TARIFF::getRFID_amount(Entrylist *user) {

	pay_amount = user->passing_price();
}

void TARIFF::Tariff_print(Entrylist* elist) {

	calcTariff(elist);
	cout << "이 이용자에게 부가될 총 관세는 " << tariff_amount << " 입니다." << endl;
}