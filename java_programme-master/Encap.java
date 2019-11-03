import java.io.*;
import java.util.Scanner;
 class Sa
{
	private String name;
	private int id;
	private int salary;
	public String getName()
	{
		return name;

	}
	public int getId()
	{
		return id;

	}
	public int getSalary()
	{
		return salary;

	}
	public void setSalry(int j)
	{
	     salary=j;

	}
	public void setId(int j)
	{
	     id=j;

	}
	public void setName(String j)
	{
	     name=j;

	}

}

public class Encap{
	public static void main(String args[])
	{
		//Static1.method1();
		//"balram");
		Sa S=new Sa();
		S.setName("balram");
		S.setId(161000);
		S.setSalry(200000);
		System.out.println("Name is "+S.getName()+"  Salary is "+S.getSalary()+" and id is "+S.getId());



	}
}