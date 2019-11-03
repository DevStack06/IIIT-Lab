#include<stdio.h>
int min(int a, int b)
{
	if(a>b)
		return b;
	else return a;
}
int main()
{
	int d[100],I[100][100],v,e,m,n,i,j,S[100],ns[100],s,pos=-1,k=0;
	printf("Enter the number of edge in given graph\n");
	scanf("%d",&e);
	printf("Enter the number of vertex in given graph\n");
	scanf("%d",&v);
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			{
				I[i][j]=99999999;
			}
    printf("Enter the pair of vertex who are connected then it cost\n");
    for(i=0;i<e;i++)
    {
    	scanf("%d%d",&m,&n);
    	
    	//printf("Enter the cost or distance b/w this vertex\n");
    	scanf("%d",&j);
    	I[m-1][n-1]=j;
    	I[n-1][m-1]=j;
    }
    printf("Enter the source vertex\n");
    scanf("%d",&s);
    j=0;
    d[s-1]=0;
    for(i=0;i<v;i++)
    {
    	if(i!=s-1)
    	{
    		ns[j]=i;
    		d[i]=9999999;
    		j++;
    	}

    }

    i=0;
    m=9999999;
    while(i<v)
    {

    	while(k<j)
    	{
    		d[ns[k]]=min(d[ns[k]],d[s-1]+I[s-1][ns[k]]);
    		if(m>d[ns[k]])
    		{
    			m=d[ns[k]];
    			n=ns[k];
    			 pos=k;
    			 //printf("\n\n %d ,%d ,%d\n\n",m,n,pos);
    		}
    		k++;
    	}
    	i++;
    	s=n+1;
    	int t=ns[pos];
    	ns[pos]=ns[j-1];
    	ns[k]=t;
    	j--;
    	k=0;
    	m=999999;

    }
    for(i=0;i<v;i++)
    {
    	printf("min(%d)=%d \n",i+1,d[i]);
    }

}