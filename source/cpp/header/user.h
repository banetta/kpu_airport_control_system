// Airport Control System
// coding by LimHS

#ifndef __US_R__
#define __US_R__

#include "main_header.h"

class User
{
public:
	User();
	~User() {};
	User(string user, int age, string region)
	virtual void Banitem_check(int);

private:
	int passnum;
	string name;
	int age;
	string region;
	Ticket myTicket;
};

User::User(string user, int age, string region)
{
}




#endif // !__US_R__

