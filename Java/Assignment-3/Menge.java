
package praktikum_2;

public class Menge {
	private byte[] Bitmap;
	
	//Constructor that receives the length for the bitmap and creates the array
	public Menge(int laenge){
		this.Bitmap = new byte[laenge];
		
		//Filling bitmap array with zeros, dunno how much sense that makes
		for(int i=0; i < laenge; i++) {
			Bitmap[i] = 0;
		}
	}
	
	//Add method with passed element
	public int add(int wert) {
		//Check whether the element is not in the basic set, if yes return -1 as the return value
		if(wert < 0 || wert >= Bitmap.length) {
			return -1;
		}
		
		//Otherwise add the element to the bitmap and return 0
		Bitmap[wert] = 1;
		return 0;
	}
	
	//Size method that counts the ones in the bitmap array
	public int size() {
		int hilfe = 0;
		for(int i=0; i < Bitmap.length; i++) {
			if(Bitmap[i] == 1) {
				hilfe++;
			}
		}
		return hilfe;
	}
	//Output elements of the array on the screen
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

//Subclass for Assignment 3.2
class neueMenge extends Menge {
	private int laenge;
	
	//Constructor that can fill the array directly with ones by calling the add method of the superclass
	public neueMenge(int laenge, int wert) {
		super(laenge);
        this.laenge = laenge;
		
		for(int i = 0; i < wert; i++){
            add(i);
        }
	}
	
	//Empty method, which finds out by calling the Size method whether the set or the array is empty and accordingly returns true or false
	public Boolean empty() {
		if(size() == 0) {
			return true;
		}
		return false;
	}
	
	//New add method
	public int add(int unten, int oben) {
		//Check whether the bottom and top are in the basic set, if so, terminate the method with -1
		if(unten < 0 || unten >= laenge || oben < 0 || oben >= laenge) {
			return -1;
		}
		
		//Otherwise, fill the array with ones between the bottom and the top using the old Add method and return a 0
		for(int i=unten+1; i < oben; i++) {
			add(i);
		}
		return 0;
	}
}
