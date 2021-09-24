/* Gruppe 49 */
/* Nicole Schmidt, Tarik Bayer */
/* Aufgabe 2.1: Klasse zum Arbeiten mit Mengen */

package praktikum_2;

import java.util.Scanner;

public class Aufgabe_2_1 {

	public static void main(String[] args) {
		int laenge = 0, auswahl, addWert;
		
		Scanner scanner = new Scanner(System.in); 
		
		//User die gewünschte Länge des Arrays eingeben lasen
		System.out.print("Bitte die Größe der Grundmenge eingeben: ");
		try {
			laenge = scanner.nextInt();
		} catch (java.util.InputMismatchException e){
			System.out.println("Fehler: Keine Zahl eingegeben!");
		}
		
		//Menge erzeugen
		Menge M = new Menge(laenge);
			
		do {
			//User fragen welche Methode benutzt werden soll oder ob das Programm beendet werden soll
            do{
                System.out.println("\nWelche Methode möchten Sie verwenden? ");
                System.out.println("1 = Add-Methode");
                System.out.println("2 = Size-Methode");
                System.out.println("3 = Print-Methode");
                System.out.println("4 = Programm beenden");
                auswahl = scanner.nextInt();
            } while (auswahl < 1 || auswahl > 4);
            
            switch(auswahl) {
            	//User einen Wert für die Add-Methode eingeben lassen, diese aufrufen und den Rückgabewert liefern
            	case 1 : 	System.out.print("  Bitte gewünschten Wert eingeben: ");
            				addWert = scanner.nextInt();
                			System.out.println("  Rückgabewert: " + M.add(addWert)); break;
            	
    			//Die Größe der Menge ausgeben (einsen im Array)
            	case 2 :	System.out.println("  Rückgabewert: " + M.size()); break;
            	
            	//Array auf den Bildschirm ausgeben
            	case 3 :	M.print(); break;
            	
            	//Programm beenden
            	case 4 : break;
            }
		
		} while(auswahl != 4);
		
		scanner.close();
	}
}
