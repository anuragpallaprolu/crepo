#include <stdlib.h>
#include <stdio.h>


/*
	LYNCH LABYRINTH EMULATOR
	Lynch-eNVY 2013
	Under The Monty Hall Simulator Architecure
	MoHaSA 2013
*/

/*
Emulating the labyrinth program under the MoHaSim Engine, it features the point sense AI, the world's
most sophisticated AI created.
*/


struct node{
	char val;
	struct node *next;
	int len;
	};
static int final[25];
typedef struct node *npt;

int ispoint(npt N){
	return N->next != NULL;
	}

/*
		**********************
		POINT SENSE SUBROUTINE

        Lynch-eNVY Computer Corporation
		   NAAG(Numerical Analysis Agency)
		**********************
*/

int point_sense(int i, npt N[], int mp[], int h){
	int j;
	if(i==0){
		if(N[i+1]->val == '*' || N[i+h]->val == '*'){
			//mp[i] = 1;
			if(N[i+1]->val == '*') mp[i+1] = 1 + mp[i+1];
			if(N[i+h]->val == '*')  mp[i+h] = 1+ mp[i+h];
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
			if(N[i-1]->val == '*') mp[i-1] = 1 + mp[i-1];
			if(N[i+1]->val == '*') mp[i+1] = 1 + mp[i+1];
			if(N[i+h]->val == '*') mp[i+h] = 1 + mp[i+h];
			if(N[i-1]->val == '*' && N[i+1]->val == '*' && N[i+h]->val == '*') final[i] = final[i] + 3;
			else if((N[i-1]->val =='*' && N[i+1]->val == '*')||(N[i+1]->val == '*' && N[i+h]->val == '*')||(N[i-1]->val == '*' && N[i+h]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	else if(i%h == 0 && i!=0 && i!= h*(h-1)){
		if(N[i-h]->val == '*' || N[i+h]->val=='*' || N[i+1]->val=='*'){
			if(N[i-h]->val == '*') mp[i-h] = mp[i-h] + 1;
			if(N[i+h]->val == '*') mp[i+h] = mp[i+h] + 1;
			if(N[i+1]->val == '*') mp[i+1] = mp[i+1] + 1;
			if(N[i-h]->val == '*' && N[i+h]->val == '*' && N[i+1]->val == '*') final[i] = final[i] + 3;
			else if((N[i-h]->val =='*' && N[i+h]->val == '*')||(N[i+h]->val == '*' && N[i+1]->val == '*')||(N[i-h]->val == '*' && N[i+1]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];			
			return 1;
			}
		else return 0;
		}
	else if(i==h*(h-1)){
		if(N[i-h]->val == '*' || N[i+1]->val == '*'){
			if(N[i-h]->val == '*') mp[i-h] = mp[i-h] + 1;
			if(N[i+1]->val == '*') mp[i+1] = mp[i+1] + 1;
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
			if(N[i-1]->val == '*') mp[i-1] = mp[i-1] + 1;
			if(N[i+1]->val == '*') mp[i+1] = mp[i+1] + 1;
			if(N[i-h]->val == '*') mp[i-h] = mp[i-h] + 1;
			if(N[i-1]->val == '*' && N[i+1]->val == '*' && N[i-h]->val == '*') final[i] = final[i] + 3;
			else if((N[i-1]->val =='*' && N[i+1]->val == '*')||(N[i+1]->val == '*' && N[i-h]->val == '*')||(N[i-1]->val == '*' && N[i-h]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	else if(i==(h*h)-1){
		if(N[i-1]->val == '*' || N[i-h]->val == '*'){
			if(N[i-1]->val == '*') ++mp[i-1];
			if(N[i-h]->val == '*') ++mp[i-h];
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
			if(N[i-1]->val == '*') ++mp[i-1];
			if(N[i-h]->val == '*') ++mp[i-h];
			if(N[i+h]->val == '*') ++mp[i+h];
			if(N[i-1]->val == '*' && N[i-h]->val == '*' && N[i+h]->val == '*') final[i] = final[i] + 3;
			else if((N[i-1]->val =='*' && N[i-h]->val == '*')||(N[i-h]->val == '*' && N[i+h]->val == '*')||(N[i-1]->val == '*' && N[i+h]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];

			return 1;
			}
		else return 0;
		}
	else if(i == h-1){
		if(N[i+h]->val == '*' || N[i-1]->val == '*'){
			if(N[i+h]->val == '*') ++mp[i+h];
			if(N[i-1]->val == '*') ++mp[i-1];
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
			if(N[i-1]->val == '*') ++mp[i-1];
			if(N[i+1]->val == '*') ++mp[i+1];
			if(N[i-h]->val == '*') ++mp[i-h];
			if(N[i+h]->val == '*') ++mp[i+h];
			if(N[i-1]->val == '*' && N[i+1]->val == '*' && N[i-h]->val == '*' && N[i+h]->val == '*') final[i] = final[i] + 4;
			else if((N[i-1]->val=='*' && N[i+1]->val == '*'&&  N[i-h]->val == '*')||( N[i+1]->val == '*' &&  N[i-h]->val == '*' &&  N[i+h]->val == '*')||(N[i-1]->val == '*' &&  N[i-h]->val == '*' && N[i+h]->val == '*')||(N[i-1]->val == '*'&& N[i+1]->val == '*' &&  N[i+h]->val == '*')) final[i] = final[i] + 3;
			else if((N[i-1]->val == '*' &&  N[i+1]->val == '*')||(N[i-1]->val == '*' &&  N[i-h]->val == '*' )||(N[i-1]->val == '*' &&  N[i+h]->val == '*') || (  N[i+1]->val == '*' && N[i-h]->val == '*') || ( N[i+1]->val == '*' &&  N[i+h]->val == '*') || (N[i-h]->val == '*' && N[i+h]->val == '*')) final[i] = final[i] + 2;
			else ++final[i];
			return 1;
			}
		else return 0;
		}
	

}

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





/*
LENGTH FIND
*/
int len(int mp[], npt N[], int h){
    int c=0,i,l=0;
	for(i=0; i<=24; ++i){
	if(N[i]->val == '*') 
    {
          if(mp[i]==3) ++c; //NON BRANCH
          if(mp[i]==4) ++l  //TWO BRANCHES

                 }
    }
	return c+1;
}
main(){
    start:;
    npt map[25];
	int mp[25];
	int ach[25];
	int i,j;
	for(i=0; i<=24; ++i){
		mp[i] = 1;
		ach[i]=0;
		map[i] = malloc(sizeof(struct node));
		map[i]->val = '#';
		map[i]->len = 0;
		map[i]->next = map[i+1];
		}
	//map[20]->next = NULL;  ----------ERROR :: TOGGLE BREAKPOINT HERE <- <- <- --------------------
	
	
	map_print(5, map);
	int c,d = 0;
	while(d!=99){
		scanf("%d", &c);
		if(c==99) d = 99;
		else{
		map[c]->val = '*';
		map_print(5, map);
		}
		}
	//map[4]->val = '*';
	map_print(5, map);
	int num_sense;
	printf("Please enter the sense vertex:");
	//scanf("%d", &num_sense);
	int a; 
	for(i=0; i<=24; ++i){
	if(map[i]->val == '*'){
	a = point_sense(i, map,mp,5);
	}
	printf("The number of blocks near node %d are %d", i, final[i]);
	printf("\n%d\n" ,a);}
	int q = len(mp, map, 5);
	printf("\n\n%d\n\n", q);
	tabprint(mp, 5);
    getch();
    goto start;
}

		
