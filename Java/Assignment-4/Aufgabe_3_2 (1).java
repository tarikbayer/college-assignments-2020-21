package praktikum_3;

import java.util.Scanner;

public class Aufgabe_3_2 {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in); 
		
		int length = 0, auswahl, value, datentyp;	
		double valueDouble;
		ArrayGList<?> List = null;

		System.out.print("Bitte die maximale Länge der IntegerList eingeben: ");
		try {
			length = scanner.nextInt();
		} catch (java.util.InputMismatchException e){
			System.out.println("Fehler: Keine Zahl eingegeben!");
		}
		System.out.println("Welchen Datentyp möchten sie verwenden?");
		System.out.println("1 = Integer");
		System.out.println("2 = Double");
		datentyp = scanner.nextInt();
		
		if(datentyp == 1) {
			List = new ArrayGList<Integer>(length);
		}
		else if(datentyp == 2) {
			List = new ArrayGList<Double>(length);
		}
	
		do {
			//User fragen welche Methode benutzt werden soll oder ob das Programm beendet werden soll
            do{
                System.out.println("\nWelche Methode möchten Sie verwenden? ");
                System.out.println("1 = getLength");
                System.out.println("2 = insertLast");
                System.out.println("3 = getFirst");
                System.out.println("4 = deleteFirst");
                System.out.println("5 = search");
                System.out.println("6 = print");
                System.out.println("7 = Programm beenden");
                auswahl = scanner.nextInt();
            } while (auswahl < 1 || auswahl > 7);
            
			
			switch(auswahl) {
            	//getLength
            	case 1 : 	System.out.print("  Rückgabewert: " + List.getLength()); break;
                
    			//insertLast
            	case 2 :	System.out.print("  Bitte gewünschten Wert eingeben: ");
            				if(datentyp == 1) {
            					value = scanner.nextInt();
            					System.out.println("  Rückgabewert: " + List.insertLast(value)); break;
            				}
            				else {
            					valueDouble = scanner.nextDouble();
            					System.out.println("  Rückgabewert: " + List.insertLast(valueDouble)); break;
            				}
			    			
            	
    			//getFirst
            	case 3 :	System.out.println("  Rückgabewert: " + List.getFirst()); break;
            	
            	//deletFirst
            	case 4 :	System.out.println("  Rückgabewert: " + List.deleteFirst()); break;
            	
            	//search
            	case 5 : 	System.out.print("  Bitte gewünschten Wert eingeben: ");
							if(datentyp == 1) {
								value = scanner.nextInt();
								System.out.println("  Rückgabewert: " + List.search(value, datentyp)); break;
							}
							else {
								valueDouble = scanner.nextDouble();
								System.out.println("  Rückgabewert: " + List.search(valueDouble, datentyp)); break;
							}
            	
            	//print
            	case 6 : 	 List.print(); break;
            				
            	//Programm beenden			
            	case 7 : 	break;
            }
		
		} while(auswahl != 7);
		
		scanner.close();
	}
}