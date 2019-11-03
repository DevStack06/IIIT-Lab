#include<stdio.h>
void sort(int *a,int n)
{
	int i,j,temp=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i]>=a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	int a[100],i,n,key,low,high,mid;
	printf("enter the arry size \n");
	scanf("%d",&n);
	printf("enter the arry element\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    printf("enter the key \n");
    scanf("%d",&key);
    low=0;
    high=n-1;
    sort(a,n);
    printf("sorted element \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    while(low<=high)
    {
    	mid=(low+high)/2;
    	if(a[mid]==key)
    	{
    		printf("%d found on %d place\n",key,mid+1);
    		break;
    	}
    	else if(a[mid]>key)
    		high=mid-1;
    	else
    		low=mid+1;
    }
    if(a[mid]!=key)
    	printf("%d is not found on that array \n",key);
}
