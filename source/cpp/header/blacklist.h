// Airport Control System
// coding by LimHS

#ifndef __Blacklist__
#define __Blacklist__

#include "main_header.h"
class Blacklist			//������Ʈ Ŭ����
{
private:
	int blacknum;					//������Ʈ�� ���ǹ�ȣ�� �Է¹���
	int reason;						//������Ʈ�� ���� ��ȣ�� �Է¹���
public:
	Blacklist() {}					//������Ʈ�� default ������
	Blacklist(int usernum, int userreason);					//������Ʈ ������ (���ǹ�ȣ, ������ȣ)
	void reason_print(User *user);	//������Ʈ ���� ��� �Լ�
};

#endif // !__Blacklist__


//�ҹ�ü�� ��� ����
//���Ա� ��� ����
//�׷�����Ʈ �з�
//�������� ������
//...etc