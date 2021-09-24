/* Gruppe 49 */
/* Nicole Schmidt, Tarik Bayer */

package praktikum_2;

public class Menge {
	private byte[] Bitmap;
	
	//Konstruktor der die Länge für die Bitmap übergeben bekommt und den Array erstellt
	public Menge(int laenge){
		this.Bitmap = new byte[laenge];
		
		//Bitmap-Array mit Nullen vorbesetzen, dunno wie viel Sinn das macht
		for(int i=0; i < laenge; i++) {
			Bitmap[i] = 0;
		}
	}
	
	//Add-Methode mit übergebenem Element
	public int add(int wert) {
		//Überprüfen ob das Element nicht in der Grundmenge liegt, falls Ja -1 als Rückgabewert liefern
		if(wert < 0 || wert >= Bitmap.length) {
			return -1;
		}
		
		//Ansonsten das Element der Bitmap hinzufügen und 0 zurückgeben
		Bitmap[wert] = 1;
		return 0;
	}
	
	//Size-Methode, die die einsen im Bitmap-Array zählt
	public int size() {
		int hilfe = 0;
		for(int i=0; i < Bitmap.length; i++) {
			if(Bitmap[i] == 1) {
				hilfe++;
			}
		}
		return hilfe;
	}
	//Elemente des Arrays auf den Bildschirm ausgeben
	public void print() {
		
		System.out.println("Inhalt der Bitmap:");
		for(int i=0; i < Bitmap.length; i++) {
			System.out.print(Bitmap[i]+" ");
		}
		
		System.out.println();
		
		for(int i=0; i < Bitmap.length; i++) {
			System.out.print(i+" ");
		}
	}
}

//Unterklasse für Aufgabe 2.2
class neueMenge extends Menge {
	private int laenge;
	
	//Konstruktur der den Array direkt mit einsen über Aufruf der Add-Methoder der Oberklasse füllen kann
	public neueMenge(int laenge, int wert) {
		super(laenge);
        this.laenge = laenge;
		
		for(int i = 0; i < wert; i++){
            add(i);
        }
	}
	
	//Empty-Methode, welche über Aufruf der Size-Methode rausfindet, ob die Menge bzw. der Array leer sind und dementsprechend true oder false zurückgibt
	public Boolean empty() {
		if(size() == 0) {
			return true;
		}
		return false;
	}
	
	//Neue Add-Methode
	public int add(int unten, int oben) {
		//Überprüfen ob unten und oben in der Grundmenge liegen, falls ja Methode mit -1 beenden
		if(unten < 0 || unten >= laenge || oben < 0 || oben >= laenge) {
			return -1;
		}
		
		//Ansonsten Array mithilfe der alten Add-Methode mit einsen zwischen unten und oben füllen und eine 0 zurückgeben
		for(int i=unten+1; i < oben; i++) {
			add(i);
		}
		return 0;
	}
}