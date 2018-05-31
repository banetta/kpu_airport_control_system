//by YHS
#include "header\main_header.h"

void FlightSchedule::takeoff_check(int num, ControlTower &ct) {
	time_t timeCur; //�ð����� ����ü ����
	tm* ptmTemp; //�ð����� ������ ����
	time(&timeCur); //����ð� �Լ�
	ptmTemp = localtime(&timeCur); // time_t* -> struct tm*

	while (num != 'q') {
		char num2 = NULL;
		// �ⱹ��������
		while (num == 1) {
			int str = -1; //�Է¸������� ����������� �� ����
			int sum[4][2][4]; //���¼����� �޴� ����(������ ���� ����, ��������� ����, �ð������� ������ ���� �迭ũ�� ����)
			int m, n, k; //�¼������� �����ϴµ� �ʿ��� ����
			const char* time1[4], *time2[4]; //time1�� �̷������ð�, time2�� ����ð�
			const char* nation[4] = { "�Ϻ�","�߱�","�̱�","����" }; //�ӽ� ������(����)��������
			const char* pla[2] = { "�ƽþƳ�","�����װ�" }; //�ӽ� �������������

			while (str != 0) {
				cout << "----------------------------------------------------------" << endl;
				for (int i = 0; i < 4; i++) { //�������� ���� ���
					cout << i + 1 << ". [" << nation[i] << ']' << " ";
				}
				cout << "\n�������� �Է�(�ѱ�) > ";
				cin >> destination;
				int j = 0;
				do {
					str = strcmp(nation[j], destination);
					m = j; //�������� �������� �¼� ����ϱ� ���� ������ �����Ѵ�.
					j++; //strcmp�� �� ���ڰ� ���� ��ġ�ϸ� str==0�̹Ƿ� while���� �����.
				} while (str != 0 && j >= 0 && j < 4);

				if (str != 0) {
					cout << "�������� �������� �ʽ��ϴ�." << endl;
					cout << "��Ͽ� �ִ� �������� �Է��ϼ���." << endl;
				}
			}

			str = -1;
			while (str != 0) {
				cout << "----------------------------------------------------------" << endl;
				for (int i = 0; i < 2; i++) { //������� ���� ���
					cout << i + 1 << ". [" << pla[i] << ']' << " ";
				}
				cout << "\n�̿��� �װ��� �Է�(�ѱ�) > ";
				cin >> plane;
				int j = 0;
				do {
					str = strcmp(pla[j], plane);
					n = j; //�������� �������� �¼� ����ϱ� ���� ������ �����Ѵ�.
					j++; //strcmp�� �� ���ڰ� ���� ��ġ�ϸ� str==0�̹Ƿ� while���� �����.
				} while (str != 0 && j >= 0 && j < 2);
				if (str != 0) {
					cout << "�ش� �װ��簡 �������� �ʽ��ϴ�." << endl;
					cout << "��Ͽ� �ִ� �װ��縸 �Է��ϼ���." << endl;
				}
			}
			if (destination == NULL || plane == NULL)
				return;
			else {
				cout << "----------------------------------------------------------" << endl;
				cout << "\t����ð� : " << ctime(&timeCur) << "\t\t[�����ⱹ��������]" << endl;
				cout << "----------------------------------------------------------" << endl;
				cout << " �װ��� | �����ð� | ����ð� | ����� | ������ | �ܿ��¼�" << endl;
				cout << "----------------------------------------------------------" << endl;

				for (int i = 0; i < 4; i++) { // �� �������� ���� �װ������� ���� �ʱ��¼��� �����ϴ� �ݺ���
					for (int j = 0; j < 2; j++) {
						for (int n = 0; n < 4; n++) {
							sum[i][j][n] = Se[i][j].initseat();
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					if (i == 0) {
						time1[i] = "08:55"; // ù��° �����ð�
						time2[i] = time1[i]; // �װ������ð��� �̷������ ���� ��� ���� ������ ����.
						if (ct.runway_check() == 0)  //Ȱ�ַΰ� ������ �ⱹ�������� ���� ����ð��� ������
							time2[i] = "09:25";
						else if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //���ܰ谡 4,5�̸� ����ð��� ������
							time2[i] = "09:55";
					}
					else if (i == 1) {
						time1[i] = "13:15"; // �ι�° �����ð�
						time2[i] = time1[i]; // �װ������ð��� �̷������ ���� ��� ���� ������ ����.
						if (ct.runway_check() == 0) //Ȱ�ַΰ� ������ �ⱹ�������� ���� ����ð��� ������
							time2[i] = "13:55";
						else if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //���ܰ谡 4,5�̸� ����ð��� ������
							time2[i] = "14:15";
					}
					else if (i == 2) {
						time1[i] = "17:35"; // ����° �����ð�
						time2[i] = time1[i]; // �װ������ð��� �̷������ ���� ��� ���� ������ ����.
						if (ct.runway_check() == 0) { //Ȱ�ַΰ� ������ �ⱹ�������� ���� ����ð��� ������
							time2[i] = "18:05";
						}
						else if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //���ܰ谡 4,5�̸� ����ð��� ������
							time2[i] = "18:35";
					}
					else if (i == 3) {
						time1[i] = "21:05"; // �׹�° �����ð�
						time2[i] = time1[i]; // �װ������ð��� �̷������ ���� ��� ���� ������ ����.
						if (ct.runway_check() == 0)  //Ȱ�ַΰ� ������ �ⱹ�������� ���� ����ð��� ������
							time2[i] = "21:35";
						else if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //���ܰ谡 4,5�̸� ����ð��� ������
							time2[i] = "22:05";
					}
					cout << plane << "|  " << time1[i] << "   |" << "  " << time2[i] << "   |" << "  " << "�ѱ�" << "  |"
						<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
					num = NULL;
				}
			}
		}

		//�Ա���������
		while (num == 0) {
			int str = -1; //�Է¸������� ����������� �� ����
			int sum[4][2][4]; //���¼����� �޴� ����(������ ���� ����, ��������� ����, �ð������� ������ ���� �迭ũ�� ����)
			int m, n, k; //�¼������� �����ϴµ� �ʿ��� ����
			const char* time1[4], *time2[4]; //time1�� �̷������ð�, time2�� ����ð�

			const char* nation[4] = { "�Ϻ�","�߱�","�̱�","����" }; //�ӽ� ������(����)��������
			const char* pla[2] = { "�ƽþƳ�","�����װ�" }; //�ӽ� �������������
			int j = 0;
			do {
				str = strcmp(nation[j], destination);
				m = j; //�������� �������� �¼� ����ϱ� ���� ������ �����Ѵ�.
				j++; //strcmp�� �� ���ڰ� ���� ��ġ�ϸ� str==0�̹Ƿ� while���� �����.
			} while (str != 0 && j >= 0 && j < 4);

			str = -1;
			while (str != 0) {
				cout << "----------------------------------------------------------" << endl;
				for (int i = 0; i < 2; i++) { //������� ���� ���
					cout << i + 1 << ". [" << pla[i] << ']' << " ";
				}
				cout << "\n�̿��� �װ��� �Է�(�ѱ�) > ";
				cin >> plane;
				int j = 0;
				do {
					str = strcmp(pla[j], plane);
					n = j; //�������� �������� �¼� ����ϱ� ���� ������ �����Ѵ�.
					j++; //strcmp�� �� ���ڰ� ���� ��ġ�ϸ� str==0�̹Ƿ� while���� �����.
				} while (str != 0 && j >= 0 && j < 2);
				if (str != 0) {
					cout << "�ش� �װ��簡 �������� �ʽ��ϴ�." << endl;
					cout << "��Ͽ� �ִ� �װ��縸 �Է��ϼ���." << endl;
				}
			}
			if (destination == NULL || plane == NULL)
				return;
			else {
				cout << "----------------------------------------------------------" << endl;
				cout << "\t����ð� : " << ctime(&timeCur) << "\t\t[�����Ա���������]" << endl;
				cout << "----------------------------------------------------------" << endl;
				cout << " �װ��� | �����ð� | ����ð� | ������ | �ܿ��¼�" << endl;
				cout << "----------------------------------------------------------" << endl;

				for (int i = 0; i < 4; i++) { // �� �������� ���� �װ������� ���� �ʱ��¼��� �����ϴ� �ݺ���
					for (int j = 0; j < 2; j++) {
						for (int n = 0; n < 4; n++) {
							sum[i][j][n] = Se[i][j].initseat();
						}
					}
				}
				for (int i = 0; i < 4; i++) {
					if (i == 0) {
						time1[i] = "08:55"; // ù��° �����ð�
						time2[i] = time1[i]; // �װ������ð��� �̷������ ���� ��� ���� ������ ����.
						if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //���ܰ谡 4,5�̸� ����ð��� ������
							time2[i] = "09:55";
					}
					else if (i == 1) {
						time1[i] = "13:15"; // �ι�° �����ð�
						time2[i] = time1[i]; // �װ������ð��� �̷������ ���� ��� ���� ������ ����.
						if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //���ܰ谡 4,5�̸� ����ð��� ������
							time2[i] = "14:15";
					}
					else if (i == 2) {
						time1[i] = "17:35"; // ����° �����ð�
						time2[i] = time1[i]; // �װ������ð��� �̷������ ���� ��� ���� ������ ����.
						if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //���ܰ谡 4,5�̸� ����ð��� ������
							time2[i] = "18:35";
					}
					else if (i == 3) {
						time1[i] = "21:05"; // �׹�° �����ð�
						time2[i] = time1[i]; // �װ������ð��� �̷������ ���� ��� ���� ������ ����.
						if (ct.weathercenter_check() == 4 || ct.weathercenter_check() == 5) //���ܰ谡 4,5�̸� ����ð��� ������
							time2[i] = "22:05";
					}
					cout << plane << "|  " << time1[i] << "   |" << "  " << time2[i] << "   |" << "  " << "�ѱ�" << "  |" << "  " << sum[m][n][i] << endl;
					num = -1;
				}
			}
		}

		while (true)
		{
			cout << "----------------------------------------------------------" << endl;
			cout << "e : �Ա�������������" << endl;
			cout << "l : �ⱹ������������" << endl;
			cout << "q : �޴��� ������ " << endl;
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
				cout << "�߸��� �Է��Դϴ�." << endl;
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
