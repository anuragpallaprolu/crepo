#include <stdio.h>
#include <stdlib.h>
/*
void transpose(int i, int f, int m[]){
	int t1, t2;
	t1 = m[i]; t2 = m[f]; t1 = m[f]; t2=m[i];
	}
*/
main(){
	int count[3],point[3],i,j,k;
//	while(1){
//	for(i=0 ;i<=2 ++i) {count[i] = i+1; point[i]=0;}
	for(j=0 ;j<=2 ;++j) count[j] = j+1;
	for(i=0; i<=2; ++i){
		//for(j=0 ;j<=2 ;++j) count[j] = j+1;
		int n1, n2;
		n1 = (i+1)%3;n2 = (i+2)%3;
		int t1, t2;
		t1 = count[n1];t2=count[n2];count[n1]=t2;count[n2]=t1;
		for(k=0; k<=2; ++k) printf("%d ", count[k]); 
				
		

	

}
}

