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
	RFID(std::string, int, int*);
	int RFID_amount(User*);
	int RFID_buypick(int *entryday, int *leaveday);

private:
	string itemname;
	int price;
	int buyday[2];
};

RFID::RFID(std::string, int inprice, int *buyday) {

}

#endif // !__RF_D_
