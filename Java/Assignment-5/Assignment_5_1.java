package praktikum_4;

import java.io.*;
import java.util.Scanner;

public class Assignment_5_1 {

	public static void main(String[] args) throws IOException, ClassNotFoundException {
		String fnap = "C:\\Users\\Tarik\\Desktop\\daten.txt";
		String fnap2 = "C:\\Users\\Tarik\\Desktop\\daten2.txt";
		int anzahl;
		
		String name;
		double groesse;
		int alter;
		
		Mensch mensch = new Mensch();
		Mensch help = mensch;
		Mensch obj1 = new Mensch();

		//Initialize the scanner and see if the file exists
		Scanner scan = null;
		try {
		    scan = new Scanner(new File(fnap));
		} catch (FileNotFoundException e) {
		    e.printStackTrace();
		}
		
		//Determine the number of objects to be read in and set the array to this length
		anzahl = scan.nextInt();
		Mensch array[] = new Mensch[anzahl]; 
		
		//Read in the names etc. and save them as an object in the array
		for(int i = 0; i < anzahl; i++) {
			name = scan.next();
			groesse = scan.nextDouble();
			alter = scan.nextInt();
			
			help.next = new Mensch(name, groesse, alter);
			help = help.next;
			array[i] = help;
		}
		scan.close();
		
		//Output the array to the screen with the print method
		System.out.println("Eingelesene Objekte aus daten.txt: ");
		for(int k = 0; k < anzahl; k++) {
			array[k].print();
			System.out.println();
		}
		
		//Save all objects through serialized output in daten2.txt
		ObjectOutputStream  objOutStr = new ObjectOutputStream(new FileOutputStream(fnap2));
		objOutStr.writeObject(mensch);
		objOutStr.close();
		
		//Now read in daten2.txt again
		ObjectInputStream  objInStr = new ObjectInputStream(new FileInputStream(fnap2));
		obj1 = (Mensch) objInStr.readObject();
		objInStr.close();
		
		//Create a new array and set the auxiliary variable
		Mensch array2[] = new Mensch[anzahl]; 
		help = obj1.next;
		
		//Save the newly created objects in a second array and output them
		System.out.println("Eingelesene Objekte aus daten2.txt: ");
		for(int l = 0; l < anzahl; l++) {
			array2[l] = help;
			help = help.next;
			
			array2[l].print();
			System.out.println();
		}
	}

}
