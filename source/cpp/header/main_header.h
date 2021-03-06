// Airport Control System Main Header 공항 관리 시스템 메인 헤더
// all header&code 에서 참조하는 index header
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
#include <iomanip>
#include <Windows.h>
#pragma warning(disable:4996)

// namespace 선언
using namespace std;

//	optional header
//	분할 작업을 위해 모든 class 및 code 분할

//#include "main_func.h"	//	main default func
#include "ticket.h"	//	ticket header, ticket.cpp
#include "user.h"	//	user header, user.cpp
#include "leaveitem.h"	//	leave item header, leaveitem.cpp
#include "leavelist.h"	//	leave list header,	leavelist.cpp
#include "rfid.h"	//	rfid header, rfid.cpp
#include "entryitem.h"	//	entry item header, entryitem.cpp
#include "entrylist.h"	//	entry list  header, entrylist.cpp
#include "flightschedule.h"	//	flightschedule header, flightschedule.cpp
#include "controltower.h"	//	controltower header, controltower.cpp
#include "blacklist.h"	//	blacklist header, blacklist.cpp
#include "tariff.h"	//	tariff header, tariff.cpp
#include "main_func.h"	//	main_func header, main_func.cpp

#endif // !__HE_D_
