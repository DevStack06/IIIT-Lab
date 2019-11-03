#include<stdio.h>
int mergesort(int *a,int low,int mid,int high)
{
int i=low,j=mid+1,k=low,c[20];
    while(i<=mid&&j<=high)
     {
      if(a[i]<=a[j])
     {
        c[k]=a[i],k=k+1,i=i+1;
      }
     else
      {
       c[k]=a[j],k=k+1,j=j+1;
     }
   }
    while(i<=mid)
     {
           c[k]=a[i],k=k+1,i=i+1;
       } 
           while(j<=high)
         {
             c[k]=a[j],k=k+1,j=j+1;
           } 
      for(i=low;i<k;i++)
    {
    a[i]=c[i];
   }
}

int merge(int *a,int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
merge(a,low,mid);
merge(a,mid+1,high);
mergesort(a,low,mid,high);
}
}


int main()
{
int i,n,a[100];
printf("Enter the array size\n");
scanf("%d",&n);
printf("Enter the array elemnt\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
merge(a,0,n);
printf("After sort array elemnt\n");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
return 0;
}
