// Airport Control System
// coding by LimHS
#include "header\main_header.h"

EntryList::EntryList(int userpassnum, string username, int userage, string userregion, int entryyear, int entrymonth, int entryday)
	: User(userpassnum, username, userage, userregion)
{
	entrylist_day[0] = entryyear;	//입국년 입력
	entrylist_day[1] = entrymonth;	//입국월 입력
	entrylist_day[2] = entryday;	//입국일 입력
}

void EntryList::banitem_check(int isBanitem)
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

void EntryList::overEntrylist_check()
{
	int lenghtofstay;					//체류기간을 받는 변수
	struct tm t;						//입국 날짜를 받기 위한 라이브러리 구조체
	time_t     tm_st;					//입국 날짜를 받기 위한 초단위 변수
	time_t     tm_nd;					//현재 날짜를 받기 위한 초단위 변수
	double     d_diff;

	t.tm_year = entrylist_day[0] - 1900;	//현재 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = entrylist_day[1] - 1;		//현재 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = entrylist_day[2];			//현재 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화

	tm_st = mktime(&t);						//입국 날짜를 받은 구조체의 변수를 초단위 변수에 입력
	time(&tm_nd);							//현재 날짜를 초단위 변수에 입력

	d_diff = difftime(tm_nd, tm_st);		//입국 날짜부터 현재 날짜까지 초단위 차이를 계산

	lenghtofstay = d_diff / (60 * 60 * 24); //초단위를 일단위로 변환 후 체류기간 변수에 입력

	cout << "Lenght of stay : " << lenghtofstay << endl; //입국자의 현재까지 체류기간 출력
}