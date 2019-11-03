#include<stdio.h>
void combine(int *s,int f,int d,int k);
void merge_sort(int *a, int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		combine(a,low,high,mid);
	}
}
void combine(int *a,int low, int high, int mid)
{
	int i=low,j=mid+1,k=low,c[100];
	while(i<=mid&&j<=high)
	{
		if(a[i]>a[j])
		{
			c[k]=a[j];
			j++;
			k++;
		}
		else
		{
			c[k]=a[i];
			i++;
			k++;
		}
	}
	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		c[k]=a[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++)
		a[i]=c[i];
}
int binary(int *a,int low,int high,int key)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			return 1;
		}
		else if(a[mid]>key)
		{
			binary(a,low,mid-1,key);
		}
		else 
			binary(a,mid+1,high,key);

	}
	

}
int main()
{
int a[100],b[100],k,i,f=0,key=0,n;
printf("enter the size of both arry\n");
scanf("%d",&n);
printf("enter the array element for A\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter the array elemnet for b\n");
for(i=0;i<n;i++)
scanf("%d",&b[i]);

printf("enter the k element\n");
scanf("%d",&k);

merge_sort(a,0,n-1);

for(i=0;i<n;i++)
{
key=k-b[i];
f=binary(a,0,n-1,key);
if(f==1)
{
printf("Found\n");
break;
}
}

if(f!=1)
printf("not found\n");

return 0;
}

