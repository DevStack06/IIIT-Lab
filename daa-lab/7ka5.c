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
int a[20],n,i,pos=-1,max=0,c=0;
printf("Enter the array size\n");
scanf("%d",&n);
printf("Enter the array elemnt\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
a[n]=99999;
merge(a,0,n);
for(i=0;i<n;i++)
{
	if(a[i]==a[i+1])
	{
		c=c+1;
	}
	else
	{
		if(max<(c+1))
		{
			max=c+1;
			c=0;
			pos=i-1;
		}
		else
			c=0;
	}
}
printf("maximum occurence is %d of element of %d \n",max,a[pos]);
}
