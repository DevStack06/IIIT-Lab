import java.io.*;
import java.util.Scanner;
public class Sec
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
				if(a[i]<a[j])
				{
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		 
		System.out.print("Second largest element is "+a[n-2]);
	
		//System.out.print(+a[p-1]+" ");
	}
}