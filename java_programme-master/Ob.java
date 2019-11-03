import java.io.*;
import java.util.Scanner;
class Person
{
	int h,w;
	Person update(Person d)
	{
		d.h=2*d.h;
		d.w=2*d.w;

		return d;
	}
}
public class Ob
{

	public static void main(String argus[])
	{
      int r[]=new int[2];
      Person d=new Person();
      Scanner sc=new Scanner(System.in);
      System.out.println("Enter the height of person");
      d.h=sc.nextInt();
      System.out.println("Enter the width of person");
      d.w=sc.nextInt();
     d= d.update(d);
     r[0]=d.h;
     r[1]=d.w;
      System.out.println("the height of person"+r[0]);
      System.out.println("the width of person"+r[1]);
         
	}

}