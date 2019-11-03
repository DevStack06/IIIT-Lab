
//parent node means visited node and visited node means parent node
/*this programme only traverse the path  but if you give me a goal node then i will break the traverse
made by balram rathore
*/
import java.io.*;
import java.util.Scanner;
public class Idfs
{
	public static void main(String args[])
	{
		int g[][]=new int[100][100];
		int i,j,m,n,top=0;
		int visited[] =new int[100];
		int level[]=new int[100];
		int parent[]=new int[100];
		int stack[]=new int[100];
		int flag=1;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the total number vertex graph have");
		m=sc.nextInt();
		System.out.println("Enter the total nuber of edge");
		n=sc.nextInt();
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				g[i][j]=0;

			}
			parent[i]=0;
			visited[i]=-1;
			level[i]=-1;
		}

		for(i=0;i<n;i++)
		{
			int x,y;
			System.out.println("Enter the node who are connected");
			x=sc.nextInt();
			y=sc.nextInt();
			g[x-1][y-1]=1;
			g[y-1][x-1]=1;
		}
		System.out.println("matrix created graph is below-----");
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				System.out.print(+g[i][j]+" ");

			}
			System.out.println();
		}
		System.out.println("Enter the parent node ");
		int p=sc.nextInt();
		p--;
		parent[p]=1;
		level[p]=1;
		stack[top]=p;
		int x=p;
		System.out.println("Enter the require depth ");
		int f=sc.nextInt();
		

		
      //  System.out.println("the Idfs path of given graph");
        while(flag>0)
        {
		while(top>-1)
		{
			System.out.println("the Idfs path of given graph");
			p=stack[top];
			top--;
			
			System.out.print(p+1+" ->");
			if(level[stack[top+1]]>f)
			{
				continue;
			}
			for(j=m-1;j>=0;j--)
			{
				if(parent[j]==0 && g[p][j]==1)
				{
					top++;
					parent[j]=1;
					stack[top]=j;
					visited[j]=p;
					level[j]=level[visited[j]]+1;
				   
				}
				
			}
			flag=0;


			
		}
		for(i=0;i<m;i++)
	    {
	    	if(parent[i]==0)
	    		flag=1;
	    	parent[i]=0;
	    }
		f++;
		p=x;
		parent[p]=1;
		level[p]=1;
		top=0;
		stack[top]=p;
		
		System.out.println();
		

	    
	}
	System.out.println();

	}
}