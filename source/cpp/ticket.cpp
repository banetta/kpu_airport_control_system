//by YHS
#include "header\main_header.h"

Ticket::Ticket(string userticketseat, int* userentryday, int* userleaveday) :ticket_seat(userticketseat)
{
	for (int i = 0; i < 3; i++)
	{
		entryday[i] = userentryday[i];
		leaveday[i] = userleaveday[i];
	}
}

//char* Ticket::ticketseat_call(){

//}
