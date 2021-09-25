package praktikum_3;

public class ArrayGList<T> implements GList<Object> {
	
	private T[] arrayList = null;
	private int length;

	//Konstruktor, der den Array erzeugt
	@SuppressWarnings("unchecked")
	public ArrayGList(int length) {
		this.arrayList = (T[]) new Object[length];
		this.length = 0;
	}
	
	//getLength-Methode
	public int getLength() {
		return length;
	}

	//insertLast-Methode, die an der letzten Stelle der Liste einen Wert einf�gt
	@SuppressWarnings("unchecked")
	public int insertLast(Object value) {
		if(arrayList.length > length) {			
			arrayList[length] = (T) value;
			length++;
			return 0;
		}
		return -1;
	}

	//getFirst-Methode, die falls m�glich, den Wert an der ersten Stelle zur�ckgibt
	public Object getFirst() {
		if(length == 0) return -9999;
		
		return arrayList[0];
	}

	//deletFirst-Methode, die den Wert an der ersten Stelle l�scht (falls m�glich) und die restlichen Werte einen Platz im Array nach vorne r�ckt
	public int deleteFirst() {
		if(length == 0) return -1;
		
		for(int i = 0; i < length; i++) {
			if(length == i + 1); //empty
			else arrayList[i] = arrayList[i + 1];
		}
		length--;
		return 0;
	}

	//Search-Methode, die mithilfe einer for-Schleife den Array durchl�uft und nach der �bergebenen Zahl sucht
	public boolean search(Object value, int datentyp) {
		
		//Search-Methode f�r Integer Werte, so wie in Aufgabe 3.1
		if(datentyp == 1) {
			for(int i = 0; i < length; i++) {
				if(value == arrayList[i]) return true;
			}
			return false;
		}
		
		//Search-Methode f�r Double Werte, mithilfe der compare Methode, da "==" nicht funktioniert hat
		else {
			for(int i = 0; i < length; i++) {
				if(Double.compare((Double) value, (Double) arrayList[i]) == 0) return true;
			}
			return false;
		}
	}

	//Print-Methode
	public void print() {
		
		System.out.println("Inhalt der IntegerList:");

		for(int i = 0; i < length; i++) {
			System.out.print(arrayList[i]+" ");
		}

	}
}
