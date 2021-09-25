package praktikum_4;

import java.io.*;
import java.util.Scanner;

public class Aufgbe_4_1 {

	public static void main(String[] args) throws IOException, ClassNotFoundException {
		String fnap = "C:\\Users\\Nicole\\Desktop\\daten.txt";
		String fnap2 = "C:\\Users\\Nicole\\Desktop\\daten2.txt";
		int anzahl;
		
		String name;
		double groesse;
		int alter;
		
		Mensch mensch = new Mensch();
		Mensch help = mensch;
		Mensch obj1 = new Mensch();

		//Scanner initialisieren und schauen ob die Datei existiert
		Scanner scan = null;
		try {
		    scan = new Scanner(new File(fnap));
		} catch (FileNotFoundException e) {
		    e.printStackTrace();
		}
		
		//Die Anzahl der einzulesenden Objekte bestimmen und den Array auf diese Länge setzen
		anzahl = scan.nextInt();
		Mensch array[] = new Mensch[anzahl]; 
		
		//Einlesen der Namen etc. und diese als Objekt in dem Array abspeichern
		for(int i = 0; i < anzahl; i++) {
			name = scan.next();
			groesse = scan.nextDouble();
			alter = scan.nextInt();
			
			help.next = new Mensch(name, groesse, alter);
			help = help.next;
			array[i] = help;
		}
		scan.close();
		
		//Array auf den Bildschirm mit der print Methode ausgeben
		System.out.println("Eingelesene Objekte aus daten.txt: ");
		for(int k = 0; k < anzahl; k++) {
			array[k].print();
			System.out.println();
		}
		
		//Alle Objekte durch serialisierte Ausgabe in daten2.txt speichern
		ObjectOutputStream  objOutStr = new ObjectOutputStream(new FileOutputStream(fnap2));
		objOutStr.writeObject(mensch);
		objOutStr.close();
		
		//Nun daten2.txt wieder einlesen
		ObjectInputStream  objInStr = new ObjectInputStream(new FileInputStream(fnap2));
		obj1 = (Mensch) objInStr.readObject();
		objInStr.close();
		
		//Neuen array erzeugen und Hilfsvariable setzen
		Mensch array2[] = new Mensch[anzahl]; 
		help = obj1.next;
		
		//Abspeichern der neu erzeugten Objekte in einen zweiten Array und diese ausgeben
		System.out.println("Eingelesene Objekte aus daten2.txt: ");
		for(int l = 0; l < anzahl; l++) {
			array2[l] = help;
			help = help.next;
			
			array2[l].print();
			System.out.println();
		}
	}

}
