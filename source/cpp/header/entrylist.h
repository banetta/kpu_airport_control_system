<<<<<<< HEAD
=======
// Airport Control System
// coding by LimHS

#ifndef __EntryList__
#define __EntryList__

#include "main_header.h"
class EntryList : public User				//�Ա��� Ŭ���� �θ��� �̿���Ŭ�����κ��� ��ӹ���
{
private:
	int entrylist_day[3];					//�Ա��� [0]�� ��,[1]�� ��,[2]�� ��
	Entryitem  entrypack;					//�Ա��� ��
public:
	EntryList() {}							//�Ա����� default ������
	EntryList(int userpassnum, string username, int userage, string userregion, int entryyear, int entrymonth, int entryday);
	//�Ա��� ������ (���ǹ�ȣ, �̸�, ����, ����, �Ա���(��,��,��))
	void banitem_check(int isBanitem);		//�Ա��� �� ���� ������ǰ ����
	void overEntrylist_check();				//�ҹ�ü������ Ȯ��
};

#endif // !__EntryList__
>>>>>>> gustjd_cpp_1st
