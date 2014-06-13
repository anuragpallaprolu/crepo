#include <stdio.h>
#include <stdlib.h>

//NEWTON RAPHSON HAMMING ITERATIVE SOLUTION : BISECTOR ALGORITHM

main(){
	double a,b,c,d;
	double p1, p2, mid;
	double function[1000];
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	int i;
	for(i=0; i<=999; ++i){
		function[i]=(a*i*i*i)+(b*i*i)+(c*i)+(d);
		printf("Func: %lf for x = %d\n", function[i], i);
		}
	for(i=0; i<=999; ++i){
		if(function[i]<0){
			p1 = i;
			break;
			}
		}
	for(i=0; i<=999; ++i){
		if(function[i]>0){
			p2 = i;
			break;
			}
		}
	//mid = (p1+p2)/2;
	while(function[(int)p2]>0 && function[(int)p1]<0){
		mid = (p1+p2)/2.0;
		if(function[(int)mid]>0){
			p2 = mid;
			}
		else if(function[(int)mid]<0){
			p1 = mid;
			}
		else{
			printf("The root is at %lf", mid);
			}
		if(p1==p2 && p2 == mid) break;
		printf("%lf\t%lf\t%lf\n", p1, p2, mid);
		}
		
}
