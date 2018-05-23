//by YHS
#include "header\main_header.h"

void FlightSchedule::takeoff_check() {
	time_t timeCur; //시간관련 구조체 생성
	tm* ptmTemp; //시간관련 포인터 생성
	time(&timeCur); //현재시간 함수
	ptmTemp = localtime(&timeCur); // time_t* -> struct tm*

	int str=-1; //입력목적지와 목적지목록의 비교 변수
	int sum[4][2][4]; //총좌석수를 받는 변수(목적지 종류 갯수, 비행기종류 갯수, 시간종류의 갯수에 따라 배열크기 변동)
	int m, n, k; //좌석정보를 저장하는데 필요한 변수
	char *time1, *time2; //time1은 예정시각, time2는 변경시각
	char* nation[4] = { "일본","중국","미국","독일" }; //임시 목적지(국가)종류설정
	char* pla[2] = { "아시아나","대한항공" }; //임시 비행기종류설정

	while (str!=0) {
		cout << "----------------------------------------------------------" << endl;
		for (int i = 0; i < 4; i++) { //목적지의 종류 출력
			cout << i + 1 << ". [" << nation[i] << ']' << " ";
		}
		cout << "\n목적지를 입력하세요 > ";
		cin >> destination;
		int j = 0;
		do {
			str = strcmp(nation[j], destination);
			m = j; //목적지의 번지수를 좌석 출력하기 위한 변수에 저장한다.
			j++; //strcmp의 두 인자가 서로 일치하면 str==0이므로 while문을 벗어난다.
		} while (str != 0 && j >= 0 && j < 4);

		if (str != 0) {
			cout << "목적지가 존재하지 않습니다." << endl;
			cout << "목록에 있는 목적지만 입력하세요." << endl;
		}
	}

	str = -1;
	while (str != 0) {
		cout << "----------------------------------------------------------" << endl;
		for (int i = 0; i < 2; i++) { //비행기의 종류 출력
			cout << i + 1 << ". [" << pla[i] << ']' << " ";
		}
		cout << "\n어떤 비행기를 이용하시겠습니까? > ";
		cin >> plane;
		int j = 0;
		do {
			str = strcmp(pla[j], plane);
			n = j; //목적지의 번지수를 좌석 출력하기 위한 변수에 저장한다.
			j++; //strcmp의 두 인자가 서로 일치하면 str==0이므로 while문을 벗어난다.
		} while (str != 0 && j >= 0 && j < 2);
		if (str != 0) {
			cout << "해당 비행기가 존재하지 않습니다." << endl;
			cout << "목록에 있는 비행기만 입력하세요." << endl;
		}
	}

	if (destination == NULL || plane == NULL)
		return;
	else {
		cout << "----------------------------------------------------------" << endl;
		cout << "\t현재시각 : " << ctime(&timeCur) << "\t\t[금일비행일정]" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << " 항공편 | 예정시각 | 변경시각 | 출발지 | 도착지 | 잔여좌석" << endl;
		cout << "----------------------------------------------------------" << endl;
		time1 = new char; //time1 포인터내의 공간을 만들어 런타임 오류를 방지한다.
		time2 = new char; //time2 포인터내의 공간을 만들어 런타임 오류를 방지한다.

		for (int i = 0; i < 4; i++) { // 각 목적지에 따른 항공종류에 따라 초기좌석을 저장하는 반복문
			for (int j = 0; j < 2; j++) {
				for (int n = 0; n < 4; n++) {
					sum[i][j][n] = Se[i][j].initseat();
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				strcpy(time1, "08:55");
				strcpy(time2, time1);
				cout << plane << "|  " << time1 << "   |" << "  " << time2 << "   |" << "  " << "한국" << "  |"
					<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
			}
			else if (i == 1) {
				strcpy(time1, "13:05");
				strcpy(time2, time1);
				cout << plane << "|  " << time1 << "   |" << "  " << time2 << "   |" << "  " << "한국" << "  |"
					<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
			}
			else if (i == 2) {
				strcpy(time1, "18:35");
				strcpy(time2, time1);
				cout << plane << "|  " << time1 << "   |" << "  " << time2 << "   |" << "  " << "한국" << "  |"
					<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
			}
			else if (i == 3) {
				strcpy(time1, "21:00");
				strcpy(time2, time1);
				cout << plane << "|  " << time1 << "   |" << "  " << time2 << "   |" << "  " << "한국" << "  |"
					<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
			}
			else //관제탑 추가 후 수정할 예정 
				strcpy(time2, "10:30");
		}
	}
		//Se[0][0].Addseat();

}
