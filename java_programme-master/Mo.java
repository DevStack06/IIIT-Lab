import java.io.*;
import java.util.Scanner;
abstract class  shape
{
	int a,b;
	void moveto(int a,int b)
	{
		this.a=a;
		this.b=b;
		//return 0;
	}
}

class circle extends shape
{
	circle(String s)
	{
		System.out.println("shape of this object is "+s);
	}
	void moveto(int a,int b)
	{
		this.a=a;
		this.b=b;
		System.out.println(+a  + "    "+b);
		//return 0;
	}
	void area()
	 {
		System.out.println(3*super.a*super.a+" is a area");
	 	

	 }
}



class rectangular extends shape
{
	rectangular(String s)
	{
		System.out.println("shape of this object is "+s);
	}
	void moveto(int a,int b)
	{
		System.out.println(+a  + "    "+b);
		this.a=a;
		this.b=b;
		//System.out.println(a*b+" is a area");

		//return 0;
	}
	 void area()
	 {
		System.out.println(super.a*super.b+" is a area");


	 }
}

class Mo
{
	public static void main(String args[])
	{
		circle a=new circle("circle");
		a.moveto(10,12);
		a.area();
		rectangular b =new rectangular("rectangular");
		
		b.moveto(11,10);
		
		b.area();

	}
}