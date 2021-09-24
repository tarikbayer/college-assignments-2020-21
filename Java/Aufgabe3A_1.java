package pi1;

import java.util.Scanner;

public class Aufgabe3A_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int n, i=0;
		Scanner scan = new Scanner(System.in);
		
		System.out.println("\nZiffern einer Ganzzahl bestimmen:\n");
        System.out.println("Bitte eingeben:");

        //Ganze Zahl n einlesen, die größer also 0 ist
        do {
            System.out.print("  Ganze Zahl n: ");
            n = scan.nextInt();
        } while(n <= 0);

        //n durch 10 teilen, i hochzählen, bis n = 0
        while(n != 0) {
            n = n / 10;
            i++;
        }
        
        //Anzahl der Ziffern ausgeben
        System.out.println("\nResultat: "+i);
	}

}
