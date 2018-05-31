#include "header\main_header.h"

void Leaveitem::isBanitem_init()
{
	isBanitem = rand() % 100;
}

int Leaveitem::sendban()
{
	return isBanitem;
	
}