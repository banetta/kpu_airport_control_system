#ifndef __EN_TR__
#define __EN_TR__

#include "main_header.h"

class Entrylist :public User
{
public:
	Entrylist();
	~Entrylist();
	Entryitem Entryitem;
	void Banitem_check(int isBanitem);
	void overEntrylist_check();
	int RFID_pass(User*);

private:
	int entrylist_day[3];
};

Entrylist::Entrylist()
{
}

Entrylist::~Entrylist()
{
}
#endif // !__US_R__
