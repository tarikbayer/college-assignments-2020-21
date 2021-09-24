package pi1;

import java.util.Scanner;

public class aufgabe1b2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		
		Scanner scan = new Scanner(System.in);
		System.out.println("Bitte geben Sie Zahl a ein: ");
		int zahlA = scan.nextInt();
		
		Scanner scan2 = new Scanner(System.in);
		System.out.println("Bitte geben Sie Zahl b ein: ");
		int zahlB = scan.nextInt();
		
		double d1; 
		double d2;
		d1 = zahlA / zahlB;
		d2 = (zahlA * 1.0) / zahlB;
		
		System.out.println("\nd1: " +d1);
		System.out.println("\nd2: " +d2);
		
		/*Wenn man Divisionen macht, die nicht eine gerade Zahl als Ergebnis haben kommen unterschiedliche Ergebnisse raus.
        Weil die Rechnung von d1 vom Typ Integer ist und deshalb die Nachkommastellen wegstreicht und bei d2 durch das " 1.0" zum Typ Double wird */
		

	}

}
