#include<stdio.h>

int main()
{
	int c[100][100],i,j,total=0,k,cost,v,e,b[100][100];
	printf("enter the number of vertex\n");
	scanf("%d",&v);
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			 {
			 	c[i][j]=0;
			 	b[i][j]=0;
			 }
	printf("Enter the connected vertex and corresponding cost\n");
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&j,&k,&cost);
		c[k-1][j-1]=cost;
		c[j-1][k-1]=cost;

	}

	int s[v],m=999999999,x,y; 
     for(i=0;i<v;i++)
         {
         	s[i]=0;
         }
     for(i=0;i<v-1;i++)
     {
       
        
        for(int u=0;u<v;u++)
        {
        	for (j=0;j<v;j++)
        	{
        	 if (c[u][j]>0&&s[j]==0&&c[u][j]<m)
              {

                 m=c[u][j];

                x=u;
                y=j;
             }
            }
        }
        b[x][y]=m;
        c[x][y]=0;
        c[y][x]=0;
        m=9999999;
        s[y]=1;
     }
     printf("in minimum cost spanning tree these edges are connected and corresponding cost is\n");
     for(i=0;i<v;i++)
     	for(j=0;j<v;j++)
        {
     	   if(b[i][j]!=0 )
     	  {
     		printf("%d - %d -%d \n",i+1,j+1,b[i][j]);
     		total=total+b[i][j];
     	  }
        }
     printf("minimum cost required is %d\n",total);
     return 0;
 }
