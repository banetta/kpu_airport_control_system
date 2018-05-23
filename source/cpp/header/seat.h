//by YHS
#ifndef _SEAT_
#define _SEAT_

class Seat { // �¼� Ŭ����
private:
	int first;
	int business;
	int economy;
public:
	int initseat();
	void Addseat();  //�¼� ���� �Լ�
	//void seatbooking(User * user);
};
#endif