package praktikum_3;

public class ArrayGList<T> implements GList<Object> {
	
	private T[] arrayList = null;
	private int length;

	//Constructor that creates the array
	@SuppressWarnings("unchecked")
	public ArrayGList(int length) {
		this.arrayList = (T[]) new Object[length];
		this.length = 0;
	}
	
	//getLength-Method
	public int getLength() {
		return length;
	}

	//insertLast method that inserts a value at the end of the list
	@SuppressWarnings("unchecked")
	public int insertLast(Object value) {
		if(arrayList.length > length) {			
			arrayList[length] = (T) value;
			length++;
			return 0;
		}
		return -1;
	}

	//getFirst method, which, if possible, returns the value in the first position
	public Object getFirst() {
		if(length == 0) return -9999;
		
		return arrayList[0];
	}

	//deleteFirst method, which deletes the value in the first position (if possible) and moves the remaining values one place forward in the array
	public int deleteFirst() {
		if(length == 0) return -1;
		
		for(int i = 0; i < length; i++) {
			if(length == i + 1); //empty
			else arrayList[i] = arrayList[i + 1];
		}
		length--;
		return 0;
	}

	//Search method that iterates through the array using a for loop and searches for the passed number
	public boolean search(Object value, int datentyp) {
		
		//Search method for integer values
		if(datentyp == 1) {
			for(int i = 0; i < length; i++) {
				if(value == arrayList[i]) return true;
			}
			return false;
		}
		
		//Search method for double values, using the compare method, because "==" did not work
		else {
			for(int i = 0; i < length; i++) {
				if(Double.compare((Double) value, (Double) arrayList[i]) == 0) return true;
			}
			return false;
		}
	}

	//Print-Method
	public void print() {
		
		System.out.println("Inhalt der IntegerList:");

		for(int i = 0; i < length; i++) {
			System.out.print(arrayList[i]+" ");
		}

	}
}
