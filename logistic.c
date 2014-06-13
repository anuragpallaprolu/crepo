#include <stdio.h>
#define NUM 1000
main(){
	double new[NUM];
	int i;
	for(i=0; i<NUM; ++i){
		new[i]=0;
}
	double r;
	scanf("%lf", &new[0]);
	scanf("%lf", &r);
	
	for(i=0; i<NUM-1; ++i)
		{
			new[i+1] = r*new[i]*(1-new[i]);
		}
//		fflush(stdin);
	
	for(i=0;i<NUM-1; ++i)
		{
			printf("%lf ", new[i]);
		}

}	
