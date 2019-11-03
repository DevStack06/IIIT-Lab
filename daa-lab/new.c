#include<stdio.h>
int main()
{



int a[20], n, temp=0, i, j, loc, min;
	printf(" Enter the size of array\n: ");
	scanf("%d", &n);
	printf(" Enter the Element of array\n:");
	for(i=0; i<n; i++)
	{
		scanf("\n%d", &a[i]);
	}



for(i=0;i<n;i++)
{
if(a[i]==a[i+1])
{
printf("found %d",a[i]);
temp= 1;
break;
}
}

if(temp!=1)
printf("not found");


}

