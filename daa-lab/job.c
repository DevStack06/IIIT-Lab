#include<stdio.h>
int max(int *a,int n)
{
	int max=0,pos=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			pos=i;
		}
	}
	return max;
}

int min(int a,int b)
{
	if(a>b)
		return b;
	else return a;
}
int main()
{
int p[20],d[20],i,j,n,temp,d_max=-1,total=0,k=0,pos=0,slot[20];
printf("enter the number of jobs\n");
scanf("%d",&n);
printf("enter the profits for each jobs\n");
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("enter the deadlines for each jobs\n");
for(i=0;i<n;i++)
scanf("%d",&d[i]);
for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
      {
        if(p[i]<p[j])
         {
          temp = p[j];
          p[j] = p[i];
          p[i] = temp;
       
          temp = d[j];
          d[j] = d[i];
          d[i] = temp;
         }
      }
    }
for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
      {
        if(p[i]==p[j])
         {
        if(d[i]<d[j])
          {
         temp = d[j];
          d[j] = d[i];
          d[i] = temp;
         }
        }
      }
   }
printf("after sorting the sequence is as follows\n");
for(i=0;i<n;i++)
   {
   printf("%d %d \n",p[i] , d[i]);
   }
	d_max=max(d,n);
	/*printf("dmax is %d \n",d_max);
	for(i=0;i<n;i++)
		printf("pro=%d and dead=%d",pro[i],dead[i]);
	printf("\n");*/
	for(i=0;i<d_max;i++)
		slot[i]=0;
	for(i=0;i<n;i++)
	{
		k=min(d_max,d[i]);
      //  printf("min=%d ",k);
        pos=i;
		while(k>=1)
		{
			if(slot[k-1]==0)
			{
				slot[k-1]=p[pos];
				total=total+p[pos];
				break;
			}
			else
				k=k-1;
		}
	}
	printf("\n");
	printf("toal profit is %d\n",total);
	printf("job sequence is   ");
	for(i=0;i<d_max;i++)
             {
               if(slot[i]!=0)
		   printf("%d ",slot[i]);
             }

      printf("\n");

	
}


