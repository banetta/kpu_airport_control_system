//by YHS
#include "header\main_header.h"

void FlightSchedule::takeoff_check(int num, ControlTower &ct) {
	time_t timeCur; //�ð����� ����ü ����
	tm* ptmTemp; //�ð����� ������ ����
	time(&timeCur); //����ð� �Լ�
	ptmTemp = localtime(&timeCur); // time_t* -> struct tm*

	if (num = 0)	//	�Ա����� ����
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
