import java.io.*;
import java.util.Scanner;
public class Ar1
{
	public static void  main(String argus[])
	{
		int n;
		System.out.println("Enter the range you want to find prime number");
		Scanner sc=new Scanner(System.in);
		n= sc.nextInt();
		int flag=0;
		for(int i=2;i<n;i++)
		{
			for(int j=2;j<9;j++)
			{
				if(i%j==0 && j!=i)
				{
					flag=1;
				}
			}	
			if(flag!=1)
			 System.out.println("This is a prime number "+i);
			 else 
		    flag=0;	
	}
	}


}