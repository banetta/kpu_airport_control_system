// Airport Control System
// coding by LimHS

#ifndef __EntryList__
#define __EntryList__

#include "main_header.h"
class EntryList : public User				//입국자 클래스 부모인 이용자클래스로부터 상속받음
{
private:
	int entrylist_day[3];					//입국일 [0]은 년,[1]은 월,[2]은 일
	Entryitem  entrypack;					//입국자 짐
public:
	EntryList() {}							//입국자의 default 생성자
	EntryList(int userpassnum, string username, int userage, string userregion, int entryyear, int entrymonth, int entryday);
	//입국자 생성자 (여권번호, 이름, 나이, 국적, 입국일(연,월,일))
	void banitem_check(int isBanitem);		//입국자 짐 내의 금지물품 조사
	void overEntrylist_check();				//불법체류여부 확인
};

#endif // !__EntryList__
