import java.math.*;
import java.util.Scanner;
import java.io.*;

public class Main
{
	static BigInteger seven = new BigInteger("7");
	static int ans[] = {0, 1, 2, 5, 9, 8, 6};
	static public void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		BigInteger x;
		int n = sc.nextInt();
		int data[] = new int[10000]; 
		int p;
		for(int i = 1; i <= n; ++ i)
		{
			x = sc.nextBigInteger();
			p = 0;
			while(! x.equals(BigInteger.ZERO))
			{
				data[++ p] = x.mod(seven).intValue();
				x = x.divide(seven);
			}
			for(int j = 1; j <= p; ++ j)
			{
				System.out.print(ans[data[j]]);
			}
			System.out.println("");
		}
	}
}