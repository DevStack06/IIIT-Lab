import java.io.*;
import java.util.Scanner;
public class Sum
{
	int range(int a[])
	{
		int t=0;
		for(int i=0;i<a.length;i++)
		{
           t=t+a[i];
		}
		//System.out.println(b);
		return t;
	}
	public static void main(String argus[])
	{
		int t;
		int k[]=new int[100];
		Sum a=new Sum();
		System.out.println("Enter the arary size");
		Scanner sc= new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println("Enter the arary element");
        for(int i=0;i<n;i++)
        	k[i]=sc.nextInt();

		t=a.range(k);
		System.out.println("Sum of array elemnt is");
		System.out.println(t);
	}
}