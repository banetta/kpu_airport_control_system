//by YHS
#ifndef _FLIGHTSCHEDULE_
#define _FLIGHTSCHEDULE_

#include "main_header.h"
//Seat 클래스와 구성관계
//비행일정에는 좌석정보를 가지고 있다.

class FlightSchedule { // 비행일정 클래스
private:
	char destination[10]; // 목적지
	char plane[10]; // 비행기
	Seat Se[4][2];
public:
	FlightSchedule() {}; //비행일정 디폴트생성자
	void takeoff_check(); //비행일정 및 좌석 체크 함수
};
#endif