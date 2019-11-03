import java.io.*;

import java.util.Scanner;

import java.lang.Math;

class Ci{



void cical(){
double  p,r,t;
Scanner a = new Scanner(System.in);
System.out.println("Enter the principle:");
p = a.nextDouble();
System.out.println("Enter the rate:");
r = a.nextDouble();
System.out.println("Enter the number of years:");
t = a.nextDouble();
double m = Math.pow((1+r/100),t);
double c = p*m;
System.out.println("The compound interest is Rupees " + c);
}

}

public class Cicalc{
public static void main(String args[]){
Ci a = new Ci();
a.cical();
}
}
