//by YHS
#include "header\main_header.h"

void FlightSchedule::takeoff_check(int num, ControlTower &ct) {
	time_t timeCur; //시간관련 구조체 생성
	tm* ptmTemp; //시간관련 포인터 생성
	time(&timeCur); //현재시간 함수
	ptmTemp = localtime(&timeCur); // time_t* -> struct tm*

	while (num != 'q') {
		char num2 = NULL;
		// 출국비행일정
		while (num == 1) {
			int str = -1; //입력목적지와 목적지목록의 비교 변수
			int sum[4][2][4]; //총좌석수를 받는 변수(목적지 종류 갯수, 비행기종류 갯수, 시간종류의 갯수에 따라 배열크기 변동)
			int m, n, k; //좌석정보를 저장하는데 필요한 변수
			const char* time1[4], *time2[4]; //time1은 이륙예정시각, time2는 변경시각
			const char* nation[4] = { "일본","중국","미국","독일" }; //임시 목적지(국가)종류설정
			const char* pla[2] = { "아시아나","대한항공" }; //임시 비행기종류설정

			while (str != 0) {
				cout << "----------------------------------------------------------" << endl;
				for (int i = 0; i < 4; i++) { //목적지의 종류 출력
					cout << i + 1 << ". [" << nation[i] << ']' << " ";
				}
				cout << "\n목적지를 입력(한글) > ";
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
				cout << "\n이용할 항공사 입력(한글) > ";
				cin >> plane;
				int j = 0;
				do {
					str = strcmp(pla[j], plane);
					n = j; //목적지의 번지수를 좌석 출력하기 위한 변수에 저장한다.
					j++; //strcmp의 두 인자가 서로 일치하면 str==0이므로 while문을 벗어난다.
				} while (str != 0 && j >= 0 && j < 2);
				if (str != 0) {
					cout << "해당 항공사가 존재하지 않습니다." << endl;
					cout << "목록에 있는 항공사만 입력하세요." << endl;
				}
			}
			if (destination == NULL || plane == NULL)
				return;
			else {
				cout << "----------------------------------------------------------" << endl;
				cout << "\t현재시각 : " << ctime(&timeCur) << "\t\t[금일출국비행일정]" << endl;
				cout << "----------------------------------------------------------" << endl;
				cout << " 항공편 | 예정시각 | 변경시각 | 출발지 | 도착지 | 잔여좌석" << endl;
				cout << "----------------------------------------------------------" << endl;

				for (int i = 0; i < 4; i++) { // 각 목적지에 따른 항공종류에 따라 초기좌석을 저장하는 반복문
					for (int j = 0; j < 2; j++) {
						for (int n = 0; n < 4; n++) {
							sum[i][j][n] = Se[i][j].initseat();
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					if (i == 0) {
						time1[i] = "08:55"; // 첫번째 예정시각
						time2[i] = time1[i]; // 항공지연시간이 이루어지지 않을 경우 값은 변하지 않음.
						if (ct.runway_check() == 0)  //활주로가 없으면 출국지연으로 인해 변경시각이 변동됨
							time2[i] = "09:25";
						else if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //기상단계가 4,5이면 변경시각이 변동됨
							time2[i] = "09:55";
					}
					else if (i == 1) {
						time1[i] = "13:15"; // 두번째 예정시각
						time2[i] = time1[i]; // 항공지연시간이 이루어지지 않을 경우 값은 변하지 않음.
						if (ct.runway_check() == 0) //활주로가 없으면 출국지연으로 인해 변경시각이 변동됨
							time2[i] = "13:55";
						else if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //기상단계가 4,5이면 변경시각이 변동됨
							time2[i] = "14:15";
					}
					else if (i == 2) {
						time1[i] = "17:35"; // 세번째 예정시각
						time2[i] = time1[i]; // 항공지연시간이 이루어지지 않을 경우 값은 변하지 않음.
						if (ct.runway_check() == 0) { //활주로가 없으면 출국지연으로 인해 변경시각이 변동됨
							time2[i] = "18:05";
						}
						else if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //기상단계가 4,5이면 변경시각이 변동됨
							time2[i] = "18:35";
					}
					else if (i == 3) {
						time1[i] = "21:05"; // 네번째 예정시각
						time2[i] = time1[i]; // 항공지연시간이 이루어지지 않을 경우 값은 변하지 않음.
						if (ct.runway_check() == 0)  //활주로가 없으면 출국지연으로 인해 변경시각이 변동됨
							time2[i] = "21:35";
						else if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //기상단계가 4,5이면 변경시각이 변동됨
							time2[i] = "22:05";
					}
					cout << plane << "|  " << time1[i] << "   |" << "  " << time2[i] << "   |" << "  " << "한국" << "  |"
						<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
					num = NULL;
				}
			}
		}

		//입국비행일정
		while (num == 0) {
			int str = -1; //입력목적지와 목적지목록의 비교 변수
			int sum[4][2][4]; //총좌석수를 받는 변수(목적지 종류 갯수, 비행기종류 갯수, 시간종류의 갯수에 따라 배열크기 변동)
			int m, n, k; //좌석정보를 저장하는데 필요한 변수
			const char* time1[4], *time2[4]; //time1은 이륙예정시각, time2는 변경시각

			const char* nation[4] = { "일본","중국","미국","독일" }; //임시 목적지(국가)종류설정
			const char* pla[2] = { "아시아나","대한항공" }; //임시 비행기종류설정
			int j = 0;
			do {
				str = strcmp(nation[j], destination);
				m = j; //목적지의 번지수를 좌석 출력하기 위한 변수에 저장한다.
				j++; //strcmp의 두 인자가 서로 일치하면 str==0이므로 while문을 벗어난다.
			} while (str != 0 && j >= 0 && j < 4);

			str = -1;
			while (str != 0) {
				cout << "----------------------------------------------------------" << endl;
				for (int i = 0; i < 2; i++) { //비행기의 종류 출력
					cout << i + 1 << ". [" << pla[i] << ']' << " ";
				}
				cout << "\n이용할 항공사 입력(한글) > ";
				cin >> plane;
				int j = 0;
				do {
					str = strcmp(pla[j], plane);
					n = j; //목적지의 번지수를 좌석 출력하기 위한 변수에 저장한다.
					j++; //strcmp의 두 인자가 서로 일치하면 str==0이므로 while문을 벗어난다.
				} while (str != 0 && j >= 0 && j < 2);
				if (str != 0) {
					cout << "해당 항공사가 존재하지 않습니다." << endl;
					cout << "목록에 있는 항공사만 입력하세요." << endl;
				}
			}
			if (destination == NULL || plane == NULL)
				return;
			else {
				cout << "----------------------------------------------------------" << endl;
				cout << "\t현재시각 : " << ctime(&timeCur) << "\t\t[금일입국비행일정]" << endl;
				cout << "----------------------------------------------------------" << endl;
				cout << " 항공편 | 예정시각 | 변경시각 | 도착지 | 잔여좌석" << endl;
				cout << "----------------------------------------------------------" << endl;

				for (int i = 0; i < 4; i++) { // 각 목적지에 따른 항공종류에 따라 초기좌석을 저장하는 반복문
					for (int j = 0; j < 2; j++) {
						for (int n = 0; n < 4; n++) {
							sum[i][j][n] = Se[i][j].initseat();
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					if (i == 0) {
						time1[i] = "08:55"; // 첫번째 예정시각
						time2[i] = time1[i]; // 항공지연시간이 이루어지지 않을 경우 값은 변하지 않음.
						if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //기상단계가 4,5이면 변경시각이 변동됨
							time2[i] = "09:55";
					}
					else if (i == 1) {
						time1[i] = "13:15"; // 두번째 예정시각
						time2[i] = time1[i]; // 항공지연시간이 이루어지지 않을 경우 값은 변하지 않음.
						if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //기상단계가 4,5이면 변경시각이 변동됨
							time2[i] = "14:15";
					}
					else if (i == 2) {
						time1[i] = "17:35"; // 세번째 예정시각
						time2[i] = time1[i]; // 항공지연시간이 이루어지지 않을 경우 값은 변하지 않음.
						if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //기상단계가 4,5이면 변경시각이 변동됨
							time2[i] = "18:35";
					}
					else if (i == 3) {
						time1[i] = "21:05"; // 네번째 예정시각
						time2[i] = time1[i]; // 항공지연시간이 이루어지지 않을 경우 값은 변하지 않음.
						if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //기상단계가 4,5이면 변경시각이 변동됨
							time2[i] = "22:05";
					}
					cout << plane << "|  " << time1[i] << "   |" << "  " << time2[i] << "   |" << "  " << "한국" << "  |" << "  " << sum[m][n][i] << endl;
					num = -1;
				}
			}
		}

		while (true)
		{
			cout << "----------------------------------------------------------" << endl;
			cout << "e : 입국비행일정보기" << endl;
			cout << "l : 출국비행일정보기" << endl;
			cout << "q : 메뉴로 나가기 " << endl;
			cout << "----------------------------------------------------------\n> ";
			switch (getchar()) {
			case 'e':
				num = 0;
				break;
			case  'l':
				num = 1;
				break;
			case 'q':
				num = 'q';
				return;
			default:
				cout << "잘못된 입력입니다." << endl;
				break;
			}
			while (getchar() != '\n');
		}
	}
}

void FlightSchedule::takeoff_init() {

}

void FlightSchedule::landing_init() {

}
