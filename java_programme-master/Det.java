import java.io.*;
import java.util.Scanner;
public class Det
{
	public static void main(String argus[])
	{
		int a[][]=new int[100][100];
		int t=0;
		Scanner sc=new Scanner(System.in);
		System.out.println("eNTER THE MATRIX ELEMENT");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			a[i][j]=sc.nextInt();
		}

      t=(a[0][0]*(a[1][1]*a[2][2]-a[2][1]*a[1][2])+a[0][1]*(a[2][0]*a[1][2]-a[2][2]*a[1][0])+a[0][2]*(a[1][0]*a[2][1]-a[2][0]*a[1][1]));
      System.out.println("Afteer determinant value  is"+t);
     
	}
}