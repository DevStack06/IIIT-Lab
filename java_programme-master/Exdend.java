interface A
{
	void print();
}

interface B extends A
{
	void hello();
}

class C implements  B
{
	public void print()
	{
		System.out.println(" interface a");
	}
	public void hello()
	{
		System.out.println(" hello ");
	}
}

class Exdend
{
	public static void main(String args[])
	{
       C a= new C();
       a.print();
       a.hello();
   }
}