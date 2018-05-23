// Airport Control System
// coding by LimHS

#ifndef __US_R__
#define __US_R__

#include "main_header.h"

class User
{
public:
	User() {};
	~User() {};
	User(int, std::string, int, std::string);
	virtual void Banitem_check(int);


private:
	int *passnum;
	string name;
	int *age;
	string region;
	//Ticket myTicket;
};
#endif // !__US_R__

