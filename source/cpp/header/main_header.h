// Airport Control System Main Header ���� ���� �ý��� ���� ���
// all header&code ���� �����ϴ� index header
// coding by Banetta Han Sang Kim

#ifndef __HE_D_	// #pragma once

#define __HE_D_	

//	basic header
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>

#pragma warning(disable:4996)

// namespace ����
using namespace std;

//	optional header
//	���� �۾��� ���� ��� class �� code ����

//#include "main_func.h"	//	main default func
#include "ticket.h"	//	ticket header, ticket.cpp
#include "user.h"	//	user header, user.cpp
#include "leaveitem.h"	//	leave item header, leaveitem.cpp
#include "leavelist.h"	//	leave list header,	leavelist.cpp
#include "rfid.h"	//	rfid header, rfid.cpp
#include "entryitem.h"	//	entry item header, entryitem.cpp
#include "entrylist.h"	//	entry list  header, entrylist.cpp
#include "seat.h"	//	seat header, seat.cpp
#include "flightschedule.h"	//	flightschedule header, flightschedule.cpp
#include "controltower.h"	//	controltower header, controltower.cpp
#include "blacklist.h"	//	blacklist header, blacklist.cpp
#include "tariff.h"	//	tariff header, tariff.cpp

time_t inittime(int* i);
void createUser(Entrylist* elist);
void createUser(Leavelist* llist);


#endif // !__HE_D_
