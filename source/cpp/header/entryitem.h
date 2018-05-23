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
	Entryitem(int e, int r,int *p) :isBanitem(e),rfid(r,p) {}
	int isBanitem_init();

private:
	int isBanitem;
	RFID rfid;
};


#endif // !EN__IT__

