// Airport Control System
// coding by LimHS

#ifndef EN__IT__
#define EN__IT__
#include "main_header.h"
class Entryitem
{
public:
	Entryitem() {};
	~Entryitem() {};
	Entryitem(int e) :isBanitem(e) { };
	void item_init();
	int passing_price(int*, int*);
	int sendban();

private:
	int isBanitem;
	RFID* rfid;
};

#endif // !EN__IT__

