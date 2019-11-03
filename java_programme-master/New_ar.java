import java.util.Scanner;
import java.io.*;

class New1
{
	New1(double i)
	
	{
		System.out.println("circle area is "+3.14*3.14*i);
		System.out.println("Your permeter of circle is "+2*3.14*i);

	}

	New1(double a,double b)
	{
		System.out.println("the area of rectangular is "+a*b);
		System.out.println("the permiter iof rectangular is "+2*(a+b));

	}

	New1(double i,String l)
	{
		System.out.println("the area of square is "+i*i);
		System.out.println("the permeter of square is "+4*i);

	}
}



public class New_ar
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		double i,j,k,r;
		System.out.println("Enter the Circle radius");
		r=sc.nextDouble();
		System.out.println("Enter the lenght and width of rectangular");
		i =sc.nextDouble();
		j= sc.nextDouble();
		System.out.println("Enter the side of square");
		k=sc.nextDouble();
        New1 a=new New1(r);
        New1  b=new New1(i,j);
        New1 c=new New1(k,"hello");

	}
}