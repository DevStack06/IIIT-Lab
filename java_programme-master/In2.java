import  java.io.*;
import java.util.Scanner;

interface software
{
	void type(String s);
}

interface hardware
{
	void componant(String s,String w);
}

class computer implements software,hardware
{
  
   public  void type(String s)
  {
  	System.out.println("type of software is "+s);
  }
  public void componant(String s,String w)
  {
  	System.out.println("componant are   "+s+"  and   "+w);

  }
}

class In2
{
	public static void main(String args[])
	{
		computer a=new computer();
		a.type("web appplication");
		a.componant("cpu","ammulater");
	}
}