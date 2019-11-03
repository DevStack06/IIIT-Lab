import java.io.*;
import java.util.Scanner;
public class Lar
{
   public static void main(String args[])
     {
          double t=0;
          Scanner scanner= new Scanner(System.in);
          System.out.println("Enter the value of a,b,c");
         double a=scanner.nextDouble();
         double b=scanner.nextDouble();
         double c=scanner.nextDouble();
         if(a>b)
          {
              if(a>c)
                 System.out.println(" a is the largest one "+a);
              else
                 System.out.println(" c is the largest one "+c);
           }
           else
           {
              if(b>c)
                 System.out.println(" b is the largest one "+b);
              else
                 System.out.println(" c is the largest one "+c);
           }

          
      }
} 