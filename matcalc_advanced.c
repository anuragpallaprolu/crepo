#include <stdio.h>
#define in 1
#define out 0
//matrix printer with unary array//
//v2
//MATCALC V1.001
//lynch_build_condo
//lynch_v3_test
//lynch_MATCALC_final.build.stable v4
void interchange(int init, int order_c, int term, double matrix[]);
void mult_row(int r_num, double f, int order_c, double matrix[]);
void subt_row(int init, int term, int order_c, double matrix[]);
//void copymatrix(int initial[], int final[], int count);
//void cofactor(int matrix[], int elem, int order_c, int rownum);
main()
{
      int order_r, order_c ,p; // *r=3 *c=4
      
      printf("Please enter number of rows:");
      scanf("%d", &order_r);
      printf("Please enter number of columns:");
      scanf("%d", &order_c);
      p = (order_r*order_c)-1;
      double matrix[p];
      int i;
      int j;
      for(i=0; i<=p; ++i){
               scanf("%lf\n", &matrix[i]);
               }
      for(i=0; i<=order_r-1; ++i){
               printf("\n");
               for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
                                printf("%lf\t", matrix[j]);
                                }
               }
      getch();
      //INSERT MATRIX OPERATIONS HERE ---------------//
      //subt_row(2,3,order_c,matrix);
      int k;
      for(i=0; i<=p; ++i)
      {
               if(matrix[i]!=0)
               {
                               printf("\nThe possible pivot entry is %lf\n", matrix[i]);
                               k=i;
                               break;
                               }
                               }
      double l;
      //l = matrix[k+order_c]/matrix[k];
      int rownum;
      int m;
      m = k / order_c;
      rownum = m +1;
      printf("The pivot entry is in row %d\n", rownum);
      for(i=1; i<=order_c-1; ++i){
               l = matrix[k + i*order_c]/matrix[k];
               mult_row(rownum-1, l, order_c, matrix);
               subt_row(rownum+i, rownum, order_c, matrix);
               }
      //END MATRIX OPERATIONS------------------------//
      //OUTPUT-----//
      printf("\n-------------------------------------------------\n");
      
	   for(i=0; i<=order_r-1; ++i){
               printf("\n");
               for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
                                printf("%lf\t", matrix[j]);
                                }
               }
      getch();
	 for(i=0; i<=p; ++i)
      {
               if(matrix[i]!=0 && i!=k)
               {
                               printf("The possible pivot entry is %lf\n", matrix[i]);
                               i=k;
                               break;
                               }
                               }
                               
	   printf("\n-------------------------------------------------\n");
		//int new_order;
		//new_order = order_c - 1;
		//int m;
		//m = (new_order * new_order)-1;
		//int newmatrix[m];
	    //for(i=0; i<=order_r-1; ++i){
         //      printf("\n");
         //      for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
		//						if(matrix[j] != 0){
			//					printf("%d\t", matrix[j]);
				//					}
                    //            }
              // }
		//int state;
		//state = out;
		//for(i=0,j=0; i<=p,j<=m; ++i,++j){
			//if(matrix[i]!=0){
				//	newmatrix[j] = matrix[i];
					
		//	}
			//}
		//j=0;
		//int u;
		//u=0;
		//while(j>=0 && j<=8){
                   
          //         while(matrix[j]!=0 && u>=0 && u<=m){
                   
            //                          newmatrix[u] = matrix[j];
                //                      ++u;
              //                        break;
                  //                    }
                   //++j;
                   //}
                              
		
	//int state;
	//state = out;
	
      
	     
	  getch();
}

void interchange(int init, int order_c, int term, double matrix[])
{
     int i, j;
     for(i=((init-1)*order_c), j =((term-1)*order_c); i<=((order_c)*(init))-1, j<=((order_c)*(term))-1; ++i, ++j)
     {
                           double t,t1;
                           t=matrix[i];
                           t1=matrix[j];
                           matrix[i] = t;
                           matrix[j] = t1; //    INTERCHANGER
                           matrix[i] = t1; //    V2
                           matrix[j] = t;  //    
     }
}

void mult_row(int r_num, double f, int order_c, double matrix[])
{
     int i;
     for(i=((r_num)*order_c); i<=((order_c)*(r_num+1))-1; ++i){
                            double t, t1; // ROW MULTIPLIER
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

void subt_row(int init, int term, int order_c, double matrix[])
{
     int i,j;
     for(i=((init-1)*order_c), j =((term-1)*order_c); i<=((order_c)*(init))-1, j<=((order_c)*(term))-1; ++i, ++j)
     {
                               double t1, t;
                               t = matrix[i];
                               t1 = matrix[i] - matrix[j];
                               matrix[i] = t1;
                               }
}
                             


	 

	 
	 




