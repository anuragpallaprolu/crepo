#ifndef TIMETABLE_H
#define TIMETABLE
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define FULL 1
#define AVAILABLE 0
struct entry{
	char course[30];
	char day[2];
	int hour;
	int sstat;
	};
#endif



