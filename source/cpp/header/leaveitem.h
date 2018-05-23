#ifndef __LE_V___
#define __LE_V___
#include "main_header.h"

class Leaveitem {
private:
	int isBanitem;
public:
	Leaveitem(){}
	Leaveitem(int l) :isBanitem(l)
	{}
	int isBanitem_init();
};

#endif // !__LE_V___

