// Airport Control System
// coding by LimHS
#include "header\main_header.h"

LeaveList::LeaveList(int userpassnum, string username, int userage, string userregion, int leaveyear, int leavemonth, int leaveday)
	: User(userpassnum, username, userage, userregion)
{
	leavelist_day[0] = leaveyear;	//출국년 입력
	leavelist_day[1] = leavemonth;	//출국월 입력
	leavelist_day[2] = leaveday;	//출국일 입력
}

void LeaveList::banitem_check(int isBanitem)
{
	switch (isBanitem)
	{
	case 1:											//수화물 내에 금지물품이 없을 경우 isBanitem에 1이 들어감 
		cout << "수화물 내 금지물품 없음 통과";
		break;
	case 0:											//수화물 내에 금지물품이 있을 경우 isBanitem에 0이 들어감 
		cout << "수화물 내 금지물품 존재" << endl;
		cout << endl;
		cout << endl;
		cout << "금지물품 폐기 완료 통과" << endl;
		break;
	default:										//혹시 오류로 인해 다른 값이 들어갔을 경우
		cout << "수화물 검사 오류" << endl;
		break;
	}
}