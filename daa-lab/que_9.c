#include<stdio.h>

int main(){

             

              int w[10][10];

              int c[10][10];

              int r[10][10];

              int p[10];

              int q[10];

              int i,n,j,k,t;

             

              printf("enetr how many p value  you want to enter");

              scanf("%d",&n);

             

              for(i=0;i<n;i++){

                           printf("enetr Q element ");

              scanf("%d",&q[i]);

             

              }

             

              for(i=1;i<n;i++){

                           printf("enetr P element ");

              scanf("%d",&p[i]);

             

              }

             



              for(i=0;i<n;i++){

                  w[i][i]=0;

                           c[i][i]=0;

                                         r[i][i]=0;

             

             

}

              for(i=0;i<n;i++){

             

                           w[i][i]=q[i];

             

             

}   

 

 

              for(i=0;i<n;i++){

             

                           printf("\n%d\n",w[i][i]);

             

             

} 

 

 

 

 

printf("\n w values\n");        

int d;

d=1;

for(t=0;t<n;t++){

 

i=0;

for(j=d;j<n;j++){

w[i][j]=p[j]+q[j]+w[i][j-1];

printf("%d\n",w[i][j]);

                i++; 

}

 

d++;

}

 

int min,min1;

 

d=1;

for(t=0;t<n;t++){

             

i=0;

for(j=d;j<n;j++){

             

              min=999999;

              min1=999999;

             

              for(k=i+1;k<=j;k++){     

                                                    
c[i][j]=c[i][k-1]+c[k][j]+w[i][j];

 

            if(c[i][j]<=min){               

                                                       min=c[i][j];

                                                       min1=k;

                                         }

                                                      

                                                        

                           c[i][j]=min;

                           r[i][j]=min1;

 

 

}

 

printf("%d---%d\n",c[i][j],r[i][j]);



                i++; 

}

 

d++;

}

 

 

 

 

 

 

 

 

 

 

 

}


