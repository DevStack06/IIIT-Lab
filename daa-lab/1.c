#include<stdio.h>
int main()
{
	int a[100],n,i,j,k=0,pos=-1;
	printf("ENter the array size \n");
	scanf("%d",&n);
	printf("enter the array element\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	a[n]=999999999;
	for(i=0;i<n;i++)
	{
		k=(k+1+i);
		for(j=0;j<n;j++)
		{
			if(a[j]==a[k]&&j!=k)
			{
				pos=j;
				break;
			}
			k++;
			//printf("%d  ",k);
		}
		//printf("\n");
		k=0;
		if(pos!=-1)
			break;
	}
	if(pos==-1)
		printf("No reapeated element\n");
	else
		printf("First elemnt repeated is %d\n",a[pos]);
	return 0;
}