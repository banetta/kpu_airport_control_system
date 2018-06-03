//by YHS
#include "header\main_header.h"

FlightSchedule::FlightSchedule(string fairline, string fdestination, int* fseat, int fhour, string fshit, int fmin)
	: airline(fairline), destination(fdestination), hour(fhour), shit(fshit)
{
	min = fmin;
	for (int i = 0; i < 3; i++)
	{
		seat[i] = fseat[i];
	}
}
void FlightSchedule::showthat()
{
	if (min == 0)
		cout << setw(18) << airline << "\t" << setw(13) << destination << "\t\t" << setw(3) << seat[0] << "\t" << setw(12) << seat[1] << "\t" << setw(12) << seat[2] << "\t" << setw(7) << hour << shit << "0" << min << endl;
	else
		cout << setw(18) << airline << "\t" << setw(13) << destination << "\t\t" << setw(3) << seat[0] << "\t" << setw(12) << seat[1] << "\t" << setw(12) << seat[2] << "\t" << setw(7) << hour << shit << min << endl;
}

void FlightSchedule::takeoff_check(ControlTower &ct)
{
	int set, set2;
	int i = 0;

	while (i == 0)
	{
		set = ct.weathercenter_check(); // 기상청
		set2 = ct.runway_check(); // 활주로

		if (min >= 60)
		{
			min -= 60;
			hour = +1;
		}
		showthat();
		if (set > 3 && set2 >0)
		{
			cout << setw(20) << "Delay in Airplain, " << "Reason : Bad weather. \n" << endl;
			min += 30;
		}
		else  if (set2 == 0 && set < 4)
		{
			cout << setw(20) << "Delay in Airplain, " << "Reason : Runway exceeded. \n" << endl;
			min += 10;
		}
		else if (set > 3 && set2 == 0) {
			cout << setw(20) << "Delay in Airplain, " << "Reason : Bad weather and Runway exceeded. \n" << endl;
			min += 40;
		}
		else
		{
			cout << setw(20) << "complete.\n" << endl;
			i = 1;
		}
	}
}