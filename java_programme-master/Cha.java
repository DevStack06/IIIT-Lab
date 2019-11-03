import java.io.*;
import java.util.Scanner;
public class Cha
{
   public static void main(String args[])
     {
          Scanner scanner= new Scanner(System.in);
          System.out.println("Enter the value of charachter");
          char a=scanner.next().charAt(0);
        // if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='I'a=='O'||a=='U'||a=='E')
          if((a=='a')||(a=='e')||(a=='i')||(a=='o')||(a=='u')  )
  
             System.out.println(" a is the Vowel"+a);
             
           
           else
              System.out.println(" a is not vowel "+a);
          

          
      }
} 