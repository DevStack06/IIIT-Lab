#include<stdio.h>
//binary search part
int binary(int *a,int low,int high)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==mid)
        {
            return mid;
        }
        else if(a[mid]>mid)
        {
            binary(a,low,mid-1);
        }
        else 
            binary(a,mid+1,high);

    }
    

}

int main()
{
    int a[100],i,n,j=-1;
    printf("enter the arry size \n");
    scanf("%d",&n);
    printf("enter the arry element\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("print the given array\t");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    j=binary(a,0,n-1);
    if(j!=-1)
        printf("a[i]=%d and i=%d founded  \n",a[j],j);
    else
        printf("there is no any element where a[i]=i\n");
}
