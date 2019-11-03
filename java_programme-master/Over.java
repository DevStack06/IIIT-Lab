import java.util.Scanner;
import java.io.*;
class New1
{
	New1(int i,int j)
	{
		System.out.println("sum of two integer is "+i+j);
		

	}

	New1(double a,double b)
	{
		System.out.println("some of two double is "+a+b);
		

	}

	New1(float i,float l)
	{
		System.out.println("sum of two float is "+i+l);
		

	}
	New1(String i,String l)
	{
		System.out.println("after concanate new string is\n "+i+l);
		

	}
}



public class Over
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int i,j;
		float k,r;
		double n,s;
		String m,g;
		System.out.println("Enter the two integer value");
		i=sc.nextInt();
		j=sc.nextInt();
		System.out.println("Enter the two float");
		k =sc.nextFloat();
		r= sc.nextFloat();
		System.out.println("Enter the two double ");
		n=sc.nextDouble();
		s=sc.nextDouble();

		System.out.println("Enter the two String for concanate ");
		m=sc.next();
		g=sc.next();
        New1 a=new New1(i,j);
        New1  b=new New1(k,r);
        New1 c=new New1(n,s);
        New1 d=new New1(m,g);

	}
}