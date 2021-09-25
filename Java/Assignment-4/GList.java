package praktikum_3;

@SuppressWarnings("hiding")
public interface GList<Object> {

	int getLength();       // returns the length of the list.
	
	int insertLast(Object value);      // inserts value at the end of the list.
	
	Object getFirst();    // returns the first element of the list.
	
	int deleteFirst();     // removes the first item from the list.
	
	boolean search(Object value, int datentyp);       //checks whether the value is in the list.
	
	void print();       // shows the contents of the list.
}
