// Airport Control System
// coding by LimHS

#ifndef EN__IT__
#define EN__IT__

class Entryitem
{
public:
	Entryitem() {};
	~Entryitem() {};
	Entryitem(int e) :isBanitem(e) {}
	RFID RFID;
	int isBanitem_init();
	int RFID_pass(User*);

private:
	int isBanitem;
};


#endif // !EN__IT__

