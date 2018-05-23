//by YHS
#include "header\main_header.h"

void FlightSchedule::takeoff_check() {
	time_t timeCur; //�ð����� ����ü ����
	tm* ptmTemp; //�ð����� ������ ����
	time(&timeCur); //����ð� �Լ�
	ptmTemp = localtime(&timeCur); // time_t* -> struct tm*

	int str=-1; //�Է¸������� ����������� �� ����
	int sum[4][2][4]; //���¼����� �޴� ����(������ ���� ����, ��������� ����, �ð������� ������ ���� �迭ũ�� ����)
	int m, n, k; //�¼������� �����ϴµ� �ʿ��� ����
	char *time1, *time2; //time1�� �����ð�, time2�� ����ð�
	char* nation[4] = { "�Ϻ�","�߱�","�̱�","����" }; //�ӽ� ������(����)��������
	char* pla[2] = { "�ƽþƳ�","�����װ�" }; //�ӽ� �������������

	while (str!=0) {
		cout << "----------------------------------------------------------" << endl;
		for (int i = 0; i < 4; i++) { //�������� ���� ���
			cout << i + 1 << ". [" << nation[i] << ']' << " ";
		}
		cout << "\n�������� �Է��ϼ��� > ";
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
		cout << "\n� ����⸦ �̿��Ͻðڽ��ϱ�? > ";
		cin >> plane;
		int j = 0;
		do {
			str = strcmp(pla[j], plane);
			n = j; //�������� �������� �¼� ����ϱ� ���� ������ �����Ѵ�.
			j++; //strcmp�� �� ���ڰ� ���� ��ġ�ϸ� str==0�̹Ƿ� while���� �����.
		} while (str != 0 && j >= 0 && j < 2);
		if (str != 0) {
			cout << "�ش� ����Ⱑ �������� �ʽ��ϴ�." << endl;
			cout << "��Ͽ� �ִ� ����⸸ �Է��ϼ���." << endl;
		}
	}

	if (destination == NULL || plane == NULL)
		return;
	else {
		cout << "----------------------------------------------------------" << endl;
		cout << "\t����ð� : " << ctime(&timeCur) << "\t\t[���Ϻ�������]" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << " �װ��� | �����ð� | ����ð� | ����� | ������ | �ܿ��¼�" << endl;
		cout << "----------------------------------------------------------" << endl;
		time1 = new char; //time1 �����ͳ��� ������ ����� ��Ÿ�� ������ �����Ѵ�.
		time2 = new char; //time2 �����ͳ��� ������ ����� ��Ÿ�� ������ �����Ѵ�.

		for (int i = 0; i < 4; i++) { // �� �������� ���� �װ������� ���� �ʱ��¼��� �����ϴ� �ݺ���
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
				cout << plane << "|  " << time1 << "   |" << "  " << time2 << "   |" << "  " << "�ѱ�" << "  |"
					<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
			}
			else if (i == 1) {
				strcpy(time1, "13:05");
				strcpy(time2, time1);
				cout << plane << "|  " << time1 << "   |" << "  " << time2 << "   |" << "  " << "�ѱ�" << "  |"
					<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
			}
			else if (i == 2) {
				strcpy(time1, "18:35");
				strcpy(time2, time1);
				cout << plane << "|  " << time1 << "   |" << "  " << time2 << "   |" << "  " << "�ѱ�" << "  |"
					<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
			}
			else if (i == 3) {
				strcpy(time1, "21:00");
				strcpy(time2, time1);
				cout << plane << "|  " << time1 << "   |" << "  " << time2 << "   |" << "  " << "�ѱ�" << "  |"
					<< "  " << destination << "  |" << "  " << sum[m][n][i] << endl;
			}
			else //����ž �߰� �� ������ ���� 
				strcpy(time2, "10:30");
		}
	}
		//Se[0][0].Addseat();

}
