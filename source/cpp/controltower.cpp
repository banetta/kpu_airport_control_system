//by YHS
#include "header\main_header.h"

int ControlTower::runway_check() {
	runway = (rand() % 5); //0~4 �������� �ο� , 0�Ͻ� ���� Ȱ�ַ� 0
	return runway;
}

int ControlTower::weathercenter_check() {
	weather = 1 + (rand() % 5); //1~5 �������� �ο�
	return weather;
}