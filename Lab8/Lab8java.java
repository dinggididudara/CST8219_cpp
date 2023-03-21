import java.util.Random;
import java.util.Scanner;

public class Lab8java
{
	static{ System.loadLibrary("Lab8Lib");}

	public static void main(String args[])
	{
		int input;

		Random ran = new Random();
		Scanner sc = new Scanner(System.in);
		Lab8java cpp = new Lab8java();

		System.out.println("Enter the number of samples to generate:  ");
		input = sc.nextInt();

		int[] numbers = new int[input];

		for(int i=0;i<input;i++){
			numbers[i] = ran.nextInt(100); 
			System.out.println("Array: " + numbers[i]);	
		}
		double mean = cpp.calculateMean(numbers); 
		double sd = cpp.calculateSTDDev(numbers);
		System.out.println("Mean: " + mean + ", Standard Deviation: " + sd);
	}
	public native double calculateMean(int [] numbers);
	public native double calculateSTDDev(int [] numbers);
	
}