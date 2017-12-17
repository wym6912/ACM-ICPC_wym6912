import java.math.*;
import java.util.Scanner;
import java.io.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		BigInteger a, b, c, d;
		while(sc.hasNextBigInteger())
		{
			a = sc.nextBigInteger();
			b = sc.nextBigInteger();
			c = sc.nextBigInteger();
			d = sc.nextBigInteger();
			b = b.subtract(a);
			d = d.subtract(c);
			int ans = b.compareTo(d);
			if(ans == 0)
			{
				System.out.println("Excellent");
			}
			else if(ans == 1)
			{
				System.out.println("Ting");
			}
			else
			{
				System.out.println("Yu");
			}
		}
	}
}