#include <stdio.h>
#include <stdlib.h>
//prorgram to test the pragmatic for recursion

void frep(int n, int param[]){
	while(n>1){
	for(param[n]=1; param[n]<=4; ++param[n]){
	//	while(n>1){
			frep(n-1, param);
			//printf("%d %d\n%d %d\n\n", param[n], param[n-1], param[n-2], param[n-3]);
			//frep(n-1, param);
			//printf("%d %d\n%d %d\n\n", param[4], param[3], param[2], param[1]);
	//		}
	}
	}
}

main(){
	int param[1000];
	frep(4, param);
}



/*

	THIS PROJECT HAS BEEN ABANDONED AS NOT-PRODUCTIVE AND OBSOLETE.
	LyncheNVY 

*/

