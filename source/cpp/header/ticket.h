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
	int entryday[3];	//	�Ա���
	int leaveday[3];	//	�ⱹ��
};


#endif // !__TIC__K
