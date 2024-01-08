import java.util.Scanner;
import Factorial.Calculation;

class	Fact
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("\nEnter The Number Below :\n");
		int n=sc.nextInt();
		Calculation c=new Calculation();
		c.calc(n);
	}
}