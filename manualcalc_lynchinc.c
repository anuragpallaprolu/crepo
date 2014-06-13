

#include <stdio.h>

//Lynch Adder
int pow(int b, int e);
int adder(int inp1[], int inp2[], int result[], int max);
main(){
       int one,n,m,j,d,p;
       j=1;
       d=0;
       one=0;
	   printf("Please enter first number:");
       scanf("%d", &n);
	   printf("Please enter second number");
	   scanf("%d", &m);
       int place1[100];
       place1[0] = 0;
       for(j=1; j<=100; ++j){
                int q;
                q = pow(10, j);
                if(n<q){
                        printf("The Number of Digits is %d\n", j);
                        
                        break;
                        }
                        }
       
       for(d=1; d<=j; ++d){
                place1[d]=0;
                }
          
       for(d=1; d<=j; ++d){
                place1[d]=((n%pow(10, d))-place1[d-1])/pow(10, d-1);
                }
	   
       for(d=1; d<=100; ++d){
       if(d>j){
	   	place1[d] = 0;
       	}
	   
       }
	   
       getch();
       int place2[100];
       place2[0] = 0;
       for(j=1; j<=100; ++j){
                int q;
                q = pow(10, j);
                if(m<q){
                        printf("The Number of Digits is %d\n", j);
                        
                        break;
                        }
                        }
       
       for(d=1; d<=j; ++d){
                place2[d]=0;
                }
          
       for(d=1; d<=j; ++d){
                place2[d]=((m%pow(10, d))-place2[d-1])/pow(10, d-1);
                }
       for(d=1; d<=100; ++d){
       if(d>j){
	   	place2[d] = 0;
       	}
	   
       }
	   
	   //for(d=1; d<=100; ++d){
	   //	printf("%d\n", place2[d]);
	   	//}
	   	int result[1000];
	   for(d=0; d<=1000; ++d){
	   	result[d] = 0;
	   	}
	   adder(place1, place2, result, 100);

	   for(d=0; d<=100; ++d){
			if(place1[100-d]!=0){
				printf("%d\t", place1[100-d]);
				}
	   	}
	   printf("\n");
	   for(d=0; d<=100; ++d){
			if(place2[100-d]!=0){
				printf("%d\t", place2[100-d]);
				}
	   	}
	   
	   printf("\n--------------\n");
	   for(d=1; d<=1000; ++d){
	   	if(result[1000-d]!=0){
			printf("%d\t", result[1000-d]);
	   		}
	   	}
       getch();
       
 
       }
       
       
int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1));
             
} 

int adder(int inp1 [ ],int inp2 [ ], int result[], int max)
{
	int s[100], i;
	for(i=0; i<=max; ++i){
		s[max-i] = inp1[max-i]+inp2[max-i];
		if(s[i]>=10){
			result[max-i] = s[max-i]-10;
			result[max-(i+1)] = s[max-(i+1)] + 1;
			}
		else{
			result[max-i] = s[max-i];
		}
		}
}

