#include "header\main_header.h"

void Leaveitem::isBanitem_init()
{
	isBanitem = rand() % 20;
}

int Leaveitem::sendban()
{
	return isBanitem;
	
}