import java.io.*;
import java.util.Scanner;
public class Sym
{
	public static void main(String argus[])
	{
		int a[][]=new int[100][100];
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the order of matrix");
		int m,n,flag=0;
		m=sc.nextInt();
		n=sc.nextInt();
		if(m==n)
	 	{
	     	System.out.println("eNTER THE MATRIX ELEMENT");
		    for(int i=0;i<m;i++)
	       {
			    for(int j=0;j<n;j++)
		      	a[i][j]=sc.nextInt();
	    	}
	    	 for(int i=0;i<m;i++)
	       {
			    for(int j=0;j<n;j++)
			    {
	    	
	    	if(a[i][j]!=a[j][i])
	    	{
              flag=1;
	    	}
	    }
	}

           if(flag==0)
              System.out.println("this matrix is symetric");
          else
          	System.out.println("this matrix is not symetric");
      


	   } 

	}
}