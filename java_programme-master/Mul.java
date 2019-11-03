import java.io.*;
import java.util.Scanner;
public class Mul
{
	public static void main(String argus[])
	{
		int a[][]=new int[100][100];
		int b[][]=new int[100][100];
		int c[][]=new int[100][100];
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the order of first matrix");
		int m,n;
		m=sc.nextInt();
		n=sc.nextInt();
		System.out.println("Enter the order of second matrix");
		int p,q,t=0;
		p=sc.nextInt();
		q=sc.nextInt();
		if(p==n)
		{
			System.out.println("eNTER THE  first MATRIX ELEMENT");
		    for(int i=0;i<m;i++)
		       {
			      for(int j=0;j<n;j++)
			      a[i][j]=sc.nextInt();
		        }

		    System.out.println("eNTER THE  second MATRIX ELEMENT");
		    for(int i=0;i<p;i++)
		       {
			      for(int j=0;j<q;j++)
			      b[i][j]=sc.nextInt();
		        }
		    for(int i=0;i<m;i++)
		    {
		    	for(int j=0;j<q;j++)
		    	{
		    		for(int k=0;k<n;k++)
		    		{
		    			t=t+a[i][k]*b[k][j];

		    		}
		    		c[i][j]=t;
		    		t=0;
		    	}
		    }    



           System.out.println("Afteer multiplication matrix element is");
           for(int i=0;i<m;i++)
		       {
			     for(int j=0;j<q;j++)
			         System.out.print(+c[i][j]+" ");
			     System.out.println();
			   } 
		}
		else
			System.out.println("You can't do matrix multiplication");
		

	}
}