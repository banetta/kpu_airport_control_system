// Airport Control System
// coding by LimHS

#ifndef __Blacklist__
#define __Blacklist__

#include "main_header.h"
class Blacklist			//������Ʈ Ŭ����
{
private:
	int reason;						//������Ʈ�� ���� ��ȣ�� �Է¹���
public:
	Blacklist() {}					//������Ʈ�� default ������
	int reason_print(int unum);	//������Ʈ ���� ��� �Լ�
};

#endif // !__Blacklist__


//�ҹ�ü�� ��� ����
//���Ա� ��� ����
//�׷�����Ʈ �з�
//�������� ������
//...etc