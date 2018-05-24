// Airport Control System
// coding by LimHS
#include "header\main_header.h"

Blacklist::Blacklist(int usernum, int userreason) : blacknum(usernum)
{
	srand((int)time(NULL));									//시드별 다른 난수가 나오도록 설정
	reason = (((rand() % 8999) + 1000) * 10) + rand() % 10;	//난수를	1~7자리에 받고 마지막 자리에 4~9가 들어가면 정상 나머진 블랙리스트

}

void Blacklist::reason_print(User *user)
{
	if (user->blacklist() == blacknum)
	{
		switch (reason % 10)
		{
		case 0:
			cout << "Reason : 불법체류 기록 존재" << endl;
			break;
		case 1:
			cout << "Reason : 밀입국 기록 존재" << endl;
			break;
		case 2:
			cout << "Reason : 테러리스트 분류" << endl;
			break;
		case 3:
			cout << "Reason : 형사재판 진행중" << endl;
			break;
		default:
			break;
		}
	}
	else
	{
		cout << "블랙리스트 해당사항 없음" << endl;
	}

}
