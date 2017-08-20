import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	public static void main(String [] args)
	{
		String a;
		BigInteger fib[] = new BigInteger[201];
		int n,la;
		Scanner sc = new Scanner(System.in);
		fib[0] = new BigInteger("1");
		fib[1] = fib[0];
		for(int i = 2;i <= 200;i ++)
		{
			fib[i] = fib[i - 1].add(fib[i - 2]);
		}
		while(sc.hasNext())
		{
			n = sc.nextInt();
			for(int i = 1;i <= n;i ++)
			{
				a = sc.next();
				la = a.length();
				System.out.println(fib[la]);
			}
		}
	}
}
