//	Airport Control System Tariff Functions
//	���װ����ý��ۿ��� ������ ���õ� �Լ��� ������ ��Ʈ
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
	cout << "�� �̿��ڿ��� �ΰ��� �� ������ " << tariff_amount << " �Դϴ�." << endl;
}