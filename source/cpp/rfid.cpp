//	RFID class functions
//	coding by Banetta

#include "header\main_header.h"

int RFID::RFID_buypick(int *entryday, int *leaveday) {	//	이 수화물이 여행기간중 구입한 수화물인지 체크해주는 Func

	struct tm t;						//날짜를 받기 위한 라이브러리 구조체
	time_t     tm_st;					//출국 날짜를 받기 위한 초단위 변수
	time_t     tm_mm;					//구매 날짜를 받기 위한 초단위 변수
	time_t     tm_nd;					//입국 날짜를 받기 위한 초단위 변수
	double     d_diff;

	t.tm_year = leaveday[0] - 1900;	//출국 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = leaveday[1] - 1;		//출국 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = leaveday[2];			//출국 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화
	tm_st = mktime(&t);						//출국 날짜를 받은 구조체의 변수를 초단위 변수에 입력

	t.tm_year = entryday[0] - 1900;	//입국 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = entryday[1] - 1;		//입국 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = entryday[2];			//입국 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화
	tm_nd = mktime(&t);						//입국 날짜를 받은 구조체의 변수를 초단위 변수에 입력

	t.tm_year = buyday[0] - 1900;	//구매 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = buyday[1] - 1;		//구매 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = buyday[2];			//구매 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화
	tm_mm = mktime(&t);						//구매 날짜를 받은 구조체의 변수를 초단위 변수에 입력
	if (tm_st <= tm_mm <= tm_nd)	{return price;} //출국 날짜와 입국 날짜 사이에 구매 날짜가 존재할 경우 물품의 가격을 반환한다.
	else {return 0;}
}