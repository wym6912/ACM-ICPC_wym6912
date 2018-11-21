import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		BigInteger x, TWO = new BigInteger("2");
		int data[] = new int[2009], p;
		while(sc.hasNextBigInteger())
		{
			x = sc.nextBigInteger();
			p = 0;
			while(! x.equals(BigInteger.ZERO))
			{
				data[++ p] = x.mod(BigInteger.TEN).intValue();
				x = x.divide(BigInteger.TEN);
			}
			System.out.println(p + " 10");
			for(int i = 1; i <= p; ++ i)
			{
				System.out.print(data[i]);
				System.out.print(' ');
			}
			System.out.println(0);
		}
	}
}

/*
1
179426080107
*/