#include <stdio.h>
#define in 1
#define out 0
//matrix printer with unary array//
//v2
//MATCALC V1.001
//lynch_build_condo
void interchange(int init, int order_c, int term, int matrix[]);
void mult_row(int r_num, int f, int order_c, int matrix[]);
void copymatrix(int initial[], int final[], int count);
void cofactor(int matrix[], int elem, int order_c, int rownum);
main()
{
      int order_r, order_c ,p; // *r=3 *c=4
      
      printf("Please enter number of rows:");
      scanf("%d", &order_r);
      printf("Please enter number of columns:");
      scanf("%d", &order_c);
      p = (order_r*order_c)-1;
      int matrix[p];
      int i;
      int j;
      for(i=0; i<=p; ++i){
               scanf("%d\n", &matrix[i]);
               }
      for(i=0; i<=order_r-1; ++i){
               printf("\n");
               for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
                                printf("%d\t", matrix[j]);
                                }
               }
      getch();
      //INSERT MATRIX OPERATIONS HERE ---------------//
      int k;
	  int l;
	  printf("Which element to be searched for?");
	  scanf("%d", &l);
      printf("Please enter row number:");
	  scanf("%d", &k);
      	
      cofactor(matrix, l, order_c, k);
      	    
      //END MATRIX OPERATIONS------------------------//
      //OUTPUT-----//
      printf("\n-------------------------------------------------\n");
      
	  
	 
	  
      for(i=0; i<=order_r-1; ++i){
               printf("\n");
               for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
                                printf("%d\t", matrix[j]);
                                }
               }
      getch();

	   printf("\n-------------------------------------------------\n");
		int new_order;
		new_order = order_c - 1;
		int m;
		m = (new_order * new_order)-1;
		int newmatrix[m];
	    for(i=0; i<=order_r-1; ++i){
               printf("\n");
               for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
								if(matrix[j] != 0){
								printf("%d\t", matrix[j]);
								int k;
								for(k=0; k<=m; ++k){
                                         newmatrix[k] = matrix[j];
                                         }
									}
                                }
               }
		
	//int state;
	//state = out;
	//for(i=0; i<=p ; ++i){
	//	while(matrix[i]!=0 && j<=m){
	//		j=0;
	//		newmatrix[j] = matrix[i];
	//		++j;
	//		}
	//	}


		for(i=0; i<=new_order-1; ++i){
					   printf("\n");
					   for(j=(i*new_order); j<=((new_order)*(i+1))-1; ++j){
										printf("%d\t", newmatrix[j]);
										}
					   }
			  getch();
			

	  getch();
}

void interchange(int init, int order_c, int term, int matrix[])
{
     int i, j;
     for(i=(init*order_c), j =(term*order_c); i<=((order_c)*(init+1))-1, j<=((order_c)*(term+1))-1; ++i, ++j)
     {
                           int t,t1;
                           t=matrix[i];
                           t1=matrix[j];
                           matrix[i] = t;
                           matrix[j] = t1; //    INTERCHANGER
                           matrix[i] = t1; //    V2
                           matrix[j] = t;  //    
     }
}

void mult_row(int r_num, int f, int order_c, int matrix[])
{
     int i;
     for(i=(r_num*order_c); i<=((order_c)*(r_num+1))-1; ++i){
                            int t, t1; // ROW MULTIPLIER
                            t = matrix[i];
                            t1 = f*matrix[i];
                            matrix[i] = t1;
                            }
}

void copymatrix(int initial[], int final[], int count)
{
     int i;
     for(i=0; i<=count; ++i){
              final[i]=0;
              }
     
     for(i=0; i<=count; ++i){                   //MATRIX COPYEDIT
              initial[i] = final[i];
              }
     
}

void cofactor(int matrix[], int elem, int order_c, int rownum)
{
     int i, colnum;
     for(i=(rownum-1)*order_c; i<=rownum*(order_c)-1; ++i){
                               if(elem == matrix[i]){
							   		   colnum = i+1 - order_c*(rownum-1);
                                       printf("Found the req element at row no. %d\n", rownum);
									   printf("Found the req element at colum no. %d\n", colnum);
                                       break;
                                       }
                               }
	int ac_row, ac_col;
	ac_row = rownum -1;
	ac_col = colnum -1;
	int j;
	for(j=(ac_row)*order_c; j<=(order_c*(ac_row+1))-1; ++j){
		matrix[j] = 0;
		}
	for(j=ac_col; j<=ac_col+order_c*(order_c-1); j = j + order_c){
		matrix[j] = 0;
		}
	
}


	 

	 
	 



