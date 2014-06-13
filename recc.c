#include <stdio.h>
#define MAX 1000
#include <math.h>
main(){
	double T[MAX];
	int i;
	T[0] = 5;
	for(i=1; i<MAX-1; ++i){
		T[i] = T[i-1] + T[(int)ceil(i/2)];
		}
	
	for(i=1; i<MAX-1; ++i){
		printf("%lf ", T[i]);
		}

}
