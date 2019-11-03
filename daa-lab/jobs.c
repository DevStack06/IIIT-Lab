#include<stdio.h>
void sort(int *pro,int*dead,int *job,int n)
{
	int pos,value,value2,value3,i;
	for(i=0;i<n;i++)
	{
		value=pro[i];
		value2=dead[i];
                value3=job[i];
		pos=i;
		while(pos>0&&pro[pos-1]<value)
		{
			pro[pos]=pro[pos-1];
			dead[pos]=dead[pos-1];
                        job[pos]=job[pos-1];
			pos--;
		}
		pro[pos]=value;
	        dead[pos]=value2;
                job[pos]=value3;
	}
}

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
	int pro[100],dead[100],total=0,n,i,d_max=-1,k=0,pos=0,job[100];
	int slot[100];
	printf("enter the number job\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the %d profit\n",i+1 );
		scanf("%d",&pro[i]);
                job[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("enter the deadlines coresponding to %d profit\n",i+1 );
		scanf("%d",&dead[i]);
	}

	sort(pro,dead,job,n);
	d_max=max(dead,n);
	/*printf("dmax is %d \n",d_max);
	for(i=0;i<n;i++)
		printf("pro=%d and dead=%d",pro[i],dead[i]);
	printf("\n");*/
	for(i=0;i<d_max;i++)
		slot[i]=0;
	for(i=0;i<n;i++)
	{
		k=min(d_max,dead[i]);
      //  printf("min=%d ",k);
        pos=i;
		while(k>=1)
		{
			if(slot[k-1]==0)
			{
				slot[k-1]=job[pos];
				total=total+pro[pos];
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
