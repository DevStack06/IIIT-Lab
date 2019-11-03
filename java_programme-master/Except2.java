
import java.io.*;
import java.util.Scanner;
public class Except2
{
	public static void main(String args[])
	{
		Scanner sc =new Scanner(System.in);
		try
		{
			int c=11/0;
		}
		catch(Exception e)
		{
			System.out.println(e);
		}

		try
		{
			String a=null;
			int l=a.length();
			System.out.println(l);

		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		try
		{
			int k[]= new int[2];
			int d[]=new int[2];
			System.out.println("Enter the total element in array");
			int x=sc.nextInt();
			System.out.println("Enter element");
			for(int i=0;i<x;i++)
				k[i]=sc.nextInt();
			for(int i=0;i<=x;i++)
			{
				d[i]=k[i]/k[i+1];

			}

		}
		catch(Exception e)
		{
			System.out.println(e);
		}

		System.out.println("he loo ");
	}
}