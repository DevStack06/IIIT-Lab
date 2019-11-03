#include<stdio.h>
int main()
{
	int a[20], n, temp, i, j, loc, min;
	printf(" Enter the size of array\n: ");
	scanf("%d", &n);
	printf(" Enter the Element of array\n:");
	for(i=0; i<n; i++)
	{
		scanf("\n%d", &a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min = a[i];
		loc = i;
		for(j=i+1;j<n;j++)
		{
			if(min>a[j])
			{	
		    	min = a[j];
			    loc =j;
		    }
	    }
	  temp = a[i];
	  a[i] = a[loc];
      a[loc] = temp;
      }
      printf("after sorting\n");
	for(i=0; i<n; i++)
	
	printf("%d\n", a[i]);
	
}
