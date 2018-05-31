// Airport Control System Main Function
// coding by Banetta Han Sang Kim

#include "header\main_header.h"

time_t inittime(int* i) {

	struct tm t;
	t.tm_year = i[0] - 1900;   //출국 년도를 입력, 함수 특성상 연도에 -1900을 해야함
	t.tm_mon = i[1] - 1;      //출국 월을 입력, 함수 특성상 월에 -1을 해야함
	t.tm_mday = i[2];         //출국 일을 입력
	t.tm_hour = t.tm_min = t.tm_sec = t.tm_isdst = 0; //나머지를 모두 0으로 초기화
	return mktime(&t);                  //출국 날짜를 받은 구조체의 변수를 초단위 변수에 입력
}

void createUser(Entrylist* elist[]) {

	int fpassnum, fage, fentrtday[3], fleaveday[3];
	string fname, fregion, fseat;
	ifstream file;

	file.open("entry.txt", ios::in);

	if (file.is_open() == false)
	{
		cout << "file is empty." << endl;
		cout << file.is_open() << endl;
	}
	else
	{
		for (int i = 0; !file.eof(); i++)
		{
			file >> fpassnum >> fname >> fage >> fregion >> fseat >> fentrtday[0] >> fentrtday[1] >> fentrtday[2] >> fleaveday[0] >> fleaveday[1] >> fleaveday[2];

			elist[i] = new Entrylist(fpassnum, fname, fage, fregion, fseat, fentrtday, fleaveday);
		}
	}
	if (file.is_open() == true)
	{
		file.close();
	}
}

void createUser(Leavelist* llist[]) {

	int fpassnum, fage, fentrtday[3], fleaveday[3];
	string fname, fregion, fseat;
	ifstream file;

	file.open("leave.txt", ios::in);

	if (file.is_open() == false)
	{
		cout << "file is empty." << endl;
	}
	else
	{
		for (int i = 0; !file.eof(); i++)
		{
			file >> fpassnum >> fname >> fage >> fregion >> fseat >> fentrtday[0] >> fentrtday[1] >> fentrtday[2] >> fleaveday[0] >> fleaveday[1] >> fleaveday[2];

			llist[i] = new Leavelist(fpassnum, fname, fage, fregion, fseat, fentrtday, fleaveday);
		}
	}
	if (file.is_open() == true)
	{
		file.close();
	}
}

int main() {

	//initUser();	//	User 입력 함수
	FlightSchedule fs;
	ControlTower ct;
	Entrylist* elist[100];
	Leavelist* llist[100];

	while (true)	//	Menu 구성
	{
		// Menu 출력
		cout << "=== Menu ===" << endl;
		cout << "e : Entry Process" << endl;	//	입국 절차
		cout << "l : Leave Process" << endl;	//	출국 절차
		cout << "t : Ticketing" << endl;	// 티켓 발권
		cout << "o : OverEntryUser Check" << endl;	//	불법 체류자 체크
		cout << "i : File Input" << endl;
		cout << "q : Quit Program" << endl;	//	프로그램 종료

		switch (getchar())	//	menu switch문 : getchar()를 이용, 문자를 받아서 적용
		{
		case 'e':	//	입국 절차 메뉴
			fs.takeoff_check(0, ct);
			break;
		case 'l':	//	출국 절차 메뉴
			fs.takeoff_check(1, ct);
			break;
		case 't':	//	티켓 발권 메뉴

			break;
		case 'o':	//	불법 체류자 체크 메뉴

			break;

		case 'i':	//	이용자 정보 파일 입력 메뉴

			cout << "이용자 정보를 불러옵니다...." << endl;
			createUser(elist);
			createUser(llist);
			cout << "이용자 정보 불러오기 완료" << endl;

			break;
		case 'q':	//	프로그램 종료 메뉴
			cout << endl;
			cout << endl;
			cout << "end of program" << endl;
			return 0;	//	프로그램 종료
		default:	//	error 경고문 출력 (메뉴 잘못 입력시)
			cout << endl;
			cout << "error!! worng char" << endl;
			cout << endl;
			break;
		}
		while (getchar() != '\n');	//	getchar()사용시 버퍼에 입력값이 남아서 이중실행이 될 수 있기 때문에 버퍼를 비우는 작업을 한다.
	}
	
}