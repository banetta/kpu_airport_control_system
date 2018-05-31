//by YHS
#ifndef __TIC__K
#define __TIC__K

#include "main_header.h"

class Ticket
{
public:
	Ticket() {};
	~Ticket() {};
	Ticket(string, int*, int*);
	//char* ticketseat_call();
private:
	string ticket_seat;
	int entryday[3];	//	입국일
	int leaveday[3];	//	출국일
};


#endif // !__TIC__K
