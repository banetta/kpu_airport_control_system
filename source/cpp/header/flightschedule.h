//by YHS
#ifndef _FLIGHTSCHEDULE_
#define _FLIGHTSCHEDULE_

#include "main_header.h"
//Seat Ŭ������ ��������
//������������ �¼������� ������ �ִ�.

class FlightSchedule { // �������� Ŭ����
private:
	char destination[10]; // ������
	char plane[10]; // �����
	Seat Se[4][2];
public:
	FlightSchedule() {}; //�������� ����Ʈ������
	void takeoff_check(); //�������� �� �¼� üũ �Լ�
};
#endif