import  java.io.*;
import java.util.Scanner;

interface shape
{
	void area(double a,double b);
}

class circle implements shape
{
	public void area(double a,double b)
	{
      System.out.println("Area of circle is  "+3.14*a*b);
	}
}
class rectangular implements shape
{
	public void area(double a,double b)
	{
      System.out.println("Area of circle is  "+3.14*a*b);
	}
}

class In
{
	public static void main(String args[])
	{
		circle a=new circle();
		
		a.area(15,15);
		rectangular b =new rectangular();
		
		b.area(11,897);
	}
}
