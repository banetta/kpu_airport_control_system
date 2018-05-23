//	Airport Control System Tariff Functions
//	���װ����ý��ۿ��� ������ ���õ� �Լ��� ������ ��Ʈ
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

	cout << "�� �̿��ڿ��� �ΰ��� �� ������ " << tariff_amount << " �Դϴ�." << endl;
}