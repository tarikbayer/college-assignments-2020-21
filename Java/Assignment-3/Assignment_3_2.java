/* Assignment 3.2: A subclass for sets with additional operations */

package praktikum_2;

import java.util.Scanner;

public class Assignment_3_2 {

	public static void main(String[] args) {
		int auswahl, addWert, unten, oben;
		
		Scanner scanner = new Scanner(System.in); 
		
		//Creating a set
		neueMenge M = new neueMenge(10, 3);
			
		do {
			//Ask the user which method should be used or whether the program should be terminated
            do{
                System.out.println("\nWelche Methode möchten Sie verwenden? ");
                System.out.println("1 = Add-Methode (Oberklasse)");
                System.out.println("2 = Add-Methode (Unterklasse)");
                System.out.println("3 = Size-Methode (Oberklasse)");
                System.out.println("4 = Print-Methode (Oberklasse)");
                System.out.println("5 = Empty-Methode (Unterklasse)");
                System.out.println("6 = Programm beenden");
                auswahl = scanner.nextInt();
            } while (auswahl < 1 || auswahl > 6);
            
            switch(auswahl) {
            	//Let the user enter a value for the add method, call it and deliver the return value
            	case 1 : 	System.out.print("  Bitte gewünschten Wert eingeben: ");
            				addWert = scanner.nextInt();
                			System.out.println("  Rückgabewert: " + M.add(addWert)); break;
                
    			//Let the user enter two values between which the array is filled with ones after checking in the method
            	case 2 :	System.out.print("  Bitte gewünschten unteren Wert eingeben: ");
							unten = scanner.nextInt();
							System.out.print("  Bitte gewünschten oberen Wert eingeben: ");
							oben = scanner.nextInt();
			    			System.out.println("  Rückgabewert: " + M.add(unten, oben)); break;
            	
    			//Print the size of the set (ones in the array)
            	case 3 :	System.out.println("  Rückgabewert: " + M.size()); break;
            	
            	//Output the array to the screen
            	case 4 :	M.print(); break;
            	
            	//Call the Empty method
            	case 5 : 	System.out.println("  Rückgabewert: " + M.empty()); break;
            	
            	//Exit program
            	case 6 : break;
            }
		
		} while(auswahl != 6);
		
		scanner.close();
	}
}
