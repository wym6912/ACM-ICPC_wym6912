import java.math.*;
import java.util.Scanner;
import java.io.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		BigInteger n, num1, num2;
		int num;
		num = 1;
		n = sc.nextBigInteger();
		num1 = BigInteger.ONE;
		num2 = BigInteger.ONE;
		while(num1.mod(n) != BigInteger.ZERO)
		{
			num ++;
			num2 = num2.multiply(BigInteger.TEN);
			num1 = num1.add(num2);
		}
		System.out.println(num1.divide(n) + " " + num);
	}
}