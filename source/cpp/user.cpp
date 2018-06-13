// Airport Control System
// coding by LimHS
#include "header\main_header.h"

User::User(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday) : passnum(userpassnum), name(username), age(userage), region(userregion), myTicket(userticketseat, userentryday, userleaveday) {}

int User::blacklist() { 
	return passnum; 
}
void User::showyou()
{
	cout << "Passnumber : " << passnum << " Name : " << name << endl;
}
