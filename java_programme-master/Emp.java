import java.io.*;
import java.util.Scanner;
//int count=0;
 class Emp1
{
	String salary;
	String name;
	String position;
	public Emp1(int r)
	{
		System.out.println(+r+"  Object created till now of employeee");
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the Employee name");
		name=sc.nextLine();
		System.out.println("Enter the employee Salary");
		salary=sc.nextLine();
		System.out.println("Enter the employee position");
		position=sc.nextLine();

				//return count;
		
	}
	int display(Emp1 x)
	{
		
		
		System.out.println(" the employee Salary"+x.salary);
		System.out.println("the employee name"+x.name);
		System.out.println("the employee position"+x.position);
		return 1;
		
	}
	
}

public class Emp
{
	public static void main(String args[])
	{
		int r=1,c=1;
		Scanner sc=new Scanner(System.in);
		while(c!=0)
		{
			System.out.println("if you want to create object press 1 other wise 0");
			 c=sc.nextInt();
			if(c==1)
			{
				//System.out.println("Give the name of object");
				//String d=sc.nextLine();
				Emp1 d=new Emp1(r);
				int k=d.display(d);
				if(k==1)
				{
					r=r+1;
					//

				}

			}
			else
				break;
		}
		
	}

 
}