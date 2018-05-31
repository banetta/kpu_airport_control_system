//by YHS
#ifndef _FLIGHTSCHEDULE_
#define _FLIGHTSCHEDULE_

#include "main_header.h"
//Seat 클래스와 구성관계
//비행일정에는 좌석정보를 가지고 있다.
class ControlTower;
class FlightSchedule { // 비행일정 클래스
private:
	string airline;
	string destination;
	int seat[3];
	int hour;
	string shit;
	int min;
public:
	FlightSchedule() {}; //비행일정 디폴트생성자
	FlightSchedule(string fairline, string fdestination, int* fseat, int fhour, string fshit, int fmin);
	void takeoff_check(char num, ControlTower &ct); //비행일정 및 좌석 체크 함수
};
#endif
