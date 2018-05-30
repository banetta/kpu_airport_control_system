// Airport Control System
// coding by LimHS

#ifndef __Leavelist__
#define __Leavelist__

#include "main_header.h"
class Leavelist : public User				//출국자 클래스 부모인 이용자클래스로부터 상속
{
private:
	int leavelist_eday[3];
	int leavelist_lday[3];					//출국일 [0]은 년,[1]은 월,[2]은 일
	Leaveitem leavepack;					//출국자 짐
public:
	Leavelist() {}						//출국자의 default 생성자
	Leavelist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday);
	//출국자 생성자 (여권번호, 이름, 나이, 국적, 출국일(연,월,일))
	void banitem_check(int isBanitem);		//출국자 짐 내의 금지물품 조사
};

#endif // !__Leavelist__

