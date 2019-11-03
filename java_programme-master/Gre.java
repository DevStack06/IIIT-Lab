public class Gre
{
   public static void main(String args[])
   {
     int a,b;
     a=50;
     b=90;
     int c=30;
     //(a>b)?((a>c)?System.out.println("a is greater than other"):System.out.println("c is greater than other")):(b>c)?
//System.out.println("b is greater than other"):(System.out.println("c is greater than other"));
  
int d = (a>b)? ((a>c)? a:c):((b>c)?b:c);

System.out.print(d);
  
  }
}