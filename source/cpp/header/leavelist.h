// Airport Control System
// coding by LimHS

#ifndef __Leavelist__
#define __Leavelist__

#include "main_header.h"
class LeaveList : public User				//�ⱹ�� Ŭ���� �θ��� �̿���Ŭ�����κ��� ���
{
private:
	int leavelist_day[3];					//�ⱹ�� [0]�� ��,[1]�� ��,[2]�� ��
	Leaveitem leavepack;					//�ⱹ�� ��
public:
	LeaveList() {}							//�ⱹ���� default ������
	LeaveList(int userpassnum, string username, int userage, string userregion, int leaveyear, int leavemonth, int leaveday);
	//�ⱹ�� ������ (���ǹ�ȣ, �̸�, ����, ����, �ⱹ��(��,��,��))
	void banitem_check(int isBanitem);		//�ⱹ�� �� ���� ������ǰ ����
};

#endif // !__Leavelist__

