#include <stdio>
#include <stdlib>
#include<fstream>

int board[3][3];
int i,j,k,checkall,win1,turn,placed;   //turn 0=O 1=X
fstream f;
void play();
void check_repetition();
void clear();
void write();
void checkall();
int win();

void main()
{
		f.open("moves.txt",ios::out);
		checkall=0;
		clear();
		while(!checkall)
		{
			win=0;
			play();
			check_repetition();
			write();
			clear();
			checkall();
			
		}
}


void play()
{
		while(!win1)
		{
			if(turn)
				turn=0;
			else 
				turn=1;  //set turn
			
			placed=0;
			while(!placed)
			{
				i=rand()%9;
				if(i<=2)
				{
					if(board[0][i]==2)
					{
						board[0][i]=turn;
						placed=1;
					}
				}
				else if(i>=3 && i<=5)
				{
					if(board[1][i-3]==2)
					{
						board[1][i-3]=turn;
						placed=1;
					}
				}
				else
				{
					if (board[2][i-6]==2)
					{
						board[2][i-6]=turn;
						placed=1;
					}
				}
		    }
			
				
			
		}
}
