#include <stdio.h>

//Conway Look And Say Sequence
int pow(int b, int e);
main(){
       int one,n,i,j,d,p;
       int n1;
       j=1;
       d=0;
       one=0;
       scanf("%d", &n);
       scanf("%d", &n1);
       //n = 45671;
       int place[10];
       place[0] = 0;
       for(i=1; i<=100; ++i){
                int q;
                q = pow(10, i);
                if(n<q){
                        //printf("The Number of Digits is %d\n", i);
                        
                        break;
                        }
                        }
       
       for(d=1; d<=i; ++d){
                place[d]=0;
                }
           
       for(d=1; d<=i; ++d){
                place[d]=((n%pow(10, d))-place[d-1])/pow(10, d-1);
                }
       
       //n1 = 4534671;
       int placed[10];
       placed[0] = 0;
       for(j=1; j<=100; ++j){
                int q;
                q = pow(10, j);
                if(n1<q){
                        //printf("The Number of Digits is %d\n", j);
                        
                        break;
                        }
                        }
       
           
       for(d=1; d<=j; ++d){
                placed[d]=((n1%pow(10, d))-placed[d-1])/pow(10, d-1);
                }
       
       int r;
       r = n + n1;
       int k;
       for(k=1; k<=100; ++k){
                int q;
                q = pow(10, k);
                if(r<q){
                        //printf("The Number of Digits is %d\n", k);
                        
                        break;
                        }
                        }
       
       int res[1000];
       for(d=1; d<=k; ++d){
                res[d]=((r%pow(10, d))-res[d-1])/pow(10, d-1);
                }
       for(d=i+1; d<=k; ++d){
                place[d] = 0;
                }
       for(d=j+1; d<=k; ++d){
                placed[d]=0;
                }
       int carry[k];
       int check[k];
       for(d=k; d>=1; d--){
                check[d] = place[d] + placed[d];
                if(check[d]>=10){
                                 carry[d] = 0;
                                 carry[d+1] = 1;
                                 }
                else
                {
                    carry[d] = 0;
                    }
                }
                
                
       printf("\n");
       for(d=k; d>=1; d--){
       printf("%d\t", carry[d]);
       }
       printf("\n");
       

       printf("------------------------------\n");
       
       for(d=k; d>=1; d--){
       printf("%d\t", place[d]);
       }
       printf("\n");
       for(d=k; d>=1; d--){
       printf("%d\t", placed[d]);
       }
       printf("\n");
       printf("-------------------\n");
       for(d=k; d>=1; d--){
       printf("%d\t", res[d]);
       }
       
       
       getch();
       /////////////////////////////////////////////
       //multiplication
       
       int a,b,w,u;
       scanf("%d", &a);
       scanf("%d", &b);
       
       int placel[10];
       placel[0] = 0;
       for(u=1; u<=100; ++u){
                int q;
                q = pow(10, u);
                if(a<q){
                        //printf("The Number of Digits is %d\n", i);
                        
                        break;
                        }
                        }
       
       for(d=1; d<=i; ++d){
                placel[d]=0;
                }
           
       for(d=1; d<=i; ++d){
                placel[d]=((a%pow(10, d))-placel[d-1])/pow(10, d-1);
                }
       
       
       
       int placem[10];
       placem[0] = 0;
       for(w=1; w<=100; ++w){
                int q;
                q = pow(10, w);
                if(a<q){
                        //printf("The Number of Digits is %d\n", i);
                        
                        break;
                        }
                        }
       
       for(d=1; d<=w; ++d){
                placem[d]=0;
                }
           
       for(d=1; d<=w; ++d){
                placem[d]=((b%pow(10, d))-placem[d-1])/pow(10, d-1);
                }
       
       int multsum[w];
       
       for(i=1; i<=w; ++i)
       {
                multsum[i] = placem[i] * pow(10, i-1);
                }
       
       for(i=1; i<=w; ++i)
       {
                printf("%d\n", placem[i]);
                }
       
       
       
       
       
       


                getch();
                }
       
int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1));
             
} 
