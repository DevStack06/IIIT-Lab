abstract class vehicle
{
	abstract void display();

}

class bike extends vehicle
{
	void display()
	{
		System.out.println("total wheel is 2 on bike");

	}
}
class car extends vehicle
{
	void display()
	{
		System.out.println("total wheel is 4 on car");
		
	}
}
class bike extends vehicle
{
	void display()
	{
		System.out.println("total wheel is 4 on bus");
		
	}
}

class Ab
{
	public static void main(String args[])
	{
		bike a=new bike();
		car b=new car();
		bus c=new bus();
		a.display();
		b.dispaly();
		c.dispaly();
	}
}