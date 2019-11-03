import java.io.*;
import java.util.Scanner;
public class Avg
{
   public static void main(String args[])
     {
          double t=0;
          Scanner scanner= new Scanner(System.in);
          System.out.println("Enter the marks");
          for(int i =0;i<5;i++)
              {
                  double k=scanner.nextDouble();
                  t=t+k;
              }
          double avg=t/5;
          double per=((t/500)*100);
          System.out.println("total ,average and percentage is "+t+" "+avg+" "+per);
      }
} 