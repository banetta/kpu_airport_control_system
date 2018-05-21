// Airport Control System Main Header 공항 관리 시스템 메인 헤더
// all header&code 에서 참조하는 index header
// coding by Banetta Han Sang Kim

#ifndef __HE_D_	// #pragma once

#define __HE_D_	

//	basic header
#include <iostream>
#include <cstring>
#include <cstdlib>

//	optional header
//	분할 작업을 위해 모든 class 및 code 분할

#include "ticket.h"	//	ticket header, ticket.cpp
#include "user.h"	//	user header, user.cpp
#include "flightschedule.h"	//	flightschedule header, flightschedule.cpp
#include "controltower.h"	//	controltower header, controltower.cpp
#include "seat.h"	//	seat header, seat.cpp
#include "rfid.h"	//	rfid header, rfid.cpp
#include "leavelist.h"	//	leave list header,	leavelist.cpp
#include "entrylist.h"	//	entry list  header, entrylist.cpp
#include "leaveitem.h"	//	leave item header, leaveitem.cpp
#include "entryitem.h"	//	entry item header, entryitem.cpp
#include "blacklist.h"	//	blacklist header, blacklist.cpp
#include "tariff.h"	//	tariff header, tariff.cpp

// namespace 선언
using namespace std;

#endif // !__HE_D_
