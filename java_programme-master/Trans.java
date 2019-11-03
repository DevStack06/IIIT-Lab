import java.io.*;
import java.util.Scanner;
public class Trans
{
	public static void main(String argus[])
	{
		int a[][]=new int[100][100];
		int b[][]=new int[100][100];
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the order of matrix");
		int m,n;
		m=sc.nextInt();
		n=sc.nextInt();
		System.out.println("eNTER THE MATRIX ELEMENT");
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			a[i][j]=sc.nextInt();
		}


      System.out.println("Afteer transpose matrix element is");
      for(int i=0;i<n;i++)
		    {
			   for(int j=0;j<m;j++)
			     System.out.print(+a[j][i]+" ");
			 System.out.println();


		    } 

	}
}