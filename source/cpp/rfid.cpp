//	RFID class functions
//	coding by Banetta

#include "header\main_header.h"

int RFID::RFID_buypick(int *entryday, int *leaveday) {	//	이 수화물이 여행기간중 구입한 수화물인지 체크해주는 Func

	//if (entryday[0] < buyday[0] && leaveday[0] > buyday[0])	//	여행기간 연도 == 구입날짜 연도인 경우
	//{
	//	if (entryday[1] < buyday[1] && leaveday[1]>buyday[1])	//	여행기간 달 == 구입날짜 달인 경우
	//	{
	//		if (entryday[2]>buyday[2] && leaveday[2]<buyday[2])	//	여행기간 일자 != 구입날짜 일자인 경우
	//		{
	//			return 0;	//	해당 물품은 여행기간동안 구입한 물품이 아님
	//		}
	//		else if (entryday[2]<buyday[2] && leaveday[2]>buyday[2])	//	여행기간 일자 == 구입날짜 일자인 경우
	//		{
	//			return price;	//	이 물품은 여행기간동안 구입하였음
	//		}
	//	}
	//}
	//else
	//{
	//	return 0;	//	그 외경우 전부 pass
	//}
	struct tm t;						//입국 날짜를 받기 위한 라이브러리 구조체
	time_t     tm_st;					//입국 날짜를 받기 위한 초단위 변수
	time_t     tm_mm;
	time_t     tm_nd;					//현재 날짜를 받기 위한 초단위 변수
	double     d_diff;

	t.tm_year = leaveday[0] - 1900;	//현재 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = leaveday[1] - 1;		//현재 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = leaveday[2];			//현재 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화
	tm_st = mktime(&t);						//입국 날짜를 받은 구조체의 변수를 초단위 변수에 입력

	t.tm_year = entryday[0] - 1900;	//현재 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = entryday[1] - 1;		//현재 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = entryday[2];			//현재 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화
	tm_nd = mktime(&t);						//입국 날짜를 받은 구조체의 변수를 초단위 변수에 입력

	t.tm_year = buyday[0] - 1900;	//현재 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = buyday[1] - 1;		//현재 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = buyday[2];			//현재 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화
	tm_mm = mktime(&t);						//입국 날짜를 받은 구조체의 변수를 초단위 변수에 입력
	if (tm_st <= tm_mm <= tm_nd)
	{
		return price;
	}
	else
	{
		return 0;
	}



}