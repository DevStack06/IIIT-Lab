import java.io.*;
import java.util.Scanner;
import java.lang.Math;
public class Ar
{
   public static void main(String args[])
     {
         
          Scanner scanner= new Scanner(System.in);
          System.out.println("Enter the value of side a,b,c");
          double a=scanner.nextDouble();
          double b=scanner.nextDouble();
          double c=scanner.nextDouble();
          double s=(a+b+c)/2;
          double area= Math.sqrt(s*(s-a)*(s-b)*(s-c));
          System.out.println("total area  is "+area);
      }
} 