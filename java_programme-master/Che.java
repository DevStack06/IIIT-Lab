import java.io.*;
import java.util.Scanner;
public class Che
{
   public static void main(String args[])
     {
          
          Scanner scanner= new Scanner(System.in);
          System.out.println("Enter the number");
          double k=scanner.nextDouble();
          if(k>0)
              System.out.println("number is positive ");
          else if(k<0)
               System.out.println("number is negative ");
           else
              System.out.println("number is neutral ");
             
              
          //System.out.println("total ,average and percentage is "+t+" "+avg+" "+per);
      }
} 