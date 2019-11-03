import java.io.*;
import java.util.Scanner;
  class india
 {
 	final String country = "india";
 	String capital="Delhi";
 	void capital()
 	{
 		System.out.println("the country  is "+country);
 		System.out.println("the capital is "+capital);

 	}
 }

 class central_india extends india
 {
 	void capital()
 	{
 		String capital="Nagpur";
 		System.out.println("the country  is "+country);
 		System.out.println("the capital is "+capital);
 		System.out.println("the capital of india is "+super.capital);
        System.out.println("the capital of india is "+this.capital);
 	}

 }
 class chattisgarh extends india
 {
 	void capital()
 	{
 		String capital="raipur";
 		System.out.println("the country  is "+country);
 		System.out.println("the capital is "+capital);
 		System.out.println("the capital of india is "+super.capital);
 		System.out.println("the capital of india is "+this.capital);

 	}

 }

 class New_inherit
 {
 	public static void main(String args[])
 	{
 		chattisgarh a= new chattisgarh();
 		central_india b=new central_india();
 		india c=new india();
 		a.capital();
 		b.capital();
 		c.capital();

 	}
 }