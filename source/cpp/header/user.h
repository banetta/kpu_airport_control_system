// Airport Control System
// coding by LimHS

#ifndef __USER__
#define __USER__

#include "main_header.h"
class User																	//이용자 클래스
{
public:
	User() {}																//이용자 default 생성자
	User(int, string , int userage, string userregion, string userticketseat,int* userentryday, int* userleaveday);	//이용자 생성자 (여권번호, 이름, 나이, 국적)
	virtual void banitem_check(int isBanitem) {};							//금지물품 체크 가상함수
	int blacklist();														//블랙리스트 확인을 위한 여권번호 호출
	void showyou();
private:
	int passnum;								//이용자 여권번호
	string name;								//이용자 이름
	int age;									//이용자 나이
	string region;								//이용자 국적
	Ticket myTicket;							//이용자 항공편
};

#endif // !__USER__


//여권번호 구성 00000000
//1000000~9999999사이 난수 출력 후 *10
//뒷자리로 블랙리스트 판별

