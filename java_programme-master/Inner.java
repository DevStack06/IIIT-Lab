import java.io.*;
import java.util.Scanner;

class outer
{
	private int value=187;

  class  Inner1
    {
    	public int get()
    	{
    		return value;

    	}

		
	}
}


public class Inner
{
	public static void main(String args[])
	{
	outer a=new outer();
	outer.Inner1 b=a.new Inner1();
	System.out.println(b.get());


	}
}