#include <stdio.h>
void shellsort(int a[], int n)
{
    int gap, j, k, tmp;
    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (j = gap; j < n; j++)
        {
            for(k = j - gap; k >= 0; k = k - gap)
            {
                if (a[k+gap] >= a[k])
                {
				
                    break;
                }
                    
                    
               else
                {
                    tmp = a[k];
                    a[k] = a[k+gap];
                    a[k+gap] = tmp;
                }
            }
        }
    }
}
int main()
{
    int a[30];
    int i,  n;
    printf("Enter total no. of elements : ");
    scanf("%d", &n);
    printf("\nEnter %d numbers: ", n);
 
    for (i =  0 ; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    shellsort(a, n);
    printf("\n Sorted array is: ");
    for (i=0;i<n;i++)
        printf("%d ", a[i]);
    return 0;
}
