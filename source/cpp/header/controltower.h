//by YHS
#ifndef _CONTROLTOWER_
#define _CONTROLTOWER_

#include "main_header.h"

class ControlTower {
private:
	int runway;
	int weather;
public:
	ControlTower() {};
	int weathercenter_check();
	int runway_check();
};
#endif