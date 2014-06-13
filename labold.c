#include <stdlib.h>
#include <stdio.h>


/*
	LYNCH LABYRINTH EMULATOR
	Lynch-eNVY 2013
	Under The Monty Hall Simulator Architecure
	MoHaSA 2013
k*/



struct node{
	char val;
	struct node *next;
	};
static int final[25];
typedef struct node *npt;

int ispoint(npt N){
	return N->next != NULL;
	}

/*
		**********************
		POINT SENSE SUBROUTINE

			Lynch-eNVY
		Numerical Analysis Agency
		**********************
*/

int point_sense(int i, npt N[], int mp[] int h){
	int j;
	if(i==0){
		if(N[i+1]->val == '*' || N[i+h]->val == '*'){
			//mp[i] = 1;
			if(N[i+1]->val=='*) mp[i+1] = mp[i] + mp[i+1];
			else mp[i+h] = mp[i]+ mp[i+h];
				
			if(N[i+1]->val == '*' && N[i+h]->val == '*'){
				final[i] = final[i] + 2;
				}
			else ++final[i];
			return 1;
			}
			
		else return 0;
		//goto loop;
		}
	
	else if(i>0 && i<h-1){
		if(N[i-1]->val == '*' || N[i+1]->val == '*' || N[i+h]->val == '*'){
			if(N[i-1]->val == '*) mp[i-1] = mp[i] + mp[i-1];
			else if(N[i+1]->val == '*')mp[i+1] = mp[i] + mp[i+1];
			else mp[i+h] = mp[i] + mp[i+h];
			if(N[i-1]->val == '*' && N[i+1]->val == '*' && N[i+h]->val == '*') final[i] = final[i] + 3;
			else if((N[i-1]->val =='*' && N[i+1]->val == '*')||(N[i+1]->val == '*' && N[i+h]->val == '*')||(N[i-1]->val == '*' && N[i+h]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	else if(i%h == 0 && i!=0 && i!= h*(h-1)){
		if(N[i-h]->val == '*' || N[i+h]->val=='*' || N[i+1]->val=='*'){
			if(N[i-h]->val == '*') mp[i-h] = mp[i-h] + mp[i];
			else if(N[i+h]->val == '*') mp[i+h] = mp[i+h] + mp[i];
			else mp[i+1] = mp[i+1] + mp[i];
			if(N[i-h]->val == '*' && N[i+h]->val == '*' && N[i+1]->val == '*') final[i] = final[i] + 3;
			else if((N[i-h]->val =='*' && N[i+h]->val == '*')||(N[i+h]->val == '*' && N[i+1]->val == '*')||(N[i-h]->val == '*' && N[i+1]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];			
			return 1;
			}
		else return 0;
		}
	else if(i==h*(h-1)){
		if(N[i-h]->val == '*' || N[i+1]->val == '*'){
			if(N[i-h]->val == '*') mp[i-h] = mp[i-h] + mp[i];
			else mp[i+1] = mp[i+1] + mp[i];
			if(N[i-h]->val == '*' && N[i+1]->val == '*'){
				final[i] = final[i] + 2;
				}
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	else if(i>h*(h-1) && i<(h*h)-1){
		if(N[i-1]->val == '*' || N[i+1]->val == '*' || N[i-h]->val == '*'){
			if(N[i-1]->val == '*') mp[i-1] = mp[i-1] + mp[i];
			else if(N[i+1]->val == '*') mp[i+1] = mp[i+1] + mp[i];
			else mp[i-h] = mp[i-h] + mp[i];
			if(N[i-1]->val == '*' && N[i+1]->val == '*' && N[i-h]->val == '*') final[i] = final[i] + 3;
			else if((N[i-1]->val =='*' && N[i+1]->val == '*')||(N[i+1]->val == '*' && N[i-h]->val == '*')||(N[i-1]->val == '*' && N[i-h]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	else if(i==(h*h)-1){
		if(N[i-1]->val == '*' || N[i-h]->val == '*'){
			if(N[i-1]->val == '*') mp[i-1] = mp[i-1] + mp[i];
			else mp[i-h] = mp[i-h] + mp[i];
			if(N[i-1]->val == '*' && N[i-h]->val == '*'){
				final[i] = final[i] + 2;
				}
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	else if(i%h == h-1 && i!=h-1 && i!=(h*h)-1){
		if(N[i-1]->val == '*' || N[i-h]->val == '*'|| N[i+h]->val == '*'){
			if(N[i-1]->val == '*') mp[i-1] = mp[i-1] + mp[i];
			else if(N[i-h]->val == '*') mp[i-h] = mp[i-h] + mp[i];
			else mp[i+h] = mp[i+h] + mp[i];
			if(N[i-1]->val == '*' && N[i-h]->val == '*' && N[i+h]->val == '*') final[i] = final[i] + 3;
			else if((N[i-1]->val =='*' && N[i-h]->val == '*')||(N[i-h]->val == '*' && N[i+h]->val == '*')||(N[i-1]->val == '*' && N[i+h]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];

			return 1;
			}
		else return 0;
		}
	else if(i == h-1){
		if(N[i+h]->val == '*' || N[i-1]->val == '*'){
			if(N[i+h]->val == '*') mp[i+h] = mp[i+h] + mp[i];
			else mp[i-1] = mp[i-1] + mp[i];
			if(N[i+h]->val == '*' && N[i-1]->val == '*'){
				final[i] = final[i] + 2;
				}
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	else{
		if(N[i-1]->val == '*' || N[i+1]->val == '*' || N[i-h]->val == '*' || N[i+h]->val == '*'){
			if(N[i-1]->val == '*') mp[i-1] = mp[i-1] + mp[i];
			else if(N[i+1]->val == '*') mp[i+1] = mp[i+1] + mp[i];
			else if(N[i-h]->val == '*') mp[i-h] = mp[i-h] + mp[i];
			else mp[i+h] = mp[i+h] + mp[i];
			if(N[i-1]->val == '*' && N[i+1]->val == '*' && N[i-h]->val == '*' && N[i+h]->val == '*') final[i] = final[i] + 4;
			else if((N[i-1]->val=='*' && N[i+1]->val == '*'&&  N[i-h]->val == '*')||( N[i+1]->val == '*' &&  N[i-h]->val == '*' &&  N[i+h]->val == '*')||(N[i-1]->val == '*' &&  N[i-h]->val == '*' && N[i+h]->val == '*')||(N[i-1]->val == '*'&& N[i+1]->val == '*' &&  N[i+h]->val == '*')) final[i] = final[i] + 3;
			else if((N[i-1]->val == '*' &&  N[i+1]->val == '*')||(N[i-1]->val == '*' &&  N[i-h]->val == '*' )||(N[i-1]->val == '*' &&  N[i+h]->val == '*') || (  N[i+1]->val == '*' && N[i-h]->val == '*') || ( N[i+1]->val == '*' &&  N[i+h]->val == '*') || (N[i-h]->val == '*' && N[i+h]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	

}
/*
///////////////////////////////////////
///////////////////////////////////////
//TAB UPDATER//////////////////////////
///////////////////////////////////////
*/
void map_print(int h, npt map[]){
	int i;
	for(i=0; i<=(h*h)-1; ++i){
		if(i%h ==0){
			printf("\n");
			printf("%c ", map[i]->val);
			}
		else printf("%c ", map[i]->val);
		}
	}

void tabprint(int m[], int h){
	int i;
	for(i=0; i<=h*h-1; ++i){
		if(i%h == 0){
			printf("\n");
			printf("%d ", m[i]);
			}
		else printf("%d ",m[i]);
		}
	}


main(){
	npt map[25];
	int mp[25], ws[25];
	int i,a;
	a = 1;
	for(i=0; i<=24; ++i){
		mp[i] = 1;
		ws[i]=0;
		map[i] = malloc(sizeof(struct node));
		map[i]->val = '#';
		map[i]->next = map[i+1];
		}
	//map[20]->next = NULL;  ----------ERROR :: TOGGLE BREAKPOINT HERE <- <- <- --------------------
	
	//MAP INPUT
	map_print(5, map);
	int c,d = 0;
	while(d!=99){
		scanf("%d", &c);
		if(c==99) d = 99;
		else{
		map[c]->val = '*';
		//int a = point_sense(5, map,ws, 5);
		map_print(5, map);
		//if(a==1 && mp[c-1]==1) continue;
		//else a = 1;
		}
		}
	//END INPUT
	//PRINT
	map_print(5, map);
	/*int num_sense;
	printf("Please enter the sense vertex:");
*/	for(i=0; i<=24; ++i){
	if(map[i]->val == '*'){
	point_sense(i, map,mp,ws,5);}
	printf("The number of blocks near node %d are %d", i, final[i]);
	//printf("\n%d\n" ,a);}
	}
	tabprint(mp, 5);

}

		

