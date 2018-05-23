//by YHS
#ifndef _SEAT_
#define _SEAT_

#include "main_header.h"

class Seat { // �¼� Ŭ����
private:
	int first;
	int business;
	int economy;
public:
	int initseat();
	void Addseat();  //�¼� ���� �Լ�
	//void seatbooking(User * user);
};
#endif