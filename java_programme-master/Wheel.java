import java.io.*;
import java.util.Scanner;
 abstract class Vehicle
 {
 	String name="hjghj" ;
 	String car_number="hjg";
 	abstract void wheel();
 	
 }

 class bus extends Vehicle
 {
 	
 	void wheel()
 	{
 		name="bus";
 	car_number="10101";
 		System.out.println("vehicle type   is "+name);
 		System.out.println("vehicle number "+car_number);
 		
 	}

 }
 class car extends Vehicle
 {
 	
 	void wheel()
 	{
 		name="car";
 	car_number="10105";

 		System.out.println("vehicle type   is "+name);
 		System.out.println("vehicle number "+car_number);
 		
 	}

 }
  class bike extends Vehicle
 {
 	
 	void wheel()
 	{
 		name="bike";
 	car_number="10";
 		System.out.println("vehicle type   is "+name);
 		System.out.println("vehicle number "+car_number);
 		
 	}

 }
 class Wheel
 {
 	public static void main(String args[])
 	{
 		//vehicle a= new vehicle();
 		bus b=new bus();
 		bike c=new bike();
 		car d =new car();
 	   // a.wheel();
 	    b.wheel();
 	    c.wheel();
 	    d.wheel();

 	}
 }