import java.util.Scanner;
import java.io.*;
interface CreditcardInterface
{
	void creditam();
	void usecard(int x);
	void paycredit(int x);
	void increse(int x,int y,int count);

}

class silver implements CreditcardInterface
{

	String name="";
	String card_number="";
	int creditamount;
	int creditlimit=50000;
	public void creditam()
	{
		creditamount=0;
		//System.out.println("hj");
		

	}

	public void usecard(int x)
	{
       //System.out.println("hj");
       if(x<=creditlimit)
            creditamount=creditamount+x;
        else
        	System.out.println("you can't increse that amount");

        System.out.println("after credit your amount is "+creditamount);
	}
	public void paycredit(int x)
	{

		if(creditamount-x>=0)
			creditamount=creditamount-x;
		else
		    System.out.println("you can't debit that amount");
		 System.out.println("after dedit your amount is "+creditamount);
	}
	public void increse(int x,int y,int count)
	{
		if(x<5000 && y==1)
		    creditlimit=creditlimit+x;
	}


}

class gold extends silver
{
	public void increse(int x,int y,int count)
	{
		int count1=count;
		if(y==1 && count1<3 )
		{
			creditlimit=100000;
		    creditlimit=creditlimit+x;
		    count++;
		}
		else
		{

			creditlimit=50000;
			System.out.println("no");
		}
	}

	
	
	
}

class credit
{
	public static void main(String args[])
	{
		int count=0,l=1;
		Scanner sc=new Scanner(System.in);
		while(l==1)
		{

			System.out.println("if you want to create object press 1 ");
			    l=sc.nextInt();
			if(l==1)
			{
				silver a=new silver();
				a.creditam();
				gold b = new gold();
		       // b.creditam();
				System.out.println("enter the credit amoount ");
				int x=sc.nextInt();
				a.usecard(x);
				//b.usecard(1000);
				System.out.println("enter the dedit amoount ");
				x=sc.nextInt();
				a.paycredit(x);
				//b.paycredit(2000);
				System.out.println("enter the increse limit amoount ");
				x=sc.nextInt();
				if(x<5000)
				{
					count++;
				a.increse(1200,0,count);
				b.increse(x,1,count);
			}

			}

		}
		

	}
}