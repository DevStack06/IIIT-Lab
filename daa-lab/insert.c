#include<stdio.h>
int main()
{
	int a[20], n, temp, i, j;
	printf(" Enter the size of array\n: ");
	scanf("%d", &n);
	printf(" Enter the Element of array\n:");
	for(i=0; i<n; i++)
	{
		scanf("\n%d", &a[i]);
	}
	for(i=1; i<n; i++)
	{
		temp = a[i];
		j = i-1;
		while(temp<a[j] && j>=0)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = temp;
	}
        
        printf("after sorting\n");
	for(i=0; i<n; i++)
	
	printf("%d\n", a[i]);
	
}
