// Airport Control System
// coding by LimHS

#ifndef __Blacklist__
#define __Blacklist__

#include "main_header.h"
class Blacklist			//블랙리스트 클래스
{
private:
	int blacknum;					//블랙리스트의 여권번호를 입력받음
	int reason;						//블랙리스트의 사유 번호를 입력받음
public:
	Blacklist() {}					//블랙리스트의 default 생성자
	Blacklist(int usernum, int userreason);					//블랙리스트 생성자 (여권번호, 사유번호)
	void reason_print(User *user);	//블랙리스트 사유 출력 함수
};

#endif // !__Blacklist__


//불법체류 기록 존재
//밀입국 기록 존재
//테러리스트 분류
//형사재판 진행중
//...etc