//by YHS
#include "header\main_header.h"

int ControlTower::runway_check() {
	runway = (rand() % 5); //0~4 랜덤숫자 부여 , 0일시 남은 활주로 0
	return runway;
}

int ControlTower::weathercenter_check() {
	weather = 1 + (rand() % 5); //1~5 랜덤숫자 부여
	return weather;
}