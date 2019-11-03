import java.util.Scanner;
import java.io.*;
class This2
{
	int i,j;
    This2(int l,int k)
	{
		i=l;
		j=k;

		System.out.println("the value of i and j"+i+j);
	   
	    
	}
	This2(This2 a)
	{
		i=a.i;
		j=a.j;

		System.out.println("the value of i and j"+i+j);
	   
	    
	}
}

public class Copy
{
	public static void main(String args[])
	{
		int i,j;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the two integer value");
		i=sc.nextInt();
		j=sc.nextInt();
	
		This2 a=new This2(i,j);
		This2 b=new This2(a);
		
		
	}

}