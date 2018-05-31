#include "header\main_header.h"


void Entryitem::item_init()
{
	int pay = (rand() % 10000)*100;
	int buyday[3];

	buyday[0] = (rand() % 5) + 2013;
	buyday[1] = (rand() % 12) + 1;
	buyday[2] = (rand() % 27) + 1;

	//isBanitem = rand() % 2;
	rfid = new RFID;
	rfid->RFID_init(pay, buyday);
}

int Entryitem::passing_price(int* entryday, int* leaveday) {

	return rfid->RFID_buypick(entryday, leaveday);
}

//int Entryitem::sendban()
//{
//	return isBanitem;
//}

