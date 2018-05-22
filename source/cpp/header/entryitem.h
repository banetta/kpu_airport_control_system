// Airport Control System
// coding by LimHS

#ifndef EN__IT__
#define EN__IT__

class Entryitem
{
public:
	Entryitem();
	~Entryitem();
	RFID RFID;
	int isBanitem_init();
	int RFID_pass(User*);

private:
	int isBanitem;
};

Entryitem::Entryitem()
{
}

Entryitem::~Entryitem()
{
}
#endif // !EN__IT__

