#include<stdio.h>
void knapsek(int n,float capcity,float p[],float w[])
{
float tp=0;
int i,j,u;
float x[20];
u=capcity;
for(i=0;i<n;i++)
   {
   x[i]=0.0;
   }
   for(i=0;i<n;i++)
      {
      if(w[i]>u)
        break;
      else
         {
          x[i]=1.0;
          tp = tp + p[i];
          u = u - w[i];
          }
       }

          if(i<n)
            x[i] = u/w[i];
            tp = tp + x[i]*p[i];
printf("the vectors is");
      for(i=0;i<n;i++)
         {
         printf("%f\t",x[i]);
         }
printf("the optimal solution is:%f",tp);   
}

int main()
{
float p[10],w[10],capcity;
int i,j,num;
float r[10],temp;
printf("enter the object");
scanf("%d",&num);
printf("choose capcity");
scanf("%f",&capcity);
printf("enter the profits and weights");
for(i=0;i<num;i++)
   {
    scanf("%f%f",&p[i],&w[i]);
    }
    for(i=0;i<num;i++)
       {
       r[i]=p[i]/w[i];
       }
       for(i=0;i<num;i++)
          {
          for(j=i+1;j<num;j++)
             {
             if(r[i]<r[j]) 
               {
               temp=r[j];
               r[j]=r[i];
               r[i]=temp;
  
               temp=p[j];
               p[j]=p[i];
               p[i]=temp;

               temp=w[j];
               w[j]=w[i];
               w[i]=temp;
               }
            }
       }
knapsek(num,capcity,p,w);
}
