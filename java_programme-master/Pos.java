import java.io.*;
import java.util.Scanner;
public class Pos
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
		System.out.println("Enter the array position you want to enter new number");
		p=sc.nextInt();
		System.out.println("Enter the nuber you want to enter");
		j=sc.nextInt();
		a[p-1]=j;
		System.out.println("After adding nuber new array is");
		for(int i=0;i<n;i++)
		{
			System.out.print(+a[i]+" ");
		}
		System.out.print(+a[p-1]+" ");
	}
}