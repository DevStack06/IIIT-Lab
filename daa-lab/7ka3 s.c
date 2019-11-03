#include <stdio.h>
#include <stdbool.h>

//7_3

#define mid (low+high)/2
int c[100005];
int n;
void conquer(int*,int,int);
void merge(int *a,int low,int high)
{
if(high-low>1)
{
merge(a,low,mid);
merge(a,mid,high);
conquer(a,low,high);
}
}

void conquer(int * a,int low,int high)
{
int ri=mid,li=low,i=low;

for(;i<=high;i++)
if(ri<=high && li<mid)
{
if(a[ri]<a[li])
c[i]=a[ri++];
else 
c[i]=a[li++];
}
else if(li<mid)
c[i]=a[li++];
else
c[i]=a[ri++];

for(i=low;i<high;i++)
a[i]=c[i];

}
bool bs(int a[],int low,int high,int key)
{
if(a[high]<key&&a[low]>key)
return false;
if(high-low<2)
return (a[low]==key||a[high]==key);

return a[mid]==key||(a[mid]<key&&bs(a,mid+1,high,key)||(a[mid]>key&&bs(a,low,mid-1,key)));

}






int main() {
    int n,i,j,min_i,tmp,k;
    printf("enter number of elemments and sum\n");
    scanf("%d%d",&n,&k);
    int a[n],b[n];
    printf("enter elements of a\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("ennter elements of b\n");
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    merge(a,0,n-1);
    for(i=0;i<n;i++)
        if(bs(a,0,n-1,k-b[i]))
        {
            printf("yes");
            return 0;
        }
    printf("no");
        
}

