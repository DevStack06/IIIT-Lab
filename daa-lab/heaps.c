#include <stdio.h>
#define left (2*(i+1)-1)
#define right (2*(i+1))
//heap  sort


void maxHeapify(int *a,int i,int n)
{
    int largest=i;
    if(left<n)
    largest=a[largest]>=a[left]?largest:left;
    if(right<n)
    largest=a[largest]>=a[right]?largest:right;
    if(largest==i)
        return;
    //printf("%d",largest);
    int tmp=a[largest];
    a[largest]=a[i];
    a[i]=tmp;
    maxHeapify(a,largest,n);
       
}

void buildheap(int *a,int n)
{   int i;
    for(i=n/2-1;i>=0;i--)
        maxHeapify(a,i,n);       
}

void heap_sort(int *a, int n)
{
    int i,tmp;
    for(i=n-1;i>=1;i--)
    {
        tmp=a[i];
        a[i]=a[0];
        a[0]=tmp;
        maxHeapify(a,0,i);
    }        
}


int main() {
    int n,i,j,min_i,tmp, a[100];
    printf("enter number of elemments\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
    {
	
        scanf("%d",&a[i]);
    }
    buildheap(a,n);
    heap_sort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

