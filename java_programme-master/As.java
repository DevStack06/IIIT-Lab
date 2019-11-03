import java.io.*;
import java.util.Scanner;
public class As
{
   public static void main(String args[])
     {
         int t=0; 
          Scanner scanner= new Scanner(System.in);
          System.out.println("Enter the number");
          int k=scanner.nextInt();
         for(int i=0;i<3;i++)
              {
                  int l= k%10;
                 t=t+l;
                 k=k/10;
               }
             
              
          System.out.println("final output is "+t);
      }
} 