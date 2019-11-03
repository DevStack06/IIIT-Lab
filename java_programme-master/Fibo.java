import java.io.*;
import java.util.Scanner;
public class Fibo
{
	public static void  main(String argus[])
	{
		int n;
		System.out.println("Enter the range you want to print fibonaci");
		Scanner sc=new Scanner(System.in);
		n= sc.nextInt();
		int x,y,c=0;
		x=1;y=0;
		for(int i=0;i<n;i++)
		{
		
				if(i==0)
					System.out.print(+x+" ");
				else
				{
					c=x+y;
					y=x;
					x=c;
					System.out.print(+c+" ");

				}
				
	    }
	}


}