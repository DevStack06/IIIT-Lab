#include<stdio.h>
//int partiation(int *a,int low,int high);
int partiation(int  *a,int low,int high)
{
int pivot=low,temp,i=low,j=high+1;
while(i<=j)
{
  do
  {
   i=i+1;
   }   while(a[pivot]>=a[i]);
      do
       {
         j=j-1;
        }   while(a[pivot]<a[j]);

      if(i<j)
  {
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
}
   temp=a[j];
    a[j]=a[pivot];
    a[pivot]=temp;
     
return j;
}

// divide part
void quick(int *a,int low,int high)
{
int k;
if(low<=high)
{
k=partiation(a,low,high);
quick(a,low,k-1);
quick(a,k+1,high);
}
}



// main part
int main()
{
int i,n,a[100];
printf("Enter the array size\n");
scanf("%d",&n);
printf("Enter the array elemnt\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
a[n]=999999;
quick(a,0,n-1);
printf("After sort array elemnt\n");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
return 0;
}
