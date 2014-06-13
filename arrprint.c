#include <stdio.h>

void aprint(int N, int arr[N][N]){
	int i,j;
	for(i=0; i<=N; ++i){
		printf("\n");
		for(j=0; j<=N; ++j){
			printf("%d", arr[i][j]);
			}
		}
}

main(){
	int i,j,inp[5][5];
	for(i=0; i<=5; ++i){
		for(j=0; j<=5; ++j){
			inp[i][j] = 0;
			}
		}
	aprint(5, inp);
	}

	
