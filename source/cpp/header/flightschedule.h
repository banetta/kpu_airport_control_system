//by YHS
#ifndef _FLIGHTSCHEDULE_
#define _FLIGHTSCHEDULE_

#include "main_header.h"
//Seat Ŭ������ ��������
//������������ �¼������� ������ �ִ�.
class ControlTower;
class FlightSchedule { // �������� Ŭ����
private:
	string airline;
	string destination;
	int seat[3];
	int hour;
	string shit;
	int min;
public:
	FlightSchedule() {}; //�������� ����Ʈ������
	FlightSchedule(string fairline, string fdestination, int* fseat, int fhour, string fshit, int fmin);
	void takeoff_check(char num, ControlTower &ct); //�������� �� �¼� üũ �Լ�
};
#endif
