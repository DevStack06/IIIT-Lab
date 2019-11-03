import java.io.*;
import java.util.Scanner;

class A
{
	int a;
	int b;
	int c;
	A(int i,int j,int k)
	{
		a=i;
		b=j;
		c=k;
	}
}

class B extends A()
{
	int d; 
	int f;

	void display(int o,int l)
	{
		d=l;
		f=o;
	}
}
public class In
{
	public static void main(String args[])
	{
		B m=new B();
	}

}