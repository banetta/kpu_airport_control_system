// Airport Control System
// coding by LimHS

#ifndef __EntryList__
#define __EntryList__

#include "main_header.h"
class Entrylist : public User				//�Ա��� Ŭ���� �θ��� �̿���Ŭ�����κ��� ��ӹ���
{
private:
	int entrylist_eday[3];	//	�Ա��� [0]�� ��,[1]�� ��,[2]�� ��
	int entrylist_lday[3];	//	�ⱹ�� "
	Entryitem* entrypack[5];					//�Ա��� ��
	int isBanitem;
public:
	Entrylist() {}							//�Ա����� default ������
	Entrylist(int userpassnum, string username, int userage, string userregion, string userticketseat, int* userentryday, int* userleaveday);
	~Entrylist() { delete entrypack; }
	//�Ա��� ������ (���ǹ�ȣ, �̸�, ����, ����, �Ա���(��,��,��))
	void banitem_check();		//�Ա��� �� ���� ������ǰ ����
	void overEntrylist_check();				//�ҹ�ü������ Ȯ��
	int passing_price();
	int sendban();
};

#endif // !__EntryList__

