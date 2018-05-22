//	RFID class functions
//	coding by Banetta
//

#include "header\main_header.h"

int RFID::RFID_amount(User* user) {

	return RFID_buypick();
	
}

int RFID::RFID_buypick(int *entryday, int *leaveday) {	//	이 수화물이 여행기간중 구입한 수화물인지 체크해주는 Func

	if (entryday[0] < buyday[0] && leaveday[0] > buyday[0])	//	여행기간 연도 == 구입날짜 연도인 경우
	{
		if (entryday[1] < buyday[1] && leaveday[1]>buyday[1])	//	여행기간 달 == 구입날짜 달인 경우
		{
			if (entryday[2]>buyday[2] && leaveday[2]<buyday[2])	//	여행기간 일자 != 구입날짜 일자인 경우
			{
				return 0;	//	해당 물품은 여행기간동안 구입한 물품이 아님
			}
			else if (entryday[2]<buyday[2] && leaveday[2]>buyday[2])	//	여행기간 일자 == 구입날짜 일자인 경우
			{
				return 1;	//	이 물품은 여행기간동안 구입하였음
			}
		}
	}
	else
	{
		return 0;	//	그 외경우 전부 pass
	}
}