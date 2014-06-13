#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timetable.h"
#include <termios.h>

//GETCH INFO CODE--IGNORE

static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}
//END OF GETCH
////////////
///////////
/////
struct entry table[51];
void print(struct entry tab[]);
void tinit(struct entry tab[]);
void err(int n);
main(){
	tinit(table);
	print(table);
	printf("\n\tWelcome to the TimeTabler!\n");
	int com,dchoice,hchoice;
	char cchoice[30];
	printf("\tOkay, we are ready to make the table, please follow the code provided and use it\n");
	printf("\t1: To enter the course selection. Press this key if you encounter any clash errors!\n");
	printf("\t2: Print the existing time-table on the screen. The table is anyway, printed after every change.\n");
	printf("\t3: To delete a course selection\n");
	printf("\t(C)Lynch-Envy Computer Corp. 2013\n");
	while(com!=-1){printf(">>");scanf("%d", &com);
	//switch(com){
	//	case(1):
	if(com==1){		
			printf("Please enter the day in which you want to make an entry..\n");
			scanf("%d", &dchoice);
			printf("Right, now, please enter the hour in which you want to make an entry..\n");
			scanf("%d", &hchoice);
			printf("So, you have taken the %dth hour. Good. Now, please enter the course..\n",hchoice);
			scanf("%s", cchoice);
			printf("Your choice of Day %d, Hour %d and Course  %s is being updated. Please wait.\n", dchoice, hchoice, cchoice); 
			if(dchoice == 1){	
				table[hchoice].hour  = hchoice;
				table[hchoice].day   = MON;
				if(table[hchoice].sstat!=FULL) {table[hchoice].sstat = FULL; strcpy(table[hchoice].course, cchoice);}
				else err(1);
				}
			else if(dchoice == 2){	
				table[hchoice+9].hour  = hchoice;
				table[hchoice+9].day   = TUE;
				if(table[hchoice+9].sstat!=FULL) {table[hchoice+9].sstat = FULL; strcpy(table[hchoice+9].course, cchoice);}
				else err(1);
				}
			else if(dchoice == 3){	
				table[hchoice+18].hour  = hchoice;
				table[hchoice+18].day   = WED;
				if(table[hchoice+18].sstat!=FULL) {table[hchoice+18].sstat = FULL; strcpy(table[hchoice+18].course, cchoice);}
				else err(1);
				}
			else if(dchoice == 4){	
				table[hchoice+27].hour  = hchoice;
				table[hchoice+27].day   = THU;
				if(table[hchoice+27].sstat!=FULL) {table[hchoice+27].sstat = FULL; strcpy(table[hchoice+27].course, cchoice);}
				else err(1);
				}
			else if(dchoice == 5){	
				table[hchoice+36].hour  = hchoice;
				table[hchoice+36].day   = FRI;
				if(table[hchoice+36].sstat!=FULL) {table[hchoice+36].sstat = FULL; strcpy(table[hchoice+36].course, cchoice);}
				else err(1);
				}
			else if(dchoice == 6){	
				table[hchoice+45].hour  = hchoice;
				table[hchoice+45].day   = SAT;
				if(table[hchoice+45].sstat!=FULL) {table[hchoice+45].sstat = FULL; strcpy(table[hchoice+45].course, cchoice);}
				else err(1);
				}
						
			else err(2);}
		else if(com==2)
			print(table);
		else if(com==3){
			printf("\nYou have chosen to edit. Please follow the instructions below\n");
			printf("Please enter the day in which you want to make an edit..\n");
			scanf("%d", &dchoice);
			printf("Right, now, please enter the hour in which you want to make an edit..\n");
			scanf("%d", &hchoice);
			//printf("So, you have taken the %dth hour. Good. Now, please enter the course a..\n",hchoice);
			//scanf("%s", cchoice);
			//printf("Your choice of Day %d, Hour %d and Course  %s is being updated. Please wait.\n", dchoice, hchoice, cchoice); 
			if(dchoice == 1){	
				table[hchoice].sstat = AVAILABLE; 
				strcpy(table[hchoice].course, " ");}
				
			else if(dchoice == 2){
				table[hchoice+9].sstat = AVAILABLE; 
				strcpy(table[hchoice+9].course, " ");
				}
			else if(dchoice == 3){	
				table[hchoice+18].sstat = AVAILABLE; 
				strcpy(table[hchoice+18].course, " ");
				}
			else if(dchoice == 4){	
				table[hchoice+27].sstat = AVAILABLE; 
				strcpy(table[hchoice+27].course, " ");
				}
			else if(dchoice == 5){	
				table[hchoice+36].sstat = AVAILABLE; 
				strcpy(table[hchoice+36].course, " ");
				
				}
			else if(dchoice == 6){	
				table[hchoice+45].sstat = AVAILABLE; 
				strcpy(table[hchoice+45].course, " ");
				}
						
			else err(2);
		}
	}
	}

//PRINT TABLE ROUTINE
void print(struct entry tab[]){
	int i;
	printf("Monday   |");
	for(i=1; i<=9; ++i){
		printf("%s\t", tab[i].course);
		}
	printf("\n");
	printf("Tuesday  |");
        for(i=10; i<=18; ++i){
                printf("%s\t", tab[i].course);
                }
        printf("\n");
	printf("Wednesday|");
        for(i=19; i<=27; ++i){
                printf("%s\t", tab[i].course);
                }
        printf("\n");
	printf("Thursday |");
        for(i=28; i<=36; ++i){
                printf("%s\t", tab[i].course);
                }
        printf("\n");
	printf("Friday   |");
        for(i=37; i<=45; ++i){
                printf("%s\t", tab[i].course);
                }
        printf("\n");
	printf("Saturday |");
        for(i=46; i<=50; ++i){
                printf("%s\t", tab[i].course);
                }
        printf("\n");
	
}

void tinit(struct entry tab[]){
	int i;
	for(i=1; i<=9; ++i){
		tab[i].day=MON;
		tab[i].sstat=AVAILABLE;		
		}
        for(i=10; i<=18; ++i){
                tab[i].day=TUE;
		tab[i].sstat=AVAILABLE;
                }
        for(i=19; i<=27; ++i){
                tab[i].day=WED;
		tab[i].sstat=AVAILABLE;
                }
        for(i=28; i<=36; ++i){
                tab[i].day=THU;
		tab[i].sstat=AVAILABLE;
                }
        for(i=37; i<=45; ++i){
                tab[i].day=FRI;
		tab[i].sstat=AVAILABLE;
                }
        for(i=46; i<=50; ++i){
                tab[i].day=SAT;
		tab[i].sstat=AVAILABLE;
		}
        printf("\n");
}

void err(int n){
	if(n==1) printf("You have a clash! Please repeat this course with a different hour selection!\n");
	else printf("Please enter one of the valid day options(1 through 6). Please read the codes carefully!\n");
}
