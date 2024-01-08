package Factorial;

public class Calculation
{
	public static void calc(int n)
	{
		int f=1;
		if(n<0)
		{
			System.out.println("\nFactorial Of Negative Number Doesn't Exist\n");
		}
		else if(n==0 || n==1)
		{
			System.out.println("\nFactorial Is : 1\n");
		}
		else
		{
			for (int i=2;i<=n;i++)
			{
				f=f*i;
			}
			System.out.println("\nFactorial Is : "+f+"\n");
		}
	}
}