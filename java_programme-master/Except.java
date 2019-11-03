public class Except
{
	public static void main(String args[])
	{
		try
		{
			int c=11/0;
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		System.out.println("he loo ");
	}
}