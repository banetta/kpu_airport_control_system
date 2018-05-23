//by YHS
#ifndef _SEAT_
#define _SEAT_

class Seat { // 좌석 클래스
private:
	int first;
	int business;
	int economy;
public:
	int initseat();
	void Addseat();  //좌석 배정 함수
	//void seatbooking(User * user);
};
#endif