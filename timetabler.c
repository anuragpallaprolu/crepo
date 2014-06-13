#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define YES 1
#define NO 0
struct entry{
	char day[50];
	int hour;
	char name[50];
	int room;
	int filled;
	}elist[50];
void pr_table(struct entry table[]){
	printf("Monday|");
	int i;
	for(i=0; i<=8; ++i){
		printf("%s ", table[i].name);
		}
	printf("\n");
	printf("Tuesday|");
   //     int i;
        for(i=9; i<=17; ++i){
                printf("%s ", table[i].name);
                }
        printf("\n");
	printf("Wednesday|");
     //   int i;
        for(i=18; i<=26; ++i){
                printf("%s ", table[i].name);
                }
        printf("\n");
	printf("Thursday|");
//        int i;
        for(i=27; i<=35; ++i){
                printf("%s ", table[i].name);
                }
        printf("\n");
	printf("Friday|");
  //      int i;
        for(i=36; i<=44; ++i){
                printf("%s ", table[i].name);
                }
        printf("\n");
	printf("Saturday|");
    //   int i;
        for(i=45; i<=49; ++i){
                printf("%s ", table[i].name);
                }
        printf("\n");
	
	}
main(){
	/*INIT PHASE HERE*/
	int i,j;
	for(i=0; i<=8; ++i){
		strcpy(elist[i].day, "Mon");
		elist[i].hour = i+1;
		}
	for(i=9; i<=17; ++i){
                strcpy(elist[i].day, "Tue");
		 elist[i].hour = 1+i-9;
     //           elist[i].et = 9+i-9;
                }
	for(i=18; i<=26; ++i){
                strcpy(elist[i].day, "Wed");
                elist[i].hour = 1+i-18;
               // elist[i].et = 9+i-18;
                }
	for(i=27; i<=35; ++i){
                strcpy(elist[i].day, "Thu");
                elist[i].hour = 1+i-27;
                //elist[i].et = 9+i-27;
                }
	for(i=36; i<=44; ++i){
                strcpy(elist[i].day, "Fri");
                elist[i].hour = 1+i-36;
                //elist[i].et = 9+i;
                }
	for(i=45; i<=49; ++i){
                strcpy(elist[i].day, "Sat");
                elist[i].hour = 1+i-45;
                //elist[i].et = 9+i-45;
                }
	pr_table(elist);	
	char com[100];
	int hourg;
	while(strcmp(com, "exit")!=0){
		scanf("%s", com);
		printf("Please enter the course name:\n");
		char course[100], d[100];
		//int hourg;
		scanf("%s", course);
		printf("Please enter the day:\n");
		scanf("%s", d);
		scanf("Please enter the hour:\n");
		scanf("%d",&hourg);
		if(strcmp(d, "Mon")==0){
			j = hourg-1;
			if(elist[j].filled == NO){
				strcpy(elist[j].day, d);
				strcpy(elist[j].name, course);
				elist[j].hour = hourg;
				}
			else err();
			}
		else if(strcmp(d, "Tue")==0){
                          j = hourg-1+9;
                          if(elist[j].filled == NO){
                                  strcpy(elist[j].day, d);
                                 strcpy(elist[j].name, course);
                                 elist[j].hour = hourg;
                                 }
                         else err();
                         }
		else if(strcmp(d, "Wed")==0){
                          j = hourg-1+18;
                          if(elist[j].filled == NO){
                                  strcpy(elist[j].day, d);
                                 strcpy(elist[j].name, course);
                                 elist[j].hour = hourg;
                                 }
                         else err();
                         }
		else if(strcmp(d, "Thu")==0){
                          j = hourg-1+27;
                          if(elist[j].filled == NO){
                                  strcpy(elist[j].day, d);
                                 strcpy(elist[j].name, course);
                                 elist[j].hour = hourg;
                                 }
                         else err();
                         }
		else if(strcmp(d, "Fri")==0){
                          j = hourg-1+36;
                          if(elist[j].filled == NO){
                                  strcpy(elist[j].day, d);
                                 strcpy(elist[j].name, course);
                                 elist[j].hour = hourg;
                                 }
                         else err();
                         }

		else if(strcmp(d, "Sat")==0){
                          j = hourg-1+45;
                          if(elist[j].filled == NO){
                                  strcpy(elist[j].day, d);
                                 strcpy(elist[j].name, course);
                                 elist[j].hour = hourg;
                                 }
                         else err();
                         }
			
		}
		pr_table(elist);	
}
