//by YHS
#include "header\main_header.h"

int Seat::initseat() { //�ʱ� �¼��� ���� ����
	first = 1 + (rand() % 10);
	business = 1 + (rand() % 30);
	economy = 1 + (rand() % 60);

	return first + business + economy; // �¼��� ����
}

void Seat::Addseat() {
	cout << "";
}