#include <stdio.h>
#define MAX 1000
main(){
	double ser[MAX];
	int i;
	for(i=0; i<MAX; ++i){
		ser[i] = 0;
		}
	scanf("%lf", &ser[1]);
	for(i=1; i<MAX-1; ++i){
		ser[i+1] = (ser[i]/(1-(ser[i] - (int)ser[i])));
		}
	
	for(i=1; i<=MAX-1; ++i){
		printf("%lf ", ser[i]);
		}
}
