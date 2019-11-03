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
int a[20],n,i,j,temp,key,low,high,flag=0;
printf("Enter the size of array\n");
scanf("%d",&n);
printf("Enter the Element  of array\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
merge_sort(a,0,n-1);
printf("arry element after sorted\n");
for(i=0;i<n;i++)
{
printf("%d\n ",a[i]);
}
for(i=0;i<n-1;i++)
{
	if(a[i]==a[i+1])
	{
		flag=1;
                break;
	}
}

        if(flag==1)
        {
        printf("yes there is having a dublicate number in this array\n");
		printf("%d\t",a[i]);
        }
        else
 	printf("no there is not  having a dublicate number in this array\n");
	 return 0;
}
