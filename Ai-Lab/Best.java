/*this programme only traverse the path  but if you give me a goal node then i will break the traverse
made by balram rathore
*/

import java.io.*;
import java.util.Scanner;
public class Best
{
	public static void main(String args[])
	{
		int g[][]=new int[100][100];
		int i,j,m,n,f=-1,r=0;
		int parent[]=new int[100];
		int visited[] =new int[100];
		int queue[]=new int[100];
		int cost1[]=new int[100];
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the total number vertex graph have");
		m=sc.nextInt();
		System.out.println("Enter the total nuber of edge");
		n=sc.nextInt();
		System.out.println("Enter the total nuber of edge");
		  int jk=sc.nextInt();
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				g[i][j]=-1;

			}
			parent[i]=0;
		}

		for(i=0;i<n;i++)
		{
			int x,y;
			System.out.println("Enter the node who are connected and corresponding cost");
			x=sc.nextInt();
			y=sc.nextInt();
			int cy=sc.nextInt();
			g[x-1][y-1]=cy;
			g[y-1][x-1]=cy;
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
		queue[r]=p;
		cost1[r]=99999999;
		
        System.out.println("the Greedy traversal of given graph");
		while(f!=r)
		{
			p=queue[f+1];
			f=f+1;
			System.out.print(p+1+" ->");
			if(p+1==jk)
				break;
			for(j=0;j<m;j++)
			
			{

				if(parent[j]==0 && g[p][j]>-1)
				{
					r++;
					parent[j]=1;
					queue[r]=j;
					cost1[r]=g[p][j];
					visited[j]=p;
				}
			}
					for(i=f+1;i<=r;i++)
			
					{
						for(int k=i+1;k<=r;k++)
						{
							if(g[visited[j]][i]>g[visited[j]][k])
							{
								int t=queue[i];
								queue[i]=queue[k];
								queue[k]=t;
							}
						}
						//System.out.println(+queue[i]);
					}


				
			
		}
		System.out.println();

	}
}