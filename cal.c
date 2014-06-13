#include <stdio.h>

main(){
       int numofcases, i;
       scanf("%d", &numofcases);
       int input[numofcases][2];
       for(i=1; i<=numofcases; ++i){
                scanf("%d %d", &input[i][1], &input[i][2]);
                }
       for(i=1; i<=numofcases; ++i){
                if((input[i][2]%4 != 0 && input[i][2]%100 == 0) || input[i][2]%400 != 0 ){
                                 if(input[i][1] <= 7){
                                                if(input[i][1]%2 != 0){
                                                                 int days[31], j;
                                                                 int month;
                                                                 if(input[i][1] == 1) month = 11;
                                                                 else month = input[i][1] - 2;
                                                                 int mcount = 2.6*month - 0.2;
                                                                 int century = (input[i][2] - (input[i][2]%100))/100;
                                                                 int year;
                                                                 if(input[i][1] == 1)  year = input[i][2]%100 - 1;
                                                                 else year = input[i][2]%100;
                                                                 for(j=1; j<=31; ++j) days[j] = j+mcount-(2*century) + year + (year/4) + (century/4);  
                                                                  for(j=1; j<=31; ++j){
                                                           if(days[j]%7 == 0){
                                                                        printf("%d ", j);
                                                                        }
                                                                        }
                                                           }
                                                 else{
                                                      int days[30], j, febdays[28];
                                                                 int month;
                                                                 if(input[i][1] == 2) month = 12;
                                                                 else month = input[i][1] - 2;
                                                                 int mcount = 2.6*month - 0.2;
                                                                 int century = (input[i][2] - (input[i][2]%100))/100;
                                                                 int year;
                                                                 if(input[i][1] == 2)  year = input[i][2]%100 - 1;
                                                                 else year = input[i][2]%100;
                                                                 for(j=1; j<=30; ++j) days[j] = j+mcount-(2*century) + year + (year/4) + (century/4);  
                                                                 for(j=1; j<=28; ++j) febdays[j] = j+mcount-(2*century) + year + (year/4) + (century/4);
                                                                  for(j=1; j<=30; ++j){
                                                           if(days[j]%7 == 0 && input[i][1]!=2){
                                                                        printf("%d ", j);
                                                                        }
                                                           else if(febdays[j]%7 == 0 && input[i][1] == 2){
                                                                                printf("%d ", j);
                                                                                }
                                                                        }
                                                           }
                                                       
                                                }
                                 else{
                                      int k;
                                      k = input[i][1] - 1;
                                      
                                      
                                      
                                      
                                      
                                      if(k%2 != 0){
                                                                 int days[31], j;
                                                                 int month;
                                                                 if(input[i][1] == 1) month = 11;
                                                                 else month = input[i][1] - 2;
                                                                 int mcount = 2.6*month - 0.2;
                                                                 int century = (input[i][2] - (input[i][2]%100))/100;
                                                                 int year;
                                                                 if(input[i][1] == 1)  year = input[i][2]%100 - 1;
                                                                 else year = input[i][2]%100;
                                                                 for(j=1; j<=31; ++j) days[j] = j+mcount-(2*century) + year + (year/4) + (century/4);  
                                                                  for(j=1; j<=31; ++j){
                                                           if(days[j]%7 == 0){
                                                                        printf("%d ", j);
                                                                        }
                                                                        }
                                                           }
                                                 else{
                                                      int days[30], j, febdays[28];
                                                                 int month;
                                                                 if(input[i][1] == 2) month = 12;
                                                                 else month = input[i][1] - 2;
                                                                 int mcount = 2.6*month - 0.2;
                                                                 int century = (input[i][2] - (input[i][2]%100))/100;
                                                                 int year;
                                                                 if(input[i][1] == 2)  year = input[i][2]%100 - 1;
                                                                 else year = input[i][2]%100;
                                                                 for(j=1; j<=30; ++j) days[j] = j+mcount-(2*century) + year + (year/4) + (century/4);  
                                                                 for(j=1; j<=28; ++j) febdays[j] = j+mcount-(2*century) + year + (year/4) + (century/4);
                                                                  for(j=1; j<=30; ++j){
                                                           if(days[j]%7 == 0 && input[i][1]!=2){
                                                                        printf("%d ", j);
                                                                        }
                                                           
                                                                        }
                                                           for(j=1; j<=28; ++j){
                                                                        if(febdays[j]%7 == 0 && input[i][1] == 2){
                                                                                printf("%d ", j);
                                                                                }
                                                                                }
                                                           }
                                                       
                                                }
                                                }
                                      
                                      
                      else{
                           if(input[i][1] <= 7){
                                                if(input[i][1]%2 != 0){
                                                                 int days[31], j;
                                                                 int month;
                                                                 if(input[i][1] == 1) month = 11;
                                                                 else month = input[i][1] - 2;
                                                                 int mcount = 2.6*month - 0.2;
                                                                 int century = (input[i][2] - (input[i][2]%100))/100;
                                                                 int year;
                                                                 if(input[i][1] == 1)  year = input[i][2]%100 - 1;
                                                                 else year = input[i][2]%100;
                                                                 for(j=1; j<=31; ++j) days[j] = j+mcount-(2*century) + year + (year/4) + (century/4);  
                                                                  for(j=1; j<=31; ++j){
                                                           if(days[j]%7 == 0){
                                                                        printf("%d ", j);
                                                                        }
                                                                        }
                                                           }
                                                 else{
                                                      int days[30], j, febdays[29];
                                                                 int month;
                                                                 if(input[i][1] == 2) month = 12;
                                                                 else month = input[i][1] - 2;
                                                                 int mcount = 2.6*month - 0.2;
                                                                 int century = (input[i][2] - (input[i][2]%100))/100;
                                                                 int year;
                                                                 if(input[i][1] == 2)  year = input[i][2]%100 - 1;
                                                                 else year = input[i][2]%100;
                                                                 for(j=1; j<=30; ++j) days[j] = j+mcount-(2*century) + year + (year/4) + (century/4);  
                                                                 for(j=1; j<=29; ++j) febdays[j] = j+mcount-(2*century) + year + (year/4) + (century/4);
                                                                  for(j=1; j<=30; ++j){
                                                           if(days[j]%7 == 0 && input[i][1]!=2){
                                                                        printf("%d ", j);
                                                                        }
                                                           else if(febdays[j]%7 == 0 && input[i][1] == 2){
                                                                                printf("%d ", j);
                                                                                }
                                                                        }
                                                           }
                                                       
                                                }
                                 else{
                                      int k;
                                      k = input[i][1] - 1;
                                      
                                      
                                      
                                      
                                      
                                      if(k%2 != 0){
                                                                 int days[31], j;
                                                                 int month;
                                                                 if(input[i][1] == 1) month = 11;
                                                                 else month = input[i][1] - 2;
                                                                 int mcount = 2.6*month - 0.2;
                                                                 int century = (input[i][2] - (input[i][2]%100))/100;
                                                                 int year;
                                                                 if(input[i][1] == 1)  year = input[i][2]%100 - 1;
                                                                 else year = input[i][2]%100;
                                                                 for(j=1; j<=31; ++j) days[j] = j+mcount-(2*century) + year + (year/4) + (century/4);  
                                                                  for(j=1; j<=31; ++j){
                                                           if(days[j]%7 == 0){
                                                                        printf("%d ", j);
                                                                        }
                                                                        }
                                                           }
                                                 else{
                                                      int days[30], j, febdays[29];
                                                                 int month;
                                                                 if(input[i][1] == 2) month = 12;
                                                                 else month = input[i][1] - 2;
                                                                 int mcount = 2.6*month - 0.2;
                                                                 int century = (input[i][2] - (input[i][2]%100))/100;
                                                                 int year;
                                                                 if(input[i][1] == 2)  year = input[i][2]%100 - 1;
                                                                 else year = input[i][2]%100;
                                                                 for(j=1; j<=30; ++j) days[j] = j+mcount-(2*century) + year + (year/4) + (century/4);  
                                                                 for(j=1; j<=28; ++j) febdays[j] = j+mcount-(2*century) + year + (year/4) + (century/4);
                                                                  for(j=1; j<=30; ++j){
                                                           if(days[j]%7 == 0 && input[i][1]!=2){
                                                                        printf("%d ", j);
                                                                        }
                                                           //else if(febdays[j]%7 == 0 && input[i][1] == 2){
                                                             //                   printf("%d ", j);
                                                               //                 }
                                                                        }
                                                               for(j=1; j<=29; ++j){
                                                                        if(febdays[j]%7 == 0 && input[i][1] == 2){
                                                                                printf("%d ", j);
                                                                                }
                                                                                }
                                                           }
                                                       
                                                }                
                                                
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                   
                                 } 
                                                                        
                                                                         
       printf("\n");                                                      
       }
       getch();
       
}

                                 
