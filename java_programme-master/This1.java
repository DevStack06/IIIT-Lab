import java.util.Scanner;
import java.io.*;
class This2
{
	int i,j;
	This2(int i,int j)
	{
		
		this.i=i;
		this.j=j;
		i=i+j;
		j=j+8;
		This2 o=new This2();
		System.out.println("instance varieble is "+o.i+" "+o.j);
		System.out.println("local varieble is "+i+" "+j);
		//return 0;
	}
}

public class This1
{
	public static void main(String args[])
	{
	
		This2 a=new This2(10,12);
		//a.Ex();
		
	}

}