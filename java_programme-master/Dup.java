import java.io.*;
import java.util.Scanner;
public class Dup
{
	public static void  main(String argus[])
	{
		int a[]=new int[10];
		int n,p,j;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the array size");
		n=sc.nextInt();
		System.out.println("Enter the array elemnent");
		for(int i=0;i<n;i++)
		{
			a[i]=sc.nextInt();
		}
		for(int i=0;i<n;i++)
		{
			for( j=0;j<n;j++)
			{
				if(a[i]==a[j]&&i!=j)
				{
                      a[j]=9999999;
				}
			}
		}
		for(int i=0;i<n;i++)
		{   if(a[i]!=9999999)
			System.out.print(+a[i]+" ");
		}
		//System.out.print(+a[p-1]+" ");
	}
}