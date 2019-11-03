import java.io.*;
import java.util.Scanner;
import java.lang.Math;
public class Comp
{
	Comp(double p,double r,double t)
	{
		double u=Math.pow((1+r/100),t);
		double i=p*u ;
		System.out.println(i);	
	}
	public static void main(String argus[])
	{
		double p,r, t;
		
	
		System.out.println("Enter the rate");
		Scanner sc= new Scanner(System.in);
		   r= sc.nextDouble();
		System.out.println("Enter the amount");
        	p=sc.nextDouble();
        //System.out.println("Enter the number of time compunded per year");
       // 	n=sc.nextDouble();
        System.out.println("Enter the time in year");
        	t=sc.nextDouble();
        Comp a=new Comp(p,r,t);
	
	}
}