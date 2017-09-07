import java.util.*;
import java.math.BigInteger;

class Main
{
	static BigInteger TWO = new BigInteger("2");
	static BigInteger ONE = new BigInteger("1");
	static BigInteger ZERO = new BigInteger("0");
	public static int pow_mod(int a, BigInteger b,int c)
	{
		int e = 1;
		while(! b.equals(ZERO))
		{
			if(ONE.equals(b.mod(TWO)))
				e = e * a % c;
			b = b.divide(TWO);
			a = a * a % c;
		}
		return e;
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		BigInteger b;
		int a, c;
		while(sc.hasNext())
		{
			a = sc.nextInt();
			b = sc.nextBigInteger();
			c = sc.nextInt();
			System.out.println((pow_mod(a, b, c)));
		}
	}
}