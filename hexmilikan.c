#include <stdio.h>
#define HEX 16
#include <string.h>

main(){
	long int inp;
	scanf("%ld", &inp);
	int q, hst[100], i,c=0;
	q = ((inp - (inp%HEX))/HEX);
	for(i=1; i<=100 && q > 0 ; ++i ){
	
		
	hst[i] = inp % HEX;
	q = ((inp - (inp%HEX))/HEX);
	inp = q;
	
	c = c+1;
	}
	for(i=1; i<=c; ++i) printf("%d\n", hst[i]);
	getch();
}
