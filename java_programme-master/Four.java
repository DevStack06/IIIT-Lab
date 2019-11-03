import java.io.*;
import java.util.Scanner;
import java.lang.Math;
class Circle
{
	
	int display()
	{
		double r;
	Scanner sc= new Scanner(System.in);
	System.out.println("Enter the radius of circle");
	r=sc.nextDouble();
	double p=2*3.14*r;
	System.out.println("Parameter of circle is "+p);
	p=3.14*r*r;
	System.out.println("Area of circle is"+p)	;
	return 0;
}
}
class Tri
{
	
	int display()
	{
		
          Scanner scanner= new Scanner(System.in);
          System.out.println("Enter the value of side a,b,c");
          double a=scanner.nextDouble();
          double b=scanner.nextDouble();
          double c=scanner.nextDouble();
          double s=(a+b+c)/2;
          System.out.println("Parameter is"+(2*s));	
          double area= Math.sqrt(s*(s-a)*(s-b)*(s-c));
          System.out.println("total area  is "+area);

	return 0;
}
}
class Rect 
{
	
	int display()
	{
		double r,s;
	Scanner sc= new Scanner(System.in);
	System.out.println("Enter the sides of rectangular");
	r=sc.nextDouble();
	s=sc.nextDouble();

	double p=2*(s*r);
	System.out.println("Parameter of Rectangular is "+p);
	p=s*r;
	System.out.println("Area of Rectangular is"+p);	
	return 0;
}
}
class Square
{
	
	int display()
	{
		double r;
	Scanner sc= new Scanner(System.in);
	System.out.println("Enter the side of squre");
	r=sc.nextDouble();
	double p=4*r;
	System.out.println("Parameter of Square is "+p);
	p=r*r;
	System.out.println("Area of Square is"+p)	;
	return 0;
}
}

class Four
{
	public static void main(String ragus[])
	{
		Square a=new Square();
		Circle b=new Circle();
		Rect c=new Rect();
		Tri d=new Tri();
		a.display();
		b.display();
		c.display();
		d.display();
	}

}