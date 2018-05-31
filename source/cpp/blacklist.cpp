// Airport Control System
// coding by LimHS
#include "header\main_header.h"


int Blacklist::reason_print(int upass)
{
	int i;
	switch (upass % 100)
	{
		case 0:
			cout << "Reason : 불법체류 기록 존재" << endl;
			i = 1;
			return i;
		case 1:
			cout << "Reason : 밀입국 기록 존재" << endl;
			i = 1;
			return i;
		case 2:
			cout << "Reason : 테러리스트 분류" << endl;
			i = 1;
			return i;
		case 3:
			cout << "Reason : 형사재판 진행중" << endl;
			i = 1;
			return i;
		default:
			cout << "블랙리스트 해당사항 없음" << endl;
			i = 0;
			return i;
	}
}
