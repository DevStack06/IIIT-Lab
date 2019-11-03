
interface A1
{
	void print();
}
interface A extends A1
{
	void print1();
}

interface B extends A1
{
	void hello();
}

class C implements  A,B
{
	public void print()
	{
		System.out.println(" hello ");
	}
	public void print1()
	{
		System.out.println(" interface a");
	}
	public void hello()
	{
		System.out.println(" hello ");
	}
}



class hybrid
{
	public static void main(String args[])
	{
       C a= new C();
       a.print();
       a.hello();
       a.print1();
   }
}