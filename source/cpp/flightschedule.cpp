//by YHS
#include "header\main_header.h"

void FlightSchedule::takeoff_check(int num, ControlTower &ct) {
	time_t timeCur; //시간관련 구조체 생성
	tm* ptmTemp; //시간관련 포인터 생성
	time(&timeCur); //현재시간 함수
	ptmTemp = localtime(&timeCur); // time_t* -> struct tm*

	if (num = 0)	//	입국절차 진행
	{
		entry_init();
	}
	else if (num = 1)
	{
		leave_init();
	}
}

void FlightSchedule::entry_init() {

}

void FlightSchedule::leave_init() {

}
