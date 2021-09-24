/* Gruppe 49 */
/* Nicole Schmidt, Tarik Bayer */
/* Aufgabe 2.2: Eine Unterklasse f�r Mengen mit Zusatzoperationen */

package praktikum_2;

import java.util.Scanner;

public class Aufgabe_2_2 {

	public static void main(String[] args) {
		int auswahl, addWert, unten, oben;
		
		Scanner scanner = new Scanner(System.in); 
		
		//Menge erzeugen
		neueMenge M = new neueMenge(10, 3);
			
		do {
			//User fragen welche Methode benutzt werden soll oder ob das Programm beendet werden soll
            do{
                System.out.println("\nWelche Methode m�chten Sie verwenden? ");
                System.out.println("1 = Add-Methode (Oberklasse)");
                System.out.println("2 = Add-Methode (Unterklasse)");
                System.out.println("3 = Size-Methode (Oberklasse)");
                System.out.println("4 = Print-Methode (Oberklasse)");
                System.out.println("5 = Empty-Methode (Unterklasse)");
                System.out.println("6 = Programm beenden");
                auswahl = scanner.nextInt();
            } while (auswahl < 1 || auswahl > 6);
            
            switch(auswahl) {
            	//User einen Wert f�r die Add-Methode eingeben lassen, diese aufrufen und den R�ckgabewert liefern
            	case 1 : 	System.out.print("  Bitte gew�nschten Wert eingeben: ");
            				addWert = scanner.nextInt();
                			System.out.println("  R�ckgabewert: " + M.add(addWert)); break;
                
    			//User zwei Werte eingeben lassen, zwischen welchen der Array nach �berpr�fung in der Methode mit einsen gef�llt wird
            	case 2 :	System.out.print("  Bitte gew�nschten unteren Wert eingeben: ");
							unten = scanner.nextInt();
							System.out.print("  Bitte gew�nschten oberen Wert eingeben: ");
							oben = scanner.nextInt();
			    			System.out.println("  R�ckgabewert: " + M.add(unten, oben)); break;
            	
    			//Die Gr��e der Menge ausgeben (einsen im Array)
            	case 3 :	System.out.println("  R�ckgabewert: " + M.size()); break;
            	
            	//Array auf den Bildschirm ausgeben
            	case 4 :	M.print(); break;
            	
            	//Empty-Methode aufrufen
            	case 5 : 	System.out.println("  R�ckgabewert: " + M.empty()); break;
            	
            	//Programm beenden
            	case 6 : break;
            }
		
		} while(auswahl != 6);
		
		scanner.close();
	}
}
