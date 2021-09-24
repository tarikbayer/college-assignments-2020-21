package pi1;

import java.util.Scanner;

public class Aufgabe3A_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int laenge, n, j = 0;
		Scanner scanLaenge = new Scanner(System.in);
		Scanner scanArray = new Scanner(System.in);
		Scanner scanN = new Scanner(System.in);

		System.out.println("Geben Sie eine ganze Zahl");

		do {
			laenge = scanLaenge.nextInt();
		} while (laenge < 5 || laenge > 10);

		int[] array = new int[laenge];

		for (int i = 0; i < laenge; i++) {
			System.out.println("Geben Sie Werte für Array:");
			array[i] = scanArray.nextInt();
		}

		System.out.println("Geben Sie eine ganze Zahl n:");
		n = scanN.nextInt();
		
		for (int i = 0; i < laenge; i++ ) {
			if(array[i] == n) {
				j++;
			}
		}
		 
		System.out.println("Anzahl der Zahl "+n+" im Array: "+j+"");
	}

}
