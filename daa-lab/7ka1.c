#include<stdio.h>
void combine(int *a,int f,int k,int d);
//divide part
void merge_sort(int *a, int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
combine(a,low,mid,high);
}
}
// combine and conquer part
void combine(int *a,int low,int mid, int high)
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
int main()
{
int a[20],n,i,j,temp,key,low,high;
printf("Enter the size of array\n");
scanf("%d",&n);
printf("Enter the Element  of array\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Eterr the key value\n");
scanf("%d",&key);
merge_sort(a,0,n-1);
printf("arry element after sorted\n");
for(i=0;i<n;i++)
{
printf("%d\n ",a[i]);
}
printf("those values are whose adds to get a key\t");
for(i=0;i<n;i++)
{
	low = i;
	high = n-1;
	while(low<high)
	{
		if(a[low]+a[high]==key)
		{
			printf("%d  %d",a[low],a[high]);
			return 0;
		}
		else if(a[low]+a[high]<key)
		{
			low++;
		}
		else
		{
			high--;
		}
	}
	
}
if(a[low]+a[high]!=key)
{
	printf("There is  no any two Element which sum equal to key\n");
}
return 0;
}

