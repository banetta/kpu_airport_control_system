//	RFID class functions
//	coding by Banetta

#include "header\main_header.h"

void RFID::RFID_init(int a, int* b) {

	price = a;
	for (int i = 0; i < 3; i++)
	{
		buyday[i] = b[i];
	}

}

int RFID::RFID_buypick(int *entryday, int *leaveday) {	

	time_t     tm_st;               //출국 날짜를 받기 위한 초단위 변수
	time_t     tm_mm;               //구매 날짜를 받기 위한 초단위 변수
	time_t     tm_nd;               //입국 날짜를 받기 위한 초단위 변수

	tm_st = inittime(leaveday);	//	출국날짜 입력
	tm_mm = inittime(entryday);	//	입국날짜 입력
	tm_nd = inittime(buyday);	//	구매날짜 입력

	if (tm_st <= tm_mm <= tm_nd) { //출국 날짜와 입국 날짜 사이에 구매 날짜가 존재할 경우 물품의 가격을 반환한다.
		return price; 
	} 
	else { 
		return 0; 
	}
}
