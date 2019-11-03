#include<stdio.h>
int main()
{
int a[20],i,j,n,flag=0;
printf("enter the array size\n");
scanf("%d",&n);
printf("enter the number in array\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
   for(j=i+1;j<n;j++)
      if(a[i]==a[j])
        {
        printf("number will be repeated: %d",a[i]);
           flag=1;
           break;
         }
       if(flag==1)
         break;
}
        if(flag==0)
          printf("not found");
        
         
}
