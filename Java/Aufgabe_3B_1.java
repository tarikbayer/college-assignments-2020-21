import java.util.Scanner;

public class Aufgabe_3B_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		double[] a = new double[5];
		boolean[] b = new boolean[5];
		
		Scanner scanA = new Scanner(System.in);
		Scanner scanB = new Scanner(System.in);
		
		for(int i = 0; i<a.length; i++) {			
			System.out.println("Werte a");
			a[i] = scanA.nextDouble();
		}
		
		for(int i = 0; i<b.length; i++) {
			System.out.println("Werte b");
			b[i] = scanB.nextBoolean();		
		}		
	}
}
