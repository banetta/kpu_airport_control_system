// Airport Control System
// coding by LimHS
#include "header\main_header.h"

Entrylist::Entrylist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday)
	: User(userpassnum, username, userage, userregion, userticketseat, userentryday, userleaveday)
{
	isBanitem = rand() % 20;
	for (int i = 0; i < 3; i++)
	{
		entrylist_eday[i] = userentryday[i];	//	입국일자 입력
		entrylist_lday[i] = userleaveday[i];
	}
	
	int j = 0;	//	입국자 수화물 index 번호 지정을 위한 변수
	for (int i = (rand() % 6); i < 5; i++)	//	입국자의 수화물 갯수를 (5-i)만큼 정해줌
	{
		entrypack[j] = new Entryitem;	//	입국자 수화물 생성 index 번호를 넣어주고 ++
		entrypack[j]->item_init();
	   entrypack[(j + 1)] = NULL;
		j++;
	}
}

int Entrylist::sendban() {
	return isBanitem;
}
void Entrylist::banitem_check()
{
	int i = NULL;
	for (int j = 0; j < 5; j++)
	{
		if (entrypack[j] != NULL)
		{
			i = sendban();
			if (i == 0) {
				cout << "수화물 내 금지물품 존재" << endl;
				cout << "금지물품 폐기 완료 통과" << endl;
				break;
			}
			else  {
				cout << "수화물 내 금지물품 없음 통과" << endl;
				break;
			}
		}
	}
	
}

void Entrylist::overEntrylist_check()
{
	int lenghtofstay;					//체류기간을 받는 변수
	time_t     tm_st;					//입국 날짜를 받기 위한 초단위 변수
	time_t     tm_nd;					//현재 날짜를 받기 위한 초단위 변수
	double     d_diff;

	tm_st = inittime(entrylist_eday);	//	입국날짜를 입력

	time(&tm_nd);							//현재 날짜를 초단위 변수에 입력

	d_diff = difftime(tm_nd, tm_st);		//입국 날짜부터 현재 날짜까지 초단위 차이를 계산

	lenghtofstay = d_diff / (60 * 60 * 24); //초단위를 일단위로 변환 후 체류기간 변수에 입력

	cout << "Lenght of stay : " << lenghtofstay << endl; //입국자의 현재까지 체류기간 출력
}

int Entrylist::passing_price() {

	int pay = NULL;
	for (int i = 0; entrypack[(i + 1)] == NULL; i++)
	{
			pay += entrypack[i]->passing_price(entrylist_eday, entrylist_lday);
		
	}
	
	return pay;

}