/* Assignment 3.1: Class for working with sets */

package praktikum_2;

import java.util.Scanner;

public class Assignment_3_1 {

	public static void main(String[] args) {
		int laenge = 0, auswahl, addWert;
		
		Scanner scanner = new Scanner(System.in); 
		
		//Let the user enter the desired length of the array
		System.out.print("Bitte die Größe der Grundmenge eingeben: ");
		try {
			laenge = scanner.nextInt();
		} catch (java.util.InputMismatchException e){
			System.out.println("Error: No number entered!");
		}
		
		//Generate quantity
		Menge M = new Menge(laenge);
			
		do {
			//Ask the user which method should be used or whether the program should be terminated
            do{
                System.out.println("\nWhich method do you want to use? ");
                System.out.println("1 = Add-Method");
                System.out.println("2 = Size-Method");
                System.out.println("3 = Print-Method");
                System.out.println("4 = Exit Program");
                auswahl = scanner.nextInt();
            } while (auswahl < 1 || auswahl > 4);
            
            switch(auswahl) {
            	//Let the user enter a value for the add method, call it and deliver the return value
            	case 1 : 	System.out.print("  Bitte gewünschten Wert eingeben: ");
            				addWert = scanner.nextInt();
                			System.out.println("  Rückgabewert: " + M.add(addWert)); break;
            	
    			//Print the size of the set (ones in the array)
            	case 2 :	System.out.println("  Rückgabewert: " + M.size()); break;
            	
            	//Output the array to the screen
            	case 3 :	M.print(); break;
            	
            	//Exit program
            	case 4 : break;
            }
		
		} while(auswahl != 4);
		
		scanner.close();
	}
}
