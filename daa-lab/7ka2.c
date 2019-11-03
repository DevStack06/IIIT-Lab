#include<stdio.h>
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
for(i=0;i<n;i++)
{
for(j=i;j<n;j++)
{
if(a[i]>a[j])
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}

printf("After the sorted array is \n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
printf("those values are whose adds to get a key\t");
 for(i=0;i<n-2;i++)
{
	low = i+1;
	high = n-1;
	while(low<high)
	{
		if(a[i]+a[low]+a[high]==key)
		{
			printf("%d  %d  %d",a[i],a[low],a[high]);
			return 0;
		}
		else if(a[i]+a[low]+a[high]<key)
		{
			low++;
		}
		else
		{
			high--;
		}
	}
	
}
if(a[i]+a[low]+a[high]!=key)
{
	printf("There is  no any three Element which sum equal to key\n");
}
return 0;
}

