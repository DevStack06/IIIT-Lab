import java.io.*;
import java.util.Scanner;
 class Static1 
{
	int model;
	String car;
	static
	{
		System.out.println("welcome in static bloc");

	}
	static String brand_new="Ferari";

	  Static1(int m,String c)
	 {
	 	model=m;
	 	car=c;
	 }


	static void method1()
	{
		brand_new= "alphabate";
	}
	void display()
	{
		System.out.println(+model +" is a car model "+car +" is car owner name "+brand_new +" is a brand new name");
	}
}

public class Stat{
	public static void main(String args[])
	{
		Static1.method1();
		Static1 p=new Static1(10000,"balram");
		Static1 o=new Static1(10110,"bhupendra");
		p.display();
		o.display();
		



	}
}