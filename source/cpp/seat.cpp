//by YHS
#include "header\main_header.h"

int Seat::initseat() { //ÃÊ±â ÁÂ¼®¼ö ÀÓÀÇ ¹èÁ¤
	first = 1 + (rand() % 10);
	business = 1 + (rand() % 30);
	economy = 1 + (rand() % 60);

	return first + business + economy; // ÁÂ¼®¼ö ÃÑÇÕ
}

void Seat::Addseat() {
	cout << "";
}