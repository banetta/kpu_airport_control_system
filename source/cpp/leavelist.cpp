// Airport Control System
// coding by LimHS
#include "header\main_header.h"

Leavelist::Leavelist()
{
}

Leavelist::Leavelist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday, int leavebanitem)
	: User(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday), leavepack(leavebanitem)
{
	for (int i = 0; i < 3; i++)
	{
		leavelist_eday[i] = userentryday[i];
		leavelist_lday[i] = userleaveday[i];
	}
}

void Leavelist::banitem_check(int isBanitem)
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