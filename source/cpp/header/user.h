// Airport Control System
// coding by LimHS

#ifndef __USER__
#define __USER__

#include "main_header.h"
class User																	//�̿��� Ŭ����
{
public:
	User() {}																//�̿��� default ������
	User(int, string , int userage, string userregion, string userticketseat,int* userentryday, int* userleaveday);	//�̿��� ������ (���ǹ�ȣ, �̸�, ����, ����)
	virtual void banitem_check(int isBanitem) {};							//������ǰ üũ �����Լ�
	int blacklist();														//������Ʈ Ȯ���� ���� ���ǹ�ȣ ȣ��
	void showyou();
private:
	int passnum;								//�̿��� ���ǹ�ȣ
	string name;								//�̿��� �̸�
	int age;									//�̿��� ����
	string region;								//�̿��� ����
	Ticket myTicket;							//�̿��� �װ���
};

#endif // !__USER__


//���ǹ�ȣ ���� 00000000
//1000000~9999999���� ���� ��� �� *10
//���ڸ��� ������Ʈ �Ǻ�

