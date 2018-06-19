#ifndef __MA__FU
#define __MA__FU

#include "main_header.h"
// 단일 함수 선언

time_t inittime(int* i);
void createUser(Entrylist* elist[]);
void createban(Entrylist* blist[]);
void createUser(Leavelist* llist[]);
void createFlightSchedule(FlightSchedule* fschedule[]);
void leaveprocess(Leavelist* llist[]);
void leaveprocess(Entrylist* elist[]);
void Airplainlist(FlightSchedule* fschedule[]);
void Airlinemanagement(FlightSchedule* fschedule[], ControlTower &ct);
void Illegal_resident(Entrylist* blist[]);

#endif // !__MA__FU
