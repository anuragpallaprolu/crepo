#include <stdio.h>
#include <stdlib.h>
/*
int gen(int n){
	int r;
	r = random(n);
	return r;
	}
*/
main(){
	//randomize();
	int i,j,k, fy[10];
	for(i=0; i<=9; ++i) fy[i] = i + 1;
	for(i=9; i>=0; --i){
			int q1, q2;
			q1 = fy[i];
			q2 = fy[i+1];
			fy[i+1] = q1;
			fy[i] = q2;
			for(k=0; k<=9; ++i) printf("%d ", fy[k]);
			printf("\n");
			
	}
}


