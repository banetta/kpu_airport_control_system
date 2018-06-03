// Airport Control System Main Function
// coding by Banetta Han Sang Kim

#include "header\main_header.h"

int main() {

	FlightSchedule* fs[100];
	ControlTower ct;
	Entrylist* elist[200];
	Leavelist* llist[200];
	Entrylist* banlist[20];


	while (true)	//	Menu 구성
	{
		// Menu 출력
		cout << "=== Menu ===" << endl;
		cout << "i : File Input" << endl;
		cout << "e : Entry Process" << endl;	//	입국 절차
		cout << "l : Leave Process" << endl;	//	출국 절차
		cout << "t : Today Airplain list" << endl;	// 금일 입출항 목록
		cout << "a : Airplain Access Management" << endl;	// 항공기 입출항 관리
		cout << "o : OverEntryUser Check" << endl;	//	불법 체류자 체크
		cout << "q : Quit Program" << endl;	//	프로그램 종료

		switch (getchar())	//	menu switch문 : getchar()를 이용, 문자를 받아서 적용
		{
		case 'i':	//	이용자 정보 파일 입력 메뉴
			cout << "금일 항공기 입출항 정보를 불러옵니다";
			createFlightSchedule(fs);
			Sleep(400); cout << '.';  Sleep(400); cout << '.'; Sleep(400); cout << '.'; Sleep(400); cout << '.' << endl;
			Sleep(400);
			cout << "금일 항공기 입출항 정보 불러오기 완료" << endl;
			Sleep(200);
			cout << "이용자 정보를 불러옵니다";
			createUser(elist);
			createUser(llist);
			createban(banlist);
			Sleep(400); cout << '.';  Sleep(400); cout << '.'; Sleep(400); cout << '.'; Sleep(400); cout << '.' << endl;
			Sleep(200);
			cout << "이용자 정보 불러오기 완료" << endl;
			Sleep(200);
			break;
		case 'e':	//	입국 절차 메뉴
			while (getchar() != '\n');
			leaveprocess(elist);
			break;
		case 'l':	//	출국 절차 메뉴
			while (getchar() != '\n');
			leaveprocess(llist);
			break;
		case 't':	//	금일 입출항 목록
			while (getchar() != '\n');
			Airplainlist(fs);
			break;
		case 'a':	//	비행기 입출항 관리 메뉴
			while (getchar() != '\n');
			Airlinemanagement(fs, ct);
			break;
		case 'o':	//	불법 체류자 체크 메뉴
			while (getchar() != '\n');
			Illegal_resident(banlist);
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