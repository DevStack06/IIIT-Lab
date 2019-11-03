#include<stdio.h>
#define f(x) (x*x*x* - x + 1)
int main()
{
float x0,x1,x2;
int k=0;
float e=0.0001;
do
 {
  printf("enter the value x0,x1...\n");
  scanf("%f%f",&x0,&x1);
 }while(f(x0)*f(x1)>0)
 do
  {
   k++;
   x2=(x0+x1)/2;
    if(f(x2)>0)
      x1=x2;
    else 
     x0=x2;
  }while(fabs(f(x2))>e)
 printf("root = %f itr = %d" ,x2,k);
}
