// Airport Control System
// coding by LimHS

#ifndef __Leavelist__
#define __Leavelist__

#include "main_header.h"
class Leavelist : public User				//�ⱹ�� Ŭ���� �θ��� �̿���Ŭ�����κ��� ���
{
private:
	int leavelist_eday[3];
	int leavelist_lday[3];					//�ⱹ�� [0]�� ��,[1]�� ��,[2]�� ��
	Leaveitem leavepack;					//�ⱹ�� ��
public:
	Leavelist() {}						//�ⱹ���� default ������
	Leavelist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday);
	//�ⱹ�� ������ (���ǹ�ȣ, �̸�, ����, ����, �ⱹ��(��,��,��))
	void banitem_check(int isBanitem);		//�ⱹ�� �� ���� ������ǰ ����
};

#endif // !__Leavelist__

