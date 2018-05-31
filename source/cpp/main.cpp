// Airport Control System Main Function
// coding by Banetta Han Sang Kim

// a

#include "header\main_header.h"

// 단일 함수 선언
void initUser();	//	User를 입력받는 함수

int main() {
	FlightSchedule fs;
	ControlTower ct;
	//initUser();	//	User 입력 함수
	while (true)	//	Menu 구성
	{
		// Menu 출력
		cout << "=== Menu ===" << endl;
		cout << "e : Entry Process" << endl;	//	입국 절차
		cout << "l : Leave Process" << endl;	//	출국 절차
		cout << "t : Ticketing" << endl;	// 티켓 발권
		cout << "o : OverEntryUser Check" << endl;	//	불법 체류자 체크
		cout << "q : Quit Program\n> ";	//	프로그램 종료
		switch (getchar())	//	menu switch문 : getchar()를 이용, 문자를 받아서 적용
		{
		case 'e':	//	입국 절차 메뉴
			fs.takeoff_check(0,ct);
			break;
		case 'l':	//	출국 절차 메뉴
			fs.takeoff_check(1,ct);
			break;
		case 't':	//	티켓 발권 메뉴

			break;
		case 'o':	//	불법 체류자 체크 메뉴

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

//void initUser() {	//	User 입력 함수 시뮬레이션을 위해 임시로 입력하지만 파일입출력으로 대체 가능
//	
//	User* user_list[10];	//	시뮬레이션에 필요한 User 10명 선언
//	for (int i = 0; i < 9; i++)	//	User 정보 입력
//	{
//		user_list[i] = new User("Kim", "23");	//	stack절약을 위해 동적선언
//	}
//}